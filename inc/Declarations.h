#ifndef Declarations_h
#define Declarations_h
#include <string>
#include <vector>
#include "TString.h"
#include <map>

namespace Declarations{
   struct Branch_Types {
      Branch_Types() : f(-999.0), c(-1), i(-999) {};
      float f;
      char c;
      int i;
      double d;
      std::vector<float> vec_f;
      std::vector<char> vec_c;
      std::vector<int> vec_i;
      std::vector<double> vec_d;
   };

   std::map< std::string, Branch_Types > output_branches;
   //
   float                 GeV(1000);
   bool                debug(false);
   TString             mySample;
   //std::string         prefix("/afs/cern.ch/user/m/mzhou/work/private/myttHAna/doc/"); //define prefix for input sample list
   std::string           prefix("/global/homes/m/mszhou/work/ttHML/myttHMLAna/doc/");
   //std::string         prepath("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v8_02/");
   //std::string         prepath("/eos/atlas/user/m/mzhou/ttHMLSamps/v8_02/");
   //std::string         prepath("/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV6/");
   std::string         prepath("/global/homes/m/mszhou/work/ttHML/GN1Samps/onelep_looseleps/");
   std::string	       outpath("/eos/atlas/user/m/mzhou/ttHMLSamps/v7_01/"); //skimed samples go here
   TString             m_treeName("nominal");

   std::vector<std::string> m_Algorithms;
   std::vector<std::string> m_Regions;
   std::vector<std::string> m_Samples;
   bool                m_commonSelections(true);
}
#endif
