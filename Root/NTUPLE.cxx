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
#include "make2l2tauVariables.cxx"

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
       float m_minlepb, dR_minlepb_tautau,  m_tautau, dR_ll, dR_ll_tautau, pt_sum_bjets;
       make2l2tauVariables( m_minlepb,  dR_minlepb_tautau,  m_tautau, dR_ll,  dR_ll_tautau, pt_sum_bjets);
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
                   //2l2tau vars
                  if(var=="m_minlepb"){
                     TH1Fs[name]->Fill(m_minlepb/GeV, wt);
                     output_branches[var].f=m_minlepb/GeV;
                  }
                  if(var=="m_tautau"){
                     TH1Fs[name]->Fill(m_tautau/GeV, wt);
                     output_branches[var].f=m_tautau/GeV;
                  }
                  if(var=="dR_minlepb_tautau"){
                     TH1Fs[name]->Fill(dR_minlepb_tautau, wt);
                     output_branches[var].f=dR_minlepb_tautau;
                  }
                  if(var=="dR_ll"){
                     TH1Fs[name]->Fill(dR_ll, wt);
                     output_branches[var].f=dR_ll;
                  }
                  if(var=="dR_ll_tautau"){
                     TH1Fs[name]->Fill(dR_ll_tautau, wt);
                     output_branches[var].f=dR_ll_tautau;
                  }
                  if(var=="pt_sum_bjets"){
                     TH1Fs[name]->Fill(pt_sum_bjets/GeV, wt);
                     output_branches[var].f=pt_sum_bjets/GeV;
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

  TString BDT_tth2l2tau = "doc/TMVAClassification_BDTG.weights6vartaupt25Triglept27tauMMbvetoTrainRandom_mimic2l2tau_R21.xml";
  std::cout<<" which BDT ? "<<BDT_tth2l2tau<<std::endl;
  initialiseTMVA_tth2l2tau(BDT_tth2l2tau);
  TString path="/global/homes/m/mszhou/work/ttHML/GN1Samps/dilep_looseleps/";
  path += mySample+"_2l2taubdt.root";
  TFile *outfile=new TFile(path,"recreate");
  TTree *outtree=new TTree(m_treeName,"");
  fChain->LoadTree(0);
  //outtree = fChain->GetTree()->CloneTree(0);
  outtree = fChain->CloneTree(0);
  Double_t myBDT;
  outtree->Branch("Mybdt", &myBDT);
  myBDT = -2.;

  Long64_t nentries = fChain->GetEntries();
 
  for(Long64_t jentry=0; jentry<nentries;jentry++){

      fChain->GetEntry(jentry);
      //std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<< EventNumber<<" Run "<<RunNumber<<std::endl;
      float m_minlepb, dR_minlepb_tautau,  m_tautau, dR_ll, dR_ll_tautau, pt_sum_bjets;
      make2l2tauVariables( m_minlepb,  dR_minlepb_tautau,  m_tautau, dR_ll,  dR_ll_tautau, pt_sum_bjets);

      tmva2l2tau_htbjets = pt_sum_bjets;
      tmva2l2tau_leadtaupt = tau_pt_0/GeV;
      tmva2l2tau_subtaupt = tau_pt_1/GeV;
      tmva2l2tau_mtautau = m_tautau/GeV;
      tmva2l2tau_drlbditau = dR_minlepb_tautau;
      tmva2l2tau_etamax = fabs(tau_eta_0)>fabs(tau_eta_1)? fabs(tau_eta_0): fabs(tau_eta_1);
      
      myBDT = reader_tth2l2tau->EvaluateMVA("BDT_tth2l2tau");
      myBDT =myBDT<1.0?myBDT:0.99;
      std::cout<<" htbjets_2l2tau: "<<tmva2l2tau_htbjets<<std::endl;
      std::cout<<" tmva2l2tau_leadtaupt: "<<tmva2l2tau_leadtaupt<<std::endl;
      std::cout<<" tmva2l2tau_subtaupt: "<<tmva2l2tau_subtaupt<<std::endl;
      std::cout<<" tmva2l2tau_mtautau: "<<tmva2l2tau_mtautau<<std::endl;
      std::cout<<" tmva2l2tau_etamax: "<<tmva2l2tau_etamax<<std::endl;
      std::cout<<" tmva2l2tau_drlbditau: "<<tmva2l2tau_drlbditau<<std::endl;
      std::cout<<" myBDT: "<<myBDT<<std::endl;
      outtree->Fill();
  }
  outtree->Write();
  outfile->Close();
}
