#define NTUPLE_cxx
#include "../inc/NTUPLE.h"
#include "../inc/BDTcalculation.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include <string>
#include <fstream>
#include <sstream>
#include "commonSelections.cxx"
#include "commonWeight.cxx"
#include "applySelections.cxx"
#include "topMassReco.cxx"

void NTUPLE::fillHistsMiniTree(std::map<string, TH1F* > & TH1Fs, TTree *minitree){

   Long64_t nentries = fChain->GetEntries();
   unsigned int numRegions=m_Regions.size();
   for(Long64_t jentry=0; jentry<nentries;jentry++){
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<<
          EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;

       //commons
       if(m_commonSelections && (!commonSelections())) continue;
       double wt;
       wt=commonWeight();
       if (mySample=="data") wt=1.0;

       //define some variables here:
         //top mass
       float top1_mass(0), top2_mass(0);
       topMassReco(top1_mass, top2_mass);

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
      
                  /*if(var=="MVA1l2tau_weight") {
                     TH1Fs[name]->Fill( MVA1l2tau_weight, wt);
                     output_branches[var].f=MVA1l2tau_weight;
                  }
                  if(var=="Mybdt") {
                     TH1Fs[name]->Fill( Mybdt, wt);
                     output_branches[var].d=Mybdt;
                  }
                  if(var=="Mybdtx") {
                     TH1Fs[name]->Fill( Mybdtx, wt);
                     output_branches[var].d=Mybdtx;
                  }*/
                  if(var=="HT_jets") {
                     TH1Fs[name]->Fill( HT_jets/GeV, wt);
                     output_branches[var].f=HT_jets/GeV;
                  }
                  if(var=="nJets_OR_T") {
                     TH1Fs[name]->Fill( nJets_OR_T, wt);
                     output_branches[var].i=nJets_OR_T;
                  }
                  if(var=="nJets_OR_T_MV2c10_70") {
                     TH1Fs[name]->Fill( nJets_OR_T_MV2c10_70, wt);
                     output_branches[var].i=nJets_OR_T_MV2c10_70;
                  }
                  /*if(var=="jjdrmin_1l2tau") {
                     TH1Fs[name]->Fill( jjdrmin_1l2tau, wt);
                     output_branches[var].f=jjdrmin_1l2tau;
                  }
                  if(var=="mtautau_1l2tau") {
                     TH1Fs[name]->Fill( mtautau_1l2tau/GeV, wt);
                     output_branches[var].f=mtautau_1l2tau/GeV;
                  }*/
                  if(var=="tau_pt_0"){
                     TH1Fs[name]->Fill( tau_pt_0/GeV, wt);
                     output_branches[var].f=tau_pt_0/GeV;
                  }
                  if(var=="tau_pt_1") {
                     TH1Fs[name]->Fill( tau_pt_1/GeV, wt);
                     output_branches[var].f=tau_pt_1/GeV;
                  }
                  /*if(var=="njets_1l2tau") {
                     TH1Fs[name]->Fill( njets_1l2tau, wt);
                     output_branches[var].f=njets_1l2tau;
                  }
                  if(var=="nbjets_1l2tau") {
                     TH1Fs[name]->Fill( nbjets_1l2tau, wt);
                     output_branches[var].f=nbjets_1l2tau;
                  }*/
                  if(var=="tau_truthType_0") {
                     TH1Fs[name]->Fill( tau_truthType_0, wt);
                     output_branches[var].i=tau_truthType_0;
                  }
                  if(var=="tau_truthType_1") {
                     TH1Fs[name]->Fill( tau_truthType_1, wt);
                     output_branches[var].i=tau_truthType_1;
                  }
                  if(var=="tau_truthOrigin_0"){
                     TH1Fs[name]->Fill( tau_truthOrigin_0, wt);
                     output_branches[var].i=tau_truthOrigin_0;
                  }
                  if(var=="tau_truthOrigin_1") {
                     TH1Fs[name]->Fill( tau_truthOrigin_1, wt);
                     output_branches[var].i=tau_truthOrigin_1;
                  }
                  if(var=="tau_tight_0") {
                     TH1Fs[name]->Fill( tau_tight_0, wt);
                     output_branches[var].f=tau_tight_0;
                  }
                  if(var=="tau_tight_1") {
                     TH1Fs[name]->Fill( tau_tight_1, wt);
                     output_branches[var].f=tau_tight_1;
                  }
                  if(var=="tau_eta_0") {
                     TH1Fs[name]->Fill( tau_eta_0, wt);
                     output_branches[var].f=tau_eta_0;
                  }
                  if(var=="tau_eta_1") {
                     TH1Fs[name]->Fill( tau_eta_1, wt);
                     output_branches[var].f=tau_eta_1;
                  }
                  if(var=="tau_tagWeightBin_0") {
                     TH1Fs[name]->Fill( tau_tagWeightBin_0, wt);
                     output_branches[var].i=tau_tagWeightBin_0;
                  }
                  if(var=="tau_tagWeightBin_1") {
                     TH1Fs[name]->Fill( tau_tagWeightBin_1, wt);
                     output_branches[var].i=tau_tagWeightBin_1;
                  }
                  if(var=="maxeta") {
                     TH1Fs[name]->Fill( fabs(tau_eta_0)>fabs(tau_eta_1)?fabs(tau_eta_0):fabs(tau_eta_1), wt);
                     output_branches[var].f=fabs(tau_eta_0)>fabs(tau_eta_1)?fabs(tau_eta_0):fabs(tau_eta_1);
                  }
                  if(var=="top1_mass"){
                     TH1Fs[name]->Fill(top1_mass/GeV, wt);
                     output_branches[var].f=top1_mass/GeV;
                  }
                  if(var=="top2_mass"){
                     TH1Fs[name]->Fill(top2_mass/GeV, wt);
                     output_branches[var].f=top2_mass/GeV;
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
       //if(!(onelep_type>0 && lep_isolationFixedCutLoose_0&&(abs(lep_ID_0)==13||((abs(lep_ID_0)==11)&&lep_isTightLH_0)))) continue;
       if(!(onelep_type>0)) continue;
          numNlepton++; numwtNlepton+=wt;
       if(!lep_isTrigMatch_0) continue;
          numtrigmatch++; numwttrigmatch+=wt;
       //if(!(nTaus_OR_Pt25==2&&input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0)) continue;
       if( !(nTaus_OR_Pt25==1 && tau_tight_0) ) continue;
       if ( !(tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4) ) continue;
          numNtau++; numwtNtau+=wt;
       //if(!((abs(lep_ID_0)==11&&lep_isolationFixedCutLoose_0&&lep_isTightLH_0&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7&&(int)(input_branches["lep_ambiguityType_0"].c)==0)||(abs(lep_ID_0)==13&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5&&lep_isolationFixedCutLoose_0))) continue;
       if(!((abs(lep_ID_0)==11&&lep_isolationFixedCutLoose_0&&lep_isTightLH_0)||(abs(lep_ID_0)==13&&lep_isolationFixedCutLoose_0))) continue; //loose lepton
       if (lep_Pt_0<27e3) continue;
          numTightL++; numwtTightL+=wt;
       //jets
       if( !(nJets_OR_T>=4 && nJets_OR_T_MV2c10_70>=2) ) continue;
       //top mass
       float top_mass1(0), top_mass2(0);
       topMassReco(top_mass1, top_mass2);

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

/*void NTUPLE::applyBDT(){

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
      //std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<< EventNumber<<" Run "<<RunNumber<<std::endl;
      tmva1l2tau_njets25 = input_branches["njets_1l2tau"].f;
      tmva1l2tau_nbjets25 = input_branches["nbjets_1l2tau"].f;
      tmva1l2tau_htjets = input_branches["htjets_1l2tau"].f;
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
      std::cout<<" njets_1l2tau: "<<tmva1l2tau_njets25<<std::endl;
      std::cout<<" nbjets_1l2tau: "<<tmva1l2tau_nbjets25<<std::endl;
      std::cout<<" htjets_1l2tau: "<<tmva1l2tau_htjets<<std::endl;
      std::cout<<" tmva1l2tau_leadtaupt: "<<tmva1l2tau_leadtaupt<<std::endl;
      std::cout<<" tmva1l2tau_subtaupt: "<<tmva1l2tau_subtaupt<<std::endl;
      std::cout<<" tmva1l2tau_mtautau: "<<tmva1l2tau_mtautau<<std::endl;
      std::cout<<" tmva1l2tau_jjdr: "<<tmva1l2tau_jjdr<<std::endl;
      std::cout<<" tmva1l2tau_etamax: "<<tmva1l2tau_etamax<<std::endl;
      std::cout<<" myBDTx: "<<myBDTx<<std::endl;
      outtree->Fill();
  }
  outtree->Write();
  outfile->Close();
}*/
