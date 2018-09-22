#!/usr/bin/env python

import ROOT, mytools, array
from ROOT import TFile, TTree, TGraphErrors, TGraph, gROOT
from array import array
from mytools import *

bkgs=["ttbar",\
           "diboson",\
           "ttV",\
           "rare",\
           "ttbargamma","Vjets"]

def scan(samp, bdt):

    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/all/%s_bdtx.root" %samp)
    tree=inputfile.Get("nominal")
    passed=0
    for evt in tree:
        lumi=1.0
        if evt.RunYear < 2016.5: lumi=36074.6
        if evt.RunYear > 2016.5: lumi=43813.7
        #weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*( 36074.6*(evt.RunYear < 2016.5) +  43813.7*(evt.RunYear > 2016.5) )
        if evt.nTaus_OR_Pt25<=0 : evt.tauSFTight=1.0
        weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
        #if evt.MVA1l2tau_weight>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
        if evt.Mybdtx>bdt and evt.tau_charge_0*evt.tau_charge_1<0 and evt.tau_passMuonOLR_0==1 and evt.tau_passEleBDT_0==1 and evt.tau_passMuonOLR_1==1 and evt.tau_passEleBDT_1==1:
           passed += weight
           print evt.RunNumber, evt.EventNumber, evt.Mybdtx, evt.lep_Pt_0, weight
    return passed

scan('tth',0.6)
