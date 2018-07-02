#include "myttHAna/BDTcalculation.h"
#include "myttHAna/NTUPLE.h"

void ApplyBDT(){

  TString BDT_tth1l2tau = "doc/TMVAClassification_BDTG.weights10varbtagtaupt25Triglept27tauTTbvetoWT_R21.xml";
  std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
  initialiseTMVA_tth1l2tau(BDT_tth1l2tau);
  
  tmva1l2tau_njets25 = njets_1l2tau ;
  tmva1l2tau_nbjets25 = nbjets_1l2tau;
  tmva1l2tau_htjets = HT_jets;
  tmva1l2tau_leadtaupt = tau_pt_0/GeV;
  tmva1l2tau_subtaupt = tau_pt_1/GeV;
  tmva1l2tau_mtautau = mtautau_1l2tau;
  tmva1l2tau_jjdr = jjdrmin_1l2tau;
  tmva1l2tau_etamax = fabs(tau_eta_0)>fabs(tau_eta_1)? fabs(tau_eta_0): fabs(tau_eta_1);
  tmva1l2tau_leadtaubtagbin = tau_tagWeightBin_0;
  tmva1l2tau_subtaubtagbin = tau_tagWeightBin_1;
  myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
  myBDT =myBDT<1.0?myBDT:0.99; 
   
}
