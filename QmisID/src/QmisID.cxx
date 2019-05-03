#define QmisID_cxx
#include "inc/QmisID.h"
#include "HelperFunctions.cxx"
#include <fstream>
#include "TFitter.h"
#include "TH2D.h"

QmisID::QmisID() {}

QmisID::~QmisID() {}

bool QmisID::ReadFiles(const string& SampleList, const string& TreeName){
  TChain *chain=new TChain(TreeName.c_str());
  //read in input files and add to TChain
  short int exit_status = true;
  try{
      //fChain = make_unique<TChain>(TreeName.c_str());
      ifstream ifile(SampleList.c_str(),ifstream::in);
      string line;
      while(getline(ifile,line)){
            if(line[0]=='#') continue;
            chain -> Add(line.c_str());
            cout<<line.c_str()<<endl;
      }
  } catch (...) {return false;}

  Init(chain);
  return exit_status;
}

void QmisID::Init(TTree *tree){

  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("weight",&weight, &b_weight);
  fChain->SetBranchAddress("Mll01",&Mll01, &b_Mll01);
  fChain->SetBranchAddress("total_charge",&total_charge, &b_total_charge);
  fChain->SetBranchAddress("lep_Pt_0",&lep_Pt_0, &b_lep_Pt_0);
  fChain->SetBranchAddress("lep_Pt_1",&lep_Pt_1, &b_lep_Pt_1);
  fChain->SetBranchAddress("lep_Eta_0",&lep_Eta_0, &b_lep_Eta_0);
  fChain->SetBranchAddress("lep_Eta_1",&lep_Eta_1, &b_lep_Eta_1);
  fChain->SetBranchAddress("lep_ID_0",         &lep_ID_0,          &b_lep_ID_0);
  fChain->SetBranchAddress("lep_ID_1",         &lep_ID_1,          &b_lep_ID_1);
  fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0,  &b_lep_truthPdgId_0);
  fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1,  &b_lep_truthPdgId_1);
  fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0,  &b_lep_truthOrigin_0);
  fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1,  &b_lep_truthOrigin_1);
  fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0,  &b_lep_truthType_0);
  fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1,  &b_lep_truthType_1);
  fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0,  &b_lep_isQMisID_0);
  fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1,  &b_lep_isQMisID_1);
  fChain->SetBranchAddress("nJets_OR_T_MV2c10_70", &nJets_OR_T_MV2c10_70,  &b_nJets_OR_T_MV2c10_70);
  fChain->SetBranchAddress("nJets_OR_T", &nJets_OR_T,  &b_nJets_OR_T);
  fChain->SetBranchAddress("lep_isTightLH_0",             &lep_isTightLH_0,             &b_lep_isTightLH_0);
  fChain->SetBranchAddress("lep_isTightLH_1",             &lep_isTightLH_1,             &b_lep_isTightLH_1);
  fChain->SetBranchAddress("lep_isLooseLH_0",             &lep_isLooseLH_0,             &b_lep_isLooseLH_0);
  fChain->SetBranchAddress("lep_isLooseLH_1",             &lep_isLooseLH_1,             &b_lep_isLooseLH_1);    
  fChain->SetBranchAddress("lep_isolationFixedCutTight_0",&lep_isolationFixedCutTight_0,&b_lep_isolationFixedCutTight_0);
  fChain->SetBranchAddress("lep_isolationFixedCutLoose_0",&lep_isolationFixedCutLoose_0,&b_lep_isolationFixedCutLoose_0);
  fChain->SetBranchAddress("lep_isolationFixedCutTight_1",&lep_isolationFixedCutTight_1,&b_lep_isolationFixedCutTight_1);
  fChain->SetBranchAddress("lep_isolationFixedCutLoose_1",&lep_isolationFixedCutLoose_1,&b_lep_isolationFixedCutLoose_1);
}

//read config file
void QmisID::ReadConfig(const TString& configFile){
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
  gSystem->Exec("mkdir -p "+TString(m_RunName.c_str()));
  ConfigFromFile(m_isData, "isData", rEnv);
  ConfigFromFile(m_doTruthMatching, "doTruthMatching", rEnv);
  ConfigFromFile(m_doAbsoluteEta, "doAbsoluteEta", rEnv);
  ConfigFromFile(m_EtaString, "Eta", rEnv);
  ConfigFromFile(m_PtString, "Pt", rEnv);
  ConfigFromFile(m_Selections, "Selections", rEnv);
  ConfigFromFile(m_ElectronTight, "ElectronTight", rEnv);
  ConfigFromFile(m_ElectronAntiTight, "ElectronAntiTight", rEnv);
  ConfigFromFile(m_ElectronsCase, "ElectronsCase", rEnv);
  ConfigFromFile(m_SS_boundaries, "SS_boundaries", rEnv);
  ConfigFromFile(m_OS_boundaries, "OS_boundaries", rEnv);
  
  //interpret eta/pt and boundaries string
  InterpString(m_EtaString, m_eta_edges);
  InterpString(m_PtString, m_pt_edges);
  InterpString(m_SS_boundaries, m_SS_edges);
  InterpString(m_OS_boundaries, m_OS_edges);
  //for(unsigned int i=0;i<m_eta_edges.size();i++){
  //    cout<<m_eta_edges[i]<<endl;
  //}
  //and then locate the starting index of crack region
  m_crack_idx_pos=LocateCrackIdx(m_EtaString, "1.37");
  m_crack_idx_neg=LocateCrackIdx(m_EtaString, "-1.52");
  if(m_crack_idx_pos >= 0 && m_crack_idx_neg<0) nbins_eta_wocrk=m_eta_edges.size()-2;
  if(m_crack_idx_pos >= 0 && m_crack_idx_neg >=0) nbins_eta_wocrk=m_eta_edges.size()-3;
  if(m_crack_idx_pos < 0 && m_crack_idx_neg >=0) nbins_eta_wocrk=m_eta_edges.size()-2;
  if(m_crack_idx_pos < 0 && m_crack_idx_neg < 0) nbins_eta_wocrk=m_eta_edges.size()-1;
  nbins_pt=m_pt_edges.size()-1;
  nbins_eta=m_eta_edges.size()-1;

  //determine electron defitions bins
  if(m_ElectronsCase==1 || m_ElectronsCase==2) nbins_id=1;
  else nbins_id=2;
  
  //create selections and electron tight/anti-tight formulas
  fChain->LoadTree(0);
  m_FitZSelectionsFormula=new TTreeFormula("m_FitZSelections",m_FitZEvtSelString.Data(), fChain);
  m_SelectionsFormula=new TTreeFormula("m_Selections",m_EvtSelString.Data(),fChain);
  m_Electron0TightFormula=new TTreeFormula("m_Electron0TightFormula",m_Elec0TightString.Data(), fChain);
  m_Electron1TightFormula=new TTreeFormula("m_Electron1TightFormula",m_Elec1TightString.Data(), fChain);
  m_Electron0AntiTightFormula=new TTreeFormula("m_Electron0AntiTightFormula",m_Elec0AntiTightString.Data(),fChain);
  m_Electron1AntiTightFormula=new TTreeFormula("m_Electron1AntiTightFormula",m_Elec1AntiTightString.Data(),fChain); 
}

void QmisID::FillCells(){
  
  //Long64_t nentries=fChain->GetEntries();

  //book maps for SS/OS events
  //The map is ordered by id(electron_defition),eta,pt, 
  //eg, 0,0,0:1,1,1, which means the leading lepton is in (0,0,0) cell, 
  //while sub lepton is in (1,1,1) cell.
  ss_counts=CreateCellMap(nbins_id, nbins_eta_wocrk, nbins_pt); 
  os_counts=CreateCellMap(nbins_id, nbins_eta_wocrk, nbins_pt);

  //book output hists for truthmatching estimation
  if(m_doTruthMatching){
     TString truthZ_filename=m_RunName;
     truthZ_filename += "/yields_truthZ.root";
     truthZ_file=new TFile(truthZ_filename.Data(),"recreate");
     Float_t *eta_bins= &m_eta_edges[0];
     Float_t *pt_bins= &m_pt_edges[0];
     for(int i=0; i<nbins_id; i++){ 
         TString hist_total_name="hist_total_"; hist_total_name += i;
         TString hist_misid_name="hist_misid_"; hist_misid_name += i;
         hists_total[i]=new TH2D(hist_total_name.Data(),"",nbins_eta, eta_bins, nbins_pt, pt_bins);
         hists_misid[i]=new TH2D(hist_misid_name.Data(),"",nbins_eta, eta_bins, nbins_pt, pt_bins);
     }
  }
  double check_ss(0), check_os(0);
  double xx(0), yy(0);
  double nElectronsCase1(0), nElectronsCase2(0), nElectronsCase3(0), nElectronsCase4(0), nElectronsCase5(0);
  double acount_os(0), bcount_os(0), ccount_os(0);
  double acount_ss(0), bcount_ss(0), ccount_ss(0);
  cout<<"Looping over events and filling in (SS/OS)maps"<<endl;
  //cout<<m_SelectionsFormula->GetNdata()<<endl;
  for(Long64_t entry=0; entry<fChain->GetEntriesFast(); entry++){
  //for(Long64_t entry=0; entry<100000; entry++){
      if(fChain->LoadTree(entry)<0)  break;
      xx++;
      fChain->GetEntry(entry);
      FormulaUpdate();
      //if(entry%500000==0) cout<<entry<<"/"<<nentries<<" Events processed"<<endl;
      if(entry%500000==0) cout<<entry<<" Events processed"<<endl;
      if (m_isData) weight=1;
      //event selections set in config 
      if ( !EventSelections() ) continue;
      yy++;

      //determine electrons comb idx.
      //00, tight-tight; 11, antitight-antitight; 01, tight-antitight; 10, antitight-tight
      string elecsidx=ElectronsCombIdx();
      ////cout<<elecsidx<<endl;
      if(!passElectronsCase(elecsidx, m_ElectronsCase)) continue;
      //only for checks
      if(passElectronsCase(elecsidx,1)) nElectronsCase1++;
      if(passElectronsCase(elecsidx,2)) nElectronsCase2++;
      if(passElectronsCase(elecsidx,3)) nElectronsCase3++;
      if(passElectronsCase(elecsidx,4)) nElectronsCase4++;
      if(passElectronsCase(elecsidx,5)) nElectronsCase5++;
      //remove crack region
      if( (fabs(lep_Eta_0)>1.37&&fabs(lep_Eta_0)<1.52) || (fabs(lep_Eta_1)>1.37&&fabs(lep_Eta_1)<1.52)) continue;

      Float_t tmp_eta0=lep_Eta_0;
      Float_t tmp_eta1=lep_Eta_1;
      if (m_doAbsoluteEta) {
          tmp_eta0=fabs(lep_Eta_0);
          tmp_eta1=fabs(lep_Eta_1);
      }
      //for truthmatching, the idea is counting. Store all the electrons in total hist, and 
      //count the misid electrons based on truthId.
      //first remove those problematic events
      if(m_doTruthMatching && (!m_isData) && 
         //((abs(lep_ID_0)!=11) || (abs(lep_ID_1)!=11) || (abs(lep_truthPdgId_0)!= 11) || (abs(lep_truthPdgId_1)!=11))) continue;
         ((abs(lep_ID_0)!=11) || (abs(lep_ID_1)!=11) )) continue;
      if(m_doTruthMatching){//truthmatching (in principle, for sure you can argue) doesn't rely on Z peak choice
         if(m_isData) {
            cout<<"Error: You are running Truth-Matching on Data!! Exiting.."<<endl;
            return;
         }
         //we care about prompt electrons and make sure the electrons are from Z boson decay
         //check here:https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/MCTruthClassifier
         if(abs(lep_truthType_0)==2 && abs(lep_truthType_1)==2 && 
            abs(lep_truthOrigin_0)==13 && abs(lep_truthOrigin_1)==13){
            //for isQMisID, check https://gitlab.cern.ch/atlasHTop/ttHMultiAna/blob/master/Root/TruthMatchAlgo.cxx
            if(nbins_id==1){ //must be electronscase 1 or 2
               hists_total[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
               hists_total[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
               if(lep_isQMisID_0) hists_misid[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
               if(lep_isQMisID_1) hists_misid[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
            }// 1
            if(nbins_id==2) {//must be electronscase 3, 4, or 5
               if(elecsidx=="01") {
                  hists_total[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight); 
                  hists_total[1]->Fill(tmp_eta1, lep_Pt_1/GeV, weight); 
                  if(lep_isQMisID_0) hists_misid[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  if(lep_isQMisID_1) hists_misid[1]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
               }//01
               if(elecsidx=="10") {
                  hists_total[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
                  hists_total[1]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  if(lep_isQMisID_0) hists_misid[1]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  if(lep_isQMisID_1) hists_misid[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
               }//10
               if(elecsidx=="00") {
                  hists_total[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  hists_total[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
                  if(lep_isQMisID_0) hists_misid[0]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  if(lep_isQMisID_1) hists_misid[0]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
               }//00
               if(elecsidx=="11") {
                  hists_total[1]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  hists_total[1]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
                  if(lep_isQMisID_0) hists_misid[1]->Fill(tmp_eta0, lep_Pt_0/GeV, weight);
                  if(lep_isQMisID_1) hists_misid[1]->Fill(tmp_eta1, lep_Pt_1/GeV, weight);
               }//11
            }// 2
         }//end if prompt and from Z
      }//end of if dotruthmatching
      
      //for likelihood, the idea is store each combination's yields in a map and write to txt files
      //Each combination is in the format of id0,eta0,pt0:id1,eta1,pt1 (0 means leading lepton, 1 sub)
      //below start to sort out the cell and fill the maps, meanwhile cal side-bands
      if(total_charge==0 ){
         if( Mll01/GeV>=m_OS_edges[0] && Mll01/GeV<m_OS_edges[1]) acount_os += weight; 
         if( Mll01/GeV>=m_OS_edges[1] && Mll01/GeV<=m_OS_edges[2]){
             os_counts[SortOutCell(elecsidx, tmp_eta0,lep_Pt_0/GeV,tmp_eta1,lep_Pt_1/GeV)] += weight;
             check_os+=weight;
             bcount_os += weight;
         }
         if( Mll01/GeV>m_OS_edges[2] && Mll01/GeV<=m_OS_edges[3]) ccount_os += weight;
      }
      if(abs(total_charge)==2 ){
         if( Mll01/GeV>=m_SS_edges[0] && Mll01/GeV<m_SS_edges[1]) acount_ss += weight;
         if(Mll01/GeV>m_SS_edges[1] && Mll01/GeV<m_SS_edges[2]){
            ss_counts[SortOutCell(elecsidx, tmp_eta0, lep_Pt_0/GeV, tmp_eta1,lep_Pt_1/GeV)] += weight;
            check_ss += weight;
            bcount_ss += weight;
         }
         if( Mll01/GeV>m_SS_edges[2] && Mll01/GeV<=m_SS_edges[3]) ccount_ss += weight;
      }
  }//end of event loop

  //write truthmatching file (if there is) 
  if(m_doTruthMatching){
     for(int i=0; i<nbins_id; i++){
         hists_total[i]->Write();
         hists_misid[i]->Write();
     }
     truthZ_file->Close();
  }

  //write the maps to txt files 
  ofstream outfile_ss, outfile_os;
  string outfile_ss_name=m_RunName+"/yields_SS.txt"; 
  string outfile_os_name=m_RunName+"/yields_OS.txt";

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
  outfile_ss.close();
  outfile_os.close();
  cout<<"----------------CHECK(two columns should be equal)-------------------"<<endl;
  cout<<left<<setw(20)<<"    Counting"<<setw(10)<<"Sum over stored map"<<endl;
  cout<<left<<"SS: "<<setw(16)<<check_ss<<setw(20)<<ncounts_ss<<endl;
  cout<<left<<"OS: "<<setw(16)<<check_os<<setw(20)<<ncounts_os<<endl;
  cout<<"---------------------------------------------------------------------"<<endl;
  cout<<"Event selections (Raw):   "<<xx<<"------->"<<yy<<endl;  
  cout<<"ElectronsCase1 (Raw):     "<<nElectronsCase1<<endl;
  cout<<"ElectronsCase2 (Raw):     "<<nElectronsCase2<<endl;
  cout<<"ElectronsCase3 (Raw):     "<<nElectronsCase3<<endl;
  cout<<"ElectronsCase4 (Raw):     "<<nElectronsCase4<<endl;
  cout<<"ElectronsCase5 (Raw):     "<<nElectronsCase5<<endl;
  //subtract and calculate scale factor for z peak events
  std::cout<<"<< ============== OS events ============== >>"<<std::endl;
  std::cout<<left<<setw(25)<<"             A"<<setw(25)<<"B"<<setw(15)<<"C"<<std::endl;
  std::cout<<"numOfevts: "<<setw(15)<<acount_os<<setw(25)<<bcount_os<<setw(15)<<ccount_os<<std::endl;
  double sf_os=(bcount_os-(acount_os+ccount_os)/2.)/bcount_os;
  std::cout<<"So Z peak events are: "<<bcount_os-(acount_os+ccount_os)/2.<<std::endl;
  std::cout<<"And corresponding scale factor is "<<sf_os<<std::endl;
  std::cout<<"<< ============== SS events ============== >>"<<std::endl;
  std::cout<<left<<setw(25)<<"             A"<<setw(25)<<"B"<<setw(15)<<"C"<<std::endl;
  std::cout<<"numOfevts: "<<setw(15)<<acount_ss<<setw(25)<<bcount_ss<<setw(15)<<ccount_ss<<std::endl;
  double sf_ss=(bcount_ss-(acount_ss+ccount_ss)/2.)/bcount_ss;
  std::cout<<"So Z peak events are: "<<bcount_ss-(acount_ss+ccount_ss)/2.<<std::endl;
  std::cout<<"And corresponding scale factor is "<<sf_ss<<std::endl;
  //write sf to txt
  ofstream outfile_sf_os;
  ofstream outfile_sf_ss;
  string outfile_sf_os_name=m_RunName+"/sf_OS.txt";
  string outfile_sf_ss_name=m_RunName+"/sf_SS.txt";
  outfile_sf_os.open(outfile_sf_os_name.c_str(), ios::trunc);
  outfile_sf_os<<sf_os<<"\n";
  outfile_sf_os.close();
  outfile_sf_ss.open(outfile_sf_ss_name.c_str(), ios::trunc);
  outfile_sf_ss<<sf_ss<<"\n";
  outfile_sf_ss.close();
}

//Truth-Matching and Minimize
void QmisID::Minimize(){

  //OK, let's first start do deal with truth-matching rates
  if(m_doTruthMatching){
     //read in truth file made in previous step
     TString ReadtruthZ_filename=m_RunName;
     ReadtruthZ_filename += "/yields_truthZ.root";
     TFile *ReadtruthZ_file=new TFile(ReadtruthZ_filename.Data());
     //book outfile for truth rates
     TString TruthRatesFileName=m_RunName;
     TruthRatesFileName += "/QmisID_TruthRates.root";
     TFile *TruthRatesFile =new TFile(TruthRatesFileName.Data(),"recreate");
     //get misid and total, divide them
     for(int i=0; i<nbins_id; i++){
         TString readhist_total_name="hist_total_"; readhist_total_name +=i;
         TString readhist_misid_name="hist_misid_"; readhist_misid_name += i;
         TH2* readhist_total=(TH2*)ReadtruthZ_file->Get(readhist_total_name.Data());
         TH2* readhist_misid=(TH2*)ReadtruthZ_file->Get(readhist_misid_name.Data());
         TString truthrates_hist_name="hist_truthQmisID_";
         truthrates_hist_name += i;
         TH2 *hist_truthrates=(TH2*)readhist_total->Clone(truthrates_hist_name.Data());
         hist_truthrates->Divide(readhist_misid, readhist_total, 1, 1, "");
         hist_truthrates->Write();  
     }
     TruthRatesFile->Close();
  }

  //Below start likelihood method
  //First Read in OS/SS maps obtained in last step
  ReadCellMap("OS",OS_Counts);
  ReadCellMap("SS",SS_Counts);

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

  //parameters for numeric estimations
  for(int n=0; n<nfit; n++){
      vstart[n] = 0.00001;
      step[n] = 0.000001;
      name[n] = Form("par%d",n+1);
  }
  for(int j = 0; j < nfit; j++) {
      minimizer->SetParameter(j, name[j], vstart[j], step[j], 0.000001, 0.2);
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
  RatesFileName += "/QmisID_Rates.root";
  TFile *RatesFile =new TFile(RatesFileName,"recreate");
  map<int, TH2D* > hists_rates;
  for(int i=0; i<nbins_id; i++){
      TString histname="hist_QmisID_";
      histname += i;
      hists_rates[i]=new TH2D(histname,"",nbins_eta,eta_bins,nbins_pt,pt_bins);
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
      hists_rates[i]->Write();
  }
  //hist_QmisID->Write();
  RatesFile->Close();
  delete[] vstart;
  delete[] step;
  delete[] name;
}
