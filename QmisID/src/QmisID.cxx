#define QmisID_cxx
#include "inc/QmisID.h"
#include "HelperFunctions.cxx"
#include <fstream>
#include "TFitter.h"
#include "TH2D.h"

QmisID::QmisID() {}

QmisID::~QmisID() {}

bool QmisID::ReadFiles(const string& SamplePath, const string& TreeName){
  //read in input files
  short int exit_status = true;
  try {
      fChain = make_unique<TChain>(TreeName.c_str());
      fChain -> Add(SamplePath.c_str());
  } catch (...) {return false;}
  return exit_status;
}

void QmisID::Init(const TString& configFile){

  fChain->SetBranchAddress("weight",&weight, &b_weight);
  fChain->SetBranchAddress("Mll01",&Mll01, &b_Mll01);
  fChain->SetBranchAddress("total_charge",&total_charge, &b_total_charge);
  fChain->SetBranchAddress("lep_Pt_0",&lep_Pt_0, &b_lep_Pt_0);
  fChain->SetBranchAddress("lep_Pt_1",&lep_Pt_1, &b_lep_Pt_1);
  fChain->SetBranchAddress("lep_Eta_0",&lep_Eta_0, &b_lep_Eta_0);
  fChain->SetBranchAddress("lep_Eta_1",&lep_Eta_1, &b_lep_Eta_1);
  fChain->SetBranchAddress("lep_isTightLH_0",             &lep_isTightLH_0,             &b_lep_isTightLH_0);             
  fChain->SetBranchAddress("lep_isTightLH_1",             &lep_isTightLH_1,             &b_lep_isTightLH_1);            
  fChain->SetBranchAddress("lep_isolationFixedCutTight_0",&lep_isolationFixedCutTight_0,&b_lep_isolationFixedCutTight_0);
  fChain->SetBranchAddress("lep_isolationFixedCutLoose_0",&lep_isolationFixedCutLoose_0,&b_lep_isolationFixedCutLoose_0);
  fChain->SetBranchAddress("lep_isolationFixedCutTight_1",&lep_isolationFixedCutTight_1,&b_lep_isolationFixedCutTight_1);
  fChain->SetBranchAddress("lep_isolationFixedCutLoose_1",&lep_isolationFixedCutLoose_1,&b_lep_isolationFixedCutLoose_1);
  //current tree number, in case there are multiple files added
  fCurrent = 0;

  //read config file
  TEnv rEnv;
  int success = -1;
  success = rEnv.ReadFile(configFile.Data(), kEnvAll);
  if( success != 0 ) {
    cout<<"Unable to read conf file " << configFile;
    return ;
  }
  else {
    cout<<"Reading conf file " << configFile<<endl;
  }
  ConfigFromFile(m_RunName, "RunName", rEnv);
  ConfigFromFile(m_isData, "isData", rEnv);
  ConfigFromFile(m_doTruthMatching, "doTruthMatching", rEnv);
  ConfigFromFile(m_doAbsoluteEta, "doAbsoluteEta", rEnv);
  ConfigFromFile(m_Eta, "Eta", rEnv);
  ConfigFromFile(m_Pt, "Pt", rEnv);
  ConfigFromFile(m_Selections, "Selections", rEnv);
  ConfigFromFile(m_ElectronTight, "ElectronTight", rEnv);
  ConfigFromFile(m_ElectronAntiTight, "ElectronAntiTight", rEnv);
  ConfigFromFile(m_ElectronsCase, "ElectronsCase", rEnv);
  ConfigFromFile(m_SS_boundaries, "SS_boundaries", rEnv);
  ConfigFromFile(m_OS_boundaries, "OS_boundaries", rEnv);
  
  //interpret eta/pt and boundaries string
  InterpString(m_Eta, m_eta_edges);
  InterpString(m_Pt, m_pt_edges);
  InterpString(m_SS_boundaries, m_SS_edges);
  InterpString(m_OS_boundaries, m_OS_edges);
  //for(unsigned int i=0;i<m_eta_edges.size();i++){
  //    cout<<m_eta_edges[i]<<endl;
  //}
  //and then locate the starting index of crack region
  m_crack_idx_pos=LocateCrackIdx(m_Eta, "1.37");
  m_crack_idx_neg=LocateCrackIdx(m_Eta, "-1.52");
  if(m_crack_idx_pos) nbins_eta_wocrk=m_doAbsoluteEta?m_eta_edges.size()-2:m_eta_edges.size()-3;
  else nbins_eta_wocrk=m_eta_edges.size()-1;
  nbins_pt=m_pt_edges.size()-1;
  nbins_eta=m_eta_edges.size()-1;

  //determine electron defitions bins
  if(m_ElectronsCase==1) nbins_id=1;
  else nbins_id=2;
  //create selections and electron tight/anti-tight formulas
  fChain->LoadTree(0);
  m_SelectionsFormula=new TTreeFormula("m_Selections","fabs(lep_Pt_0)>=100e3",fChain->GetTree());
  m_Electron0TightFormula=new TTreeFormula("m_Electron0TightFormula","lep_isTightLH_0&&lep_isolationFixedCutLoose_0", fChain->GetTree());
  m_Electron1TightFormula=new TTreeFormula("m_Electron1TightFormula","lep_isTightLH_1&&lep_isolationFixedCutLoose_1", fChain->GetTree());
  m_Electron0AntiTightFormula=new TTreeFormula("m_Electron0AntiTightFormula","lep_isTightLH_0&&(!lep_isolationFixedCutLoose_0)", fChain->GetTree());
  m_Electron1AntiTightFormula=new TTreeFormula("m_Electron1AntiTightFormula","lep_isTightLH_1&&(!lep_isolationFixedCutLoose_1)", fChain->GetTree());
  
}

void QmisID::FillCells(){
  
  Long64_t nentries=fChain->GetEntries();

  //ss_counts=CreateCellMap(m_eta_edges, m_pt_edges); //looks no need to initialize
  //os_counts=CreateCellMap(m_eta_edges, m_pt_edges);

  double check_ss(0), check_os(0);
  double xx(0), yy(0);
  cout<<"Looping over events and filling in (SS/OS)maps"<<endl;
  //cout<<m_SelectionsFormula->GetNdata()<<endl;
  for(Long64_t entry=0; entry<nentries; entry++){

      xx++;
      fChain->GetEntry(entry);

      //event selections set in config 
      if (! EventSelections() ) continue;
      yy++;

      //determine electrons comb idx.
      //00, tight-tight; 11, antitight-antitight; 01, tight-antitight; 10, antitight-tight
      bool passElectronsCase=false;
      string elecsidx=ElectronsCombIdx();
      //cout<<elecsidx<<endl;
      switch(m_ElectronsCase){
         case 1:
           { if (elecsidx=="00" || elecsidx=="11") passElectronsCase=true; }
           break;
         case 2:
           { if (elecsidx=="01" || elecsidx=="10") passElectronsCase=true; }
           break;
         case 3:
           { if (elecsidx=="00" || elecsidx=="11" || elecsidx=="01" || elecsidx=="10") passElectronsCase=true; }
           break;
         default : { cout<<"Error: The ElectronsCase must be 1, 2 or 3!"<<endl; return; }
      }
      if(!passElectronsCase) continue;

      //remove crack region
      if( (fabs(lep_Eta_0)>1.37&&fabs(lep_Eta_0)<1.52) || (fabs(lep_Eta_1)>1.37&&fabs(lep_Eta_1)<1.52)) continue;

      //sort out the cell and fill the maps
      if(total_charge==0 && Mll01/GeV>m_OS_edges[1] && Mll01/GeV<m_OS_edges[2]){
         os_counts[SortOutCell(elecsidx, lep_Eta_0,lep_Pt_0/GeV,lep_Eta_1,lep_Pt_1/GeV)] += 1;
         check_os++;
      }
      if(abs(total_charge)==2 && Mll01/GeV>m_SS_edges[1] && Mll01/GeV<m_SS_edges[2]){
         ss_counts[SortOutCell(elecsidx, lep_Eta_0,lep_Pt_0/GeV,lep_Eta_1,lep_Pt_1/GeV)] += 1;
         check_ss++;
      }
  }//end of event loop
 
  //write the maps to txt files 
  ofstream outfile_ss, outfile_os;
  string outfile_ss_name=m_RunName+"_SS.txt"; 
  string outfile_os_name=m_RunName+"_OS.txt";

  outfile_ss.open(outfile_ss_name.c_str(), ios::trunc); 
  outfile_os.open(outfile_os_name.c_str(), ios::trunc);

  map<string, double>::iterator it;
  double ncounts_ss(0), ncounts_os(0);
  for(it=ss_counts.begin(); it!=ss_counts.end(); ++it){
      outfile_ss << it->first <<" "<<it->second<<"\n";
      ncounts_ss += it->second;
  } 

  for(it=os_counts.begin(); it!=os_counts.end(); ++it){
      outfile_os << it->first <<" "<<it->second<<"\n";
      ncounts_os += it->second;
  }

  cout<<"----------------CHECK(two columns should be equal)-------------------"<<endl;
  cout<<left<<setw(20)<<"    Counting"<<setw(10)<<"Sum over stored map"<<endl;
  cout<<left<<"SS: "<<setw(16)<<check_ss<<setw(20)<<ncounts_ss<<endl;
  cout<<left<<"OS: "<<setw(16)<<check_os<<setw(20)<<ncounts_os<<endl;
  cout<<"---------------------------------------------------------------------"<<endl;
  cout<<xx<<" "<<yy<<endl;  
}

//Minimize
void QmisID::Minimize(){

  const int nfit=nbins_pt*nbins_eta_wocrk*nbins_id;//npars
  Double_t Qff[nfit], Qff_err[nfit];
  TFitter* minimizer = new TFitter(nfit);
  minimizer->SetFCN(Likelihood);
  cout<<nfit<<endl;
  double arglist[10];
  //Setting up minuit parameters
  Double_t *vstart = new Double_t[nfit];
  Double_t *step=new Double_t[nfit];
  TString *name = new TString[nfit];

  for(int n=0; n<nfit; n++){
      vstart[n] = 0.00001;
      step[n] = 0.000001;
      name[n] = Form("par%d",n+1);
  }
  for(int j = 0; j < nfit; j++) {
      minimizer->SetParameter(j, name[j], vstart[j], step[j], 0.000001, 0.1);
  }
  //
  minimizer->ExecuteCommand("CAL", arglist, 1);
  minimizer->ExecuteCommand("SET NOG", arglist, 0);
  minimizer->ExecuteCommand("MINIMIZE", arglist, 0);
  minimizer->ExecuteCommand("MIGRAD", arglist, 0);
  minimizer->ExecuteCommand("HESSE", arglist, 0);
  minimizer->ExecuteCommand("CAL", arglist, 1);

  //book output to store estimated rates
  Float_t *eta_bins= &m_eta_edges[0];
  Float_t *pt_bins= &m_pt_edges[0];
  TString RatesFileName=m_RunName;
  RatesFileName += "_Rates.root";
  TFile *RatesFile =new TFile(RatesFileName,"recreate");
  map<int, TH2D* > hists_rates;
  for(int i=0; i<nbins_id; i++){
      string histname="hist_QmisID_";
      histname += i;
      hists_rates[i]=new TH2D(histname.c_str(),"",nbins_eta,eta_bins,nbins_pt,pt_bins);
  }
  std::cout<<"<< ===== Fitted QmisID rates =====>"<<std::endl;
  for (int j = 0; j < nfit; j++) {
       Qff[j] = minimizer->GetParameter(j);
       Qff_err[j] = minimizer->GetParError(j);
       std::cout<<j<<"  "<<Qff[j]<<"  "<<Qff_err[j]<<std::endl;
  }

  int index=0;
  for(int a=0; a<nbins_id; a++){
      for(int i=0;i<nbins_eta;i++){
          if(i==m_crack_idx_neg || i==m_crack_idx_pos) continue;//crack region
             for(int j=0;j<nbins_pt;j++){
                 hists_rates[a]->SetBinContent(i+1,j+1,minimizer->GetParameter(index));
                 hists_rates[a]->SetBinError(i+1,j+1,minimizer->GetParError(index));
                 index++;
             }
      }
  }
  //write rates hists
  for(int i=0; i<nbins_id; i++){
      string histname="hist_QmisID_";
      histname += i;
      hists_rates[i]->Write();
  }
  //hist_QmisID->Write();
  RatesFile->Close();
  delete[] vstart;
  delete[] step;
  delete[] name;
}
