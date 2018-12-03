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

    inputfile=TFile("/Users/mason/Desktop/myWork/myttHMLAna/hists/%s.root" %samp)
    tree=inputfile.Get("minitree")
    passed=0
    for evt in tree:
        lumi=1.0
        #if evt.RunYear < 2016.5: lumi=36074.6
        #if evt.RunYear > 2016.5: lumi=43813.7
        #weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*( 36074.6*(evt.RunYear < 2016.5) +  43813.7*(evt.RunYear > 2016.5) )
        #if evt.nTaus_OR_Pt25<=0 : evt.tauSFTight=1.0
        #weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
        #if evt.MVA1l2tau_weight>bdt and evt.tau_charge_0*evt.tau_charge_1<0:
        #if evt.Mybdtx>bdt and evt.tau_charge_0*evt.tau_charge_1<0 and evt.tau_passMuonOLR_0==1 and evt.tau_passMuonOLR_1==1:
        #weight=evt.mc_norm*evt.mcWeightOrg*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight
        #if evt.Mybdtx>bdt and evt.dilep_type>0 and evt.lep_ID_0*evt.lep_ID_1<0 and \
        #(abs(evt.lep_ID_0)==13 or (abs(evt.lep_ID_0)==11 and evt.lep_isTightLH_0)) and \
        #(abs(evt.lep_ID_1)==13 or (abs(evt.lep_ID_1)==11 and evt.lep_isTightLH_1)) and \
        #evt.lep_isolationFixedCutLoose_0 and evt.lep_isolationFixedCutLoose_1 and \
        #evt.nTaus_OR_Pt25==2 and evt.tau_JetBDTSigTight_0 and evt.tau_JetBDTSigTight_1 and \
        #evt.nJets_OR_T_MV2c10_70>=1 and evt.tau_charge_0*evt.tau_charge_1<0 and \
        #evt.nJets_OR_T>=2 and \
        #(evt.lep_isTrigMatch_0 or evt.lep_isTrigMatch_1 or evt.matchDLTll01) and \
        #evt.tau_passMuonOLR_0==1 and evt.tau_passEleBDT_0==1 and evt.tau_tagWeightBin_0 <4 and \
        #evt.tau_passMuonOLR_1==1 and evt.tau_passEleBDT_1==1 and evt.tau_tagWeightBin_1 <4:
        #   if evt.lep_ID_0*evt.lep_ID_1==-121 or evt.lep_ID_0*evt.lep_ID_1==-169:
        #      if evt.Mll01-91000>10000:
        #         passed += weight
        #   else: passed += weight 
        if evt.Mybdt>bdt and evt.TwoL2tauLooseMedium : passed += evt.weight
    return passed

bdts=(-1.0, -0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9)
points, points_errs=array('d'), array('d')
sigs, errs=array('d'), array('d')
for bdt in bdts:
    s=scan("tth",bdt)
    b=0
    for bkg in bkgs:
      b += scan(bkg, bdt)
    Z0=medianZ(s, b)
    points.append(bdt)
    sigs.append(Z0)
    #errs.append(ERR)
    points_errs.append(0)
    print "%s %s %.2f  %.2f"  % (s, b, bdt, Z0)
SetAtlasStyle()
gROOT.SetBatch(True)
#gr=TGraphErrors(9, points, sigs, points_errs, errs)
gr=TGraph(20, points, sigs)
gr.GetXaxis().SetTitle("> BDT score")
gr.GetYaxis().SetTitle("Z0")
c=createCanvas()
gr.Draw("ALP")
gr.SetMaximum(2.0)
gr.SetLineColor(kBlue)
createLabels()
myText(0.60,0.85, kBlack,"t#bar{t}H vs. All bkg (MC)")
c.SaveAs("plots/bdt2l2tauLooseMedium_scan.pdf")
outfile=TFile("scanbdt2l2tauLooseMedium.root","update")
gr.Write()
outfile.Close()
