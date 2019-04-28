#ifndef QmisID_h
#define QmisID_h

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TEnv.h"
#include "TSystem.h"
#include "TString.h"
#include "TTreeFormula.h"

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <fstream>
#include "TH1F.h"
#include <iomanip>
#include <cmath>

#include "mySpace.h"

using namespace std;
using namespace mySpace;

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
};

struct Cell {
      Cell() : ij(-1), i(-1), j(-1) {};
      int ij; //each ij combination in likelihood function
      int i; //unique bin for one electron
      int j; //unique bin for the other electron
};

class QmisID{

 public:

   QmisID();
   ~QmisID();
  
   bool ReadFiles(const std::string& SamplePath, const std::string& TreeName);

   void Init(const TString& configFile);
   bool EventSelections();
   std::string ElectronsCombIdx();
   //void InterpString(string s, vector<float> & f);
   //void InterpString(string s, int & i, int & j, int & p, int & q);
   //int  LocateCrackIdx(string s);
   std::map<string, double> CreateCellMap(vector<float>eta_edges, vector<float>pt_edges);
   std::string SortOutCell(string elecscombidx, Float_t eta0, Float_t pt0, Float_t eta1, Float_t pt1);

   void FillCells();

   //void Likelihood(int & npar, double* gout, double & func, double *par, int flg);
   void Minimize();

   std::unique_ptr<TChain>   fChain = 0;  //!unique pointer to the nominal TChain
   Int_t           fCurrent;                   //!current Tree number in a TChain

   Double_t weight;
   Float_t Mll01;
   Int_t total_charge;
   Float_t lep_Pt_0;
   Float_t lep_Pt_1;
   Float_t lep_Eta_0;
   Float_t lep_Eta_1;
   Char_t  lep_isTightLH_0;
   Char_t  lep_isTightLH_1;
   Int_t   lep_isolationFixedCutTight_0;
   Int_t   lep_isolationFixedCutLoose_0;
   Int_t   lep_isolationFixedCutTight_1;
   Int_t   lep_isolationFixedCutLoose_1;
   
   TBranch *b_weight;
   TBranch *b_Mll01;
   TBranch *b_total_charge;
   TBranch *b_lep_Pt_0;
   TBranch *b_lep_Pt_1;
   TBranch *b_lep_Eta_0;
   TBranch *b_lep_Eta_1;
   TBranch *b_lep_isTightLH_0;
   TBranch *b_lep_isTightLH_1;
   TBranch *b_lep_isolationFixedCutTight_0;
   TBranch *b_lep_isolationFixedCutLoose_0;
   TBranch *b_lep_isolationFixedCutTight_1;
   TBranch *b_lep_isolationFixedCutLoose_1;

   //Methods to get the value from configuration files
   void ConfigFromFile(bool& property, const std::string &propname, TEnv &rEnv) {
   property = rEnv.GetValue(propname.c_str(), (int) property);
   }
   void ConfigFromFile(int& property, const std::string &propname, TEnv &rEnv) {
   property = rEnv.GetValue(propname.c_str(), property);
   }
   void ConfigFromFile(std::string& property, const std::string &propname, TEnv &rEnv) {
   property = rEnv.GetValue(propname.c_str(), property.c_str());
   }
   //void ConfigFromFile(TString& property, const std::string &propname, TEnv &rEnv) {
   //property = rEnv.GetValue(propname.c_str(), property);
   //}

   //config set in config file
   string m_RunName;
   bool m_isData;
   bool m_doTruthMatching;
   bool m_doAbsoluteEta;
   string m_Selections; //must be TString, thus can be properly interpreted by TTreeFormulas later on
   string m_ElectronTight;
   string m_ElectronAntiTight;
   int    m_ElectronsCase;
   string m_Eta;
   string m_Pt;
   string m_SS_boundaries;
   string m_OS_boundaries;
   //binning edges
   vector<float> m_eta_edges;
   vector<float> m_pt_edges;
   vector<float> m_SS_edges;
   vector<float> m_OS_edges;
   int m_crack_idx_pos;//the starting idx of crack region (postive side)
   int m_crack_idx_neg;//the starting idx of crack region (negtive side)
   //nbins
   //int nbins_eta_wocrk; //nbins after removing crack region(if there is)
   //int nbins_eta;
   //int nbins_pt;
   //maps for SS/OS events
   //std::map<string, double> ss_counts;      
   //std::map<string, double> os_counts;
   TTreeFormula * m_SelectionsFormula;
   TTreeFormula * m_Electron0TightFormula;      
   TTreeFormula * m_Electron1TightFormula;      
   TTreeFormula * m_Electron0AntiTightFormula;      
   TTreeFormula * m_Electron1AntiTightFormula;      
};
#endif
