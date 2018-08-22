/**********************************************************************************
 * Project   : TMVA - a Root-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Exectuable: TMVAClassificationApplication                                      *
 *                                                                                *
 * This macro provides a simple example on how to use the trained classifiers     *
 * within an analysis module                                                      *
 **********************************************************************************/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMath.h"
#include "TStopwatch.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Reader.h"
#include "TMVA/Config.h"
#include "TMVA/Tools.h"
#include "TMVA/MethodCuts.h"
#include "RooStats/NumberCountingUtils.h"
#include "EWPlotMacros.h" 
#include "HistoUtils.h"
#endif

using namespace TMVA;
using namespace RooStats;
using namespace std;
void CalculateRoofitSignicance(Float_t e_sig, Float_t e_bkg, Float_t e_sig_err, Float_t e_bkg_err, Float_t e_bkg_sys_err, Float_t &roofitSignificance, Float_t &roofitSignificance_err){
  cout<<e_sig<<"\t"<<e_bkg<<endl;
  roofitSignificance=RooStats :: NumberCountingUtils :: BinomialExpZ(e_sig,e_bkg,e_bkg_sys_err);
  Float_t significance_variations[4];
  significance_variations[0]=RooStats :: NumberCountingUtils :: BinomialExpZ(e_sig+e_sig_err,e_bkg,e_bkg_sys_err);
  significance_variations[1]=RooStats :: NumberCountingUtils :: BinomialExpZ(e_sig-e_sig_err,e_bkg,e_bkg_sys_err);
  significance_variations[2]=RooStats :: NumberCountingUtils :: BinomialExpZ(e_sig,e_bkg+e_bkg_err,e_bkg_sys_err);
  significance_variations[3]=RooStats :: NumberCountingUtils :: BinomialExpZ(e_sig,e_bkg-e_bkg_err,e_bkg_sys_err);

  Float_t significance_e_sig_err=significance_variations[0]>significance_variations[1]?significance_variations[0]:significance_variations[1];
  Float_t significance_e_bkg_err=significance_variations[2]>significance_variations[3]?significance_variations[2]:significance_variations[3];
  
  significance_e_sig_err=significance_e_sig_err-roofitSignificance;
  significance_e_bkg_err=significance_e_bkg_err-roofitSignificance;
  if(TMath::Finite(significance_variations[0])!=1) significance_e_sig_err=significance_variations[1];
  if(TMath::Finite(significance_variations[1])!=1) significance_e_sig_err=significance_variations[0];
  if(TMath::Finite(significance_variations[2])!=1) significance_e_bkg_err=significance_variations[3];
  if(TMath::Finite(significance_variations[3])!=1) significance_e_bkg_err=significance_variations[2];
  roofitSignificance_err=sqrt(pow(significance_e_sig_err,2.0)+pow(significance_e_bkg_err,2.0));
  if(TMath::Finite(roofitSignificance)!=1) roofitSignificance=0;
  if(TMath::Finite(roofitSignificance_err)!=1) roofitSignificance_err=0;
  

 }
void CalculateCowanSignicance(Float_t e_sig, Float_t e_bkg, Float_t e_sig_err, Float_t e_bkg_err, Float_t e_bkg_sys_err, Float_t &CowanSignificance, Float_t &CowanSignificance_err){

  CowanSignificance=sqrt(2*((e_sig+(e_bkg+ e_bkg_sys_err*e_bkg))*log(1.+e_sig/(e_bkg+ e_bkg_sys_err*e_bkg))-e_sig));
  Float_t significance_variations[4];
  significance_variations[0]=sqrt(2*((e_sig+e_sig_err+(e_bkg+ e_bkg_sys_err*e_bkg))*log(1.+(e_sig+e_sig_err)/(e_bkg+ e_bkg_sys_err*e_bkg))-(e_sig+e_sig_err))); 
  significance_variations[1]=sqrt(2*((e_sig-e_sig_err+(e_bkg+ e_bkg_sys_err*e_bkg))*log(1.+(e_sig-e_sig_err)/(e_bkg+ e_bkg_sys_err*e_bkg))-(e_sig-e_sig_err)));  
  significance_variations[2]=sqrt(2*((e_sig+(e_bkg+e_bkg_err)*(1.0+ e_bkg_sys_err))*log(1.+e_sig/((e_bkg+e_bkg_err)*(1.0+ e_bkg_sys_err)))-e_sig)); 
  significance_variations[3]=sqrt(2*((e_sig+(e_bkg-e_bkg_err)*(1.0+ e_bkg_sys_err))*log(1.+e_sig/((e_bkg-e_bkg_err)*(1.0+ e_bkg_sys_err)))-e_sig)); 
  Float_t significance_e_sig_err=significance_variations[0]>significance_variations[1]?significance_variations[0]:significance_variations[1];
  Float_t significance_e_bkg_err=significance_variations[2]>significance_variations[3]?significance_variations[2]:significance_variations[3];
  
  if(TMath::Finite(significance_variations[0])!=1) significance_e_sig_err=significance_variations[1];
  if(TMath::Finite(significance_variations[1])!=1) significance_e_sig_err=significance_variations[0];
  if(TMath::Finite(significance_variations[2])!=1) significance_e_bkg_err=significance_variations[3];
  if(TMath::Finite(significance_variations[3])!=1) significance_e_bkg_err=significance_variations[2];

  significance_e_sig_err=significance_e_sig_err-CowanSignificance;
  significance_e_bkg_err=significance_e_bkg_err-CowanSignificance;
  CowanSignificance_err=sqrt(pow(significance_e_sig_err,2.0)+pow(significance_e_bkg_err,2.0));
  if(TMath::Finite(CowanSignificance)!=1) CowanSignificance=0;
  if(TMath::Finite(CowanSignificance_err)!=1) CowanSignificance_err=0;

}


void PlotScanEff(TH1F *h, TH1F *h1, TString filename){
int style=-1;
TCanvas* c1 = EWCreateTCanvas();
h->SetXTitle("Signal MVA cuts Eff. WP");
 if(filename.Contains("Significance")){
 EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(), "Significance");
 EWBeautify(h1,POINT_1, h->GetXaxis()->GetTitle(), "Significance");}
 else{
   EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(), "Ratio");
   EWBeautify(h1,POINT_1, h->GetXaxis()->GetTitle(), "Ratio");

 }

h->SetFillColor(0);
h->SetMarkerColor(2);
h->SetLineColor(2);
h1->SetFillColor(0);
h1->SetMarkerColor(4);
h1->SetLineColor(4);
 if(filename.Contains("Significance")){
h->SetAxisRange(-0.4,0.55,"Y");
h1->SetAxisRange(-0.4,0.55,"Y");
 }
 else{
   
   h->SetAxisRange(0,0.5,"Y");
   h1->SetAxisRange(0,0.5,"Y");
   h->SetAxisRange(0.3,1,"X");
   h1->SetAxisRange(0.3,1,"X");

 }
EWDraw(h);
EWDraw(h1);
double x1,y1,x2,y2;

    x1 = 0.20;
    x2 = 0.50;
    y1 = 0.65;
    y2 = 0.9;

    TLegend* leg = new TLegend(x1,y1,x2,y2);
    leg->SetFillColor(0);
    leg->SetShadowColor(0);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.03);
    if(filename.Contains("Significance")){
    leg->AddEntry(h,"Roofit significance","lp");
    leg->AddEntry(h1,"Cowan significance","lp");}
    else{
      leg->AddEntry(h,"S/B","lp");
      leg->AddEntry(h1,"S/#sqrt{B}","lp");
    }
    leg->Draw("same"); 
    gPad->RedrawAxis();
    c1->SaveAs(Form("./../../2LSSAna/output/dataMC_3jets/SigOpt/nonres/%s.pdf",filename.Data()));
}

void PlotCowanScanEff(TH1F *h, TString filename){
int style=-1;
TCanvas* c1 = EWCreateTCanvas();
h->SetXTitle("Signal MVA cuts Eff. WP");
 std::string Ytitle;
 Float_t Ymax(1.0);
 if(filename.Contains("Cowan")){
EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(), "Significance");
 Ymax=0.3; 
}
 if(filename.Contains("SOverB")){
   EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(), "S/B");
   Ymax=0.5;
 }
 if(filename.Contains("SOverRootB")){
   EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(), "S/#sqrt{B}");
   Ymax=0.5; 
}

h->SetFillColor(0);
h->SetMarkerColor(2);
h->SetLineColor(2);

h->SetAxisRange(0,Ymax,"Y");

EWDraw(h);

double x1,y1,x2,y2;

    x1 = 0.20;
    x2 = 0.50;
    y1 = 0.65;
    y2 = 0.9;

    TLegend* leg = new TLegend(x1,y1,x2,y2);
    leg->SetFillColor(0);
    leg->SetShadowColor(0);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.03);
    if(filename.Contains("Cowan")) leg->AddEntry(h,"Cowan significance","lp");

    if(filename.Contains("Cowan")) leg->Draw("same"); 
    gPad->RedrawAxis();
    c1->SaveAs(Form("./../../2LSSAna/output/dataMC_3jets/SigOpt/nonres/%s.pdf",filename.Data()));

}

void PlotScanCuts(TH1F *h, TH1F *h1, TString which_variable){
int style=-1;
// deltaR_23,m_12,m_13,m_23,mindR_l2j,mindR_l3j;
 map<TString,std::string> Ylables;
 Ylables["MET_ee"]= "MET cut";
 Ylables["mindR_l2j_ee"]= "#Delta R_{l_{2}j} cut";
 Ylables["mindR_l1j_ee"]= "#Delta R_{l_{1}j} cut";
 Ylables["m_ll_ee"]= "M(ll) cut";
 Ylables["m_l1jj_ee"]= "M(l_{1}jj) cut";
 Ylables["m_all_ee"]= "M(all) cut";
 Ylables["MET_mumu"]= "MET cut";
 Ylables["mindR_l2j_mumu"]= "#Delta R_{l_{2}j} cut";
 Ylables["mindR_l1j_mumu"]= "#Delta R_{l_{1}j} cut";
 Ylables["m_ll_mumu"]= "M(ll) cut";
 Ylables["m_l1jj_mumu"]= "M(l_{1}jj) cut";
 Ylables["m_all_mumu"]= "M(all) cut";
 Ylables["MET_emu"]= "MET cut";
 Ylables["mindR_l2j_emu"]= "#Delta R_{l_{2}j} cut";
 Ylables["mindR_l1j_emu"]= "#Delta R_{l_{1}j} cut";
 Ylables["m_ll_emu"]= "M(ll) cut";
 Ylables["m_l1jj_emu"]= "M(l_{1}jj) cut";
 Ylables["m_all_emu"]= "M(all) cut";
 Ylables["Efficiency_ee"]= "Efficiency";
 Ylables["Efficiency_mumu"]= "Efficiency";
 Ylables["Efficiency_emu"]= "Efficiency";
 
TCanvas* c1 = EWCreateTCanvas();
h->SetXTitle("Signal MVA cuts Eff. WP");
EWBeautify(h,POINT_1, h->GetXaxis()->GetTitle(),  Ylables[which_variable]);
EWBeautify(h1,POINT_1, h->GetXaxis()->GetTitle(), Ylables[which_variable]);
h->SetFillColor(0);
h->SetMarkerColor(2);
h->SetLineColor(2);
h1->SetFillColor(0);
h1->SetMarkerColor(4);
h1->SetLineColor(4);
 Float_t min_Y=h->GetMinimum()*0.5;
 Float_t max_Y=h1->GetMaximum()*1.2;

 if(which_variable.Contains("Efficiency")) max_Y=1.2;

h->SetAxisRange(min_Y,max_Y,"Y");
h1->SetAxisRange(min_Y,max_Y,"Y");
h->SetAxisRange(0.305,0.995,"X");
h1->SetAxisRange(0.305,0.995,"X");
 
 h->Draw("hist");
 h1->Draw("histsame");

double x1,y1,x2,y2;

    x1 = 0.20;
    x2 = 0.50;
    y1 = 0.65;
    y2 = 0.9;

    TLegend* leg = new TLegend(x1,y1,x2,y2);
    leg->SetFillColor(0);
    leg->SetShadowColor(0);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.03);
    if(Ylables[which_variable].find("cut")!=-1){
       leg->AddEntry(h,"Lower cuts","lp");
       leg->AddEntry(h1,"Higher cuts","lp");}
    else{
    leg->AddEntry(h,"Signal efficiency","lp");
    leg->AddEntry(h1,"Background efficiency","lp");
    }
    
    leg->Draw("same"); 
    gPad->RedrawAxis();
    c1->SaveAs(Form("./../../2LSSAna/output/dataMC_3jets/SigOpt/nonres/%s.pdf",which_variable.Data()));

}

int main( int argc, char** argv )
{
   //fake factor
   Float_t ff_mu=0.34, ff_ele=0.61;
   std::string argStr = argv[1];
                 std::vector<std::string> filelist;
                 for(size_t si=0,n;si<=argStr.length();si=n+1){
                 n=argStr.find_first_of(',',si);
                 if(n==std::string::npos) n=argStr.length();
                 std::string tmp = argStr.substr(si,n-si);
                 std::cout<<tmp<<std::endl;
                 filelist.push_back(tmp);
                }
		 Int_t WP_min=std::atoi(filelist[0].c_str());
		 Int_t WP_max=std::atoi(filelist[1].c_str()); 
		 cout<<"Working point\t"<<WP_min<<"\t"<<WP_max<<endl;
   //---------------------------------------------------------------
   //---------------------------------------------------------------

   // ---------------------------------------------------------------
   // default MVA methods to be trained + tested
   std::map<std::string,int> Use;
   // ---
   
    Use["CutsSA"]          = 1;

    TMVA::Reader *reader_first = new TMVA::Reader( "!Color:!Silent" );
    TMVA::Reader *reader_second = new TMVA::Reader( "!Color:!Silent" );  

   // Create a set of variables and declare them to the reader
   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
   Float_t mindR_l1j,mindR_l2j,MET,m_ll,m_l1jj,m_all;
   reader_first->AddVariable("MET", &MET);
   reader_first->AddVariable( "m_ll",                &m_ll );
   reader_first->AddVariable( "m_all",                &m_all );
   reader_second->AddVariable( "mindR_l2j",                &mindR_l2j );
   reader_second->AddVariable( "mindR_l1j",                &mindR_l1j );
   reader_second->AddVariable( "m_l1jj",                &m_l1jj );
 
   // Spectator variables declared in the training have to be added to the reader, too
   //Float_t spec1,spec2;
   //reader_first->AddSpectator( "spec1 := var1*2",   &spec1 );
   //reader_first->AddSpectator( "spec2 := var1*3",   &spec2 );

   /*Float_t Category_cat1, Category_cat2, Category_cat3;
   if (Use["Category"]){
      // Add artificial spectators for distinguishing categories
      reader_first->AddSpectator( "Category_cat1 := var3<=0",             &Category_cat1 );
      reader_first->AddSpectator( "Category_cat2 := (var3>0)&&(var4<0)",  &Category_cat2 );
      reader_first->AddSpectator( "Category_cat3 := (var3>0)&&(var4>=0)", &Category_cat3 );
   }*/

   // --- Book the MVA methods

   TString dir    = "weights/";
   TString prefix = "TMVAClassification";

   // Book method(s)
   /*
   for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
      if(it->second) {
         TString methodName = TString(it->first) + TString(" method");
         TString weightfile = dir + prefix + TString("_") + TString(it->first) + TString(".weights.xml");
         reader_first->BookMVA( methodName, weightfile ); 
      }
      }*/
     reader_first->BookMVA("CutsSA ee First","weights/nonres_atlas/ee/firstgroup/TMVAClassification_CutsSA.weights.xml");
     reader_second->BookMVA("CutsSA ee Second","weights/nonres_atlas/ee/secondgroup/TMVAClassification_CutsSA.weights.xml");
     reader_first->BookMVA("CutsSA mumu First","weights/nonres_atlas/mumu/firstgroup/TMVAClassification_CutsSA.weights.xml");
     reader_second->BookMVA("CutsSA mumu Second","weights/nonres_atlas/mumu/secondgroup/TMVAClassification_CutsSA.weights.xml");
     reader_first->BookMVA("CutsSA emu First","weights/nonres_atlas/emu/firstgroup/TMVAClassification_CutsSA.weights.xml");
     reader_second->BookMVA("CutsSA emu Second","weights/nonres_atlas/emu/secondgroup/TMVAClassification_CutsSA.weights.xml");
   
   // Book output histograms
   UInt_t nbin = 100;
   TH1F   *histLk(0), *histLkD(0), *histLkPCA(0), *histLkKDE(0), *histLkMIX(0), *histPD(0), *histPDD(0);
   TH1F   *histPDPCA(0), *histPDEFoam(0), *histPDEFoamErr(0), *histPDEFoamSig(0), *histKNN(0), *histHm(0);
   TH1F   *histFi(0), *histFiG(0), *histFiB(0), *histLD(0), *histNn(0),*histNnbfgs(0),*histNnbnn(0);
   TH1F   *histNnC(0), *histNnT(0), *histBdt(0), *histBdtG(0), *histBdtD(0), *histRf(0), *histSVMG(0);
   TH1F   *histSVMP(0), *histSVML(0), *histFDAMT(0), *histFDAGA(0), *histCat(0), *histPBdt(0);

   if (Use["Likelihood"])    histLk      = new TH1F( "MVA_Likelihood",    "MVA_Likelihood",    nbin, -1, 1 );
   if (Use["LikelihoodD"])   histLkD     = new TH1F( "MVA_LikelihoodD",   "MVA_LikelihoodD",   nbin, -1, 0.9999 );
   if (Use["LikelihoodPCA"]) histLkPCA   = new TH1F( "MVA_LikelihoodPCA", "MVA_LikelihoodPCA", nbin, -1, 1 );
   if (Use["LikelihoodKDE"]) histLkKDE   = new TH1F( "MVA_LikelihoodKDE", "MVA_LikelihoodKDE", nbin,  -0.00001, 0.99999 );
   if (Use["LikelihoodMIX"]) histLkMIX   = new TH1F( "MVA_LikelihoodMIX", "MVA_LikelihoodMIX", nbin,  0, 1 );
   if (Use["PDERS"])         histPD      = new TH1F( "MVA_PDERS",         "MVA_PDERS",         nbin,  0, 1 );
   if (Use["PDERSD"])        histPDD     = new TH1F( "MVA_PDERSD",        "MVA_PDERSD",        nbin,  0, 1 );
   if (Use["PDERSPCA"])      histPDPCA   = new TH1F( "MVA_PDERSPCA",      "MVA_PDERSPCA",      nbin,  0, 1 );
   if (Use["KNN"])           histKNN     = new TH1F( "MVA_KNN",           "MVA_KNN",           nbin,  0, 1 );
   if (Use["HMatrix"])       histHm      = new TH1F( "MVA_HMatrix",       "MVA_HMatrix",       nbin, -0.95, 1.55 );
   if (Use["Fisher"])        histFi      = new TH1F( "MVA_Fisher",        "MVA_Fisher",        nbin, -4, 4 );
   if (Use["FisherG"])       histFiG     = new TH1F( "MVA_FisherG",       "MVA_FisherG",       nbin, -1, 1 );
   if (Use["BoostedFisher"]) histFiB     = new TH1F( "MVA_BoostedFisher", "MVA_BoostedFisher", nbin, -2, 2 );
   if (Use["LD"])            histLD      = new TH1F( "MVA_LD",            "MVA_LD",            nbin, -2, 2 );
   if (Use["MLP"])           histNn      = new TH1F( "MVA_MLP",           "MVA_MLP",           nbin, -1.25, 1.5 );
   if (Use["MLPBFGS"])       histNnbfgs  = new TH1F( "MVA_MLPBFGS",       "MVA_MLPBFGS",       nbin, -1.25, 1.5 );
   if (Use["MLPBNN"])        histNnbnn   = new TH1F( "MVA_MLPBNN",        "MVA_MLPBNN",        nbin, -1.25, 1.5 );
   if (Use["CFMlpANN"])      histNnC     = new TH1F( "MVA_CFMlpANN",      "MVA_CFMlpANN",      nbin,  0, 1 );
   if (Use["TMlpANN"])       histNnT     = new TH1F( "MVA_TMlpANN",       "MVA_TMlpANN",       nbin, -1.3, 1.3 );
   if (Use["BDT"])           histBdt     = new TH1F( "MVA_BDT",           "MVA_BDT",           nbin, -0.8, 0.8 );
   if (Use["BDTD"])          histBdtD    = new TH1F( "MVA_BDTD",          "MVA_BDTD",          nbin, -0.8, 0.8 );
   if (Use["BDTG"])          histBdtG    = new TH1F( "MVA_BDTG",          "MVA_BDTG",          nbin, -1.0, 1.0 );
   if (Use["RuleFit"])       histRf      = new TH1F( "MVA_RuleFit",       "MVA_RuleFit",       nbin, -2.0, 2.0 );
   if (Use["SVM_Gauss"])     histSVMG    = new TH1F( "MVA_SVM_Gauss",     "MVA_SVM_Gauss",     nbin,  0.0, 1.0 );
   if (Use["SVM_Poly"])      histSVMP    = new TH1F( "MVA_SVM_Poly",      "MVA_SVM_Poly",      nbin,  0.0, 1.0 );
   if (Use["SVM_Lin"])       histSVML    = new TH1F( "MVA_SVM_Lin",       "MVA_SVM_Lin",       nbin,  0.0, 1.0 );
   if (Use["FDA_MT"])        histFDAMT   = new TH1F( "MVA_FDA_MT",        "MVA_FDA_MT",        nbin, -2.0, 3.0 );
   if (Use["FDA_GA"])        histFDAGA   = new TH1F( "MVA_FDA_GA",        "MVA_FDA_GA",        nbin, -2.0, 3.0 );
   if (Use["Category"])      histCat     = new TH1F( "MVA_Category",      "MVA_Category",      nbin, -2., 2. );
   if (Use["Plugin"])        histPBdt    = new TH1F( "MVA_PBDT",          "MVA_BDT",           nbin, -0.8, 0.8 );

   // PDEFoam also returns per-event error, fill in histogram, and also fill significance
   if (Use["PDEFoam"]) {
      histPDEFoam    = new TH1F( "MVA_PDEFoam",       "MVA_PDEFoam",              nbin,  0, 1 );
      histPDEFoamErr = new TH1F( "MVA_PDEFoamErr",    "MVA_PDEFoam error",        nbin,  0, 1 );
      histPDEFoamSig = new TH1F( "MVA_PDEFoamSig",    "MVA_PDEFoam significance", nbin,  0, 10 );
   }

   // Book example histogram for probability (the other methods are done similarly)
   TH1F *probHistFi(0), *rarityHistFi(0);
   if (Use["Fisher"]) {
      probHistFi   = new TH1F( "MVA_Fisher_Proba",  "MVA_Fisher_Proba",  nbin, 0, 1 );
      rarityHistFi = new TH1F( "MVA_Fisher_Rarity", "MVA_Fisher_Rarity", nbin, 0, 1 );
   }

   // Prepare input tree (this must be replaced by your data source)
   // in this example, there is a toy tree with signal and one with background events
   // we'll later on use only the "signal" events for the test in this example.
   //   
   TFile *input(0);
   TFile *input_bkg(0);
   TString fname = "./../../2LSSAna/output/dataMC_3jets/miniNtuple_nonres.root"; 
   TString fname_bkg = "../../2LSSAna/output/dataMC_3jets/miniNtuple_totalbkg.root";   
   if (!gSystem->AccessPathName( fname )) 
      input = TFile::Open( fname ); // check if file in local directory exists
   //else    
   //   input = TFile::Open( "http://root.cern.ch/files/tmva_class_example.root" ); // if not: download from ROOT server
   
   if (!input) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }

   input_bkg = TFile::Open( fname_bkg );
   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;
   
   // --- Event loop

   // Prepare the event tree
   // - here the variable names have to corresponds to your tree
   // - you can use the same variables as above which is slightly faster,
   //   but of course you can use different ones and copy the values inside the event loop
   //
   std::cout << "--- Select signal sample" << std::endl;
  
       TString inputTree="Tree"; 
       TTree* theTree=(TTree*)input->Get(inputTree);
       TTree* theTree_bkg=(TTree*)input_bkg->Get(inputTree);
       /////Run over the background trees to get the correponding background events.
      
      Double_t weight;
      Int_t channel, category;
      TString *component=0;
   
   theTree->SetBranchAddress( "mindR_l1j", &mindR_l1j);
   theTree->SetBranchAddress( "mindR_l2j", &mindR_l2j); 
    theTree->SetBranchAddress( "MET", &MET);
   theTree->SetBranchAddress( "m_ll", &m_ll);
   theTree->SetBranchAddress( "m_l1jj", &m_l1jj);
   theTree->SetBranchAddress( "m_all", &m_all);
   theTree->SetBranchAddress( "weight", &weight );
   theTree->SetBranchAddress( "channel", &channel); 
   theTree->SetBranchAddress( "category", &category); 
   theTree->SetBranchAddress( "component", &component); 
   // Efficiency calculator for cut method
   Float_t    nSelCutsGA =0;
   Float_t    nSelCutsSA = 0.;
   Float_t    sumofWeight = 0.;
   Float_t    sumofWeight_bkg = 0.;
   Float_t    sumofWeight_err = 0.;
   Float_t    sumofWeight_bkg_err = 0.;

   Float_t sumOfweight_channel[3]={0.,0.,0.};
   Float_t sumOfweight_channel_bkg[3]={0.,0.,0.};
   
   Double_t effS       = 0.7;
   Double_t effScan[100];
   for(int i(0);i<100;i++) effScan[i]=i*0.01+0.01;
   Double_t nSelCutsSAScan_ee[100];
   Double_t nSelCutsSAScan_ee_err[100];
   Double_t nSelCutsSAScan_ee_bkg[100];
   Double_t nSelCutsSAScan_ee_bkg_err[100];
   
   Double_t nSelCutsSAScan_mumu[100];
   Double_t nSelCutsSAScan_mumu_err[100];
   Double_t nSelCutsSAScan_mumu_bkg[100];
   Double_t nSelCutsSAScan_mumu_bkg_err[100];

   Double_t nSelCutsSAScan_emu[100];
   Double_t nSelCutsSAScan_emu_err[100];
   Double_t nSelCutsSAScan_emu_bkg[100];
   Double_t nSelCutsSAScan_emu_bkg_err[100];

   for(int i(0);i<100;i++) {
       nSelCutsSAScan_ee[i]=0;nSelCutsSAScan_ee_err[i]=0;
       nSelCutsSAScan_mumu[i]=0;nSelCutsSAScan_mumu_err[i]=0;
       nSelCutsSAScan_emu[i]=0;nSelCutsSAScan_emu_err[i]=0;
   }
   for(int i(0);i<100;i++){
       nSelCutsSAScan_ee_bkg[i]=0;nSelCutsSAScan_ee_bkg_err[i]=0;
       nSelCutsSAScan_mumu_bkg[i]=0;nSelCutsSAScan_mumu_bkg_err[i]=0;
       nSelCutsSAScan_emu_bkg[i]=0;nSelCutsSAScan_emu_bkg_err[i]=0;
   }

   //book output tree
   TFile *target  = new TFile( "./../../2LSSAna/output/dataMC_3jets/TMVApp4w_nonres.root","recreate" );
   std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   
   //evaluate signal
   Long64_t nentries=theTree->GetEntries();
   for(Long64_t ievt=0; ievt<nentries;ievt++) {
    
      theTree->GetEntry(ievt);
      sumofWeight+=weight;
      if (channel==1) sumOfweight_channel[0]+=weight;
      if (channel==2) sumOfweight_channel[1]+=weight;
      if (channel==3) sumOfweight_channel[2]+=weight;

      if (Use["CutsGA"]) {
         // Cuts is a special case: give the desired signal efficienciy
         Int_t passed = reader_first->EvaluateMVA( "CutsGA method", effS );
         if (passed) nSelCutsGA+=weight;
      }

      if (Use["CutsSA"]) {
         // Cuts is a special case: give the desired signal efficienciy
         for(int i(WP_min);i<WP_max;i++){
         
         bool passed_ee = reader_first->EvaluateMVA( "CutsSA ee First", effScan[i]);
	 bool passed_ee_second=true;
         TMVA::MethodCuts* mcuts_ee = reader_second->FindCutsMVA( "CutsSA ee Second" );
         if (mcuts_ee) {      
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
	   mcuts_ee->GetCuts( effScan[i], cutsMin, cutsMax );
	 
	   passed_ee_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
	 if (channel==1&&passed_ee&&passed_ee_second) {nSelCutsSAScan_ee[i]+=weight;nSelCutsSAScan_ee_err[i]+=weight*weight; }

	 bool passed_mumu = reader_first->EvaluateMVA( "CutsSA mumu First", effScan[i]);
	 bool passed_mumu_second = true;
	 TMVA::MethodCuts* mcuts_mumu = reader_second->FindCutsMVA( "CutsSA mumu Second" );
         if (mcuts_mumu) {      
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
	   mcuts_mumu->GetCuts( effScan[i], cutsMin, cutsMax );
	   passed_mumu_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
	 if (channel==2&&passed_mumu&&passed_mumu_second) {nSelCutsSAScan_mumu[i]+=weight;nSelCutsSAScan_mumu_err[i]+=weight*weight; }
        
         bool passed_emu = reader_first->EvaluateMVA( "CutsSA emu First", effScan[i]);
         bool passed_emu_second = true;
         TMVA::MethodCuts* mcuts_emu = reader_second->FindCutsMVA( "CutsSA emu Second" );
         if (mcuts_emu) {
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
           mcuts_emu->GetCuts( effScan[i], cutsMin, cutsMax );
           passed_emu_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
         if (channel==3&&passed_emu&&passed_emu_second) {nSelCutsSAScan_emu[i]+=weight;nSelCutsSAScan_emu_err[i]+=weight*weight; }
    
	 }
       }

   }
   //evaluate bkg 
   component=0;
   theTree_bkg->SetBranchAddress( "mindR_l1j", &mindR_l1j);
   theTree_bkg->SetBranchAddress( "mindR_l2j", &mindR_l2j);
   theTree_bkg->SetBranchAddress( "MET", &MET);
   theTree_bkg->SetBranchAddress( "m_ll", &m_ll);
   theTree_bkg->SetBranchAddress( "m_l1jj", &m_l1jj);
   theTree_bkg->SetBranchAddress( "m_all", &m_all);
   theTree_bkg->SetBranchAddress( "weight", &weight );
   theTree_bkg->SetBranchAddress( "channel", &channel);
   theTree_bkg->SetBranchAddress( "category", &category);
   theTree_bkg->SetBranchAddress( "component", &component);

   nentries=theTree_bkg->GetEntries();
    std::cout << "--- Processing: " << theTree_bkg->GetEntries() << " events" << std::endl;
   for(Long64_t ievt=0; ievt<nentries;ievt++) {

     theTree_bkg->GetEntry(ievt);
     sumofWeight_bkg+=weight;
     if (channel==1) sumOfweight_channel_bkg[0]+=weight;
     if (channel==2) sumOfweight_channel_bkg[1]+=weight;
     if (channel==3) sumOfweight_channel_bkg[2]+=weight;
     if (Use["CutsSA"]) {
       // Cuts is a special case: give the desired signal efficienciy                                                                                                                
       for(int i(WP_min);i<WP_max;i++){
     	 
         bool passed_ee = reader_first->EvaluateMVA( "CutsSA ee First", effScan[i]);
	 bool passed_ee_second=true;
         TMVA::MethodCuts* mcuts_ee = reader_second->FindCutsMVA( "CutsSA ee Second" );
         if (mcuts_ee) {      
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
	   mcuts_ee->GetCuts( effScan[i], cutsMin, cutsMax );
	   bool passed_ee_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
         if(channel==1&&passed_ee&&passed_ee_second) {
            nSelCutsSAScan_ee_bkg[i]+=weight; 
            double err_nofake(0), err_fake(0);
            if((*component)!="fake") err_nofake+=weight*weight;
            if((*component)=="fake") err_fake+=ff_ele;
            nSelCutsSAScan_ee_bkg_err[i]+=err_nofake+err_fake; 
         }

         bool passed_mumu = reader_first->EvaluateMVA( "CutsSA mumu First", effScan[i]);
         bool passed_mumu_second=true;
         TMVA::MethodCuts* mcuts_mumu = reader_second->FindCutsMVA( "CutsSA mumu Second" );
         if (mcuts_mumu) {
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
           mcuts_mumu->GetCuts( effScan[i], cutsMin, cutsMax );
           bool passed_mumu_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
         if(channel==2&&passed_mumu&&passed_mumu_second) {
            nSelCutsSAScan_mumu_bkg[i]+=weight;
            double err_nofake(0), err_fake(0);
            if((*component)!="fake") err_nofake+=weight*weight;
            if((*component)=="fake") err_fake+=ff_ele;
            nSelCutsSAScan_mumu_bkg_err[i]+=err_nofake+err_fake;
         }

         bool passed_emu = reader_first->EvaluateMVA( "CutsSA emu First", effScan[i]);
         bool passed_emu_second=true;
         TMVA::MethodCuts* mcuts_emu = reader_second->FindCutsMVA( "CutsSA emu Second" ); 
         if (mcuts_emu) {
           std::vector<Double_t> cutsMin;
           std::vector<Double_t> cutsMax;
           mcuts_emu->GetCuts( effScan[i], cutsMin, cutsMax );
           bool passed_emu_second = (mindR_l2j>cutsMin[0]&&mindR_l2j<cutsMax[0]&&mindR_l1j>cutsMin[1]&&mindR_l1j<cutsMax[1]&&
                                 m_l1jj>cutsMin[2]&&m_l1jj<cutsMax[2]);
         }
         if(channel==3&&passed_emu&&passed_emu_second) {
            nSelCutsSAScan_emu_bkg[i]+=weight;
            double err_nofake(0), err_fake(0);
            if((*component)!="fake") err_nofake+=weight*weight;
            if((*component)=="fake" && category==22) err_fake+=ff_ele;
            if((*component)=="fake" && category==23) err_fake+=ff_mu;
            nSelCutsSAScan_emu_bkg_err[i]+=err_nofake+err_fake;
         }

       }
       //cout<<reader_first->EvaluateMVA( "CutsSA method", 0.7)<< "\t"<<passed <<"\t"<<weight<<endl;                                                                                       
     }


   }//end of bkg loop
   //calculate significance for each signal eff. WP
   Float_t RoofitSignificance_scan_ee[100];
   Float_t CowanSignificance_scan_ee[100];
   Float_t RoofitSignificance_scan_ee_err[100];
   Float_t CowanSignificance_scan_ee_err[100];

   Float_t RoofitSignificance_scan_mumu[100];
   Float_t CowanSignificance_scan_mumu[100];
   Float_t RoofitSignificance_scan_mumu_err[100];
   Float_t CowanSignificance_scan_mumu_err[100];

   Float_t RoofitSignificance_scan_emu[100];
   Float_t CowanSignificance_scan_emu[100];
   Float_t RoofitSignificance_scan_emu_err[100];
   Float_t CowanSignificance_scan_emu_err[100];

   Float_t signal_ee_eff[100];
   Float_t bkg_ee_eff[100];
   Float_t signal_ee_eff_err[100];
   Float_t bkg_ee_eff_err[100];
   Float_t SOverB_ee[100];
   Float_t SOverRootB_ee[100];
   Float_t SOverB_ee_err[100];
   Float_t SOverRootB_ee_err[100];
   Float_t signal_mumu_eff[100];
   Float_t bkg_mumu_eff[100];
   Float_t signal_mumu_eff_err[100];
   Float_t bkg_mumu_eff_err[100];
   Float_t SOverB_mumu[100];
   Float_t SOverRootB_mumu[100];
   Float_t SOverB_mumu_err[100];
   Float_t SOverRootB_mumu_err[100];
   Float_t signal_emu_eff[100];
   Float_t bkg_emu_eff[100];
   Float_t signal_emu_eff_err[100];
   Float_t bkg_emu_eff_err[100];
   Float_t SOverB_emu[100];
   Float_t SOverRootB_emu[100];
   Float_t SOverB_emu_err[100];
   Float_t SOverRootB_emu_err[100];
  
   for(int i(WP_min);i<WP_max;i++){
     SOverB_ee[i]=0;
     SOverB_ee_err[i]=0;
     SOverRootB_ee[i]=0;
     SOverRootB_ee_err[i]=0;
     SOverB_mumu[i]=0;
     SOverB_mumu_err[i]=0;
     SOverRootB_mumu[i]=0;
     SOverRootB_mumu_err[i]=0;
     SOverB_emu[i]=0;
     SOverB_emu_err[i]=0;
     SOverRootB_emu[i]=0;
     SOverRootB_emu_err[i]=0;

     nSelCutsSAScan_ee_bkg_err[i]=sqrt(nSelCutsSAScan_ee_bkg_err[i]);
     nSelCutsSAScan_ee_err[i]=sqrt(nSelCutsSAScan_ee_err[i]);
     nSelCutsSAScan_mumu_bkg_err[i]=sqrt(nSelCutsSAScan_mumu_bkg_err[i]);
     nSelCutsSAScan_mumu_err[i]=sqrt(nSelCutsSAScan_mumu_err[i]);
     nSelCutsSAScan_emu_bkg_err[i]=sqrt(nSelCutsSAScan_emu_bkg_err[i]);
     nSelCutsSAScan_emu_err[i]=sqrt(nSelCutsSAScan_emu_err[i]);

     signal_ee_eff[i]=nSelCutsSAScan_ee[i]/sumOfweight_channel[0];
     bkg_ee_eff[i]=nSelCutsSAScan_ee_bkg[i]/sumOfweight_channel_bkg[0];
     signal_mumu_eff[i]=nSelCutsSAScan_mumu[i]/sumOfweight_channel[1];
     bkg_mumu_eff[i]=nSelCutsSAScan_mumu_bkg[i]/sumOfweight_channel_bkg[1];
     signal_emu_eff[i]=nSelCutsSAScan_emu[i]/sumOfweight_channel[2];
     bkg_emu_eff[i]=nSelCutsSAScan_emu_bkg[i]/sumOfweight_channel_bkg[2];

     if(nSelCutsSAScan_ee_bkg[i]>0){
        SOverB_ee[i]=nSelCutsSAScan_ee[i]/nSelCutsSAScan_ee_bkg[i];
        SOverB_ee_err[i]=sqrt(pow(nSelCutsSAScan_ee_err[i]/nSelCutsSAScan_ee[i],2.0)+pow(nSelCutsSAScan_ee_bkg_err[i]/nSelCutsSAScan_ee_bkg[i],2.0))*nSelCutsSAScan_ee[i]/nSelCutsSAScan_ee_bkg[i];

        SOverRootB_ee[i]=nSelCutsSAScan_ee[i]/sqrt(nSelCutsSAScan_ee_bkg[i]);
        SOverRootB_ee_err[i]=sqrt(pow(nSelCutsSAScan_ee_err[i]/nSelCutsSAScan_ee[i],2.0)+pow(nSelCutsSAScan_ee_bkg_err[i]/nSelCutsSAScan_ee_bkg[i],2.0))*SOverRootB_ee[i];
     }
     
     signal_ee_eff_err[i]=sqrt((1-signal_ee_eff[i])*signal_ee_eff[i]/sumOfweight_channel[0]);
     bkg_ee_eff_err[i]=sqrt((1-bkg_ee_eff[i])*bkg_ee_eff[i]/sumOfweight_channel_bkg[0]);

   CalculateRoofitSignicance(nSelCutsSAScan_ee[i], nSelCutsSAScan_ee_bkg[i], nSelCutsSAScan_ee_err[i], nSelCutsSAScan_ee_bkg_err[i],0.4,RoofitSignificance_scan_ee[i], RoofitSignificance_scan_ee_err[i]);

   CalculateCowanSignicance(nSelCutsSAScan_ee[i], nSelCutsSAScan_ee_bkg[i], nSelCutsSAScan_ee_err[i], nSelCutsSAScan_ee_bkg_err[i],0.4,CowanSignificance_scan_ee[i], CowanSignificance_scan_ee_err[i]);
  
     if(nSelCutsSAScan_mumu_bkg[i]>0){
        SOverB_mumu[i]=nSelCutsSAScan_mumu[i]/nSelCutsSAScan_mumu_bkg[i];
        SOverB_mumu_err[i]=sqrt(pow(nSelCutsSAScan_mumu_err[i]/nSelCutsSAScan_mumu[i],2.0)+pow(nSelCutsSAScan_mumu_bkg_err[i]/nSelCutsSAScan_mumu_bkg[i],2.0))*nSelCutsSAScan_mumu[i]/nSelCutsSAScan_mumu_bkg[i];
       
        SOverRootB_mumu[i]=nSelCutsSAScan_mumu[i]/sqrt(nSelCutsSAScan_mumu_bkg[i]);
        SOverRootB_mumu_err[i]=sqrt(pow(nSelCutsSAScan_mumu_err[i]/nSelCutsSAScan_mumu[i],2.0)+pow(nSelCutsSAScan_mumu_bkg_err[i]/nSelCutsSAScan_mumu_bkg[i],2.0))*SOverRootB_mumu[i];
     }

     signal_mumu_eff_err[i]=sqrt((1-signal_mumu_eff[i])*signal_mumu_eff[i]/sumOfweight_channel[1]);
     bkg_mumu_eff_err[i]=sqrt((1-bkg_mumu_eff[i])*bkg_mumu_eff[i]/sumOfweight_channel_bkg[1]);
     
   CalculateRoofitSignicance(nSelCutsSAScan_mumu[i], nSelCutsSAScan_mumu_bkg[i], nSelCutsSAScan_mumu_err[i], nSelCutsSAScan_mumu_bkg_err[i],0.4,RoofitSignificance_scan_mumu[i], RoofitSignificance_scan_mumu_err[i]);

   CalculateCowanSignicance(nSelCutsSAScan_mumu[i], nSelCutsSAScan_mumu_bkg[i], nSelCutsSAScan_mumu_err[i], nSelCutsSAScan_mumu_bkg_err[i],0.4,CowanSignificance_scan_mumu[i], CowanSignificance_scan_mumu_err[i]);
  
    if(nSelCutsSAScan_emu_bkg[i]>0){
        SOverB_emu[i]=nSelCutsSAScan_emu[i]/nSelCutsSAScan_emu_bkg[i];
        SOverB_emu_err[i]=sqrt(pow(nSelCutsSAScan_emu_err[i]/nSelCutsSAScan_emu[i],2.0)+pow(nSelCutsSAScan_emu_bkg_err[i]/nSelCutsSAScan_emu_bkg[i],2.0))*nSelCutsSAScan_emu[i]/nSelCutsSAScan_emu_bkg[i];

        SOverRootB_emu[i]=nSelCutsSAScan_emu[i]/sqrt(nSelCutsSAScan_emu_bkg[i]);
        SOverRootB_emu_err[i]=sqrt(pow(nSelCutsSAScan_emu_err[i]/nSelCutsSAScan_emu[i],2.0)+pow(nSelCutsSAScan_emu_bkg_err[i]/nSelCutsSAScan_emu_bkg[i],2.0))*SOverRootB_emu[i];
     }

     signal_emu_eff_err[i]=sqrt((1-signal_emu_eff[i])*signal_emu_eff[i]/sumOfweight_channel[2]);
     bkg_emu_eff_err[i]=sqrt((1-bkg_emu_eff[i])*bkg_emu_eff[i]/sumOfweight_channel_bkg[2]);

   CalculateRoofitSignicance(nSelCutsSAScan_emu[i], nSelCutsSAScan_emu_bkg[i], nSelCutsSAScan_emu_err[i], nSelCutsSAScan_emu_bkg_err[i],0.4,RoofitSignificance_scan_emu[i], RoofitSignificance_scan_emu_err[i]);

   CalculateCowanSignicance(nSelCutsSAScan_emu[i], nSelCutsSAScan_emu_bkg[i], nSelCutsSAScan_emu_err[i], nSelCutsSAScan_emu_bkg_err[i],0.4,CowanSignificance_scan_emu[i], CowanSignificance_scan_emu_err[i]); 
   }
   TH1F *h_Roofit_ee=new TH1F("Scan_Roofit_ee","",99,0.005,0.995);
   TH1F *h_Cowan_ee=new TH1F("Scan_Cowan_ee","",99,0.005,0.995);
   TH1F *h_Roofit_mumu=new TH1F("Scan_Roofit_mumu","",99,0.005,0.995);
   TH1F *h_Cowan_mumu=new TH1F("Scan_Cowan_mumu","",99,0.005,0.995);
   TH1F *h_Roofit_emu=new TH1F("Scan_Roofit_emu","",99,0.005,0.995);
   TH1F *h_Cowan_emu=new TH1F("Scan_Cowan_emu","",99,0.005,0.995);
   TH1F *h_SOverRootB_ee=new TH1F("SOverB_ee","",99,0.005,0.995);
   TH1F *h_SOverRootB_mumu=new TH1F("SOverRootB_mumu","",99,0.005,0.995);  
   TH1F *h_SOverRootB_emu=new TH1F("SOverRootB_emu","",99,0.005,0.995);  
  
   map<TString,TH1F*> TH1Fmap;
   // deltaR_23,m_12,m_13,m_23,mindR_l2j,mindR_l3j;
   TString variable_name[]={"Signal_ee_eff","Bkg_ee_eff","Signal_mumu_eff","Bkg_mumu_eff","Signal_emu_eff","Bkg_emu_eff",
                            "MET_lower","m_ll_lower","mindR_l2j_lower","mindR_l1j_lower","m_l1jj_lower","m_all_lower",
                           "MET_higher","m_ll_higher","mindR_l2j_higher","mindR_l1j_higher","m_l1jj_higher","m_all_higher"};
   TString variable_index_ee[]={"MET_ee","m_ll_ee","mindR_l2j_ee","mindR_l1j_ee","m_l1jj_ee","m_all_ee"};
   TString variable_index_mumu[]={"MET_mumu","m_ll_mumu","mindR_l2j_mumu","mindR_l1j_mumu","m_l1jj_mumu","m_all_mumu"};
   TString variable_index_emu[]={"MET_emu","m_ll_emu","mindR_l2j_emu","mindR_l1j_emu","m_l1jj_emu","m_all_emu"};
   // TH1Fmap["Signal_eff"]=HistoUtils::InitTH1F("Signal_eff","Signal MVA cuts Eff. WP",100,0.,1.);
   //TH1Fmap["Bkg_eff"]=HistoUtils::InitTH1F("Bkg_eff","Signal MVA cuts Eff. WP",100,0.,1.);
   for(int i(0);i<18;i++){
   TH1Fmap[variable_name[i]]=HistoUtils::InitTH1F(variable_name[i],"Signal MVA cuts Eff. WP",99,0.005,0.995);
   }

   for(int i(WP_min);i<WP_max;i++){

     h_Roofit_ee->SetBinContent(i+1,RoofitSignificance_scan_ee[i]);
     h_Roofit_ee->SetBinError(i+1,RoofitSignificance_scan_ee_err[i]);
     h_Roofit_mumu->SetBinContent(i+1,RoofitSignificance_scan_mumu[i]);
     h_Roofit_mumu->SetBinError(i+1,RoofitSignificance_scan_mumu_err[i]);
     h_Roofit_emu->SetBinContent(i+1,RoofitSignificance_scan_emu[i]);
     h_Roofit_emu->SetBinError(i+1,RoofitSignificance_scan_emu_err[i]);

     h_Cowan_ee->SetBinContent(i+1,CowanSignificance_scan_ee[i]);
     h_Cowan_ee->SetBinError(i+1,CowanSignificance_scan_ee_err[i]);
     h_Cowan_mumu->SetBinContent(i+1,CowanSignificance_scan_mumu[i]);
     h_Cowan_mumu->SetBinError(i+1,CowanSignificance_scan_mumu_err[i]);
     h_Cowan_emu->SetBinContent(i+1,CowanSignificance_scan_emu[i]);
     h_Cowan_emu->SetBinError(i+1,CowanSignificance_scan_emu_err[i]);

     h_SOverRootB_ee->SetBinContent(i+1,SOverRootB_ee[i]);
     h_SOverRootB_ee->SetBinError(i+1,SOverRootB_ee_err[i]);
     h_SOverRootB_mumu->SetBinContent(i+1,SOverRootB_mumu[i]);
     h_SOverRootB_mumu->SetBinError(i+1,SOverRootB_mumu_err[i]);
     h_SOverRootB_emu->SetBinContent(i+1,SOverRootB_emu[i]);
     h_SOverRootB_emu->SetBinError(i+1,SOverRootB_emu_err[i]);

     TH1Fmap["Signal_ee_eff"]->SetBinContent(i+1,signal_ee_eff[i]);
     TH1Fmap["Bkg_ee_eff"]->SetBinContent(i+1,bkg_ee_eff[i]);
     TH1Fmap["Signal_ee_eff"]->SetBinError(i+1,signal_ee_eff_err[i]);
     TH1Fmap["Bkg_ee_eff"]->SetBinError(i+1,bkg_ee_eff_err[i]);
     TH1Fmap["Signal_mumu_eff"]->SetBinContent(i+1,signal_mumu_eff[i]);
     TH1Fmap["Bkg_mumu_eff"]->SetBinContent(i+1,bkg_mumu_eff[i]);
     TH1Fmap["Signal_mumu_eff"]->SetBinError(i+1,signal_mumu_eff_err[i]);
     TH1Fmap["Bkg_mumu_eff"]->SetBinError(i+1,bkg_mumu_eff_err[i]);
     TH1Fmap["Signal_emu_eff"]->SetBinContent(i+1,signal_emu_eff[i]);
     TH1Fmap["Bkg_emu_eff"]->SetBinContent(i+1,bkg_emu_eff[i]);
     TH1Fmap["Signal_emu_eff"]->SetBinError(i+1,signal_emu_eff_err[i]);
     TH1Fmap["Bkg_emu_eff"]->SetBinError(i+1,bkg_emu_eff_err[i]);
     
     TMVA::MethodCuts* mcuts_ee_first = reader_first->FindCutsMVA( "CutsSA ee First" );

      if (mcuts_ee_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_ee_first->GetCuts( effScan[i], cutsMin, cutsMax );
         for(int j(0);j<2;j++){
	    TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j]);
	    TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j]);
         }
         TH1Fmap[variable_name[11]]->SetBinContent(i+1,cutsMin[2]);      
         TH1Fmap[variable_name[17]]->SetBinContent(i+1,cutsMax[2]);      
      }

      TMVA::MethodCuts* mcuts_ee_second = reader_second->FindCutsMVA( "CutsSA ee Second" );

      if (mcuts_ee_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_ee_second->GetCuts( effScan[i], cutsMin, cutsMax );
        for(int j(2);j<5;j++){
	   TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j-2]);
	   TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j-2]);
        }
     }
   } 
   PlotScanCuts(TH1Fmap["Signal_ee_eff"], TH1Fmap["Bkg_ee_eff"], "Efficiency_ee");
   PlotScanCuts(TH1Fmap["Signal_mumu_eff"], TH1Fmap["Bkg_mumu_eff"], "Efficiency_mumu");
   PlotScanCuts(TH1Fmap["Signal_emu_eff"], TH1Fmap["Bkg_emu_eff"], "Efficiency_emu");
   for(int j(0);j<6;j++) PlotScanCuts(TH1Fmap[variable_name[j+6]],TH1Fmap[variable_name[j+12]],variable_index_ee[j]);

   for(int i(6);i<18;i++){
   TH1Fmap[variable_name[i]]=HistoUtils::InitTH1F(variable_name[i],"Signal MVA cuts Eff. WP",99,0.005,0.995);
   }
   for(int i(WP_min);i<WP_max;i++){
     TMVA::MethodCuts* mcuts_mumu_first = reader_first->FindCutsMVA( "CutsSA mumu First" );

      if (mcuts_mumu_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_mumu_first->GetCuts( effScan[i], cutsMin, cutsMax );
         for(int j(0);j<2;j++){
	    TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j]);
	    TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j]);
         }
         TH1Fmap[variable_name[11]]->SetBinContent(i+1,cutsMin[2]);      
         TH1Fmap[variable_name[17]]->SetBinContent(i+1,cutsMax[2]);      
      }

      TMVA::MethodCuts* mcuts_mumu_second = reader_second->FindCutsMVA( "CutsSA mumu Second" );

      if (mcuts_mumu_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_mumu_second->GetCuts( effScan[i], cutsMin, cutsMax );
        for(int j(2);j<5;j++){
	   TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j-2]);
	   TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j-2]);
        }
     }
   }
   for(int j(0);j<6;j++) PlotScanCuts(TH1Fmap[variable_name[j+6]],TH1Fmap[variable_name[j+12]],variable_index_mumu[j]);

   for(int i(6);i<18;i++){
   TH1Fmap[variable_name[i]]=HistoUtils::InitTH1F(variable_name[i],"Signal MVA cuts Eff. WP",99,0.005,0.995);
   }
   for(int i(WP_min);i<WP_max;i++){
     TMVA::MethodCuts* mcuts_emu_first = reader_first->FindCutsMVA( "CutsSA emu First" );

      if (mcuts_emu_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_emu_first->GetCuts( effScan[i], cutsMin, cutsMax );
         for(int j(0);j<2;j++){
	    TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j]);
	    TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j]);
         }
         TH1Fmap[variable_name[11]]->SetBinContent(i+1,cutsMin[2]);      
         TH1Fmap[variable_name[17]]->SetBinContent(i+1,cutsMax[2]);      
      }

      TMVA::MethodCuts* mcuts_emu_second = reader_second->FindCutsMVA( "CutsSA emu Second" );

      if (mcuts_emu_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_emu_second->GetCuts( effScan[i], cutsMin, cutsMax );
        for(int j(2);j<5;j++){
	   TH1Fmap[variable_name[j+6]]->SetBinContent(i+1,cutsMin[j-2]);
	   TH1Fmap[variable_name[j+12]]->SetBinContent(i+1,cutsMax[j-2]);
        }
     }
 
   }
   for(int j(0);j<6;j++) PlotScanCuts(TH1Fmap[variable_name[j+6]],TH1Fmap[variable_name[j+12]],variable_index_emu[j]);
 // ---Output the txt
   TString output_Roofit_ee_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/RooSignificance_Scan_ee.txt";
   std::fstream fs_Roofit_ee;
   fs_Roofit_ee.open (output_Roofit_ee_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_Roofit_ee<<effScan[i]<<"\t"<<RoofitSignificance_scan_ee[i]<<"\t" <<RoofitSignificance_scan_ee_err[i]<<endl;
   // ---Output the Cowan significance
   TString output_Cowan_ee_txt="./../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/CowanSignificance_Scan_ee.txt";
   std::fstream fs_Cowan_ee;
   fs_Cowan_ee.open (output_Cowan_ee_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_Cowan_ee<<effScan[i]<<"\t"<<CowanSignificance_scan_ee[i]<<"\t" <<CowanSignificance_scan_ee_err[i]<<endl;

   TString output_Roofit_mumu_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/RooSignificance_Scan_mumu.txt";
   std::fstream fs_Roofit_mumu;
   fs_Roofit_mumu.open (output_Roofit_mumu_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_Roofit_mumu<<effScan[i]<<"\t"<<RoofitSignificance_scan_mumu[i]<<"\t" <<RoofitSignificance_scan_mumu_err[i]<<endl; 
   // ---Output the Cowan significance
   TString output_Cowan_mumu_txt="./../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/CowanSignificance_Scan_mumu.txt";
   std::fstream fs_Cowan_mumu;
   fs_Cowan_mumu.open (output_Cowan_mumu_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_Cowan_mumu<<effScan[i]<<"\t"<<CowanSignificance_scan_mumu[i]<<"\t" <<CowanSignificance_scan_mumu_err[i]<<endl;

   TString output_Roofit_emu_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/RooSignificance_Scan_emu.txt";
   std::fstream fs_Roofit_emu;
   fs_Roofit_emu.open (output_Roofit_emu_txt, std::fstream::out | std::fstream::app);  
   for(int i(WP_min);i<WP_max;i++) fs_Roofit_emu<<effScan[i]<<"\t"<<RoofitSignificance_scan_emu[i]<<"\t" <<RoofitSignificance_scan_emu_err[i]<<endl; 
   // ---Output the Cowan significance
   TString output_Cowan_emu_txt="./../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/CowanSignificance_Scan_emu.txt";
   std::fstream fs_Cowan_emu;
   fs_Cowan_emu.open (output_Cowan_emu_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_Cowan_emu<<effScan[i]<<"\t"<<CowanSignificance_scan_emu[i]<<"\t" <<CowanSignificance_scan_emu_err[i]<<endl; //S/sqrt(B)
   TString output_SOverRootB_ee_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/SOverRootBSignificance_Scan_ee.txt";
   std::fstream fs_SOverRootB_ee;
   fs_SOverRootB_ee.open (output_SOverRootB_ee_txt, std::fstream::out | std::fstream::app);
   for(int i(WP_min);i<WP_max;i++) fs_SOverRootB_ee<<effScan[i]<<"\t"<<SOverRootB_ee[i]<<"\t" <<SOverRootB_ee_err[i]<<endl;
   TString output_SOverRootB_mumu_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/SOverRootBSignificance_Scan_mumu.txt";
   std::fstream fs_SOverRootB_mumu;
   fs_SOverRootB_mumu.open (output_SOverRootB_mumu_txt, std::fstream::out | std::fstream::app);   for(int i(WP_min);i<WP_max;i++) fs_SOverRootB_mumu<<effScan[i]<<"\t"<<SOverRootB_mumu[i]<<"\t" <<SOverRootB_mumu_err[i]<<endl;
  
   TString output_SOverRootB_emu_txt="../../2LSSAna/ouput/dataMC_3jets/SigOpt/nonres/SOverRootBSignificance_Scan_emu.txt";
   std::fstream fs_SOverRootB_emu;
   fs_SOverRootB_emu.open (output_SOverRootB_emu_txt, std::fstream::out | std::fstream::app);       for(int i(WP_min);i<WP_max;i++) fs_SOverRootB_emu<<effScan[i]<<"\t"<<SOverRootB_emu[i]<<"\t" <<SOverRootB_emu_err[i]<<endl;
   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: "; sw.Print();

   // Get efficiency for cuts classifier
    
   // if (Use["CutsSA"]) std::cout << "--- Efficiency for CutsSA method: " << nSelCutsSA/sumofWeight
   //                           << " (for a required signal efficiency of " << effS << ")" << std::endl;

   if (Use["CutsSA"]) {

      // test: retrieve cuts for particular signal efficiency
      // CINT ignores dynamic_casts so we have to use a cuts-secific Reader function to acces the pointer  
      TMVA::MethodCuts* mcuts_ee_first = reader_first->FindCutsMVA( "CutsSA ee First" );

      if (mcuts_ee_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_ee_first->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 ee from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_ee_first->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
      }

       TMVA::MethodCuts* mcuts_ee_second = reader_second->FindCutsMVA( "CutsSA ee Second" );

      if (mcuts_ee_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_ee_second->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 ee from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_ee_second->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
      }
      
        TMVA::MethodCuts* mcuts_mumu_first = reader_first->FindCutsMVA( "CutsSA mumu First" ) ;
        if (mcuts_mumu_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_mumu_first->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 mumu from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_mumu_first->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         }

	TMVA::MethodCuts* mcuts_mumu_second = reader_second->FindCutsMVA( "CutsSA mumu Second" ) ;
        if (mcuts_mumu_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_mumu_second->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 mumu from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_mumu_second->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         }
         
        TMVA::MethodCuts* mcuts_emu_first = reader_first->FindCutsMVA( "CutsSA emu First" ) ;
        if (mcuts_emu_first) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_emu_first->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 emu from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_emu_first->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         }

	TMVA::MethodCuts* mcuts_emu_second = reader_second->FindCutsMVA( "CutsSA emu Second" ) ;
        if (mcuts_emu_second) {      
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts_emu_second->GetCuts( 0.55, cutsMin, cutsMax );
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.55 emu from Reader" << std::endl;
         for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
            std::cout << "... Cut: " 
                      << cutsMin[ivar] 
                      << " < \"" 
                      << mcuts_emu_second->GetInputVar(ivar)
                      << "\" <= " 
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         }


   }

   // --- Write histograms

   //TFile *target  = new TFile( "TMVApp.root","RECREATE" );
   //AppTree->Write();
   if (Use["Likelihood"   ])   histLk     ->Write();
   if (Use["LikelihoodD"  ])   histLkD    ->Write();
   if (Use["LikelihoodPCA"])   histLkPCA  ->Write();
   if (Use["LikelihoodKDE"])   histLkKDE  ->Write();
   if (Use["LikelihoodMIX"])   histLkMIX  ->Write();
   if (Use["PDERS"        ])   histPD     ->Write();
   if (Use["PDERSD"       ])   histPDD    ->Write();
   if (Use["PDERSPCA"     ])   histPDPCA  ->Write();
   if (Use["KNN"          ])   histKNN    ->Write();
   if (Use["HMatrix"      ])   histHm     ->Write();
   if (Use["Fisher"       ])   histFi     ->Write();
   if (Use["FisherG"      ])   histFiG    ->Write();
   if (Use["BoostedFisher"])   histFiB    ->Write();
   if (Use["LD"           ])   histLD     ->Write();
   if (Use["MLP"          ])   histNn     ->Write();
   if (Use["MLPBFGS"      ])   histNnbfgs ->Write();
   if (Use["MLPBNN"       ])   histNnbnn  ->Write();
   if (Use["CFMlpANN"     ])   histNnC    ->Write();
   if (Use["TMlpANN"      ])   histNnT    ->Write();
   if (Use["BDT"          ])   histBdt    ->Write();
   if (Use["BDTD"         ])   histBdtD   ->Write();
   if (Use["BDTG"         ])   histBdtG   ->Write(); 
   if (Use["RuleFit"      ])   histRf     ->Write();
   if (Use["SVM_Gauss"    ])   histSVMG   ->Write();
   if (Use["SVM_Poly"     ])   histSVMP   ->Write();
   if (Use["SVM_Lin"      ])   histSVML   ->Write();
   if (Use["FDA_MT"       ])   histFDAMT  ->Write();
   if (Use["FDA_GA"       ])   histFDAGA  ->Write();
   if (Use["Category"     ])   histCat    ->Write();
   if (Use["Plugin"       ])   histPBdt   ->Write();

   // Write the scan histogram
   PlotScanEff(h_Roofit_ee, h_Cowan_ee, "Significance_ee");
   PlotScanEff(h_Roofit_mumu, h_Cowan_mumu, "Significance_mumu");
   PlotScanEff(h_Roofit_emu, h_Cowan_emu, "Significance_emu");
   PlotCowanScanEff(h_SOverRootB_ee,"SOverRootB_ee");
   PlotCowanScanEff(h_SOverRootB_mumu,"SOverRootB_mumu");
   PlotCowanScanEff(h_SOverRootB_emu,"SOverRootB_emu");

   // Write also error and significance histos
   if (Use["PDEFoam"]) { histPDEFoam->Write(); histPDEFoamErr->Write(); histPDEFoamSig->Write(); }

   // Write also probability hists
   if (Use["Fisher"]) { if (probHistFi != 0) probHistFi->Write(); if (rarityHistFi != 0) rarityHistFi->Write(); }
   target->Close();


   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;
  
   delete reader_first;
   delete reader_second;
    
   std::cout << "==> TMVAClassificationApplication is done!" << endl << std::endl;
}
