#!/usr/bin/env python

""" Plot_dataMC.py: make data/mc comparison plot """

__author__     = "Maosen Zhou"
__email__      = "maosen.zhou@cern.ch"
__maintainer__ = "Maosen Zhou"

import ROOT, mytools, commonPlotting
from ROOT import TFile, THStack, TH1, kBlack, kDashed, kRed, TGraphErrors, TH1F
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import os, math, array
from math import sqrt, isnan, fabs
from array import array
from mytools import getRegionsVars, createCanvasPads, createLabels, SetAtlasStyle, calentries
from commonPlotting import *

#if set true, data won't be plotted
DataIgnored=True
processes={'ttbar':"ttbar",\
           'ttbargamma':"ttbargamma",\
           'diboson':"diboson",\
           'tth':"tth",\
           'Vjets':"Vjets",\
           'ttV':"ttV",\
           'rare':"rare"}

isBlinded=True
regions, variables=getRegionsVars("tth")
#regions=("ttbarCR", "OneL2tauSR","OneL1tau2b", "OneL1tau1b") 
regions=("SS1Lep1Tau5j1b", "SS1Lep1Tau5j2b", "SS1Lep1Tau6j1b", "SS1Lep1Tau6j2b") 
#regions=("OneL1tau2b6jHiggsLTau", )
#variables=("mtautau_1l2tau_F",)

SetAtlasStyle()

def addHists(region, variable, components):
    """read the hists from the same sample and add them together"""
    #first get one hist
    fhistfile=TFile("hists/%s.root" % components)
    total_hist=fhistfile.Get("%s_%s" % (region, variable))
    total_hist.SetDirectory(0) #don't destroy histogram while closing root file
    return total_hist

def allHists():
    """get ALL the hists produced (already summed for each sample)"""
    all_hists={}
    for variable in variables:
      for i in processes:
          all_hists[region+"_"+variable+"_"+i]=addHists(region, variable, processes[i])
    return all_hists

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

def makeRatio(hist_data, mchists, hs):
    h_bkg=hs.GetStack().Last().Clone("h_bkg") #uncertainty band on stack hist
    h_ratio=hist_data.Clone("h_ratio") #ratio points in lower pad
    #h_ratio.Reset("ICES")
    h_ratio_err=hist_data.Clone("h_ratio_err") #uncertainty band in lower pad
    h_bkg.SetMarkerSize(0)
    h_bkg.SetFillStyle(3253)
    h_bkg.SetFillColor(13)
    h_bkg.SetLineColor(13)
    Nbins=hist_data.GetNbinsX()
    #h_ratio=TH1F("h_ratio","",Nbins,hist_data.GetXaxis().GetXmin(), hist_data.GetXaxis().GetXmax())
    upArrowBins=[]
    #x_ratio, y_ratio, ex_ratio, ey_ratio=array('d'), array('d'), array('d'), array('d') #x, y, ex, ey for ratio (data/bkg)
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
        #ratio, ratio_err=0.0, 0.0
        if N_bkg != 0.0:
           ratio=N_data/N_bkg
           ratio_err=err_data/N_bkg
           if N_data > max(N_bkg*2, 0.) and ratio-ratio_err>2: upArrowBins.append(ibin+1)
           h_ratio.SetBinContent(ibin+1, ratio)
           h_ratio.SetBinError(ibin+1, ratio_err)
        else:
           h_ratio.SetBinContent(ibin+1, N_data/0.0001)
           h_ratio.SetBinError(ibin+1, err_data/0.0001)
    #gr_ratio=TGraphErrors(Nbins,x_ratio,y_ratio,ex_ratio,ey_ratio)     
    return h_bkg, h_ratio, h_ratio_err, upArrowBins

def drawDataMC(region):
    hists=allHists()
    os.mkdir("plots/%s" % region)
    for variable in variables:
        mchists=[]
        for i in processes:
            if i != 'data' and i != 'tth':
                temp=hists[region+"_"+variable+"_"+i]
                mchists.append(temp)
        hs=makeStack(mchists)
        #retrieve data and signal
        hist_data=hs.GetStack().Last().Clone("hist_data")
        if DataIgnored == False : hist_data=hists[region+"_"+variable+"_data"]
        hist_signal=hists[region+"_"+variable+"_tth"]

        h_bkg, h_ratio, h_ratio_err, upArrowBins= makeRatio(hist_data, mchists, hs)
        print calentries(hist_signal), calentries(h_bkg)
        c, pad1, pad2=createCanvasPads()
        XTitle, YTitle=(titles[variable[0:len(variable)-2]])[0], (titles[variable[0:len(variable)-2]])[1]
        #stack plot
        pad1.cd()
        leg=TLegend(0.60,0.70,0.90,0.90)
        leg.SetNColumns(2)
        leg.SetFillStyle(0);
        leg.SetBorderSize(0);
        if DataIgnored == False : leg.AddEntry(hist_data, "data", "pe")
        leg.AddEntry(hist_signal, "tth", "l")
        for i in processes:
             if i != 'data' and i != 'tth': leg.AddEntry(hists[region+"_"+variable+"_"+i], i, "f")
        leg.AddEntry(h_bkg,"uncertainty",'f')
        Ymaximum = 3.*hist_data.GetBinContent(hist_data.GetMaximumBin())
        hs.SetMaximum(Ymaximum)
        hs.SetMinimum(0.00001)
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
        if region != 'OneL2tauSR' or isBlinded == False :
           if DataIgnored == False : hist_data.Draw("e x0 same")
        hist_signal.SetLineColor(kRed)
        hist_signal.SetLineStyle(kDashed)
        if hist_signal.Integral(0, hist_signal.GetNbinsX()+1) != 0:
           hist_signal.Scale(hist_data.Integral(0,hist_data.GetNbinsX()+1)/hist_signal.Integral(0, hist_signal.GetNbinsX()+1)) #scale to data
        hist_signal.Draw("hist same")
        createLabels()
        leg.Draw("same")
        #ratio plot
        pad2.cd()
        h_ratio_err.SetMinimum(0.000001)# also to avoid drawing markers for ratio with 0 contents (P doesn't work)
        h_ratio_err.SetMaximum(2.0)
        h_ratio_err.GetYaxis().SetTitle("Data/Bkg")
        h_ratio_err.GetYaxis().SetTitleSize(0.06)
        h_ratio_err.GetYaxis().SetTitleOffset(1)
        h_ratio_err.GetXaxis().SetTitle(XTitle)
        h_ratio_err.GetXaxis().SetLabelSize(0.14)
        h_ratio_err.GetXaxis().SetLabelOffset(0.025)
        h_ratio_err.GetXaxis().SetTitleSize(0.13)
        h_ratio_err.GetXaxis().SetTitleOffset(1.05)
        h_ratio_err.GetYaxis().SetLabelSize(0.1)
        h_ratio_err.GetYaxis().SetTitleSize(0.14)
        h_ratio_err.GetYaxis().SetTitleOffset(0.40)
        h_ratio_err.GetYaxis().SetNdivisions(505)
        h_ratio.SetMarkerStyle(20)
        h_ratio.SetMarkerSize(0.8)
        h_ratio_err.SetMarkerSize(0)
        h_ratio_err.SetFillColor(17)
        h_ratio_err.Draw("e2")
        if region != 'OneL2tauSR' or isBlinded == False :
           if DataIgnored == False : h_ratio.Draw("E0 P X0 SAME")
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

        c.SaveAs("plots/%s/%s.pdf" %(region, variable))

gROOT.SetBatch(True)
for region in regions:
  drawDataMC(region)
