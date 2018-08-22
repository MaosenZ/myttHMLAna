//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 26 15:26:33 2018 by ROOT version 6.10/04
// from TTree Tmva1l2tau/TMVA 1l2tau ntuple
// found on file: ../../../Hist/25ns_R21Skim/FakeMini/MytthAnaSkim_ttbarnohad_powhpy8_mc16av5.root
//////////////////////////////////////////////////////////

#ifndef AnatthMini_h
#define AnatthMini_h

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <TH1.h>
#include <TH2.h>
#include <TRandom.h>
#include <TLorentzVector.h>
#include <TVector.h>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;

class AnatthMini {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   double          myBDT;
   double          myBDTx;
   Float_t         Event;
   Float_t         Run;
   Float_t         Evtclass;
   Float_t         Weight;
   Float_t         Njets25;
   Float_t         Nbjets25;
   Float_t         Met;
   Float_t         Lept;
   Float_t         Htjets;
   Float_t         Leadtaupt;
   Float_t         Subtaupt;
   Float_t         Leadtaueta;
   Float_t         Subtaueta;
   Float_t         Leadtautight;
   Float_t         Subtautight;
   Float_t         Leadtauntrk;
   Float_t         Subtauntrk;
   Float_t         Leadtaubdtjetscore;
   Float_t         Subtaubdtjetscore;
   Float_t         Mtautau;
   Float_t         Ljdr;
   Float_t         Jjdr;
   Float_t         Drtautau;
   Float_t         Pttautau;
   Float_t         Drltautau;
   Float_t         Leadtaubtag;
   Float_t         Subtaubtag;
   Float_t         LeadtaubtagBin;
   Float_t         SubtaubtagBin;
   Float_t         Leadtauptv;
   Float_t         Subtauptv;
   Float_t         Leadtautruth;
   Float_t         Subtautruth;
   Float_t         Leadtauch;
   Float_t         Subtauch;
   Float_t         Bdt;
   Float_t         Drltau;
   Float_t         Drtauj;
   Float_t         Mtauj;
   Float_t         Drmetditau;
   Float_t         Plv;
   Float_t         Lepid;
   Float_t         Leptruth;
   Float_t         Etamax;
   Float_t         Leptrig;
   Float_t         Lepqmistight;
   Float_t         LepambiguityType;
   Float_t         Leadfrompv;
   Float_t         Subfrompv;


   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evtclass;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_Njets25;   //!
   TBranch        *b_Nbjets25;   //!
   TBranch        *b_Met;   //!
   TBranch        *b_Lept;   //!
   TBranch        *b_Htjets;   //!
   TBranch        *b_Leadtaupt;   //!
   TBranch        *b_Subtaupt;   //!
   TBranch        *b_Leadtaueta;   //!
   TBranch        *b_Subtaueta;   //!
   TBranch        *b_Leadtautight;   //!
   TBranch        *b_Subtautight;   //!
   TBranch        *b_Leadtauntrk;   //!
   TBranch        *b_Subtauntrk;   //!
   TBranch        *b_Leadtaubdtjetscore;   //!
   TBranch        *b_Subtaubdtjetscore;   //!
   TBranch        *b_Mtautau;   //!
   TBranch        *b_Ljdr;   //!
   TBranch        *b_Jjdr;   //!
   TBranch        *b_Drtautau;   //!
   TBranch        *b_Pttautau;   //!
   TBranch        *b_Drltautau;   //!
   TBranch        *b_Leadtaubtag;   //!
   TBranch        *b_Subtaubtag;   //!
   TBranch        *b_LeadtaubtagBin;   //!
   TBranch        *b_SubtaubtagBin;   //!
   TBranch        *b_Leadtauptv;   //!
   TBranch        *b_Subtauptv;   //!
   TBranch        *b_Leadtautruth;   //!
   TBranch        *b_Subtautruth;   //!
   TBranch        *b_Leadtauch;   //!
   TBranch        *b_Subtauch;   //!
   TBranch        *b_Bdt;   //!
   TBranch        *b_Drltau;   //!
   TBranch        *b_Drtauj;   //!
   TBranch        *b_Mtauj;   //!
   TBranch        *b_Drmetditau;   //!
   TBranch        *b_Plv;   //!
   TBranch        *b_Lepid;   //!
   TBranch        *b_Leptruth;   //!
   TBranch        *b_Etamax;   //!
   TBranch        *b_Leptrig;   //!
   TBranch        *b_Lepqmistight;   //!
   TBranch        *b_LepambiguityType;   //!
   TBranch        *b_Leadfrompv;   //!
   TBranch        *b_Subfrompv;   //!

   AnatthMini(TTree *tree=0);
   virtual ~AnatthMini();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void SetOutHistFile(TString name); //output of root                                                          
   void SetOutHistFile(TFile* f);
   TString GetOutHistFile(); // name of filelists                                                               
   void SetNevtAna(int nevt);
   int GetNevtAna();
   void SetSampleid(int id);
   void SetIsmc(bool ismc);
   void SetLum(double lum);
   void SetDebug(int debug);
   double DrEtaPhi(double eta1, double phi1, double eta2, double phi2);
 private:
   TFile* _histf; // output file                                                                                
   TString _outhist; // output file name                                                                        
   int _nevtAna; // number of events to analysis                                                                
   int _sampleid; // mc sample id                                                                               
   bool _ismc; // ismc or not                                                                                   
   int _debug; // set debug                                                                                     
   double _lum;
};

#endif

#ifdef AnatthMini_cxx
AnatthMini::AnatthMini(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../../Hist/25ns_R21Skim/FakeMini/MytthAnaSkim_ttbarnohad_powhpy8_mc16av5.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../../Hist/25ns_R21Skim/FakeMini/MytthAnaSkim_ttbarnohad_powhpy8_mc16av5.root");
      }
      f->GetObject("Tmva1l2tau",tree);

   }
*/
   Init(tree);
}

AnatthMini::~AnatthMini()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AnatthMini::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AnatthMini::LoadTree(Long64_t entry)
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

void AnatthMini::SetSampleid(int id){
  _sampleid = id;
}

void AnatthMini::SetIsmc(bool ismc){
  _ismc = ismc;
}

void AnatthMini::SetLum(double lum){
  _lum = lum;
}

void AnatthMini::SetDebug(int debug){
  _debug = debug;
}

double AnatthMini::DrEtaPhi(double eta1, double phi1, double eta2, double phi2){
  double dphi = fabs(phi2 - phi1);
  if(dphi>TMath::Pi())dphi = 2*TMath::Pi()-dphi;
  return sqrt(pow(dphi,2)+pow((eta2-eta1),2));
}


void AnatthMini::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evtclass", &Evtclass, &b_Evtclass);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("Njets25", &Njets25, &b_Njets25);
   fChain->SetBranchAddress("Nbjets25", &Nbjets25, &b_Nbjets25);
   fChain->SetBranchAddress("Met", &Met, &b_Met);
   fChain->SetBranchAddress("Lept", &Lept, &b_Lept);
   fChain->SetBranchAddress("Htjets", &Htjets, &b_Htjets);
   fChain->SetBranchAddress("Leadtaupt", &Leadtaupt, &b_Leadtaupt);
   fChain->SetBranchAddress("Subtaupt", &Subtaupt, &b_Subtaupt);
   fChain->SetBranchAddress("Leadtaueta", &Leadtaueta, &b_Leadtaueta);
   fChain->SetBranchAddress("Subtaueta", &Subtaueta, &b_Subtaueta);
   fChain->SetBranchAddress("Leadtautight", &Leadtautight, &b_Leadtautight);
   fChain->SetBranchAddress("Subtautight", &Subtautight, &b_Subtautight);
   fChain->SetBranchAddress("Leadtauntrk", &Leadtauntrk, &b_Leadtauntrk);
   fChain->SetBranchAddress("Subtauntrk", &Subtauntrk, &b_Subtauntrk);
   fChain->SetBranchAddress("Leadtaubdtjetscore", &Leadtaubdtjetscore, &b_Leadtaubdtjetscore);
   fChain->SetBranchAddress("Subtaubdtjetscore", &Subtaubdtjetscore, &b_Subtaubdtjetscore);
   fChain->SetBranchAddress("Mtautau", &Mtautau, &b_Mtautau);
   fChain->SetBranchAddress("Ljdr", &Ljdr, &b_Ljdr);
   fChain->SetBranchAddress("Jjdr", &Jjdr, &b_Jjdr);
   fChain->SetBranchAddress("Drtautau", &Drtautau, &b_Drtautau);
   fChain->SetBranchAddress("Pttautau", &Pttautau, &b_Pttautau);
   fChain->SetBranchAddress("Drltautau", &Drltautau, &b_Drltautau);
   fChain->SetBranchAddress("Leadtaubtag", &Leadtaubtag, &b_Leadtaubtag);
   fChain->SetBranchAddress("Subtaubtag", &Subtaubtag, &b_Subtaubtag);
   fChain->SetBranchAddress("LeadtaubtagBin", &LeadtaubtagBin, &b_LeadtaubtagBin);
   fChain->SetBranchAddress("SubtaubtagBin", &SubtaubtagBin, &b_SubtaubtagBin);
   fChain->SetBranchAddress("Leadtauptv", &Leadtauptv, &b_Leadtauptv);
   fChain->SetBranchAddress("Subtauptv", &Subtauptv, &b_Subtauptv);
   fChain->SetBranchAddress("Leadtautruth", &Leadtautruth, &b_Leadtautruth);
   fChain->SetBranchAddress("Subtautruth", &Subtautruth, &b_Subtautruth);
   fChain->SetBranchAddress("Leadtauch", &Leadtauch, &b_Leadtauch);
   fChain->SetBranchAddress("Subtauch", &Subtauch, &b_Subtauch);
   fChain->SetBranchAddress("Bdt", &Bdt, &b_Bdt);
   fChain->SetBranchAddress("Drltau", &Drltau, &b_Drltau);
   fChain->SetBranchAddress("Drtauj", &Drtauj, &b_Drtauj);
   fChain->SetBranchAddress("Mtauj", &Mtauj, &b_Mtauj);
   fChain->SetBranchAddress("Drmetditau", &Drmetditau, &b_Drmetditau);
   fChain->SetBranchAddress("Plv", &Plv, &b_Plv);
   fChain->SetBranchAddress("Lepid", &Lepid, &b_Lepid);
   fChain->SetBranchAddress("Leptruth", &Leptruth, &b_Leptruth);
   fChain->SetBranchAddress("Etamax", &Etamax, &b_Etamax);
   fChain->SetBranchAddress("Leptrig", &Leptrig, &b_Leptrig);
   fChain->SetBranchAddress("Lepqmistight", &Lepqmistight, &b_Lepqmistight);
   fChain->SetBranchAddress("LepambiguityType", &LepambiguityType, &b_LepambiguityType);
   fChain->SetBranchAddress("Leadfrompv", &Leadfrompv, &b_Leadfrompv);
   fChain->SetBranchAddress("Subfrompv", &Subfrompv, &b_Subfrompv);

   Notify();
}

Bool_t AnatthMini::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AnatthMini::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AnatthMini::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void AnatthMini::SetOutHistFile(TString name){
  std::cout<<" name of output=" << name <<std::endl;
  _outhist = name;
  TString nameroot;
  TString nametxt;
  TString namelist;
  TString namex = name;
  nameroot= namex+".root";
  nametxt= namex+".txt";
  namelist =namex+".list";
  std::cout<< " root file will be created="<<nameroot<<std::endl;
}

void AnatthMini::SetOutHistFile(TFile* f){
  _histf = f;
}

TString AnatthMini::GetOutHistFile(){
  return _outhist;
}

void AnatthMini::SetNevtAna(int nevt){
  _nevtAna = nevt;
}
int AnatthMini::GetNevtAna(){
  return _nevtAna;
}
#endif // #ifdef AnatthMini_cxx
