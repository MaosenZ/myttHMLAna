import ROOT
from ROOT import TFile, TH1, THStack, kBlack, kDashed, kRed
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import math
from math import sqrt,log

gROOT.LoadMacro("/Users/mason/Desktop/myWork/PlotUtils/AtlasStyle.C")
gROOT.LoadMacro("/Users/mason/Desktop/myWork/PlotUtils/AtlasUtils.C")

from ROOT import SetAtlasStyle, ATLAS_LABEL, myText

def calentries(hist):
    total=0
    Nbins=hist.GetNbinsX()
    for idx in range(Nbins+2):
        total += hist.GetBinContent(idx)
    return total

def medianZ(s,b):
    '''calculate meidan Z0 for discovery'''
    return sqrt(2*((s+b)*log((s+b)/b)-s))

##for plots
def makeStack(mchists):
    """make stack plot"""
    stack=THStack("hs","")
    index=3
    for hist in mchists:
         hist.SetLineColor(index)
         hist.SetFillColor(index)
         stack.Add(hist)
         index += 1
    return stack

def createCanvasPads():
  c = TCanvas("c", "canvas", 900, 700)
  # Upper histogram plot is pad1
  pad1 = TPad("pad1", "pad1", 0, 0.25, 1, 1.0)
  #pad1.SetBottomMargin(0)  # joins upper and lower plot
  pad1.Draw()
  # Lower ratio plot is pad2
  c.cd()  # returns to main canvas before defining pad2
  pad2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.35)
  #pad2.SetTopMargin(0)  # joins upper and lower plot
  pad2.SetBottomMargin(0.3)
  pad2.Draw()
  return c, pad1, pad2

def createLabels():
  ATLAS_LABEL(0.2,0.85,kBlack)
  myText(0.35,0.85, kBlack,"Internal")
  myText(0.20,0.75,kBlack,"#int Ldt = 80 fb^{-1}, #sqrt{s}=13 TeV")
