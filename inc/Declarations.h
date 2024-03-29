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
   std::string         prefix("/afs/cern.ch/user/m/mzhou/work/private/myttHAna/doc/"); //define prefix for input sample list
   //std::string         prefix("/Users/mason/Desktop/myWork/myttHMLAna/doc/"); //define prefix for input sample list
   std::string         prepath("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v7_04/");
   //std::string         prepath("/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/");
   std::string	       outpath("/eos/atlas/user/m/mzhou/ttHMLSamps/v7_01/"); //skimed samples go here
   TString             m_treeName("nominal");

   std::vector<std::string> m_Algorithms;
   std::vector<std::string> m_Regions;
   std::vector<std::string> m_Samples;
   bool                m_commonSelections(true);
}
#endif
