#include "TFile.h"
#include "TH2.h"
#include <iostream>

void TruthCal(){

  TFile *f=new TFile("hists/Hists_Zjets_QmisIDBDT.root");
  TH2 *hist_os=(TH2*)f->Get("hist_os_counts");
  TH2 *hist_ss=(TH2*)f->Get("hist_ss_counts");

  //hist_os->Sumw2();
  //hist_ss->Sumw2();

  hist_os->Add(hist_ss,1);//total now

  //book output
  TFile *outfile=new TFile("rates/QmisID_truth_QmisID.root","recreate");
  TH2 *hist_rates=(TH2*)hist_ss->Clone("Rates_Truth");
  hist_rates->Divide(hist_ss, hist_os, 1, 2, "");

  for(int i=0;i<6;i++){
      if(i==3) continue;//crack region
      for(int j=0;j<4;j++){
          std::cout<<i<<" "<<j<<" "<<hist_rates->GetBinContent(i+1,j+1)<<"    +-   "<<hist_rates->GetBinError(i+1,j+1)<<std::endl;
          
      }
  }
  hist_rates->Write();
  outfile->Close();
  
}
