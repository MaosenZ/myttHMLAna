#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists, TChain, TTreeFormula
from ROOT import TString
import sys

prepath="/Users/mason/Desktop/myWork/ttHMLSamps/SampleT/"

def Count(chan, trigs):
    #deal with weights first
    sumWeights=TChain("sumWeights")
    sumWeights.Add("%stth*.root" % prepath) 
    weights=[]
    fCurrent_wt = 0
    sampleNEvt=0
    nWeightEntries=sumWeights.GetEntries()
    for a in range(nWeightEntries):
       sumWeights.GetEntry(a)
       totalEventsWeighted=getattr(sumWeights, 'totalEventsWeighted')
       if sumWeights.GetTreeNumber() != fCurrent_wt:
          fCurrent_wt = sumWeights.GetTreeNumber()
          weights.append(sampleNEvt)
          sampleNEvt=0
       sampleNEvt = sampleNEvt+totalEventsWeighted
       if a==nWeightEntries-1: weights.append(sampleNEvt) #last file
    chain=TChain("nominal")
    chain.Add("%stth*.root" % prepath)
    nentries=chain.GetEntries()

    chain.SetBranchStatus("*",0) 
    chain.SetBranchStatus("Mll01",1)
    chain.SetBranchStatus("total_charge",1)
    chain.SetBranchStatus("lep_Pt_0",1)
    chain.SetBranchStatus("lep_Pt_1",1)
    chain.SetBranchStatus("lep_Eta_0",1)
    chain.SetBranchStatus("lep_Eta_1",1)
    chain.SetBranchStatus("lep_ID_0",1)
    chain.SetBranchStatus("lep_ID_1",1)
    chain.SetBranchStatus("lep_truthPdgId_0",1)
    chain.SetBranchStatus("lep_truthPdgId_1",1)
    chain.SetBranchStatus("lep_truthOrigin_0",1)
    chain.SetBranchStatus("lep_truthOrigin_1",1)
    chain.SetBranchStatus("lep_truthType_0",1)
    chain.SetBranchStatus("lep_truthType_1",1)
    chain.SetBranchStatus("lep_isQMisID_0",1)
    chain.SetBranchStatus("lep_isQMisID_1",1)
    chain.SetBranchStatus("nJets_OR_T_MV2c10_70",1)
    chain.SetBranchStatus("nJets_OR_T",1)
    chain.SetBranchStatus("lep_isTightLH_0",1)
    chain.SetBranchStatus("lep_isTightLH_1",1)
    chain.SetBranchStatus("lep_isLooseLH_0",1)
    chain.SetBranchStatus("lep_isLooseLH_1",1)
    chain.SetBranchStatus("lep_isolationFixedCutTight_0",1)
    chain.SetBranchStatus("lep_isolationFixedCutLoose_0",1)
    chain.SetBranchStatus("lep_isolationFixedCutTight_1",1)
    chain.SetBranchStatus("lep_isolationFixedCutLoose_1",1)
    chain.SetBranchStatus("lep_isolationFixedCutTightTrackOnly_0",1)
    chain.SetBranchStatus("lep_isolationFixedCutTightTrackOnly_1",1)
    chain.SetBranchStatus("HLT*",1)
    chain.SetBranchStatus("*type",1)
    chain.SetBranchStatus("RunYear",1)
    chain.SetBranchStatus("passEventCleaning",1)
    chain.SetBranchStatus("lep_isTrigMatch_0",1)
    chain.SetBranchStatus("lep_isTrigMatch_1",1)
    chain.SetBranchStatus("lep_isTrigMatchDLT_0",1)
    chain.SetBranchStatus("lep_isTrigMatchDLT_1",1)
    chain.SetBranchStatus("mcWeightOrg",1)
    chain.SetBranchStatus("pileupEventWeight_090",1)
    chain.SetBranchStatus("lepSFObjTight",1)
    chain.SetBranchStatus("lepSFTrigTight",1)
    chain.SetBranchStatus("JVT_EventWeight",1)
    chain.SetBranchStatus("SherpaNJetWeight",1)
    chain.SetBranchStatus("MV2c10_70_EventWeight",1)
    chain.SetBranchStatus("lep_chargeIDBDT*",1)
    chain.SetBranchStatus("nTaus_OR_Pt25",1)
    chain.SetBranchStatus("tau_JetBDTSigTight_0",1)
    chain.SetBranchStatus("tau_JetBDTSigTight_1",1)
    chain.SetBranchStatus("tau_tagWeightBin_0",1)
    chain.SetBranchStatus("tau_tagWeightBin_1",1)
    chain.SetBranchStatus("tau_passMuonOLR_0",1)
    chain.SetBranchStatus("tau_passMuonOLR_1",1)
    chain.SetBranchStatus("tau_passEleBDT_0",1)
    chain.SetBranchStatus("tau_passEleBDT_1",1)
    chain.SetBranchStatus("tau_charge_0",1)
    chain.SetBranchStatus("tau_charge_1",1)
    chain.SetBranchStatus("lep_ID_2",1)
    chain.SetBranchStatus("Mll02",1)
    chain.SetBranchStatus("lep_promptLeptonVeto_TagWeight_0",1)
    chain.SetBranchStatus("lep_promptLeptonVeto_TagWeight_1",1)
    chain.SetBranchStatus("lep_ambiguityType_0",1)
    chain.SetBranchStatus("lep_ambiguityType_1",1)
    #cuts
    fCurrent=-1
    chain.LoadTree(0)
    cuts_sr=TTreeFormula("cuts_sr",chan,chain)
    cuts_trig=TTreeFormula("cuts_trig",trigs,chain)
    raw_evts, numevts=0,0
    for evt in range(nentries):
    #for event in chain:
       #if evt%10000==0 : print evt
       chain.GetEntry(evt)
       #get current file
       currentFileName=chain.GetCurrentFile().GetName()
       RunYear=getattr(chain, "RunYear")
       mcWeightOrg=getattr(chain, "mcWeightOrg")
       pileupEventWeight_090=getattr(chain, "pileupEventWeight_090")
       lepSFObjTight=getattr(chain, "lepSFObjTight")
       lepSFTrigTight=getattr(chain, "lepSFTrigTight")
       JVT_EventWeight=getattr(chain, "JVT_EventWeight")
       SherpaNJetWeight=getattr(chain, "SherpaNJetWeight")
       MV2c10_70_EventWeight=getattr(chain, "MV2c10_70_EventWeight")
       lumi=1.0
       if RunYear < 2016.5: lumi=36074.6
       if RunYear > 2016.5: lumi=43813.7
       if chain.GetTreeNumber() != fCurrent:
          fCurrent=chain.GetTreeNumber()
          cuts_sr.Notify()
          cuts_trig.Notify()
       if cuts_sr.EvalInstance() and cuts_trig.EvalInstance():
       #if cuts_trig.EvalInstance():
          if "341177" in currentFileName: weight=0.05343
          if "341270" in currentFileName: weight=0.22276
          if "341271" in currentFileName: weight=0.23082
          kfac, filEff=1,1
          weight=weight*kfac*filEff*mcWeightOrg*pileupEventWeight_090*lepSFObjTight*lepSFTrigTight*JVT_EventWeight*SherpaNJetWeight*MV2c10_70_EventWeight*lumi/weights[fCurrent]
          #print xsec, kfac, filEff, event.mcWeightOrg,event.pileupEventWeight_090,event.lepSFObjTight,event.lepSFTrigTight,event.JVT_EventWeight,event.SherpaNJetWeight,event.MV2c10_70_EventWeight, lumi
	  raw_evts=raw_evts+1
          numevts=numevts+weight
    print "%s(%.2f)" %(raw_evts, numevts)
Common="(passEventCleaning)"	
OneL2tauSR="(passEventCleaning && onelep_type>0 && ( abs(lep_ID_0)==13 ||((abs(lep_ID_0)==11)&&lep_isTightLH_0)) && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 && nTaus_OR_Pt25==2 && tau_JetBDTSigTight_0 && tau_JetBDTSigTight_1 && nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 && tau_tagWeightBin_1<4 && tau_tagWeightBin_0 <4 && tau_passMuonOLR_0==1&&tau_passEleBDT_0==1&&tau_passMuonOLR_1==1&&tau_passEleBDT_1==1)"#&&lep_isTrigMatch_0
TwoLSS1tauSR="(dilep_type>0 && nTaus_OR_Pt25==1 && lep_ID_0*lep_ID_1>0 &&(abs(Mll01-91.2e3)>10e3 || abs(lep_ID_0)!=11 || abs(lep_ID_1)!=11) && nJets_OR_T>=2&&nJets_OR_T_MV2c10_70>=1 && lep_Pt_0>20e3 && lep_Pt_1>20e3)"
TwoLOS1tauSR="dilep_type>0&&lep_ID_0*lep_ID_1<0&&(abs(lep_ID_0)!=abs(lep_ID_1) || abs(Mll01-91200)>10000)&&nTaus_OR_Pt25==1&&nJets_OR_T>=3&&nJets_OR_T_MV2c10_70>=1"
TwoL2tauSR="(dilep_type>0 && (lep_ID_0*lep_ID_1<0) && ((abs(lep_ID_0)==13 && lep_isolationFixedCutLoose_0 && lep_promptLeptonVeto_TagWeight_0<-0.5) || (abs(lep_ID_0)==11 && lep_isolationFixedCutLoose_0 && lep_isTightLH_0 && lep_chargeIDBDTTight_0>0.7 && lep_ambiguityType_0 == 0 && lep_promptLeptonVeto_TagWeight_0<-0.7)) && ((abs(lep_ID_1)==13 && lep_isolationFixedCutLoose_1 && lep_promptLeptonVeto_TagWeight_1<-0.5) || (abs(lep_ID_1)==11 && lep_isolationFixedCutLoose_1 && lep_isTightLH_1 && lep_chargeIDBDTTight_1>0.7 && lep_ambiguityType_1 == 0 && lep_promptLeptonVeto_TagWeight_1<-0.7)) && nTaus_OR_Pt25==2 && tau_JetBDTSigTight_0 && tau_JetBDTSigTight_1 && nJets_OR_T_MV2c10_70>=1 && tau_charge_0*tau_charge_1<0 && tau_passMuonOLR_0==1 && tau_passEleBDT_0==1 && tau_tagWeightBin_0 <4 && tau_passMuonOLR_1==1 && tau_passEleBDT_1==1 && tau_tagWeightBin_1<4)"
ThreeL1tauSR="(trilep_type>0&&nTaus_OR_Pt25==1&&(total_charge+tau_charge_0)==0&&nJets_OR_T>=2&&nJets_OR_T_MV2c10_70>=1&&(lep_ID_0!=-lep_ID_1||(Mll01>12e3&&abs(Mll01-91.2e3)>10e3))&&(lep_ID_0!=-lep_ID_2||(Mll02>12e3&&abs(Mll02-91.2e3)>10e3)))"
DilepTrigs="((RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1)))"
OnelepTrigs="((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 )))"
New="(HLT_e17_lhmedium_nod0_ivarloose_tau25_mediumRNN_tracktwoMVA || HLT_e17_lhmedium_nod0_ivarloose_tau25_mediumRNN_tracktwoMVA_L1EM15VHI_2TAU12IM_4J12 || HLT_e24_lhmedium_nod0_ivarloose_tau35_mediumRNN_tracktwoMVA || HLT_mu14_ivarloose_tau25_mediumRNN_tracktwoMVA || HLT_mu14_ivarloose_tau25_mediumRNN_tracktwoMVA_L1MU10_TAU12IM_3J12 || HLT_mu14_ivarloose_tau35_mediumRNN_tracktwoMVA)"
New1="(HLT_e17_lhmedium_nod0_ivarloose_tau25_mediumRNN_tracktwoMVA)"
New2="(HLT_e17_lhmedium_nod0_ivarloose_tau25_mediumRNN_tracktwoMVA_L1EM15VHI_2TAU12IM_4J12)"
New3="(HLT_e24_lhmedium_nod0_ivarloose_tau35_mediumRNN_tracktwoMVA)"
New4="(HLT_mu14_ivarloose_tau25_mediumRNN_tracktwoMVA)"
New5="(HLT_mu14_ivarloose_tau25_mediumRNN_tracktwoMVA_L1MU10_TAU12IM_3J12)"
New6="(HLT_mu14_ivarloose_tau35_mediumRNN_tracktwoMVA)"
Count(OneL2tauSR,OnelepTrigs)
Count(OneL2tauSR,OnelepTrigs+"||"+New)
Count(OneL2tauSR,New)
Count(OneL2tauSR,OnelepTrigs+"||"+New1)
Count(OneL2tauSR,OnelepTrigs+"||"+New2)
Count(OneL2tauSR,OnelepTrigs+"||"+New3)
Count(OneL2tauSR,OnelepTrigs+"||"+New4)
Count(OneL2tauSR,OnelepTrigs+"||"+New5)
Count(OneL2tauSR,OnelepTrigs+"||"+New6)
Count(OneL2tauSR,"HLT_mu20_iloose_L1MU15")
Count(OneL2tauSR,"HLT_mu50")
Count(OneL2tauSR,"HLT_e24_lhmedium_L1EM20VH")
Count(OneL2tauSR,"HLT_e60_lhmedium")
Count(OneL2tauSR,"HLT_e120_lhloose")
Count(OneL2tauSR,"HLT_mu26_ivarmedium")
Count(OneL2tauSR,"HLT_e26_lhtight_nod0_ivarloose")
Count(OneL2tauSR,"HLT_e60_lhmedium_nod0")
Count(OneL2tauSR,"HLT_e140_lhloose_nod0")
Count(OneL2tauSR,"HLT_2e12_lhloose_L12EM10VH")
Count(OneL2tauSR,"HLT_e17_lhloose_mu14")
Count(OneL2tauSR,"HLT_mu18_mu8noL1")
Count(OneL2tauSR,"HLT_2e17_lhvloose_nod0")
Count(OneL2tauSR,"HLT_e17_lhloose_nod0_mu14")
Count(OneL2tauSR,"HLT_mu22_mu8noL1")
Count(OneL2tauSR,New1)
Count(OneL2tauSR,New2)
Count(OneL2tauSR,New3)
Count(OneL2tauSR,New4)
Count(OneL2tauSR,New5)
Count(OneL2tauSR,New6)
