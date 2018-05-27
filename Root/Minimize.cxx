#include "CalSideband.cxx"
#include "TMath.h"
#include "TFitter.h"

extern void myLikelihood(int & npar, double* gout, double & func, double *par, int flg){
 
  double sf_os=0.957913, sf_ss=0.947161;
  double counts_os[36][16], counts_ss[36][16];
  //retrive counts
  TFile *f=new TFile("Hists_data_QmisIDBDT.root");
  TH2 *hist_os=(TH2*)f->Get("hist_os");
  TH2 *hist_ss=(TH2*)f->Get("hist_ss");
  
  double likelihoods=0;
   
  double temp_par[20];
  int index=0;
  for(int i=0;i<6;i++){
      if(i==3) continue;//crack region
      for(int j=0;j<4;j++){
          if(i>3) temp_par[4*(i-1)+j]=par[index];
          else temp_par[4*i+j]=par[index];
          index++;
      }
  }
  //std::cout<<"I am here"<<std::endl;
  for(int i=0;i<6;i++){
      if(i==3) continue;//crack region
      for(int j=0;j<4;j++){
          for(int k=i;k<6;k++){
              if(k==3) continue;//crack region
              for(int l=j;l<4;l++){//par[20] 
                  counts_ss[6*i+k][4*j+l]=hist_ss->GetBinContent(6*i+k+1,4*j+l+1);
                  counts_os[6*i+k][4*j+l]=hist_os->GetBinContent(6*i+k+1,4*j+l+1);
                  //if(counts_ss[6*i+k][4*j+l]==0 && counts_os[6*i+k][4*j+l]==0) continue;
 
                  double N_cell=sf_ss*counts_ss[6*i+k][4*j+l] + sf_os*counts_os[6*i+k][4*j+l];
                  double N_ss=sf_ss*counts_ss[6*i+k][4*j+l];
                  if(i<3 && k<3)
                  likelihoods += TMath::Log((temp_par[4*i+j]+temp_par[4*k+l]))*N_ss-N_cell*(temp_par[4*i+j]+temp_par[4*k+l]);
                  if(i>3 && k<3)
                  likelihoods += TMath::Log((temp_par[4*(i-1)+j]+temp_par[4*k+l]))*N_ss-N_cell*(temp_par[4*(i-1)+j]+temp_par[4*k+l]);
                  if(i<3 && k>3)
                  likelihoods += TMath::Log((temp_par[4*i+j]+temp_par[4*(k-1)+l]))*N_ss-N_cell*(temp_par[4*i+j]+temp_par[4*(k-1)+l]);
                  if(i>3 && k>3)
                  {likelihoods += TMath::Log((temp_par[4*(i-1)+j]+temp_par[4*(k-1)+l]))*N_ss-N_cell*(temp_par[4*(i-1)+j]+temp_par[4*(k-1)+l]);}
              }//end l
          }//end k
      }//end j   
  }//end i
  
  func=-1*likelihoods;  
  std::cout<<"func: "<<func<<std::endl; 
}

void Minimize(){

  const int nfit=20;//npars
  Double_t Qff[nfit], Qff_err[nfit];
  TFitter* minimizer = new TFitter(nfit);
  minimizer->SetFCN(myLikelihood);

  double arglist[10];
  //Setting up minuit parameters
  Double_t *vstart = new Double_t[nfit];
  Double_t *step=new Double_t[nfit];
  TString *name = new TString[nfit];

  for(int n=0; n<nfit; n++){
      vstart[n] = 0.00001;
      step[n] = 0.000001;
      name[n] = Form("par%d",n+1);
  } 
  for(int j = 0; j < nfit; j++) {
      minimizer->SetParameter(j, name[j], vstart[j], step[j], 0.000001, 0.1);
  } 
  //
  minimizer->ExecuteCommand("CAL", arglist, 1);         
  minimizer->ExecuteCommand("SET NOG", arglist, 0);
  minimizer->ExecuteCommand("MINIMIZE", arglist, 0);
  minimizer->ExecuteCommand("MIGRAD", arglist, 0);
  minimizer->ExecuteCommand("HESSE", arglist, 0);
  minimizer->ExecuteCommand("CAL", arglist, 1);    

  //book output to store
  Float_t eta_bins[7]={0,0.6,1.1,1.37,1.52,2.0,2.47};
  Float_t pt_bins[5]={10,60,90,130,1000};
  TFile *outfile =new TFile("QmisID_tight_data.root","recreate");
  TH2D *hist_QmisID=new TH2D("hist_QmisID","",6,eta_bins,4,pt_bins);

  std::cout<<"<< ===== Fitted QmisID rates =====>"<<std::endl;
  for (int j = 0; j < nfit; j++) {
       Qff[j] = minimizer->GetParameter(j);
       Qff_err[j] = minimizer->GetParError(j);
       std::cout<<j<<"  "<<Qff[j]<<"  "<<Qff_err[j]<<std::endl;
  }

  int index=0;
  for(int i=0;i<6;i++){
      if(i==3) continue;//crack region
      for(int j=0;j<4;j++){
          hist_QmisID->SetBinContent(i+1,j+1,minimizer->GetParameter(index));
          hist_QmisID->SetBinError(i+1,j+1,minimizer->GetParError(index));
          index++;
      }
  }
  hist_QmisID->Write();
  outfile->Close(); 
  delete[] vstart;
  delete[] step;
  delete[] name;
  return 0; 
} 
