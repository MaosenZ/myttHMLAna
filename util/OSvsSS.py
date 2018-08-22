import mytools, commonPlotting, array
from mytools import *
from commonPlotting import *
from array import array

extras=["ttbargamma",\
           "diboson",\
           "Vjets",\
           "ttV",\
           "rare"]

#Samp="ttbar"
Cates={"OS":"OneL2tauOSnoBDT", "SS":"OneL2tauSSnoBDT"}

SetAtlasStyle()

regions, variables=getRegionsVars('ttbar')

def getHists(Samp, variable):
    histfile=TFile("hists/%s.root" % Samp)
    h_SS=histfile.Get("%s_%s" % (Cates["SS"], variable))
    h_OS=histfile.Get("%s_%s" % (Cates["OS"], variable))
    xbins=array("d",[-1,0.,0.6,1.0])
    if variable=="Mybdt_F" or variable=="Mybdtx_F":
       h_SS_rebin=TH1F("h_SS_rebin","",3,xbins)
       h_OS_rebin=TH1F("h_OS_rebin","",3,xbins)
       rebinerror=0
       rebincontent=h_SS.IntegralAndError(1,5,rebinerror)
       h_SS_rebin.SetBinContent(1,rebincontent)
       h_SS_rebin.SetBinError(1, rebinerror)
       h_SS_rebin.SetBinContent(2, h_SS.IntegralAndError(6,8,rebinerror))
       h_SS_rebin.SetBinError(2, rebinerror)
       h_SS_rebin.SetBinContent(3, h_SS.IntegralAndError(9,10,rebinerror))
       h_SS_rebin.SetBinError(3, rebinerror)
       h_OS_rebin.SetBinContent(1,h_OS.IntegralAndError(1,5,rebinerror))
       h_OS_rebin.SetBinError(1, rebinerror)
       h_OS_rebin.SetBinContent(2, h_OS.IntegralAndError(6,8,rebinerror))
       h_OS_rebin.SetBinError(2, rebinerror)
       h_OS_rebin.SetBinContent(3, h_OS.IntegralAndError(9,10,rebinerror))
       h_OS_rebin.SetBinError(3, rebinerror)
       h_SS=h_SS_rebin
       h_OS=h_OS_rebin
    h_SS.SetDirectory(0)
    h_OS.SetDirectory(0)
    return h_SS, h_OS

gROOT.SetBatch(True)
#os.mkdir("plots/OSvsSS_%s" % Samp)
os.mkdir("plots/OSvsSS_all")

for variable in variables:
    h_SS, h_OS=getHists('ttbar', variable)
    for Samp in extras:
        temp_SS, temp_OS=getHists(Samp, variable)
        h_SS.Add(temp_SS,1)
        h_OS.Add(temp_OS,1)
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
    #c.SaveAs("plots/OSvsSS_%s/%s.pdf" %(Samp, variable)) 
    c.SaveAs("plots/OSvsSS_all/%s.pdf" % variable)
