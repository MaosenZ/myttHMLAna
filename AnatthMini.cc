#define AnatthMini_cxx
#include "AnatthMini.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "BDTcalculation.h"

const double btagwpCut[4]={0.94,0.83,0.64,0.11}; // 60, 70, 77, 85 % (0.8244273); // 0.645925 77% for MV2c10; 70% 0.8244273
//const double btagwpCut(0.8244273);

void AnatthMini::Loop()
{
//   In a ROOT session, you can do:
//      root> .L AnatthMini.C
//      root> AnatthMini t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  int GeV(1000);
  bool dump(false);
  if(!_ismc)dump = true;
  _histf = new TFile(_outhist+".root", "RECREATE");
  std::ofstream* fout_txt;
  if(dump)fout_txt = new std::ofstream(_outhist+".txt");
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights10vartaupt25Triglept27tauMM_R21.xml";
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTT_R21.xml";
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights10varbtagtaupt25Triglept27tauMM_R21.xml";
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights10varbtagtaupt25Triglept27tauTTbvetoetamax2_R21.xml";
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights10varbtagtaupt25Triglept27tauTTbvetoWT_R21.xml";
  TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfix_R21.xml";
  TString BDT_tth1l2tauEven ="TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfixTrainEven_R21.xml";
  TString BDT_tth1l2tauOdd ="TMVAClassification_BDTG.weights8varbtagtaupt25Triglept27tauTTbvetoWTfixTrainOdd_R21.xml"; 
  //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights9varbtagtaupt25Triglept27tauTTbvetoWT_R21.xml";
  std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
  initialiseTMVA_tth1l2tau(BDT_tth1l2tau,BDT_tth1l2tauEven,BDT_tth1l2tauOdd);
  //
  const char *mylabel[5]={"Other","Gluon","Light","C","B"};
  const char *mylabelx[3]={"TwoFakes", "OneFake","RealTaus"}; 
  Float_t xbins[4]={-1.,0.0,0.6,1.0};
  //1l1tau
  TH1D* h1ltau_njets = new TH1D("h1ltau_njets","h1ltau_njets", 6, 0.,6.);
  TH1D* h1ltau_nbjets = new TH1D("h1ltau_nbjets","h1ltau_nbjets", 4, 0.,4.);
  TH1D* h1ltau_njbjets = new TH1D("h1ltau_njbjets","h1ltau_njbjets", 100, 0.,100.);
  TH1D* h1ltau_htjets = new TH1D("h1ltau_htjets","h1ltau_htjets", 50, 0.,1000.);
  TH1D* h1ltau_met = new TH1D("h1ltau_met","h1ltau_met", 50, 0.,500.);
  TH1D* h1ltau_lept = new TH1D("h1ltau_lept","h1ltau_lept", 50, 0.,250.);
  TH1D* h1ltau_totcharge = new TH1D("h1ltau_totcharge","h1ltau_totcharge", 50, -5.,5.);
  TH1D* h1ltau_ljdr = new TH1D("h1ltau_ljdr","h1ltau_ljdr", 25, 0.,5.);
  TH1D* h1ltau_jjdr = new TH1D("h1ltau_jjdr","h1ltau_jjdr", 25, 0.,5.);
  TH1D* h1ltau_taupt = new TH1D("h1ltau_taupt","h1ltau_taupt", 50, 0.,250.);
  TH1D* h1ltau_taueta = new TH1D("h1ltau_taueta","h1ltau_taueta", 50, -5.,5.);
  TH1D* h1ltau_tautight = new TH1D("h1ltau_tautight","h1ltau_tautight", 5, 0.,5.);
  TH1D* h1ltau_taubtag = new TH1D("h1ltau_taubtag","h1ltau_taubtag", 5, 0.,5.);
  TH1D* h1ltau_taucharge = new TH1D("h1ltau_taucharge","h1ltau_taucharge", 5, -2.5,2.5);
  TH1D* h1ltau_tauntrk = new TH1D("h1ltau_tauntrk","h1ltau_tauntrk", 5, 0.,5.);
  TH1D* h1ltau_tautruth = new TH1D("h1ltau_tautruth","h1ltau_tautruth", 25, 0.,25.);
  TH1D* h1ltau_bdtjetsigtrans = new TH1D("h1ltau_bdtjetsigtrans","h1ltau_bdtjetsigtrans", 20, 0.,1.);
  TH1D* h1ltau_tauptv = new TH1D("h1ltau_tauptv","h1ltau_tauptv", 20, -1., 1.); 
  // 1ltau with extra loose tau os
  TH1D* h1ltau_Ltauosnjets = new TH1D("h1ltau_Ltauosnjets","h1ltau_Ltauosnjets", 10, 0.,10.);
  TH1D* h1ltau_Ltauosnbjets = new TH1D("h1ltau_Ltauosnbjets","h1ltau_Ltauosnbjets", 10, 0.,10.);
  TH1D* h1ltau_Ltauoshtjets = new TH1D("h1ltau_Ltauoshtjets","h1ltau_Ltauoshtjets", 50, 0.,1000.);
  TH1D* h1ltau_Ltauosleadtaupt = new TH1D("h1ltau_Ltauosleadtaupt","h1ltau_Ltauosleadtaupt", 50, 0.,250.);
  TH1D* h1ltau_Ltauossubtaupt = new TH1D("h1ltau_Ltauossubtaupt","h1ltau_Ltauossubtaupt", 50, 0.,250.);
  TH1D* h1ltau_Ltauosmtautau = new TH1D("h1ltau_Ltauosmtautau","h1ltau_Ltauosmtautau", 50, 0.,250.);
  TH1D* h1ltau_Ltauostruth = new TH1D("h1ltau_Ltauostruth","h1ltau_Ltauostruth", 3, 0.,3.);
  TH1D* h1ltau_Ltauosjjdr = new TH1D("h1ltau_Ltauosjjdr","h1ltau_Ltauosjjdr", 25, 0.,5.);
  TH1D* h1ltau_Ltauosoldbdt = new TH1D("h1ltau_Ltauosoldbdt","h1ltau_Ltauosoldbdt", 8, -1., 1.);
  TH1D* h1ltau_Ltauosoldbdt3bins = new TH1D("h1ltau_Ltauosoldbdt3bins","h1ltau_Ltauosoldbdt3bins", 3,xbins);
  TH1D* h1ltau_Ltauosfakeorig = new TH1D("h1ltau_Ltauosfakeorig","h1ltau_Ltauosfakeorig",5, 0., 5.); 
  TH1D* h1ltau_Ltauosleadbdtjetsigtrans = new TH1D("h1ltau_Ltauosleadbdtjetsigtrans","h1ltau_Ltauosleadbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1ltau_Ltauossubbdtjetsigtrans = new TH1D("h1ltau_Ltauossubbdtjetsigtrans","h1ltau_Ltauossubbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1ltau_Ltauosleadtauptv = new TH1D("h1ltau_Ltauosleadtauptv","h1ltau_Ltauosleadtauptv", 20, -1., 1.);
  TH1D* h1ltau_Ltauossubtauptv = new TH1D("h1ltau_Ltauossubtauptv","h1ltau_Ltauossubtauptv", 20, -1., 1.);
  TH1D* h1ltau_Ltauosbdt = new TH1D("h1ltau_Ltauosbdt","h1ltau_Ltauosbdt", 8, -1., 1.);
  TH1D* h1ltau_Ltauosbdt3bins = new TH1D("h1ltau_Ltauosbdt3bins","h1ltau_Ltauosbdt3bins", 3,xbins);
  TH1D* h1ltau_Ltauosmtautaubdtcut = new TH1D("h1ltau_Ltauosmtautaubdtcut","h1ltau_Ltauosmtautaubdtcut", 50, 0.,250.);
  TH1D* h1ltau_Ltauosnjetsbdtcut = new TH1D("h1ltau_Ltauosnjetsbdtcut","h1ltau_Ltauosnjetsbdtcut", 10, 0.,10.);
  // truth 
  TH1D* h1ltau_Ltauosnjetstruth = new TH1D("h1ltau_Ltauosnjetstruth","h1ltau_Ltauosnjetstruth", 10, 0.,10.);
  TH1D* h1ltau_Ltauosnbjetstruth = new TH1D("h1ltau_Ltauosnbjetstruth","h1ltau_Ltauosnbjetstruth", 10, 0.,10.);
  TH1D* h1ltau_Ltauoshtjetstruth = new TH1D("h1ltau_Ltauoshtjetstruth","h1ltau_Ltauoshtjetstruth", 50, 0.,1000.);
  TH1D* h1ltau_Ltauosleadtaupttruth = new TH1D("h1ltau_Ltauosleadtaupttruth","h1ltau_Ltauosleadtaupttruth", 50, 0.,250.);
  TH1D* h1ltau_Ltauossubtaupttruth = new TH1D("h1ltau_Ltauossubtaupttruth","h1ltau_Ltauossubtaupttruth", 50, 0.,250.);
  TH1D* h1ltau_Ltauosmtautautruth = new TH1D("h1ltau_Ltauosmtautautruth","h1ltau_Ltauosmtautautruth", 50, 0.,250.);
  TH1D* h1ltau_Ltauosjjdrtruth = new TH1D("h1ltau_Ltauosjjdrtruth","h1ltau_Ltauosjjdrtruth", 25, 0.,5.);
  TH1D* h1ltau_Ltauosoldbdttruth = new TH1D("h1ltau_Ltauosoldbdttruth","h1ltau_Ltauosoldbdttruth", 8, -1., 1.);
  TH1D* h1ltau_Ltauosoldbdt3binstruth = new TH1D("h1ltau_Ltauosoldbdt3binstruth","h1ltau_Ltauosoldbdt3binstruth", 3,xbins);
  TH1D* h1ltau_Ltauosleadbdtjetsigtranstruth = new TH1D("h1ltau_Ltauosleadbdtjetsigtranstruth","h1ltau_bLtauosleaddtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1ltau_Ltauossubbdtjetsigtranstruth = new TH1D("h1ltau_Ltauossubbdtjetsigtranstruth","h1ltau_Ltauossubbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1ltau_Ltauosleadtauptvtruth = new TH1D("h1ltau_Ltauosleadtauptvtruth","h1ltau_Ltauosleadtauptvtruth", 20, -1., 1.);
  TH1D* h1ltau_Ltauossubtauptvtruth = new TH1D("h1ltau_Ltauossubtauptvtruth","h1ltau_Ltauossubtauptvtruth", 20, -1., 1.);
  TH1D* h1ltau_Ltauosbdttruth = new TH1D("h1ltau_Ltauosbdttruth","h1ltau_Ltauosbdttruth", 8, -1., 1.);
  TH1D* h1ltau_Ltauosbdt3binstruth = new TH1D("h1ltau_Ltauosbdt3binstruth","h1ltau_Ltauosbdt3binstruth", 3,xbins);
  //
  // 1ltau with extra loose tau ss
  TH1D* h1ltau_Ltaussnjets = new TH1D("h1ltau_Ltaussnjets","h1ltau_Ltaussnjets", 10, 0.,10.);
  TH1D* h1ltau_Ltaussnbjets = new TH1D("h1ltau_Ltaussnbjets","h1ltau_Ltaussnbjets", 10, 0.,10.);
  TH1D* h1ltau_Ltausshtjets = new TH1D("h1ltau_Ltausshtjets","h1ltau_Ltausshtjets", 50, 0.,1000.);
  TH1D* h1ltau_Ltaussleadtaupt = new TH1D("h1ltau_Ltaussleadtaupt","h1ltau_Ltaussleadtaupt", 50, 0.,250.);
  TH1D* h1ltau_Ltausssubtaupt = new TH1D("h1ltau_Ltausssubtaupt","h1ltau_Ltausssubtaupt", 50, 0.,250.);
  TH1D* h1ltau_Ltaussmtautau = new TH1D("h1ltau_Ltaussmtautau","h1ltau_Ltaussmtautau", 50, 0.,250.);
  TH1D* h1ltau_Ltausstruth = new TH1D("h1ltau_Ltausstruth","h1ltau_Ltausstruth", 3, 0.,3.);
  TH1D* h1ltau_Ltaussjjdr = new TH1D("h1ltau_Ltaussjjdr","h1ltau_Ltaussjjdr", 25, 0.,5.);
  TH1D* h1ltau_Ltaussoldbdt = new TH1D("h1ltau_Ltaussoldbdt","h1ltau_Ltaussoldbdt", 8, -1., 1.);
  TH1D* h1ltau_Ltaussoldbdt3bins = new TH1D("h1ltau_Ltaussoldbdt3bins","h1ltau_Ltaussoldbdt3bins", 3,xbins);
  TH1D* h1ltau_Ltaussfakeorig = new TH1D("h1ltau_Ltaussfakeorig","h1ltau_Ltaussfakeorig",5, 0., 5.); 
  TH1D* h1ltau_Ltaussleadbdtjetsigtrans = new TH1D("h1ltau_Ltaussleadbdtjetsigtrans","h1ltau_bLtaussleaddtjetsigtrans", 20, 0.,1.);
  TH1D* h1ltau_Ltausssubbdtjetsigtrans = new TH1D("h1ltau_Ltausssubbdtjetsigtrans","h1ltau_Ltausssubbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1ltau_Ltaussleadtauptv = new TH1D("h1ltau_Ltaussleadtauptv","h1ltau_Ltaussleadtauptv", 20, -1., 1.);
  TH1D* h1ltau_Ltausssubtauptv = new TH1D("h1ltau_Ltausssubtauptv","h1ltau_Ltausssubtauptv", 20, -1., 1.);
  TH1D* h1ltau_Ltaussbdt = new TH1D("h1ltau_Ltaussbdt","h1ltau_Ltaussbdt", 8, -1., 1.);
  TH1D* h1ltau_Ltaussbdt3bins = new TH1D("h1ltau_Ltaussbdt3bins","h1ltau_Ltaussbdt3bins", 3,xbins);
  TH1D* h1ltau_Ltaussmtautaubdtcut = new TH1D("h1ltau_Ltaussmtautaubdtcut","h1ltau_Ltaussmtautaubdtcut", 50, 0.,250.);
  TH1D* h1ltau_Ltaussnjetsbdtcut = new TH1D("h1ltau_Ltaussnjetsbdtcut","h1ltau_Ltaussnjetsbdtcut", 10, 0.,10.);
  // truth 
  TH1D* h1ltau_Ltaussnjetstruth = new TH1D("h1ltau_Ltaussnjetstruth","h1ltau_Ltaussnjetstruth", 10, 0.,10.);
  TH1D* h1ltau_Ltaussnbjetstruth = new TH1D("h1ltau_Ltaussnbjetstruth","h1ltau_Ltaussnbjetstruth", 10, 0.,10.);
  TH1D* h1ltau_Ltausshtjetstruth = new TH1D("h1ltau_Ltausshtjetstruth","h1ltau_Ltausshtjetstruth", 50, 0.,1000.);
  TH1D* h1ltau_Ltaussleadtaupttruth = new TH1D("h1ltau_Ltaussleadtaupttruth","h1ltau_Ltaussleadtaupttruth", 50, 0.,250.);
  TH1D* h1ltau_Ltausssubtaupttruth = new TH1D("h1ltau_Ltausssubtaupttruth","h1ltau_Ltausssubtaupttruth", 50, 0.,250.);
  TH1D* h1ltau_Ltaussmtautautruth = new TH1D("h1ltau_Ltaussmtautautruth","h1ltau_Ltaussmtautautruth", 50, 0.,250.);
  TH1D* h1ltau_Ltaussjjdrtruth = new TH1D("h1ltau_Ltaussjjdrtruth","h1ltau_Ltaussjjdrtruth", 25, 0.,5.);
  TH1D* h1ltau_Ltaussoldbdttruth = new TH1D("h1ltau_Ltaussoldbdttruth","h1ltau_Ltaussoldbdttruth", 8, -1., 1.);
  TH1D* h1ltau_Ltaussoldbdt3binstruth = new TH1D("h1ltau_Ltaussoldbdt3binstruth","h1ltau_Ltaussoldbdt3binstruth", 3,xbins);
  TH1D* h1ltau_Ltaussleadbdtjetsigtranstruth = new TH1D("h1ltau_Ltaussleadbdtjetsigtranstruth","h1ltau_bLtaussleaddtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1ltau_Ltausssubbdtjetsigtranstruth = new TH1D("h1ltau_Ltausssubbdtjetsigtranstruth","h1ltau_Ltausssubbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1ltau_Ltaussleadtauptvtruth = new TH1D("h1ltau_Ltaussleadtauptvtruth","h1ltau_Ltaussleadtauptvtruth", 20, -1., 1.);
  TH1D* h1ltau_Ltausssubtauptvtruth = new TH1D("h1ltau_Ltausssubtauptvtruth","h1ltau_Ltausssubtauptvtruth", 20, -1., 1.);
  TH1D* h1ltau_Ltaussbdttruth = new TH1D("h1ltau_Ltaussbdttruth","h1ltau_Ltaussbdttruth", 8, -1., 1.);
  TH1D* h1ltau_Ltaussbdt3binstruth = new TH1D("h1ltau_Ltaussbdt3binstruth","h1ltau_Ltaussbdt3binstruth", 3,xbins);
 //1l2tau
  TH1D* h1l2tau_njets = new TH1D("h1l2tau_njets","h1l2tau_njets", 6, 0.,6.);
  TH1D* h1l2tau_nbjets = new TH1D("h1l2tau_nbjets","h1l2tau_nbjets", 4, 0.,4.);
  TH1D* h1l2tau_njbjets = new TH1D("h1l2tau_njbjets","h1l2tau_njbjets", 100, 0.,100.);
  TH1D* h1l2tau_htjets = new TH1D("h1l2tau_htjets","h1l2tau_htjets", 50, 0.,1000.);
  TH1D* h1l2tau_leadtaupt = new TH1D("h1l2tau_leadtaupt","h1l2tau_leadtaupt", 10, 25.,125.);
  TH1D* h1l2tau_subtaupt = new TH1D("h1l2tau_subtaupt","h1l2tau_subtaupt", 10, 25.,125.);
  TH1D* h1l2tau_mtautau = new TH1D("h1l2tau_mtautau","h1l2tau_mtautau", 20, 0.,200.);
  TH1D* h1l2tau_met = new TH1D("h1l2tau_met","h1l2tau_met", 50, 0.,500.);
  TH1D* h1l2tau_lept = new TH1D("h1l2tau_lept","h1l2tau_lept", 50, 0.,250.);
  TH1D* h1l2tau_totcharge = new TH1D("h1l2tau_totcharge","h1l2tau_totcharge", 50, -5.,5.);
  TH1D* h1l2tau_ljdr = new TH1D("h1l2tau_ljdr","h1l2tau_ljdr", 25, 0.,5.);
  TH1D* h1l2tau_jjdr = new TH1D("h1l2tau_jjdr","h1l2tau_jjdr", 25, 0.,5.);
  TH1D* h1l2tau_etamax = new TH1D("h1l2tau_etamax","h1l2tau_etamax", 10, 0.,2.5);
  TH1D* h1l2tau_bdtT3bins = new TH1D("h1l2tau_bdtT3bins","h1l2tau_bdtT3bins", 3,xbins);
  // 12tau with two tau os
  TH1D* h1l2tauos_njets = new TH1D("h1l2tauos_njets","h1l2tauos_njets", 6, 0.,6.);
  TH1D* h1l2tauos_nbjets = new TH1D("h1l2tauos_nbjets","h1l2tauos_nbjets", 4, 0.,4.);
  TH1D* h1l2tauos_htjets = new TH1D("h1l2tauos_htjets","h1l2tauos_htjets", 20, 0.,800.);
  TH1D* h1l2tauos_leadtaupt = new TH1D("h1l2tauos_leadtaupt","h1l2tauos_leadtaupt", 10, 25.,125.);
  TH1D* h1l2tauos_subtaupt = new TH1D("h1l2tauos_subtaupt","h1l2tauos_subtaupt", 10, 25.,125.);
  TH1D* h1l2tauos_mtautau = new TH1D("h1l2tauos_mtautau","h1l2tauos_mtautau", 20, 0.,200.);
  TH1D* h1l2tauos_truth = new TH1D("h1l2tauos_truth","h1l2tauos_truth", 3, 0.,3.);
  TH1D* h1l2tauos_jjdr = new TH1D("h1l2tauos_jjdr","h1l2tauos_jjdr", 10, 0.,4.);
  TH1D* h1l2tauos_etamax = new TH1D("h1l2tauos_etamax","h1l2tauos_etamax", 10, 0.,2.5);
  TH1D* h1l2tauos_frompv = new TH1D("h1l2tauos_frompv","h1l2tauos_frompv", 2, 0., 2.);
  TH1D* h1l2tauos_drltautau = new TH1D("h1l2tauos_drltautau","h1l2tauos_drltautau", 10, 0.,6.);
  TH1D* h1l2tauos_pttautau = new TH1D("h1l2tauos_pttautau","h1l2tauos_pttautau", 50, 0.,250.);
  TH1D* h1l2tauos_oldbdt = new TH1D("h1l2tauos_oldbdt","h1l2tauos_oldbdt", 8, -1., 1.);
  TH1D* h1l2tauos_oldbdtf = new TH1D("h1l2tauos_oldbdtf","h1l2tauos_oldbdtf", 100, -1., 1.);
  TH1D* h1l2tauos_oldbdt3bins = new TH1D("h1l2tauos_oldbdt3bins","h1l2tauos_oldbdt3bins", 3,xbins);
  TH1D* h1l2tauos_fakeorig = new TH1D("h1l2tauos_fakeorig","h1l2tauos_fakeorig",5, 0., 5.); 
  TH1D* h1l2tauos_leadbdtjetsigtrans = new TH1D("h1l2tauos_leadbdtjetsigtrans","h1l2tauos_leadbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1l2tauos_subbdtjetsigtrans = new TH1D("h1l2tauos_subbdtjetsigtrans","h1l2tauos_subbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1l2tauos_leadtauptv = new TH1D("h1l2tauos_leadtauptv","h1l2tauos_leadtauptv", 20, -1., 1.);
  TH1D* h1l2tauos_subtauptv = new TH1D("h1l2tauos_subtauptv","h1l2tauos_subtauptv", 20, -1., 1.);
  TH1D* h1l2tauos_bdt = new TH1D("h1l2tauos_bdt","h1l2tauos_bdt", 8, -1., 1.);
  TH1D* h1l2tauos_bdtf = new TH1D("h1l2tauos_bdtf","h1l2tauos_bdtf", 100, -1., 1.);
  TH1D* h1l2tauos_bdt3bins = new TH1D("h1l2tauos_bdt3bins","h1l2tauos_bdt3bins", 3,xbins);
  TH1D* h1l2tauos_mtautaubdtcut = new TH1D("h1l2tauos_mtautaubdtcut","h1l2tauos_mtautaubdtcut", 50, 0.,250.);
  TH1D* h1l2tauos_njetsbdtcut = new TH1D("h1l2tauos_njetsbdtcut","h1l2tauos_njetsbdtcut", 6, 0.,6.);
  TH1D* h1l2tauos_leadtauptbdtcut = new TH1D("h1l2tauos_leadtauptbdtcut","h1l2tauos_leadtauptbdtcut", 50, 0.,250.);
  TH1D* h1l2tauos_subtauptbdtcut = new TH1D("h1l2tauos_subtauptbdtcut","h1l2tauos_subtauptbdtcut", 50, 0.,250.);
  TH1D* h1l2tauos_truthbdtcut = new TH1D("h1l2tauos_truthbdtcut","h1l2tauos_truthbdtcut", 3, 0.,3.);
  TH1D* h1l2tauos_oldbdtM = new TH1D("h1l2tauos_oldbdtM","h1l2tauos_oldbdtM", 4, -1., 1.);
  TH1D* h1l2tauos_bdtM = new TH1D("h1l2tauos_bdtM","h1l2tauos_bdtM", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtT = new TH1D("h1l2tauos_oldbdtT","h1l2tauos_oldbdtT", 4, -1., 1.);
  TH1D* h1l2tauos_bdtT = new TH1D("h1l2tauos_bdtT","h1l2tauos_bdtT", 4, -1., 1.);
  TH1D* h1l2tauos_bdtT3bins = new TH1D("h1l2tauos_bdtT3bins","h1l2tauos_bdtT3bins", 3,xbins);
  TH1D* h1l2tauos_pvbdtT3bins = new TH1D("h1l2tauos_pvbdtT3bins","h1l2tauos_pvbdtT3bins", 3,xbins);
  TH1D* h1l2tauos_pvbdtX3bins = new TH1D("h1l2tauos_pvbdtX3bins","h1l2tauos_pvbdtX3bins", 3,xbins);
  TH1D* h1l2tauos_pvbdtNbv3bins = new TH1D("h1l2tauos_pvbdtNbv3bins","h1l2tauos_pvbdtNbv3bins", 3,xbins);
  TH1D* h1l2tauos_pvbdtCapb3bins = new TH1D("h1l2tauos_pvbdtCapb3bins","h1l2tauos_pvbdtCapb3bins", 3,xbins);
  TH1D* h1l2tauos_bdtnT = new TH1D("h1l2tauos_bdtnT","h1l2tauos_bdtnT", 4, -1., 1.); // may 4
  TH1D* h1l2tauos_oldbdtMx = new TH1D("h1l2tauos_oldbdtMx","h1l2tauos_oldbdtMx", 4, -1., 1.);
  TH1D* h1l2tauos_bdtMx = new TH1D("h1l2tauos_bdtMx","h1l2tauos_bdtMx", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtTx = new TH1D("h1l2tauos_oldbdtTx","h1l2tauos_oldbdtTx", 4, -1., 1.);
  TH1D* h1l2tauos_bdtTx = new TH1D("h1l2tauos_bdtTx","h1l2tauos_bdtTx", 4, -1., 1.);
  TH1D* h1l2tauos_bdtnTx = new TH1D("h1l2tauos_bdtnTx","h1l2tauos_bdtnTx", 4, -1., 1.); // may 4
  TH1D* h1l2tauos_oldbdtnT = new TH1D("h1l2tauos_oldbdtnT","h1l2tauos_oldbdtnT", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtnTx = new TH1D("h1l2tauos_oldbdtnTx","h1l2tauos_oldbdtnTx", 4, -1., 1.);
  // 5-11 
  TH1D* h1l2tauos_oldbdtT3bins = new TH1D("h1l2tauos_oldbdtT3bins","h1l2tauos_oldbdtT3bins", 3,xbins);
  TH1D* h1l2tauos_oldbdtnT3bins = new TH1D("h1l2tauos_oldbdtnT3bins","h1l2tauos_oldbdtnT3bins", 3,xbins);
  TH1D* h1l2tauos_oldbdtMx3bins = new TH1D("h1l2tauos_oldbdtMx3bins","h1l2tauos_oldbdtMx3bins", 3,xbins);
  TH1D* h1l2tauos_oldbdtTx3bins = new TH1D("h1l2tauos_oldbdtTx3bins","h1l2tauos_oldbdtTx3bins", 3,xbins);
  TH1D* h1l2tauos_oldbdtnTx3bins = new TH1D("h1l2tauos_oldbdtnTx3bins","h1l2tauos_oldbdtnTx3bins", 3,xbins);
  // truth 
  TH1D* h1l2tauos_njetstruth = new TH1D("h1l2tauos_njetstruth","h1l2tauos_njetstruth", 6, 0.,6.);
  TH1D* h1l2tauos_nbjetstruth = new TH1D("h1l2tauos_nbjetstruth","h1l2tauos_nbjetstruth", 4, 0.,4.);
  TH1D* h1l2tauos_htjetstruth = new TH1D("h1l2tauos_htjetstruth","h1l2tauos_htjetstruth", 20, 0.,800.);
  TH1D* h1l2tauos_leadtaupttruth = new TH1D("h1l2tauos_leadtaupttruth","h1l2tauos_leadtaupttruth", 10, 25.,125.);
  TH1D* h1l2tauos_subtaupttruth = new TH1D("h1l2tauos_subtaupttruth","h1l2tauos_subtaupttruth", 10, 25.,125.);
  TH1D* h1l2tauos_mtautautruth = new TH1D("h1l2tauos_mtautautruth","h1l2tauos_mtautautruth", 20, 0.,200.);
  TH1D* h1l2tauos_jjdrtruth = new TH1D("h1l2tauos_jjdrtruth","h1l2tauos_jjdrtruth", 10, 0.,4.);
  TH1D* h1l2tauos_oldbdttruth = new TH1D("h1l2tauos_oldbdttruth","h1l2tauos_oldbdttruth", 8, -1., 1.);
  TH1D* h1l2tauos_oldbdtTtruth = new TH1D("h1l2tauos_oldbdtTtruth","h1l2tauos_oldbdtTtruth", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdt3binstruth = new TH1D("h1l2tauos_oldbdt3binstruth","h1l2tauos_oldbdt3binstruth", 3,xbins);
  TH1D* h1l2tauos_leadbdtjetsigtranstruth = new TH1D("h1l2tauos_leadbdtjetsigtranstruth","h1l2tauos_leadbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1l2tauos_subbdtjetsigtranstruth = new TH1D("h1l2tauos_subbdtjetsigtranstruth","h1l2tauos_subbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1l2tauos_leadtauptvtruth = new TH1D("h1l2tauos_leadtauptvtruth","h1l2tauos_leadtauptvtruth", 20, -1., 1.);
  TH1D* h1l2tauos_subtauptvtruth = new TH1D("h1l2tauos_subtauptvtruth","h1l2tauos_subtauptvtruth", 20, -1., 1.);
  TH1D* h1l2tauos_bdttruth = new TH1D("h1l2tauos_bdttruth","h1l2tauos_bdttruth", 8, -1., 1.);
  TH1D* h1l2tauos_bdt3binstruth = new TH1D("h1l2tauos_bdt3binstruth","h1l2tauos_bdt3binstruth", 3,xbins);
  TH1D* h1l2tauos_bdtMtruth = new TH1D("h1l2tauos_bdtMtruth","h1l2tauos_bdtMtruth", 4, -1., 1.);
  TH1D* h1l2tauos_bdtTtruth = new TH1D("h1l2tauos_bdtTtruth","h1l2tauos_bdtTtruth", 4, -1., 1.); // may 4 
  TH1D* h1l2tauos_bdtT3binstruth = new TH1D("h1l2tauos_bdtT3binstruth","h1l2tauos_bdtT3binstruth", 3,xbins);
  TH1D* h1l2tauos_pvbdtT3binstruth = new TH1D("h1l2tauos_pvbdtT3binstruth","h1l2tauos_pvbdtT3binstruth", 3,xbins);
  TH1D* h1l2tauos_pvbdtX3binstruth = new TH1D("h1l2tauos_pvbdtX3binstruth","h1l2tauos_pvbdtX3binstruth", 3,xbins);
  TH1D* h1l2tauos_pvbdtNbv3binstruth = new TH1D("h1l2tauos_pvbdtNbv3binstruth","h1l2tauos_pvbdtNbv3binstruth", 3,xbins);
  TH1D* h1l2tauos_pvbdtCapb3binstruth = new TH1D("h1l2tauos_pvbdtCapb3binstruth","h1l2tauos_pvbdtCapb3binstruth", 3,xbins);
  TH1D* h1l2tauos_bdtnTtruth = new TH1D("h1l2tauos_bdtnTtruth","h1l2tauos_bdtnTtruth", 4, -1., 1.);
  TH1D* h1l2tauos_bdtMxtruth = new TH1D("h1l2tauos_bdtMxtruth","h1l2tauos_bdtMxtruth", 4, -1., 1.);
  TH1D* h1l2tauos_bdtTxtruth = new TH1D("h1l2tauos_bdtTxtruth","h1l2tauos_bdtTxtruth", 4, -1., 1.);
  TH1D* h1l2tauos_bdtnTxtruth = new TH1D("h1l2tauos_bdtnTxtruth","h1l2tauos_bdtnTxtruth", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtnTtruth = new TH1D("h1l2tauos_oldbdtnTtruth","h1l2tauos_oldbdtnTtruth", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtnTxtruth = new TH1D("h1l2tauos_oldbdtnTxtruth","h1l2tauos_oldbdtnTxtruth", 4, -1., 1.);
  // 5-11
  TH1D* h1l2tauos_oldbdtT3binstruth = new TH1D("h1l2tauos_oldbdtT3binstruth","h1l2tauos_oldbdtT3binstruth", 3,xbins);
  TH1D* h1l2tauos_oldbdtnT3binstruth = new TH1D("h1l2tauos_oldbdtnT3binstruth","h1l2tauos_oldbdtnT3binstruth", 3,xbins);
  TH1D* h1l2tauos_oldbdtMx3binstruth = new TH1D("h1l2tauos_oldbdtMx3binstruth","h1l2tauos_oldbdtMx3binstruth", 3,xbins);
  TH1D* h1l2tauos_oldbdtTx3binstruth = new TH1D("h1l2tauos_oldbdtTx3binstruth","h1l2tauos_oldbdtTx3binstruth", 3,xbins);
  TH1D* h1l2tauos_oldbdtnTx3binstruth = new TH1D("h1l2tauos_oldbdtnTx3binstruth","h1l2tauos_oldbdtnTx3binstruth", 3,xbins);
  TH1D* h1l2tauos_oldbdtMxtruth = new TH1D("h1l2tauos_oldbdtMxtruth","h1l2tauos_oldbdtMxtruth", 4, -1., 1.);
  TH1D* h1l2tauos_oldbdtTxtruth = new TH1D("h1l2tauos_oldbdtTxtruth","h1l2tauos_oldbdtTxtruth", 4, -1., 1.);
  //6-30 
  TH1D* h1l2tauos_sumtautight = new TH1D("h1l2tauos_sumtautight","h1l2tauos_sumtautight", 3, 0., 3.);
  TH1D* h1l2tauos_leadtaubtagbin = new TH1D("h1l2tauos_leadtaubtagbin","h1l2tauos_leadtaubtagbin", 6, 0., 6.);
  TH1D* h1l2tauos_subtaubtagbin = new TH1D("h1l2tauos_subtaubtagbin","h1l2tauos_subtaubtagbin", 6, 0., 6.);
  TH1D* h1l2tauos_etamaxtruth = new TH1D("h1l2tauos_etamaxtruth","h1l2tauos_etamaxtruth", 10, 0.,2.5);
  TH1D* h1l2tauos_frompvtruth = new TH1D("h1l2tauos_frompvtruth","h1l2tauos_frompvtruth", 2, 0., 2.);
  TH1D* h1l2tauos_drltautautruth = new TH1D("h1l2tauos_drltautautruth","h1l2tauos_drltautautruth", 10, 0.,6.);
  TH1D* h1l2tauos_sumtautighttruth = new TH1D("h1l2tauos_sumtautighttruth","h1l2tauos_sumtautighttruth", 3, 0., 3.);
  TH1D* h1l2tauos_leadtaubtagbintruth = new TH1D("h1l2tauos_leadtaubtagbintruth","h1l2tauos_leadtaubtagbintruth", 6, 0., 6.);
  TH1D* h1l2tauos_subtaubtagbintruth = new TH1D("h1l2tauos_subtaubtagbintruth","h1l2tauos_subtaubtagbintruth", 6, 0., 6.);
  // 12tau with two tau ss
  TH1D* h1l2tauss_njets = new TH1D("h1l2tauss_njets","h1l2tauss_njets", 6, 0.,6.);
  TH1D* h1l2tauss_nbjets = new TH1D("h1l2tauss_nbjets","h1l2tauss_nbjets", 4, 0.,4.);
  TH1D* h1l2tauss_htjets = new TH1D("h1l2tauss_htjets","h1l2tauss_htjets", 20, 0.,800.);
  TH1D* h1l2tauss_leadtaupt = new TH1D("h1l2tauss_leadtaupt","h1l2tauss_leadtaupt", 10, 25.,125.);
  TH1D* h1l2tauss_subtaupt = new TH1D("h1l2tauss_subtaupt","h1l2tauss_subtaupt", 10, 25.,125.);
  TH1D* h1l2tauss_mtautau = new TH1D("h1l2tauss_mtautau","h1l2tauss_mtautau", 20, 0.,200.);
  TH1D* h1l2tauss_truth = new TH1D("h1l2tauss_truth","h1l2tauss_truth", 3, 0.,3.);
  TH1D* h1l2tauss_jjdr = new TH1D("h1l2tauss_jjdr","h1l2tauss_jjdr", 10, 0.,4.);
  TH1D* h1l2tauss_etamax = new TH1D("h1l2tauss_etamax","h1l2tauss_etamax", 10, 0.,2.5);
  TH1D* h1l2tauss_frompv = new TH1D("h1l2tauss_frompv","h1l2tauss_frompv", 2, 0., 2.);
  TH1D* h1l2tauss_drltautau = new TH1D("h1l2tauss_drltautau","h1l2tauss_drltautau", 10, 0.,6.);
  TH1D* h1l2tauss_pttautau = new TH1D("h1l2tauss_pttautau","h1l2tauss_pttautau", 50, 0.,250.);
  TH1D* h1l2tauss_oldbdt = new TH1D("h1l2tauss_oldbdt","h1l2tauss_oldbdt", 8, -1., 1.);
  TH1D* h1l2tauss_oldbdt3bins = new TH1D("h1l2tauss_oldbdt3bins","h1l2tauss_oldbdt3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtM = new TH1D("h1l2tauss_oldbdtM","h1l2tauss_oldbdtM", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtT = new TH1D("h1l2tauss_oldbdtT","h1l2tauss_oldbdtT", 4, -1., 1.);
  TH1D* h1l2tauss_fakeorig = new TH1D("h1l2tauss_fakeorig","h1l2tauss_fakeorig",5, 0., 5.); 
  TH1D* h1l2tauss_leadbdtjetsigtrans = new TH1D("h1l2tauss_leadbdtjetsigtrans","h1l2tauss_leadbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1l2tauss_subbdtjetsigtrans = new TH1D("h1l2tauss_subbdtjetsigtrans","h1l2tauss_subbdtjetsigtrans", 20, 0.,1.);
  TH1D* h1l2tauss_leadtauptv = new TH1D("h1l2tauss_leadtauptv","h1l2tauss_leadtauptv", 20, -1., 1.);
  TH1D* h1l2tauss_subtauptv = new TH1D("h1l2tauss_subtauptv","h1l2tauss_subtauptv", 20, -1., 1.);
  TH1D* h1l2tauss_bdt = new TH1D("h1l2tauss_bdt","h1l2tauss_bdt", 8, -1., 1.);
  TH1D* h1l2tauss_bdt3bins = new TH1D("h1l2tauss_bdt3bins","h1l2tauss_bdt3bins", 3,xbins);
  TH1D* h1l2tauss_mtautaubdtcut = new TH1D("h1l2tauss_mtautaubdtcut","h1l2tauss_mtautaubdtcut", 50, 0.,250.);
  TH1D* h1l2tauss_njetsbdtcut = new TH1D("h1l2tauss_njetsbdtcut","h1l2tauss_njetsbdtcut", 6, 0.,6.);
  TH1D* h1l2tauss_bdtf = new TH1D("h1l2tauss_bdtf","h1l2tauss_bdtf", 100, -1., 1.); // may 4 
  TH1D* h1l2tauss_bdtM = new TH1D("h1l2tauss_bdtM","h1l2tauss_bdtM", 4, -1., 1.);
  TH1D* h1l2tauss_bdtT = new TH1D("h1l2tauss_bdtT","h1l2tauss_bdtT", 4, -1., 1.);
  TH1D* h1l2tauss_bdtT3bins = new TH1D("h1l2tauss_bdtT3bins","h1l2tauss_bdtT3bins", 3,xbins);
  TH1D* h1l2tauss_pvbdtT3bins = new TH1D("h1l2tauss_pvbdtT3bins","h1l2tauss_pvbdtT3bins", 3,xbins);
  TH1D* h1l2tauss_pvbdtX3bins = new TH1D("h1l2tauss_pvbdtX3bins","h1l2tauss_pvbdtX3bins", 3,xbins);
  TH1D* h1l2tauss_pvbdtNbv3bins = new TH1D("h1l2tauss_pvbdtNbv3bins","h1l2tauss_pvbdtNbv3bins", 3,xbins);
  TH1D* h1l2tauss_pvbdtCapb3bins = new TH1D("h1l2tauss_pvbdtCapb3bins","h1l2tauss_pvbdtCapb3bins", 3,xbins);
  TH1D* h1l2tauss_bdtnT = new TH1D("h1l2tauss_bdtnT","h1l2tauss_bdtnT", 4, -1., 1.); // may 4
  TH1D* h1l2tauss_bdtMx = new TH1D("h1l2tauss_bdtMx","h1l2tauss_bdtMx", 4, -1., 1.);
  TH1D* h1l2tauss_bdtTx = new TH1D("h1l2tauss_bdtTx","h1l2tauss_bdtTx", 4, -1., 1.);
  TH1D* h1l2tauss_bdtnTx = new TH1D("h1l2tauss_bdtnTx","h1l2tauss_bdtnTx", 4, -1., 1.); // may 4 
  TH1D* h1l2tauss_oldbdtnT = new TH1D("h1l2tauss_oldbdtnT","h1l2tauss_oldbdtnT", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtnTx = new TH1D("h1l2tauss_oldbdtnTx","h1l2tauss_oldbdtnTx", 4, -1., 1.);                                            
  // 5-11
  TH1D* h1l2tauss_oldbdtT3bins = new TH1D("h1l2tauss_oldbdtT3bins","h1l2tauss_oldbdtT3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtnT3bins = new TH1D("h1l2tauss_oldbdtnT3bins","h1l2tauss_oldbdtnT3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtMx3bins = new TH1D("h1l2tauss_oldbdtMx3bins","h1l2tauss_oldbdtMx3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtTx3bins = new TH1D("h1l2tauss_oldbdtTx3bins","h1l2tauss_oldbdtTx3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtnTx3bins = new TH1D("h1l2tauss_oldbdtnTx3bins","h1l2tauss_oldbdtnTx3bins", 3,xbins);
  TH1D* h1l2tauss_oldbdtMx = new TH1D("h1l2tauss_oldbdtMx","h1l2tauss_oldbdtMx", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtTx = new TH1D("h1l2tauss_oldbdtTx","h1l2tauss_oldbdtTx", 4, -1., 1.);
  // truth 
  TH1D* h1l2tauss_njetstruth = new TH1D("h1l2tauss_njetstruth","h1l2tauss_njetstruth", 6, 0.,6.);
  TH1D* h1l2tauss_nbjetstruth = new TH1D("h1l2tauss_nbjetstruth","h1l2tauss_nbjetstruth", 4, 0.,4.);
  TH1D* h1l2tauss_htjetstruth = new TH1D("h1l2tauss_htjetstruth","h1l2tauss_htjetstruth", 20, 0.,800.);
  TH1D* h1l2tauss_leadtaupttruth = new TH1D("h1l2tauss_leadtaupttruth","h1l2tauss_leadtaupttruth", 10, 25.,125.);
  TH1D* h1l2tauss_subtaupttruth = new TH1D("h1l2tauss_subtaupttruth","h1l2tauss_subtaupttruth", 10, 25.,125.);
  TH1D* h1l2tauss_mtautautruth = new TH1D("h1l2tauss_mtautautruth","h1l2tauss_mtautautruth", 20, 0.,200.);
  TH1D* h1l2tauss_jjdrtruth = new TH1D("h1l2tauss_jjdrtruth","h1l2tauss_jjdrtruth", 10, 0.,4.);
  TH1D* h1l2tauss_oldbdttruth = new TH1D("h1l2tauss_oldbdttruth","h1l2tauss_oldbdttruth", 8, -1., 1.);
  TH1D* h1l2tauss_oldbdtMtruth = new TH1D("h1l2tauss_oldbdtMtruth","h1l2tauss_oldbdtMtruth", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtTtruth = new TH1D("h1l2tauss_oldbdtTtruth","h1l2tauss_oldbdtTtruth", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdt3binstruth = new TH1D("h1l2tauss_oldbdt3binstruth","h1l2tauss_oldbdt3binstruth", 3,xbins);
  TH1D* h1l2tauss_leadbdtjetsigtranstruth = new TH1D("h1l2tauss_leadbdtjetsigtranstruth","h1l2tauss_leadbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1l2tauss_subbdtjetsigtranstruth = new TH1D("h1l2tauss_subbdtjetsigtranstruth","h1l2tauss_subbdtjetsigtranstruth", 20, 0.,1.);
  TH1D* h1l2tauss_leadtauptvtruth = new TH1D("h1l2tauss_leadtauptvtruth","h1l2tauss_leadtauptvtruth", 20, -1., 1.);
  TH1D* h1l2tauss_subtauptvtruth = new TH1D("h1l2tauss_subtauptvtruth","h1l2tauss_subtauptvtruth", 20, -1., 1.);
  TH1D* h1l2tauss_bdttruth = new TH1D("h1l2tauss_bdttruth","h1l2tauss_bdttruth", 8, -1., 1.);
  TH1D* h1l2tauss_bdt3binstruth = new TH1D("h1l2tauss_bdt3binstruth","h1l2tauss_bdt3binstruth", 3,xbins);
  TH1D* h1l2tauss_bdtMtruth = new TH1D("h1l2tauss_bdtMtruth","h1l2tauss_bdtMtruth", 4, -1., 1.); 
  TH1D* h1l2tauss_bdtTtruth = new TH1D("h1l2tauss_bdtTtruth","h1l2tauss_bdtTtruth", 4, -1., 1.); // may 4 
  TH1D* h1l2tauss_bdtT3binstruth = new TH1D("h1l2tauss_bdtT3binstruth","h1l2tauss_bdtT3binstruth", 3,xbins);
  TH1D* h1l2tauss_pvbdtT3binstruth = new TH1D("h1l2tauss_pvbdtT3binstruth","h1l2tauss_pvbdtT3binstruth", 3,xbins);
  TH1D* h1l2tauss_pvbdtX3binstruth = new TH1D("h1l2tauss_pvbdtX3binstruth","h1l2tauss_pvbdtX3binstruth", 3,xbins);
  TH1D* h1l2tauss_pvbdtNbv3binstruth = new TH1D("h1l2tauss_pvbdtNbv3binstruth","h1l2tauss_pvbdtNbv3binstruth", 3,xbins);
  TH1D* h1l2tauss_pvbdtCapb3binstruth = new TH1D("h1l2tauss_pvbdtCapb3binstruth","h1l2tauss_pvbdtCapb3binstruth", 3,xbins);
  TH1D* h1l2tauss_bdtnTtruth = new TH1D("h1l2tauss_bdtnTtruth","h1l2tauss_bdtnTtruth", 4, -1., 1.);
  TH1D* h1l2tauss_bdtMxtruth = new TH1D("h1l2tauss_bdtMxtruth","h1l2tauss_bdtMxtruth", 4, -1., 1.); 
  TH1D* h1l2tauss_bdtTxtruth = new TH1D("h1l2tauss_bdtTxtruth","h1l2tauss_bdtTxtruth", 4, -1., 1.); // may 4
  TH1D* h1l2tauss_bdtnTxtruth = new TH1D("h1l2tauss_bdtnTxtruth","h1l2tauss_bdtnTxtruth", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtnTtruth = new TH1D("h1l2tauss_oldbdtnTtruth","h1l2tauss_oldbdtnTtruth", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtnTxtruth = new TH1D("h1l2tauss_oldbdtnTxtruth","h1l2tauss_oldbdtnTxtruth", 4, -1., 1.);
  // 5-11
  TH1D* h1l2tauss_oldbdtT3binstruth = new TH1D("h1l2tauss_oldbdtT3binstruth","h1l2tauss_oldbdtT3binstruth", 3,xbins);
  TH1D* h1l2tauss_oldbdtnT3binstruth = new TH1D("h1l2tauss_oldbdtnT3binstruth","h1l2tauss_oldbdtnT3binstruth", 3,xbins);
  TH1D* h1l2tauss_oldbdtMx3binstruth = new TH1D("h1l2tauss_oldbdtMx3binstruth","h1l2tauss_oldbdtMx3binstruth", 3,xbins);
  TH1D* h1l2tauss_oldbdtTx3binstruth = new TH1D("h1l2tauss_oldbdtTx3binstruth","h1l2tauss_oldbdtTx3binstruth", 3,xbins);
  TH1D* h1l2tauss_oldbdtnTx3binstruth = new TH1D("h1l2tauss_oldbdtnTx3binstruth","h1l2tauss_oldbdtnTx3binstruth", 3,xbins);
  TH1D* h1l2tauss_oldbdtMxtruth = new TH1D("h1l2tauss_oldbdtMxtruth","h1l2tauss_oldbdtMxtruth", 4, -1., 1.);
  TH1D* h1l2tauss_oldbdtTxtruth = new TH1D("h1l2tauss_oldbdtTxtruth","h1l2tauss_oldbdtTxtruth", 4, -1., 1.);
  //6-30
  TH1D* h1l2tauss_sumtautight = new TH1D("h1l2tauss_sumtautight","h1l2tauss_sumtautight", 3, 0., 3.);
  TH1D* h1l2tauss_leadtaubtagbin = new TH1D("h1l2tauss_leadtaubtagbin","h1l2tauss_leadtaubtagbin", 6, 0., 6.);
  TH1D* h1l2tauss_subtaubtagbin = new TH1D("h1l2tauss_subtaubtagbin","h1l2tauss_subtaubtagbin", 6, 0., 6.);
  TH1D* h1l2tauss_etamaxtruth = new TH1D("h1l2tauss_etamaxtruth","h1l2tauss_etamaxtruth", 10, 0.,2.5);
  TH1D* h1l2tauss_frompvtruth = new TH1D("h1l2tauss_frompvtruth","h1l2tauss_frompvtruth", 2, 0., 2.);
  TH1D* h1l2tauss_drltautautruth = new TH1D("h1l2tauss_drltautautruth","h1l2tauss_drltautautruth", 10, 0.,6.);
  TH1D* h1l2tauss_sumtautighttruth = new TH1D("h1l2tauss_sumtautighttruth","h1l2tauss_sumtautighttruth", 3, 0., 3.);
  TH1D* h1l2tauss_leadtaubtagbintruth = new TH1D("h1l2tauss_leadtaubtagbintruth","h1l2tauss_leadtaubtagbintruth", 6, 0., 6.);
  TH1D* h1l2tauss_subtaubtagbintruth = new TH1D("h1l2tauss_subtaubtagbintruth","h1l2tauss_subtaubtagbintruth", 6, 0., 6.);
  //
  h1ltau_njets->Sumw2();
  h1ltau_nbjets->Sumw2();
  h1ltau_njbjets->Sumw2();
  h1ltau_htjets->Sumw2();
  h1ltau_met->Sumw2();
  h1ltau_lept->Sumw2();
  h1ltau_totcharge->Sumw2();
  h1ltau_ljdr->Sumw2();
  h1ltau_jjdr->Sumw2();
  h1ltau_taupt->Sumw2();
  h1ltau_taueta->Sumw2();
  h1ltau_tautight->Sumw2();
  h1ltau_taubtag->Sumw2();
  h1ltau_taucharge->Sumw2();
  h1ltau_tauntrk->Sumw2();
  h1ltau_bdtjetsigtrans->Sumw2();
  h1ltau_tauptv->Sumw2();
  // 1ltau+loose tau os 
  h1ltau_Ltauosnjets->Sumw2();
  h1ltau_Ltauosnbjets->Sumw2();
  h1ltau_Ltauoshtjets->Sumw2();
  h1ltau_Ltauosleadtaupt->Sumw2();
  h1ltau_Ltauossubtaupt->Sumw2();
  h1ltau_Ltauosmtautau->Sumw2();
  h1ltau_Ltauostruth->Sumw2();
  h1ltau_Ltauosjjdr->Sumw2();
  h1ltau_Ltauosoldbdt->Sumw2();
  h1ltau_Ltauosoldbdt3bins->Sumw2();
  h1ltau_Ltauosleadbdtjetsigtrans->Sumw2();
  h1ltau_Ltauossubbdtjetsigtrans->Sumw2(); 
  h1ltau_Ltauosleadtauptv->Sumw2();
  h1ltau_Ltauossubtauptv->Sumw2();
  h1ltau_Ltauosbdt->Sumw2();
  h1ltau_Ltauosbdt3bins->Sumw2();
  h1ltau_Ltauosmtautaubdtcut->Sumw2();
  h1ltau_Ltauosnjetsbdtcut->Sumw2();
  for(int i = 0; i<3; ++i){
    h1ltau_Ltauostruth->Fill(mylabelx[i],0);
  }
  for(int i = 0; i<5; ++i){
    h1ltau_Ltauosfakeorig->Fill(mylabel[i],0);
  }
  // truth 
  h1ltau_Ltauosnjetstruth->Sumw2();
  h1ltau_Ltauosnbjetstruth->Sumw2();
  h1ltau_Ltauoshtjetstruth->Sumw2();
  h1ltau_Ltauosleadtaupttruth->Sumw2();
  h1ltau_Ltauossubtaupttruth->Sumw2();
  h1ltau_Ltauosmtautautruth->Sumw2();
  h1ltau_Ltauosjjdrtruth->Sumw2();
  h1ltau_Ltauosoldbdttruth->Sumw2();
  h1ltau_Ltauosoldbdt3binstruth->Sumw2();
  h1ltau_Ltauosleadbdtjetsigtranstruth->Sumw2();
  h1ltau_Ltauossubbdtjetsigtranstruth->Sumw2(); 
  h1ltau_Ltauosleadtauptvtruth->Sumw2();
  h1ltau_Ltauossubtauptvtruth->Sumw2();
  h1ltau_Ltauosbdttruth->Sumw2();
  h1ltau_Ltauosbdt3binstruth->Sumw2();
  // 1ltau+loose tau ss 
  h1ltau_Ltaussnjets->Sumw2();
  h1ltau_Ltaussnbjets->Sumw2();
  h1ltau_Ltausshtjets->Sumw2();
  h1ltau_Ltaussleadtaupt->Sumw2();
  h1ltau_Ltausssubtaupt->Sumw2();
  h1ltau_Ltaussmtautau->Sumw2();
  h1ltau_Ltausstruth->Sumw2();
  h1ltau_Ltaussjjdr->Sumw2();
  h1ltau_Ltaussoldbdt->Sumw2();
  h1ltau_Ltaussoldbdt3bins->Sumw2();
  h1ltau_Ltaussleadbdtjetsigtrans->Sumw2();
  h1ltau_Ltausssubbdtjetsigtrans->Sumw2(); 
  h1ltau_Ltaussleadtauptv->Sumw2();
  h1ltau_Ltausssubtauptv->Sumw2();
  h1ltau_Ltaussbdt->Sumw2();
  h1ltau_Ltaussbdt3bins->Sumw2();
  h1ltau_Ltaussmtautaubdtcut->Sumw2();
  h1ltau_Ltaussnjetsbdtcut->Sumw2();
  for(int i = 0; i<3; ++i){
    h1ltau_Ltausstruth->Fill(mylabelx[i],0);
  }
  for(int i = 0; i<5; ++i){
    h1ltau_Ltaussfakeorig->Fill(mylabel[i],0);
  }
  // truth 
  h1ltau_Ltaussnjetstruth->Sumw2();
  h1ltau_Ltaussnbjetstruth->Sumw2();
  h1ltau_Ltausshtjetstruth->Sumw2();
  h1ltau_Ltaussleadtaupttruth->Sumw2();
  h1ltau_Ltausssubtaupttruth->Sumw2();
  h1ltau_Ltaussmtautautruth->Sumw2();
  h1ltau_Ltaussjjdrtruth->Sumw2();
  h1ltau_Ltaussoldbdttruth->Sumw2();
  h1ltau_Ltaussoldbdt3binstruth->Sumw2();
  h1ltau_Ltaussleadbdtjetsigtranstruth->Sumw2();
  h1ltau_Ltausssubbdtjetsigtranstruth->Sumw2(); 
  h1ltau_Ltaussleadtauptvtruth->Sumw2();
  h1ltau_Ltausssubtauptvtruth->Sumw2();
  h1ltau_Ltaussbdttruth->Sumw2();
  h1ltau_Ltaussbdt3binstruth->Sumw2();
  // 1l2tau 
  h1l2tau_njets->Sumw2();
  h1l2tau_nbjets->Sumw2();
  h1l2tau_njbjets->Sumw2();
  h1l2tau_htjets->Sumw2();
  h1l2tau_leadtaupt->Sumw2();
  h1l2tau_subtaupt->Sumw2();
  h1l2tau_mtautau->Sumw2();
  h1l2tau_met->Sumw2();
  h1l2tau_lept->Sumw2();
  h1l2tau_totcharge->Sumw2();
  h1l2tau_ljdr->Sumw2();
  h1l2tau_jjdr->Sumw2();
  h1l2tau_etamax->Sumw2();
  h1l2tau_bdtT3bins->Sumw2();
  // 1l2tau os 
  h1l2tauos_njets->Sumw2();
  h1l2tauos_nbjets->Sumw2();
  h1l2tauos_htjets->Sumw2();
  h1l2tauos_leadtaupt->Sumw2();
  h1l2tauos_subtaupt->Sumw2();
  h1l2tauos_mtautau->Sumw2();
  h1l2tauos_truth->Sumw2();
  h1l2tauos_jjdr->Sumw2();
  h1l2tauos_etamax->Sumw2();
  h1l2tauos_frompv->Sumw2();
  h1l2tauos_drltautau->Sumw2();
  h1l2tauos_pttautau->Sumw2();
  h1l2tauos_oldbdt->Sumw2();
  h1l2tauos_oldbdtf->Sumw2();
  h1l2tauos_oldbdt3bins->Sumw2();
  h1l2tauos_leadbdtjetsigtrans->Sumw2();
  h1l2tauos_subbdtjetsigtrans->Sumw2(); 
  h1l2tauos_leadtauptv->Sumw2();
  h1l2tauos_subtauptv->Sumw2();
  h1l2tauos_bdt->Sumw2();
  h1l2tauos_bdtf->Sumw2();
  h1l2tauos_bdt3bins->Sumw2();
  h1l2tauos_mtautaubdtcut->Sumw2();
  h1l2tauos_njetsbdtcut->Sumw2();
  for(int i = 0; i<3; ++i){
    h1l2tauos_truth->Fill(mylabelx[i],0);
  }
  for(int i = 0; i<5; ++i){
    h1l2tauos_fakeorig->Fill(mylabel[i],0);
  }  
  // truth 
  h1l2tauos_njetstruth->Sumw2();
  h1l2tauos_nbjetstruth->Sumw2();
  h1l2tauos_htjetstruth->Sumw2();
  h1l2tauos_leadtaupttruth->Sumw2();
  h1l2tauos_subtaupttruth->Sumw2();
  h1l2tauos_mtautautruth->Sumw2();
  h1l2tauos_jjdrtruth->Sumw2();
  h1l2tauos_oldbdttruth->Sumw2();
  h1l2tauos_oldbdt3binstruth->Sumw2();
  h1l2tauos_leadbdtjetsigtranstruth->Sumw2();
  h1l2tauos_subbdtjetsigtranstruth->Sumw2(); 
  h1l2tauos_leadtauptvtruth->Sumw2();
  h1l2tauos_subtauptvtruth->Sumw2();
  h1l2tauos_bdttruth->Sumw2();
  h1l2tauos_bdt3binstruth->Sumw2();
  h1l2tauos_oldbdtM->Sumw2();
  h1l2tauos_bdtM->Sumw2();
  h1l2tauos_oldbdtT->Sumw2();
  h1l2tauos_bdtT->Sumw2();
  h1l2tauos_bdtT3bins->Sumw2();
  h1l2tauos_pvbdtT3bins->Sumw2();
  h1l2tauos_pvbdtX3bins->Sumw2();
  h1l2tauos_pvbdtNbv3bins->Sumw2();
  h1l2tauos_pvbdtCapb3bins->Sumw2();
  h1l2tauos_bdtnT->Sumw2();
  h1l2tauos_oldbdtMx->Sumw2();
  h1l2tauos_bdtMx->Sumw2();
  h1l2tauos_oldbdtTx->Sumw2();
  h1l2tauos_oldbdtTtruth->Sumw2();
  h1l2tauos_bdtTx->Sumw2();
  h1l2tauos_bdtnTx->Sumw2(); // may 4
  h1l2tauos_bdtMtruth->Sumw2();
  h1l2tauos_bdtTtruth->Sumw2();
  h1l2tauos_bdtT3binstruth->Sumw2();
  h1l2tauos_pvbdtT3binstruth->Sumw2();
  h1l2tauos_pvbdtX3binstruth->Sumw2();
  h1l2tauos_pvbdtNbv3binstruth->Sumw2();
  h1l2tauos_pvbdtCapb3binstruth->Sumw2();
  h1l2tauos_bdtnTtruth->Sumw2();
  h1l2tauos_bdtMxtruth->Sumw2();
  h1l2tauos_bdtTxtruth->Sumw2();
  h1l2tauos_bdtnTxtruth->Sumw2();
  h1l2tauos_oldbdtnT->Sumw2();
  h1l2tauos_oldbdtnTx->Sumw2();
  h1l2tauos_oldbdtnTtruth->Sumw2();
  h1l2tauos_oldbdtnTxtruth->Sumw2();
  // 5-11 
  h1l2tauos_oldbdtT3bins->Sumw2();
  h1l2tauos_oldbdtnT3bins->Sumw2();
  h1l2tauos_oldbdtMx3bins->Sumw2();
  h1l2tauos_oldbdtTx3bins->Sumw2();
  h1l2tauos_oldbdtnTx3bins->Sumw2();
  h1l2tauos_oldbdtT3binstruth->Sumw2();
  h1l2tauos_oldbdtnT3binstruth->Sumw2();
  h1l2tauos_oldbdtMx3binstruth->Sumw2();
  h1l2tauos_oldbdtTx3binstruth->Sumw2();
  h1l2tauos_oldbdtnTx3binstruth->Sumw2();
  h1l2tauos_oldbdtMxtruth->Sumw2();
  h1l2tauos_oldbdtTxtruth->Sumw2();
  //6-30
  h1l2tauos_sumtautight->Sumw2();
  h1l2tauos_leadtaubtagbin->Sumw2();
  h1l2tauos_subtaubtagbin->Sumw2();
  h1l2tauos_etamaxtruth->Sumw2();
  h1l2tauos_frompvtruth->Sumw2();
  h1l2tauos_drltautautruth->Sumw2();
  h1l2tauos_sumtautighttruth->Sumw2();
  h1l2tauos_leadtaubtagbintruth->Sumw2();
  h1l2tauos_subtaubtagbintruth->Sumw2();
  // 1l2tau ss 
  h1l2tauss_njets->Sumw2();
  h1l2tauss_nbjets->Sumw2();
  h1l2tauss_htjets->Sumw2();
  h1l2tauss_leadtaupt->Sumw2();
  h1l2tauss_subtaupt->Sumw2();
  h1l2tauss_mtautau->Sumw2();
  h1l2tauss_truth->Sumw2();
  h1l2tauss_jjdr->Sumw2();
  h1l2tauss_etamax->Sumw2();
  h1l2tauss_frompv->Sumw2();
  h1l2tauss_drltautau->Sumw2();
  h1l2tauss_pttautau->Sumw2();
  h1l2tauss_oldbdt->Sumw2();
  h1l2tauss_oldbdtM->Sumw2();
  h1l2tauss_oldbdtT->Sumw2();
  h1l2tauss_oldbdt3bins->Sumw2();
  h1l2tauss_leadbdtjetsigtrans->Sumw2();
  h1l2tauss_subbdtjetsigtrans->Sumw2(); 
  h1l2tauss_leadtauptv->Sumw2();
  h1l2tauss_subtauptv->Sumw2();
  h1l2tauss_bdt->Sumw2();
  h1l2tauss_bdt3bins->Sumw2();
  h1l2tauss_mtautaubdtcut->Sumw2();
  h1l2tauss_njetsbdtcut->Sumw2();
  for(int i = 0; i<3; ++i){
    h1l2tauss_truth->Fill(mylabelx[i],0);
  }
  for(int i = 0; i<5; ++i){
    h1l2tauss_fakeorig->Fill(mylabel[i],0);
  }  
  h1l2tauss_bdtf->Sumw2();
  h1l2tauss_bdtM->Sumw2();
  h1l2tauss_bdtT->Sumw2();
  h1l2tauss_bdtT3bins->Sumw2();
  h1l2tauss_pvbdtT3bins->Sumw2();
  h1l2tauss_pvbdtX3bins->Sumw2();
  h1l2tauss_pvbdtNbv3bins->Sumw2();
  h1l2tauss_pvbdtCapb3bins->Sumw2();
  h1l2tauss_bdtnT->Sumw2();
  h1l2tauss_bdtMx->Sumw2(); // may 4
  h1l2tauss_bdtTx->Sumw2();
  h1l2tauss_bdtnTx->Sumw2();
  h1l2tauss_oldbdtnT->Sumw2();
  h1l2tauss_oldbdtnTx->Sumw2();
  // 5-11 
  h1l2tauss_oldbdtT3bins->Sumw2();
  h1l2tauss_oldbdtnT3bins->Sumw2();
  h1l2tauss_oldbdtMx3bins->Sumw2();
  h1l2tauss_oldbdtTx3bins->Sumw2();
  h1l2tauss_oldbdtnTx3bins->Sumw2();
  h1l2tauss_oldbdtMx->Sumw2();
  h1l2tauss_oldbdtTx->Sumw2();
  // truth 
  h1l2tauss_njetstruth->Sumw2();
  h1l2tauss_nbjetstruth->Sumw2();
  h1l2tauss_htjetstruth->Sumw2();
  h1l2tauss_leadtaupttruth->Sumw2();
  h1l2tauss_subtaupttruth->Sumw2();
  h1l2tauss_mtautautruth->Sumw2();
  h1l2tauss_jjdrtruth->Sumw2();
  h1l2tauss_oldbdttruth->Sumw2();
  h1l2tauss_oldbdtMtruth->Sumw2();
  h1l2tauss_oldbdtTtruth->Sumw2();
  h1l2tauss_oldbdt3binstruth->Sumw2();
  h1l2tauss_leadbdtjetsigtranstruth->Sumw2();
  h1l2tauss_subbdtjetsigtranstruth->Sumw2(); 
  h1l2tauss_leadtauptvtruth->Sumw2();
  h1l2tauss_subtauptvtruth->Sumw2();
  h1l2tauss_bdttruth->Sumw2();
  h1l2tauss_bdt3binstruth->Sumw2();
  h1l2tauss_bdtMtruth->Sumw2(); // may 4
  h1l2tauss_bdtTtruth->Sumw2();
  h1l2tauss_bdtT3binstruth->Sumw2();
  h1l2tauss_pvbdtT3binstruth->Sumw2();
  h1l2tauss_pvbdtX3binstruth->Sumw2();
  h1l2tauss_pvbdtNbv3binstruth->Sumw2();
  h1l2tauss_pvbdtCapb3binstruth->Sumw2();
  h1l2tauss_bdtnTtruth->Sumw2();
  h1l2tauss_bdtMxtruth->Sumw2();
  h1l2tauss_bdtTxtruth->Sumw2();
  h1l2tauss_bdtnTxtruth->Sumw2();
  h1l2tauss_oldbdtnTtruth->Sumw2();
  h1l2tauss_oldbdtnTxtruth->Sumw2();
  // 5-11
  h1l2tauss_oldbdtT3binstruth->Sumw2();
  h1l2tauss_oldbdtnT3binstruth->Sumw2();
  h1l2tauss_oldbdtMx3binstruth->Sumw2();
  h1l2tauss_oldbdtTx3binstruth->Sumw2();
  h1l2tauss_oldbdtnTx3binstruth->Sumw2();
  h1l2tauss_oldbdtMxtruth->Sumw2();
  h1l2tauss_oldbdtTxtruth->Sumw2();
  //6-30
  h1l2tauss_sumtautight->Sumw2();
  h1l2tauss_leadtaubtagbin->Sumw2();
  h1l2tauss_subtaubtagbin->Sumw2();
  h1l2tauss_etamaxtruth->Sumw2();
  h1l2tauss_frompvtruth->Sumw2();
  h1l2tauss_drltautautruth->Sumw2();
  h1l2tauss_sumtautighttruth->Sumw2();
  h1l2tauss_leadtaubtagbintruth->Sumw2();
  h1l2tauss_subtaubtagbintruth->Sumw2();
  //
  if (fChain == 0) return;
  TString treename = fChain->GetTree()->GetName();
  fChain->LoadTree(0);
  TTree *newtree = fChain->GetTree()->CloneTree(0);
  newtree->Branch("Mybdt", &myBDT, "Mybdt/D");
  newtree->Branch("Mybdtx", &myBDTx, "Mybdtx/D");
  myBDT = -2.;
  myBDTx = -2.;
  Long64_t nentries = GetNevtAna()>10?GetNevtAna():fChain->GetEntriesFast();
  if(GetNevtAna()>-1)std::cout<<" This is a test run with part of dataset: "<<GetNevtAna()<<" ismc "<<_ismc<<std::endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(jentry%1000==0)std::cout<<" Analysised "<<jentry<<" run "<<Run<<" event "<<Event<<std::endl;

      // job control: control(0); signal(1); 
      if((GetNevtAna()==0) && Evtclass>0 && Njets25>=3)continue; // for  control regions 
      if((GetNevtAna()>0) && Evtclass>0 && Njets25<3)continue; // for signal regions 
      if(_debug)std::cout<<" Debug "<<Run<<" "<<Event<<" "<<Evtclass<<" "<<Njets25<<std::endl;
      double wtx = Weight;
      myBDT = -2.;
      myBDTx = -2.;
      // 1lep1tau with loose tau 
      if(Evtclass==1&&Leptrig){
	tmva1l2tau_njets25 = Njets25 ;
	tmva1l2tau_nbjets25 = Nbjets25;
	tmva1l2tau_htjets = Htjets;
	tmva1l2tau_leadtaupt = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt;
	tmva1l2tau_subtaupt = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
	tmva1l2tau_leadtaubdtjetsigtrans = Leadtaupt>Subtaupt?Leadtaubdtjetscore:Subtaubdtjetscore;
	tmva1l2tau_subtaubdtjetsigtrans = Leadtaupt<Subtaupt?Leadtaubdtjetscore:Subtaubdtjetscore;
	tmva1l2tau_mtautau = Mtautau;
	tmva1l2tau_jjdr = Jjdr;
	tmva1l2tau_leadtauptv =Leadtaupt>Subtaupt?Leadtauptv:Subtauptv;
	tmva1l2tau_subtauptv =Leadtaupt<Subtaupt?Leadtauptv:Subtauptv;
	tmva1l2tau_etamax = Etamax;
        tmva1l2tau_drltautau = Drltautau;
	tmva1l2tau_pttautau = Pttautau;
	tmva1l2tau_sumtautight = Leadtautight+Subtautight;
	tmva1l2tau_leadtaubtagbin = LeadtaubtagBin;
	tmva1l2tau_subtaubtagbin = SubtaubtagBin;
	myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
	myBDT =myBDT<1.0?myBDT:0.99;
	if((int)Event%2==1){ // odd events 
	  myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauEven");
	  myBDTx =myBDTx<1.0?myBDTx:0.99;
	}
	else{ // even events 
	  myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauOdd");
          myBDTx =myBDTx<1.0?myBDTx:0.99;
	}
	if(Nbjets25>0){
	  h1ltau_njets->Fill(Njets25, wtx);
	  h1ltau_nbjets->Fill(Nbjets25, wtx);
	  h1ltau_njbjets->Fill(Njets25+10*Nbjets25, wtx);
	  h1ltau_htjets->Fill(Htjets/GeV, wtx);
	  h1ltau_met->Fill(Met, wtx);
	  h1ltau_lept->Fill(fabs(Lept), wtx);
	  h1ltau_totcharge->Fill(Lept/fabs(Lept)*Leadtauch,wtx);
	  h1ltau_ljdr->Fill(Ljdr,wtx);
	  h1ltau_jjdr->Fill(Jjdr,wtx);
	  h1ltau_taupt->Fill(Leadtaupt,wtx);
	  h1ltau_taueta->Fill(Leadtaueta,wtx);
	  h1ltau_tautight->Fill(Leadtautight,wtx);
	  h1ltau_taubtag->Fill(Leadtaubtag>btagwpCut[1]?1:0,wtx);
	  h1ltau_taucharge->Fill(Leadtauch,wtx);
	  h1ltau_tauntrk->Fill(Leadtauntrk,wtx);
	  h1ltau_tautruth->Fill(Leadtautruth,wtx);
	  h1ltau_bdtjetsigtrans->Fill(Leadtaubdtjetscore,wtx);
	  h1ltau_tauptv->Fill(Leadtauptv, wtx);

	  int truthid = 0;
	  if(Leadtautruth==10&&Subtautruth==10){
	    truthid = 2;
	  }
	  else if(Leadtautruth==10||Subtautruth==10){
	    truthid = 1;
	  }
	  int leadfakeorig(-1);
	  int subfakeorig(-1);
	  if(Leadtautruth!=10){ 
	    if(Leadtautruth>0&&Leadtautruth<4){
	      leadfakeorig=2; 
	    }
	    else if(Leadtautruth==21){
	      leadfakeorig=1;
	    }  
	    else if(Leadtautruth==4){
	      leadfakeorig=3;
            }
            else if(Leadtautruth==5){
              leadfakeorig=4;
            }
            else{
              leadfakeorig=0;
            }
	  }
          if(Subtautruth!=10){
            if(Subtautruth>0&&Subtautruth<4){
	      subfakeorig=2;
	    }   
            else if(Subtautruth==21){
	      subfakeorig=1;
            }
            else if(Subtautruth==4){
              subfakeorig=3;
            }
            else if(Subtautruth==5){
              subfakeorig=4;
            }
            else{
              subfakeorig=0;
            }
          }
	  if(Leadtauch*Subtauch<0){ // os sign
	    h1ltau_Ltauosnjets->Fill(Njets25, wtx);
	    h1ltau_Ltauosnbjets->Fill(Nbjets25, wtx);
	    h1ltau_Ltauoshtjets->Fill(Htjets/GeV, wtx);
	    h1ltau_Ltauosleadtaupt->Fill(Leadtaupt>Subtaupt?Leadtaupt:Subtaupt, wtx);
	    h1ltau_Ltauossubtaupt->Fill(Leadtaupt<Subtaupt?Leadtaupt:Subtaupt, wtx);
	    h1ltau_Ltauosmtautau->Fill(Mtautau,wtx);
	    h1ltau_Ltauostruth->Fill(mylabelx[truthid],wtx);
	    h1ltau_Ltauosjjdr->Fill(Jjdr,wtx);
            h1ltau_Ltauosoldbdt->Fill(Bdt,wtx);
	    h1ltau_Ltauosoldbdt3bins->Fill(Bdt,wtx);
	    if(leadfakeorig>-1)h1ltau_Ltauosfakeorig->Fill(mylabel[leadfakeorig],wtx);
            if(subfakeorig>-1)h1ltau_Ltauosfakeorig->Fill(mylabel[subfakeorig],wtx);
	    h1ltau_Ltauosleadbdtjetsigtrans->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
	    h1ltau_Ltauossubbdtjetsigtrans->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
	    h1ltau_Ltauosleadtauptv->Fill(tmva1l2tau_leadtauptv, wtx);
            h1ltau_Ltauossubtauptv->Fill(tmva1l2tau_subtauptv,wtx);
	    h1ltau_Ltauosbdt->Fill(myBDT, wtx);
	    h1ltau_Ltauosbdt3bins->Fill(myBDT, wtx);
	    if(myBDT>0.5){
	      h1ltau_Ltauosmtautaubdtcut->Fill(Mtautau,wtx);
	      h1ltau_Ltauosnjetsbdtcut->Fill(Njets25, wtx);
	    }
	    if((Leadtautruth==10)&&(Subtautruth==10)){
	      h1ltau_Ltauosnjetstruth->Fill(Njets25, wtx);
	      h1ltau_Ltauosnbjetstruth->Fill(Nbjets25, wtx);
	      h1ltau_Ltauoshtjetstruth->Fill(Htjets/GeV, wtx);
	      h1ltau_Ltauosleadtaupttruth->Fill(Leadtaupt>Subtaupt?Leadtaupt:Subtaupt, wtx);
	      h1ltau_Ltauossubtaupttruth->Fill(Leadtaupt<Subtaupt?Leadtaupt:Subtaupt, wtx);
	      h1ltau_Ltauosmtautautruth->Fill(Mtautau,wtx);
	      h1ltau_Ltauosjjdrtruth->Fill(Jjdr,wtx);
	      h1ltau_Ltauosoldbdttruth->Fill(Bdt, wtx);
	      h1ltau_Ltauosoldbdt3binstruth->Fill(Bdt, wtx);
	      h1ltau_Ltauosleadbdtjetsigtranstruth->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
	      h1ltau_Ltauossubbdtjetsigtranstruth->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
	      h1ltau_Ltauosleadtauptvtruth->Fill(tmva1l2tau_leadtauptv, wtx);
	      h1ltau_Ltauossubtauptvtruth->Fill(tmva1l2tau_subtauptv,wtx);
	      h1ltau_Ltauosbdttruth->Fill(myBDT, wtx);
	      h1ltau_Ltauosbdt3binstruth->Fill(myBDT, wtx);
	    }
	  }
	  else{ // same sign 
            h1ltau_Ltaussnjets->Fill(Njets25, wtx);
            h1ltau_Ltaussnbjets->Fill(Nbjets25, wtx);
            h1ltau_Ltausshtjets->Fill(Htjets/GeV, wtx);
            h1ltau_Ltaussleadtaupt->Fill(Leadtaupt>Subtaupt?Leadtaupt:Subtaupt, wtx);
            h1ltau_Ltausssubtaupt->Fill(Leadtaupt<Subtaupt?Leadtaupt:Subtaupt, wtx);
            h1ltau_Ltaussmtautau->Fill(Mtautau,wtx);
            h1ltau_Ltausstruth->Fill(mylabelx[truthid],wtx);
	    h1ltau_Ltaussjjdr->Fill(Jjdr,wtx);
            h1ltau_Ltaussoldbdt->Fill(Bdt,wtx);
	    h1ltau_Ltaussoldbdt3bins->Fill(Bdt,wtx);
            if(leadfakeorig>-1)h1ltau_Ltaussfakeorig->Fill(mylabel[leadfakeorig],wtx);
            if(subfakeorig>-1)h1ltau_Ltaussfakeorig->Fill(mylabel[subfakeorig],wtx);
            h1ltau_Ltaussleadbdtjetsigtrans->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
            h1ltau_Ltausssubbdtjetsigtrans->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
            h1ltau_Ltaussleadtauptv->Fill(tmva1l2tau_leadtauptv, wtx);
            h1ltau_Ltausssubtauptv->Fill(tmva1l2tau_subtauptv,wtx);
            h1ltau_Ltaussbdt->Fill(myBDT, wtx);
            h1ltau_Ltaussbdt3bins->Fill(myBDT, wtx);
            if(myBDT>0.5){
              h1ltau_Ltaussmtautaubdtcut->Fill(Mtautau,wtx);
              h1ltau_Ltaussnjetsbdtcut->Fill(Njets25, wtx);
            }
            if((Leadtautruth==10)&&(Subtautruth==10)){
	      h1ltau_Ltaussnjetstruth->Fill(Njets25, wtx);
	      h1ltau_Ltaussnbjetstruth->Fill(Nbjets25, wtx);
	      h1ltau_Ltausshtjetstruth->Fill(Htjets/GeV, wtx);
	      h1ltau_Ltaussleadtaupttruth->Fill(Leadtaupt>Subtaupt?Leadtaupt:Subtaupt, wtx);
	      h1ltau_Ltausssubtaupttruth->Fill(Leadtaupt<Subtaupt?Leadtaupt:Subtaupt, wtx);
	      h1ltau_Ltaussmtautautruth->Fill(Mtautau,wtx);
	      h1ltau_Ltaussjjdrtruth->Fill(Jjdr,wtx);
	      h1ltau_Ltaussoldbdttruth->Fill(Bdt, wtx);
	      h1ltau_Ltaussoldbdt3binstruth->Fill(Bdt, wtx);
	      h1ltau_Ltaussleadbdtjetsigtranstruth->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
	      h1ltau_Ltausssubbdtjetsigtranstruth->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
	      h1ltau_Ltaussleadtauptvtruth->Fill(tmva1l2tau_leadtauptv, wtx);
	      h1ltau_Ltausssubtauptvtruth->Fill(tmva1l2tau_subtauptv,wtx);
	      h1ltau_Ltaussbdttruth->Fill(myBDT, wtx);
	      h1ltau_Ltaussbdt3binstruth->Fill(myBDT, wtx);
	    }
	  }
	}
      }
      // l2tau
      bool NobtagCut(0); // apply btag ==0 or not==1 
      if(Evtclass==2&&Leptrig){
	tmva1l2tau_njets25 = Njets25 ;
	tmva1l2tau_nbjets25 = Nbjets25;
	tmva1l2tau_htjets = Htjets;
	tmva1l2tau_leadtaupt = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt;
	tmva1l2tau_subtaupt = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
	tmva1l2tau_leadtaubdtjetsigtrans = Leadtaupt>Subtaupt?Leadtaubdtjetscore:Subtaubdtjetscore;
	tmva1l2tau_subtaubdtjetsigtrans = Leadtaupt<Subtaupt?Leadtaubdtjetscore:Subtaubdtjetscore;
	tmva1l2tau_mtautau = Mtautau;
	tmva1l2tau_jjdr = Jjdr;
	tmva1l2tau_leadtauptv =Leadtaupt>Subtaupt?Leadtauptv:Subtauptv;
	tmva1l2tau_subtauptv =Leadtaupt<Subtaupt?Leadtauptv:Subtauptv;
	tmva1l2tau_etamax = Etamax;
        tmva1l2tau_drltautau = Drltautau;
	tmva1l2tau_pttautau = Pttautau;
	tmva1l2tau_sumtautight = Leadtautight+Subtautight;
	tmva1l2tau_leadtaubtagbin =LeadtaubtagBin;
	tmva1l2tau_subtaubtagbin = SubtaubtagBin;
	myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
	myBDT =myBDT<1.0?myBDT:0.99;
        if((int)Event%2==1){ // odd events
          myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauEven");
          myBDTx =myBDTx<1.0?myBDTx:0.99;
        }
        else{ // even events
          myBDTx = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tauOdd");
          myBDTx =myBDTx<1.0?myBDTx:0.99;
        }
	// cap the njets to maximum 2 
	tmva1l2tau_nbjets25 = Nbjets25<3?Nbjets25:2; 
	double myBDTc = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
        myBDTc =myBDTc<1.0?myBDTc:0.99;
	// tight up in the signal region 8/2/2018 
	if(Nbjets25>0){
	  if((Leadtauch*Subtauch<0)&&Leadtautight&&Subtautight&&(Leadtaubtag<btagwpCut[1])&&(Subtaubtag<btagwpCut[1])&&
	     Leadfrompv&&Subfrompv){ 
	    h1l2tau_njets->Fill(Njets25<6?Njets25:5, wtx);
	    h1l2tau_nbjets->Fill(Nbjets25<4?Nbjets25:3, wtx);
	    h1l2tau_njbjets->Fill(Njets25+10*Nbjets25, wtx);
	    h1l2tau_htjets->Fill(Htjets/GeV, wtx);
	    double pt1 = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt;
	    double pt2 = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
	    h1l2tau_leadtaupt->Fill(pt1<125?pt1:124., wtx);
	    h1l2tau_subtaupt->Fill(pt2<125?pt2:124., wtx);
	    h1l2tau_mtautau->Fill(Mtautau<200?Mtautau:199.,wtx);
	    h1l2tau_met->Fill(Met, wtx);
	    h1l2tau_lept->Fill(fabs(Lept), wtx);
	    h1l2tau_totcharge->Fill(Lept/fabs(Lept)*Leadtauch,wtx);
	    h1l2tau_ljdr->Fill(Ljdr,wtx);
	    h1l2tau_jjdr->Fill(Jjdr,wtx);
	    h1l2tau_etamax->Fill(Etamax,wtx);
	    if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDT<0.5))))h1l2tau_bdtT3bins->Fill(myBDT,wtx);
	  }
	  int truthid = 0;
	  if(Leadtautruth==10&&Subtautruth==10){
	    truthid = 2;
	  }
	  else if(Leadtautruth==10||Subtautruth==10){
	    truthid = 1;
	  }
          int leadfakeorig(-1);
          int subfakeorig(-1);
          if(Leadtautruth!=10){
            if(Leadtautruth>0&&Leadtautruth<4){
              leadfakeorig=1;
            }
            else if(Leadtautruth==21){
              leadfakeorig=2;
            }
            else if(Leadtautruth==4){
              leadfakeorig=3;
            }
            else if(Leadtautruth==5){
              leadfakeorig=4;
            }
            else{
              leadfakeorig=0;
            }
          }
          if(Subtautruth!=10){
            if(Subtautruth>0&&Subtautruth<4){
              subfakeorig=1;
            }
            else if(Subtautruth==21){
              subfakeorig=2;
            }
            else if(Subtautruth==4){
              subfakeorig=3;
            }
            else if(Subtautruth==5){
              subfakeorig=4;
            }
            else{
              subfakeorig=0;
            }
          }
          if(Leadtauch*Subtauch<0){ // os sign
	    if(myBDT<0.5){
	      if(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1])h1l2tauos_sumtautight->Fill(Leadtautight+Subtautight, wtx);
	      if(Leadtautight&&Subtautight){
		h1l2tauos_leadtaubtagbin->Fill(LeadtaubtagBin, wtx);
		h1l2tauos_subtaubtagbin->Fill(SubtaubtagBin, wtx);
	      }
	    }
	    if(myBDT<0.5&&Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	      h1l2tauos_njets->Fill(Njets25<6?Njets25:5, wtx);
	      h1l2tauos_nbjets->Fill(Nbjets25<4?Nbjets25:3, wtx);
	      h1l2tauos_htjets->Fill(Htjets/GeV<800?Htjets/GeV:799., wtx);
	      double pt1 = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt; 
	      double pt2 = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt; 
	      h1l2tauos_leadtaupt->Fill(pt1<125?pt1:124., wtx);
	      h1l2tauos_subtaupt->Fill(pt2<125?pt2:124., wtx);
	      h1l2tauos_mtautau->Fill(Mtautau<200?Mtautau:199.,wtx);
	      h1l2tauos_truth->Fill(mylabelx[truthid],wtx);
	      h1l2tauos_jjdr->Fill(Jjdr<4?Jjdr:3.9,wtx);
	      h1l2tauos_etamax->Fill(Etamax,wtx);
	      h1l2tauos_frompv->Fill(Leadfrompv,wtx);
	      h1l2tauos_frompv->Fill(Subfrompv,wtx);
              h1l2tauos_drltautau->Fill(Drltautau,wtx);
	      h1l2tauos_pttautau->Fill(Pttautau,wtx);	      
	    }
	    if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&Bdt<0.5)))){	      
	      if((Leadtautight||Subtautight)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_oldbdt->Fill(Bdt,wtx);
		h1l2tauos_oldbdt3bins->Fill(Bdt,wtx);
		h1l2tauos_oldbdtf->Fill(Bdt,wtx);
                h1l2tauos_oldbdtM->Fill(Bdt,wtx);
		if(Leadtautight&&Subtautight){
		  h1l2tauos_oldbdtT->Fill(Bdt,wtx);
		  h1l2tauos_oldbdtT3bins->Fill(Bdt,wtx); // 5-11
		}
		if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		  h1l2tauos_oldbdtMx->Fill(Bdt,wtx);      // 5-11
		  h1l2tauos_oldbdtMx3bins->Fill(Bdt,wtx); // 5-11
		  if(Leadtautight&&Subtautight){
		    h1l2tauos_oldbdtTx->Fill(Bdt,wtx);  // 5-11
		    h1l2tauos_oldbdtTx3bins->Fill(Bdt,wtx); // 5-11
		  }
		}
	      }
	      if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauos_oldbdtnT->Fill(Bdt, wtx);
	       h1l2tauos_oldbdtnT3bins->Fill(Bdt, wtx); // 5-11
	       if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		 h1l2tauos_oldbdtnTx->Fill(Bdt,wtx);
		 h1l2tauos_oldbdtnTx3bins->Fill(Bdt,wtx); // 5-11
	       }
	      }
	    }
	    if(leadfakeorig>-1)h1l2tauos_fakeorig->Fill(mylabel[leadfakeorig],wtx);
            if(subfakeorig>-1)h1l2tauos_fakeorig->Fill(mylabel[subfakeorig],wtx);
            h1l2tauos_leadbdtjetsigtrans->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
            h1l2tauos_subbdtjetsigtrans->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
            h1l2tauos_leadtauptv->Fill(tmva1l2tau_leadtauptv, wtx);
            h1l2tauos_subtauptv->Fill(tmva1l2tau_subtauptv,wtx);
	    if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDTx<0.5)))){
	      if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&Leadfrompv&&Subfrompv){
		h1l2tauos_pvbdtX3bins->Fill(myBDTx, wtx);
	      }
	    }
            if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDTc<0.5)))){
              if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&Leadfrompv&&Subfrompv){
                h1l2tauos_pvbdtCapb3bins->Fill(myBDTc, wtx);
              }
            }
	    if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDT<0.5)))){
             h1l2tauos_bdt->Fill(myBDT, wtx);
	     h1l2tauos_bdt3bins->Fill(myBDT, wtx);
	     if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
	       h1l2tauos_bdtM->Fill(myBDT, wtx);
	     if(Leadtautight&&Subtautight&&Leadfrompv&&Subfrompv)h1l2tauos_pvbdtNbv3bins->Fill(myBDT, wtx);
	     if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauos_bdtT->Fill(myBDT, wtx);
               h1l2tauos_bdtT3bins->Fill(myBDT, wtx);
               if(Leadfrompv&&Subfrompv){
		 h1l2tauos_pvbdtT3bins->Fill(myBDT, wtx);
		 if(dump)*fout_txt<<" "<<Run<<" "<<Event<<" "<<myBDT<<" "<<Njets25<<" "<<Nbjets25<<std::endl;
	       }
	       h1l2tauos_bdtf->Fill(myBDT, wtx);
	     }
	     if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauos_bdtnT->Fill(myBDT, wtx);
	     }
	     if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
	       if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		 h1l2tauos_bdtMx->Fill(myBDT, wtx);
	       if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		 h1l2tauos_bdtTx->Fill(myBDT, wtx);
	       }
	       if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		 h1l2tauos_bdtnTx->Fill(myBDT, wtx);
	       }
	     }
	    }
            if((GetNevtAna()==0||_ismc)&&myBDT>0.5){
	      if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_mtautaubdtcut->Fill(Mtautau,wtx);
		h1l2tauos_njetsbdtcut->Fill(Njets25, wtx);
		h1l2tauos_leadtauptbdtcut->Fill(tmva1l2tau_leadtaupt, wtx);
		h1l2tauos_subtauptbdtcut->Fill(tmva1l2tau_subtaupt, wtx);
		h1l2tauos_truthbdtcut->Fill(mylabelx[truthid],wtx);
	      }
            }
            if((Leadtautruth==10)&&(Subtautruth==10)){ // no data
	      if(myBDT<0.5){
		if(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1])h1l2tauos_sumtautighttruth->Fill(Leadtautight+Subtautight, wtx);
		if(Leadtautight&&Subtautight){
		  h1l2tauos_leadtaubtagbintruth->Fill(LeadtaubtagBin, wtx);
		  h1l2tauos_subtaubtagbintruth->Fill(SubtaubtagBin, wtx);
		}
	      } 
	      if(myBDT<0.5&&Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_njetstruth->Fill(Njets25<6?Njets25:5, wtx);
		h1l2tauos_nbjetstruth->Fill(Nbjets25<4?Nbjets25:3, wtx);
		h1l2tauos_htjetstruth->Fill(Htjets/GeV<800?Htjets/GeV:799, wtx);
		double pt1 = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt;
		double pt2 = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
		h1l2tauos_leadtaupttruth->Fill(pt1<125?pt1:124., wtx);
		h1l2tauos_subtaupttruth->Fill(pt2<125?pt2:124., wtx);
		h1l2tauos_mtautautruth->Fill(Mtautau<200?Mtautau:199.,wtx);
		h1l2tauos_jjdrtruth->Fill(Jjdr<4?Jjdr:3.9,wtx);
		h1l2tauos_etamaxtruth->Fill(Etamax,wtx);
		h1l2tauos_frompvtruth->Fill(Leadfrompv,wtx);
		h1l2tauos_frompvtruth->Fill(Subfrompv,wtx);
		h1l2tauos_drltautautruth->Fill(Drltautau,wtx);
	      }
	      if((Leadtautight||Subtautight)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_oldbdttruth->Fill(Bdt, wtx);
		h1l2tauos_oldbdt3binstruth->Fill(Bdt, wtx);
		if(Leadtautight&&Subtautight){
                  h1l2tauos_oldbdtTtruth->Fill(Bdt,wtx);
		  h1l2tauos_oldbdtT3binstruth->Fill(Bdt,wtx); // 5-11
                }
		if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		  h1l2tauos_oldbdtMxtruth->Fill(Bdt,wtx);      // 5-11
		  h1l2tauos_oldbdtMx3binstruth->Fill(Bdt,wtx); // 5-11
		  if(Leadtautight&&Subtautight){
		    h1l2tauos_oldbdtTxtruth->Fill(Bdt,wtx);  // 5-11
		    h1l2tauos_oldbdtTx3binstruth->Fill(Bdt,wtx); // 5-11
		  }
		}
	      }
	      if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauos_oldbdtnTtruth->Fill(Bdt, wtx);
	       h1l2tauos_oldbdtnT3binstruth->Fill(Bdt, wtx); // 5-11
	       if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		 h1l2tauos_oldbdtnTxtruth->Fill(Bdt,wtx);
		 h1l2tauos_oldbdtnTx3binstruth->Fill(Bdt,wtx); // 5-11 
	       }
	      }
	      h1l2tauos_leadbdtjetsigtranstruth->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
	      h1l2tauos_subbdtjetsigtranstruth->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
	      h1l2tauos_leadtauptvtruth->Fill(tmva1l2tau_leadtauptv, wtx);
	      h1l2tauos_subtauptvtruth->Fill(tmva1l2tau_subtauptv,wtx);
	      h1l2tauos_bdttruth->Fill(myBDT, wtx);
	      h1l2tauos_bdt3binstruth->Fill(myBDT, wtx);
	      if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		h1l2tauos_bdtMtruth->Fill(myBDT, wtx);
	      if(Leadtautight&&Subtautight&&Leadfrompv&&Subfrompv)h1l2tauos_pvbdtNbv3binstruth->Fill(myBDT, wtx);
	      if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_bdtTtruth->Fill(myBDT, wtx);
                h1l2tauos_bdtT3binstruth->Fill(myBDT, wtx);
		if(Leadfrompv&&Subfrompv){
		  h1l2tauos_pvbdtT3binstruth->Fill(myBDT, wtx);
		  h1l2tauos_pvbdtX3binstruth->Fill(myBDTx, wtx);
                  h1l2tauos_pvbdtCapb3binstruth->Fill(myBDTc, wtx);
		}
	      }
	      if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauos_bdtnTtruth->Fill(myBDT, wtx);
	      }
	      if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		  h1l2tauos_bdtMxtruth->Fill(myBDT, wtx);
		if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		  h1l2tauos_bdtTxtruth->Fill(myBDT, wtx);
		}
		if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		  h1l2tauos_bdtnTxtruth->Fill(myBDT, wtx);
		}
	      }
	    }
          }
          else{ // same sign
	    if((Leadtautight||Subtautight)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	      h1l2tauss_oldbdt->Fill(Bdt,wtx);
              h1l2tauss_oldbdtM->Fill(Bdt,wtx);
	      h1l2tauss_oldbdt3bins->Fill(Bdt,wtx);
	      if(Leadtautight&&Subtautight){
		h1l2tauss_oldbdtT->Fill(Bdt,wtx);
		h1l2tauss_oldbdtT3bins->Fill(Bdt,wtx); // 5-11
	      }
	      if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		h1l2tauss_oldbdtMx->Fill(Bdt,wtx);     // 5-11
		h1l2tauss_oldbdtMx3bins->Fill(Bdt,wtx); // 5-11
		if(Leadtautight&&Subtautight){
		  h1l2tauss_oldbdtTx->Fill(Bdt,wtx); // 5-11
		  h1l2tauss_oldbdtTx3bins->Fill(Bdt,wtx); // 5-11
		}		
	      }	      
	    }
	    if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	      h1l2tauss_oldbdtnT->Fill(Bdt, wtx);
	      h1l2tauss_oldbdtnT3bins->Fill(Bdt, wtx); // 5-11
	      if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		h1l2tauss_oldbdtnTx->Fill(Bdt,wtx);
		h1l2tauss_oldbdtnTx3bins->Fill(Bdt,wtx); // 5-11
	      }
	    }
            if(leadfakeorig>-1)h1l2tauss_fakeorig->Fill(mylabel[leadfakeorig],wtx);
            if(subfakeorig>-1)h1l2tauss_fakeorig->Fill(mylabel[subfakeorig],wtx);
            h1l2tauss_leadbdtjetsigtrans->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
            h1l2tauss_subbdtjetsigtrans->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
            h1l2tauss_leadtauptv->Fill(tmva1l2tau_leadtauptv, wtx);
            h1l2tauss_subtauptv->Fill(tmva1l2tau_subtauptv,wtx);
            //h1l2tauss_bdt->Fill(myBDT, wtx);
	    //h1l2tauss_bdt3bins->Fill(myBDT, wtx);
            if(myBDT<0.5){
	      if(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1])h1l2tauss_sumtautight->Fill(Leadtautight+Subtautight, wtx);
	      if(Leadtautight&&Subtautight){
                h1l2tauss_leadtaubtagbin->Fill(LeadtaubtagBin, wtx);
                h1l2tauss_subtaubtagbin->Fill(SubtaubtagBin, wtx);
	      } 
            }
            if(myBDT<0.5&&Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
              h1l2tauss_njets->Fill(Njets25<6?Njets25:5, wtx);
              h1l2tauss_nbjets->Fill(Nbjets25<4?Nbjets25:3, wtx);
              h1l2tauss_htjets->Fill(Htjets/GeV<800?Htjets/GeV:799., wtx);
	      double pt1 = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt; 
	      double pt2 = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
              h1l2tauss_leadtaupt->Fill(pt1<125?pt1:124., wtx);
              h1l2tauss_subtaupt->Fill(pt2<125?pt2:124., wtx);
              h1l2tauss_mtautau->Fill(Mtautau<200?Mtautau:199.,wtx);
              h1l2tauss_truth->Fill(mylabelx[truthid],wtx);
              h1l2tauss_jjdr->Fill(Jjdr<4?Jjdr:3.9,wtx);
              h1l2tauss_etamax->Fill(Etamax,wtx);
	      h1l2tauss_frompv->Fill(Leadfrompv,wtx);
	      h1l2tauss_frompv->Fill(Subfrompv,wtx);
              h1l2tauss_drltautau->Fill(Drltautau,wtx);
              h1l2tauss_pttautau->Fill(Pttautau,wtx);
            }
            if(myBDT>0.5){
              h1l2tauss_mtautaubdtcut->Fill(Mtautau,wtx);
              h1l2tauss_njetsbdtcut->Fill(Njets25, wtx);
            }
            if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDTx<1.0)))){
              if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&Leadfrompv&&Subfrompv){
                h1l2tauss_pvbdtX3bins->Fill(myBDTx, wtx);
              }
            }
            if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDTc<1.0)))){
              if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&Leadfrompv&&Subfrompv){
                h1l2tauss_pvbdtCapb3bins->Fill(myBDTc, wtx);
              }
            }
	    if(GetNevtAna()==0||(GetNevtAna()==1&&(_ismc||((!_ismc)&&myBDT<1.0)))){
             h1l2tauss_bdt->Fill(myBDT, wtx);
	     h1l2tauss_bdt3bins->Fill(myBDT, wtx);
	     if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
	       h1l2tauss_bdtM->Fill(myBDT, wtx);
	     if(Leadtautight&&Subtautight&&Leadfrompv&&Subfrompv)h1l2tauss_pvbdtNbv3bins->Fill(myBDT, wtx);
	     if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauss_bdtT->Fill(myBDT, wtx);
               h1l2tauss_bdtT3bins->Fill(myBDT, wtx);
	       if(Leadfrompv&&Subfrompv)h1l2tauss_pvbdtT3bins->Fill(myBDT, wtx);
	       h1l2tauss_bdtf->Fill(myBDT, wtx);
	     }
	     if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauss_bdtnT->Fill(myBDT, wtx);
	     }
	     if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
	       if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		 h1l2tauss_bdtMx->Fill(myBDT, wtx);
	       if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		 h1l2tauss_bdtTx->Fill(myBDT, wtx);
	       }
	       if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		 h1l2tauss_bdtnTx->Fill(myBDT, wtx);
	       }
	     }
	    }
            if((Leadtautruth==10)&&(Subtautruth==10)){
	      if(myBDT<0.5){
		if(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1])h1l2tauss_sumtautighttruth->Fill(Leadtautight+Subtautight, wtx);
		if(Leadtautight&&Subtautight){
		  h1l2tauss_leadtaubtagbintruth->Fill(LeadtaubtagBin, wtx);
		  h1l2tauss_subtaubtagbintruth->Fill(SubtaubtagBin, wtx);
		}
	      }
	      if(myBDT<0.5&&Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauss_njetstruth->Fill(Njets25<6?Njets25:5, wtx);
		h1l2tauss_nbjetstruth->Fill(Nbjets25<4?Nbjets25:3, wtx);
		h1l2tauss_htjetstruth->Fill(Htjets/GeV<800?Htjets/GeV:799., wtx);
		double pt1 = Leadtaupt>Subtaupt?Leadtaupt:Subtaupt;
		double pt2 = Leadtaupt<Subtaupt?Leadtaupt:Subtaupt;
		h1l2tauss_leadtaupttruth->Fill(pt1<125?pt1:124., wtx);
		h1l2tauss_subtaupttruth->Fill(pt2<125?pt2:124., wtx);
		h1l2tauss_mtautautruth->Fill(Mtautau<200?Mtautau:199.,wtx);
		h1l2tauss_jjdrtruth->Fill(Jjdr<4?Jjdr:3.9,wtx);
                h1l2tauss_etamaxtruth->Fill(Etamax,wtx);
		h1l2tauss_frompvtruth->Fill(Leadfrompv,wtx);
		h1l2tauss_frompvtruth->Fill(Subfrompv,wtx);
		h1l2tauss_drltautautruth->Fill(Drltautau,wtx);
	      }
	      if((Leadtautight||Subtautight)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauss_oldbdttruth->Fill(Bdt, wtx);
                h1l2tauss_oldbdtMtruth->Fill(Bdt, wtx);
		h1l2tauss_oldbdt3binstruth->Fill(Bdt, wtx);
                if(Leadtautight&&Subtautight){
                  h1l2tauss_oldbdtTtruth->Fill(Bdt,wtx);
		  h1l2tauss_oldbdtT3binstruth->Fill(Bdt,wtx); // 5-11
                }
		if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		  h1l2tauss_oldbdtMxtruth->Fill(Bdt,wtx); // 5-11
		  h1l2tauss_oldbdtMx3binstruth->Fill(Bdt,wtx); // 5-11
		  if(Leadtautight&&Subtautight){
		    h1l2tauss_oldbdtTxtruth->Fill(Bdt,wtx);// 5-11
		    h1l2tauss_oldbdtTx3binstruth->Fill(Bdt,wtx); // 5-11
		  }		
		}	      
	      }
	      if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
	       h1l2tauss_oldbdtnT->Fill(Bdt, wtx);
	       h1l2tauss_oldbdtnTtruth->Fill(Bdt, wtx); // 5-11
	       if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		 h1l2tauss_oldbdtnTxtruth->Fill(Bdt,wtx);
		 h1l2tauss_oldbdtnTx3binstruth->Fill(Bdt,wtx); // 5-11
	       }
	      }
	      h1l2tauss_leadbdtjetsigtranstruth->Fill(tmva1l2tau_leadtaubdtjetsigtrans, wtx);
	      h1l2tauss_subbdtjetsigtranstruth->Fill(tmva1l2tau_subtaubdtjetsigtrans,wtx);
	      h1l2tauss_leadtauptvtruth->Fill(tmva1l2tau_leadtauptv, wtx);
	      h1l2tauss_subtauptvtruth->Fill(tmva1l2tau_subtauptv,wtx);
	      h1l2tauss_bdttruth->Fill(myBDT, wtx);
	      h1l2tauss_bdt3binstruth->Fill(myBDT, wtx);
	      if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		h1l2tauss_bdtMtruth->Fill(myBDT, wtx);
	      if(Leadtautight&&Subtautight&&Leadfrompv&&Subfrompv)h1l2tauss_pvbdtNbv3binstruth->Fill(myBDT, wtx);
	      if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauss_bdtTtruth->Fill(myBDT, wtx);
		h1l2tauss_bdtT3binstruth->Fill(myBDT, wtx);
		if(Leadfrompv&&Subfrompv){
		  h1l2tauss_pvbdtT3binstruth->Fill(myBDT, wtx);
		  h1l2tauss_pvbdtX3binstruth->Fill(myBDTx, wtx); 
                  h1l2tauss_pvbdtCapb3binstruth->Fill(myBDTc, wtx);
		}
	      }
	      if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		h1l2tauss_bdtnTtruth->Fill(myBDT, wtx);
	      }
	      if((abs(Lepid)==11&&Plv<-0.7&&LepambiguityType==0&&Lepqmistight>0.7)||(abs(Lepid)==13&&Plv<-0.5)){
		if((NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))&&(Leadtautight||Subtautight))
		  h1l2tauss_bdtMxtruth->Fill(myBDT, wtx);
		if(Leadtautight&&Subtautight&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		  h1l2tauss_bdtTxtruth->Fill(myBDT, wtx);
		}
		if((Leadtautight==0&&Subtautight==0)&&(NobtagCut||(Leadtaubtag<btagwpCut[1]&&Subtaubtag<btagwpCut[1]))){
		  h1l2tauss_bdtnTxtruth->Fill(myBDT, wtx);
		}
	      }
	    }
          }
        }
      }
      //std::cout<<" I am here "<<myBDT<<std::endl;
      newtree->Fill();
   }
   // end for now.                                                                                                                                   
   _histf->cd();
   _histf->Write();
   _histf->Close();
}
