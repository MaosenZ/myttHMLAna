import ROOT
from ROOT import TFile, TH1, THStack, kDashed, TH1F
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
from ROOT import kBlue, kBlack, kRed
import math, os
from math import sqrt,log

gROOT.LoadMacro("/Users/mason/Desktop/myWork/myttHMLAna/inc/AtlasStyle.C")
gROOT.LoadMacro("/Users/mason/Desktop/myWork/myttHMLAna/inc/AtlasUtils.C")

from ROOT import SetAtlasStyle, ATLAS_LABEL, myText

def calentries(hist):
    total=0
    err2=0
    Nbins=hist.GetNbinsX()
    for idx in range(Nbins+2):
        total += hist.GetBinContent(idx)
        err2 += pow(hist.GetBinError(idx),2)
    #total += hist.GetBinContent(4)
    #err2 += pow(hist.GetBinError(4),2)
    return total, sqrt(err2)

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
  c = TCanvas("c", "canvas", 600, 600)
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

def createCanvas():
  c = TCanvas("c", "canvas", 800, 600)
  return c

def createLabels():
  ATLAS_LABEL(0.2,0.85,kBlack)
  myText(0.40,0.85, kBlack,"Internal")
  myText(0.20,0.75,kBlack,"#int Ldt = 80 fb^{-1}, #sqrt{s}=13 TeV")

def getRegionsVars(samp):
    """ Get processed regions from hists produced """
    f=TFile("hists/%s.root" % samp)
    keys=[name.GetName() for name in f.GetListOfKeys()]
    #first get all the region and var names of hists
    dupregions=[]
    dupvars=[]
    for key in keys:
      pos=key.find('_')
      dupregions.append(key[0:pos])
      dupvars.append(key[pos+1:len(key)]) #hist name is regionname_var_vartype
    #strip out the repeated region names
    regions=[]
    for x in dupregions:
      if x not in regions:
         regions.append(x)
    #strip out the repeated var names
    varnames=[]
    for x in dupvars:
      if x not in varnames and x != 'minitree':
         varnames.append(x)
    return regions, varnames
