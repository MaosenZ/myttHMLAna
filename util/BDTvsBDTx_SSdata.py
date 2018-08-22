import ROOT, mytools
from ROOT import TGraph, kRed, kBlack, TMultiGraph, TH1F
from mytools import *

def getHist(samp):
    inputfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v7_01/all/%s_bdtx.root" %samp)
    tree=inputfile.Get("nominal")

    hist_oldbdt=TH1F("hist_oldbdt","",4,-1,1)
    hist_newbdt=TH1F("hist_newbdt","",4,-1,1)

    for evt in tree:
        lumi=1.0
        if evt.RunYear < 2016.5: lumi=36074.6
        if evt.RunYear > 2016.5: lumi=43813.7
        #weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*( 36074.6*(evt.RunYear < 2016.5) +  43813.7*(evt.RunYear > 2016.5) )
        if evt.nTaus_OR_Pt25<=0 : evt.tauSFTight=1.0
        weight=evt.scale_nom*evt.pileupEventWeight_090 *evt.JVT_EventWeight*evt.MV2c10_70_EventWeight*evt.SherpaNJetWeight*evt.lepSFObjLoose*evt.tauSFTight*lumi
        if evt.tau_charge_0*evt.tau_charge_1>0:
           hist_oldbdt.Fill(evt.MVA1l2tau_weight)
           hist_newbdt.Fill(evt.Mybdtx)
    hist_oldbdt.SetDirectory(0) 
    hist_newbdt.SetDirectory(0) 

    return hist_oldbdt, hist_newbdt

SetAtlasStyle()
gROOT.SetBatch(True)
hist_oldbdt, hist_newbdt=getHist("data")

c=createCanvas()
hist_oldbdt.SetLineColor(kBlue)
hist_newbdt.SetLineColor(kRed)
hist_oldbdt.Draw()
hist_newbdt.Draw("same")
hist_oldbdt.SetMaximum(60)
leg=TLegend(0.70,0.60,0.95,0.75)
leg.SetFillStyle(0);
leg.SetBorderSize(0);
leg.AddEntry(hist_oldbdt, "OldBDT", "l")
leg.AddEntry(hist_newbdt, "Cross-trained", "l")
leg.Draw("same")
hist_oldbdt.GetXaxis().SetTitle("BDT score")
hist_oldbdt.GetYaxis().SetTitle("Events")
createLabels()
myText(0.60,0.85, kBlack,"SS data")
c.SaveAs("plots/oldbdtvsbdtx_SSdata.pdf")
print hist_oldbdt.GetEntries()
print hist_newbdt.GetEntries()
