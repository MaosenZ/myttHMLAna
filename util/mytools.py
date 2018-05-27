import ROOT
from ROOT import TFile, TH1
import math
from math import sqrt,log

def calentries(hist):
    total=0
    Nbins=hist.GetNbinsX()
    for idx in range(Nbins+2):
        total += hist.GetBinContent(idx)
    return total

def medianZ(s,b):
    '''calculate meidan Z0 for discovery'''
    return sqrt(2*((s+b)*log((s+b)/b)-s))
