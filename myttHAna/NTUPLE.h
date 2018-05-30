//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Feb 16 21:32:40 2018 by ROOT version 6.10/04
// from TTree nominal/tree
// found on file: /global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_v2901PLICFTSkimNew/MytthAnaSkim_zljets_merged.root
//////////////////////////////////////////////////////////

#ifndef NTUPLE_h
#define NTUPLE_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <fstream>
#include "TH1F.h"
#include "Declarations.h"
#include <iomanip>
#include <cmath>
using namespace std;
using namespace Declarations;

class NTUPLE {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   vector<float>   counts;
   int             tree_number;
   double SumOfTotalWeightedEvents;
   // Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        mcWeightOrg;
   Double_t        pileupEventWeight_090;
   Double_t        bTagSF_weight_Continuous;
   Double_t        MV2c10_60_EventWeight;
   Double_t        MV2c10_70_EventWeight;
   Double_t        MV2c10_77_EventWeight;
   Double_t        MV2c10_85_EventWeight;
   Double_t        MV2c10_Continuous_EventWeight;
   Double_t        JVT_EventWeight;
   ULong64_t       EventNumber;
   Float_t         scale_nom;
   UInt_t          RunNumber;
   UInt_t          lbn;
   UInt_t          bcid;
   Bool_t          passEventCleaning;
   Float_t         m_vxp_x;
   Float_t         m_vxp_y;
   Float_t         m_vxp_z;
   Double_t        SherpaNJetWeight;
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
   Int_t           m_MEphoton_mother_pdgId;
   Float_t         m_MEphoton_mother_pt;
   Float_t         m_MEphoton_mother_eta;
   Float_t         m_MEphoton_mother_phi;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_RefFinal_sumet;
   Char_t          HLT_2e12_lhloose_L12EM10VH;
   Char_t          HLT_2e12_lhvloose_nod0_L12EM10VH;
   Char_t          HLT_2e17_lhvloose_nod0;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e140_lhloose;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_e17_lhloose_mu14;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu18_mu8noL1;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_mu50;
   Char_t          HLT_mu22_mu8noL1;

   std::vector<std::string> lep_input_vars  = {"ID/F","Pt/F","E/F","Eta/F","Phi/F","EtaBE2/F","sigd0PV/F","Z0SinTheta/F","isTightLH/B","isMediumLH/B","isLooseLH/B","isTight/B","isMedium/B","isLoose/B","isolationLooseTrackOnly/I","isolationLoose/I","isolationFixedCutTight/I","isolationFixedCutTightTrackOnly/I","isolationFixedCutLoose/I","topoEtcone20/F","ptVarcone20/F","ptVarcone30/F","promptLeptonIso_TagWeight/F","promptLeptonVeto_TagWeight/F","ambiguityType/B","chargeIDBDTLoose/F","chargeIDBDTMedium/F","chargeIDBDTTight/F","isPrompt/B","isBrems/B","isQMisID/B","truthType/I","truthOrigin/I","truthParentType/I","truthParentOrigin/I","truthParentPdgId/I","SFIDLoose/F","SFIDTight/F","SFTrigLoose/F","SFTrigTight/F","EffTrigLoose/F","EffTrigTight/F","SFIsoLoose/F","SFIsoTight/F","SFReco/F","SFTTVA/F","SFObjLoose/F","SFObjTight/F"};
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_isTrigMatchDLT_0;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_isTrigMatchDLT_1;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_isTrigMatchDLT_2;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_isTrigMatchDLT_3;
   std::map< std::string, Branch_Types > input_branches;

   std::vector<std::string> tau_input_vars ={"pt/F", "eta/F", "phi/F", "charge/F", "E/F", "BDTJetScore/D", "JetBDTSigLoose/I", "JetBDTSigMedium/I", "JetBDTSigTight/I", "numTrack/I", "isHadronic/I", "tagWeightBin/I", "fromPV/B", "SFTight/F", "SFLoose/F", "passEleOLR/I", "passEleBDT/I", "passMuonOLR/I", "truthOrigin/I", "truthType/I", "truthJetFlavour/I","tight/F"};

   Int_t           onelep_type;
   Int_t           dilep_type;
   Int_t           trilep_type;
   Int_t           quadlep_type;
   Int_t           total_charge;
   Int_t           total_leptons;
   Char_t          isQMisIDEvent;
   Char_t          isFakeEvent;
   Char_t          isLepFromPhEvent;
   Char_t          matchDLTll01;
   Char_t          matchDLTll02;
   Char_t          matchDLTll03;
   Char_t          matchDLTll12;
   Char_t          matchDLTll13;
   Char_t          matchDLTll23;
  
   std::vector<std::string> event_input_vars={"Mll01/F", "Ptll01/F", "DRll01/F", "Mlll012/F", "Mllll0123/F","Mlll013/F","Mll02/F", "Ptll02/F", "DRll02/F", "Mlll023/F","Mll03/F", "Ptll03/F", "DRll03/F", "Mll12/F", "Ptll12/F", "DRll12/F", "Mlll123/F", "Mll13/F", "Ptll13/F", "DRll13/F", "Mll23/F", "Ptll23/F", "DRll23/F", "best_Z_Mll/F", "best_Z_other_Mll/F", "minOSSFMll/F", "minOSMll","HT/F","HT_lep/F","HT_jets/F","htjets_1l2tau/F","jjdrmin_1l2tau/F","mtautau_1l2tau/F","njets_1l2tau/F","nbjets_1l2tau/F","nJets_OR_T/I","nJets_OR_T_MV2c20_70/I","nJets_OR_T_MV2c10_70/I","MVA1l2tau_weight/F"};
   Int_t           nJets_OR;
   Int_t           nJets_OR_T_MV2c20_60;
   Int_t           nJets_OR_T_MV2c20_77;
   Int_t           nJets_OR_T_MV2c20_85;
   Int_t           nJets_OR_MV2c20_85;
   Int_t           nJets_OR_MV2c20_60;
   Int_t           nJets_OR_MV2c20_77;
   Int_t           nJets_OR_MV2c20_70;
   Int_t           nJets_OR_T_MV2c10_60;
   Int_t           nJets_OR_T_MV2c10_77;
   Int_t           nJets_OR_T_MV2c10_85;
   Int_t           nJets_OR_MV2c10_85;
   Int_t           nJets_OR_MV2c10_60;
   Int_t           nJets_OR_MV2c10_77;
   Int_t           nJets_OR_MV2c10_70;
   Int_t           nTaus_OR_Pt25;
   Bool_t          isBlinded;
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
   Float_t        tau_btag70_0;
   Int_t           tau_truth_0;
   Float_t        tau_btag70_1;
   Int_t           tau_truth_1;

   NTUPLE(string inputSample);
   virtual ~NTUPLE();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   //virtual void     makeMiniTree();
   virtual void     fillHistsMiniTree(std::map<string, TH1F* > & TH1Fs, TTree *minitree);
   virtual void     cutFlow();
   virtual bool     commonSelections();
   virtual double   commonWeight();
   virtual bool     applySelections(string selection);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef NTUPLE_cxx
NTUPLE::NTUPLE(string inputSample) : fChain(0) 
{
   TChain *chain=new TChain(m_treeName);

   string inputlist=prefix+inputSample+".list";
   ifstream inputfile(inputlist.c_str(), ifstream::in);
   string line;
   while (getline(inputfile, line)){
          TString ifile=prepath+line;
          chain->Add(ifile);    
 
          /*TFile countfile(ifile);  
          TH1* hist_count=(TH1*)countfile.Get("loose/Count");
          counts.push_back(hist_count->GetBinContent(2));*/
   }
   Init(chain);
   tree_number=0; 
   mySample=inputSample;
}

NTUPLE::~NTUPLE()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NTUPLE::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NTUPLE::LoadTree(Long64_t entry)
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

void NTUPLE::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("scale_nom", &scale_nom);
   fChain->SetBranchAddress("mcWeightOrg", &mcWeightOrg); 
   fChain->SetBranchAddress("pileupEventWeight_090", &pileupEventWeight_090);
   fChain->SetBranchAddress("bTagSF_weight_Continuous", &bTagSF_weight_Continuous);
   fChain->SetBranchAddress("MV2c10_60_EventWeight", &MV2c10_60_EventWeight);
   fChain->SetBranchAddress("MV2c10_70_EventWeight", &MV2c10_70_EventWeight);
   fChain->SetBranchAddress("MV2c10_77_EventWeight", &MV2c10_77_EventWeight);
   fChain->SetBranchAddress("MV2c10_85_EventWeight", &MV2c10_85_EventWeight);
   fChain->SetBranchAddress("MV2c10_Continuous_EventWeight", &MV2c10_Continuous_EventWeight);
   fChain->SetBranchAddress("JVT_EventWeight", &JVT_EventWeight);
   fChain->SetBranchAddress("EventNumber", &EventNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber);
   fChain->SetBranchAddress("lbn", &lbn);
   fChain->SetBranchAddress("bcid", &bcid);
   fChain->SetBranchAddress("passEventCleaning", &passEventCleaning);
   fChain->SetBranchAddress("m_vxp_x", &m_vxp_x);
   fChain->SetBranchAddress("m_vxp_y", &m_vxp_y);
   fChain->SetBranchAddress("m_vxp_z", &m_vxp_z);
   fChain->SetBranchAddress("SherpaNJetWeight", &SherpaNJetWeight);
   fChain->SetBranchAddress("higgs_pt", &higgs_pt);
   fChain->SetBranchAddress("higgs_eta", &higgs_eta);
   fChain->SetBranchAddress("higgs_phi", &higgs_phi);
   fChain->SetBranchAddress("higgs_E", &higgs_E);
   fChain->SetBranchAddress("higgs_rapidity", &higgs_rapidity);
   fChain->SetBranchAddress("top_pt", &top_pt);
   fChain->SetBranchAddress("top_eta", &top_eta);
   fChain->SetBranchAddress("top_phi", &top_phi);
   fChain->SetBranchAddress("top_E", &top_E);
   fChain->SetBranchAddress("antitop_pt", &antitop_pt);
   fChain->SetBranchAddress("antitop_eta", &antitop_eta);
   fChain->SetBranchAddress("antitop_phi", &antitop_phi);
   fChain->SetBranchAddress("antitop_E", &antitop_E);
   fChain->SetBranchAddress("RunYear", &RunYear);
   fChain->SetBranchAddress("HF_Classification", &HF_Classification);
   fChain->SetBranchAddress("HF_ClassificationTop", &HF_ClassificationTop);
   fChain->SetBranchAddress("DLF_Classification", &DLF_Classification);
   fChain->SetBranchAddress("higgsDecayMode", &higgsDecayMode);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number);
   fChain->SetBranchAddress("mc_isAFII", &mc_isAFII);
   fChain->SetBranchAddress("averageIntPerXing_uncorr", &averageIntPerXing_uncorr);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing);
   fChain->SetBranchAddress("m_vxp_n", &m_vxp_n);
   fChain->SetBranchAddress("m_vxpu_n", &m_vxpu_n);
   fChain->SetBranchAddress("m_hasMEphoton", &m_hasMEphoton);
   fChain->SetBranchAddress("m_hasMEphoton_DRgt02_nonhad", &m_hasMEphoton_DRgt02_nonhad);
   fChain->SetBranchAddress("m_MEphoton_OLtty_keepEvent", &m_MEphoton_OLtty_keepEvent);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat1", &m_MEphoton_OLtty_cat1);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat2", &m_MEphoton_OLtty_cat2);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat3", &m_MEphoton_OLtty_cat3);
   fChain->SetBranchAddress("m_MEphoton_OLtty_cat4", &m_MEphoton_OLtty_cat4);
   fChain->SetBranchAddress("m_MEphoton_pt", &m_MEphoton_pt);
   fChain->SetBranchAddress("m_MEphoton_eta", &m_MEphoton_eta);
   fChain->SetBranchAddress("m_MEphoton_phi", &m_MEphoton_phi);
   fChain->SetBranchAddress("m_MEphoton_mother_pdgId", &m_MEphoton_mother_pdgId);
   fChain->SetBranchAddress("m_MEphoton_mother_pt", &m_MEphoton_mother_pt);
   fChain->SetBranchAddress("m_MEphoton_mother_eta", &m_MEphoton_mother_eta);
   fChain->SetBranchAddress("m_MEphoton_mother_phi", &m_MEphoton_mother_phi);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_2e12_lhvloose_nod0_L12EM10VH", &HLT_2e12_lhvloose_nod0_L12EM10VH);
   fChain->SetBranchAddress("HLT_2e17_lhvloose_nod0", &HLT_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose", &HLT_e140_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15",&HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu50",&HLT_mu50);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH",&HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e60_lhmedium",&HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium",&HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose",&HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0",&HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1",&HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH",&HLT_2e12_lhloose_L12EM10VH);

   std::string branchname, branchtype, key;
   for ( const auto& var : lep_input_vars ) {

        key = var.substr( 0, var.length() - 2 );

        branchtype = var.substr( var.length() - 1 );

        for (int idx(0); idx < 4; ++idx ) {

            branchname = "lep_" + key + "_" + std::to_string(idx);

            if ( branchtype.compare("F") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].f ); }
            if ( branchtype.compare("D") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].d ); }
            if ( branchtype.compare("B") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].c ); }
            if ( branchtype.compare("I") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].i ); }
        }
   }
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3);
 
   for ( const auto& var : tau_input_vars ) {

        key = var.substr( 0, var.length() - 2 );

        branchtype = var.substr( var.length() - 1 );

        for (int idx(0); idx < 2; ++idx ) {

            branchname = "tau_" + key + "_" + std::to_string(idx);

            if ( branchtype.compare("F") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].f ); }
            if ( branchtype.compare("D") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].d ); }
            if ( branchtype.compare("B") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].c ); }
            if ( branchtype.compare("I") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].i ); }
        }
   }

   fChain->SetBranchAddress("onelep_type", &onelep_type);
   fChain->SetBranchAddress("dilep_type", &dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type);
   fChain->SetBranchAddress("total_charge", &total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons);
   fChain->SetBranchAddress("isQMisIDEvent", &isQMisIDEvent);
   fChain->SetBranchAddress("isFakeEvent", &isFakeEvent);
   fChain->SetBranchAddress("isLepFromPhEvent", &isLepFromPhEvent);
   fChain->SetBranchAddress("matchDLTll02", &matchDLTll02);
   fChain->SetBranchAddress("matchDLTll03", &matchDLTll03);
   fChain->SetBranchAddress("matchDLTll12", &matchDLTll12);
   fChain->SetBranchAddress("matchDLTll13", &matchDLTll13);
   fChain->SetBranchAddress("matchDLTll23", &matchDLTll23);
   
   for ( const auto& var : event_input_vars ) {

        branchname = var.substr( 0, var.length() - 2 );

        branchtype = var.substr( var.length() - 1 );

        if ( branchtype.compare("F") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].f ); }
        if ( branchtype.compare("D") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].d ); }
        if ( branchtype.compare("B") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].c ); }
        if ( branchtype.compare("I") == 0 )   { fChain->SetBranchAddress ( branchname.c_str(),   &input_branches[branchname].i ); }
   }

   fChain->SetBranchAddress("nJets_OR", &nJets_OR);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_60", &nJets_OR_T_MV2c20_60);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_77", &nJets_OR_T_MV2c20_77);
   fChain->SetBranchAddress("nJets_OR_T_MV2c20_85", &nJets_OR_T_MV2c20_85);
   fChain->SetBranchAddress("nJets_OR_MV2c20_85", &nJets_OR_MV2c20_85);
   fChain->SetBranchAddress("nJets_OR_MV2c20_60", &nJets_OR_MV2c20_60);
   fChain->SetBranchAddress("nJets_OR_MV2c20_77", &nJets_OR_MV2c20_77);
   fChain->SetBranchAddress("nJets_OR_MV2c20_70", &nJets_OR_MV2c20_70);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_60", &nJets_OR_T_MV2c10_60);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_77", &nJets_OR_T_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_85", &nJets_OR_T_MV2c10_85);
   fChain->SetBranchAddress("nJets_OR_MV2c10_85", &nJets_OR_MV2c10_85);
   fChain->SetBranchAddress("nJets_OR_MV2c10_60", &nJets_OR_MV2c10_60);
   fChain->SetBranchAddress("nJets_OR_MV2c10_77", &nJets_OR_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_MV2c10_70", &nJets_OR_MV2c10_70);
   fChain->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25);
   fChain->SetBranchAddress("isBlinded", &isBlinded);
   fChain->SetBranchAddress("lead_jetPt", &lead_jetPt);
   fChain->SetBranchAddress("lead_jetEta", &lead_jetEta);
   fChain->SetBranchAddress("lead_jetPhi", &lead_jetPhi);
   fChain->SetBranchAddress("lead_jetE", &lead_jetE);
   fChain->SetBranchAddress("sublead_jetPt", &sublead_jetPt);
   fChain->SetBranchAddress("sublead_jetEta", &sublead_jetEta);
   fChain->SetBranchAddress("sublead_jetPhi", &sublead_jetPhi);
   fChain->SetBranchAddress("sublead_jetE", &sublead_jetE);
   fChain->SetBranchAddress("lepSFTrigLoose", &lepSFTrigLoose);
   fChain->SetBranchAddress("lepSFTrigTight", &lepSFTrigTight);
   fChain->SetBranchAddress("lepSFTrigTightLoose", &lepSFTrigTightLoose);
   fChain->SetBranchAddress("lepSFTrigLooseTight", &lepSFTrigLooseTight);
   fChain->SetBranchAddress("lepEffTrigLoose", &lepEffTrigLoose);
   fChain->SetBranchAddress("lepEffTrigTight", &lepEffTrigTight);
   fChain->SetBranchAddress("lepEffTrigTightLoose", &lepEffTrigTightLoose);
   fChain->SetBranchAddress("lepEffTrigLooseTight", &lepEffTrigLooseTight);
   fChain->SetBranchAddress("lepDataEffTrigLoose", &lepDataEffTrigLoose);
   fChain->SetBranchAddress("lepDataEffTrigTight", &lepDataEffTrigTight);
   fChain->SetBranchAddress("lepDataEffTrigTightLoose", &lepDataEffTrigTightLoose);
   fChain->SetBranchAddress("lepDataEffTrigLooseTight", &lepDataEffTrigLooseTight);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight);
   fChain->SetBranchAddress("tauSFTight", &tauSFTight);
   fChain->SetBranchAddress("tauSFLoose", &tauSFLoose);
   fChain->SetBranchAddress("tau_btag70_0", &tau_btag70_0);
   if(!mySample.Contains("data") ){
      fChain->SetBranchAddress("tau_truth_0", &tau_truth_0);
      fChain->SetBranchAddress("tau_truth_1", &tau_truth_1);
   }
   fChain->SetBranchAddress("tau_btag70_1", &tau_btag70_1);
   Notify();
}

Bool_t NTUPLE::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   cout<<"a new file is opened"<<endl;
   tree_number += 1;
   return kTRUE;
}

void NTUPLE::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NTUPLE::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

//my defined functions
//std::map<string, std::shared_ptr<TH1F> > TH1Fs; 
#endif 
