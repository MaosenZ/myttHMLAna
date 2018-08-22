#define NTUPLE_cxx
#include "../myttHAna/NTUPLE.h"
#include "../myttHAna/BDTcalculation.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <string>
#include <fstream>
#include <sstream>
#include "commonSelections.cxx"
#include "commonWeight.cxx"
#include "applySelections.cxx"

/*void NTUPLE::makeMiniTree(TTree &tree, regions)
{
  TFile *outfile=new TFile(mySample, "recreate");
  TTree *tree=new TTree("tree","tree");
  Int_t o_tau_truthType_0, o_tau_truthType_1, o_tau_truthOrigin_0, o_tau_truthOrigin_1;
  tree->Branch("tau_truthType_0", &o_tau_truthType_0);
  tree->Branch("tau_truthType_1", &o_tau_truthType_1);
  tree->Branch("tau_truthOrigin_0", &o_tau_truthOrigin_0);
  tree->Branch("tau_truthOrigin_1", &o_tau_truthOrigin_1);

  std::map< std::string, Branch_Types > output_branches;
  for(unsigned int i=0; i<regions.size();i++){
      tree->Branch((regions[i]).c_str(), &output_branches[regions[i]].c)
  }
  
}*/

void NTUPLE::fillHistsMiniTree(std::map<string, TH1F* > & TH1Fs, TTree *minitree){

   Long64_t nentries = fChain->GetEntries();
   unsigned int numRegions=m_Regions.size();
   for(Long64_t jentry=0; jentry<nentries;jentry++){
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<<
          EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;

       if(m_commonSelections && (!commonSelections())) continue;
       double wt;
       wt=commonWeight();
       if (mySample=="data") wt=1.0;
       //further selections
       string mySelection, regionname,name, var, vartype;
       size_t pos=0;
       output_branches["weight"].d=wt;
       for(unsigned int ir=0;ir<numRegions;ir++){//fill various regions/selections
      
           mySelection=m_Regions[ir];
           output_branches[mySelection].i=0;//init
           if(applySelections(mySelection)){//apply selections
      
              output_branches[mySelection].i=1;
      
              for(std::map<string, TH1F*>::iterator it=TH1Fs.begin();it!=TH1Fs.end();it++){ 
       
                  name=it->first;
                  pos=name.find("_");
                  regionname=name.substr(0,pos);
       
                  if(regionname != mySelection) continue; //only fill current region of course!
       
                  var=name.substr(pos+1, name.length()-3-pos);//the name is defined as 'regionname_varname_vartype'
                  //if(var=="lep_Pt_0") TH1Fs[it->first]->Fill(lep_Pt_0/GeV,wt);
                  vartype=name.substr(name.length()-1);
       
                  if(vartype=="I") { 
                     if(var.find("tagWeightBin")!=string::npos) 
                        input_branches[var].i=input_branches[var].i<0?0:input_branches[var].i;
                     TH1Fs[name]->Fill( input_branches[var].i, wt);
                     output_branches[var].i=input_branches[var].i;
                  }
       
                  if(vartype=="F") {
                     if(var.find("weight")!=string::npos || var.find("dr")!=string::npos
                        || var.find("nj")!=string::npos || var.find("nb")!=string::npos || 
                        var.find("tight")!=string::npos || var.find("eta")!=string::npos ) 
                        { if(var=="maxeta") {
                             TH1Fs[name]->Fill(fabs(input_branches["tau_eta_0"].f)>fabs(input_branches["tau_eta_1"].f)?fabs(input_branches["tau_eta_0"].f):fabs(input_branches["tau_eta_1"].f), wt);
                             output_branches[var].f=fabs(input_branches["tau_eta_0"].f)>fabs(input_branches["tau_eta_1"].f)?fabs(input_branches["tau_eta_0"].f):fabs(input_branches["tau_eta_1"].f);                                 
                          }
                          else{
                             TH1Fs[name]->Fill( input_branches[var].f, wt);
                             output_branches[var].f=input_branches[var].f;
                          }
			}
                     else {TH1Fs[name]->Fill( (input_branches[var].f)/GeV, wt);
                          output_branches[var].f=(input_branches[var].f)/GeV;
		     }
                  }

                  if(vartype=="D") {
                     TH1Fs[name]->Fill( input_branches[var].d, wt);
                     output_branches[var].d=input_branches[var].d;
                     std::cout<<"Mybdtx: "<<input_branches["Mybdtx"].d<<std::endl;
                  }
              }//end of loop hists map
           }//end of basic selections
       }
       minitree->Fill();
   }//end of event loop
}

void NTUPLE::cutFlow(){
  //get tree weights
  Long64_t nentries = fChain->GetEntries();
  double numinput(0), numevtcln(0), numcomsel(0), numNlepton(0), numtrigmatch(0), numNtau(0), numTightL(0);
  double numwtinput(0), numwtevtcln(0),numwtcomsel(0), numwtNlepton(0), numwttrigmatch(0), numwtNtau(0), numwtTightL(0);
  for(Long64_t jentry=0; jentry<nentries;jentry++){
       /*Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       SumOfTotalWeightedEvents = counts[tree_number-1];*/
        
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<<
          EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<" wt "<<SumOfTotalWeightedEvents<<std::endl;
       double wt;
       wt=commonWeight();
       if (mySample=="data") wt=1.0;

       if(!((onelep_type||dilep_type||trilep_type||quadlep_type))) continue;
          numinput++, numwtinput+=wt;
       if(!passEventCleaning) continue;
          numevtcln++; numwtevtcln+=wt;
       if(m_commonSelections && (!commonSelections())) continue;
          numcomsel++; numwtcomsel+=wt; 
       //if(!(onelep_type>0 && input_branches["lep_isolationFixedCutLoose_0"].i&&(abs(input_branches["lep_ID_0"].f)==13||((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)))) continue;
       if(!(onelep_type>0)) continue;
          numNlepton++; numwtNlepton+=wt;
       if(!lep_isTrigMatch_0) continue;
          numtrigmatch++; numwttrigmatch+=wt;
       if(!(nTaus_OR_Pt25==2&&input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0)) continue;
          numNtau++; numwtNtau+=wt;
       if(!((abs(input_branches["lep_ID_0"].f)==11&&input_branches["lep_isolationFixedCutLoose_0"].i&&input_branches["lep_isTightLH_0"].c&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7&&(int)(input_branches["lep_ambiguityType_0"].c)==0)||(abs(input_branches["lep_ID_0"].f)==13&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5&&input_branches["lep_isolationFixedCutLoose_0"].i))) continue;
          numTightL++; numwtTightL+=wt;
          
  }
  cout<<" Events "<<setw(20)<<" Events (weighted)"<<endl;
  cout<<numinput<<setw(20)<<numwtinput<<endl;
  cout<<numevtcln<<setw(20)<<numwtevtcln<<endl;
  cout<<numcomsel<<setw(20)<<numwtcomsel<<endl;
  cout<<numNlepton<<setw(20)<<numwtNlepton<<endl;
  cout<<numtrigmatch<<setw(20)<<numwttrigmatch<<endl;
  cout<<numNtau<<setw(20)<<numwtNtau<<endl;
  cout<<numTightL<<setw(20)<<numwtTightL<<endl; 
}

void NTUPLE::applyBDT(){

  TString BDT_tth1l2tau = "doc/TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfix_R21.xml";
  TString BDT_tth1l2tauEven ="doc/TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfixTrainEven_R21.xml";
  TString BDT_tth1l2tauOdd ="doc/TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfixTrainOdd_R21.xml";
  std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
  initialiseTMVA_tth1l2tau(BDT_tth1l2tau, BDT_tth1l2tauEven,BDT_tth1l2tauOdd);
  TString path="/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/all/";
  path += mySample+"_bdtx.root";
  TFile *outfile=new TFile(path,"update");
  TTree *outtree=new TTree(m_treeName,"");
  fChain->LoadTree(0);
  //outtree = fChain->GetTree()->CloneTree(0);
  outtree = fChain->CloneTree(0);
  Double_t myBDT, myBDTx;
  outtree->Branch("Mybdt", &myBDT);
  outtree->Branch("Mybdtx", &myBDTx);
  myBDT = -2.;
  myBDTx = -2.;

  Long64_t nentries = fChain->GetEntries();
 
  for(Long64_t jentry=0; jentry<nentries;jentry++){

      fChain->GetEntry(jentry);

      tmva1l2tau_njets25 = input_branches["njets_1l2tau"].i ;
      tmva1l2tau_nbjets25 = input_branches["nbjets_1l2tau"].i;
      tmva1l2tau_htjets = input_branches["HT_jets"].f;
      tmva1l2tau_leadtaupt = input_branches["tau_pt_0"].f/GeV;
      tmva1l2tau_subtaupt = input_branches["tau_pt_1"].f/GeV;
      tmva1l2tau_mtautau = input_branches["mtautau_1l2tau"].f/GeV;
      tmva1l2tau_jjdr = input_branches["jjdrmin_1l2tau"].f;
      tmva1l2tau_etamax = fabs(input_branches["tau_eta_0"].f)>fabs(input_branches["tau_eta_1"].f)? fabs(input_branches["tau_eta_0"].f): fabs(input_branches["tau_eta_1"].f);
      tmva1l2tau_leadtaubtagbin = input_branches["tau_tagWeightBin_0"].i;
      tmva1l2tau_subtaubtagbin = input_branches["tau_tagWeightBin_1"].i;
      myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
      myBDT =myBDT<1.0?myBDT:0.99;
      if(EventNumber%2==1){ // odd events
          myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauEven");
          myBDTx =myBDTx<1.0?myBDTx:0.99;
      }
      else{ // even events
          myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauOdd");
          myBDTx =myBDTx<1.0?myBDTx:0.99;
      }
      outtree->Fill();
  }
  outtree->Write();
  outfile->Close();
}
