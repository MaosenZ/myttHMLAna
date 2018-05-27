#define NTUPLE_cxx
#include "../myttHAna/NTUPLE.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <string>
#include <fstream>
#include <sstream>
#include "commonSelections.cxx"
#include "commonWeight.cxx"
#include "applySelections.cxx"

void NTUPLE::makeMiniTree()
{
   /*if (fChain == 0) return ;
   int GeV(1000);
   bool debug(false);
   //book a tree here, which will be used by roofit
   TFile *outfile = new TFile("mini_20_zcjets_QmisIDBDT.root","recreate");
   TTree *minitree=new TTree("minitree","minitree");
   Double_t weight;
   Float_t  n_Mll01,n_lep_Pt_0,n_lep_Pt_1,n_lep_Eta_0,n_lep_Eta_1;
   Int_t n_total_charge;
   minitree->Branch("weight",&weight,"weight/D") ;
   minitree->Branch("Mll01",&n_Mll01,"n_weight/F");
   minitree->Branch("total_charge",&n_total_charge,"n_total_charge/I");
   minitree->Branch("lep_Pt_0",&n_lep_Pt_0,"n_lep_Pt_0/F");
   minitree->Branch("lep_Pt_1",&n_lep_Pt_1,"n_lep_Pt_1/F");
   minitree->Branch("lep_Eta_0",&n_lep_Eta_0,"n_lep_Eta_0/F");
   minitree->Branch("lep_Eta_1",&n_lep_Eta_1,"n_lep_Eta_1/F");

   Long64_t nentries = fChain->GetEntries();
   
   for(Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<
                            RunNumber<<" ismc "<<mc_channel_number<<std::endl;
       bool basic_selection = passEventCleaning;
       // merging tt vs ttgamma; Vjets vs Vgamma; then they can be merged:
       //if(_outhist.Contains("ttgamma"))basic_selection &=m_hasMEphoton_DRgt02_nonhad;
       //if(_outhist.Contains("_top_merged"))basic_selection &=!m_hasMEphoton_DRgt02_nonhad;
       //if(_outhist.Contains("Vjetsnozb")||_outhist.Contains("zbjets"))basic_selection &=m_MEphoton_pt/GeV<10;
       basic_selection &=((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH ||
                                             HLT_e60_lhmedium || HLT_e120_lhloose ))||
                                             (RunYear==2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose ||
                                                                HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
                         (RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
                         (RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1)));
       bool trig_match =(lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
       //double wt = mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_Continuous*lepSFObjTight*
       // ((!dilep_type||!total_charge)*lepSFTrigTight+(dilep_type&&total_charge)*lepSFTrigLoose)*tauSFTight*
       // JVT_EventWeight*SherpaNJetWeight*((quadlep_type>0)/lep_SFIsoLoose_0/lep_SFIsoLoose_1+(onelep_type>0)/lep_SFObjLoose_0*
       //                                   (mc_channel_number>0?(tau_truth_0+tau_truth_1)>1:1)+(!quadlep_type&&!onelep_type));   
        double wt = mc_channel_number>0?(mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_Continuous*lepSFObjTight*
                                       ((!dilep_type||!total_charge)*lepSFTrigTight+(dilep_type&&total_charge)*lepSFTrigLoose)*(tauSFTight<10?tauSFTight:1.0)*
                                       JVT_EventWeight*SherpaNJetWeight*((quadlep_type>0?1./lep_SFIsoLoose_0/lep_SFIsoLoose_1:0.)+
                                                                         (onelep_type>0?1./lep_SFObjLoose_0:0.)+(!quadlep_type&&!onelep_type))):1.0;
       //begin selection
       if(basic_selection && trig_match  &&
           total_leptons==2 && abs(lep_ID_0)==11 && abs(lep_ID_1)==11 &&
           lep_Pt_0>20e3&&lep_Pt_1>20e3 && 
           lep_promptLeptonIso_TagWeight_0<-0.5 && lep_promptLeptonIso_TagWeight_1<-0.5 &&
           (*electron_ChargeIDBDTTight)[0] > 0.0670415 && (*electron_ChargeIDBDTTight)[1] > 0.0670415){
          weight=wt;
          n_Mll01=Mll01/GeV;            
          n_total_charge=total_charge;
          n_lep_Pt_0=lep_Pt_0/GeV;
          n_lep_Pt_1=lep_Pt_1/GeV;
          n_lep_Eta_0=lep_Eta_0;
          n_lep_Eta_1=lep_Eta_1;
          minitree->Fill();
       }//end of basic selections 
   }//end of event loop 
   minitree->Write();
   outfile->Close();*/
}

void NTUPLE::fillHists(std::map<string, TH1F* > & TH1Fs){

   Long64_t nentries = fChain->GetEntries();
   unsigned int numRegions=m_Regions.size();
   for(Long64_t jentry=0; jentry<nentries;jentry++){
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<<
          EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;

       if(m_commonSelections && (!commonSelections())) continue;
       double wt;
       wt=commonWeight();
       if (mySample=="data") wt=1.0;
       //further selections
       string mySelection, regionname,name, var, vartype;
       size_t pos=0;
       //cout<<"tau_tight_1: "<<tau_tight_1<<endl;
       //cout<<"tau_btag70_1: "<<tau_btag70_1<<endl;
       //cout<<"----------------"<<endl;
       for(unsigned int ir=0;ir<numRegions;ir++){//fill various regions/selections
           mySelection=m_Regions[ir];
           if(applySelections(mySelection)){//apply selections
              for(std::map<string, TH1F*>::iterator it=TH1Fs.begin();it!=TH1Fs.end();it++){ 
                  name=it->first;
                  pos=name.find("_");
                  regionname=name.substr(0,pos);
                  if(regionname != mySelection) continue; //only fill current region of course!
                  var=name.substr(pos+1, name.length()-3-pos);//the name is defined as 'regionname_varname_vartype'
                  //if(var=="lep_Pt_0") TH1Fs[it->first]->Fill(lep_Pt_0/GeV,wt);
                  vartype=name.substr(name.length()-1);
                  /*cout<<"----------------"<<endl;
                  cout<<"input_branches[var].i: "<<var<<input_branches[var].i<<endl;
                  cout<<"input_branches[var].f: "<<var<<input_branches[var].f<<endl;
                  cout<<"----------------"<<endl;*/
                  if(vartype=="I") { TH1Fs[name]->Fill( input_branches[var].i, wt);
                     /*cout<<"var: "<<var<<endl;
                     cout<<"vartype: "<<vartype<<endl;
                     cout<<"input_branches[var].i: "<<input_branches[var].i<<endl;
                     cout<<"wt: "<<wt<<endl;*/
                  }
                  if(vartype=="F") {
                     //cout<<"name: "<<name<<" var: "<<var<<" f: "<<input_branches[var].f<<" GeV: "<<GeV<<endl;
                     if(var.find("weight")!=string::npos || var.find("dr")!=string::npos
                        || var.find("nj")!=string::npos || var.find("nb")!=string::npos || 
                        var.find("tight")!=string::npos) 
                        {TH1Fs[name]->Fill( input_branches[var].f, wt);
  			 //cout<<var<<endl;
			}
                     else {TH1Fs[name]->Fill( (input_branches[var].f)/GeV, wt);
	                 //cout<<"gev: "<<var<<" f:"<<(input_branches[var].f)/GeV<<endl;
		     }
                  }
              }
           }//end of basic selections
       }
       //cout<<"----------------"<<endl;
   }//end of event loop
}

void NTUPLE::cutFlow(){
  //get tree weights
  Long64_t nentries = fChain->GetEntries();
  double numinput(0), numevtcln(0), numcomsel(0), numNlepton(0), numtrigmatch(0), numNtau(0), numTightL(0);
  double numwtinput(0), numwtevtcln(0),numwtcomsel(0), numwtNlepton(0), numwttrigmatch(0), numwtNtau(0), numwtTightL(0);
  for(Long64_t jentry=0; jentry<nentries;jentry++){
       /*Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       SumOfTotalWeightedEvents = counts[tree_number-1];*/
        
       fChain->GetEntry(jentry);
       if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<"/"<<nentries<<" Event "<<
          EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<" wt "<<SumOfTotalWeightedEvents<<std::endl;
       double wt;
       wt=commonWeight();
       if (mySample=="data") wt=1.0;

       if(!((onelep_type||dilep_type||trilep_type||quadlep_type))) continue;
          numinput++, numwtinput+=wt;
       if(!passEventCleaning) continue;
          numevtcln++; numwtevtcln+=wt;
       if(m_commonSelections && (!commonSelections())) continue;
          numcomsel++; numwtcomsel+=wt; 
       //if(!(onelep_type>0 && input_branches["lep_isolationFixedCutLoose_0"].i&&(abs(input_branches["lep_ID_0"].f)==13||((abs(input_branches["lep_ID_0"].f)==11)&&input_branches["lep_isTightLH_0"].c)))) continue;
       if(!(onelep_type>0)) continue;
          numNlepton++; numwtNlepton+=wt;
       if(!lep_isTrigMatch_0) continue;
          numtrigmatch++; numwttrigmatch+=wt;
       if(!(nTaus_OR_Pt25==2&&input_branches["tau_charge_0"].f*input_branches["tau_charge_1"].f<0)) continue;
          numNtau++; numwtNtau+=wt;
       if(!((abs(input_branches["lep_ID_0"].f)==11&&input_branches["lep_isolationFixedCutLoose_0"].i&&input_branches["lep_isTightLH_0"].c&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.7&&(int)(input_branches["lep_ambiguityType_0"].c)==0)||(abs(input_branches["lep_ID_0"].f)==13&&input_branches["lep_promptLeptonVeto_TagWeight_0"].f<-0.5&&input_branches["lep_isolationFixedCutLoose_0"].i))) continue;
          numTightL++; numwtTightL+=wt;
          
  }
  cout<<" Events "<<setw(20)<<" Events (weighted)"<<endl;
  cout<<numinput<<setw(20)<<numwtinput<<endl;
  cout<<numevtcln<<setw(20)<<numwtevtcln<<endl;
  cout<<numcomsel<<setw(20)<<numwtcomsel<<endl;
  cout<<numNlepton<<setw(20)<<numwtNlepton<<endl;
  cout<<numtrigmatch<<setw(20)<<numwttrigmatch<<endl;
  cout<<numNtau<<setw(20)<<numwtNtau<<endl;
  cout<<numTightL<<setw(20)<<numwtTightL<<endl; 
}
