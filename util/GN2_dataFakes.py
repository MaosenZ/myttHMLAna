#!/usr/bin/env python

""" Plot_dataMC.py: make data/mc comparison plot """

__author__     = "Maosen Zhou"
__email__      = "maosen.zhou@cern.ch"
__maintainer__ = "Maosen Zhou"

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

#define plot titles here
titles={'lep_Pt_0':('p^{T}_{l1} [GeV]', 'Events'), \
        'tau_pt_0':('p^{T}_{#tau_{1}} [GeV]', 'Events'), \
        'tau_pt_1':('p^{T}_{#tau_{2}} [GeV]', 'Events'), \
        'MVA1l2tau_weight':('BDT score', 'Events'), \
        'nJets_OR_T':('nJets_OR_T', 'Events'), \
        'nJets_OR_T_MV2c10_70':('nJets_OR_T_MV2c10_70', 'Events'), \
        'HT_jets':('HT_jets [GeV]', 'Events'), \
        'jjdrmin_1l2tau':('#Delta R_{min}(jj)', 'Events'), \
        'mtautau_1l2tau':('#M(#tau_{had}#tau_{had})', 'Events'), \
        'njets_1l2tau':('njets_1l2tau', 'Events'), \
        'nbjets_1l2tau':('nbjets_1l2tau', 'Events'), \
        'htjets_1l2tau':('htjets_1l2tau', 'Events'), \
        'tau_BDTJetScore_0':('#tau_{1} BDTJetScore', 'Events'), \
        'tau_BDTJetScore_1':('#tau_{2} BDTJetScore', 'Events'), \
        'tau_tight_0':('tau_tight_0', 'Events'), \
        'tau_tight_1':('tau_tight_1', 'Events'), \
        'tau_truthType_0':('tau_truthType_0','Events'),\
        'tau_truthType_1':('tau_truthType_1','Events'),\
        'tau_truthOrigin_1':('tau_truthOrigin_1','Events'),\
        'tau_truthOrigin_0':('tau_truthOrigin_0','Events'),\
         }

import ROOT, mytools
from ROOT import TFile, TH1, THStack, kBlack, kDashed, kRed
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import os, math
from math import sqrt, isnan, fabs
#from mytools import calentries, createCanvasPads, makeStack, createLabels 
from mytools import *

SetAtlasStyle()

def getVars():
    """ Get processed regions from hists produced """
    f=TFile("hists/%s.root" % inputsamples[0])
    keys=[name.GetName() for name in f.GetListOfKeys()]
    #first get all the region and var names of hists
    dupvars=[]
    for key in keys:
      pos=key.find('_')
      dupvars.append(key[pos+1:len(key)]) #hist name is regionname_var_vartype
    #strip out the repeated var names
    varnames=[]
    for x in dupvars:
      if x not in varnames:
         varnames.append(x)
    return varnames

variables=getVars()

def getHists(samp,region):
    '''get all hists in one region of stored sample'''
    fdata=TFile("hists/%s.root" %samp)
    variables=getVars()
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
        if N_bkg != 0:
           ratio=N_data/N_bkg
           ratio_err=err_data/N_bkg
           if N_data > max(N_bkg*2, 0) : upArrowBins.append(ibin+1)
        else :
           if N_data >= 1 : #
              ratio=N_data+1
              ratio_err=err_data
              if fabs(err_data-N_data)>=1 : upArrowBins.append(ibin+1)
        h_ratio.SetBinContent(ibin+1, ratio)
        h_ratio.SetBinError(ibin+1, ratio_err)
    return h_bkg, h_ratio, h_ratio_err, upArrowBins

def draw():
      os.mkdir("plots/lowBDTOSFakes")
      hists_data=getHists("data","1l2taulowBDTOS")
      hists_signal=getHists("tth","1l2taulowBDTOS")
      for idy in range(len(variables)):
          variable=variables[idy]
          hist_data=hists_data[idy]
          hist_signal=hists_signal[idy]
          mchists=[]
          temps=[]
          for i in range(len(bkgs)):
              if bkgs[i]=='fakes' : temps=getHists(bkgs[i],"1l2taulowBDTSS")
              else: temps=getHists(bkgs[i],"1l2taulowBDTOStruth")
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
          hist_signal.Scale(calentries(hist_data)/calentries(hist_signal)) #scale to data
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
