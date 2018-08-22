import ROOT, mytools
from ROOT import TGraph, kRed, kBlack, TMultiGraph
from mytools import *

f_bdt=TFile("scanoldbdt.root")
f_bdtx=TFile("scanbdtx.root")

gr_bdt=f_bdt.Get("Graph")
gr_bdtx=f_bdtx.Get("Graph")

SetAtlasStyle()
gROOT.SetBatch(True)

c=createCanvas()
gr_bdt.SetLineColor(kBlue)
gr_bdtx.SetLineColor(kRed)
mg=TMultiGraph()
mg.Add(gr_bdt)
mg.Add(gr_bdtx)
mg.SetMaximum(2.0)
mg.Draw("ALP")
leg=TLegend(0.70,0.60,0.95,0.75)
leg.SetFillStyle(0);
leg.SetBorderSize(0);
leg.AddEntry(gr_bdt, "Old-BDT", "l")
leg.AddEntry(gr_bdtx, "Cross-trained", "l")
leg.Draw("same")
mg.GetXaxis().SetTitle("> BDT score")
mg.GetYaxis().SetTitle("Z0")
createLabels()
myText(0.60,0.85, kBlack,"t#bar{t}H vs. All bkg (MC)")
c.SaveAs("plots/bdtvsbdtx.pdf")
