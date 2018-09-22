#!/usr/bin/env python

import ROOT, mytools, array
from ROOT import TFile, TTree, TGraphErrors, TGraph, gROOT
from array import array
from mytools import *

isOS=True

SetAtlasStyle()
gROOT.SetBatch(True)

def scan(samp, bdt_low, bdt_high, isOS):

    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/all/%s_notaubveto_bdtx.root" %samp)
    tree=inputfile.Get("nominal")
    passed, passed_err2=0, 0
    passed_truth, passed_truth_err2=0, 0
    passed_truth_bveto, passed_truth_bveto_err2=0, 0
    for evt in tree:
        #if (isOS==True and evt.tau_charge_0*evt.tau_charge_1<0) or (isOS==False and evt.tau_charge_0*evt.tau_charge_1>0):
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
              if evt.Mybdtx>bdt_low and evt.Mybdtx<bdt_high :
                 passed += weight
                 passed_err2 += weight*weight
                 #if evt.tau_truthType_0==10 and evt.tau_truthType_1==10:
                 if evt.tau_truth_0 ==0 or evt.tau_truth_1==0:
                    passed_truth += weight
                    passed_truth_err2 += weight*weight
                    #if (evt.tau_btag70_0==0 and evt.tau_truth_0 ==0 ) or (evt.tau_btag70_1==0 and evt.tau_truth_1==0):
                    if evt.tau_btag70_0==0 and evt.tau_btag70_1==0 :
                       passed_truth_bveto += weight
                       passed_truth_bveto_err2 += weight*weight
    #print "%s & %.2f$\\pm$%.2f"  % (samp,passed-passed_truth, sqrt(passed_err2+passed_truth_err2))
    #print "%s & %.2f$\\pm$%.2f"  % (samp,passed, sqrt(passed_err2))
    return passed_truth, sqrt(passed_truth_err2), passed_truth_bveto, sqrt(passed_truth_bveto_err2)

#print scan('data',bdt_low, bdt_high, isOS)
#signal yield
xbins=array("d",[-1,0.,0.6,1.0])
hist_signal=TH1F("hist_signal","",3,xbins)
hist_ttbar=TH1F("hist_ttbar","",3,xbins)

def getError(s,b,err_s, err_b):
    return (s/b)*sqrt(pow(err_s/s,2) + pow(err_b/b,2))

for inx in range(3):
    tmp_sig, err_sig, tmp_bveto_sig, err_bveto_sig=scan("tth",xbins[inx],xbins[inx+1],isOS) 
    tmp_bkg, err_bkg, tmp_bveto_bkg, err_bveto_bkg=scan("ttbar",xbins[inx],xbins[inx+1],isOS) 

    hist_signal.SetBinContent(inx+1, tmp_bveto_sig/tmp_sig)
    hist_signal.SetBinError(inx+1, getError(tmp_bveto_sig, tmp_sig, err_bveto_sig, err_sig))

    hist_ttbar.SetBinContent(inx+1, tmp_bveto_bkg/tmp_bkg)
    hist_ttbar.SetBinError(inx+1, getError(tmp_bveto_bkg, tmp_bkg, err_bveto_bkg, err_bkg))

c=createCanvas()
leg=TLegend(0.70,0.75,0.90,0.90)
leg.SetFillStyle(0);
leg.SetBorderSize(0);
leg.AddEntry(hist_signal, "tth", "l")
leg.AddEntry(hist_ttbar, "t#bar{t} MC", "l")
hist_signal.GetYaxis().SetTitleSize(0.06)
hist_signal.GetYaxis().SetTitleOffset(1)
hist_signal.GetYaxis().SetTitle("Ratio")
hist_signal.GetXaxis().SetTitle("BDT")
hist_signal.SetLineColor(kBlue)
hist_ttbar.SetLineColor(kRed)
hist_signal.Draw()
hist_ttbar.Draw("same")
hist_signal.SetMinimum(0.0)
hist_signal.SetMaximum(2.0)
createLabels()
leg.Draw("same")
c.SaveAs("plots/EffBveto.pdf")
