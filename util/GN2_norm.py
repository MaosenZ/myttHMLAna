#!/usr/bin/env python

""" Plot_dataMC.py: make data/mc comparison plot """

__author__     = "Maosen Zhou"
__email__      = "maosen.zhou@cern.ch"
__maintainer__ = "Maosen Zhou"

import ROOT, mytools, commonPlotting
from ROOT import TFile, THStack, TH1, kBlack, kDashed, kRed
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import os, math
from math import sqrt, isnan, fabs
from mytools import calentries, getRegionsVars, createCanvas, SetAtlasStyle, createLabels 
from commonPlotting import *

SetAtlasStyle()

regions, variables=getRegionsVars('ttbar')
region="OneL2tauSSnoBDT"

def addHists(region, variable, components):
    """read the hists from the same sample and add them together"""
    #first get one hist
    fhistfile=TFile("hists/%s.root" % components)
    print '%s_%s' % (region, variable)
    total_hist=fhistfile.Get("%s_%s" % (region, variable))
    total_hist.SetDirectory(0) #don't destroy histogram while closing root file
    return total_hist

def allHists():
    """get ALL the hists produced (already summed for each sample)"""
    all_hists={}
    for variable in variables:
      for i in processes:
          all_hists[region+"_"+variable+"_"+i]=addHists(region, variable, i)
    return all_hists

def makeStack(mchists):
    """make stack plot"""
    stack=THStack("hs","")
    index=3
    for hist in mchists:
         mchists[hist].SetLineColor(index)
         mchists[hist].SetFillColor(index)
         stack.Add(mchists[hist])
         index += 1
    return stack

def drawNorm():
    hists=allHists()
    os.mkdir("plots/%s_norm" % region)
    for variable in variables:
        hist_data=hists[region+"_"+variable+"_data"]
        hist_signal=hists[region+"_"+variable+"_tth"]
        mchists={}
        for i in processes:
            if i != 'data' and i != 'tth':
                temp=hists[region+"_"+variable+"_"+i]
                mchists[i]=temp
        hs=makeStack(mchists)
        h_bkg=hs.GetStack().Last().Clone("h_bkg")
        c=createCanvas()
        XTitle, YTitle=(titles[variable[0:len(variable)-2]])[0], (titles_norm[variable[0:len(variable)-2]])[1]
        leg=TLegend(0.60,0.70,0.90,0.90)
        leg.SetNColumns(2)
        leg.SetFillStyle(0);
        leg.SetBorderSize(0);
        leg.AddEntry(hist_data, "data", "pe")
        leg.AddEntry(hist_signal, "tth", "l")
        #normalize individual hist
        mchists_norm={}
        for i in mchists:
             mchists[i].Scale(1./h_bkg.Integral())
             mchists_norm[i]=mchists[i]
        hs_norm=makeStack(mchists_norm)
        for i in mchists:
             leg.AddEntry(mchists_norm[i], i, "f")
        leg.AddEntry(h_bkg,"uncertainty",'f')
        #draw
        hs_norm.SetTitle("")
        hs_norm.SetMaximum(3*hist_data.GetBinContent(hist_data.GetMaximumBin())/hist_data.Integral())
        hs_norm.Draw("hist") 
        hs_norm.GetYaxis().SetTitleSize(0.06)
        hs_norm.GetYaxis().SetTitleOffset(1)
        hs_norm.GetYaxis().SetTitle(YTitle)
        hs_norm.GetXaxis().SetTitle(XTitle)
        #hs_norm.GetXaxis().SetTitleSize(0.)
        #hs_norm.GetXaxis().SetLabelSize(0.)
        h_bkg.SetFillStyle(3253)
        h_bkg.SetFillColor(13)
        h_bkg.SetLineColor(13)
        h_bkg.DrawNormalized("E2 same")
        hist_data.SetMarkerStyle(20)
        hist_data.SetMarkerSize(0.8)
        #hist_data.SetLineColor(kBlack)
        hist_data.DrawNormalized("e x0 same")
        hist_signal.SetLineColor(kRed)
        hist_signal.SetLineStyle(kDashed)
        hist_signal.DrawNormalized("hist same")
        createLabels()
        leg.Draw("same")
        c.SaveAs("plots/%s_norm/%s.pdf" %(region, variable))

gROOT.SetBatch(True)
drawNorm()
