#include "Root/NTUPLE.cxx"

void ApplyBDT(){
  //string samps[]={"tth","diboson","rare","ttV"};
  //string samps[]={"data","ttbar","Vjets","ttbargamma"};
  //string samps[]={"ttZ","tth_Gen","tth_af2","tth_aMChwg","tth_semiaf2"};
  string samps[]={"tth_notaubveto","ttbar_notaubveto"};

  for(unsigned int i=0;i<2;i++){
      std::cout<<samps[i]<<std::endl;
      string samp=samps[i];
      string treenames[]={"nominal"};
      /*string treenames[]={"nominal",
          "EG_RESOLUTION_ALL__1down",	
          "EG_RESOLUTION_ALL__1up",	
          "EG_SCALE_AF2__1down",	
          "EG_SCALE_AF2__1up",	
          "EG_SCALE_ALL__1down",	
          "EG_SCALE_ALL__1up",	
          "JET_CategoryReduction_JET_BJES_Response__1down",	
          "JET_CategoryReduction_JET_BJES_Response__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Detector1__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Detector1__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed1__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed1__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed2__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed2__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed3__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Mixed3__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling1__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling1__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling2__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling2__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling3__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling3__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling4__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Modelling4__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical1__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical1__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical2__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical2__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical3__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical3__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical4__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical4__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical5__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical5__1up",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical6__1down",	
          "JET_CategoryReduction_JET_EffectiveNP_Statistical6__1up",	
          "JET_CategoryReduction_JET_EtaIntercalibration_Modelling__1down",	
          "JET_CategoryReduction_JET_EtaIntercalibration_Modelling__1up",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_highE__1down",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_highE__1up",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_negEta__1down",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_negEta__1up",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_posEta__1down",	
          "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_posEta__1up",	
          "JET_CategoryReduction_JET_EtaIntercalibration_TotalStat__1down",	
          "JET_CategoryReduction_JET_EtaIntercalibration_TotalStat__1up",	
          "JET_CategoryReduction_JET_Flavor_Composition__1down",	
          "JET_CategoryReduction_JET_Flavor_Composition__1up",	
          "JET_CategoryReduction_JET_Flavor_Response__1down",	
          "JET_CategoryReduction_JET_Flavor_Response__1up",	
          "JET_CategoryReduction_JET_Pileup_OffsetMu__1down",	
          "JET_CategoryReduction_JET_Pileup_OffsetMu__1up",	
          "JET_CategoryReduction_JET_Pileup_OffsetNPV__1down",	
          "JET_CategoryReduction_JET_Pileup_OffsetNPV__1up",	
          "JET_CategoryReduction_JET_Pileup_PtTerm__1down",	
          "JET_CategoryReduction_JET_Pileup_PtTerm__1up",	
          "JET_CategoryReduction_JET_Pileup_RhoTopology__1down",	
          "JET_CategoryReduction_JET_Pileup_RhoTopology__1up",	
          "JET_CategoryReduction_JET_PunchThrough_MC16__1down",	
          "JET_CategoryReduction_JET_PunchThrough_MC16__1up",	
          "JET_CategoryReduction_JET_SingleParticle_HighPt__1down",	
          "JET_CategoryReduction_JET_SingleParticle_HighPt__1up",	
          "JET_JER_SINGLE_NP__1up",	
          "MET_SoftTrk_ResoPara",	
          "MET_SoftTrk_ResoPerp",	
          "MET_SoftTrk_ScaleDown",	
          "MET_SoftTrk_ScaleUp",	
          "MUON_ID__1down",	
          "MUON_ID__1up",	
          "MUON_MS__1down",	
          "MUON_MS__1up",	
          "MUON_SAGITTA_RESBIAS__1down",	
          "MUON_SAGITTA_RESBIAS__1up",	
          "MUON_SAGITTA_RHO__1down",	
          "MUON_SAGITTA_RHO__1up",	
          "MUON_SCALE__1down",	
          "MUON_SCALE__1up",	
          "TAUS_TRUEHADTAU_SME_TES_DETECTOR__1down",	
          "TAUS_TRUEHADTAU_SME_TES_DETECTOR__1up",	
          "TAUS_TRUEHADTAU_SME_TES_INSITU__1down",	
          "TAUS_TRUEHADTAU_SME_TES_INSITU__1up",	
          "TAUS_TRUEHADTAU_SME_TES_MODEL__1down",	
          "TAUS_TRUEHADTAU_SME_TES_MODEL__1up"};*/
     
      //for (int index=0; index<84;index++){
      for (int index=0; index<1;index++){
           NTUPLE *ntuple=new NTUPLE(samp, treenames[index]);
           std::cout<<" samp:   "<<samp<<"   Tree:  "<<treenames[index]<<std::endl; 
           ntuple->applyBDT();
    	   delete ntuple;
      }
  }
}
