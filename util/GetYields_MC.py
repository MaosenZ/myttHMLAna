#!/usr/bin/env python

import ROOT, mytools, array
from ROOT import TFile, TTree, TGraphErrors, TGraph, gROOT
from array import array
from mytools import *

bdt_low, bdt_high = 0.5, 1
isOS=True
bkgs=["ttbar",\
           "diboson",\
           "ttV",\
           "rare","ttbargamma","Vjets"]

print "%s < BDT < %s " % (bdt_low, bdt_high)
def scan(samp, bdt_low, bdt_high, isOS):

    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/all/%s_bdtx.root" %samp)
    tree=inputfile.Get("nominal")
    passed, passed_err2=0, 0
    passed_truth, passed_truth_err2=0, 0
    for evt in tree:
        if (isOS==True and evt.tau_charge_0*evt.tau_charge_1<0) or (isOS==False and evt.tau_charge_0*evt.tau_charge_1>0):
           if samp == "data":
              if evt.Mybdt>bdt_low and evt.Mybdt<bdt_high and evt.tau_fromPV_0 and evt.tau_fromPV_1:
                 passed += 1
                 passed_err2 += 1
           else : 
              lumi=1.0
              if evt.RunYear < 2016.5: lumi=36074.6
              if evt.RunYear > 2016.5: lumi=43813.7
              if evt.nTaus_OR_Pt25<=0 : evt.tauSFTight=1.0
              weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
              #if evt.MVA1l2tau_weight>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
              if evt.Mybdt>bdt_low and evt.Mybdt<bdt_high :
                 passed += weight
                 passed_err2 += weight*weight
                 if evt.tau_truthType_0==10 and evt.tau_truthType_1==10:
                    passed_truth += weight
                    passed_truth_err2 += weight*weight
    #print "%s & %.2f$\\pm$%.2f"  % (samp,passed-passed_truth, sqrt(passed_err2+passed_truth_err2))
    print "%s & %.2f$\\pm$%.2f"  % (samp,passed, sqrt(passed_err2))
    return passed, sqrt(passed_err2)

#print scan('data',bdt_low, bdt_high, isOS)
#signal yield
#evt_tth, err_tth=scan("tth",bdt_low,bdt_high,isOS)
scan("tth",-1,0,True)
scan("tth",0,0.6,True)
scan("tth",0.6,1,True)
scan("tth",-1,1,True)
###ttV
##evt_ttV, err_ttV=scan("ttV",bdt_low,bdt_high,True)
###Diboson
##evt_diboson, err_diboson=scan("diboson",bdt_low,bdt_high,True)
###Rare
##evt_rare, err_rare=scan("rare",bdt_low,bdt_high,True)
###fakes
##evt_ssdata, err_ssdata=scan("data",bdt_low,bdt_high,False)
#b, err2_b=0, 0
#for bkg in bkgs:
#  tmp, err_tmp = scan(bkg, bdt_low, bdt_high, isOS)
#  b += tmp
#  err2_b += err_tmp*err_tmp
##significance
#s=evt_tth
#Z0=medianZ(s, b)
#err_b=sqrt(err2_b)
#print "Total B & %.2f$\\pm$%.2f"  % (b, err_b)
#print "z0  & %.2f " % Z0
