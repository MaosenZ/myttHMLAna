import mytools, commonPlotting
from mytools import *
from commonPlotting import *

Samp="ttbar"
Cates={"OS":"OneL2tauOSnoBDT", "SS":"OneL2tauSSnoBDT"}

SetAtlasStyle()

regions, variables=getRegionsVars('ttbar')

def getHists(Samp, variable):
    histfile=TFile("hists/%s.root" % Samp)
    h_SS=histfile.Get("%s_%s" % (Cates["SS"], variable))
    h_OS=histfile.Get("%s_%s" % (Cates["OS"], variable))
    h_SS.SetDirectory(0)
    h_OS.SetDirectory(0)
    return h_SS, h_OS

gROOT.SetBatch(True)
os.mkdir("plots/OSvsSS_%s" % Samp)

for variable in variables:
    h_SS, h_OS=getHists(Samp, variable)
    c=createCanvas()
    XTitle, YTitle=(titles_norm[variable[0:len(variable)-2]])[0], (titles_norm[variable[0:len(variable)-2]])[1]
    Nbins=h_OS.GetNbinsX()
    Xmin=h_OS.GetBinLowEdge(1)
    Xmax=h_OS.GetBinLowEdge(h_OS.GetNbinsX())+h_OS.GetBinWidth(1)
    h_frame=TH1F("frame","",Nbins,Xmin,Xmax)
    h_frame.SetMaximum(3*h_OS.GetBinContent(h_OS.GetMaximumBin())/h_OS.Integral())
    h_frame.GetYaxis().SetTitleSize(0.06)
    h_frame.GetYaxis().SetTitleOffset(1)
    h_frame.GetYaxis().SetTitle(YTitle)
    h_frame.GetXaxis().SetTitle(XTitle)
    h_frame.Draw()
    h_SS.SetLineColor(kBlue)
    h_OS.SetLineColor(kRed)
    h_SS.DrawNormalized("e same")
    #h_SS.SetMaximum(3*h_OS.GetBinContent(h_OS.GetMaximumBin()))
    h_OS.DrawNormalized("e same")
    leg=TLegend(0.70,0.70,0.95,0.90)
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    leg.AddEntry(h_SS,"SS","l") 
    leg.AddEntry(h_OS,"OS","l")
    createLabels()
    leg.Draw("same")
    c.SaveAs("plots/OSvsSS_%s/%s.pdf" %(Samp, variable)) 
