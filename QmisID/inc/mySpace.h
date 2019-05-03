#ifndef mySpace_h
#define mySpace_h
#include <string>
#include <map>
#include <iostream>
#include "TString.h"

namespace mySpace {
 
  float GeV(1000.);//just in case the input ntuples use MeV
  //maps for SS/OS events, id0,eta0,pt0:id1,eta1,pt1
  std::map<std::string, double> SS_Counts;
  std::map<std::string, double> OS_Counts;  
 
  //set in config 
  std::string m_RunName;
  //nbins
  int nbins_eta_wocrk; //nbins after removing crack region(if there is)
  int nbins_eta;
  int nbins_pt;
  int nbins_id; //nbins of electron defitions, can be 1 or 2

  //evt selections and electron definitions
  TString m_FitZEvtSelString="lep_isolationFixedCutLoose_0&&lep_isolationFixedCutLoose_1&&lep_isLooseLH_0&&lep_isLooseLH_1&&Mll01>50e3&&Mll01<130e3"; //event selections used for Z peak fit
  TString m_EvtSelString="lep_Pt_0>=10e3 && lep_Pt_1>=10e3"; //event selections used for QmisID rates estimation
  //make sure elec0 and elec1 have consistent definitions!!
  TString m_Elec0TightString="lep_isTightLH_0&&lep_isolationFixedCutTight_0";
  TString m_Elec1TightString="lep_isTightLH_1&&lep_isolationFixedCutTight_1";
  TString m_Elec0AntiTightString="(!lep_isTightLH_0)&&lep_isolationFixedCutLoose_0&&lep_isLooseLH_0";
  TString m_Elec1AntiTightString="(!lep_isTightLH_1)&&lep_isolationFixedCutLoose_1&&lep_isLooseLH_1";
}
#endif
