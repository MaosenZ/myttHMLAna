#ifdef NTUPLE_cxx

bool NTUPLE::applySelections(string selection){

  bool passed=false;
  if(selection=="Zpeak"){

     if(total_leptons==2 && abs(lep_ID_0)==11 && abs(lep_ID_1)==11 &&
          lep_Pt_0>20e3&&lep_Pt_1>20e3 &&
          lep_promptLeptonIso_TagWeight_0<-0.5 && lep_promptLeptonIso_TagWeight_1<-0.5 )//&&
//          (*electron_ChargeIDBDTTight)[0] > 0.0670415 && (*electron_ChargeIDBDTTight)[1] > 0.0670415)
         passed=true;
  }

  if(selection=="ttbarCR"){
      if(dilep_type>0 && lep_ID_0*lep_ID_1<0 &&
        ( (abs(lep_ID_0)==13 &&
        lep_promptLeptonVeto_TagWeight_0<-0.5)||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0 &&
        lep_chargeIDBDTTight_0 >0.7 &&
        lep_promptLeptonVeto_TagWeight_0<-0.7 &&
        lep_ambiguityType_0 == 0)) &&
        ( (abs(lep_ID_1)==13 &&
        lep_promptLeptonVeto_TagWeight_1<-0.5)||
     ((abs(lep_ID_1)==11)&&lep_isTightLH_1 &&
        lep_chargeIDBDTTight_1 >0.7 &&
        lep_promptLeptonVeto_TagWeight_1<-0.7 &&
        lep_ambiguityType_1 == 0)) &&
     (lep_isTrigMatch_0 || lep_isTrigMatch_1||matchDLTll01) &&
     lep_isolationFixedCutLoose_0 && lep_isolationFixedCutLoose_1 &&
     nJets_OR_T_MV2c10_70>=2 && fabs(Mll01-91000)>20e3 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
      passed=true;
  }

  if(selection=="OneL2tauSR"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
      passed=true;
  }

  if(selection=="OneL2tauSSnoBDT"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1>0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
      passed=true;
  }

  if(selection=="OneL2tauOSnoBDT"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
      passed=true;
  }

  if(selection=="OneL2tauSRtruth"){//signal region, but tau is truth matched
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 &&
     tau_truthType_0==10 && tau_truthType_1==10 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
      passed=true;
  }

  if(selection=="OneL2tauSS"){//same selections as SR, except same-sign
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1>0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 && 
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauSStruth"){//same selections as SS, but tau is truth matched
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1>0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 &&
     tau_truthType_0==10 && tau_truthType_1==10 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2taulowBDTOS"){//same selections as SR, except same-sign
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx<0.5 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2taulowBDTOStruth"){//same selections as lowBDTOS, but tau is truth matched
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx<0.5 &&
     tau_truthType_0==10 && tau_truthType_1==10 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2taulowBDTSS"){//low BDT, SS
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1>0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx<0.5 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2taulowBDTSStruth"){//same selections as lowBDTSS, but tau is truth matched
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1>0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx<0.5 &&
     tau_truthType_0==10 && tau_truthType_1==10 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauleptau0OS"){//lep_charge_0*tau_charge_0<0
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0  && lep_ID_0*tau_charge_0>0 &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauleptau1OS"){//lep_charge_0*tau_charge_1<0
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_1  && lep_ID_0*tau_charge_1>0 &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2taulowNjet"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T<3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauLTT"){//loose lepton and two tight taus, same as SR in fact
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauLTM"){//loose lepton and at least one tight tau
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     (tau_tight_0 || tau_tight_1)  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauTTT"){//tight lepton and two tight taus
     if(onelep_type>0 && ( (abs(lep_ID_0)==13 && 
        lep_promptLeptonVeto_TagWeight_0<-0.5)||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0 && 
        lep_chargeIDBDTTight_0 >0.7 && 
        lep_promptLeptonVeto_TagWeight_0<-0.7 &&
        lep_ambiguityType_0 == 0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     tau_tight_0 && tau_tight_1  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauTTM"){//tight lepton and at least one tight tau 
     if(onelep_type>0 && ( (abs(lep_ID_0)==13 &&
        lep_promptLeptonVeto_TagWeight_0<-0.5)||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0 &&
        lep_chargeIDBDTTight_0 >0.7 &&
        lep_promptLeptonVeto_TagWeight_0<-0.7 &&
        lep_ambiguityType_0 == 0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
     (tau_tight_0 || tau_tight_1)  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="OneL2tauTTMnotTTT"){//tight lepton and at least one tight tau
     if(onelep_type>0 && ( (abs(lep_ID_0)==13 &&
        lep_promptLeptonVeto_TagWeight_0<-0.5)||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0 &&
        lep_chargeIDBDTTight_0 >0.7 &&
        lep_promptLeptonVeto_TagWeight_0<-0.7 &&
        lep_ambiguityType_0 == 0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0&&
     tau_charge_0*tau_charge_1<0 && nTaus_OR_Pt25==2 &&
    ( (tau_tight_0 && (!tau_tight_1)) || ((!tau_tight_0) && tau_tight_1) )  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 &&
     tau_passMuonOLR_0==1 && tau_passMuonOLR_1==1)
       passed=true;
  }

  if(selection=="SS1Lep1Tau5j1b"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 &&
     nTaus_OR_Pt25==1 && tau_JetBDTSigTight_0  &&
     nJets_OR_T>=5 && nJets_OR_T_MV2c10_70>=1 && lep_ID_0*tau_charge_0<0 &&
     //nJets_OR_T_MV2c10_85>=3 && 
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4)
     passed=true;
  }

  if(selection=="SS1Lep1Tau5j2b"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 &&
     nTaus_OR_Pt25==1 && tau_JetBDTSigTight_0  &&
     nJets_OR_T>=5 && nJets_OR_T_MV2c10_70>=2 && lep_ID_0*tau_charge_0<0 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4)
     passed=true;
  }
  if(selection=="SS1Lep1Tau6j1b"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 &&
     nTaus_OR_Pt25==1 && tau_JetBDTSigTight_0  &&
     nJets_OR_T>5 && nJets_OR_T_MV2c10_70>=1 && lep_ID_0*tau_charge_0<0 &&
     //nJets_OR_T_MV2c10_85>=3 &&
     //tau_truthOrigin_0==14 && lep_truthOrigin_0==14 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4)
     passed=true;
  }

  if(selection=="SS1Lep1Tau6j2b"){
     if(onelep_type>0 && ( abs(lep_ID_0)==13 ||
     ((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&
     lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 &&
     nTaus_OR_Pt25==1 && tau_JetBDTSigTight_0  &&
     nJets_OR_T>5 && nJets_OR_T_MV2c10_70>=2 && lep_ID_0*tau_charge_0<0 &&
     //tau_truthOrigin_0==14 && lep_truthOrigin_0==14 &&
     //Mybdtx>0.5 &&
     tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4)
     passed=true; 
  }
 
  return passed;
}
#endif
