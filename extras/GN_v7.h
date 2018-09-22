//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 14 14:35:37 2018 by ROOT version 6.12/06
// from TTree nominal/Mini Ntuples
// found on file: ../ttHMLSamps/v7_01/all/tth.root
//////////////////////////////////////////////////////////

#ifndef GN_v7_h
#define GN_v7_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class GN_v7 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Bool_t          is1L2Tau;
   Bool_t          is2LSS0Tau;
   Bool_t          pass_tight_2L;
   Bool_t          pass_SS_2L;
   Bool_t          is2LSS1Tau;
   Bool_t          is2LOS1Tau;
   Bool_t          is3L;
   Bool_t          is3L1Tau;
   Bool_t          is4L;
   Bool_t          is2lLowNJet0Tau;
   Bool_t          is2LSS0Tau_SR_Relaxed;
   Bool_t          is2LSS1Tau_SR_Relaxed;
   Bool_t          is3L0Tau_SR_Relaxed;
   Bool_t          is3L0Tau_SR_Relaxed3j;
   Bool_t          is4L_SR_VV_Relaxed;
   Bool_t          is4L_SR_ttV_Relaxed;
   Bool_t          is4L_SR_ttV_Zenriched;
   Bool_t          is3L0Tau_CR_ttbar_Relaxed;
   Bool_t          is3L0Tau_CR_VV_Relaxed;
   Bool_t          is3L0Tau_CR_ttW_Relaxed;
   Bool_t          is2L_VR_ttW_ICHEP;
   Bool_t          is2L_VR_ttbarFakes_ICHEP;
   Bool_t          is4lCRttZRelaxed;
   Bool_t          is2LOS1Tau_CR_ttbar;
   Bool_t          is2LOS1Tau_CR_ttZ;
   Bool_t          is2LOS1Tau_CR_W;
   Bool_t          is3L1Tau_VR;
   Char_t          is2lOS0TauBaseline;
   Char_t          is2lOS0TauBaseline_ee;
   Char_t          is2lOS0TauBaseline_mm;
   Char_t          is2lOS0TauBaseline_OF;
   Char_t          is2lOS0TauBaseline_me;
   Char_t          is2lOS0TauBaseline_em;
   Char_t          is2lSS0TauBaseline;
   Char_t          is2lSS0TauBaseline_ee;
   Char_t          is2lSS0TauBaseline_mm;
   Char_t          is2lSS0TauBaseline_OF;
   Char_t          is2lSS0TauBaseline_me;
   Char_t          is2lSS0TauBaseline_em;
   Char_t          is2lOS1TauBaseline;
   Char_t          is2lOS1TauBaseline_ee;
   Char_t          is2lOS1TauBaseline_mm;
   Char_t          is2lOS1TauBaseline_OF;
   Char_t          is2lOS1TauBaseline_me;
   Char_t          is2lOS1TauBaseline_em;
   Char_t          is2lSS1TauBaseline;
   Char_t          is2lSS1TauBaseline_ee;
   Char_t          is2lSS1TauBaseline_mm;
   Char_t          is2lSS1TauBaseline_OF;
   Char_t          is2lSS1TauBaseline_me;
   Char_t          is2lSS1TauBaseline_em;
   Char_t          is3lBaseline;
   Char_t          is3lBaselineNoZVeto;
   Char_t          is2lss1tau_regionB;
   Char_t          is2lss1tau_regionC;
   Char_t          is2lss1tau_regionD;
   Bool_t          isGNv02;
   Float_t         minOSMll;
   Float_t         minOSSFMll;
   Float_t         jet_flvWtOrdr_0_pt;
   Float_t         jet_flvWtOrdr_0_eta;
   Float_t         jet_flvWtOrdr_0_phi;
   Float_t         jet_flvWtOrdr_0_E;
   Float_t         jet_flvWtOrdr_0_mv2c10;
   Float_t         jet_flvWtOrdr_1_pt;
   Float_t         jet_flvWtOrdr_1_eta;
   Float_t         jet_flvWtOrdr_1_phi;
   Float_t         jet_flvWtOrdr_1_E;
   Float_t         jet_flvWtOrdr_1_mv2c10;
   Float_t         jet_flvWtOrdr_2_pt;
   Float_t         jet_flvWtOrdr_2_eta;
   Float_t         jet_flvWtOrdr_2_phi;
   Float_t         jet_flvWtOrdr_2_E;
   Float_t         jet_flvWtOrdr_2_mv2c10;
   Float_t         DEtall01;
   Float_t         DEtall02;
   Float_t         DEtall12;
   Int_t           lep_flavour;
   Int_t           jet_flavor;
   Int_t           total_charge_2lSS;
   Int_t           isExtConv;
   Int_t           isIntConv;
   Float_t         max_eta;
   Float_t         SDRll;
   Float_t         DeltaR_max_lep;
   Float_t         DPhi_max_lep_met;
   Float_t         DeltaR_min_lep_jet;
   Float_t         minDeltaR_LJ_0;
   Float_t         minDeltaR_LJ_1;
   Float_t         minDeltaR_LJ_2;
   Float_t         Meff;
   Float_t         Mjj_closeW;
   Float_t         DRlb_h;
   Float_t         ptlb_h;
   Float_t         DeltaRLeadjets;
   Float_t         jet1pTbin;
   Float_t         jet2pTbin;
   Float_t         jet3pTbin;
   Float_t         jet3etabin;
   Float_t         jet1MV2c10_bin;
   Float_t         jet2MV2c10_bin;
   Float_t         MvisH;
   Float_t         MvisnonH;
   Float_t         lep_PtVarCone20Rel_1;
   Float_t         DeltaRLeadLepClosestJet;
   Float_t         Ml2l3met;
   Float_t         FSF_4L_tot;
   Float_t         FSF_4L_tot_up;
   Float_t         FSF_4L_tot_down;
   Int_t           FSF_category;
   Float_t         FSF_4L_e_L;
   Float_t         FSF_4L_e_H;
   Float_t         FSF_4L_m;
   Float_t         jet2_pt;
   Float_t         jet2_eta;
   Float_t         jet2_phi;
   Float_t         jet3_pt;
   Float_t         jet3_eta;
   Float_t         jet3_phi;
   Int_t           jet0_tagWeightBin;
   Int_t           jet1_tagWeightBin;
   Int_t           jet2_tagWeightBin;
   Int_t           jet3_tagWeightBin;
   Int_t           N_el;
   Int_t           N_mu;
   Float_t         tempDPl0t;
   Float_t         tempDPl1t;
   Float_t         tempDP2l;
   Float_t         tempDPlt_closest;
   Float_t         tempDPlt_furthest;
   Float_t         DeltaRSubLepClosestJet;
   Int_t           SignProduct2sslt;
   Float_t         TransverseMassLeadLepMET;
   Float_t         LD_HTmiss_ETmiss;
   Float_t         Mjj_nonb;
   Float_t         Mtop;
   Float_t         MtopW;
   Float_t         temptopoetcone20overpTlep0;
   Float_t         temptopoetcone20overpTlep1;
   Float_t         tempptvarcone20overpTlep0;
   Float_t         tempptvarcone20overpTlep1;
   Bool_t          lep_isAntiTight_0;
   Bool_t          lep_isAntiTight_1;
   Float_t         tau_tight_0;
   Float_t         tau_tight_1;
   Float_t         tau_btag70_0;
   Float_t         tau_btag70_1;
   Float_t         tau_truth_0;
   Float_t         tau_truth_1;
   Float_t         htjets_1l2tau;
   Float_t         jjdrmin_1l2tau;
   Float_t         mtautau_1l2tau;
   Float_t         njets_1l2tau;
   Float_t         nbjets_1l2tau;
   Float_t         DRlj00;
   Float_t         DRjj01;
   Float_t         min_DRl0j;
   Float_t         min_DRl1j;
   Float_t         min_DRl2j;
   Float_t         min_DRl0b;
   Float_t         min_DRl1b;
   Float_t         min_DRl2b;
   Float_t         min_DRlj_new;
   Int_t           nJets_OR_T_overflow;
   Int_t           nJets_OR_T_MV2c10_70_overflow;
   Float_t         DPhij0MET;
   Float_t         lead_BjetPt;
   Float_t         lead_jet_sumBEff;
   Float_t         sublead_jet_sumBEff;
   Int_t           lead_jet_pass_FixedCutBEff_70;
   Int_t           sublead_jet_pass_FixedCutBEff_70;
   Float_t         lead_jet_is_lead_antitag;
   Float_t         lead_jet_is_lead_tag;
   Float_t         lep_Pt_1_new;
   Float_t         lep_Pt_2_new;
   Float_t         lep_ID_1_new;
   Float_t         lep_ID_2_new;
   Float_t         lep_isPrompt_1_new;
   Float_t         lep_isPrompt_2_new;
   Float_t         lep_truthOrigin_1_new;
   Float_t         lep_truthOrigin_2_new;
   Float_t         lep_truthParentPdgId_1_new;
   Float_t         lep_truthParentPdgId_2_new;
   Float_t         lep_truthParentType_1_new;
   Float_t         lep_truthParentPdgId_2_new;
   Float_t         lep_isQMisID_1_new;
   Float_t         lep_isQMisID_2_new;
   Float_t         lep_Eta_1_new;
   Float_t         lep_Eta_2_new;
   Float_t         lep_Phi_1_new;
   Float_t         lep_Phi_2_new;
   Float_t         lep_isolationFixedCutLoose_1_new;
   Float_t         lep_isolationFixedCutLoose_2_new;
   Float_t         lep_promptLeptonVeto_TagWeight_1_new;
   Float_t         lep_promptLeptonVeto_TagWeight_2_new;
   Float_t         lep_isTightLH_1_new;
   Float_t         lep_isTightLH_2_new;
   Float_t         lep_chargeIDBDTTight_1_new;
   Float_t         lep_chargeIDBDTTight_2_new;
   Float_t         lep_ambiguityType_1_new;
   Float_t         lep_ambiguityType_2_new;
   Float_t         lep_isMedium_1_new;
   Float_t         lep_isMedium_2_new;
   Float_t         EventWeight;
   Char_t          lep_isTightSelected_0;
   Char_t          lep_isTightSelected_1;
   Char_t          lep_isTightSelected_2;
   Char_t          lep_isTightSelected_3;
   Char_t          lep_isTightSelected_2LOS1Tau_0;
   Char_t          lep_isTightSelected_2LOS1Tau_1;
   Char_t          lep_isTightSelectedAndPt_0;
   Char_t          lep_isTightSelectedAndPt_1;
   Char_t          lep_isTightSelectedAndPt_2;
   Char_t          lep_isTightSelectedAndPt_3;
   Char_t          lep_isTightSelectedAndPt_2LOS1Tau_0;
   Char_t          lep_isTightSelectedAndPt_2LOS1Tau_1;
   vector<int>     *jet_flavor_truth_label_ghost;
   vector<float>   *jet_pT;
   vector<float>   *jet_eta;
   Float_t         MVA2lSSMarseille_weight_ttV;
   Float_t         MVA2lSSMarseille_weight_ttbar;
   Float_t         MVA2lSSMarseille_weight_ttV_2;
   Float_t         MVA2lSSMarseille_weight_ttbar_2;
   Float_t         MVA2lSS1tau_weight_random_ttbar;
   Float_t         MVA2lSS1tau_weight_CT_ttbar;
   Float_t         MVA2lSS1tau_weight_random_nottbar;
   Float_t         MVA2lSS1tau_weight_CT_nottbar;
   Float_t         MVA2lOS1tau_weight;
   Float_t         SumPtBJet;
   Float_t         SumPtJet;
   Float_t         SumPtLep;
   Float_t         DRlj;
   Float_t         DRlb;
   Float_t         DRjb;
   Float_t         DRl0tau;
   Float_t         DRl1tau;
   Float_t         MVA3lCERN_weight_ttH;
   Float_t         MVA3lCERN_weight_ttW;
   Float_t         MVA3lCERN_weight_ttZ;
   Float_t         MVA3lCERN_weight_VV;
   Float_t         MVA3lCERN_weight_ttbar;
   Float_t         MVA3lCERN_category;
   Float_t         MVA3lZZCERN_weight_ttH;
   Float_t         MVA3lZZCERN_weight_ttZ;
   Float_t         MVA3lZZCERN_weight_VV;
   Float_t         MVA3lZZCERN_category;
   Float_t         MVA4lBonn_weight_ttZ;
   Float_t         fourLep_PME;
   Float_t         MVA1l2tau_weight;
   Float_t         D_PME;
   Float_t         BDT_out;
   Float_t         mlb_h;
   Float_t         mOSl_h;
   Float_t         averageMW;
   vector<float>   *lepton_PromptLeptonIso_TagWeight;
   vector<float>   *lepton_ChargeIDBDTTight;
   Bool_t          CRB1_2lSStau_FF_Fake;
   Bool_t          CRB1_2lSStau_FF_Prompt;
   Bool_t          CRB2_2lSStau_FF_Fake;
   Bool_t          CRB2_2lSStau_FF_RealTau;
   Bool_t          CRB3_2lSStau_FF_Fake;
   Bool_t          CRB3_2lSStau_FF_RealTau;
   Bool_t          CRB3_2lSStau_FF_Prompt;
   Float_t         CRB1_2lSStau_FF_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin1Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin1Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin2Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin2Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin3Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin3Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin4Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin4Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin5Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_elStat_Bin5Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin1Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin1Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin2Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin2Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin3Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin3Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin4Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin4Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin5Up_EventWeight;
   Float_t         CRB1_2lSStau_FF_muStat_Bin5Dn_EventWeight;
   Float_t         CRB1_2lSStau_FF_ttwUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_ttwDn_EventWeight;
   Float_t         CRB1_2lSStau_FF_ttzUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_ttzDn_EventWeight;
   Float_t         CRB1_2lSStau_FF_vvUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_vvDn_EventWeight;
   Float_t         CRB1_2lSStau_FF_rareUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_rareDn_EventWeight;
   Float_t         CRB1_2lSStau_FF_tthUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_tthDn_EventWeight;
   Float_t         CRB1_2lSStau_FF_QMisIdUp_EventWeight;
   Float_t         CRB1_2lSStau_FF_QMisIdDn_EventWeight;
   Float_t         CRB2_2lSStau_FF_EventWeight;
   Float_t         CRB2_2lSStau_FF_RealtauUp_EventWeight;
   Float_t         CRB2_2lSStau_FF_RealtauDn_EventWeight;
   Float_t         CRB2_2lSStau_FF_tthUp_EventWeight;
   Float_t         CRB2_2lSStau_FF_tthDn_EventWeight;
   Float_t         CRB2_2lSStau_FF_QMisIdUp_EventWeight;
   Float_t         CRB2_2lSStau_FF_QMisIdDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_EventWeight;
   Float_t         CRB3_2lSStau_FF_RealtauUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_RealtauDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_ttwUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_ttwDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_ttzUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_ttzDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_vvUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_vvDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_rareUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_rareDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_tthUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_tthDn_EventWeight;
   Float_t         CRB3_2lSStau_FF_QMisIdUp_EventWeight;
   Float_t         CRB3_2lSStau_FF_QMisIdDn_EventWeight;
   Bool_t          isttH;
   Bool_t          isttZ;
   Bool_t          isttW;
   Bool_t          isVV;
   Bool_t          istZ;
   Bool_t          isWtZ;
   Bool_t          istHjb;
   Bool_t          isWtH;
   Bool_t          isttWW;
   Bool_t          isVH;
   Bool_t          isVVV;
   Bool_t          is3Tops;
   Bool_t          is4Tops;
   Bool_t          isttbar;
   Bool_t          isttll;
   Bool_t          israreTop;
   Bool_t          isttGamma;
   Bool_t          isttbarDilep;
   Char_t          passTrigger;
   Float_t         scale_nom;
   Float_t         scale_varA14up;
   Float_t         scale_varA14down;
   Float_t         scale_varRup;
   Float_t         scale_varRdown;
   Float_t         scale_varFup;
   Float_t         scale_varFdown;
   Float_t         scale_varRFup;
   Float_t         scale_varRFdown;
   Double_t        pileupEventWeight_UP;
   Double_t        pileupEventWeight_DOWN;
   Double_t        JVT_EventWeight_UP;
   Double_t        JVT_EventWeight_DOWN;
   Double_t        bTagSF_weight_MV2c10_FixedCutBEff_70;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepSFTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepEffTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepEffTrigTight_EL_SF_Trigger_UP;
   Float_t         lepEffTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepEffTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigTight_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepEffTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Reco_UP;
   Float_t         lepSFObjTight_EL_SF_Reco_UP;
   Float_t         lepSFObjLoose_EL_SF_Reco_DOWN;
   Float_t         lepSFObjTight_EL_SF_Reco_DOWN;
   Float_t         lepSFObjLoose_EL_SF_ID_UP;
   Float_t         lepSFObjTight_EL_SF_ID_UP;
   Float_t         lepSFObjLoose_EL_SF_ID_DOWN;
   Float_t         lepSFObjTight_EL_SF_ID_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Isol_UP;
   Float_t         lepSFObjTight_EL_SF_Isol_UP;
   Float_t         lepSFObjLoose_EL_SF_Isol_DOWN;
   Float_t         lepSFObjTight_EL_SF_Isol_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
   Float_t         tauSFTight_TAU_SF_ELEOLR_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_JETID_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_JETID_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_JETID_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_JETID_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_RECO_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_RECO_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_RECO_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_RECO_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_JETID_HIGHPT_UP;
   Float_t         tauSFLoose_TAU_SF_JETID_HIGHPT_UP;
   Float_t         tauSFTight_TAU_SF_JETID_HIGHPT_DOWN;
   Float_t         tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN;
   Float_t         tauSFTight_TAU_SF_RECO_HIGHPT_UP;
   Float_t         tauSFLoose_TAU_SF_RECO_HIGHPT_UP;
   Float_t         tauSFTight_TAU_SF_RECO_HIGHPT_DOWN;
   Float_t         tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN;
   Float_t         tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;
   Char_t          forFit_promptSel;
   Char_t          forFit_tightSel;
   Char_t          forFit_3l0tauBaseLine;
   Char_t          forFit_3l0tauFakesSel;
   Char_t          forFit_2lss0tauBaseLine;
   Char_t          forFit_2lssFakeQmisSel;
   Double_t        mcWeightOrg;
   Double_t        pileupEventWeight_090;
   Double_t        MV2c10_60_EventWeight;
   Double_t        MV2c10_70_EventWeight;
   Double_t        MV2c10_77_EventWeight;
   Double_t        MV2c10_85_EventWeight;
   Double_t        MV2c10_Continuous_EventWeight;
   Double_t        bTagSF_weight_Continuous;
   Double_t        JVT_EventWeight;
   Double_t        SherpaNJetWeight;
   ULong64_t       EventNumber;
   UInt_t          RunNumber;
   UInt_t          lbn;
   UInt_t          bcid;
   Bool_t          passEventCleaning;
   Float_t         m_vxp_x;
   Float_t         m_vxp_y;
   Float_t         m_vxp_z;
   Double_t        higgs_pt;
   Double_t        higgs_eta;
   Double_t        higgs_phi;
   Double_t        higgs_E;
   Double_t        higgs_rapidity;
   Double_t        top_pt;
   Double_t        top_eta;
   Double_t        top_phi;
   Double_t        top_E;
   Double_t        antitop_pt;
   Double_t        antitop_eta;
   Double_t        antitop_phi;
   Double_t        antitop_E;
   Int_t           RunYear;
   Int_t           HF_Classification;
   Int_t           HF_ClassificationTop;
   Int_t           DLF_Classification;
   Int_t           higgsDecayMode;
   UInt_t          mc_channel_number;
   Char_t          mc_isAFII;
   Float_t         averageIntPerXing_uncorr;
   Float_t         averageIntPerXing;
   Float_t         actualIntPerXing;
   Int_t           m_vxp_n;
   Int_t           m_vxpu_n;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_RefFinal_sumet;
   Char_t          m_hasMEphoton;
   Char_t          m_hasMEphoton_DRgt02_nonhad;
   Char_t          m_MEphoton_OLtty_keepEvent;
   Char_t          m_MEphoton_OLtty_cat1;
   Char_t          m_MEphoton_OLtty_cat2;
   Char_t          m_MEphoton_OLtty_cat3;
   Char_t          m_MEphoton_OLtty_cat4;
   Float_t         m_MEphoton_pt;
   Float_t         m_MEphoton_eta;
   Float_t         m_MEphoton_phi;
   Float_t         m_MEphoton_mother_pt;
   Float_t         m_MEphoton_mother_eta;
   Float_t         m_MEphoton_mother_phi;
   Int_t           m_MEphoton_mother_pdgId;
   Char_t          HLT_2e12_lhloose_L12EM10VH;
   Char_t          HLT_2e12_lhvloose_nod0_L12EM10VH;
   Char_t          HLT_2e17_lhvloose_nod0;
   Char_t          HLT_2e24_lhvloose_nod0;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e140_lhloose;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_e17_lhloose_mu14;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e24_lhmedium_L1EM18VH;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_e24_lhmedium_nod0_L1EM20VH;
   Char_t          HLT_e26_lhtight_iloose;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_e60_medium;
   Char_t          HLT_e7_lhmedium_mu24;
   Char_t          HLT_e7_medium_mu24;
   Char_t          HLT_mu18_mu8noL1;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_mu20_mu8noL1;
   Char_t          HLT_mu22_mu8noL1;
   Char_t          HLT_mu24_imedium;
   Char_t          HLT_mu24_ivarloose;
   Char_t          HLT_mu24_ivarmedium;
   Char_t          HLT_mu26_imedium;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_mu50;
   Char_t          HLT_2e17_lhvloose_nod0_L12EM15VHI;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_0;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_1;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_2;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_0;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_1;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_2;
   Float_t         lep_promptLeptonInput_DL1mu_0;
   Float_t         lep_promptLeptonInput_DL1mu_1;
   Float_t         lep_promptLeptonInput_DL1mu_2;
   Float_t         lep_promptLeptonInput_DRlj_0;
   Float_t         lep_promptLeptonInput_DRlj_1;
   Float_t         lep_promptLeptonInput_DRlj_2;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_0;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_1;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_2;
   Float_t         lep_promptLeptonInput_PtFrac_0;
   Float_t         lep_promptLeptonInput_PtFrac_1;
   Float_t         lep_promptLeptonInput_PtFrac_2;
   Float_t         lep_promptLeptonInput_PtRel_0;
   Float_t         lep_promptLeptonInput_PtRel_1;
   Float_t         lep_promptLeptonInput_PtRel_2;
   Float_t         lep_promptLeptonInput_ip2_0;
   Float_t         lep_promptLeptonInput_ip2_1;
   Float_t         lep_promptLeptonInput_ip2_2;
   Float_t         lep_promptLeptonInput_ip3_0;
   Float_t         lep_promptLeptonInput_ip3_1;
   Float_t         lep_promptLeptonInput_ip3_2;
   Float_t         lep_promptLeptonInput_rnnip_0;
   Float_t         lep_promptLeptonInput_rnnip_1;
   Float_t         lep_promptLeptonInput_rnnip_2;
   Float_t         lep_ID_0;
   Int_t           lep_Index_0;
   UChar_t         lep_ambiguityType_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_Phi_0;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_topoEtcone20_0;
   Float_t         lep_topoEtcone30_0;
   Float_t         lep_topoEtcone40_0;
   Float_t         lep_ptVarcone20_0;
   Float_t         lep_ptVarcone30_0;
   Float_t         lep_ptVarcone40_0;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_Z0SinTheta_0;
   Float_t         lep_d0_0;
   Float_t         lep_z0_0;
   Float_t         lep_vz_0;
   Float_t         lep_deltaz0_0;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isMediumLH_0;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isTight_0;
   Char_t          lep_isMedium_0;
   Char_t          lep_isLoose_0;
   Int_t           lep_isolationLooseTrackOnly_0;
   Int_t           lep_isolationLoose_0;
   Int_t           lep_isolationGradient_0;
   Int_t           lep_isolationGradientLoose_0;
   Int_t           lep_isolationFixedCutTight_0;
   Int_t           lep_isolationFixedCutTightTrackOnly_0;
   Int_t           lep_isolationFixedCutLoose_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_isTrigMatchDLT_0;
   Char_t          lep_isPrompt_0;
   Char_t          lep_isFakeLep_0;
   Char_t          lep_isQMisID_0;
   Char_t          lep_isConvPh_0;
   Char_t          lep_isIntConvPh_0;
   Char_t          lep_isExtConvPh_0;
   Char_t          lep_isISR_FSR_Ph_0;
   Char_t          lep_isBrems_0;
   Char_t          lep_isTruthMatched_0;
   Int_t           lep_truthType_0;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthPdgId_0;
   Int_t           lep_truthStatus_0;
   Int_t           lep_truthParentType_0;
   Int_t           lep_truthParentOrigin_0;
   Int_t           lep_truthParentPdgId_0;
   Int_t           lep_truthParentStatus_0;
   Float_t         lep_truthPt_0;
   Float_t         lep_truthEta_0;
   Float_t         lep_truthPhi_0;
   Float_t         lep_truthM_0;
   Float_t         lep_truthE_0;
   Float_t         lep_truthRapidity_0;
   Float_t         lep_SFIDLoose_0;
   Float_t         lep_SFIDTight_0;
   Float_t         lep_SFTrigLoose_0;
   Float_t         lep_SFTrigTight_0;
   Float_t         lep_EffTrigLoose_0;
   Float_t         lep_EffTrigTight_0;
   Float_t         lep_SFIsoLoose_0;
   Float_t         lep_SFIsoTight_0;
   Float_t         lep_SFReco_0;
   Float_t         lep_SFTTVA_0;
   Float_t         lep_SFObjLoose_0;
   Float_t         lep_SFObjTight_0;
   Float_t         lep_chargeIDBDTLoose_0;
   Float_t         lep_chargeIDBDTMedium_0;
   Float_t         lep_chargeIDBDTTight_0;
   Float_t         lep_promptLeptonIso_TagWeight_0;
   Float_t         lep_promptLeptonVeto_TagWeight_0;
   Float_t         lep_ID_1;
   Int_t           lep_Index_1;
   UChar_t         lep_ambiguityType_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_Phi_1;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_topoEtcone20_1;
   Float_t         lep_topoEtcone30_1;
   Float_t         lep_topoEtcone40_1;
   Float_t         lep_ptVarcone20_1;
   Float_t         lep_ptVarcone30_1;
   Float_t         lep_ptVarcone40_1;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_Z0SinTheta_1;
   Float_t         lep_d0_1;
   Float_t         lep_z0_1;
   Float_t         lep_vz_1;
   Float_t         lep_deltaz0_1;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isMediumLH_1;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isTight_1;
   Char_t          lep_isMedium_1;
   Char_t          lep_isLoose_1;
   Int_t           lep_isolationLooseTrackOnly_1;
   Int_t           lep_isolationLoose_1;
   Int_t           lep_isolationGradient_1;
   Int_t           lep_isolationGradientLoose_1;
   Int_t           lep_isolationFixedCutTight_1;
   Int_t           lep_isolationFixedCutTightTrackOnly_1;
   Int_t           lep_isolationFixedCutLoose_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_isTrigMatchDLT_1;
   Char_t          lep_isPrompt_1;
   Char_t          lep_isFakeLep_1;
   Char_t          lep_isQMisID_1;
   Char_t          lep_isConvPh_1;
   Char_t          lep_isIntConvPh_1;
   Char_t          lep_isExtConvPh_1;
   Char_t          lep_isISR_FSR_Ph_1;
   Char_t          lep_isBrems_1;
   Char_t          lep_isTruthMatched_1;
   Int_t           lep_truthType_1;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthPdgId_1;
   Int_t           lep_truthStatus_1;
   Int_t           lep_truthParentType_1;
   Int_t           lep_truthParentOrigin_1;
   Int_t           lep_truthParentPdgId_1;
   Int_t           lep_truthParentStatus_1;
   Float_t         lep_truthPt_1;
   Float_t         lep_truthEta_1;
   Float_t         lep_truthPhi_1;
   Float_t         lep_truthM_1;
   Float_t         lep_truthE_1;
   Float_t         lep_truthRapidity_1;
   Float_t         lep_SFIDLoose_1;
   Float_t         lep_SFIDTight_1;
   Float_t         lep_SFTrigLoose_1;
   Float_t         lep_SFTrigTight_1;
   Float_t         lep_EffTrigLoose_1;
   Float_t         lep_EffTrigTight_1;
   Float_t         lep_SFIsoLoose_1;
   Float_t         lep_SFIsoTight_1;
   Float_t         lep_SFReco_1;
   Float_t         lep_SFTTVA_1;
   Float_t         lep_SFObjLoose_1;
   Float_t         lep_SFObjTight_1;
   Float_t         lep_chargeIDBDTLoose_1;
   Float_t         lep_chargeIDBDTMedium_1;
   Float_t         lep_chargeIDBDTTight_1;
   Float_t         lep_promptLeptonIso_TagWeight_1;
   Float_t         lep_promptLeptonVeto_TagWeight_1;
   Float_t         lep_ID_2;
   Int_t           lep_Index_2;
   UChar_t         lep_ambiguityType_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_Phi_2;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_topoEtcone20_2;
   Float_t         lep_topoEtcone30_2;
   Float_t         lep_topoEtcone40_2;
   Float_t         lep_ptVarcone20_2;
   Float_t         lep_ptVarcone30_2;
   Float_t         lep_ptVarcone40_2;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_Z0SinTheta_2;
   Float_t         lep_d0_2;
   Float_t         lep_z0_2;
   Float_t         lep_vz_2;
   Float_t         lep_deltaz0_2;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isMediumLH_2;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isTight_2;
   Char_t          lep_isMedium_2;
   Char_t          lep_isLoose_2;
   Int_t           lep_isolationLooseTrackOnly_2;
   Int_t           lep_isolationLoose_2;
   Int_t           lep_isolationGradient_2;
   Int_t           lep_isolationGradientLoose_2;
   Int_t           lep_isolationFixedCutTight_2;
   Int_t           lep_isolationFixedCutTightTrackOnly_2;
   Int_t           lep_isolationFixedCutLoose_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_isTrigMatchDLT_2;
   Char_t          lep_isPrompt_2;
   Char_t          lep_isFakeLep_2;
   Char_t          lep_isQMisID_2;
   Char_t          lep_isConvPh_2;
   Char_t          lep_isIntConvPh_2;
   Char_t          lep_isExtConvPh_2;
   Char_t          lep_isISR_FSR_Ph_2;
   Char_t          lep_isBrems_2;
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Int_t           lep_truthStatus_2;
   Int_t           lep_truthParentType_2;
   Int_t           lep_truthParentOrigin_2;
   Int_t           lep_truthParentPdgId_2;
   Int_t           lep_truthParentStatus_2;
   Float_t         lep_truthPt_2;
   Float_t         lep_truthEta_2;
   Float_t         lep_truthPhi_2;
   Float_t         lep_truthM_2;
   Float_t         lep_truthE_2;
   Float_t         lep_truthRapidity_2;
   Float_t         lep_SFIDLoose_2;
   Float_t         lep_SFIDTight_2;
   Float_t         lep_SFTrigLoose_2;
   Float_t         lep_SFTrigTight_2;
   Float_t         lep_EffTrigLoose_2;
   Float_t         lep_EffTrigTight_2;
   Float_t         lep_SFIsoLoose_2;
   Float_t         lep_SFIsoTight_2;
   Float_t         lep_SFReco_2;
   Float_t         lep_SFTTVA_2;
   Float_t         lep_SFObjLoose_2;
   Float_t         lep_SFObjTight_2;
   Float_t         lep_chargeIDBDTLoose_2;
   Float_t         lep_chargeIDBDTMedium_2;
   Float_t         lep_chargeIDBDTTight_2;
   Float_t         lep_promptLeptonIso_TagWeight_2;
   Float_t         lep_promptLeptonVeto_TagWeight_2;
   Float_t         lep_ID_3;
   Int_t           lep_Index_3;
   UChar_t         lep_ambiguityType_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_Phi_3;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_topoEtcone20_3;
   Float_t         lep_topoEtcone30_3;
   Float_t         lep_topoEtcone40_3;
   Float_t         lep_ptVarcone20_3;
   Float_t         lep_ptVarcone30_3;
   Float_t         lep_ptVarcone40_3;
   Float_t         lep_sigd0PV_3;
   Float_t         lep_Z0SinTheta_3;
   Float_t         lep_d0_3;
   Float_t         lep_z0_3;
   Float_t         lep_vz_3;
   Float_t         lep_deltaz0_3;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isMediumLH_3;
   Char_t          lep_isLooseLH_3;
   Char_t          lep_isTight_3;
   Char_t          lep_isMedium_3;
   Char_t          lep_isLoose_3;
   Int_t           lep_isolationLooseTrackOnly_3;
   Int_t           lep_isolationLoose_3;
   Int_t           lep_isolationGradient_3;
   Int_t           lep_isolationGradientLoose_3;
   Int_t           lep_isolationFixedCutTight_3;
   Int_t           lep_isolationFixedCutTightTrackOnly_3;
   Int_t           lep_isolationFixedCutLoose_3;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_isTrigMatchDLT_3;
   Char_t          lep_isPrompt_3;
   Char_t          lep_isFakeLep_3;
   Char_t          lep_isQMisID_3;
   Char_t          lep_isConvPh_3;
   Char_t          lep_isIntConvPh_3;
   Char_t          lep_isExtConvPh_3;
   Char_t          lep_isISR_FSR_Ph_3;
   Char_t          lep_isBrems_3;
   Char_t          lep_isTruthMatched_3;
   Int_t           lep_truthType_3;
   Int_t           lep_truthOrigin_3;
   Int_t           lep_truthPdgId_3;
   Int_t           lep_truthStatus_3;
   Int_t           lep_truthParentType_3;
   Int_t           lep_truthParentOrigin_3;
   Int_t           lep_truthParentPdgId_3;
   Int_t           lep_truthParentStatus_3;
   Float_t         lep_truthPt_3;
   Float_t         lep_truthEta_3;
   Float_t         lep_truthPhi_3;
   Float_t         lep_truthM_3;
   Float_t         lep_truthE_3;
   Float_t         lep_truthRapidity_3;
   Float_t         lep_SFIDLoose_3;
   Float_t         lep_SFIDTight_3;
   Float_t         lep_SFTrigLoose_3;
   Float_t         lep_SFTrigTight_3;
   Float_t         lep_EffTrigLoose_3;
   Float_t         lep_EffTrigTight_3;
   Float_t         lep_SFIsoLoose_3;
   Float_t         lep_SFIsoTight_3;
   Float_t         lep_SFReco_3;
   Float_t         lep_SFTTVA_3;
   Float_t         lep_SFObjLoose_3;
   Float_t         lep_SFObjTight_3;
   Float_t         lep_chargeIDBDTLoose_3;
   Float_t         lep_chargeIDBDTMedium_3;
   Float_t         lep_chargeIDBDTTight_3;
   Float_t         lep_promptLeptonIso_TagWeight_3;
   Float_t         lep_promptLeptonVeto_TagWeight_3;
   vector<unsigned char> *electron_ambiguityType;
   vector<float>   *electron_PromptLeptonIso_TagWeight;
   vector<float>   *electron_PromptLeptonVeto_TagWeight;
   vector<float>   *muon_PromptLeptonIso_TagWeight;
   vector<float>   *muon_PromptLeptonVeto_TagWeight;
   Float_t         tau_MV2c10_0;
   Float_t         tau_MV2c10_1;
   Float_t         tau_pt_0;
   Float_t         tau_eta_0;
   Float_t         tau_phi_0;
   Float_t         tau_charge_0;
   Float_t         tau_E_0;
   Double_t        tau_BDTJetScore_0;
   Int_t           tau_JetBDTSigLoose_0;
   Int_t           tau_JetBDTSigMedium_0;
   Int_t           tau_JetBDTSigTight_0;
   Int_t           tau_isHadronic_0;
   Int_t           tau_numTrack_0;
   Float_t         tau_SFTight_0;
   Float_t         tau_SFLoose_0;
   Int_t           tau_tagWeightBin_0;
   Char_t          tau_fromPV_0;
   Int_t           tau_passEleOLR_0;
   Int_t           tau_passEleBDT_0;
   Int_t           tau_passMuonOLR_0;
   Int_t           tau_truthOrigin_0;
   Int_t           tau_truthType_0;
   Int_t           tau_truthJetFlavour_0;
   Float_t         tau_pt_1;
   Float_t         tau_eta_1;
   Float_t         tau_phi_1;
   Float_t         tau_charge_1;
   Float_t         tau_E_1;
   Double_t        tau_BDTJetScore_1;
   Int_t           tau_JetBDTSigLoose_1;
   Int_t           tau_JetBDTSigMedium_1;
   Int_t           tau_JetBDTSigTight_1;
   Int_t           tau_numTrack_1;
   Int_t           tau_isHadronic_1;
   Float_t         tau_SFTight_1;
   Float_t         tau_SFLoose_1;
   Int_t           tau_tagWeightBin_1;
   Char_t          tau_fromPV_1;
   Int_t           tau_passEleOLR_1;
   Int_t           tau_passEleBDT_1;
   Int_t           tau_passMuonOLR_1;
   Int_t           tau_truthOrigin_1;
   Int_t           tau_truthType_1;
   Int_t           tau_truthJetFlavour_1;
   Float_t         tau_promptTauVeto_0;
   Float_t         tau_promptTauVeto_1;
   Int_t           onelep_type;
   Int_t           dilep_type;
   Int_t           trilep_type;
   Int_t           quadlep_type;
   Int_t           total_charge;
   Int_t           total_leptons;
   Char_t          isQMisIDEvent;
   Char_t          isFakeEvent;
   Char_t          isLepFromPhEvent;
   Float_t         Mll01;
   Float_t         Ptll01;
   Float_t         DRll01;
   Float_t         Mlll012;
   Float_t         Mllll0123;
   Float_t         Mlll013;
   Float_t         Mll02;
   Float_t         Ptll02;
   Float_t         DRll02;
   Float_t         Mlll023;
   Float_t         Mll03;
   Float_t         Ptll03;
   Float_t         DRll03;
   Float_t         Mll12;
   Float_t         Ptll12;
   Float_t         DRll12;
   Float_t         Mlll123;
   Float_t         Mll13;
   Float_t         Ptll13;
   Float_t         DRll13;
   Float_t         Mll23;
   Float_t         Ptll23;
   Float_t         DRll23;
   Char_t          matchDLTll01;
   Char_t          matchDLTll02;
   Char_t          matchDLTll12;
   Char_t          matchDLTll03;
   Char_t          matchDLTll13;
   Char_t          matchDLTll23;
   Float_t         best_Z_Mll;
   Float_t         best_Z_other_Mll;
   Float_t         best_Z_other_MtLepMet;
   Int_t           nJets_OR_T;
   Int_t           nJets_OR;
   Int_t           nJets_OR_T_MV2c20_60;
   Int_t           nJets_OR_T_MV2c20_70;
   Int_t           nJets_OR_T_MV2c20_77;
   Int_t           nJets_OR_T_MV2c20_85;
   Int_t           nJets_OR_MV2c20_85;
   Int_t           nJets_OR_MV2c20_60;
   Int_t           nJets_OR_MV2c20_77;
   Int_t           nJets_OR_MV2c20_70;
   Int_t           nJets_OR_T_MV2c10_60;
   Int_t           nJets_OR_T_MV2c10_70;
   Int_t           nJets_OR_T_MV2c10_77;
   Int_t           nJets_OR_T_MV2c10_85;
   Int_t           nJets_OR_MV2c10_85;
   Int_t           nJets_OR_MV2c10_60;
   Int_t           nJets_OR_MV2c10_77;
   Int_t           nJets_OR_MV2c10_70;
   Int_t           nTaus_OR_Pt25;
   Bool_t          isBlinded;
   Float_t         HT;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Float_t         lead_jetPt;
   Float_t         lead_jetEta;
   Float_t         lead_jetPhi;
   Float_t         lead_jetE;
   Float_t         sublead_jetPt;
   Float_t         sublead_jetEta;
   Float_t         sublead_jetPhi;
   Float_t         sublead_jetE;
   Float_t         lepSFTrigLoose;
   Float_t         lepSFTrigTight;
   Float_t         lepSFTrigTightLoose;
   Float_t         lepSFTrigLooseTight;
   Float_t         lepEffTrigLoose;
   Float_t         lepEffTrigTight;
   Float_t         lepEffTrigTightLoose;
   Float_t         lepEffTrigLooseTight;
   Float_t         lepDataEffTrigLoose;
   Float_t         lepDataEffTrigTight;
   Float_t         lepDataEffTrigTightLoose;
   Float_t         lepDataEffTrigLooseTight;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         tauSFTight;
   Float_t         tauSFLoose;
   Float_t         tauFakeSF_weight;
   Float_t         tauFakeSF_weight_SYST_UP;
   Float_t         tauFakeSF_weight_SYST_DOWN;
   Float_t         tauFakeSF_weight_STAT_UP;
   Float_t         tauFakeSF_weight_STAT_DOWN;

   // List of branches
   TBranch        *b_is1L2Tau;   //!
   TBranch        *b_is2LSS0Tau;   //!
   TBranch        *b_pass_tight_2L;   //!
   TBranch        *b_pass_SS_2L;   //!
   TBranch        *b_is2LSS1Tau;   //!
   TBranch        *b_is2LOS1Tau;   //!
   TBranch        *b_is3L;   //!
   TBranch        *b_is3L1Tau;   //!
   TBranch        *b_is4L;   //!
   TBranch        *b_is2lLowNJet0Tau;   //!
   TBranch        *b_is2LSS0Tau_SR_Relaxed;   //!
   TBranch        *b_is2LSS1Tau_SR_Relaxed;   //!
   TBranch        *b_is3L0Tau_SR_Relaxed;   //!
   TBranch        *b_is3L0Tau_SR_Relaxed3j;   //!
   TBranch        *b_is4L_SR_VV_Relaxed;   //!
   TBranch        *b_is4L_SR_ttV_Relaxed;   //!
   TBranch        *b_is4L_SR_ttV_Zenriched;   //!
   TBranch        *b_is3L0Tau_CR_ttbar_Relaxed;   //!
   TBranch        *b_is3L0Tau_CR_VV_Relaxed;   //!
   TBranch        *b_is3L0Tau_CR_ttW_Relaxed;   //!
   TBranch        *b_is2L_VR_ttW_ICHEP;   //!
   TBranch        *b_is2L_VR_ttbarFakes_ICHEP;   //!
   TBranch        *b_is4lCRttZRelaxed;   //!
   TBranch        *b_is2LOS1Tau_CR_ttbar;   //!
   TBranch        *b_is2LOS1Tau_CR_ttZ;   //!
   TBranch        *b_is2LOS1Tau_CR_W;   //!
   TBranch        *b_is3L1Tau_VR;   //!
   TBranch        *b_is2lOS0TauBaseline;   //!
   TBranch        *b_is2lOS0TauBaseline_ee;   //!
   TBranch        *b_is2lOS0TauBaseline_mm;   //!
   TBranch        *b_is2lOS0TauBaseline_OF;   //!
   TBranch        *b_is2lOS0TauBaseline_me;   //!
   TBranch        *b_is2lOS0TauBaseline_em;   //!
   TBranch        *b_is2lSS0TauBaseline;   //!
   TBranch        *b_is2lSS0TauBaseline_ee;   //!
   TBranch        *b_is2lSS0TauBaseline_mm;   //!
   TBranch        *b_is2lSS0TauBaseline_OF;   //!
   TBranch        *b_is2lSS0TauBaseline_me;   //!
   TBranch        *b_is2lSS0TauBaseline_em;   //!
   TBranch        *b_is2lOS1TauBaseline;   //!
   TBranch        *b_is2lOS1TauBaseline_ee;   //!
   TBranch        *b_is2lOS1TauBaseline_mm;   //!
   TBranch        *b_is2lOS1TauBaseline_OF;   //!
   TBranch        *b_is2lOS1TauBaseline_me;   //!
   TBranch        *b_is2lOS1TauBaseline_em;   //!
   TBranch        *b_is2lSS1TauBaseline;   //!
   TBranch        *b_is2lSS1TauBaseline_ee;   //!
   TBranch        *b_is2lSS1TauBaseline_mm;   //!
   TBranch        *b_is2lSS1TauBaseline_OF;   //!
   TBranch        *b_is2lSS1TauBaseline_me;   //!
   TBranch        *b_is2lSS1TauBaseline_em;   //!
   TBranch        *b_is3lBaseline;   //!
   TBranch        *b_is3lBaselineNoZVeto;   //!
   TBranch        *b_is2lss1tau_regionB;   //!
   TBranch        *b_is2lss1tau_regionC;   //!
   TBranch        *b_is2lss1tau_regionD;   //!
   TBranch        *b_isGNv02;   //!
   TBranch        *b_minOSMll;   //!
   TBranch        *b_minOSSFMll;   //!
   TBranch        *b_jet_flvWtOrdr_0_pt;   //!
   TBranch        *b_jet_flvWtOrdr_0_eta;   //!
   TBranch        *b_jet_flvWtOrdr_0_phi;   //!
   TBranch        *b_jet_flvWtOrdr_0_E;   //!
   TBranch        *b_jet_flvWtOrdr_0_mv2c10;   //!
   TBranch        *b_jet_flvWtOrdr_1_pt;   //!
   TBranch        *b_jet_flvWtOrdr_1_eta;   //!
   TBranch        *b_jet_flvWtOrdr_1_phi;   //!
   TBranch        *b_jet_flvWtOrdr_1_E;   //!
   TBranch        *b_jet_flvWtOrdr_1_mv2c10;   //!
   TBranch        *b_jet_flvWtOrdr_2_pt;   //!
   TBranch        *b_jet_flvWtOrdr_2_eta;   //!
   TBranch        *b_jet_flvWtOrdr_2_phi;   //!
   TBranch        *b_jet_flvWtOrdr_2_E;   //!
   TBranch        *b_jet_flvWtOrdr_2_mv2c10;   //!
   TBranch        *b_DEtall01;   //!
   TBranch        *b_DEtall02;   //!
   TBranch        *b_DEtall12;   //!
   TBranch        *b_lep_flavour;   //!
   TBranch        *b_jet_flavor;   //!
   TBranch        *b_total_charge_2lSS;   //!
   TBranch        *b_isExtConv;   //!
   TBranch        *b_isIntConv;   //!
   TBranch        *b_max_eta;   //!
   TBranch        *b_SDRll;   //!
   TBranch        *b_DeltaR_max_lep;   //!
   TBranch        *b_DPhi_max_lep_met;   //!
   TBranch        *b_DeltaR_min_lep_jet;   //!
   TBranch        *b_minDeltaR_LJ_0;   //!
   TBranch        *b_minDeltaR_LJ_1;   //!
   TBranch        *b_minDeltaR_LJ_2;   //!
   TBranch        *b_Meff;   //!
   TBranch        *b_Mjj_closeW;   //!
   TBranch        *b_DRlb_h;   //!
   TBranch        *b_ptlb_h;   //!
   TBranch        *b_DeltaRLeadjets;   //!
   TBranch        *b_jet1pTbin;   //!
   TBranch        *b_jet2pTbin;   //!
   TBranch        *b_jet3pTbin;   //!
   TBranch        *b_jet3etabin;   //!
   TBranch        *b_jet1MV2c10_bin;   //!
   TBranch        *b_jet2MV2c10_bin;   //!
   TBranch        *b_MvisH;   //!
   TBranch        *b_MvisnonH;   //!
   TBranch        *b_lep_PtVarCone20Rel_1;   //!
   TBranch        *b_DeltaRLeadLepClosestJet;   //!
   TBranch        *b_Ml2l3met;   //!
   TBranch        *b_FSF_4L_tot;   //!
   TBranch        *b_FSF_4L_tot_up;   //!
   TBranch        *b_FSF_4L_tot_down;   //!
   TBranch        *b_FSF_category;   //!
   TBranch        *b_FSF_4L_e_L;   //!
   TBranch        *b_FSF_4L_e_H;   //!
   TBranch        *b_FSF_4L_m;   //!
   TBranch        *b_jet2_pt;   //!
   TBranch        *b_jet2_eta;   //!
   TBranch        *b_jet2_phi;   //!
   TBranch        *b_jet3_pt;   //!
   TBranch        *b_jet3_eta;   //!
   TBranch        *b_jet3_phi;   //!
   TBranch        *b_jet0_tagWeightBin;   //!
   TBranch        *b_jet1_tagWeightBin;   //!
   TBranch        *b_jet2_tagWeightBin;   //!
   TBranch        *b_jet3_tagWeightBin;   //!
   TBranch        *b_N_el;   //!
   TBranch        *b_N_mu;   //!
   TBranch        *b_tempDPl0t;   //!
   TBranch        *b_tempDPl1t;   //!
   TBranch        *b_tempDP2l;   //!
   TBranch        *b_tempDPlt_closest;   //!
   TBranch        *b_tempDPlt_furthest;   //!
   TBranch        *b_DeltaRSubLepClosestJet;   //!
   TBranch        *b_SignProduct2sslt;   //!
   TBranch        *b_TransverseMassLeadLepMET;   //!
   TBranch        *b_LD_HTmiss_ETmiss;   //!
   TBranch        *b_Mjj_nonb;   //!
   TBranch        *b_Mtop;   //!
   TBranch        *b_MtopW;   //!
   TBranch        *b_temptopoetcone20overpTlep0;   //!
   TBranch        *b_temptopoetcone20overpTlep1;   //!
   TBranch        *b_tempptvarcone20overpTlep0;   //!
   TBranch        *b_tempptvarcone20overpTlep1;   //!
   TBranch        *b_lep_isAntiTight_0;   //!
   TBranch        *b_lep_isAntiTight_1;   //!
   TBranch        *b_tau_tight_0;   //!
   TBranch        *b_tau_tight_1;   //!
   TBranch        *b_tau_btag70_0;   //!
   TBranch        *b_tau_btag70_1;   //!
   TBranch        *b_tau_truth_0;   //!
   TBranch        *b_tau_truth_1;   //!
   TBranch        *b_htjets_1l2tau;   //!
   TBranch        *b_jjdrmin_1l2tau;   //!
   TBranch        *b_mtautau_1l2tau;   //!
   TBranch        *b_njets_1l2tau;   //!
   TBranch        *b_nbjets_1l2tau;   //!
   TBranch        *b_DRlj00;   //!
   TBranch        *b_DRjj01;   //!
   TBranch        *b_min_DRl0j;   //!
   TBranch        *b_min_DRl1j;   //!
   TBranch        *b_min_DRl2j;   //!
   TBranch        *b_min_DRl0b;   //!
   TBranch        *b_min_DRl1b;   //!
   TBranch        *b_min_DRl2b;   //!
   TBranch        *b_min_DRlj_new;   //!
   TBranch        *b_nJets_OR_T_overflow;   //!
   TBranch        *b_nJets_OR_T_MV2c10_70_overflow;   //!
   TBranch        *b_DPhij0MET;   //!
   TBranch        *b_lead_BjetPt;   //!
   TBranch        *b_lead_jet_sumBEff;   //!
   TBranch        *b_sublead_jet_sumBEff;   //!
   TBranch        *b_lead_jet_pass_FixedCutBEff_70;   //!
   TBranch        *b_sublead_jet_pass_FixedCutBEff_70;   //!
   TBranch        *b_lead_jet_is_lead_antitag;   //!
   TBranch        *b_lead_jet_is_lead_tag;   //!
   TBranch        *b_lep_Pt_1_new;   //!
   TBranch        *b_lep_Pt_2_new;   //!
   TBranch        *b_lep_ID_1_new;   //!
   TBranch        *b_lep_ID_2_new;   //!
   TBranch        *b_lep_isPrompt_1_new;   //!
   TBranch        *b_lep_isPrompt_2_new;   //!
   TBranch        *b_lep_truthOrigin_1_new;   //!
   TBranch        *b_lep_truthOrigin_2_new;   //!
   TBranch        *b_lep_truthParentPdgId_1_new;   //!
   TBranch        *b_lep_truthParentPdgId_2_new;   //!
   TBranch        *b_lep_truthParentType_1_new;   //!
   TBranch        *b_lep_truthParentPdgId_2_new;   //!
   TBranch        *b_lep_isQMisID_1_new;   //!
   TBranch        *b_lep_isQMisID_2_new;   //!
   TBranch        *b_lep_Eta_1_new;   //!
   TBranch        *b_lep_Eta_2_new;   //!
   TBranch        *b_lep_Phi_1_new;   //!
   TBranch        *b_lep_Phi_2_new;   //!
   TBranch        *b_lep_isolationFixedCutLoose_1_new;   //!
   TBranch        *b_lep_isolationFixedCutLoose_2_new;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_1_new;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_2_new;   //!
   TBranch        *b_lep_isTightLH_1_new;   //!
   TBranch        *b_lep_isTightLH_2_new;   //!
   TBranch        *b_lep_chargeIDBDTTight_1_new;   //!
   TBranch        *b_lep_chargeIDBDTTight_2_new;   //!
   TBranch        *b_lep_ambiguityType_1_new;   //!
   TBranch        *b_lep_ambiguityType_2_new;   //!
   TBranch        *b_lep_isMedium_1_new;   //!
   TBranch        *b_lep_isMedium_2_new;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_lep_isTightSelected_0;   //!
   TBranch        *b_lep_isTightSelected_1;   //!
   TBranch        *b_lep_isTightSelected_2;   //!
   TBranch        *b_lep_isTightSelected_3;   //!
   TBranch        *b_lep_isTightSelected_2LOS1Tau_0;   //!
   TBranch        *b_lep_isTightSelected_2LOS1Tau_1;   //!
   TBranch        *b_lep_isTightSelectedAndPt_0;   //!
   TBranch        *b_lep_isTightSelectedAndPt_1;   //!
   TBranch        *b_lep_isTightSelectedAndPt_2;   //!
   TBranch        *b_lep_isTightSelectedAndPt_3;   //!
   TBranch        *b_lep_isTightSelectedAndPt_2LOS1Tau_0;   //!
   TBranch        *b_lep_isTightSelectedAndPt_2LOS1Tau_1;   //!
   TBranch        *b_jet_flavor_truth_label_ghost;   //!
   TBranch        *b_jet_pT;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_MVA2lSSMarseille_weight_ttV;   //!
   TBranch        *b_MVA2lSSMarseille_weight_ttbar;   //!
   TBranch        *b_MVA2lSSMarseille_weight_ttV_2;   //!
   TBranch        *b_MVA2lSSMarseille_weight_ttbar_2;   //!
   TBranch        *b_MVA2lSS1tau_weight_random_ttbar;   //!
   TBranch        *b_MVA2lSS1tau_weight_CT_ttbar;   //!
   TBranch        *b_MVA2lSS1tau_weight_random_nottbar;   //!
   TBranch        *b_MVA2lSS1tau_weight_CT_nottbar;   //!
   TBranch        *b_MVA2lOS1tau_weight;   //!
   TBranch        *b_SumPtBJet;   //!
   TBranch        *b_SumPtJet;   //!
   TBranch        *b_SumPtLep;   //!
   TBranch        *b_DRlj;   //!
   TBranch        *b_DRlb;   //!
   TBranch        *b_DRjb;   //!
   TBranch        *b_DRl0tau;   //!
   TBranch        *b_DRl1tau;   //!
   TBranch        *b_MVA3lCERN_weight_ttH;   //!
   TBranch        *b_MVA3lCERN_weight_ttW;   //!
   TBranch        *b_MVA3lCERN_weight_ttZ;   //!
   TBranch        *b_MVA3lCERN_weight_VV;   //!
   TBranch        *b_MVA3lCERN_weight_ttbar;   //!
   TBranch        *b_MVA3lCERN_category;   //!
   TBranch        *b_MVA3lZZCERN_weight_ttH;   //!
   TBranch        *b_MVA3lZZCERN_weight_ttZ;   //!
   TBranch        *b_MVA3lZZCERN_weight_VV;   //!
   TBranch        *b_MVA3lZZCERN_category;   //!
   TBranch        *b_MVA4lBonn_weight_ttZ;   //!
   TBranch        *b_fourLep_PME;   //!
   TBranch        *b_MVA1l2tau_weight;   //!
   TBranch        *b_D_PME;   //!
   TBranch        *b_BDT_out;   //!
   TBranch        *b_mlb_h;   //!
   TBranch        *b_mOSl_h;   //!
   TBranch        *b_averageMW;   //!
   TBranch        *b_lepton_PromptLeptonIso_TagWeight;   //!
   TBranch        *b_lepton_ChargeIDBDTTight;   //!
   TBranch        *b_CRB1_2lSStau_FF_Fake;   //!
   TBranch        *b_CRB1_2lSStau_FF_Prompt;   //!
   TBranch        *b_CRB2_2lSStau_FF_Fake;   //!
   TBranch        *b_CRB2_2lSStau_FF_RealTau;   //!
   TBranch        *b_CRB3_2lSStau_FF_Fake;   //!
   TBranch        *b_CRB3_2lSStau_FF_RealTau;   //!
   TBranch        *b_CRB3_2lSStau_FF_Prompt;   //!
   TBranch        *b_CRB1_2lSStau_FF_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin1Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin1Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin2Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin2Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin3Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin3Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin4Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin4Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin5Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_elStat_Bin5Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin1Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin1Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin2Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin2Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin3Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin3Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin4Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin4Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin5Up_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_muStat_Bin5Dn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_ttwUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_ttwDn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_ttzUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_ttzDn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_vvUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_vvDn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_rareUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_rareDn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_tthUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_tthDn_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_QMisIdUp_EventWeight;   //!
   TBranch        *b_CRB1_2lSStau_FF_QMisIdDn_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_RealtauUp_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_RealtauDn_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_tthUp_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_tthDn_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_QMisIdUp_EventWeight;   //!
   TBranch        *b_CRB2_2lSStau_FF_QMisIdDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_RealtauUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_RealtauDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_ttwUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_ttwDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_ttzUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_ttzDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_vvUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_vvDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_rareUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_rareDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_tthUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_tthDn_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_QMisIdUp_EventWeight;   //!
   TBranch        *b_CRB3_2lSStau_FF_QMisIdDn_EventWeight;   //!
   TBranch        *b_isttH;   //!
   TBranch        *b_isttZ;   //!
   TBranch        *b_isttW;   //!
   TBranch        *b_isVV;   //!
   TBranch        *b_istZ;   //!
   TBranch        *b_isWtZ;   //!
   TBranch        *b_istHjb;   //!
   TBranch        *b_isWtH;   //!
   TBranch        *b_isttWW;   //!
   TBranch        *b_isVH;   //!
   TBranch        *b_isVVV;   //!
   TBranch        *b_is3Tops;   //!
   TBranch        *b_is4Tops;   //!
   TBranch        *b_isttbar;   //!
   TBranch        *b_isttll;   //!
   TBranch        *b_israreTop;   //!
   TBranch        *b_isttGamma;   //!
   TBranch        *b_isttbarDilep;   //!
   TBranch        *b_passTrigger;   //!
   TBranch        *b_scale_nom;   //!
   TBranch        *b_scale_varA14up;   //!
   TBranch        *b_scale_varA14down;   //!
   TBranch        *b_scale_varRup;   //!
   TBranch        *b_scale_varRdown;   //!
   TBranch        *b_scale_varFup;   //!
   TBranch        *b_scale_varFdown;   //!
   TBranch        *b_scale_varRFup;   //!
   TBranch        *b_scale_varRFdown;   //!
   TBranch        *b_pileupEventWeight_UP;   //!
   TBranch        *b_pileupEventWeight_DOWN;   //!
   TBranch        *b_JVT_EventWeight_UP;   //!
   TBranch        *b_JVT_EventWeight_DOWN;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_HIGHPT_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_HIGHPT_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_HIGHPT_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_HIGHPT_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_forFit_promptSel;   //!
   TBranch        *b_forFit_tightSel;   //!
   TBranch        *b_forFit_3l0tauBaseLine;   //!
   TBranch        *b_forFit_3l0tauFakesSel;   //!
   TBranch        *b_forFit_2lss0tauBaseLine;   //!
   TBranch        *b_forFit_2lssFakeQmisSel;   //!
   TBranch        *b_mcWeightOrg;   //!
   TBranch        *b_pileupEventWeight_090;   //!
   TBranch        *b_MV2c10_60_EventWeight;   //!
   TBranch        *b_MV2c10_70_EventWeight;   //!
   TBranch        *b_MV2c10_77_EventWeight;   //!
   TBranch        *b_MV2c10_85_EventWeight;   //!
   TBranch        *b_MV2c10_Continuous_EventWeight;   //!
   TBranch        *b_bTagSF_weight_Continuous;   //!
   TBranch        *b_JVT_EventWeight;   //!
   TBranch        *b_SherpaNJetWeight;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_passEventCleaning;   //!
   TBranch        *b_m_vxp_x;   //!
   TBranch        *b_m_vxp_y;   //!
   TBranch        *b_m_vxp_z;   //!
   TBranch        *b_higgs_pt;   //!
   TBranch        *b_higgs_eta;   //!
   TBranch        *b_higgs_phi;   //!
   TBranch        *b_higgs_E;   //!
   TBranch        *b_higgs_rapidity;   //!
   TBranch        *b_top_pt;   //!
   TBranch        *b_top_eta;   //!
   TBranch        *b_top_phi;   //!
   TBranch        *b_top_E;   //!
   TBranch        *b_antitop_pt;   //!
   TBranch        *b_antitop_eta;   //!
   TBranch        *b_antitop_phi;   //!
   TBranch        *b_antitop_E;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_HF_Classification;   //!
   TBranch        *b_HF_ClassificationTop;   //!
   TBranch        *b_DLF_Classification;   //!
   TBranch        *b_higgsDecayMode;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_mc_isAFII;   //!
   TBranch        *b_averageIntPerXing_uncorr;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_actualIntPerXing;   //!
   TBranch        *b_m_vxp_n;   //!
   TBranch        *b_m_vxpu_n;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_MET_RefFinal_sumet;   //!
   TBranch        *b_m_hasMEphoton;   //!
   TBranch        *b_m_hasMEphoton_DRgt02_nonhad;   //!
   TBranch        *b_m_MEphoton_OLtty_keepEvent;   //!
   TBranch        *b_m_MEphoton_OLtty_cat1;   //!
   TBranch        *b_m_MEphoton_OLtty_cat2;   //!
   TBranch        *b_m_MEphoton_OLtty_cat3;   //!
   TBranch        *b_m_MEphoton_OLtty_cat4;   //!
   TBranch        *b_m_MEphoton_pt;   //!
   TBranch        *b_m_MEphoton_eta;   //!
   TBranch        *b_m_MEphoton_phi;   //!
   TBranch        *b_m_MEphoton_mother_pt;   //!
   TBranch        *b_m_MEphoton_mother_eta;   //!
   TBranch        *b_m_MEphoton_mother_phi;   //!
   TBranch        *b_m_MEphoton_mother_pdgId;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_2e12_lhvloose_nod0_L12EM10VH;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e140_lhloose;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e24_lhmedium_nod0_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhtight_iloose;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_e60_medium;   //!
   TBranch        *b_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_HLT_e7_medium_mu24;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu20_mu8noL1;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_mu24_imedium;   //!
   TBranch        *b_HLT_mu24_ivarloose;   //!
   TBranch        *b_HLT_mu24_ivarmedium;   //!
   TBranch        *b_HLT_mu26_imedium;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0_L12EM15VHI;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_0;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_1;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_2;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_0;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_1;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_2;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_0;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_1;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_2;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_0;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_1;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_2;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_0;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_1;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_2;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_0;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_1;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_2;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_0;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_1;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_2;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_0;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_1;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_2;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_0;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_1;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_2;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_0;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_1;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_2;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Index_0;   //!
   TBranch        *b_lep_ambiguityType_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_topoEtcone20_0;   //!
   TBranch        *b_lep_topoEtcone30_0;   //!
   TBranch        *b_lep_topoEtcone40_0;   //!
   TBranch        *b_lep_ptVarcone20_0;   //!
   TBranch        *b_lep_ptVarcone30_0;   //!
   TBranch        *b_lep_ptVarcone40_0;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_d0_0;   //!
   TBranch        *b_lep_z0_0;   //!
   TBranch        *b_lep_vz_0;   //!
   TBranch        *b_lep_deltaz0_0;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isMediumLH_0;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isTight_0;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isLoose_0;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_0;   //!
   TBranch        *b_lep_isolationLoose_0;   //!
   TBranch        *b_lep_isolationGradient_0;   //!
   TBranch        *b_lep_isolationGradientLoose_0;   //!
   TBranch        *b_lep_isolationFixedCutTight_0;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_0;   //!
   TBranch        *b_lep_isolationFixedCutLoose_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_isTrigMatchDLT_0;   //!
   TBranch        *b_lep_isPrompt_0;   //!
   TBranch        *b_lep_isFakeLep_0;   //!
   TBranch        *b_lep_isQMisID_0;   //!
   TBranch        *b_lep_isConvPh_0;   //!
   TBranch        *b_lep_isIntConvPh_0;   //!
   TBranch        *b_lep_isExtConvPh_0;   //!
   TBranch        *b_lep_isISR_FSR_Ph_0;   //!
   TBranch        *b_lep_isBrems_0;   //!
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_truthStatus_0;   //!
   TBranch        *b_lep_truthParentType_0;   //!
   TBranch        *b_lep_truthParentOrigin_0;   //!
   TBranch        *b_lep_truthParentPdgId_0;   //!
   TBranch        *b_lep_truthParentStatus_0;   //!
   TBranch        *b_lep_truthPt_0;   //!
   TBranch        *b_lep_truthEta_0;   //!
   TBranch        *b_lep_truthPhi_0;   //!
   TBranch        *b_lep_truthM_0;   //!
   TBranch        *b_lep_truthE_0;   //!
   TBranch        *b_lep_truthRapidity_0;   //!
   TBranch        *b_lep_SFIDLoose_0;   //!
   TBranch        *b_lep_SFIDTight_0;   //!
   TBranch        *b_lep_SFTrigLoose_0;   //!
   TBranch        *b_lep_SFTrigTight_0;   //!
   TBranch        *b_lep_EffTrigLoose_0;   //!
   TBranch        *b_lep_EffTrigTight_0;   //!
   TBranch        *b_lep_SFIsoLoose_0;   //!
   TBranch        *b_lep_SFIsoTight_0;   //!
   TBranch        *b_lep_SFReco_0;   //!
   TBranch        *b_lep_SFTTVA_0;   //!
   TBranch        *b_lep_SFObjLoose_0;   //!
   TBranch        *b_lep_SFObjTight_0;   //!
   TBranch        *b_lep_chargeIDBDTLoose_0;   //!
   TBranch        *b_lep_chargeIDBDTMedium_0;   //!
   TBranch        *b_lep_chargeIDBDTTight_0;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Index_1;   //!
   TBranch        *b_lep_ambiguityType_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_topoEtcone20_1;   //!
   TBranch        *b_lep_topoEtcone30_1;   //!
   TBranch        *b_lep_topoEtcone40_1;   //!
   TBranch        *b_lep_ptVarcone20_1;   //!
   TBranch        *b_lep_ptVarcone30_1;   //!
   TBranch        *b_lep_ptVarcone40_1;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_d0_1;   //!
   TBranch        *b_lep_z0_1;   //!
   TBranch        *b_lep_vz_1;   //!
   TBranch        *b_lep_deltaz0_1;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isMediumLH_1;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isTight_1;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isLoose_1;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_1;   //!
   TBranch        *b_lep_isolationLoose_1;   //!
   TBranch        *b_lep_isolationGradient_1;   //!
   TBranch        *b_lep_isolationGradientLoose_1;   //!
   TBranch        *b_lep_isolationFixedCutTight_1;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_1;   //!
   TBranch        *b_lep_isolationFixedCutLoose_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_isTrigMatchDLT_1;   //!
   TBranch        *b_lep_isPrompt_1;   //!
   TBranch        *b_lep_isFakeLep_1;   //!
   TBranch        *b_lep_isQMisID_1;   //!
   TBranch        *b_lep_isConvPh_1;   //!
   TBranch        *b_lep_isIntConvPh_1;   //!
   TBranch        *b_lep_isExtConvPh_1;   //!
   TBranch        *b_lep_isISR_FSR_Ph_1;   //!
   TBranch        *b_lep_isBrems_1;   //!
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_truthStatus_1;   //!
   TBranch        *b_lep_truthParentType_1;   //!
   TBranch        *b_lep_truthParentOrigin_1;   //!
   TBranch        *b_lep_truthParentPdgId_1;   //!
   TBranch        *b_lep_truthParentStatus_1;   //!
   TBranch        *b_lep_truthPt_1;   //!
   TBranch        *b_lep_truthEta_1;   //!
   TBranch        *b_lep_truthPhi_1;   //!
   TBranch        *b_lep_truthM_1;   //!
   TBranch        *b_lep_truthE_1;   //!
   TBranch        *b_lep_truthRapidity_1;   //!
   TBranch        *b_lep_SFIDLoose_1;   //!
   TBranch        *b_lep_SFIDTight_1;   //!
   TBranch        *b_lep_SFTrigLoose_1;   //!
   TBranch        *b_lep_SFTrigTight_1;   //!
   TBranch        *b_lep_EffTrigLoose_1;   //!
   TBranch        *b_lep_EffTrigTight_1;   //!
   TBranch        *b_lep_SFIsoLoose_1;   //!
   TBranch        *b_lep_SFIsoTight_1;   //!
   TBranch        *b_lep_SFReco_1;   //!
   TBranch        *b_lep_SFTTVA_1;   //!
   TBranch        *b_lep_SFObjLoose_1;   //!
   TBranch        *b_lep_SFObjTight_1;   //!
   TBranch        *b_lep_chargeIDBDTLoose_1;   //!
   TBranch        *b_lep_chargeIDBDTMedium_1;   //!
   TBranch        *b_lep_chargeIDBDTTight_1;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Index_2;   //!
   TBranch        *b_lep_ambiguityType_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_topoEtcone20_2;   //!
   TBranch        *b_lep_topoEtcone30_2;   //!
   TBranch        *b_lep_topoEtcone40_2;   //!
   TBranch        *b_lep_ptVarcone20_2;   //!
   TBranch        *b_lep_ptVarcone30_2;   //!
   TBranch        *b_lep_ptVarcone40_2;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_d0_2;   //!
   TBranch        *b_lep_z0_2;   //!
   TBranch        *b_lep_vz_2;   //!
   TBranch        *b_lep_deltaz0_2;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isMediumLH_2;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isTight_2;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isLoose_2;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_2;   //!
   TBranch        *b_lep_isolationLoose_2;   //!
   TBranch        *b_lep_isolationGradient_2;   //!
   TBranch        *b_lep_isolationGradientLoose_2;   //!
   TBranch        *b_lep_isolationFixedCutTight_2;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_2;   //!
   TBranch        *b_lep_isolationFixedCutLoose_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_isTrigMatchDLT_2;   //!
   TBranch        *b_lep_isPrompt_2;   //!
   TBranch        *b_lep_isFakeLep_2;   //!
   TBranch        *b_lep_isQMisID_2;   //!
   TBranch        *b_lep_isConvPh_2;   //!
   TBranch        *b_lep_isIntConvPh_2;   //!
   TBranch        *b_lep_isExtConvPh_2;   //!
   TBranch        *b_lep_isISR_FSR_Ph_2;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_truthStatus_2;   //!
   TBranch        *b_lep_truthParentType_2;   //!
   TBranch        *b_lep_truthParentOrigin_2;   //!
   TBranch        *b_lep_truthParentPdgId_2;   //!
   TBranch        *b_lep_truthParentStatus_2;   //!
   TBranch        *b_lep_truthPt_2;   //!
   TBranch        *b_lep_truthEta_2;   //!
   TBranch        *b_lep_truthPhi_2;   //!
   TBranch        *b_lep_truthM_2;   //!
   TBranch        *b_lep_truthE_2;   //!
   TBranch        *b_lep_truthRapidity_2;   //!
   TBranch        *b_lep_SFIDLoose_2;   //!
   TBranch        *b_lep_SFIDTight_2;   //!
   TBranch        *b_lep_SFTrigLoose_2;   //!
   TBranch        *b_lep_SFTrigTight_2;   //!
   TBranch        *b_lep_EffTrigLoose_2;   //!
   TBranch        *b_lep_EffTrigTight_2;   //!
   TBranch        *b_lep_SFIsoLoose_2;   //!
   TBranch        *b_lep_SFIsoTight_2;   //!
   TBranch        *b_lep_SFReco_2;   //!
   TBranch        *b_lep_SFTTVA_2;   //!
   TBranch        *b_lep_SFObjLoose_2;   //!
   TBranch        *b_lep_SFObjTight_2;   //!
   TBranch        *b_lep_chargeIDBDTLoose_2;   //!
   TBranch        *b_lep_chargeIDBDTMedium_2;   //!
   TBranch        *b_lep_chargeIDBDTTight_2;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Index_3;   //!
   TBranch        *b_lep_ambiguityType_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_topoEtcone20_3;   //!
   TBranch        *b_lep_topoEtcone30_3;   //!
   TBranch        *b_lep_topoEtcone40_3;   //!
   TBranch        *b_lep_ptVarcone20_3;   //!
   TBranch        *b_lep_ptVarcone30_3;   //!
   TBranch        *b_lep_ptVarcone40_3;   //!
   TBranch        *b_lep_sigd0PV_3;   //!
   TBranch        *b_lep_Z0SinTheta_3;   //!
   TBranch        *b_lep_d0_3;   //!
   TBranch        *b_lep_z0_3;   //!
   TBranch        *b_lep_vz_3;   //!
   TBranch        *b_lep_deltaz0_3;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isMediumLH_3;   //!
   TBranch        *b_lep_isLooseLH_3;   //!
   TBranch        *b_lep_isTight_3;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isLoose_3;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_3;   //!
   TBranch        *b_lep_isolationLoose_3;   //!
   TBranch        *b_lep_isolationGradient_3;   //!
   TBranch        *b_lep_isolationGradientLoose_3;   //!
   TBranch        *b_lep_isolationFixedCutTight_3;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_3;   //!
   TBranch        *b_lep_isolationFixedCutLoose_3;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_isTrigMatchDLT_3;   //!
   TBranch        *b_lep_isPrompt_3;   //!
   TBranch        *b_lep_isFakeLep_3;   //!
   TBranch        *b_lep_isQMisID_3;   //!
   TBranch        *b_lep_isConvPh_3;   //!
   TBranch        *b_lep_isIntConvPh_3;   //!
   TBranch        *b_lep_isExtConvPh_3;   //!
   TBranch        *b_lep_isISR_FSR_Ph_3;   //!
   TBranch        *b_lep_isBrems_3;   //!
   TBranch        *b_lep_isTruthMatched_3;   //!
   TBranch        *b_lep_truthType_3;   //!
   TBranch        *b_lep_truthOrigin_3;   //!
   TBranch        *b_lep_truthPdgId_3;   //!
   TBranch        *b_lep_truthStatus_3;   //!
   TBranch        *b_lep_truthParentType_3;   //!
   TBranch        *b_lep_truthParentOrigin_3;   //!
   TBranch        *b_lep_truthParentPdgId_3;   //!
   TBranch        *b_lep_truthParentStatus_3;   //!
   TBranch        *b_lep_truthPt_3;   //!
   TBranch        *b_lep_truthEta_3;   //!
   TBranch        *b_lep_truthPhi_3;   //!
   TBranch        *b_lep_truthM_3;   //!
   TBranch        *b_lep_truthE_3;   //!
   TBranch        *b_lep_truthRapidity_3;   //!
   TBranch        *b_lep_SFIDLoose_3;   //!
   TBranch        *b_lep_SFIDTight_3;   //!
   TBranch        *b_lep_SFTrigLoose_3;   //!
   TBranch        *b_lep_SFTrigTight_3;   //!
   TBranch        *b_lep_EffTrigLoose_3;   //!
   TBranch        *b_lep_EffTrigTight_3;   //!
   TBranch        *b_lep_SFIsoLoose_3;   //!
   TBranch        *b_lep_SFIsoTight_3;   //!
   TBranch        *b_lep_SFReco_3;   //!
   TBranch        *b_lep_SFTTVA_3;   //!
   TBranch        *b_lep_SFObjLoose_3;   //!
   TBranch        *b_lep_SFObjTight_3;   //!
   TBranch        *b_lep_chargeIDBDTLoose_3;   //!
   TBranch        *b_lep_chargeIDBDTMedium_3;   //!
   TBranch        *b_lep_chargeIDBDTTight_3;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_3;   //!
   TBranch        *b_electron_ambiguityType;   //!
   TBranch        *b_electron_PromptLeptonIso_TagWeight;   //!
   TBranch        *b_electron_PromptLeptonVeto_TagWeight;   //!
   TBranch        *b_muon_PromptLeptonIso_TagWeight;   //!
   TBranch        *b_muon_PromptLeptonVeto_TagWeight;   //!
   TBranch        *b_tau_MV2c10_0;   //!
   TBranch        *b_tau_MV2c10_1;   //!
   TBranch        *b_tau_pt_0;   //!
   TBranch        *b_tau_eta_0;   //!
   TBranch        *b_tau_phi_0;   //!
   TBranch        *b_tau_charge_0;   //!
   TBranch        *b_tau_E_0;   //!
   TBranch        *b_tau_BDTJetScore_0;   //!
   TBranch        *b_tau_JetBDTSigLoose_0;   //!
   TBranch        *b_tau_JetBDTSigMedium_0;   //!
   TBranch        *b_tau_JetBDTSigTight_0;   //!
   TBranch        *b_tau_isHadronic_0;   //!
   TBranch        *b_tau_numTrack_0;   //!
   TBranch        *b_tau_SFTight_0;   //!
   TBranch        *b_tau_SFLoose_0;   //!
   TBranch        *b_tau_tagWeightBin_0;   //!
   TBranch        *b_tau_fromPV_0;   //!
   TBranch        *b_tau_passEleOLR_0;   //!
   TBranch        *b_tau_passEleBDT_0;   //!
   TBranch        *b_tau_passMuonOLR_0;   //!
   TBranch        *b_tau_truthOrigin_0;   //!
   TBranch        *b_tau_truthType_0;   //!
   TBranch        *b_tau_truthJetFlavour_0;   //!
   TBranch        *b_tau_pt_1;   //!
   TBranch        *b_tau_eta_1;   //!
   TBranch        *b_tau_phi_1;   //!
   TBranch        *b_tau_charge_1;   //!
   TBranch        *b_tau_E_1;   //!
   TBranch        *b_tau_BDTJetScore_1;   //!
   TBranch        *b_tau_JetBDTSigLoose_1;   //!
   TBranch        *b_tau_JetBDTSigMedium_1;   //!
   TBranch        *b_tau_JetBDTSigTight_1;   //!
   TBranch        *b_tau_numTrack_1;   //!
   TBranch        *b_tau_isHadronic_1;   //!
   TBranch        *b_tau_SFTight_1;   //!
   TBranch        *b_tau_SFLoose_1;   //!
   TBranch        *b_tau_tagWeightBin_1;   //!
   TBranch        *b_tau_fromPV_1;   //!
   TBranch        *b_tau_passEleOLR_1;   //!
   TBranch        *b_tau_passEleBDT_1;   //!
   TBranch        *b_tau_passMuonOLR_1;   //!
   TBranch        *b_tau_truthOrigin_1;   //!
   TBranch        *b_tau_truthType_1;   //!
   TBranch        *b_tau_truthJetFlavour_1;   //!
   TBranch        *b_tau_promptTauVeto_0;   //!
   TBranch        *b_tau_promptTauVeto_1;   //!
   TBranch        *b_onelep_type;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_quadlep_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_isQMisIDEvent;   //!
   TBranch        *b_isFakeEvent;   //!
   TBranch        *b_isLepFromPhEvent;   //!
   TBranch        *b_Mll01;   //!
   TBranch        *b_Ptll01;   //!
   TBranch        *b_DRll01;   //!
   TBranch        *b_Mlll012;   //!
   TBranch        *b_Mllll0123;   //!
   TBranch        *b_Mlll013;   //!
   TBranch        *b_Mll02;   //!
   TBranch        *b_Ptll02;   //!
   TBranch        *b_DRll02;   //!
   TBranch        *b_Mlll023;   //!
   TBranch        *b_Mll03;   //!
   TBranch        *b_Ptll03;   //!
   TBranch        *b_DRll03;   //!
   TBranch        *b_Mll12;   //!
   TBranch        *b_Ptll12;   //!
   TBranch        *b_DRll12;   //!
   TBranch        *b_Mlll123;   //!
   TBranch        *b_Mll13;   //!
   TBranch        *b_Ptll13;   //!
   TBranch        *b_DRll13;   //!
   TBranch        *b_Mll23;   //!
   TBranch        *b_Ptll23;   //!
   TBranch        *b_DRll23;   //!
   TBranch        *b_matchDLTll01;   //!
   TBranch        *b_matchDLTll02;   //!
   TBranch        *b_matchDLTll12;   //!
   TBranch        *b_matchDLTll03;   //!
   TBranch        *b_matchDLTll13;   //!
   TBranch        *b_matchDLTll23;   //!
   TBranch        *b_best_Z_Mll;   //!
   TBranch        *b_best_Z_other_Mll;   //!
   TBranch        *b_best_Z_other_MtLepMet;   //!
   TBranch        *b_nJets_OR_T;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nJets_OR_T_MV2c20_60;   //!
   TBranch        *b_nJets_OR_T_MV2c20_70;   //!
   TBranch        *b_nJets_OR_T_MV2c20_77;   //!
   TBranch        *b_nJets_OR_T_MV2c20_85;   //!
   TBranch        *b_nJets_OR_MV2c20_85;   //!
   TBranch        *b_nJets_OR_MV2c20_60;   //!
   TBranch        *b_nJets_OR_MV2c20_77;   //!
   TBranch        *b_nJets_OR_MV2c20_70;   //!
   TBranch        *b_nJets_OR_T_MV2c10_60;   //!
   TBranch        *b_nJets_OR_T_MV2c10_70;   //!
   TBranch        *b_nJets_OR_T_MV2c10_77;   //!
   TBranch        *b_nJets_OR_T_MV2c10_85;   //!
   TBranch        *b_nJets_OR_MV2c10_85;   //!
   TBranch        *b_nJets_OR_MV2c10_60;   //!
   TBranch        *b_nJets_OR_MV2c10_77;   //!
   TBranch        *b_nJets_OR_MV2c10_70;   //!
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_isBlinded;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_lead_jetPt;   //!
   TBranch        *b_lead_jetEta;   //!
   TBranch        *b_lead_jetPhi;   //!
   TBranch        *b_lead_jetE;   //!
   TBranch        *b_sublead_jetPt;   //!
   TBranch        *b_sublead_jetEta;   //!
   TBranch        *b_sublead_jetPhi;   //!
   TBranch        *b_sublead_jetE;   //!
   TBranch        *b_lepSFTrigLoose;   //!
   TBranch        *b_lepSFTrigTight;   //!
   TBranch        *b_lepSFTrigTightLoose;   //!
   TBranch        *b_lepSFTrigLooseTight;   //!
   TBranch        *b_lepEffTrigLoose;   //!
   TBranch        *b_lepEffTrigTight;   //!
   TBranch        *b_lepEffTrigTightLoose;   //!
   TBranch        *b_lepEffTrigLooseTight;   //!
   TBranch        *b_lepDataEffTrigLoose;   //!
   TBranch        *b_lepDataEffTrigTight;   //!
   TBranch        *b_lepDataEffTrigTightLoose;   //!
   TBranch        *b_lepDataEffTrigLooseTight;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_tauSFTight;   //!
   TBranch        *b_tauSFLoose;   //!
   TBranch        *b_tauFakeSF_weight;   //!
   TBranch        *b_tauFakeSF_weight_SYST_UP;   //!
   TBranch        *b_tauFakeSF_weight_SYST_DOWN;   //!
   TBranch        *b_tauFakeSF_weight_STAT_UP;   //!
   TBranch        *b_tauFakeSF_weight_STAT_DOWN;   //!

   GN_v7(TTree *tree=0);
   virtual ~GN_v7();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef GN_v7_cxx
GN_v7::GN_v7(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../ttHMLSamps/v7_01/all/tth.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../ttHMLSamps/v7_01/all/tth.root");
      }
      f->GetObject("nominal",tree);

   }
   Init(tree);
}

GN_v7::~GN_v7()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GN_v7::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GN_v7::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void GN_v7::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_flavor_truth_label_ghost = 0;
   jet_pT = 0;
   jet_eta = 0;
   lepton_PromptLeptonIso_TagWeight = 0;
   lepton_ChargeIDBDTTight = 0;
   electron_ambiguityType = 0;
   electron_PromptLeptonIso_TagWeight = 0;
   electron_PromptLeptonVeto_TagWeight = 0;
   muon_PromptLeptonIso_TagWeight = 0;
   muon_PromptLeptonVeto_TagWeight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("is1L2Tau", &is1L2Tau, &b_is1L2Tau);
   fChain->SetBranchAddress("is2LSS0Tau", &is2LSS0Tau, &b_is2LSS0Tau);
   fChain->SetBranchAddress("pass_tight_2L", &pass_tight_2L, &b_pass_tight_2L);
   fChain->SetBranchAddress("pass_SS_2L", &pass_SS_2L, &b_pass_SS_2L);
   fChain->SetBranchAddress("is2LSS1Tau", &is2LSS1Tau, &b_is2LSS1Tau);
   fChain->SetBranchAddress("is2LOS1Tau", &is2LOS1Tau, &b_is2LOS1Tau);
   fChain->SetBranchAddress("is3L", &is3L, &b_is3L);
   fChain->SetBranchAddress("is3L1Tau", &is3L1Tau, &b_is3L1Tau);
   fChain->SetBranchAddress("is4L", &is4L, &b_is4L);
   fChain->SetBranchAddress("is2lLowNJet0Tau", &is2lLowNJet0Tau, &b_is2lLowNJet0Tau);
   fChain->SetBranchAddress("is2LSS0Tau_SR_Relaxed", &is2LSS0Tau_SR_Relaxed, &b_is2LSS0Tau_SR_Relaxed);
   fChain->SetBranchAddress("is2LSS1Tau_SR_Relaxed", &is2LSS1Tau_SR_Relaxed, &b_is2LSS1Tau_SR_Relaxed);
   fChain->SetBranchAddress("is3L0Tau_SR_Relaxed", &is3L0Tau_SR_Relaxed, &b_is3L0Tau_SR_Relaxed);
   fChain->SetBranchAddress("is3L0Tau_SR_Relaxed3j", &is3L0Tau_SR_Relaxed3j, &b_is3L0Tau_SR_Relaxed3j);
   fChain->SetBranchAddress("is4L_SR_VV_Relaxed", &is4L_SR_VV_Relaxed, &b_is4L_SR_VV_Relaxed);
   fChain->SetBranchAddress("is4L_SR_ttV_Relaxed", &is4L_SR_ttV_Relaxed, &b_is4L_SR_ttV_Relaxed);
   fChain->SetBranchAddress("is4L_SR_ttV_Zenriched", &is4L_SR_ttV_Zenriched, &b_is4L_SR_ttV_Zenriched);
   fChain->SetBranchAddress("is3L0Tau_CR_ttbar_Relaxed", &is3L0Tau_CR_ttbar_Relaxed, &b_is3L0Tau_CR_ttbar_Relaxed);
   fChain->SetBranchAddress("is3L0Tau_CR_VV_Relaxed", &is3L0Tau_CR_VV_Relaxed, &b_is3L0Tau_CR_VV_Relaxed);
   fChain->SetBranchAddress("is3L0Tau_CR_ttW_Relaxed", &is3L0Tau_CR_ttW_Relaxed, &b_is3L0Tau_CR_ttW_Relaxed);
   fChain->SetBranchAddress("is2L_VR_ttW_ICHEP", &is2L_VR_ttW_ICHEP, &b_is2L_VR_ttW_ICHEP);
   fChain->SetBranchAddress("is2L_VR_ttbarFakes_ICHEP", &is2L_VR_ttbarFakes_ICHEP, &b_is2L_VR_ttbarFakes_ICHEP);
   fChain->SetBranchAddress("is4lCRttZRelaxed", &is4lCRttZRelaxed, &b_is4lCRttZRelaxed);
   fChain->SetBranchAddress("is2LOS1Tau_CR_ttbar", &is2LOS1Tau_CR_ttbar, &b_is2LOS1Tau_CR_ttbar);
   fChain->SetBranchAddress("is2LOS1Tau_CR_ttZ", &is2LOS1Tau_CR_ttZ, &b_is2LOS1Tau_CR_ttZ);
   fChain->SetBranchAddress("is2LOS1Tau_CR_W", &is2LOS1Tau_CR_W, &b_is2LOS1Tau_CR_W);
   fChain->SetBranchAddress("is3L1Tau_VR", &is3L1Tau_VR, &b_is3L1Tau_VR);
   fChain->SetBranchAddress("is2lOS0TauBaseline", &is2lOS0TauBaseline, &b_is2lOS0TauBaseline);
   fChain->SetBranchAddress("is2lOS0TauBaseline_ee", &is2lOS0TauBaseline_ee, &b_is2lOS0TauBaseline_ee);
   fChain->SetBranchAddress("is2lOS0TauBaseline_mm", &is2lOS0TauBaseline_mm, &b_is2lOS0TauBaseline_mm);
   fChain->SetBranchAddress("is2lOS0TauBaseline_OF", &is2lOS0TauBaseline_OF, &b_is2lOS0TauBaseline_OF);
   fChain->SetBranchAddress("is2lOS0TauBaseline_me", &is2lOS0TauBaseline_me, &b_is2lOS0TauBaseline_me);
   fChain->SetBranchAddress("is2lOS0TauBaseline_em", &is2lOS0TauBaseline_em, &b_is2lOS0TauBaseline_em);
   fChain->SetBranchAddress("is2lSS0TauBaseline", &is2lSS0TauBaseline, &b_is2lSS0TauBaseline);
   fChain->SetBranchAddress("is2lSS0TauBaseline_ee", &is2lSS0TauBaseline_ee, &b_is2lSS0TauBaseline_ee);
   fChain->SetBranchAddress("is2lSS0TauBaseline_mm", &is2lSS0TauBaseline_mm, &b_is2lSS0TauBaseline_mm);
   fChain->SetBranchAddress("is2lSS0TauBaseline_OF", &is2lSS0TauBaseline_OF, &b_is2lSS0TauBaseline_OF);
   fChain->SetBranchAddress("is2lSS0TauBaseline_me", &is2lSS0TauBaseline_me, &b_is2lSS0TauBaseline_me);
   fChain->SetBranchAddress("is2lSS0TauBaseline_em", &is2lSS0TauBaseline_em, &b_is2lSS0TauBaseline_em);
   fChain->SetBranchAddress("is2lOS1TauBaseline", &is2lOS1TauBaseline, &b_is2lOS1TauBaseline);
   fChain->SetBranchAddress("is2lOS1TauBaseline_ee", &is2lOS1TauBaseline_ee, &b_is2lOS1TauBaseline_ee);
   fChain->SetBranchAddress("is2lOS1TauBaseline_mm", &is2lOS1TauBaseline_mm, &b_is2lOS1TauBaseline_mm);
   fChain->SetBranchAddress("is2lOS1TauBaseline_OF", &is2lOS1TauBaseline_OF, &b_is2lOS1TauBaseline_OF);
   fChain->SetBranchAddress("is2lOS1TauBaseline_me", &is2lOS1TauBaseline_me, &b_is2lOS1TauBaseline_me);
   fChain->SetBranchAddress("is2lOS1TauBaseline_em", &is2lOS1TauBaseline_em, &b_is2lOS1TauBaseline_em);
   fChain->SetBranchAddress("is2lSS1TauBaseline", &is2lSS1TauBaseline, &b_is2lSS1TauBaseline);
   fChain->SetBranchAddress("is2lSS1TauBaseline_ee", &is2lSS1TauBaseline_ee, &b_is2lSS1TauBaseline_ee);
   fChain->SetBranchAddress("is2lSS1TauBaseline_mm", &is2lSS1TauBaseline_mm, &b_is2lSS1TauBaseline_mm);
   fChain->SetBranchAddress("is2lSS1TauBaseline_OF", &is2lSS1TauBaseline_OF, &b_is2lSS1TauBaseline_OF);
   fChain->SetBranchAddress("is2lSS1TauBaseline_me", &is2lSS1TauBaseline_me, &b_is2lSS1TauBaseline_me);
   fChain->SetBranchAddress("is2lSS1TauBaseline_em", &is2lSS1TauBaseline_em, &b_is2lSS1TauBaseline_em);
   fChain->SetBranchAddress("is3lBaseline", &is3lBaseline, &b_is3lBaseline);
   fChain->SetBranchAddress("is3lBaselineNoZVeto", &is3lBaselineNoZVeto, &b_is3lBaselineNoZVeto);
   fChain->SetBranchAddress("is2lss1tau_regionB", &is2lss1tau_regionB, &b_is2lss1tau_regionB);
   fChain->SetBranchAddress("is2lss1tau_regionC", &is2lss1tau_regionC, &b_is2lss1tau_regionC);
   fChain->SetBranchAddress("is2lss1tau_regionD", &is2lss1tau_regionD, &b_is2lss1tau_regionD);
   fChain->SetBranchAddress("isGNv02", &isGNv02, &b_isGNv02);
   fChain->SetBranchAddress("minOSMll", &minOSMll, &b_minOSMll);
   fChain->SetBranchAddress("minOSSFMll", &minOSSFMll, &b_minOSSFMll);
   fChain->SetBranchAddress("jet_flvWtOrdr_0_pt", &jet_flvWtOrdr_0_pt, &b_jet_flvWtOrdr_0_pt);
   fChain->SetBranchAddress("jet_flvWtOrdr_0_eta", &jet_flvWtOrdr_0_eta, &b_jet_flvWtOrdr_0_eta);
   fChain->SetBranchAddress("jet_flvWtOrdr_0_phi", &jet_flvWtOrdr_0_phi, &b_jet_flvWtOrdr_0_phi);
   fChain->SetBranchAddress("jet_flvWtOrdr_0_E", &jet_flvWtOrdr_0_E, &b_jet_flvWtOrdr_0_E);
   fChain->SetBranchAddress("jet_flvWtOrdr_0_mv2c10", &jet_flvWtOrdr_0_mv2c10, &b_jet_flvWtOrdr_0_mv2c10);
   fChain->SetBranchAddress("jet_flvWtOrdr_1_pt", &jet_flvWtOrdr_1_pt, &b_jet_flvWtOrdr_1_pt);
   fChain->SetBranchAddress("jet_flvWtOrdr_1_eta", &jet_flvWtOrdr_1_eta, &b_jet_flvWtOrdr_1_eta);
   fChain->SetBranchAddress("jet_flvWtOrdr_1_phi", &jet_flvWtOrdr_1_phi, &b_jet_flvWtOrdr_1_phi);
   fChain->SetBranchAddress("jet_flvWtOrdr_1_E", &jet_flvWtOrdr_1_E, &b_jet_flvWtOrdr_1_E);
   fChain->SetBranchAddress("jet_flvWtOrdr_1_mv2c10", &jet_flvWtOrdr_1_mv2c10, &b_jet_flvWtOrdr_1_mv2c10);
   fChain->SetBranchAddress("jet_flvWtOrdr_2_pt", &jet_flvWtOrdr_2_pt, &b_jet_flvWtOrdr_2_pt);
   fChain->SetBranchAddress("jet_flvWtOrdr_2_eta", &jet_flvWtOrdr_2_eta, &b_jet_flvWtOrdr_2_eta);
   fChain->SetBranchAddress("jet_flvWtOrdr_2_phi", &jet_flvWtOrdr_2_phi, &b_jet_flvWtOrdr_2_phi);
   fChain->SetBranchAddress("jet_flvWtOrdr_2_E", &jet_flvWtOrdr_2_E, &b_jet_flvWtOrdr_2_E);
   fChain->SetBranchAddress("jet_flvWtOrdr_2_mv2c10", &jet_flvWtOrdr_2_mv2c10, &b_jet_flvWtOrdr_2_mv2c10);
   fChain->SetBranchAddress("DEtall01", &DEtall01, &b_DEtall01);
   fChain->SetBranchAddress("DEtall02", &DEtall02, &b_DEtall02);
   fChain->SetBranchAddress("DEtall12", &DEtall12, &b_DEtall12);
   fChain->SetBranchAddress("lep_flavour", &lep_flavour, &b_lep_flavour);
   fChain->SetBranchAddress("jet_flavor", &jet_flavor, &b_jet_flavor);
   fChain->SetBranchAddress("total_charge_2lSS", &total_charge_2lSS, &b_total_charge_2lSS);
   fChain->SetBranchAddress("isExtConv", &isExtConv, &b_isExtConv);
   fChain->SetBranchAddress("isIntConv", &isIntConv, &b_isIntConv);
   fChain->SetBranchAddress("max_eta", &max_eta, &b_max_eta);
   fChain->SetBranchAddress("SDRll", &SDRll, &b_SDRll);
   fChain->SetBranchAddress("DeltaR_max_lep", &DeltaR_max_lep, &b_DeltaR_max_lep);
   fChain->SetBranchAddress("DPhi_max_lep_met", &DPhi_max_lep_met, &b_DPhi_max_lep_met);
   fChain->SetBranchAddress("DeltaR_min_lep_jet", &DeltaR_min_lep_jet, &b_DeltaR_min_lep_jet);
   fChain->SetBranchAddress("minDeltaR_LJ_0", &minDeltaR_LJ_0, &b_minDeltaR_LJ_0);
   fChain->SetBranchAddress("minDeltaR_LJ_1", &minDeltaR_LJ_1, &b_minDeltaR_LJ_1);
   fChain->SetBranchAddress("minDeltaR_LJ_2", &minDeltaR_LJ_2, &b_minDeltaR_LJ_2);
   fChain->SetBranchAddress("Meff", &Meff, &b_Meff);
   fChain->SetBranchAddress("Mjj_closeW", &Mjj_closeW, &b_Mjj_closeW);
   fChain->SetBranchAddress("DRlb_h", &DRlb_h, &b_DRlb_h);
   fChain->SetBranchAddress("ptlb_h", &ptlb_h, &b_ptlb_h);
   fChain->SetBranchAddress("DeltaRLeadjets", &DeltaRLeadjets, &b_DeltaRLeadjets);
   fChain->SetBranchAddress("jet1pTbin", &jet1pTbin, &b_jet1pTbin);
   fChain->SetBranchAddress("jet2pTbin", &jet2pTbin, &b_jet2pTbin);
   fChain->SetBranchAddress("jet3pTbin", &jet3pTbin, &b_jet3pTbin);
   fChain->SetBranchAddress("jet3etabin", &jet3etabin, &b_jet3etabin);
   fChain->SetBranchAddress("jet1MV2c10_bin", &jet1MV2c10_bin, &b_jet1MV2c10_bin);
   fChain->SetBranchAddress("jet2MV2c10_bin", &jet2MV2c10_bin, &b_jet2MV2c10_bin);
   fChain->SetBranchAddress("MvisH", &MvisH, &b_MvisH);
   fChain->SetBranchAddress("MvisnonH", &MvisnonH, &b_MvisnonH);
   fChain->SetBranchAddress("lep_PtVarCone20Rel_1", &lep_PtVarCone20Rel_1, &b_lep_PtVarCone20Rel_1);
   fChain->SetBranchAddress("DeltaRLeadLepClosestJet", &DeltaRLeadLepClosestJet, &b_DeltaRLeadLepClosestJet);
   fChain->SetBranchAddress("Ml2l3met", &Ml2l3met, &b_Ml2l3met);
   fChain->SetBranchAddress("FSF_4L_tot", &FSF_4L_tot, &b_FSF_4L_tot);
   fChain->SetBranchAddress("FSF_4L_tot_up", &FSF_4L_tot_up, &b_FSF_4L_tot_up);
   fChain->SetBranchAddress("FSF_4L_tot_down", &FSF_4L_tot_down, &b_FSF_4L_tot_down);
   fChain->SetBranchAddress("FSF_category", &FSF_category, &b_FSF_category);
   fChain->SetBranchAddress("FSF_4L_e_L", &FSF_4L_e_L, &b_FSF_4L_e_L);
   fChain->SetBranchAddress("FSF_4L_e_H", &FSF_4L_e_H, &b_FSF_4L_e_H);
   fChain->SetBranchAddress("FSF_4L_m", &FSF_4L_m, &b_FSF_4L_m);
   fChain->SetBranchAddress("jet2_pt", &jet2_pt, &b_jet2_pt);
   fChain->SetBranchAddress("jet2_eta", &jet2_eta, &b_jet2_eta);
   fChain->SetBranchAddress("jet2_phi", &jet2_phi, &b_jet2_phi);
   fChain->SetBranchAddress("jet3_pt", &jet3_pt, &b_jet3_pt);
   fChain->SetBranchAddress("jet3_eta", &jet3_eta, &b_jet3_eta);
   fChain->SetBranchAddress("jet3_phi", &jet3_phi, &b_jet3_phi);
   fChain->SetBranchAddress("jet0_tagWeightBin", &jet0_tagWeightBin, &b_jet0_tagWeightBin);
   fChain->SetBranchAddress("jet1_tagWeightBin", &jet1_tagWeightBin, &b_jet1_tagWeightBin);
   fChain->SetBranchAddress("jet2_tagWeightBin", &jet2_tagWeightBin, &b_jet2_tagWeightBin);
   fChain->SetBranchAddress("jet3_tagWeightBin", &jet3_tagWeightBin, &b_jet3_tagWeightBin);
   fChain->SetBranchAddress("N_el", &N_el, &b_N_el);
   fChain->SetBranchAddress("N_mu", &N_mu, &b_N_mu);
   fChain->SetBranchAddress("tempDPl0t", &tempDPl0t, &b_tempDPl0t);
   fChain->SetBranchAddress("tempDPl1t", &tempDPl1t, &b_tempDPl1t);
   fChain->SetBranchAddress("tempDP2l", &tempDP2l, &b_tempDP2l);
   fChain->SetBranchAddress("tempDPlt_closest", &tempDPlt_closest, &b_tempDPlt_closest);
   fChain->SetBranchAddress("tempDPlt_furthest", &tempDPlt_furthest, &b_tempDPlt_furthest);
   fChain->SetBranchAddress("DeltaRSubLepClosestJet", &DeltaRSubLepClosestJet, &b_DeltaRSubLepClosestJet);
   fChain->SetBranchAddress("SignProduct2sslt", &SignProduct2sslt, &b_SignProduct2sslt);
   fChain->SetBranchAddress("TransverseMassLeadLepMET", &TransverseMassLeadLepMET, &b_TransverseMassLeadLepMET);
   fChain->SetBranchAddress("LD_HTmiss_ETmiss", &LD_HTmiss_ETmiss, &b_LD_HTmiss_ETmiss);
   fChain->SetBranchAddress("Mjj_nonb", &Mjj_nonb, &b_Mjj_nonb);
   fChain->SetBranchAddress("Mtop", &Mtop, &b_Mtop);
   fChain->SetBranchAddress("MtopW", &MtopW, &b_MtopW);
   fChain->SetBranchAddress("temptopoetcone20overpTlep0", &temptopoetcone20overpTlep0, &b_temptopoetcone20overpTlep0);
   fChain->SetBranchAddress("temptopoetcone20overpTlep1", &temptopoetcone20overpTlep1, &b_temptopoetcone20overpTlep1);
   fChain->SetBranchAddress("tempptvarcone20overpTlep0", &tempptvarcone20overpTlep0, &b_tempptvarcone20overpTlep0);
   fChain->SetBranchAddress("tempptvarcone20overpTlep1", &tempptvarcone20overpTlep1, &b_tempptvarcone20overpTlep1);
   fChain->SetBranchAddress("lep_isAntiTight_0", &lep_isAntiTight_0, &b_lep_isAntiTight_0);
   fChain->SetBranchAddress("lep_isAntiTight_1", &lep_isAntiTight_1, &b_lep_isAntiTight_1);
   fChain->SetBranchAddress("tau_tight_0", &tau_tight_0, &b_tau_tight_0);
   fChain->SetBranchAddress("tau_tight_1", &tau_tight_1, &b_tau_tight_1);
   fChain->SetBranchAddress("tau_btag70_0", &tau_btag70_0, &b_tau_btag70_0);
   fChain->SetBranchAddress("tau_btag70_1", &tau_btag70_1, &b_tau_btag70_1);
   fChain->SetBranchAddress("tau_truth_0", &tau_truth_0, &b_tau_truth_0);
   fChain->SetBranchAddress("tau_truth_1", &tau_truth_1, &b_tau_truth_1);
   fChain->SetBranchAddress("htjets_1l2tau", &htjets_1l2tau, &b_htjets_1l2tau);
   fChain->SetBranchAddress("jjdrmin_1l2tau", &jjdrmin_1l2tau, &b_jjdrmin_1l2tau);
   fChain->SetBranchAddress("mtautau_1l2tau", &mtautau_1l2tau, &b_mtautau_1l2tau);
   fChain->SetBranchAddress("njets_1l2tau", &njets_1l2tau, &b_njets_1l2tau);
   fChain->SetBranchAddress("nbjets_1l2tau", &nbjets_1l2tau, &b_nbjets_1l2tau);
   fChain->SetBranchAddress("DRlj00", &DRlj00, &b_DRlj00);
   fChain->SetBranchAddress("DRjj01", &DRjj01, &b_DRjj01);
   fChain->SetBranchAddress("min_DRl0j", &min_DRl0j, &b_min_DRl0j);
   fChain->SetBranchAddress("min_DRl1j", &min_DRl1j, &b_min_DRl1j);
   fChain->SetBranchAddress("min_DRl2j", &min_DRl2j, &b_min_DRl2j);
   fChain->SetBranchAddress("min_DRl0b", &min_DRl0b, &b_min_DRl0b);
   fChain->SetBranchAddress("min_DRl1b", &min_DRl1b, &b_min_DRl1b);
   fChain->SetBranchAddress("min_DRl2b", &min_DRl2b, &b_min_DRl2b);
   fChain->SetBranchAddress("min_DRlj_new", &min_DRlj_new, &b_min_DRlj_new);
   fChain->SetBranchAddress("nJets_OR_T_overflow", &nJets_OR_T_overflow, &b_nJets_OR_T_overflow);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_70_overflow", &nJets_OR_T_MV2c10_70_overflow, &b_nJets_OR_T_MV2c10_70_overflow);
   fChain->SetBranchAddress("DPhij0MET", &DPhij0MET, &b_DPhij0MET);
   fChain->SetBranchAddress("lead_BjetPt", &lead_BjetPt, &b_lead_BjetPt);
   fChain->SetBranchAddress("lead_jet_sumBEff", &lead_jet_sumBEff, &b_lead_jet_sumBEff);
   fChain->SetBranchAddress("sublead_jet_sumBEff", &sublead_jet_sumBEff, &b_sublead_jet_sumBEff);
   fChain->SetBranchAddress("lead_jet_pass_FixedCutBEff_70", &lead_jet_pass_FixedCutBEff_70, &b_lead_jet_pass_FixedCutBEff_70);
   fChain->SetBranchAddress("sublead_jet_pass_FixedCutBEff_70", &sublead_jet_pass_FixedCutBEff_70, &b_sublead_jet_pass_FixedCutBEff_70);
   fChain->SetBranchAddress("lead_jet_is_lead_antitag", &lead_jet_is_lead_antitag, &b_lead_jet_is_lead_antitag);
   fChain->SetBranchAddress("lead_jet_is_lead_tag", &lead_jet_is_lead_tag, &b_lead_jet_is_lead_tag);
   fChain->SetBranchAddress("lep_Pt_1_new", &lep_Pt_1_new, &b_lep_Pt_1_new);
   fChain->SetBranchAddress("lep_Pt_2_new", &lep_Pt_2_new, &b_lep_Pt_2_new);
   fChain->SetBranchAddress("lep_ID_1_new", &lep_ID_1_new, &b_lep_ID_1_new);
   fChain->SetBranchAddress("lep_ID_2_new", &lep_ID_2_new, &b_lep_ID_2_new);
   fChain->SetBranchAddress("lep_isPrompt_1_new", &lep_isPrompt_1_new, &b_lep_isPrompt_1_new);
   fChain->SetBranchAddress("lep_isPrompt_2_new", &lep_isPrompt_2_new, &b_lep_isPrompt_2_new);
   fChain->SetBranchAddress("lep_truthOrigin_1_new", &lep_truthOrigin_1_new, &b_lep_truthOrigin_1_new);
   fChain->SetBranchAddress("lep_truthOrigin_2_new", &lep_truthOrigin_2_new, &b_lep_truthOrigin_2_new);
   fChain->SetBranchAddress("lep_truthParentPdgId_1_new", &lep_truthParentPdgId_1_new, &b_lep_truthParentPdgId_1_new);
   fChain->SetBranchAddress("lep_truthParentPdgId_2_new", &lep_truthParentPdgId_2_new, &b_lep_truthParentPdgId_2_new);
   fChain->SetBranchAddress("lep_truthParentType_1_new", &lep_truthParentType_1_new, &b_lep_truthParentType_1_new);
//    fChain->SetBranchAddress("lep_truthParentPdgId_2_new", &lep_truthParentPdgId_2_new, &b_lep_truthParentPdgId_2_new);
   fChain->SetBranchAddress("lep_isQMisID_1_new", &lep_isQMisID_1_new, &b_lep_isQMisID_1_new);
   fChain->SetBranchAddress("lep_isQMisID_2_new", &lep_isQMisID_2_new, &b_lep_isQMisID_2_new);
   fChain->SetBranchAddress("lep_Eta_1_new", &lep_Eta_1_new, &b_lep_Eta_1_new);
   fChain->SetBranchAddress("lep_Eta_2_new", &lep_Eta_2_new, &b_lep_Eta_2_new);
   fChain->SetBranchAddress("lep_Phi_1_new", &lep_Phi_1_new, &b_lep_Phi_1_new);
   fChain->SetBranchAddress("lep_Phi_2_new", &lep_Phi_2_new, &b_lep_Phi_2_new);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_1_new", &lep_isolationFixedCutLoose_1_new, &b_lep_isolationFixedCutLoose_1_new);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_2_new", &lep_isolationFixedCutLoose_2_new, &b_lep_isolationFixedCutLoose_2_new);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_1_new", &lep_promptLeptonVeto_TagWeight_1_new, &b_lep_promptLeptonVeto_TagWeight_1_new);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_2_new", &lep_promptLeptonVeto_TagWeight_2_new, &b_lep_promptLeptonVeto_TagWeight_2_new);
   fChain->SetBranchAddress("lep_isTightLH_1_new", &lep_isTightLH_1_new, &b_lep_isTightLH_1_new);
   fChain->SetBranchAddress("lep_isTightLH_2_new", &lep_isTightLH_2_new, &b_lep_isTightLH_2_new);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_1_new", &lep_chargeIDBDTTight_1_new, &b_lep_chargeIDBDTTight_1_new);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_2_new", &lep_chargeIDBDTTight_2_new, &b_lep_chargeIDBDTTight_2_new);
   fChain->SetBranchAddress("lep_ambiguityType_1_new", &lep_ambiguityType_1_new, &b_lep_ambiguityType_1_new);
   fChain->SetBranchAddress("lep_ambiguityType_2_new", &lep_ambiguityType_2_new, &b_lep_ambiguityType_2_new);
   fChain->SetBranchAddress("lep_isMedium_1_new", &lep_isMedium_1_new, &b_lep_isMedium_1_new);
   fChain->SetBranchAddress("lep_isMedium_2_new", &lep_isMedium_2_new, &b_lep_isMedium_2_new);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("lep_isTightSelected_0", &lep_isTightSelected_0, &b_lep_isTightSelected_0);
   fChain->SetBranchAddress("lep_isTightSelected_1", &lep_isTightSelected_1, &b_lep_isTightSelected_1);
   fChain->SetBranchAddress("lep_isTightSelected_2", &lep_isTightSelected_2, &b_lep_isTightSelected_2);
   fChain->SetBranchAddress("lep_isTightSelected_3", &lep_isTightSelected_3, &b_lep_isTightSelected_3);
   fChain->SetBranchAddress("lep_isTightSelected_2LOS1Tau_0", &lep_isTightSelected_2LOS1Tau_0, &b_lep_isTightSelected_2LOS1Tau_0);
   fChain->SetBranchAddress("lep_isTightSelected_2LOS1Tau_1", &lep_isTightSelected_2LOS1Tau_1, &b_lep_isTightSelected_2LOS1Tau_1);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_0", &lep_isTightSelectedAndPt_0, &b_lep_isTightSelectedAndPt_0);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_1", &lep_isTightSelectedAndPt_1, &b_lep_isTightSelectedAndPt_1);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_2", &lep_isTightSelectedAndPt_2, &b_lep_isTightSelectedAndPt_2);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_3", &lep_isTightSelectedAndPt_3, &b_lep_isTightSelectedAndPt_3);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_2LOS1Tau_0", &lep_isTightSelectedAndPt_2LOS1Tau_0, &b_lep_isTightSelectedAndPt_2LOS1Tau_0);
   fChain->SetBranchAddress("lep_isTightSelectedAndPt_2LOS1Tau_1", &lep_isTightSelectedAndPt_2LOS1Tau_1, &b_lep_isTightSelectedAndPt_2LOS1Tau_1);
   fChain->SetBranchAddress("jet_flavor_truth_label_ghost", &jet_flavor_truth_label_ghost, &b_jet_flavor_truth_label_ghost);
   fChain->SetBranchAddress("jet_pT", &jet_pT, &b_jet_pT);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("MVA2lSSMarseille_weight_ttV", &MVA2lSSMarseille_weight_ttV, &b_MVA2lSSMarseille_weight_ttV);
   fChain->SetBranchAddress("MVA2lSSMarseille_weight_ttbar", &MVA2lSSMarseille_weight_ttbar, &b_MVA2lSSMarseille_weight_ttbar);
   fChain->SetBranchAddress("MVA2lSSMarseille_weight_ttV_2", &MVA2lSSMarseille_weight_ttV_2, &b_MVA2lSSMarseille_weight_ttV_2);
   fChain->SetBranchAddress("MVA2lSSMarseille_weight_ttbar_2", &MVA2lSSMarseille_weight_ttbar_2, &b_MVA2lSSMarseille_weight_ttbar_2);
   fChain->SetBranchAddress("MVA2lSS1tau_weight_random_ttbar", &MVA2lSS1tau_weight_random_ttbar, &b_MVA2lSS1tau_weight_random_ttbar);
   fChain->SetBranchAddress("MVA2lSS1tau_weight_CT_ttbar", &MVA2lSS1tau_weight_CT_ttbar, &b_MVA2lSS1tau_weight_CT_ttbar);
   fChain->SetBranchAddress("MVA2lSS1tau_weight_random_nottbar", &MVA2lSS1tau_weight_random_nottbar, &b_MVA2lSS1tau_weight_random_nottbar);
   fChain->SetBranchAddress("MVA2lSS1tau_weight_CT_nottbar", &MVA2lSS1tau_weight_CT_nottbar, &b_MVA2lSS1tau_weight_CT_nottbar);
   fChain->SetBranchAddress("MVA2lOS1tau_weight", &MVA2lOS1tau_weight, &b_MVA2lOS1tau_weight);
   fChain->SetBranchAddress("SumPtBJet", &SumPtBJet, &b_SumPtBJet);
   fChain->SetBranchAddress("SumPtJet", &SumPtJet, &b_SumPtJet);
   fChain->SetBranchAddress("SumPtLep", &SumPtLep, &b_SumPtLep);
   fChain->SetBranchAddress("DRlj", &DRlj, &b_DRlj);
   fChain->SetBranchAddress("DRlb", &DRlb, &b_DRlb);
   fChain->SetBranchAddress("DRjb", &DRjb, &b_DRjb);
   fChain->SetBranchAddress("DRl0tau", &DRl0tau, &b_DRl0tau);
   fChain->SetBranchAddress("DRl1tau", &DRl1tau, &b_DRl1tau);
   fChain->SetBranchAddress("MVA3lCERN_weight_ttH", &MVA3lCERN_weight_ttH, &b_MVA3lCERN_weight_ttH);
   fChain->SetBranchAddress("MVA3lCERN_weight_ttW", &MVA3lCERN_weight_ttW, &b_MVA3lCERN_weight_ttW);
   fChain->SetBranchAddress("MVA3lCERN_weight_ttZ", &MVA3lCERN_weight_ttZ, &b_MVA3lCERN_weight_ttZ);
   fChain->SetBranchAddress("MVA3lCERN_weight_VV", &MVA3lCERN_weight_VV, &b_MVA3lCERN_weight_VV);
   fChain->SetBranchAddress("MVA3lCERN_weight_ttbar", &MVA3lCERN_weight_ttbar, &b_MVA3lCERN_weight_ttbar);
   fChain->SetBranchAddress("MVA3lCERN_category", &MVA3lCERN_category, &b_MVA3lCERN_category);
   fChain->SetBranchAddress("MVA3lZZCERN_weight_ttH", &MVA3lZZCERN_weight_ttH, &b_MVA3lZZCERN_weight_ttH);
   fChain->SetBranchAddress("MVA3lZZCERN_weight_ttZ", &MVA3lZZCERN_weight_ttZ, &b_MVA3lZZCERN_weight_ttZ);
   fChain->SetBranchAddress("MVA3lZZCERN_weight_VV", &MVA3lZZCERN_weight_VV, &b_MVA3lZZCERN_weight_VV);
   fChain->SetBranchAddress("MVA3lZZCERN_category", &MVA3lZZCERN_category, &b_MVA3lZZCERN_category);
   fChain->SetBranchAddress("MVA4lBonn_weight_ttZ", &MVA4lBonn_weight_ttZ, &b_MVA4lBonn_weight_ttZ);
   fChain->SetBranchAddress("fourLep_PME", &fourLep_PME, &b_fourLep_PME);
   fChain->SetBranchAddress("MVA1l2tau_weight", &MVA1l2tau_weight, &b_MVA1l2tau_weight);
   fChain->SetBranchAddress("D_PME", &D_PME, &b_D_PME);
   fChain->SetBranchAddress("BDT_out", &BDT_out, &b_BDT_out);
   fChain->SetBranchAddress("mlb_h", &mlb_h, &b_mlb_h);
   fChain->SetBranchAddress("mOSl_h", &mOSl_h, &b_mOSl_h);
   fChain->SetBranchAddress("averageMW", &averageMW, &b_averageMW);
   fChain->SetBranchAddress("lepton_PromptLeptonIso_TagWeight", &lepton_PromptLeptonIso_TagWeight, &b_lepton_PromptLeptonIso_TagWeight);
   fChain->SetBranchAddress("lepton_ChargeIDBDTTight", &lepton_ChargeIDBDTTight, &b_lepton_ChargeIDBDTTight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_Fake", &CRB1_2lSStau_FF_Fake, &b_CRB1_2lSStau_FF_Fake);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_Prompt", &CRB1_2lSStau_FF_Prompt, &b_CRB1_2lSStau_FF_Prompt);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_Fake", &CRB2_2lSStau_FF_Fake, &b_CRB2_2lSStau_FF_Fake);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_RealTau", &CRB2_2lSStau_FF_RealTau, &b_CRB2_2lSStau_FF_RealTau);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_Fake", &CRB3_2lSStau_FF_Fake, &b_CRB3_2lSStau_FF_Fake);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_RealTau", &CRB3_2lSStau_FF_RealTau, &b_CRB3_2lSStau_FF_RealTau);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_Prompt", &CRB3_2lSStau_FF_Prompt, &b_CRB3_2lSStau_FF_Prompt);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_EventWeight", &CRB1_2lSStau_FF_EventWeight, &b_CRB1_2lSStau_FF_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin1Up_EventWeight", &CRB1_2lSStau_FF_elStat_Bin1Up_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin1Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin1Dn_EventWeight", &CRB1_2lSStau_FF_elStat_Bin1Dn_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin1Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin2Up_EventWeight", &CRB1_2lSStau_FF_elStat_Bin2Up_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin2Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin2Dn_EventWeight", &CRB1_2lSStau_FF_elStat_Bin2Dn_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin2Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin3Up_EventWeight", &CRB1_2lSStau_FF_elStat_Bin3Up_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin3Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin3Dn_EventWeight", &CRB1_2lSStau_FF_elStat_Bin3Dn_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin3Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin4Up_EventWeight", &CRB1_2lSStau_FF_elStat_Bin4Up_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin4Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin4Dn_EventWeight", &CRB1_2lSStau_FF_elStat_Bin4Dn_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin4Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin5Up_EventWeight", &CRB1_2lSStau_FF_elStat_Bin5Up_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin5Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_elStat_Bin5Dn_EventWeight", &CRB1_2lSStau_FF_elStat_Bin5Dn_EventWeight, &b_CRB1_2lSStau_FF_elStat_Bin5Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin1Up_EventWeight", &CRB1_2lSStau_FF_muStat_Bin1Up_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin1Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin1Dn_EventWeight", &CRB1_2lSStau_FF_muStat_Bin1Dn_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin1Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin2Up_EventWeight", &CRB1_2lSStau_FF_muStat_Bin2Up_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin2Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin2Dn_EventWeight", &CRB1_2lSStau_FF_muStat_Bin2Dn_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin2Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin3Up_EventWeight", &CRB1_2lSStau_FF_muStat_Bin3Up_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin3Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin3Dn_EventWeight", &CRB1_2lSStau_FF_muStat_Bin3Dn_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin3Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin4Up_EventWeight", &CRB1_2lSStau_FF_muStat_Bin4Up_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin4Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin4Dn_EventWeight", &CRB1_2lSStau_FF_muStat_Bin4Dn_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin4Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin5Up_EventWeight", &CRB1_2lSStau_FF_muStat_Bin5Up_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin5Up_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_muStat_Bin5Dn_EventWeight", &CRB1_2lSStau_FF_muStat_Bin5Dn_EventWeight, &b_CRB1_2lSStau_FF_muStat_Bin5Dn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_ttwUp_EventWeight", &CRB1_2lSStau_FF_ttwUp_EventWeight, &b_CRB1_2lSStau_FF_ttwUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_ttwDn_EventWeight", &CRB1_2lSStau_FF_ttwDn_EventWeight, &b_CRB1_2lSStau_FF_ttwDn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_ttzUp_EventWeight", &CRB1_2lSStau_FF_ttzUp_EventWeight, &b_CRB1_2lSStau_FF_ttzUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_ttzDn_EventWeight", &CRB1_2lSStau_FF_ttzDn_EventWeight, &b_CRB1_2lSStau_FF_ttzDn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_vvUp_EventWeight", &CRB1_2lSStau_FF_vvUp_EventWeight, &b_CRB1_2lSStau_FF_vvUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_vvDn_EventWeight", &CRB1_2lSStau_FF_vvDn_EventWeight, &b_CRB1_2lSStau_FF_vvDn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_rareUp_EventWeight", &CRB1_2lSStau_FF_rareUp_EventWeight, &b_CRB1_2lSStau_FF_rareUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_rareDn_EventWeight", &CRB1_2lSStau_FF_rareDn_EventWeight, &b_CRB1_2lSStau_FF_rareDn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_tthUp_EventWeight", &CRB1_2lSStau_FF_tthUp_EventWeight, &b_CRB1_2lSStau_FF_tthUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_tthDn_EventWeight", &CRB1_2lSStau_FF_tthDn_EventWeight, &b_CRB1_2lSStau_FF_tthDn_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_QMisIdUp_EventWeight", &CRB1_2lSStau_FF_QMisIdUp_EventWeight, &b_CRB1_2lSStau_FF_QMisIdUp_EventWeight);
   fChain->SetBranchAddress("CRB1_2lSStau_FF_QMisIdDn_EventWeight", &CRB1_2lSStau_FF_QMisIdDn_EventWeight, &b_CRB1_2lSStau_FF_QMisIdDn_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_EventWeight", &CRB2_2lSStau_FF_EventWeight, &b_CRB2_2lSStau_FF_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_RealtauUp_EventWeight", &CRB2_2lSStau_FF_RealtauUp_EventWeight, &b_CRB2_2lSStau_FF_RealtauUp_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_RealtauDn_EventWeight", &CRB2_2lSStau_FF_RealtauDn_EventWeight, &b_CRB2_2lSStau_FF_RealtauDn_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_tthUp_EventWeight", &CRB2_2lSStau_FF_tthUp_EventWeight, &b_CRB2_2lSStau_FF_tthUp_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_tthDn_EventWeight", &CRB2_2lSStau_FF_tthDn_EventWeight, &b_CRB2_2lSStau_FF_tthDn_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_QMisIdUp_EventWeight", &CRB2_2lSStau_FF_QMisIdUp_EventWeight, &b_CRB2_2lSStau_FF_QMisIdUp_EventWeight);
   fChain->SetBranchAddress("CRB2_2lSStau_FF_QMisIdDn_EventWeight", &CRB2_2lSStau_FF_QMisIdDn_EventWeight, &b_CRB2_2lSStau_FF_QMisIdDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_EventWeight", &CRB3_2lSStau_FF_EventWeight, &b_CRB3_2lSStau_FF_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_RealtauUp_EventWeight", &CRB3_2lSStau_FF_RealtauUp_EventWeight, &b_CRB3_2lSStau_FF_RealtauUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_RealtauDn_EventWeight", &CRB3_2lSStau_FF_RealtauDn_EventWeight, &b_CRB3_2lSStau_FF_RealtauDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_ttwUp_EventWeight", &CRB3_2lSStau_FF_ttwUp_EventWeight, &b_CRB3_2lSStau_FF_ttwUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_ttwDn_EventWeight", &CRB3_2lSStau_FF_ttwDn_EventWeight, &b_CRB3_2lSStau_FF_ttwDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_ttzUp_EventWeight", &CRB3_2lSStau_FF_ttzUp_EventWeight, &b_CRB3_2lSStau_FF_ttzUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_ttzDn_EventWeight", &CRB3_2lSStau_FF_ttzDn_EventWeight, &b_CRB3_2lSStau_FF_ttzDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_vvUp_EventWeight", &CRB3_2lSStau_FF_vvUp_EventWeight, &b_CRB3_2lSStau_FF_vvUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_vvDn_EventWeight", &CRB3_2lSStau_FF_vvDn_EventWeight, &b_CRB3_2lSStau_FF_vvDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_rareUp_EventWeight", &CRB3_2lSStau_FF_rareUp_EventWeight, &b_CRB3_2lSStau_FF_rareUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_rareDn_EventWeight", &CRB3_2lSStau_FF_rareDn_EventWeight, &b_CRB3_2lSStau_FF_rareDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_tthUp_EventWeight", &CRB3_2lSStau_FF_tthUp_EventWeight, &b_CRB3_2lSStau_FF_tthUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_tthDn_EventWeight", &CRB3_2lSStau_FF_tthDn_EventWeight, &b_CRB3_2lSStau_FF_tthDn_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_QMisIdUp_EventWeight", &CRB3_2lSStau_FF_QMisIdUp_EventWeight, &b_CRB3_2lSStau_FF_QMisIdUp_EventWeight);
   fChain->SetBranchAddress("CRB3_2lSStau_FF_QMisIdDn_EventWeight", &CRB3_2lSStau_FF_QMisIdDn_EventWeight, &b_CRB3_2lSStau_FF_QMisIdDn_EventWeight);
   fChain->SetBranchAddress("isttH", &isttH, &b_isttH);
   fChain->SetBranchAddress("isttZ", &isttZ, &b_isttZ);
   fChain->SetBranchAddress("isttW", &isttW, &b_isttW);
   fChain->SetBranchAddress("isVV", &isVV, &b_isVV);
   fChain->SetBranchAddress("istZ", &istZ, &b_istZ);
   fChain->SetBranchAddress("isWtZ", &isWtZ, &b_isWtZ);
   fChain->SetBranchAddress("istHjb", &istHjb, &b_istHjb);
   fChain->SetBranchAddress("isWtH", &isWtH, &b_isWtH);
   fChain->SetBranchAddress("isttWW", &isttWW, &b_isttWW);
   fChain->SetBranchAddress("isVH", &isVH, &b_isVH);
   fChain->SetBranchAddress("isVVV", &isVVV, &b_isVVV);
   fChain->SetBranchAddress("is3Tops", &is3Tops, &b_is3Tops);
   fChain->SetBranchAddress("is4Tops", &is4Tops, &b_is4Tops);
   fChain->SetBranchAddress("isttbar", &isttbar, &b_isttbar);
   fChain->SetBranchAddress("isttll", &isttll, &b_isttll);
   fChain->SetBranchAddress("israreTop", &israreTop, &b_israreTop);
   fChain->SetBranchAddress("isttGamma", &isttGamma, &b_isttGamma);
   fChain->SetBranchAddress("isttbarDilep", &isttbarDilep, &b_isttbarDilep);
   fChain->SetBranchAddress("passTrigger", &passTrigger, &b_passTrigger);
   fChain->SetBranchAddress("scale_nom", &scale_nom, &b_scale_nom);
   fChain->SetBranchAddress("scale_varA14up", &scale_varA14up, &b_scale_varA14up);
   fChain->SetBranchAddress("scale_varA14down", &scale_varA14down, &b_scale_varA14down);
   fChain->SetBranchAddress("scale_varRup", &scale_varRup, &b_scale_varRup);
   fChain->SetBranchAddress("scale_varRdown", &scale_varRdown, &b_scale_varRdown);
   fChain->SetBranchAddress("scale_varFup", &scale_varFup, &b_scale_varFup);
   fChain->SetBranchAddress("scale_varFdown", &scale_varFdown, &b_scale_varFdown);
   fChain->SetBranchAddress("scale_varRFup", &scale_varRFup, &b_scale_varRFup);
   fChain->SetBranchAddress("scale_varRFdown", &scale_varRFdown, &b_scale_varRFdown);
   fChain->SetBranchAddress("pileupEventWeight_UP", &pileupEventWeight_UP, &b_pileupEventWeight_UP);
   fChain->SetBranchAddress("pileupEventWeight_DOWN", &pileupEventWeight_DOWN, &b_pileupEventWeight_DOWN);
   fChain->SetBranchAddress("JVT_EventWeight_UP", &JVT_EventWeight_UP, &b_JVT_EventWeight_UP);
   fChain->SetBranchAddress("JVT_EventWeight_DOWN", &JVT_EventWeight_DOWN, &b_JVT_EventWeight_DOWN);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70", &bTagSF_weight_MV2c10_FixedCutBEff_70, &b_bTagSF_weight_MV2c10_FixedCutBEff_70);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up);
   fChain->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_SYST_UP", &lepSFTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepSFTrigLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_UP", &lepSFTrigTight_MU_SF_Trigger_SYST_UP, &b_lepSFTrigTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_SYST_UP", &lepSFTrigTightLoose_MU_SF_Trigger_SYST_UP, &b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_SYST_UP", &lepSFTrigLooseTight_MU_SF_Trigger_SYST_UP, &b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_SYST_UP", &lepEffTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepEffTrigLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_SYST_UP", &lepEffTrigTight_MU_SF_Trigger_SYST_UP, &b_lepEffTrigTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP", &lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP, &b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP", &lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP, &b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP", &lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_SYST_UP", &lepDataEffTrigTight_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP", &lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP", &lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_SYST_DOWN", &lepEffTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_UP", &lepSFTrigLoose_EL_SF_Trigger_UP, &b_lepSFTrigLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_UP", &lepSFTrigTight_EL_SF_Trigger_UP, &b_lepSFTrigTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTightLoose_EL_SF_Trigger_UP", &lepSFTrigTightLoose_EL_SF_Trigger_UP, &b_lepSFTrigTightLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigLooseTight_EL_SF_Trigger_UP", &lepSFTrigLooseTight_EL_SF_Trigger_UP, &b_lepSFTrigLooseTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigLoose_EL_SF_Trigger_UP", &lepEffTrigLoose_EL_SF_Trigger_UP, &b_lepEffTrigLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigTight_EL_SF_Trigger_UP", &lepEffTrigTight_EL_SF_Trigger_UP, &b_lepEffTrigTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigTightLoose_EL_SF_Trigger_UP", &lepEffTrigTightLoose_EL_SF_Trigger_UP, &b_lepEffTrigTightLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigLooseTight_EL_SF_Trigger_UP", &lepEffTrigLooseTight_EL_SF_Trigger_UP, &b_lepEffTrigLooseTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigLoose_EL_SF_Trigger_UP", &lepDataEffTrigLoose_EL_SF_Trigger_UP, &b_lepDataEffTrigLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigTight_EL_SF_Trigger_UP", &lepDataEffTrigTight_EL_SF_Trigger_UP, &b_lepDataEffTrigTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_EL_SF_Trigger_UP", &lepDataEffTrigTightLoose_EL_SF_Trigger_UP, &b_lepDataEffTrigTightLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_EL_SF_Trigger_UP", &lepDataEffTrigLooseTight_EL_SF_Trigger_UP, &b_lepDataEffTrigLooseTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_DOWN", &lepSFTrigLoose_EL_SF_Trigger_DOWN, &b_lepSFTrigLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_DOWN", &lepSFTrigTight_EL_SF_Trigger_DOWN, &b_lepSFTrigTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigTightLoose_EL_SF_Trigger_DOWN", &lepSFTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepSFTrigTightLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigLooseTight_EL_SF_Trigger_DOWN", &lepSFTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepSFTrigLooseTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigLoose_EL_SF_Trigger_DOWN", &lepEffTrigLoose_EL_SF_Trigger_DOWN, &b_lepEffTrigLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigTight_EL_SF_Trigger_DOWN", &lepEffTrigTight_EL_SF_Trigger_DOWN, &b_lepEffTrigTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigTightLoose_EL_SF_Trigger_DOWN", &lepEffTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepEffTrigTightLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigLooseTight_EL_SF_Trigger_DOWN", &lepEffTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepEffTrigLooseTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLoose_EL_SF_Trigger_DOWN", &lepDataEffTrigLoose_EL_SF_Trigger_DOWN, &b_lepDataEffTrigLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTight_EL_SF_Trigger_DOWN", &lepDataEffTrigTight_EL_SF_Trigger_DOWN, &b_lepDataEffTrigTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN", &lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN", &lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_UP", &lepSFTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_UP", &lepSFTrigTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_STAT_UP", &lepEffTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepEffTrigLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_STAT_UP", &lepEffTrigTight_MU_SF_Trigger_STAT_UP, &b_lepEffTrigTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP", &lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_STAT_UP", &lepDataEffTrigTight_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_STAT_DOWN", &lepEffTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN", &lepEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN", &lepEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_EFF_Trigger_UP", &lepSFTrigLoose_EL_EFF_Trigger_UP, &b_lepSFTrigLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTight_EL_EFF_Trigger_UP", &lepSFTrigTight_EL_EFF_Trigger_UP, &b_lepSFTrigTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTightLoose_EL_EFF_Trigger_UP", &lepSFTrigTightLoose_EL_EFF_Trigger_UP, &b_lepSFTrigTightLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigLooseTight_EL_EFF_Trigger_UP", &lepSFTrigLooseTight_EL_EFF_Trigger_UP, &b_lepSFTrigLooseTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigLoose_EL_EFF_Trigger_UP", &lepEffTrigLoose_EL_EFF_Trigger_UP, &b_lepEffTrigLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigTight_EL_EFF_Trigger_UP", &lepEffTrigTight_EL_EFF_Trigger_UP, &b_lepEffTrigTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigTightLoose_EL_EFF_Trigger_UP", &lepEffTrigTightLoose_EL_EFF_Trigger_UP, &b_lepEffTrigTightLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepEffTrigLooseTight_EL_EFF_Trigger_UP", &lepEffTrigLooseTight_EL_EFF_Trigger_UP, &b_lepEffTrigLooseTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigLoose_EL_EFF_Trigger_UP", &lepDataEffTrigLoose_EL_EFF_Trigger_UP, &b_lepDataEffTrigLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigTight_EL_EFF_Trigger_UP", &lepDataEffTrigTight_EL_EFF_Trigger_UP, &b_lepDataEffTrigTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_EL_EFF_Trigger_UP", &lepDataEffTrigTightLoose_EL_EFF_Trigger_UP, &b_lepDataEffTrigTightLoose_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_EL_EFF_Trigger_UP", &lepDataEffTrigLooseTight_EL_EFF_Trigger_UP, &b_lepDataEffTrigLooseTight_EL_EFF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_EFF_Trigger_DOWN", &lepSFTrigLoose_EL_EFF_Trigger_DOWN, &b_lepSFTrigLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_EL_EFF_Trigger_DOWN", &lepSFTrigTight_EL_EFF_Trigger_DOWN, &b_lepSFTrigTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigTightLoose_EL_EFF_Trigger_DOWN", &lepSFTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepSFTrigTightLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigLooseTight_EL_EFF_Trigger_DOWN", &lepSFTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepSFTrigLooseTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigLoose_EL_EFF_Trigger_DOWN", &lepEffTrigLoose_EL_EFF_Trigger_DOWN, &b_lepEffTrigLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigTight_EL_EFF_Trigger_DOWN", &lepEffTrigTight_EL_EFF_Trigger_DOWN, &b_lepEffTrigTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigTightLoose_EL_EFF_Trigger_DOWN", &lepEffTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepEffTrigTightLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepEffTrigLooseTight_EL_EFF_Trigger_DOWN", &lepEffTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepEffTrigLooseTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLoose_EL_EFF_Trigger_DOWN", &lepDataEffTrigLoose_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTight_EL_EFF_Trigger_DOWN", &lepDataEffTrigTight_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN", &lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN", &lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_UP", &lepSFObjLoose_EL_SF_Reco_UP, &b_lepSFObjLoose_EL_SF_Reco_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_UP", &lepSFObjTight_EL_SF_Reco_UP, &b_lepSFObjTight_EL_SF_Reco_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_DOWN", &lepSFObjLoose_EL_SF_Reco_DOWN, &b_lepSFObjLoose_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_DOWN", &lepSFObjTight_EL_SF_Reco_DOWN, &b_lepSFObjTight_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_ID_UP", &lepSFObjLoose_EL_SF_ID_UP, &b_lepSFObjLoose_EL_SF_ID_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_UP", &lepSFObjTight_EL_SF_ID_UP, &b_lepSFObjTight_EL_SF_ID_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_ID_DOWN", &lepSFObjLoose_EL_SF_ID_DOWN, &b_lepSFObjLoose_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_DOWN", &lepSFObjTight_EL_SF_ID_DOWN, &b_lepSFObjTight_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_UP", &lepSFObjLoose_EL_SF_Isol_UP, &b_lepSFObjLoose_EL_SF_Isol_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_UP", &lepSFObjTight_EL_SF_Isol_UP, &b_lepSFObjTight_EL_SF_Isol_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_DOWN", &lepSFObjLoose_EL_SF_Isol_DOWN, &b_lepSFObjLoose_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_DOWN", &lepSFObjTight_EL_SF_Isol_DOWN, &b_lepSFObjTight_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_UP", &lepSFObjLoose_MU_SF_ID_STAT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_UP", &lepSFObjTight_MU_SF_ID_STAT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_UP", &lepSFObjLoose_MU_SF_ID_SYST_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_UP", &lepSFObjTight_MU_SF_ID_SYST_UP, &b_lepSFObjTight_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_DOWN", &lepSFObjTight_MU_SF_ID_SYST_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_UP", &lepSFObjLoose_MU_SF_Isol_STAT_UP, &b_lepSFObjLoose_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_UP", &lepSFObjTight_MU_SF_Isol_STAT_UP, &b_lepSFObjTight_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_DOWN", &lepSFObjLoose_MU_SF_Isol_STAT_DOWN, &b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_DOWN", &lepSFObjTight_MU_SF_Isol_STAT_DOWN, &b_lepSFObjTight_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_UP", &lepSFObjLoose_MU_SF_Isol_SYST_UP, &b_lepSFObjLoose_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_UP", &lepSFObjTight_MU_SF_Isol_SYST_UP, &b_lepSFObjTight_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_DOWN", &lepSFObjLoose_MU_SF_Isol_SYST_DOWN, &b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_DOWN", &lepSFObjTight_MU_SF_Isol_SYST_DOWN, &b_lepSFObjTight_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_UP", &lepSFObjLoose_MU_SF_TTVA_STAT_UP, &b_lepSFObjLoose_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_UP", &lepSFObjTight_MU_SF_TTVA_STAT_UP, &b_lepSFObjTight_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_DOWN", &lepSFObjLoose_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_DOWN", &lepSFObjTight_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_UP", &lepSFObjLoose_MU_SF_TTVA_SYST_UP, &b_lepSFObjLoose_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_UP", &lepSFObjTight_MU_SF_TTVA_SYST_UP, &b_lepSFObjTight_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_DOWN", &lepSFObjLoose_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_DOWN", &lepSFObjTight_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_ELEOLR_TOTAL_UP", &tauSFTight_TAU_SF_ELEOLR_TOTAL_UP, &b_tauSFTight_TAU_SF_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP", &tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP, &b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN", &tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN, &b_tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN", &tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_JETID_TOTAL_UP", &tauSFTight_TAU_SF_JETID_TOTAL_UP, &b_tauSFTight_TAU_SF_JETID_TOTAL_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_JETID_TOTAL_UP", &tauSFLoose_TAU_SF_JETID_TOTAL_UP, &b_tauSFLoose_TAU_SF_JETID_TOTAL_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_JETID_TOTAL_DOWN", &tauSFTight_TAU_SF_JETID_TOTAL_DOWN, &b_tauSFTight_TAU_SF_JETID_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_JETID_TOTAL_DOWN", &tauSFLoose_TAU_SF_JETID_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_JETID_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_RECO_TOTAL_UP", &tauSFTight_TAU_SF_RECO_TOTAL_UP, &b_tauSFTight_TAU_SF_RECO_TOTAL_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_RECO_TOTAL_UP", &tauSFLoose_TAU_SF_RECO_TOTAL_UP, &b_tauSFLoose_TAU_SF_RECO_TOTAL_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_RECO_TOTAL_DOWN", &tauSFTight_TAU_SF_RECO_TOTAL_DOWN, &b_tauSFTight_TAU_SF_RECO_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_RECO_TOTAL_DOWN", &tauSFLoose_TAU_SF_RECO_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_RECO_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_JETID_HIGHPT_UP", &tauSFTight_TAU_SF_JETID_HIGHPT_UP, &b_tauSFTight_TAU_SF_JETID_HIGHPT_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_JETID_HIGHPT_UP", &tauSFLoose_TAU_SF_JETID_HIGHPT_UP, &b_tauSFLoose_TAU_SF_JETID_HIGHPT_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_JETID_HIGHPT_DOWN", &tauSFTight_TAU_SF_JETID_HIGHPT_DOWN, &b_tauSFTight_TAU_SF_JETID_HIGHPT_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN", &tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN, &b_tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_RECO_HIGHPT_UP", &tauSFTight_TAU_SF_RECO_HIGHPT_UP, &b_tauSFTight_TAU_SF_RECO_HIGHPT_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_RECO_HIGHPT_UP", &tauSFLoose_TAU_SF_RECO_HIGHPT_UP, &b_tauSFLoose_TAU_SF_RECO_HIGHPT_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_RECO_HIGHPT_DOWN", &tauSFTight_TAU_SF_RECO_HIGHPT_DOWN, &b_tauSFTight_TAU_SF_RECO_HIGHPT_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN", &tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN, &b_tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP", &tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP, &b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP", &tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP, &b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN", &tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, &b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN", &tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("forFit_promptSel", &forFit_promptSel, &b_forFit_promptSel);
   fChain->SetBranchAddress("forFit_tightSel", &forFit_tightSel, &b_forFit_tightSel);
   fChain->SetBranchAddress("forFit_3l0tauBaseLine", &forFit_3l0tauBaseLine, &b_forFit_3l0tauBaseLine);
   fChain->SetBranchAddress("forFit_3l0tauFakesSel", &forFit_3l0tauFakesSel, &b_forFit_3l0tauFakesSel);
   fChain->SetBranchAddress("forFit_2lss0tauBaseLine", &forFit_2lss0tauBaseLine, &b_forFit_2lss0tauBaseLine);
   fChain->SetBranchAddress("forFit_2lssFakeQmisSel", &forFit_2lssFakeQmisSel, &b_forFit_2lssFakeQmisSel);
   fChain->SetBranchAddress("mcWeightOrg", &mcWeightOrg, &b_mcWeightOrg);
   fChain->SetBranchAddress("pileupEventWeight_090", &pileupEventWeight_090, &b_pileupEventWeight_090);
   fChain->SetBranchAddress("MV2c10_60_EventWeight", &MV2c10_60_EventWeight, &b_MV2c10_60_EventWeight);
   fChain->SetBranchAddress("MV2c10_70_EventWeight", &MV2c10_70_EventWeight, &b_MV2c10_70_EventWeight);
   fChain->SetBranchAddress("MV2c10_77_EventWeight", &MV2c10_77_EventWeight, &b_MV2c10_77_EventWeight);
   fChain->SetBranchAddress("MV2c10_85_EventWeight", &MV2c10_85_EventWeight, &b_MV2c10_85_EventWeight);
   fChain->SetBranchAddress("MV2c10_Continuous_EventWeight", &MV2c10_Continuous_EventWeight, &b_MV2c10_Continuous_EventWeight);
   fChain->SetBranchAddress("bTagSF_weight_Continuous", &bTagSF_weight_Continuous, &b_bTagSF_weight_Continuous);
   fChain->SetBranchAddress("JVT_EventWeight", &JVT_EventWeight, &b_JVT_EventWeight);
   fChain->SetBranchAddress("SherpaNJetWeight", &SherpaNJetWeight, &b_SherpaNJetWeight);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("passEventCleaning", &passEventCleaning, &b_passEventCleaning);
   fChain->SetBranchAddress("m_vxp_x", &m_vxp_x, &b_m_vxp_x);
   fChain->SetBranchAddress("m_vxp_y", &m_vxp_y, &b_m_vxp_y);
   fChain->SetBranchAddress("m_vxp_z", &m_vxp_z, &b_m_vxp_z);
   fChain->SetBranchAddress("higgs_pt", &higgs_pt, &b_higgs_pt);
   fChain->SetBranchAddress("higgs_eta", &higgs_eta, &b_higgs_eta);
   fChain->SetBranchAddress("higgs_phi", &higgs_phi, &b_higgs_phi);
   fChain->SetBranchAddress("higgs_E", &higgs_E, &b_higgs_E);
   fChain->SetBranchAddress("higgs_rapidity", &higgs_rapidity, &b_higgs_rapidity);
   fChain->SetBranchAddress("top_pt", &top_pt, &b_top_pt);
   fChain->SetBranchAddress("top_eta", &top_eta, &b_top_eta);
   fChain->SetBranchAddress("top_phi", &top_phi, &b_top_phi);
   fChain->SetBranchAddress("top_E", &top_E, &b_top_E);
   fChain->SetBranchAddress("antitop_pt", &antitop_pt, &b_antitop_pt);
   fChain->SetBranchAddress("antitop_eta", &antitop_eta, &b_antitop_eta);
   fChain->SetBranchAddress("antitop_phi", &antitop_phi, &b_antitop_phi);
   fChain->SetBranchAddress("antitop_E", &antitop_E, &b_antitop_E);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("HF_Classification", &HF_Classification, &b_HF_Classification);
   fChain->SetBranchAddress("HF_ClassificationTop", &HF_ClassificationTop, &b_HF_ClassificationTop);
   fChain->SetBranchAddress("DLF_Classification", &DLF_Classification, &b_DLF_Classification);
   fChain->SetBranchAddress("higgsDecayMode", &higgsDecayMode, &b_higgsDecayMode);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("mc_isAFII", &mc_isAFII, &b_mc_isAFII);
   fChain->SetBranchAddress("averageIntPerXing_uncorr", &averageIntPerXing_uncorr, &b_averageIntPerXing_uncorr);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   fChain->SetBranchAddress("m_vxp_n", &m_vxp_n, &b_m_vxp_n);
   fChain->SetBranchAddress("m_vxpu_n", &m_vxpu_n, &b_m_vxpu_n);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
   fChain->SetBranchAddress("m_hasMEphoton", &m_hasMEphoton, &b_m_hasMEphoton);
   fChain->SetBranchAddress("m_hasMEphoton_DRgt02_nonhad", &m_hasMEphoton_DRgt02_nonhad, &b_m_hasMEphoton_DRgt02_nonhad);
   fChain->SetBranchAddress("m_MEphoton_OLtty_keepEvent", &m_MEphoton_OLtty_keepEvent, &b_m_MEphoton_OLtty_keepEvent);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat1", &m_MEphoton_OLtty_cat1, &b_m_MEphoton_OLtty_cat1);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat2", &m_MEphoton_OLtty_cat2, &b_m_MEphoton_OLtty_cat2);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat3", &m_MEphoton_OLtty_cat3, &b_m_MEphoton_OLtty_cat3);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat4", &m_MEphoton_OLtty_cat4, &b_m_MEphoton_OLtty_cat4);
   fChain->SetBranchAddress("m_MEphoton_pt", &m_MEphoton_pt, &b_m_MEphoton_pt);
   fChain->SetBranchAddress("m_MEphoton_eta", &m_MEphoton_eta, &b_m_MEphoton_eta);
   fChain->SetBranchAddress("m_MEphoton_phi", &m_MEphoton_phi, &b_m_MEphoton_phi);
   fChain->SetBranchAddress("m_MEphoton_mother_pt", &m_MEphoton_mother_pt, &b_m_MEphoton_mother_pt);
   fChain->SetBranchAddress("m_MEphoton_mother_eta", &m_MEphoton_mother_eta, &b_m_MEphoton_mother_eta);
   fChain->SetBranchAddress("m_MEphoton_mother_phi", &m_MEphoton_mother_phi, &b_m_MEphoton_mother_phi);
   fChain->SetBranchAddress("m_MEphoton_mother_pdgId", &m_MEphoton_mother_pdgId, &b_m_MEphoton_mother_pdgId);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH, &b_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_2e12_lhvloose_nod0_L12EM10VH", &HLT_2e12_lhvloose_nod0_L12EM10VH, &b_HLT_2e12_lhvloose_nod0_L12EM10VH);
   fChain->SetBranchAddress("HLT_2e17_lhvloose_nod0", &HLT_2e17_lhvloose_nod0, &b_HLT_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_2e24_lhvloose_nod0", &HLT_2e24_lhvloose_nod0, &b_HLT_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose", &HLT_e140_lhloose, &b_HLT_e140_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM18VH", &HLT_e24_lhmedium_L1EM18VH, &b_HLT_e24_lhmedium_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_nod0_L1EM20VH", &HLT_e24_lhmedium_nod0_L1EM20VH, &b_HLT_e24_lhmedium_nod0_L1EM20VH);
   fChain->SetBranchAddress("HLT_e26_lhtight_iloose", &HLT_e26_lhtight_iloose, &b_HLT_e26_lhtight_iloose);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_e60_medium", &HLT_e60_medium, &b_HLT_e60_medium);
   fChain->SetBranchAddress("HLT_e7_lhmedium_mu24", &HLT_e7_lhmedium_mu24, &b_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("HLT_e7_medium_mu24", &HLT_e7_medium_mu24, &b_HLT_e7_medium_mu24);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_mu8noL1", &HLT_mu20_mu8noL1, &b_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("HLT_mu24_imedium", &HLT_mu24_imedium, &b_HLT_mu24_imedium);
   fChain->SetBranchAddress("HLT_mu24_ivarloose", &HLT_mu24_ivarloose, &b_HLT_mu24_ivarloose);
   fChain->SetBranchAddress("HLT_mu24_ivarmedium", &HLT_mu24_ivarmedium, &b_HLT_mu24_ivarmedium);
   fChain->SetBranchAddress("HLT_mu26_imedium", &HLT_mu26_imedium, &b_HLT_mu26_imedium);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_2e17_lhvloose_nod0_L12EM15VHI", &HLT_2e17_lhvloose_nod0_L12EM15VHI, &b_HLT_2e17_lhvloose_nod0_L12EM15VHI);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_0", &lep_promptLeptonInput_sv1_jf_ntrkv_0, &b_lep_promptLeptonInput_sv1_jf_ntrkv_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_1", &lep_promptLeptonInput_sv1_jf_ntrkv_1, &b_lep_promptLeptonInput_sv1_jf_ntrkv_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_2", &lep_promptLeptonInput_sv1_jf_ntrkv_2, &b_lep_promptLeptonInput_sv1_jf_ntrkv_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_0", &lep_promptLeptonInput_TrackJetNTrack_0, &b_lep_promptLeptonInput_TrackJetNTrack_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_1", &lep_promptLeptonInput_TrackJetNTrack_1, &b_lep_promptLeptonInput_TrackJetNTrack_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_2", &lep_promptLeptonInput_TrackJetNTrack_2, &b_lep_promptLeptonInput_TrackJetNTrack_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_0", &lep_promptLeptonInput_DL1mu_0, &b_lep_promptLeptonInput_DL1mu_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_1", &lep_promptLeptonInput_DL1mu_1, &b_lep_promptLeptonInput_DL1mu_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_2", &lep_promptLeptonInput_DL1mu_2, &b_lep_promptLeptonInput_DL1mu_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_0", &lep_promptLeptonInput_DRlj_0, &b_lep_promptLeptonInput_DRlj_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_1", &lep_promptLeptonInput_DRlj_1, &b_lep_promptLeptonInput_DRlj_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_2", &lep_promptLeptonInput_DRlj_2, &b_lep_promptLeptonInput_DRlj_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_0", &lep_promptLeptonInput_LepJetPtFrac_0, &b_lep_promptLeptonInput_LepJetPtFrac_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_1", &lep_promptLeptonInput_LepJetPtFrac_1, &b_lep_promptLeptonInput_LepJetPtFrac_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_2", &lep_promptLeptonInput_LepJetPtFrac_2, &b_lep_promptLeptonInput_LepJetPtFrac_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_0", &lep_promptLeptonInput_PtFrac_0, &b_lep_promptLeptonInput_PtFrac_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_1", &lep_promptLeptonInput_PtFrac_1, &b_lep_promptLeptonInput_PtFrac_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_2", &lep_promptLeptonInput_PtFrac_2, &b_lep_promptLeptonInput_PtFrac_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_0", &lep_promptLeptonInput_PtRel_0, &b_lep_promptLeptonInput_PtRel_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_1", &lep_promptLeptonInput_PtRel_1, &b_lep_promptLeptonInput_PtRel_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_2", &lep_promptLeptonInput_PtRel_2, &b_lep_promptLeptonInput_PtRel_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_0", &lep_promptLeptonInput_ip2_0, &b_lep_promptLeptonInput_ip2_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_1", &lep_promptLeptonInput_ip2_1, &b_lep_promptLeptonInput_ip2_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_2", &lep_promptLeptonInput_ip2_2, &b_lep_promptLeptonInput_ip2_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_0", &lep_promptLeptonInput_ip3_0, &b_lep_promptLeptonInput_ip3_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_1", &lep_promptLeptonInput_ip3_1, &b_lep_promptLeptonInput_ip3_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_2", &lep_promptLeptonInput_ip3_2, &b_lep_promptLeptonInput_ip3_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_0", &lep_promptLeptonInput_rnnip_0, &b_lep_promptLeptonInput_rnnip_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_1", &lep_promptLeptonInput_rnnip_1, &b_lep_promptLeptonInput_rnnip_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_2", &lep_promptLeptonInput_rnnip_2, &b_lep_promptLeptonInput_rnnip_2);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Index_0", &lep_Index_0, &b_lep_Index_0);
   fChain->SetBranchAddress("lep_ambiguityType_0", &lep_ambiguityType_0, &b_lep_ambiguityType_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   fChain->SetBranchAddress("lep_topoEtcone20_0", &lep_topoEtcone20_0, &b_lep_topoEtcone20_0);
   fChain->SetBranchAddress("lep_topoEtcone30_0", &lep_topoEtcone30_0, &b_lep_topoEtcone30_0);
   fChain->SetBranchAddress("lep_topoEtcone40_0", &lep_topoEtcone40_0, &b_lep_topoEtcone40_0);
   fChain->SetBranchAddress("lep_ptVarcone20_0", &lep_ptVarcone20_0, &b_lep_ptVarcone20_0);
   fChain->SetBranchAddress("lep_ptVarcone30_0", &lep_ptVarcone30_0, &b_lep_ptVarcone30_0);
   fChain->SetBranchAddress("lep_ptVarcone40_0", &lep_ptVarcone40_0, &b_lep_ptVarcone40_0);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   fChain->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   fChain->SetBranchAddress("lep_vz_0", &lep_vz_0, &b_lep_vz_0);
   fChain->SetBranchAddress("lep_deltaz0_0", &lep_deltaz0_0, &b_lep_deltaz0_0);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_0", &lep_isolationLooseTrackOnly_0, &b_lep_isolationLooseTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationLoose_0", &lep_isolationLoose_0, &b_lep_isolationLoose_0);
   fChain->SetBranchAddress("lep_isolationGradient_0", &lep_isolationGradient_0, &b_lep_isolationGradient_0);
   fChain->SetBranchAddress("lep_isolationGradientLoose_0", &lep_isolationGradientLoose_0, &b_lep_isolationGradientLoose_0);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_0", &lep_isolationFixedCutTight_0, &b_lep_isolationFixedCutTight_0);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_0", &lep_isolationFixedCutTightTrackOnly_0, &b_lep_isolationFixedCutTightTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_0", &lep_isolationFixedCutLoose_0, &b_lep_isolationFixedCutLoose_0);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
   fChain->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   fChain->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   fChain->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
   fChain->SetBranchAddress("lep_isIntConvPh_0", &lep_isIntConvPh_0, &b_lep_isIntConvPh_0);
   fChain->SetBranchAddress("lep_isExtConvPh_0", &lep_isExtConvPh_0, &b_lep_isExtConvPh_0);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   fChain->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   fChain->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   fChain->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   fChain->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   fChain->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   fChain->SetBranchAddress("lep_truthPt_0", &lep_truthPt_0, &b_lep_truthPt_0);
   fChain->SetBranchAddress("lep_truthEta_0", &lep_truthEta_0, &b_lep_truthEta_0);
   fChain->SetBranchAddress("lep_truthPhi_0", &lep_truthPhi_0, &b_lep_truthPhi_0);
   fChain->SetBranchAddress("lep_truthM_0", &lep_truthM_0, &b_lep_truthM_0);
   fChain->SetBranchAddress("lep_truthE_0", &lep_truthE_0, &b_lep_truthE_0);
   fChain->SetBranchAddress("lep_truthRapidity_0", &lep_truthRapidity_0, &b_lep_truthRapidity_0);
   fChain->SetBranchAddress("lep_SFIDLoose_0", &lep_SFIDLoose_0, &b_lep_SFIDLoose_0);
   fChain->SetBranchAddress("lep_SFIDTight_0", &lep_SFIDTight_0, &b_lep_SFIDTight_0);
   fChain->SetBranchAddress("lep_SFTrigLoose_0", &lep_SFTrigLoose_0, &b_lep_SFTrigLoose_0);
   fChain->SetBranchAddress("lep_SFTrigTight_0", &lep_SFTrigTight_0, &b_lep_SFTrigTight_0);
   fChain->SetBranchAddress("lep_EffTrigLoose_0", &lep_EffTrigLoose_0, &b_lep_EffTrigLoose_0);
   fChain->SetBranchAddress("lep_EffTrigTight_0", &lep_EffTrigTight_0, &b_lep_EffTrigTight_0);
   fChain->SetBranchAddress("lep_SFIsoLoose_0", &lep_SFIsoLoose_0, &b_lep_SFIsoLoose_0);
   fChain->SetBranchAddress("lep_SFIsoTight_0", &lep_SFIsoTight_0, &b_lep_SFIsoTight_0);
   fChain->SetBranchAddress("lep_SFReco_0", &lep_SFReco_0, &b_lep_SFReco_0);
   fChain->SetBranchAddress("lep_SFTTVA_0", &lep_SFTTVA_0, &b_lep_SFTTVA_0);
   fChain->SetBranchAddress("lep_SFObjLoose_0", &lep_SFObjLoose_0, &b_lep_SFObjLoose_0);
   fChain->SetBranchAddress("lep_SFObjTight_0", &lep_SFObjTight_0, &b_lep_SFObjTight_0);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_0", &lep_chargeIDBDTLoose_0, &b_lep_chargeIDBDTLoose_0);
   fChain->SetBranchAddress("lep_chargeIDBDTMedium_0", &lep_chargeIDBDTMedium_0, &b_lep_chargeIDBDTMedium_0);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_0", &lep_chargeIDBDTTight_0, &b_lep_chargeIDBDTTight_0);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_0", &lep_promptLeptonIso_TagWeight_0, &b_lep_promptLeptonIso_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_0", &lep_promptLeptonVeto_TagWeight_0, &b_lep_promptLeptonVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_Index_1", &lep_Index_1, &b_lep_Index_1);
   fChain->SetBranchAddress("lep_ambiguityType_1", &lep_ambiguityType_1, &b_lep_ambiguityType_1);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   fChain->SetBranchAddress("lep_topoEtcone20_1", &lep_topoEtcone20_1, &b_lep_topoEtcone20_1);
   fChain->SetBranchAddress("lep_topoEtcone30_1", &lep_topoEtcone30_1, &b_lep_topoEtcone30_1);
   fChain->SetBranchAddress("lep_topoEtcone40_1", &lep_topoEtcone40_1, &b_lep_topoEtcone40_1);
   fChain->SetBranchAddress("lep_ptVarcone20_1", &lep_ptVarcone20_1, &b_lep_ptVarcone20_1);
   fChain->SetBranchAddress("lep_ptVarcone30_1", &lep_ptVarcone30_1, &b_lep_ptVarcone30_1);
   fChain->SetBranchAddress("lep_ptVarcone40_1", &lep_ptVarcone40_1, &b_lep_ptVarcone40_1);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   fChain->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   fChain->SetBranchAddress("lep_vz_1", &lep_vz_1, &b_lep_vz_1);
   fChain->SetBranchAddress("lep_deltaz0_1", &lep_deltaz0_1, &b_lep_deltaz0_1);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_1", &lep_isolationLooseTrackOnly_1, &b_lep_isolationLooseTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationLoose_1", &lep_isolationLoose_1, &b_lep_isolationLoose_1);
   fChain->SetBranchAddress("lep_isolationGradient_1", &lep_isolationGradient_1, &b_lep_isolationGradient_1);
   fChain->SetBranchAddress("lep_isolationGradientLoose_1", &lep_isolationGradientLoose_1, &b_lep_isolationGradientLoose_1);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_1", &lep_isolationFixedCutTight_1, &b_lep_isolationFixedCutTight_1);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_1", &lep_isolationFixedCutTightTrackOnly_1, &b_lep_isolationFixedCutTightTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_1", &lep_isolationFixedCutLoose_1, &b_lep_isolationFixedCutLoose_1);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
   fChain->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   fChain->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   fChain->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
   fChain->SetBranchAddress("lep_isIntConvPh_1", &lep_isIntConvPh_1, &b_lep_isIntConvPh_1);
   fChain->SetBranchAddress("lep_isExtConvPh_1", &lep_isExtConvPh_1, &b_lep_isExtConvPh_1);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   fChain->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   fChain->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   fChain->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   fChain->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   fChain->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   fChain->SetBranchAddress("lep_truthPt_1", &lep_truthPt_1, &b_lep_truthPt_1);
   fChain->SetBranchAddress("lep_truthEta_1", &lep_truthEta_1, &b_lep_truthEta_1);
   fChain->SetBranchAddress("lep_truthPhi_1", &lep_truthPhi_1, &b_lep_truthPhi_1);
   fChain->SetBranchAddress("lep_truthM_1", &lep_truthM_1, &b_lep_truthM_1);
   fChain->SetBranchAddress("lep_truthE_1", &lep_truthE_1, &b_lep_truthE_1);
   fChain->SetBranchAddress("lep_truthRapidity_1", &lep_truthRapidity_1, &b_lep_truthRapidity_1);
   fChain->SetBranchAddress("lep_SFIDLoose_1", &lep_SFIDLoose_1, &b_lep_SFIDLoose_1);
   fChain->SetBranchAddress("lep_SFIDTight_1", &lep_SFIDTight_1, &b_lep_SFIDTight_1);
   fChain->SetBranchAddress("lep_SFTrigLoose_1", &lep_SFTrigLoose_1, &b_lep_SFTrigLoose_1);
   fChain->SetBranchAddress("lep_SFTrigTight_1", &lep_SFTrigTight_1, &b_lep_SFTrigTight_1);
   fChain->SetBranchAddress("lep_EffTrigLoose_1", &lep_EffTrigLoose_1, &b_lep_EffTrigLoose_1);
   fChain->SetBranchAddress("lep_EffTrigTight_1", &lep_EffTrigTight_1, &b_lep_EffTrigTight_1);
   fChain->SetBranchAddress("lep_SFIsoLoose_1", &lep_SFIsoLoose_1, &b_lep_SFIsoLoose_1);
   fChain->SetBranchAddress("lep_SFIsoTight_1", &lep_SFIsoTight_1, &b_lep_SFIsoTight_1);
   fChain->SetBranchAddress("lep_SFReco_1", &lep_SFReco_1, &b_lep_SFReco_1);
   fChain->SetBranchAddress("lep_SFTTVA_1", &lep_SFTTVA_1, &b_lep_SFTTVA_1);
   fChain->SetBranchAddress("lep_SFObjLoose_1", &lep_SFObjLoose_1, &b_lep_SFObjLoose_1);
   fChain->SetBranchAddress("lep_SFObjTight_1", &lep_SFObjTight_1, &b_lep_SFObjTight_1);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_1", &lep_chargeIDBDTLoose_1, &b_lep_chargeIDBDTLoose_1);
   fChain->SetBranchAddress("lep_chargeIDBDTMedium_1", &lep_chargeIDBDTMedium_1, &b_lep_chargeIDBDTMedium_1);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_1", &lep_chargeIDBDTTight_1, &b_lep_chargeIDBDTTight_1);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_1", &lep_promptLeptonIso_TagWeight_1, &b_lep_promptLeptonIso_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_1", &lep_promptLeptonVeto_TagWeight_1, &b_lep_promptLeptonVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_Index_2", &lep_Index_2, &b_lep_Index_2);
   fChain->SetBranchAddress("lep_ambiguityType_2", &lep_ambiguityType_2, &b_lep_ambiguityType_2);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   fChain->SetBranchAddress("lep_topoEtcone20_2", &lep_topoEtcone20_2, &b_lep_topoEtcone20_2);
   fChain->SetBranchAddress("lep_topoEtcone30_2", &lep_topoEtcone30_2, &b_lep_topoEtcone30_2);
   fChain->SetBranchAddress("lep_topoEtcone40_2", &lep_topoEtcone40_2, &b_lep_topoEtcone40_2);
   fChain->SetBranchAddress("lep_ptVarcone20_2", &lep_ptVarcone20_2, &b_lep_ptVarcone20_2);
   fChain->SetBranchAddress("lep_ptVarcone30_2", &lep_ptVarcone30_2, &b_lep_ptVarcone30_2);
   fChain->SetBranchAddress("lep_ptVarcone40_2", &lep_ptVarcone40_2, &b_lep_ptVarcone40_2);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   fChain->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   fChain->SetBranchAddress("lep_vz_2", &lep_vz_2, &b_lep_vz_2);
   fChain->SetBranchAddress("lep_deltaz0_2", &lep_deltaz0_2, &b_lep_deltaz0_2);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_2", &lep_isolationLooseTrackOnly_2, &b_lep_isolationLooseTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationLoose_2", &lep_isolationLoose_2, &b_lep_isolationLoose_2);
   fChain->SetBranchAddress("lep_isolationGradient_2", &lep_isolationGradient_2, &b_lep_isolationGradient_2);
   fChain->SetBranchAddress("lep_isolationGradientLoose_2", &lep_isolationGradientLoose_2, &b_lep_isolationGradientLoose_2);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_2", &lep_isolationFixedCutTight_2, &b_lep_isolationFixedCutTight_2);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_2", &lep_isolationFixedCutTightTrackOnly_2, &b_lep_isolationFixedCutTightTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_2", &lep_isolationFixedCutLoose_2, &b_lep_isolationFixedCutLoose_2);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
   fChain->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   fChain->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   fChain->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   fChain->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   fChain->SetBranchAddress("lep_isIntConvPh_2", &lep_isIntConvPh_2, &b_lep_isIntConvPh_2);
   fChain->SetBranchAddress("lep_isExtConvPh_2", &lep_isExtConvPh_2, &b_lep_isExtConvPh_2);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   fChain->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   fChain->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   fChain->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   fChain->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   fChain->SetBranchAddress("lep_truthPt_2", &lep_truthPt_2, &b_lep_truthPt_2);
   fChain->SetBranchAddress("lep_truthEta_2", &lep_truthEta_2, &b_lep_truthEta_2);
   fChain->SetBranchAddress("lep_truthPhi_2", &lep_truthPhi_2, &b_lep_truthPhi_2);
   fChain->SetBranchAddress("lep_truthM_2", &lep_truthM_2, &b_lep_truthM_2);
   fChain->SetBranchAddress("lep_truthE_2", &lep_truthE_2, &b_lep_truthE_2);
   fChain->SetBranchAddress("lep_truthRapidity_2", &lep_truthRapidity_2, &b_lep_truthRapidity_2);
   fChain->SetBranchAddress("lep_SFIDLoose_2", &lep_SFIDLoose_2, &b_lep_SFIDLoose_2);
   fChain->SetBranchAddress("lep_SFIDTight_2", &lep_SFIDTight_2, &b_lep_SFIDTight_2);
   fChain->SetBranchAddress("lep_SFTrigLoose_2", &lep_SFTrigLoose_2, &b_lep_SFTrigLoose_2);
   fChain->SetBranchAddress("lep_SFTrigTight_2", &lep_SFTrigTight_2, &b_lep_SFTrigTight_2);
   fChain->SetBranchAddress("lep_EffTrigLoose_2", &lep_EffTrigLoose_2, &b_lep_EffTrigLoose_2);
   fChain->SetBranchAddress("lep_EffTrigTight_2", &lep_EffTrigTight_2, &b_lep_EffTrigTight_2);
   fChain->SetBranchAddress("lep_SFIsoLoose_2", &lep_SFIsoLoose_2, &b_lep_SFIsoLoose_2);
   fChain->SetBranchAddress("lep_SFIsoTight_2", &lep_SFIsoTight_2, &b_lep_SFIsoTight_2);
   fChain->SetBranchAddress("lep_SFReco_2", &lep_SFReco_2, &b_lep_SFReco_2);
   fChain->SetBranchAddress("lep_SFTTVA_2", &lep_SFTTVA_2, &b_lep_SFTTVA_2);
   fChain->SetBranchAddress("lep_SFObjLoose_2", &lep_SFObjLoose_2, &b_lep_SFObjLoose_2);
   fChain->SetBranchAddress("lep_SFObjTight_2", &lep_SFObjTight_2, &b_lep_SFObjTight_2);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_2", &lep_chargeIDBDTLoose_2, &b_lep_chargeIDBDTLoose_2);
   fChain->SetBranchAddress("lep_chargeIDBDTMedium_2", &lep_chargeIDBDTMedium_2, &b_lep_chargeIDBDTMedium_2);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_2", &lep_chargeIDBDTTight_2, &b_lep_chargeIDBDTTight_2);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_2", &lep_promptLeptonIso_TagWeight_2, &b_lep_promptLeptonIso_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_2", &lep_promptLeptonVeto_TagWeight_2, &b_lep_promptLeptonVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Index_3", &lep_Index_3, &b_lep_Index_3);
   fChain->SetBranchAddress("lep_ambiguityType_3", &lep_ambiguityType_3, &b_lep_ambiguityType_3);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   fChain->SetBranchAddress("lep_topoEtcone20_3", &lep_topoEtcone20_3, &b_lep_topoEtcone20_3);
   fChain->SetBranchAddress("lep_topoEtcone30_3", &lep_topoEtcone30_3, &b_lep_topoEtcone30_3);
   fChain->SetBranchAddress("lep_topoEtcone40_3", &lep_topoEtcone40_3, &b_lep_topoEtcone40_3);
   fChain->SetBranchAddress("lep_ptVarcone20_3", &lep_ptVarcone20_3, &b_lep_ptVarcone20_3);
   fChain->SetBranchAddress("lep_ptVarcone30_3", &lep_ptVarcone30_3, &b_lep_ptVarcone30_3);
   fChain->SetBranchAddress("lep_ptVarcone40_3", &lep_ptVarcone40_3, &b_lep_ptVarcone40_3);
   fChain->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   fChain->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   fChain->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   fChain->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   fChain->SetBranchAddress("lep_vz_3", &lep_vz_3, &b_lep_vz_3);
   fChain->SetBranchAddress("lep_deltaz0_3", &lep_deltaz0_3, &b_lep_deltaz0_3);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isMediumLH_3", &lep_isMediumLH_3, &b_lep_isMediumLH_3);
   fChain->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   fChain->SetBranchAddress("lep_isTight_3", &lep_isTight_3, &b_lep_isTight_3);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isLoose_3", &lep_isLoose_3, &b_lep_isLoose_3);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_3", &lep_isolationLooseTrackOnly_3, &b_lep_isolationLooseTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationLoose_3", &lep_isolationLoose_3, &b_lep_isolationLoose_3);
   fChain->SetBranchAddress("lep_isolationGradient_3", &lep_isolationGradient_3, &b_lep_isolationGradient_3);
   fChain->SetBranchAddress("lep_isolationGradientLoose_3", &lep_isolationGradientLoose_3, &b_lep_isolationGradientLoose_3);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_3", &lep_isolationFixedCutTight_3, &b_lep_isolationFixedCutTight_3);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_3", &lep_isolationFixedCutTightTrackOnly_3, &b_lep_isolationFixedCutTightTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_3", &lep_isolationFixedCutLoose_3, &b_lep_isolationFixedCutLoose_3);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   fChain->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   fChain->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   fChain->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   fChain->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   fChain->SetBranchAddress("lep_isIntConvPh_3", &lep_isIntConvPh_3, &b_lep_isIntConvPh_3);
   fChain->SetBranchAddress("lep_isExtConvPh_3", &lep_isExtConvPh_3, &b_lep_isExtConvPh_3);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   fChain->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   fChain->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   fChain->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   fChain->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   fChain->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   fChain->SetBranchAddress("lep_truthStatus_3", &lep_truthStatus_3, &b_lep_truthStatus_3);
   fChain->SetBranchAddress("lep_truthParentType_3", &lep_truthParentType_3, &b_lep_truthParentType_3);
   fChain->SetBranchAddress("lep_truthParentOrigin_3", &lep_truthParentOrigin_3, &b_lep_truthParentOrigin_3);
   fChain->SetBranchAddress("lep_truthParentPdgId_3", &lep_truthParentPdgId_3, &b_lep_truthParentPdgId_3);
   fChain->SetBranchAddress("lep_truthParentStatus_3", &lep_truthParentStatus_3, &b_lep_truthParentStatus_3);
   fChain->SetBranchAddress("lep_truthPt_3", &lep_truthPt_3, &b_lep_truthPt_3);
   fChain->SetBranchAddress("lep_truthEta_3", &lep_truthEta_3, &b_lep_truthEta_3);
   fChain->SetBranchAddress("lep_truthPhi_3", &lep_truthPhi_3, &b_lep_truthPhi_3);
   fChain->SetBranchAddress("lep_truthM_3", &lep_truthM_3, &b_lep_truthM_3);
   fChain->SetBranchAddress("lep_truthE_3", &lep_truthE_3, &b_lep_truthE_3);
   fChain->SetBranchAddress("lep_truthRapidity_3", &lep_truthRapidity_3, &b_lep_truthRapidity_3);
   fChain->SetBranchAddress("lep_SFIDLoose_3", &lep_SFIDLoose_3, &b_lep_SFIDLoose_3);
   fChain->SetBranchAddress("lep_SFIDTight_3", &lep_SFIDTight_3, &b_lep_SFIDTight_3);
   fChain->SetBranchAddress("lep_SFTrigLoose_3", &lep_SFTrigLoose_3, &b_lep_SFTrigLoose_3);
   fChain->SetBranchAddress("lep_SFTrigTight_3", &lep_SFTrigTight_3, &b_lep_SFTrigTight_3);
   fChain->SetBranchAddress("lep_EffTrigLoose_3", &lep_EffTrigLoose_3, &b_lep_EffTrigLoose_3);
   fChain->SetBranchAddress("lep_EffTrigTight_3", &lep_EffTrigTight_3, &b_lep_EffTrigTight_3);
   fChain->SetBranchAddress("lep_SFIsoLoose_3", &lep_SFIsoLoose_3, &b_lep_SFIsoLoose_3);
   fChain->SetBranchAddress("lep_SFIsoTight_3", &lep_SFIsoTight_3, &b_lep_SFIsoTight_3);
   fChain->SetBranchAddress("lep_SFReco_3", &lep_SFReco_3, &b_lep_SFReco_3);
   fChain->SetBranchAddress("lep_SFTTVA_3", &lep_SFTTVA_3, &b_lep_SFTTVA_3);
   fChain->SetBranchAddress("lep_SFObjLoose_3", &lep_SFObjLoose_3, &b_lep_SFObjLoose_3);
   fChain->SetBranchAddress("lep_SFObjTight_3", &lep_SFObjTight_3, &b_lep_SFObjTight_3);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_3", &lep_chargeIDBDTLoose_3, &b_lep_chargeIDBDTLoose_3);
   fChain->SetBranchAddress("lep_chargeIDBDTMedium_3", &lep_chargeIDBDTMedium_3, &b_lep_chargeIDBDTMedium_3);
   fChain->SetBranchAddress("lep_chargeIDBDTTight_3", &lep_chargeIDBDTTight_3, &b_lep_chargeIDBDTTight_3);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_3", &lep_promptLeptonIso_TagWeight_3, &b_lep_promptLeptonIso_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_3", &lep_promptLeptonVeto_TagWeight_3, &b_lep_promptLeptonVeto_TagWeight_3);
   fChain->SetBranchAddress("electron_ambiguityType", &electron_ambiguityType, &b_electron_ambiguityType);
   fChain->SetBranchAddress("electron_PromptLeptonIso_TagWeight", &electron_PromptLeptonIso_TagWeight, &b_electron_PromptLeptonIso_TagWeight);
   fChain->SetBranchAddress("electron_PromptLeptonVeto_TagWeight", &electron_PromptLeptonVeto_TagWeight, &b_electron_PromptLeptonVeto_TagWeight);
   fChain->SetBranchAddress("muon_PromptLeptonIso_TagWeight", &muon_PromptLeptonIso_TagWeight, &b_muon_PromptLeptonIso_TagWeight);
   fChain->SetBranchAddress("muon_PromptLeptonVeto_TagWeight", &muon_PromptLeptonVeto_TagWeight, &b_muon_PromptLeptonVeto_TagWeight);
   fChain->SetBranchAddress("tau_MV2c10_0", &tau_MV2c10_0, &b_tau_MV2c10_0);
   fChain->SetBranchAddress("tau_MV2c10_1", &tau_MV2c10_1, &b_tau_MV2c10_1);
   fChain->SetBranchAddress("tau_pt_0", &tau_pt_0, &b_tau_pt_0);
   fChain->SetBranchAddress("tau_eta_0", &tau_eta_0, &b_tau_eta_0);
   fChain->SetBranchAddress("tau_phi_0", &tau_phi_0, &b_tau_phi_0);
   fChain->SetBranchAddress("tau_charge_0", &tau_charge_0, &b_tau_charge_0);
   fChain->SetBranchAddress("tau_E_0", &tau_E_0, &b_tau_E_0);
   fChain->SetBranchAddress("tau_BDTJetScore_0", &tau_BDTJetScore_0, &b_tau_BDTJetScore_0);
   fChain->SetBranchAddress("tau_JetBDTSigLoose_0", &tau_JetBDTSigLoose_0, &b_tau_JetBDTSigLoose_0);
   fChain->SetBranchAddress("tau_JetBDTSigMedium_0", &tau_JetBDTSigMedium_0, &b_tau_JetBDTSigMedium_0);
   fChain->SetBranchAddress("tau_JetBDTSigTight_0", &tau_JetBDTSigTight_0, &b_tau_JetBDTSigTight_0);
   fChain->SetBranchAddress("tau_isHadronic_0", &tau_isHadronic_0, &b_tau_isHadronic_0);
   fChain->SetBranchAddress("tau_numTrack_0", &tau_numTrack_0, &b_tau_numTrack_0);
   fChain->SetBranchAddress("tau_SFTight_0", &tau_SFTight_0, &b_tau_SFTight_0);
   fChain->SetBranchAddress("tau_SFLoose_0", &tau_SFLoose_0, &b_tau_SFLoose_0);
   fChain->SetBranchAddress("tau_tagWeightBin_0", &tau_tagWeightBin_0, &b_tau_tagWeightBin_0);
   fChain->SetBranchAddress("tau_fromPV_0", &tau_fromPV_0, &b_tau_fromPV_0);
   fChain->SetBranchAddress("tau_passEleOLR_0", &tau_passEleOLR_0, &b_tau_passEleOLR_0);
   fChain->SetBranchAddress("tau_passEleBDT_0", &tau_passEleBDT_0, &b_tau_passEleBDT_0);
   fChain->SetBranchAddress("tau_passMuonOLR_0", &tau_passMuonOLR_0, &b_tau_passMuonOLR_0);
   fChain->SetBranchAddress("tau_truthOrigin_0", &tau_truthOrigin_0, &b_tau_truthOrigin_0);
   fChain->SetBranchAddress("tau_truthType_0", &tau_truthType_0, &b_tau_truthType_0);
   fChain->SetBranchAddress("tau_truthJetFlavour_0", &tau_truthJetFlavour_0, &b_tau_truthJetFlavour_0);
   fChain->SetBranchAddress("tau_pt_1", &tau_pt_1, &b_tau_pt_1);
   fChain->SetBranchAddress("tau_eta_1", &tau_eta_1, &b_tau_eta_1);
   fChain->SetBranchAddress("tau_phi_1", &tau_phi_1, &b_tau_phi_1);
   fChain->SetBranchAddress("tau_charge_1", &tau_charge_1, &b_tau_charge_1);
   fChain->SetBranchAddress("tau_E_1", &tau_E_1, &b_tau_E_1);
   fChain->SetBranchAddress("tau_BDTJetScore_1", &tau_BDTJetScore_1, &b_tau_BDTJetScore_1);
   fChain->SetBranchAddress("tau_JetBDTSigLoose_1", &tau_JetBDTSigLoose_1, &b_tau_JetBDTSigLoose_1);
   fChain->SetBranchAddress("tau_JetBDTSigMedium_1", &tau_JetBDTSigMedium_1, &b_tau_JetBDTSigMedium_1);
   fChain->SetBranchAddress("tau_JetBDTSigTight_1", &tau_JetBDTSigTight_1, &b_tau_JetBDTSigTight_1);
   fChain->SetBranchAddress("tau_numTrack_1", &tau_numTrack_1, &b_tau_numTrack_1);
   fChain->SetBranchAddress("tau_isHadronic_1", &tau_isHadronic_1, &b_tau_isHadronic_1);
   fChain->SetBranchAddress("tau_SFTight_1", &tau_SFTight_1, &b_tau_SFTight_1);
   fChain->SetBranchAddress("tau_SFLoose_1", &tau_SFLoose_1, &b_tau_SFLoose_1);
   fChain->SetBranchAddress("tau_tagWeightBin_1", &tau_tagWeightBin_1, &b_tau_tagWeightBin_1);
   fChain->SetBranchAddress("tau_fromPV_1", &tau_fromPV_1, &b_tau_fromPV_1);
   fChain->SetBranchAddress("tau_passEleOLR_1", &tau_passEleOLR_1, &b_tau_passEleOLR_1);
   fChain->SetBranchAddress("tau_passEleBDT_1", &tau_passEleBDT_1, &b_tau_passEleBDT_1);
   fChain->SetBranchAddress("tau_passMuonOLR_1", &tau_passMuonOLR_1, &b_tau_passMuonOLR_1);
   fChain->SetBranchAddress("tau_truthOrigin_1", &tau_truthOrigin_1, &b_tau_truthOrigin_1);
   fChain->SetBranchAddress("tau_truthType_1", &tau_truthType_1, &b_tau_truthType_1);
   fChain->SetBranchAddress("tau_truthJetFlavour_1", &tau_truthJetFlavour_1, &b_tau_truthJetFlavour_1);
   fChain->SetBranchAddress("tau_promptTauVeto_0", &tau_promptTauVeto_0, &b_tau_promptTauVeto_0);
   fChain->SetBranchAddress("tau_promptTauVeto_1", &tau_promptTauVeto_1, &b_tau_promptTauVeto_1);
   fChain->SetBranchAddress("onelep_type", &onelep_type, &b_onelep_type);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("isQMisIDEvent", &isQMisIDEvent, &b_isQMisIDEvent);
   fChain->SetBranchAddress("isFakeEvent", &isFakeEvent, &b_isFakeEvent);
   fChain->SetBranchAddress("isLepFromPhEvent", &isLepFromPhEvent, &b_isLepFromPhEvent);
   fChain->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   fChain->SetBranchAddress("Ptll01", &Ptll01, &b_Ptll01);
   fChain->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   fChain->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   fChain->SetBranchAddress("Mllll0123", &Mllll0123, &b_Mllll0123);
   fChain->SetBranchAddress("Mlll013", &Mlll013, &b_Mlll013);
   fChain->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   fChain->SetBranchAddress("Ptll02", &Ptll02, &b_Ptll02);
   fChain->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   fChain->SetBranchAddress("Mlll023", &Mlll023, &b_Mlll023);
   fChain->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   fChain->SetBranchAddress("Ptll03", &Ptll03, &b_Ptll03);
   fChain->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   fChain->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   fChain->SetBranchAddress("Ptll12", &Ptll12, &b_Ptll12);
   fChain->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   fChain->SetBranchAddress("Mlll123", &Mlll123, &b_Mlll123);
   fChain->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   fChain->SetBranchAddress("Ptll13", &Ptll13, &b_Ptll13);
   fChain->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   fChain->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   fChain->SetBranchAddress("Ptll23", &Ptll23, &b_Ptll23);
   fChain->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   fChain->SetBranchAddress("matchDLTll01", &matchDLTll01, &b_matchDLTll01);
   fChain->SetBranchAddress("matchDLTll02", &matchDLTll02, &b_matchDLTll02);
   fChain->SetBranchAddress("matchDLTll12", &matchDLTll12, &b_matchDLTll12);
   fChain->SetBranchAddress("matchDLTll03", &matchDLTll03, &b_matchDLTll03);
   fChain->SetBranchAddress("matchDLTll13", &matchDLTll13, &b_matchDLTll13);
   fChain->SetBranchAddress("matchDLTll23", &matchDLTll23, &b_matchDLTll23);
   fChain->SetBranchAddress("best_Z_Mll", &best_Z_Mll, &b_best_Z_Mll);
   fChain->SetBranchAddress("best_Z_other_Mll", &best_Z_other_Mll, &b_best_Z_other_Mll);
   fChain->SetBranchAddress("best_Z_other_MtLepMet", &best_Z_other_MtLepMet, &b_best_Z_other_MtLepMet);
   fChain->SetBranchAddress("nJets_OR_T", &nJets_OR_T, &b_nJets_OR_T);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_60", &nJets_OR_T_MV2c20_60, &b_nJets_OR_T_MV2c20_60);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_70", &nJets_OR_T_MV2c20_70, &b_nJets_OR_T_MV2c20_70);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_77", &nJets_OR_T_MV2c20_77, &b_nJets_OR_T_MV2c20_77);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_85", &nJets_OR_T_MV2c20_85, &b_nJets_OR_T_MV2c20_85);
   fChain->SetBranchAddress("nJets_OR_MV2c20_85", &nJets_OR_MV2c20_85, &b_nJets_OR_MV2c20_85);
   fChain->SetBranchAddress("nJets_OR_MV2c20_60", &nJets_OR_MV2c20_60, &b_nJets_OR_MV2c20_60);
   fChain->SetBranchAddress("nJets_OR_MV2c20_77", &nJets_OR_MV2c20_77, &b_nJets_OR_MV2c20_77);
   fChain->SetBranchAddress("nJets_OR_MV2c20_70", &nJets_OR_MV2c20_70, &b_nJets_OR_MV2c20_70);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_60", &nJets_OR_T_MV2c10_60, &b_nJets_OR_T_MV2c10_60);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_70", &nJets_OR_T_MV2c10_70, &b_nJets_OR_T_MV2c10_70);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_77", &nJets_OR_T_MV2c10_77, &b_nJets_OR_T_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_85", &nJets_OR_T_MV2c10_85, &b_nJets_OR_T_MV2c10_85);
   fChain->SetBranchAddress("nJets_OR_MV2c10_85", &nJets_OR_MV2c10_85, &b_nJets_OR_MV2c10_85);
   fChain->SetBranchAddress("nJets_OR_MV2c10_60", &nJets_OR_MV2c10_60, &b_nJets_OR_MV2c10_60);
   fChain->SetBranchAddress("nJets_OR_MV2c10_77", &nJets_OR_MV2c10_77, &b_nJets_OR_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_MV2c10_70", &nJets_OR_MV2c10_70, &b_nJets_OR_MV2c10_70);
   fChain->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25, &b_nTaus_OR_Pt25);
   fChain->SetBranchAddress("isBlinded", &isBlinded, &b_isBlinded);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("lead_jetPt", &lead_jetPt, &b_lead_jetPt);
   fChain->SetBranchAddress("lead_jetEta", &lead_jetEta, &b_lead_jetEta);
   fChain->SetBranchAddress("lead_jetPhi", &lead_jetPhi, &b_lead_jetPhi);
   fChain->SetBranchAddress("lead_jetE", &lead_jetE, &b_lead_jetE);
   fChain->SetBranchAddress("sublead_jetPt", &sublead_jetPt, &b_sublead_jetPt);
   fChain->SetBranchAddress("sublead_jetEta", &sublead_jetEta, &b_sublead_jetEta);
   fChain->SetBranchAddress("sublead_jetPhi", &sublead_jetPhi, &b_sublead_jetPhi);
   fChain->SetBranchAddress("sublead_jetE", &sublead_jetE, &b_sublead_jetE);
   fChain->SetBranchAddress("lepSFTrigLoose", &lepSFTrigLoose, &b_lepSFTrigLoose);
   fChain->SetBranchAddress("lepSFTrigTight", &lepSFTrigTight, &b_lepSFTrigTight);
   fChain->SetBranchAddress("lepSFTrigTightLoose", &lepSFTrigTightLoose, &b_lepSFTrigTightLoose);
   fChain->SetBranchAddress("lepSFTrigLooseTight", &lepSFTrigLooseTight, &b_lepSFTrigLooseTight);
   fChain->SetBranchAddress("lepEffTrigLoose", &lepEffTrigLoose, &b_lepEffTrigLoose);
   fChain->SetBranchAddress("lepEffTrigTight", &lepEffTrigTight, &b_lepEffTrigTight);
   fChain->SetBranchAddress("lepEffTrigTightLoose", &lepEffTrigTightLoose, &b_lepEffTrigTightLoose);
   fChain->SetBranchAddress("lepEffTrigLooseTight", &lepEffTrigLooseTight, &b_lepEffTrigLooseTight);
   fChain->SetBranchAddress("lepDataEffTrigLoose", &lepDataEffTrigLoose, &b_lepDataEffTrigLoose);
   fChain->SetBranchAddress("lepDataEffTrigTight", &lepDataEffTrigTight, &b_lepDataEffTrigTight);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose", &lepDataEffTrigTightLoose, &b_lepDataEffTrigTightLoose);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight", &lepDataEffTrigLooseTight, &b_lepDataEffTrigLooseTight);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("tauSFTight", &tauSFTight, &b_tauSFTight);
   fChain->SetBranchAddress("tauSFLoose", &tauSFLoose, &b_tauSFLoose);
   fChain->SetBranchAddress("tauFakeSF_weight", &tauFakeSF_weight, &b_tauFakeSF_weight);
   fChain->SetBranchAddress("tauFakeSF_weight_SYST_UP", &tauFakeSF_weight_SYST_UP, &b_tauFakeSF_weight_SYST_UP);
   fChain->SetBranchAddress("tauFakeSF_weight_SYST_DOWN", &tauFakeSF_weight_SYST_DOWN, &b_tauFakeSF_weight_SYST_DOWN);
   fChain->SetBranchAddress("tauFakeSF_weight_STAT_UP", &tauFakeSF_weight_STAT_UP, &b_tauFakeSF_weight_STAT_UP);
   fChain->SetBranchAddress("tauFakeSF_weight_STAT_DOWN", &tauFakeSF_weight_STAT_DOWN, &b_tauFakeSF_weight_STAT_DOWN);
   Notify();
}

Bool_t GN_v7::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void GN_v7::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t GN_v7::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef GN_v7_cxx

