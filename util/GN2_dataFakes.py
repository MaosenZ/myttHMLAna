#!/usr/bin/env python

""" Plot_dataFakes.py: make data/mc comparison plot including data-driven tau fakes"""
#input sample lists
inputsamples=("data","ttbar","ttbargamma","diboson","tth","Vjets","ttV","rare","fakes")
#input sample lists that going to be plotted
bkgs=["ttbar",\
           "ttbargamma",\
           "diboson",\
           "Vjets",\
           "ttV",\
           "rare",\
           "fakes"]

import ROOT, mytools, commonPlotting
from ROOT import TFile, TH1, THStack, kBlack, kDashed, kRed
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import os, math
from math import sqrt, isnan, fabs
from mytools import *
from commonPlotting import *

SetAtlasStyle()

#def getVars():
#    """ Get processed regions from hists produced """
#    f=TFile("hists/%s.root" % inputsamples[0])
#    keys=[name.GetName() for name in f.GetListOfKeys()]
#    #first get all the region and var names of hists
#    dupvars=[]
#    for key in keys:
#      pos=key.find('_')
#      dupvars.append(key[pos+1:len(key)]) #hist name is regionname_var_vartype
#    #strip out the repeated var names
#    varnames=[]
#    for x in dupvars:
#      if x not in varnames:
#         varnames.append(x)
#    return varnames

regions, variables=getRegionsVars("ttbar")

def getHists(samp,region):
    '''get all hists in one region of stored sample'''
    fdata=TFile("hists/%s.root" %samp)
    hists=[]
    for idx in variables:
        hist=fdata.Get("%s_%s" %(region, idx))
        hist.SetDirectory(0)
        hists.append(hist)
    return hists

def makeRatio(hist_data, mchists, hs):
    h_bkg=hs.GetStack().Last().Clone("h_bkg") #uncertainty band on stack hist
    h_ratio=hist_data.Clone("h_ratio") #ratio points in lower pad
    h_ratio_err=hist_data.Clone("h_ratio_err") #uncertainty band in lower pad
    #h_bkg.SetMarkerSize(0)
    h_bkg.SetFillStyle(3253)
    h_bkg.SetFillColor(13)
    h_bkg.SetLineColor(13)
    Nbins=hist_data.GetNbinsX()
    upArrowBins=[]
    for ibin in range(Nbins):
        N_data=hist_data.GetBinContent(ibin+1)
        err_data=hist_data.GetBinError(ibin+1)
        N_bkg=h_bkg.GetBinContent(ibin+1)
        err2_bkg=0
        for hist in mchists:
            err2_bkg += pow(hist.GetBinError(ibin+1), 2)
        err_bkg=sqrt(err2_bkg)
        if isnan(N_bkg) or N_bkg==0.0: 
           h_ratio_err.SetBinError(ibin+1, 0)
        else:
           h_ratio_err.SetBinError(ibin+1, err_bkg/N_bkg) 
        h_ratio_err.SetBinContent(ibin+1, 1.)
        h_bkg.SetBinError(ibin+1,err_bkg)
        ratio, ratio_err=0,0
        if N_bkg != 0.0:
           ratio=N_data/N_bkg
           ratio_err=err_data/N_bkg
           if N_data > max(N_bkg*2, 0.) and ratio-ratio_err>2: upArrowBins.append(ibin+1)
           h_ratio.SetBinContent(ibin+1, ratio)
           h_ratio.SetBinError(ibin+1, ratio_err)
        else:
           h_ratio.SetBinContent(ibin+1, N_data/0.0001)
           h_ratio.SetBinError(ibin+1, err_data/0.0001)
        h_ratio.SetBinContent(ibin+1, ratio)
        h_ratio.SetBinError(ibin+1, ratio_err)
    return h_bkg, h_ratio, h_ratio_err, upArrowBins

def draw():
      os.mkdir("plots/lowBDTOSFakes")
      hists_data=getHists("data","OneL2taulowBDTOS")
      hists_signal=getHists("tth","OneL2taulowBDTOS")
      for idy in range(len(variables)):
          variable=variables[idy]
          hist_data=hists_data[idy]
          hist_signal=hists_signal[idy]
          mchists=[]
          temps=[]
          for i in range(len(bkgs)):
              if bkgs[i]=='fakes' : temps=getHists(bkgs[i],"OneL2taulowBDTSS")
              else: temps=getHists(bkgs[i],"OneL2taulowBDTOStruth")
              mchists.append(temps[idy])
          hs=makeStack(mchists)
          h_bkg, h_ratio, h_ratio_err, upArrowBins= makeRatio(hist_data, mchists, hs)
          c, pad1, pad2=createCanvasPads()
          XTitle, YTitle=(titles[variable[0:len(variable)-2]])[0], (titles[variable[0:len(variable)-2]])[1]
          #stack plot
          pad1.cd()
          leg=TLegend(0.60,0.70,0.90,0.90)
          leg.SetNColumns(2)
          leg.SetFillStyle(0);
          leg.SetBorderSize(0);
          leg.AddEntry(hist_data, "data", "pe")
          leg.AddEntry(hist_signal, "tth", "l")
          for i in range(len(bkgs)):
              leg.AddEntry(mchists[i], bkgs[i], "f")
          leg.AddEntry(h_bkg,"uncertainty",'f')
          Ymaximum = 3.*hist_data.GetBinContent(hist_data.GetMaximumBin())
          hs.SetMaximum(Ymaximum)
          hs.SetMinimum(0.001)
          hs.SetTitle("")
          hs.Draw("hist") # thstack must draw first
          hs.GetYaxis().SetTitleSize(0.06)
          hs.GetYaxis().SetTitleOffset(1)
          hs.GetYaxis().SetTitle(YTitle)
          hs.GetXaxis().SetTitle("")
          hs.GetXaxis().SetTitleSize(0.)
          hs.GetXaxis().SetLabelSize(0.)
          h_bkg.Draw("E2 same")
          hist_data.SetMarkerStyle(20)
          hist_data.SetMarkerSize(0.8)
          hist_data.Draw("e x0 same")
          hist_signal.SetLineColor(kRed)
          hist_signal.SetLineStyle(kDashed)
          hist_signal.Scale(hist_data.Integral()/hist_signal.Integral()) #scale to data
          hist_signal.Draw("hist same")
          createLabels()
          leg.Draw("same")
          #ratio plot
          pad2.cd()
          h_ratio.SetMinimum(0.0)
          h_ratio.SetMaximum(2.0)
          h_ratio.GetYaxis().SetTitle("Data/Bkg")
          h_ratio.GetYaxis().SetTitleSize(0.06)
          h_ratio.GetYaxis().SetTitleOffset(1)
          h_ratio.GetXaxis().SetTitle(XTitle)
          h_ratio.GetXaxis().SetLabelSize(0.14)
          h_ratio.GetXaxis().SetLabelOffset(0.025)
          h_ratio.GetXaxis().SetTitleSize(0.13)
          h_ratio.GetXaxis().SetTitleOffset(1.05)
          h_ratio.GetYaxis().SetLabelSize(0.1)
          h_ratio.GetYaxis().SetTitleSize(0.14)
          h_ratio.GetYaxis().SetTitleOffset(0.40)
          h_ratio.GetYaxis().SetNdivisions(505)
          h_ratio.SetMarkerStyle(20)
          h_ratio.SetMarkerSize(0.8)
          h_ratio_err.SetMarkerSize(0)
          h_ratio_err.SetFillColor(17)
          h_ratio.Draw("e x0")
          h_ratio_err.Draw("e2 same")
          h_ratio.Draw("axis same")
          h_ratio.Draw("e x0 same")

          for iBin in upArrowBins :
            binCenter = h_ratio.GetBinCenter(iBin)
            a = TArrow(binCenter,1.7,binCenter,1.95,0.01,"|>")
            a.SetLineWidth(3)
            a.SetLineColor(2)
            a.SetFillColor(2)
            a.Draw()
  
          line=TLine()
          line.DrawLine(h_ratio.GetXaxis().GetXmin(),1.0,h_ratio.GetXaxis().GetXmax(),1.0)
          line.SetLineColor(kBlack)
          line.SetLineStyle(kDashed)
          line.DrawLine(h_ratio.GetXaxis().GetXmin(),0.5,h_ratio.GetXaxis().GetXmax(),0.5)
          line.DrawLine(h_ratio.GetXaxis().GetXmin(),1.5,h_ratio.GetXaxis().GetXmax(),1.5)

          c.SaveAs("plots/lowBDTOSFakes/%s.pdf" %variable)

gROOT.SetBatch(True)
draw()
