/*
 * This macro is to subtract sideband for Z peak
 * */
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include <iostream>

void CalSideband(){
 
  //boundaries for a, b, c regions
  Float_t alow_ss=51.7, blow_ss=76.5, clow_ss=101.3, cup_ss=126;
  Float_t alow_os=54.7, blow_os=78.5, clow_os=102.3, cup_os=126;
  double sf_os, sf_ss;
 
  TFile *f=new TFile("output/mini.root");
  TTree *tree=(TTree*)f->Get("minitree");

  Double_t weight;
  Float_t Mll01,lep_Pt_0,lep_Pt_1,lep_Eta_0,lep_Eta_1;
  Int_t total_charge;
  
  tree->SetBranchAddress("weight",&weight);
  tree->SetBranchAddress("Mll01",&Mll01);
  tree->SetBranchAddress("total_charge",&total_charge);
  tree->SetBranchAddress("lep_Pt_0",&lep_Pt_0);
  tree->SetBranchAddress("lep_Pt_1",&lep_Pt_1);
  tree->SetBranchAddress("lep_Eta_0",&lep_Eta_0);
  tree->SetBranchAddress("lep_Eta_1",&lep_Eta_1);

  Double_t bcount_ss(0),acount_ss(0),ccount_ss(0),nbcount_ss(0);
  Double_t bcount_os(0),acount_os(0),ccount_os(0),nbcount_os(0);
  //book outbut root
  TFile *outfile=new TFile("Hists_mini.root","recreate");
  Float_t eta_bins[7]={0,0.6,1.1,1.37,1.52,2.0,2.47};
  Float_t pt_bins[5]={10,60,90,130,1000};

  TH2D *hist_os=new TH2D("hist_os","hist_os",36,0,36,16,0,16);
  TH2D *hist_ss=new TH2D("hist_ss","hist_ss",36,0,36,16,0,16);
  TH2D *hist_os_counts=new TH2D("hist_os_counts","hist_os_counts",6,eta_bins,4,pt_bins);
  TH2D *hist_ss_counts=new TH2D("hist_ss_counts","hist_ss_counts",6,eta_bins,4,pt_bins);
 
  Double_t counts_os[36][16], ncounts_ss[36][16]; Double_t counts_ss[36][16] ,ncounts_os[36][16];
  for(int i=0;i<6;i++){
      for(int j=0;j<4;j++){
          for(int k=i;k<6;k++){
              for(int l=j;l<4;l++){
                  counts_os[6*i+k][4*j+l]=0;
                  counts_ss[6*i+k][4*j+l]=0;
                  ncounts_os[6*i+k][4*j+l]=0;
                  ncounts_ss[6*i+k][4*j+l]=0;
              }
          }
      }
  }
  for(Long64_t entry=0;entry<tree->GetEntries();entry++){
      tree->GetEntry(entry);
      if(fabs(weight)>200) continue;//to avoid some abnormally large weights
      if(lep_Pt_0>=1000) lep_Pt_0=999;
      if(lep_Pt_1>=1000) lep_Pt_1=999;
      if(fabs(total_charge)==0){
         if(Mll01>alow_os && Mll01<blow_os) acount_os+=weight;
         if(Mll01>blow_os && Mll01<clow_os){
            bcount_os+=weight;
            nbcount_os++;
            hist_os_counts->Fill(fabs(lep_Eta_0),lep_Pt_0,weight);
            hist_os_counts->Fill(fabs(lep_Eta_1),lep_Pt_1,weight);
            for(int i=0;i<6;i++){
                for(int j=0;j<4;j++){//
                    for(int k=i;k<6;k++){
                        for(int m=j;m<4;m++){//
                            if( (fabs(lep_Eta_0)>=eta_bins[i] && fabs(lep_Eta_0)<eta_bins[i+1] 
                               && lep_Pt_0>=pt_bins[j] && lep_Pt_0<pt_bins[j+1]
                               && fabs(lep_Eta_1)>=eta_bins[k] && fabs(lep_Eta_1)<eta_bins[k+1]
                               && lep_Pt_1>=pt_bins[m] && lep_Pt_1<pt_bins[m+1]) ||
                                (fabs(lep_Eta_1)>=eta_bins[i] && fabs(lep_Eta_1)<eta_bins[i+1]
                               && lep_Pt_0>=pt_bins[j] && lep_Pt_0<pt_bins[j+1]
                               && fabs(lep_Eta_0)>=eta_bins[k] && fabs(lep_Eta_0)<eta_bins[k+1]
                               && lep_Pt_1>=pt_bins[m] && lep_Pt_1<pt_bins[m+1]) ||
                                (fabs(lep_Eta_0)>=eta_bins[i] && fabs(lep_Eta_0)<eta_bins[i+1]
                               && lep_Pt_1>=pt_bins[j] && lep_Pt_1<pt_bins[j+1]
                               && fabs(lep_Eta_1)>=eta_bins[k] && fabs(lep_Eta_1)<eta_bins[k+1]
                               && lep_Pt_0>=pt_bins[m] && lep_Pt_0<pt_bins[m+1]) ||
                                (fabs(lep_Eta_1)>=eta_bins[i] && fabs(lep_Eta_1)<eta_bins[i+1]
                               && lep_Pt_1>=pt_bins[j] && lep_Pt_1<pt_bins[j+1]
                               && fabs(lep_Eta_0)>=eta_bins[k] && fabs(lep_Eta_0)<eta_bins[k+1]
                               && lep_Pt_0>=pt_bins[m] && lep_Pt_0<pt_bins[m+1]) )
                                {counts_os[6*i+k][4*j+m]+=weight;
                                 ncounts_os[6*i+k][4*j+m]++;
                                }
                        }//end m
                    }//end k
                }//end j
            }//end i
         }
         if(Mll01>clow_os && Mll01<cup_os) ccount_os+=weight;
      }
      if(fabs(total_charge)==2){
         if(Mll01>alow_ss && Mll01<blow_ss) acount_ss+=weight;
         if(Mll01>blow_ss && Mll01<clow_ss){
            bcount_ss+=weight;
            nbcount_ss++;
            hist_ss_counts->Fill(fabs(lep_Eta_0),lep_Pt_0,weight);
            hist_ss_counts->Fill(fabs(lep_Eta_1),lep_Pt_1,weight);
            for(int i=0;i<6;i++){
                for(int j=0;j<4;j++){//
                    for(int k=i;k<6;k++){
                        for(int m=j;m<4;m++){//
                            if( (fabs(lep_Eta_0)>=eta_bins[i] && fabs(lep_Eta_0)<eta_bins[i+1]
                               && lep_Pt_0>=pt_bins[j] && lep_Pt_0<pt_bins[j+1]
                               && fabs(lep_Eta_1)>=eta_bins[k] && fabs(lep_Eta_1)<eta_bins[k+1]
                               && lep_Pt_1>=pt_bins[m] && lep_Pt_1<pt_bins[m+1]) ||
                                (fabs(lep_Eta_1)>=eta_bins[i] && fabs(lep_Eta_1)<eta_bins[i+1]
                               && lep_Pt_0>=pt_bins[j] && lep_Pt_0<pt_bins[j+1]
                               && fabs(lep_Eta_0)>=eta_bins[k] && fabs(lep_Eta_0)<eta_bins[k+1]
                               && lep_Pt_1>=pt_bins[m] && lep_Pt_1<pt_bins[m+1]) ||
                                (fabs(lep_Eta_0)>=eta_bins[i] && fabs(lep_Eta_0)<eta_bins[i+1]
                               && lep_Pt_1>=pt_bins[j] && lep_Pt_1<pt_bins[j+1]
                               && fabs(lep_Eta_1)>=eta_bins[k] && fabs(lep_Eta_1)<eta_bins[k+1]
                               && lep_Pt_0>=pt_bins[m] && lep_Pt_0<pt_bins[m+1]) ||
                                (fabs(lep_Eta_1)>=eta_bins[i] && fabs(lep_Eta_1)<eta_bins[i+1]
                               && lep_Pt_1>=pt_bins[j] && lep_Pt_1<pt_bins[j+1]
                               && fabs(lep_Eta_0)>=eta_bins[k] && fabs(lep_Eta_0)<eta_bins[k+1]
                               && lep_Pt_0>=pt_bins[m] && lep_Pt_0<pt_bins[m+1]) )
                                { counts_ss[6*i+k][4*j+m]+=weight; ncounts_ss[6*i+k][4*j+m]++;
                                }
                        }//end m
                    }//end k
                }//end j
            }//end i
         }
         if(Mll01>clow_ss && Mll01<cup_ss) ccount_ss+=weight;
      }
  }//end of event loop
  //subtract and calculate scale factor for z peak events
  std::cout<<"<< ============== OS events ============== >>"<<std::endl;
  std::cout<<"              A             B              C"<<std::endl;
  std::cout<<"numOfevts:"<<acount_os<<"     "<<bcount_os<<"    "<<ccount_os<<std::endl;
  sf_os=(bcount_os-(acount_os+ccount_os)/2.)/bcount_os;
  std::cout<<"So Z peak events are: "<<bcount_os-(acount_os+ccount_os)/2.<<" and corresponding scale factor is "<<
             (bcount_os-(acount_os+ccount_os)/2.)/bcount_os<<std::endl;
  std::cout<<"<< ============== SS events ============== >>"<<std::endl;
  std::cout<<"              A             B              C"<<std::endl;
  std::cout<<"numOfevts:"<<acount_ss<<"     "<<bcount_ss<<"    "<<ccount_ss<<std::endl;
  sf_ss=(bcount_ss-(acount_ss+ccount_ss)/2.)/bcount_ss;
  std::cout<<"So Z peak events are: "<<bcount_ss-(acount_ss+ccount_ss)/2.<<" and corresponding scale factor is "<<
             (bcount_ss-(acount_ss+ccount_ss)/2.)/bcount_ss<<std::endl;
  double check_ss=0,check_os=0;
  for(int i=0;i<6;i++){
      for(int j=0;j<4;j++){//
          for(int k=i;k<6;k++){
              for(int m=j;m<4;m++){//
                   check_ss+=ncounts_ss[6*i+k][4*j+m];
                   check_os+=ncounts_os[6*i+k][4*j+m];
                   hist_ss->SetBinContent(6*i+k+1,4*j+m+1,counts_ss[6*i+k][4*j+m]);
                   hist_os->SetBinContent(6*i+k+1,4*j+m+1,counts_os[6*i+k][4*j+m]);
              }//end m
          }//end k
      }//end j
  }//end i
  std::cout<<"check ss: "<<check_ss <<" nbcount_ss: "<<nbcount_ss<<std::endl;
  std::cout<<"check os: "<<check_os <<" nbcount_os: "<<nbcount_os<<std::endl;
  hist_ss->Write();
  hist_os->Write();
  hist_os_counts->Write();
  hist_ss_counts->Write();
  outfile->Close();
}
