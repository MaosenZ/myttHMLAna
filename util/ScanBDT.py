#!/usr/bin/env python

import ROOT, mytools, array
from ROOT import TFile, TTree, TGraphErrors, TGraph, gROOT
from array import array
from mytools import *

def scan(samp, bdt):

    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v6_02/nominal/%s_bdt.root" %samp)
    tree=inputfile.Get("nominal")
    passed=0
    for evt in tree:
        lumi=1.0
        if evt.RunYear < 2016.5: lumi=36074.6
        if evt.RunYear > 2016.5: lumi=43813.7
        #weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_Continuous_EventWeight*evt.SherpaNJetWeight*( 36074.6*(evt.RunYear < 2016.5) +  43813.7*(evt.RunYear > 2016.5) )
        if evt.nTaus_OR_Pt25<=0 : evt.tauSFTight=1.0
        weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_Continuous_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
        #if evt.MVA1l2tau_weight>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
        if evt.Mybdt>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
           passed += weight
    return passed

bdts=(0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9)
points, points_errs=array('d'), array('d')
sigs, errs=array('d'), array('d')

for bdt in bdts:
    s=scan("tth",bdt)
    b=scan("ttbar", bdt)
    Z0=medianZ(s, b)
    points.append(bdt)
    sigs.append(Z0)
    #errs.append(ERR)
    points_errs.append(0)
    print "%.2f  %.2f"  % (bdt, Z0)
SetAtlasStyle()
gROOT.SetBatch(True)
#gr=TGraphErrors(9, points, sigs, points_errs, errs)
gr=TGraph(9, points, sigs)
gr.GetXaxis().SetTitle("BDT score")
gr.GetYaxis().SetTitle("Z0")
c=createCanvas()
gr.Draw("ALP")
c.SaveAs("plots/newbdt_scan.pdf")
