import ROOT
from ROOT import TGraph, kRed, kBlack, TMultiGraph, TFile, TCanvas, TLegend, kBlue
from ROOT import gPad

f_mix=TFile("dataset_mix_allgen/BDTG_train.root")
f_wm=TFile("dataset_WM_allgen/BDTG_train.root")

gr_mix=f_mix.Get("dataset/Graph")
gr_wm=f_wm.Get("dataset/Graph")

#SetAtlasStyle()
#gROOT.SetBatch(True)

c=TCanvas("","",700,700)
gPad.SetLineWidth(2)
gr_wm.SetLineColor(kBlack)
gr_mix.SetLineColor(kBlue)
#mg=TMultiGraph()
#mg.Add(gr_mix)
#mg.Add(gr_wm)
#mg.SetMaximum(2.0)
#mg.Draw()
gr_wm.Draw()
gr_mix.Draw("same")
leg=TLegend(0.70,0.75,0.90,0.90)
leg.SetFillStyle(0);
leg.SetBorderSize(0);
leg.AddEntry(gr_mix, "w/ CMS vars", "l")
leg.AddEntry(gr_wm, "Current", "l")
leg.Draw("same")
c.SaveAs("comparison_eff_allgen.pdf")
#mg.GetXaxis().SetTitle("> BDT score")
#mg.GetYaxis().SetTitle("Z0")
