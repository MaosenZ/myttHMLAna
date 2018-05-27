#ifdef NTUPLE_cxx

inline double NTUPLE::commonWeight(){

  //if regular variable doesn't wrok, try input_branches["var_name"].c (c, f, and i means bool/char, float and int, respectively)
  /*double wt = mc_channel_number>0?(mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_Continuous*lepSFObjTight*
                                       ((!dilep_type||!total_charge)*lepSFTrigTight+(dilep_type&&total_charge)*lepSFTrigLoose)*(tauSFTight<10?tauSFTight:1.0)*
                                       JVT_EventWeight*SherpaNJetWeight*((quadlep_type>0?1./input_branches["lep_SFIsoLoose_0"].f/input_branches["lep_SFIsoLoose_1"].f:0.)+
                                                                         (onelep_type>0?1./input_branches["lep_SFObjLoose_0"].f:0.)+(!quadlep_type&&!onelep_type))):1.0;*/
   //double mc_norm=mcWeightOrg*0.238652*1/SumOfTotalWeightedEvents;
   double mc_norm=scale_nom;
   double wt=mc_norm*pileupEventWeight_090 *JVT_EventWeight*MV2c10_Continuous_EventWeight*SherpaNJetWeight*( 36074.6*(RunYear < 2016.5) +  43813.7*(RunYear > 2016.5) );
   
  //double wt=mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*JVT_EventWeight*SherpaNJetWeight:1.0;

  return wt;
}
#endif
