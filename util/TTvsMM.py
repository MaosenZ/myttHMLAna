import mytools, commonPlotting, array
from mytools import *
from commonPlotting import *
from array import array

extras=["data",]

#Samp="ttbar"
Cates={"TT":"OneL2tauLTTSS", "MM":"OneL2tauLMMSS"}

SetAtlasStyle()

regions, variables=getRegionsVars('data')
variables=("MVA1l2tau_weight_F",)

def getHists(Samp, variable):
    histfile=TFile("hists/%s.root" % Samp)
    h_TT=histfile.Get("%s_%s" % (Cates["TT"], variable))
    h_MM=histfile.Get("%s_%s" % (Cates["MM"], variable))
    h_TT.SetDirectory(0)
    h_MM.SetDirectory(0)
    return h_TT, h_MM

gROOT.SetBatch(True)
#os.mkdir("plots/MMvsTT_%s" % Samp)
os.mkdir("plots/MMvsTT_SSdata")

for variable in variables:
    h_TT, h_MM=getHists('data', variable)
    '''for Samp in extras:
        temp_TT, temp_MM=getHists(Samp, variable)
        h_TT.Add(temp_TT,1)
        h_MM.Add(temp_MM,1)'''
    c=createCanvas()
    XTitle, YTitle=(titles_norm[variable[0:len(variable)-2]])[0], (titles_norm[variable[0:len(variable)-2]])[1]
    Nbins=h_MM.GetNbinsX()
    Xmin=h_MM.GetBinLowEdge(1)
    Xmax=h_MM.GetBinLowEdge(h_MM.GetNbinsX())+h_MM.GetBinWidth(1)
    h_frame=TH1F("frame","",Nbins,Xmin,1)
    h_frame.SetMaximum(3*h_MM.GetBinContent(h_MM.GetMaximumBin())/h_MM.Integral())
    h_frame.GetYaxis().SetTitleSize(0.06)
    h_frame.GetYaxis().SetTitleOffset(1)
    h_frame.GetYaxis().SetTitle(YTitle)
    h_frame.GetXaxis().SetTitle(XTitle)
    h_frame.Draw()
    h_TT.SetLineColor(kBlue)
    h_MM.SetLineColor(kRed)
    h_TT.DrawNormalized("e same")
    #h_TT.SetMaximum(3*h_MM.GetBinContent(h_MM.GetMaximumBin()))
    h_MM.DrawNormalized("e same")
    leg=TLegend(0.70,0.70,0.95,0.90)
    leg.SetFillStyle(0);
    leg.SetBorderSize(0);
    leg.AddEntry(h_TT,"TT","l") 
    leg.AddEntry(h_MM,"MM","l")
    createLabels()
    leg.Draw("same")
    #c.SaveAs("plots/MMvsTT_%s/%s.pdf" %(Samp, variable)) 
    c.SaveAs("plots/MMvsTT_SSdata/%s.pdf" % variable)
