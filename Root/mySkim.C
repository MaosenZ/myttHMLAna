#include "../myttHAna/Declarations.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"

using namespace Declarations;

void mySkim(TString dsid, TString treename){
  
  TString inputpath=prepath+dsid;
  TFile *f1=new TFile(inputpath);
  TTree *tree=(TTree*)f1->Get(treename);

  //skim here
  TString outputname=outpath+dsid;
  TFile *f2=new TFile(outputname,"recreate");
  TTree *outtree = tree->CopyTree("passEventCleaning && (onelep_type||dilep_type||trilep_type||quadlep_type) && ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 ))||(RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))) && onelep_type>0 && ( abs(lep_ID_0)==13 ||((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 && nTaus_OR_Pt25==2 &&tau_tight_0 && tau_tight_1&&tau_btag70_0==0 && tau_btag70_1==0 &&nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1"); //skip MVA1l2tau_weight>0.5 tau_charge_0*tau_charge_1<0
  outtree->Write();
  f2->Close();
} 
