/*This macro obtains the tree from NTUPLE and do a likelihood fit
 * 2/17/2018
 * maosen*/
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"
#include "RooMinuit.h"
#include "RooFitResult.h"

using namespace RooFit;

void FitZpeak(){
  
  TFile *f=new TFile("../output/mini.root");
  TTree *tree=(TTree*)f->Get("minitree");
  RooRealVar mass("mass","mass",50,130);
  RooRealVar wt("wt","wt",-100,100);
  RooArgSet argset(mass,wt,"dataset");

  RooDataSet *ds1=new RooDataSet("ds1","ds1",argset);

  Double_t weight;
  Float_t Mll01;
  Int_t total_charge;
  tree->SetBranchAddress("Mll01",&Mll01);
  tree->SetBranchAddress("weight",&weight);
  tree->SetBranchAddress("total_charge",&total_charge);
  double maxweight=0;
  for(Int_t entry=0;entry<tree->GetEntries();entry++){
      tree->GetEntry(entry);
      if(fabs(weight)>100) continue;
      if(fabs(total_charge)==2) continue; 
      mass.setVal(Mll01);
      wt.setVal(weight);
      ds1->add(argset);
      if(fabs(weight)>fabs(maxweight)) maxweight=weight;
  }
  std::cout<<"max weight: "<<maxweight<<std::endl;
  //weight it
  RooDataSet *ds2=new RooDataSet(ds1->GetName(),ds1->GetTitle(),ds1,*ds1->get(),0,wt.GetName());

  //unbinned likelihood fit
  // Fit a Gaussian p.d.f to the data
  RooRealVar mean("mean","mean",90,80,100) ;
  RooRealVar sigma("sigma","sigma",5,1,30) ;
  RooGaussian gauss("gauss","gauss",mass,mean,sigma);
  
  //fit result
  RooFitResult* r_ml_wgt_corr=gauss.fitTo(*ds2,Save(),SumW2Error(kTRUE));

  //plot fitted result
  RooPlot* mass_frame = mass.frame(Title("Unbinned ML fit, binned chi^2 fit to weighted data")) ;
  ds2->plotOn(mass_frame,DataError(RooAbsData::SumW2)) ;
  gauss.plotOn(mass_frame);
  //ds1->plotOn(mass_frame);

  //binnned fit 
  RooDataHist *binnedData = ds2->binnedClone();
  binnedData->Print("v");

  RooChi2Var chi2("chi2","chi2",gauss,*binnedData,DataError(RooAbsData::SumW2)) ;
  RooMinuit m(chi2);
  m.migrad() ;
  m.hesse() ;

  // Plot chi^2 fit result on frame as well
  RooFitResult* r_chi2_wgt = m.save() ;
  gauss.plotOn(mass_frame,LineStyle(kDashed),LineColor(kRed)); 
  mass_frame->Draw();

  //compare
  std::cout<<"<== Unbinned ML fit ==>"<<std::endl;
  r_ml_wgt_corr->Print(); 
  std::cout<<"<== Binned fit ==>"<<std::endl;
  r_chi2_wgt->Print();
}
