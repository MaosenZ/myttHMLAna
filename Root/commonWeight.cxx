#ifdef NTUPLE_cxx

inline double NTUPLE::commonWeight(){

  //if regular variable doesn't wrok, try input_branches["var_name"].c (c, f, and i means bool/char, float and int, respectively)
   
  // double wt=scale_nom*pileupEventWeight_090 *JVT_EventWeight*MV2c10_Continuous_EventWeight*SherpaNJetWeight*( 36074.6*(RunYear < 2016.5) +  43813.7*(RunYear > 2016.5) );//v5
   double wt=scale_nom*pileupEventWeight_090 *JVT_EventWeight*MV2c10_Continuous_EventWeight*SherpaNJetWeight* ((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjLoose)*(nTaus_OR_Pt25>0?tauSFTight:1.0)*( 36074.6*(RunYear < 2016.5) +  43813.7*(RunYear > 2016.5) );
  //double wt=mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*JVT_EventWeight*SherpaNJetWeight:1.0;

  return wt;
}
#endif
