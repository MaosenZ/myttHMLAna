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
#include "makeVariables.cxx"

//void NTUPLE::fillHistsMiniTree(std::map<string, TH1F* > & TH1Fs, TTree *minitree){
void NTUPLE::fillHistsMiniTree(std::map<string, std::unique_ptr<TH1F> > & TH1Fs, TTree *minitree){

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
       //topMassReco(top1_mass, top2_mass);
       float mT_lepmet(0), m_blepmin(0), dphi_ltaumet(0), wmass2(0), wmass1(0), pt_lepminustau(-100),
             m_ltau(0), m_ltaumet(0), pt_sum_all(0), pt_sum_nonbjets(0);
       makeVariables(top1_mass, top2_mass, mT_lepmet, m_blepmin, dphi_ltaumet, wmass1, wmass2, pt_lepminustau, 
                     m_ltau, m_ltaumet, pt_sum_all, pt_sum_nonbjets);
       //further selections
       string mySelection, regionname,name, var, vartype;
       size_t pos=0;
       output_branches["weight"].d=wt;
       for(unsigned int ir=0;ir<numRegions;ir++){//fill various regions/selections
      
           mySelection=m_Regions[ir];
           output_branches[mySelection].i=0;//init
           if(applySelections(mySelection)){//apply selections
      
              output_branches[mySelection].i=1;
      
              //for(std::map<string, TH1F*>::iterator it=TH1Fs.begin();it!=TH1Fs.end();it++){ 
              for(std::map<string, std::unique_ptr<TH1F> >::iterator it=TH1Fs.begin();it!=TH1Fs.end();it++){ 
       
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
                  }*/
                  if(var=="Mybdt") {
                     TH1Fs[name]->Fill( Mybdt, wt);
                     output_branches[var].d=Mybdt;
                  }
                  if(var=="Mybdtx") {
                     TH1Fs[name]->Fill( Mybdtx, wt);
                     output_branches[var].d=Mybdtx;
                  }
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
                  if(var=="lep_Pt_0"){
                     TH1Fs[name]->Fill( lep_Pt_0/GeV, wt);
                     output_branches[var].f=lep_Pt_0/GeV;
                  }
                  if(var=="lep_Pt_1") {
                     TH1Fs[name]->Fill( lep_Pt_1/GeV, wt);
                     output_branches[var].f=lep_Pt_1/GeV;
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
                  if(var=="MET_RefFinal_et") {
                     TH1Fs[name]->Fill(MET_RefFinal_et/GeV, wt);
                     output_branches[var].f=MET_RefFinal_et/GeV;
                  }
                  if(var=="Mll01"){
                     TH1Fs[name]->Fill(Mll01/GeV, wt);
                     output_branches[var].f=Mll01/GeV;
                  }
                  //personal variables start from here
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
                  if(var=="mT_lepmet"){
                     TH1Fs[name]->Fill(mT_lepmet/GeV, wt);
                     output_branches[var].f=mT_lepmet/GeV;
                  }
                  if(var=="m_blepmin"){
                     TH1Fs[name]->Fill(m_blepmin/GeV, wt);
                     output_branches[var].f=m_blepmin/GeV;
                  }
                  if(var=="wmass1"){
                     TH1Fs[name]->Fill(wmass1/GeV, wt);
                     output_branches[var].f=wmass1/GeV;
                  }
                  if(var=="wmass2"){
                     TH1Fs[name]->Fill(wmass2/GeV, wt);
                     output_branches[var].f=wmass2/GeV;
                  }
                  if(var=="pt_lepminustau"){
                     TH1Fs[name]->Fill(pt_lepminustau/GeV, wt);
                     output_branches[var].f=pt_lepminustau/GeV;
                  }
                  if(var=="dphi_ltaumet"){
                     TH1Fs[name]->Fill(dphi_ltaumet, wt);
                     output_branches[var].f=dphi_ltaumet;
                  }
                  if(var=="m_ltau"){
                     TH1Fs[name]->Fill(m_ltau/GeV, wt);
                     output_branches[var].f=m_ltau/GeV;
                  }
                  if(var=="m_ltaumet"){
                     TH1Fs[name]->Fill(m_ltaumet/GeV, wt);
                     output_branches[var].f=m_ltaumet/GeV;
                  }
                  if(var=="pt_sum_all"){
                     TH1Fs[name]->Fill(pt_sum_all/GeV, wt);
                     output_branches[var].f=pt_sum_all/GeV;
                  }
                  if(var=="pt_sum_nonbjets"){
                     TH1Fs[name]->Fill(pt_sum_nonbjets/GeV, wt);
                     output_branches[var].f=pt_sum_nonbjets/GeV;
                  }
              }//end of loop hists map
           }//end of basic selections
       }//end of fill Regions
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
  TString path="/global/homes/m/mszhou/work/ttHML/GN1Samps/dilep_looseleps/";
  path += mySample+"_bdtx.root";
  TFile *outfile=new TFile(path,"recreate");
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
      float jjdrmin(99.);
      float sumjets(0.), mtautau_1l2tau(0.), htjets_1l2tau(0);
      int njets_1l2tau = selected_jets_T->size()>7?7:selected_jets_T->size();
      int nbjets(0);
      for(int index = 0; index < njets_1l2tau; index++) {
          int index_jet = selected_jets_T->at(index);
          sumjets +=m_jet_pt->at(index_jet);
          if(m_jet_flavor_weight_MV2c10->at(index_jet)>0.83) ++nbjets;
          for(int index2 = index+1; index2 < njets_1l2tau; index2++) {
              int index2_jet = selected_jets_T->at(index2);
              float this_DR = sqrt(pow((m_jet_eta->at(index_jet) - m_jet_eta->at(index2_jet)), 2.0) + pow((acos(cos(m_jet_phi->at(index_jet) - m_jet_phi->at(index2_jet)))), 2.0));
              if (this_DR < jjdrmin)jjdrmin = this_DR;
          }
      }
      htjets_1l2tau=sumjets;
      TLorentzVector p4tau[2];
      p4tau[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0, tau_phi_0,tau_E_0);
      p4tau[1].SetPtEtaPhiE(tau_pt_1,tau_eta_1, tau_phi_1,tau_E_1);
      mtautau_1l2tau = (p4tau[0]+p4tau[1]).M();
      
      tmva1l2tau_njets25 = njets_1l2tau;
      tmva1l2tau_nbjets25 = nbjets;
      tmva1l2tau_htjets = htjets_1l2tau/GeV;
      tmva1l2tau_leadtaupt = tau_pt_0/GeV;
      tmva1l2tau_subtaupt = tau_pt_1/GeV;
      tmva1l2tau_mtautau = mtautau_1l2tau/GeV;
      tmva1l2tau_jjdr = jjdrmin;
      tmva1l2tau_etamax = fabs(tau_eta_0)>fabs(tau_eta_1)? fabs(tau_eta_0): fabs(tau_eta_1);
      tmva1l2tau_leadtaubtagbin = tau_tagWeightBin_0;
      tmva1l2tau_subtaubtagbin = tau_tagWeightBin_1;
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
      /*std::cout<<" njets_1l2tau: "<<tmva1l2tau_njets25<<std::endl;
      std::cout<<" nbjets_1l2tau: "<<tmva1l2tau_nbjets25<<std::endl;
      std::cout<<" htjets_1l2tau: "<<tmva1l2tau_htjets<<std::endl;
      std::cout<<" tmva1l2tau_leadtaupt: "<<tmva1l2tau_leadtaupt<<std::endl;
      std::cout<<" tmva1l2tau_subtaupt: "<<tmva1l2tau_subtaupt<<std::endl;
      std::cout<<" tmva1l2tau_mtautau: "<<tmva1l2tau_mtautau<<std::endl;
      std::cout<<" tmva1l2tau_jjdr: "<<tmva1l2tau_jjdr<<std::endl;
      std::cout<<" tmva1l2tau_etamax: "<<tmva1l2tau_etamax<<std::endl;
      std::cout<<" myBDTx: "<<myBDTx<<std::endl;*/
      outtree->Fill();
  }
  outtree->Write();
  outfile->Close();
}
