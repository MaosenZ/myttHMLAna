import ROOT
from ROOT import TFile, TCanvas, TH2, TH1D, TLine, TLegend, TPad, TGaxis
from array import array
from ROOT import kBlack, kRed, kGreen, kBlue, kFALSE
from ROOT import gPad, gStyle, gROOT

gROOT.Reset()
gROOT.LoadMacro("/Users/mason/Desktop/myWork/PlotUtils/AtlasStyle.C")
gROOT.LoadMacro("/Users/mason/Desktop/myWork/PlotUtils/AtlasUtils.C")
from ROOT import SetAtlasStyle, ATLAS_LABEL, myText 
SetAtlasStyle()

#open QmsID file, retrieve QmisID values
def getQmisID(sample):
  inputfile="QmisID_tight_%s.root" % sample
  f=TFile(inputfile)
  if sample == "truth":
    hist_QmisID=f.Get("Rates_Truth")
  else :
    hist_QmisID=f.Get("hist_QmisID")
  hist_QmisID.SetDirectory(0)
  return hist_QmisID

def createHists(sample):
  #avoid memory leak warnings
  #delete gROOT.FindObject("hist_pt_10_60");
  #get QmisID hists
  hist_QmisID=getQmisID(sample) 
  #book hists
  eta_bins=(0,0.6,1.1,1.37,1.52,2.0,2.47)
  hist_pt_10_60=TH1D("hist_pt_10_60","h1",6,array('d',eta_bins))
  hist_pt_60_90=TH1D("hist_pt_60_90","h2",6,array('d',eta_bins))
  hist_pt_90_130=TH1D("hist_pt_90_130","h3",6,array('d',eta_bins))
  hist_pt_130_1000=TH1D("hist_pt_130_1000","h4",6,array('d',eta_bins))
  
  #get QmsID values
  for index in range(6):
      if index==3 :
          continue #crack region
      hist_pt_10_60.SetBinContent(index+1,hist_QmisID.GetBinContent(index+1,1))
      hist_pt_10_60.SetBinError(index+1,hist_QmisID.GetBinError(index+1,1))
  
      hist_pt_60_90.SetBinContent(index+1,hist_QmisID.GetBinContent(index+1,2))
      hist_pt_60_90.SetBinError(index+1,hist_QmisID.GetBinError(index+1,2))
  
      hist_pt_90_130.SetBinContent(index+1,hist_QmisID.GetBinContent(index+1,3))
      hist_pt_90_130.SetBinError(index+1,hist_QmisID.GetBinError(index+1,3))
  
      hist_pt_130_1000.SetBinContent(index+1,hist_QmisID.GetBinContent(index+1,4))
      hist_pt_130_1000.SetBinError(index+1,hist_QmisID.GetBinError(index+1,4))
  
  #set color
  hist_pt_10_60.SetLineColor(kBlack)
  hist_pt_60_90.SetLineColor(kRed)
  hist_pt_90_130.SetLineColor(kGreen)
  hist_pt_130_1000.SetLineColor(kBlue)
  #hist_pt_10_60.SetMarkerStyle(kBlack)
  #hist_pt_60_90.SetMarkerStyle(kRed)
  #hist_pt_90_130.SetMarkerStyle(kGreen)
  #hist_pt_130_1000.SetMarkerStyle(kBlue)
  hist_pt_10_60.SetMarkerColor(kBlack)
  hist_pt_60_90.SetMarkerColor(kRed)
  hist_pt_90_130.SetMarkerColor(kGreen)
  hist_pt_130_1000.SetMarkerColor(kBlue)
  if sample=="truth":
     hist_pt_10_60.SetLineStyle(2)
     hist_pt_60_90.SetLineStyle(2)
     hist_pt_90_130.SetLineStyle(2)
     hist_pt_130_1000.SetLineStyle(2)
  return hist_pt_10_60, hist_pt_60_90, hist_pt_90_130, hist_pt_130_1000

def createRatio(h1, h2):
  h3 = h1.Clone("h3")
  #h3.Sumw2()
  h3.SetStats(0)
  h3.Divide(h2)
  return h3

def createCanvasPads():
  c = TCanvas("c", "canvas", 900, 700)
  # Upper histogram plot is pad1
  pad1 = TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
  pad1.SetBottomMargin(0)  # joins upper and lower plot
  pad1.Draw()
  # Lower ratio plot is pad2
  c.cd()  # returns to main canvas before defining pad2
  pad2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
  pad2.SetTopMargin(0)  # joins upper and lower plot
  pad2.SetBottomMargin(0.3)
  pad2.Draw()
  return c, pad1, pad2

def createLabels(sample):
  ATLAS_LABEL(0.2,0.85,kBlack)
  if sample=="data":
     myText(0.35,0.85, kBlack,"Internal") 
     myText(0.20,0.75,kBlack,"#int Ldt = 36.1 fb^{-1}, #sqrt{s}=13 TeV")
  else:
     myText(0.30,0.85, kBlack,"Internal")
     myText(0.20,0.75, kBlack,"Z+jets Simulation")

def createLegends(sample,h1,h2,h3,h4):
  if sample=="data":
     leg=TLegend(0.65,0.75,0.92,0.90)
  if sample=="zjets":
     leg=TLegend(0.60,0.75,0.90,0.90)
     leg.SetHeader("Likelihood")
  if sample=="truth":
     leg=TLegend(0.60,0.55,0.90,0.72)
     leg.SetHeader("Truth-matching")
  leg.SetFillStyle(0)
  #leg.SetBorderSize(0)
  leg.SetTextFont(62)
  leg.SetTextSize(0.03)
  leg.AddEntry(h1,"p_{T} #in [10, 60] GeV ","l") 
  leg.AddEntry(h2,"p_{T} #in [60, 90] GeV ","l") 
  leg.AddEntry(h3,"p_{T} #in [90, 130] GeV ","l")
  leg.AddEntry(h4,"p_{T} #in [130, 1000] GeV ","l") 
  return leg
#QmisID plots for data
def dataplot():
  hist_pt_10_60, hist_pt_60_90, hist_pt_90_130, hist_pt_130_1000 = createHists("data")
  
  c_data=TCanvas("c_data","c_data",900,700)
  gPad.SetLogy()
  gStyle.SetOptStat(0)
  hist_pt_10_60.GetYaxis().SetTitle("#in_{mis-id}")
  hist_pt_10_60.GetXaxis().SetTitle("|#eta|")
  hist_pt_10_60.SetMinimum(1e-4)
  hist_pt_10_60.SetMaximum(1)

  hist_pt_10_60.Draw("e")
  hist_pt_60_90.Draw("e same")
  hist_pt_90_130.Draw("e same")
  hist_pt_130_1000.Draw("e same")
  createLabels("data")
  leg=createLegends("data",hist_pt_10_60,hist_pt_60_90,hist_pt_90_130,hist_pt_130_1000)
  leg.Draw("same")
  c_data.SaveAs("data_QmisID.pdf")

#Zjets, truth plot and ratio plot
def mcplot():
  hzjets1, hzjets2, hzjets3, hzjets4=createHists("Zjets")
  htruth1, htruth2, htruth3, htruth4=createHists("truth")
  hratio_pt_10_60=createRatio(hzjets1, htruth1)
  hratio_pt_60_90=createRatio(hzjets2, htruth2)
  hratio_pt_90_130=createRatio(hzjets3, htruth3)
  hratio_pt_130_1000=createRatio(hzjets4, htruth4)

  c, pad1, pad2= createCanvasPads()
  gStyle.SetOptStat(0)
  #draw QmisID values first
  pad1.cd()
  pad1.SetLogy()
  hzjets1.GetYaxis().SetTitle("#in_{mis-id}")
  hzjets1.SetMinimum(0.00002)
  hzjets1.SetMaximum(1)
  hzjets1.GetYaxis().SetTitleSize(0.05)
  hzjets1.GetYaxis().SetTitleOffset(0.9)
  hzjets1.Draw("e")
  hzjets2.Draw("e same")
  hzjets3.Draw("e same")
  hzjets4.Draw("e same")
  htruth1.Draw("e same")
  htruth2.Draw("e same")
  htruth3.Draw("e same")
  htruth4.Draw("e same")
  createLabels("zjets")
  leg1=createLegends("zjets",hzjets1,hzjets2,hzjets3,hzjets4)
  leg2=createLegends("truth",htruth1,htruth2,htruth3,htruth4)
  leg1.Draw("same")
  leg2.Draw("same")
  #draw ratio
  pad2.cd()
  #painful adjustment for axis, lables, titles, never friendly..
  hratio_pt_10_60.GetXaxis().SetTitle("|#eta|")
  hratio_pt_10_60.GetYaxis().SetTitle("Likelihood/Truth-matching")
  hratio_pt_10_60.GetYaxis().SetLabelSize(0.15)
  hratio_pt_10_60.GetYaxis().SetTitleSize(0.08)
  hratio_pt_10_60.GetXaxis().SetLabelSize(0.15)
  hratio_pt_10_60.GetXaxis().SetTitleSize(0.15)
  hratio_pt_10_60.GetXaxis().SetTitleOffset(1)
  hratio_pt_10_60.GetYaxis().SetTitleOffset(0.5)
  hratio_pt_10_60.GetYaxis().SetNdivisions(204)
  #set ranges, draw lines
  hratio_pt_10_60.SetMinimum(0)
  hratio_pt_10_60.SetMaximum(2.15)
  line1=TLine(0,0.5,2.47,0.5)
  line2=TLine(0,1.5,2.47,1.5)
  line3=TLine(0,1.0,2.47,1.0)
  hratio_pt_10_60.Draw("e")
  hratio_pt_60_90.Draw("e same")
  hratio_pt_90_130.Draw("e same")
  hratio_pt_130_1000.Draw("e same")
  line1.SetLineStyle(2)
  line2.SetLineStyle(2)
  line3.SetLineStyle(2)
  line1.Draw("same")
  line2.Draw("same")
  line3.Draw("same")
  c.SaveAs("mc_QmisID.pdf")
dataplot()
mcplot()
