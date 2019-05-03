/*This macro used to fit Z peak 
 * 2/17/2018
 * maosen*/
#ifdef QmisID_cxx
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooChi2Var.h"
#include "RooPlot.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "TCanvas.h"
#include "inc/QmisID.h"
#include "HelperFunctions.cxx"

using namespace RooFit;

void QmisID::FitZpeak(){
 
  //std::map<int, RooRealVar> wt;
  //std::map<int, RooRealVar> mass;
  RooRealVar *mass[2];
  RooRealVar *wt[2];
  RooArgSet *argset[2];

  //SS
  mass[0]=new RooRealVar("mass_ss","mass_ss",50,130);
  wt[0]=new RooRealVar("wt_ss","wt_ss",-100,100);
  argset[0]=new RooArgSet(*mass[0],*wt[0],"dataset_ss");
  //OS
  mass[1]=new RooRealVar("mass_os","mass_os",50,130);
  wt[1]=new RooRealVar("wt_os","wt_os",-100,100);
  argset[1]=new RooArgSet(*mass[1],*wt[1],"dataset_os");

  RooDataSet *ds[2];
  ds[0]=new RooDataSet("ds_ss","ds_ss",*argset[0]);
  ds[1]=new RooDataSet("ds_os","ds_os",*argset[1]);

  int xx=0, yy=0;
  for(Long64_t entry=0;entry<fChain->GetEntriesFast(); entry++){

      if (fChain->LoadTree(entry) <0) break;

      fChain->GetEntry(entry);
    
      FormulaUpdate(); 
      //event selections for fit
      xx++;
      //cout<<entry<<endl;
      if ( !FitZEventSelections() ) continue;
      yy++;
      //if you want to follow the same selections on electrons used for QmisID estimation
      //if(!passElectronsCase(ElectronsCombIdx(), m_ElectronsCase)) continue; 

      if (m_isData) weight=1;

      if(fabs(total_charge)==2) { 
         mass[0]->setVal(Mll01/GeV);
         wt[0]->setVal(weight);
         ds[0]->add(*argset[0]);
      }
      if(fabs(total_charge)==0) {
         mass[1]->setVal(Mll01/GeV);
         wt[1]->setVal(weight);
         ds[1]->add(*argset[1]);
      }
  }
  cout<<"   Number of Events   "<<xx<<"-->"<<yy<<endl;
  for(int i=0; i<2; i++){
      std::cout<<"       $$$$$$$$$$$$$$$$$-------------------------$$$$$$$$$$$$$$$$$$$$$"<<endl;
      std::cout<<"              Fit "<<i<<" type events (0: SS; 1: OS)"<<std::endl;
      std::cout<<"       $$$$$$$$$$$$$$$$$-------------------------$$$$$$$$$$$$$$$$$$$$$"<<endl;
      //weight it
      RooDataSet *ds2=new RooDataSet(ds[i]->GetName(),ds[i]->GetTitle(),ds[i],*ds[i]->get(),0,wt[i]->GetName());
      //RooDataSet *ds2=new RooDataSet(ds1->GetName(),ds1->GetTitle(),ds1,*ds1->get(),0,wt.GetName());

      //unbinned likelihood fit
      // Fit a Gaussian p.d.f to the data
      RooRealVar mean("mean","mean",90,80,100) ;
      RooRealVar sigma("sigma","sigma",5,1,30) ;
      RooGaussian gauss("gauss","gauss",*mass[i],mean,sigma);
      
      //fit result
      RooFitResult* r_ml_wgt_corr=gauss.fitTo(*ds2,Save(),SumW2Error(kTRUE));
    
      //plot fitted result
      TString outpdf_name=m_RunName;
      outpdf_name += i==0? "/Fit_SS.pdf": "/Fit_OS.pdf";
      TCanvas *c=new TCanvas("c","",700,700);
      RooPlot* mass_frame = mass[i]->frame(Title("Unbinned ML fit, binned chi^2 fit to weighted data")) ;
      ds2->plotOn(mass_frame,DataError(RooAbsData::SumW2)) ;
      gauss.plotOn(mass_frame);
    
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
      c->SaveAs(outpdf_name.Data()) ;
      //compare
      std::cout<<"<== Unbinned ML fit ==>"<<std::endl;
      r_ml_wgt_corr->Print(); 
      std::cout<<"<== Binned fit ==>"<<std::endl;
      r_chi2_wgt->Print();
  
      delete r_chi2_wgt;
      delete binnedData;
      delete mass_frame;   
      delete r_ml_wgt_corr; 
      delete ds2;
  }
}
#endif
