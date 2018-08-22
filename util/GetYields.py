#!/usr/bin/env python

import ROOT, mytools, array
from ROOT import TFile, TTree, TGraphErrors, TGraph, gROOT
from array import array
from mytools import *

bdt_low, bdt_high = 0.6,1
bkgs=["ttbar",\
           "diboson",\
           "ttV",\
           "rare"]

def scan(samp, bdt_low, bdt_high, isOS):

    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v6_04/all/%s_bdt.root" %samp)
    tree=inputfile.Get("nominal")
    passed, passed_err2=0, 0
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
              weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_Continuous_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
              #if evt.MVA1l2tau_weight>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
              if evt.Mybdt>bdt_low and evt.Mybdt<bdt_high and evt.tau_truthType_0==10 and evt.tau_truthType_1==10 :
                 passed += weight
                 passed_err2 += weight*weight
    return passed, sqrt(passed_err2)

#print scan('data',bdt_low, bdt_high, True)
#signal yield
evt_tth, err_tth=scan("tth",bdt_low,bdt_high,True)
#ttV
evt_ttV, err_ttV=scan("ttV",bdt_low,bdt_high,True)
#Diboson
evt_diboson, err_diboson=scan("diboson",bdt_low,bdt_high,True)
#Rare
evt_rare, err_rare=scan("rare",bdt_low,bdt_high,True)
#fakes
evt_ssdata, err_ssdata=scan("data",bdt_low,bdt_high,False)
evt_sstruth, err2_sstruth=0, 0
for bkg in bkgs:
  tmp, err_tmp = scan(bkg, bdt_low, bdt_high, False)
  evt_sstruth += tmp
  err2_sstruth += err_tmp*err_tmp
evt_fakes=evt_ssdata-evt_sstruth
err_fakes=sqrt(err2_sstruth + err_ssdata*err_ssdata)
#significance
s=evt_tth
b=evt_ttV+evt_diboson+evt_rare+evt_fakes
err_b=sqrt(err_fakes*err_fakes+err_rare*err_rare+err_diboson*err_diboson+err_ttV*err_ttV+err_tth*err_tth)
Z0=medianZ(s, b)
print "%s < BDT < %s " % (bdt_low, bdt_high)
print "ttH(truth) & %.2f$\\pm$%.2f"  % (evt_tth, err_tth)
print "ttV(truth) & %.2f$\\pm$%.2f"  % (evt_ttV, err_ttV)
print "diboson(truth) & %.2f$\\pm$%.2f"  % (evt_diboson, err_diboson)
print "rare(truth) & %.2f$\\pm$%.2f"  % (evt_rare, err_rare)
print "fakes(truth) & %.2f$\\pm$%.2f"  % (evt_fakes, err_fakes)
print "Total B & %.2f$\\pm$%.2f"  % (b, err_b)
print "z0  & %.2f " % Z0
