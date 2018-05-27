#ifdef NTUPLE_cxx

bool NTUPLE::applySelections(string selection){

  bool passed=false;
  if(selection=="Zpeak"){

     if(total_leptons==2 && abs(input_branches["lep_ID_0"].i)==11 && abs(input_branches["lep_ID_1"].i)==11 &&
          input_branches["lep_Pt_0"].f>20e3&&input_branches["lep_Pt_1"].f>20e3 &&
          input_branches["lep_promptLeptonIso_TagWeight_0"].f<-0.5 && input_branches["lep_promptLeptonIso_TagWeight_1"].f<-0.5 )//&&
//          (*electron_ChargeIDBDTTight)[0] > 0.0670415 && (*electron_ChargeIDBDTTight)[1] > 0.0670415)
         passed=true;

  }

  if(selection=="ttbarCR"){
      if(dilep_type>0 && input_branches["lep_ID_0"].f*input_branches["lep_ID_1"].f<0 &&
        ( (abs(input_branches["lep_ID_0"].f)==13 &&
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5)||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c &&
        input_branches["lep_chargeIDBDTTight_0"].f >0.7 &&
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7 &&
        input_branches["lep_ambiguityType_0"].c == 0)) &&
        ( (abs(input_branches["lep_ID_1"].f)==13 &&
        input_branches["lep_promptLeptonVeto_TagWeight_1"].f<-0.5)||
     ((abs(input_branches["lep_ID_1"].f)==11)&&input_branches["lep_isTightLH_1"].c &&
        input_branches["lep_chargeIDBDTTight_1"].f >0.7 &&
        input_branches["lep_promptLeptonVeto_TagWeight_1"].f<-0.7 &&
        input_branches["lep_ambiguityType_1"].c == 0)) &&
     (lep_isTrigMatch_0 || lep_isTrigMatch_1||matchDLTll01) &&
     input_branches["lep_isolationFixedCutLoose_0"].i && input_branches["lep_isolationFixedCutLoose_1"].i &&
     input_branches["nJets_OR_T_MV2c10_70"].i>=2 && fabs(input_branches["Mll01"].f-91000)>20e3)
      passed=true;
  }

  if(selection=="1l2tauSR"){
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5)
      passed=true;
  }

  if(selection=="1l2tauSRtruth"){//signal region, but tau is truth matched
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5 &&
     input_branches["tau_truthType_0"].i==10 && input_branches["tau_truthType_1"].i==10)
      passed=true;
  }

  if(selection=="1l2tauSS"){//same selections as SR, except same-sign
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f>0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5)
       passed=true;
  }

  if(selection=="1l2tauSStruth"){//same selections as SS, but tau is truth matched
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f>0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5 &&
     input_branches["tau_truthType_0"].i==10 && input_branches["tau_truthType_1"].i==10)
       passed=true;
  }

  if(selection=="1l2taulowBDTOS"){//same selections as SR, except same-sign
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f<0.5)
       passed=true;
  }

  if(selection=="1l2taulowBDTOStruth"){//same selections as lowBDTOS, but tau is truth matched
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f<0.5 &&
     input_branches["tau_truthType_0"].i==10 && input_branches["tau_truthType_1"].i==10)
       passed=true;
  }

  if(selection=="1l2taulowBDTSS"){//low BDT, SS
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f>0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f<0.5)
       passed=true;
  }

  if(selection=="1l2taulowBDTSStruth"){//same selections as lowBDTSS, but tau is truth matched
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f>0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f<0.5 &&
     input_branches["tau_truthType_0"].i==10 && input_branches["tau_truthType_1"].i==10)
       passed=true;
  }

  if(selection=="1l2tauleptau0OS"){//lep_charge_0*tau_charge_0<0
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f  && input_branches["lep_ID_0"].f*input_branches["tau_charge_0"].f>0 &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5)
       passed=true;
  }

  if(selection=="1l2tauleptau1OS"){//lep_charge_0*tau_charge_1<0
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_1"].f  && input_branches["lep_ID_0"].f*input_branches["tau_charge_1"].f>0 &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1 &&
     input_branches["MVA1l2tau_weight"].f>0.5)
       passed=true;
  }

  if(selection=="1l2taulowNjet"){
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i<3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1)
       passed=true;
  }

  if(selection=="1l2tauLTT"){//loose lepton and two tight taus, same as SR in fact
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1)
       passed=true;
  }

  if(selection=="1l2tauLTM"){//loose lepton and at least one tight tau
     if(onelep_type>0 && ( abs(input_branches["lep_ID_0"].f)==13 ||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     (input_branches["tau_tight_0"].f || input_branches["tau_tight_1"].f)  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1)
       passed=true;
  }

  if(selection=="1l2tauTTT"){//tight lepton and two tight taus
     if(onelep_type>0 && ( (abs(input_branches["lep_ID_0"].f)==13 && 
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5)||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c && 
        input_branches["lep_chargeIDBDTTight_0"].f >0.7 && 
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7 &&
        input_branches["lep_ambiguityType_0"].c == 0)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     input_branches["tau_tight_0"].f && input_branches["tau_tight_1"].f  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1)
       passed=true;
  }

  if(selection=="1l2tauTTM"){//tight lepton and at least one tight tau 
     if(onelep_type>0 && ( (abs(input_branches["lep_ID_0"].f)==13 &&
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5)||
     ((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c &&
        input_branches["lep_chargeIDBDTTight_0"].f >0.7 &&
        input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7 &&
        input_branches["lep_ambiguityType_0"].c == 0)) &&
     lep_isTrigMatch_0 && input_branches["lep_Pt_0"].f>27e3 && input_branches["lep_isolationFixedCutLoose_0"].i&&
     input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0 && nTaus_OR_Pt25==2 &&
     (input_branches["tau_tight_0"].f || input_branches["tau_tight_1"].f)  &&
     tau_btag70_0==0 && tau_btag70_1==0 &&
     input_branches["nJets_OR_T"].i>=3 && input_branches["nJets_OR_T_MV2c10_70"].i>=1)
       passed=true;
  }
  return passed;
}
#endif
