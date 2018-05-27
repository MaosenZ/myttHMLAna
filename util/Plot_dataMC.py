#!/usr/bin/env python

""" Plot_dataMC.py: make data/mc comparison plot """

__author__     = "Maosen Zhou"
__email__      = "maosen.zhou@cern.ch"
__maintainer__ = "Maosen Zhou"

#input sample lists
#inputsamples=("data_combined_25ns_R21_data1516v5","data_combined_25ns_R21_data15v5","data_combined_25ns_R21_data16v1","data_combined_25ns_R21_data16v5","data_combined_25ns_R21_data17v1","data_combined_25ns_R21_data17v5","diboson_mc16av5","diboson_mc16cv5","mll10_40_mc16av5","mll10_40_mc16cv5","Others_mc16av5","Others_mc16cv5","ttbargamma_madpy8_mc16av5","ttbargamma_madpy8_mc16cv5","ttbarnohad_powhpy8_mc16av5","ttbarnohad_powhpy8_mc16cv5","ttbarnohad_powhpy8showerwt_mc16av5","ttbarnohad_powhpy8showerwt_mc16cv5","ttbarnohad_sherpa_mc16av5","ttbarnohad_sherpa_mc16cv5","tth_aMChpp_mc16av5","tth_aMChpp_mc16cv5","tth_aMCpy8_mc16av5","tth_aMCpy8_mc16cv5","tth_powhpy8_mc16av5","tth_powhpy8_mc16cv5","ttV_aMCpy8_mc16av5","ttV_aMCpy8_mc16cv5","ttV_sherpa_mc16av5","ttV_sherpa_mc16cv5","ttW_aMCpy8_mc16av5","ttZ_aMCpy8_mc16av5","ttZ_aMCpy8_mc16cv5","vjets_mc16av5","vjets_mc16cv5","wjets_mc16av5","wjets_mc16cv5","zjets_mc16av5","zjets_mc16cv5")
inputsamples=("data_combined_25ns_R21_data1516v5","data_combined_25ns_R21_data17v5","diboson_mc16av5","diboson_mc16cv5","Others_mc16av5","Others_mc16cv5","ttbargamma_madpy8_mc16av5","ttbargamma_madpy8_mc16cv5","ttbarnohad_powhpy8_mc16av5","ttbarnohad_powhpy8_mc16cv5","tth_aMChpp_mc16av5","tth_aMChpp_mc16cv5","tth_aMCpy8_mc16av5","tth_aMCpy8_mc16cv5","tth_powhpy8_mc16av5","tth_powhpy8_mc16cv5","ttV_aMCpy8_mc16av5","ttV_aMCpy8_mc16cv5","vjets_mc16av5","vjets_mc16cv5")

#processes=("data","diboson","mll10_40","Others","ttbargamma","ttbarnohad","tth","ttV","vjets")

#input sample lists that going to be plotted
processes={'data':("data_combined_25ns_R21_data1516v5","data_combined_25ns_R21_data17v5"),\
           'diboson':("diboson_mc16av5","diboson_mc16cv5"),\
           'Others':("Others_mc16av5","Others_mc16cv5"),\
           'ttbargamma':("ttbargamma_madpy8_mc16av5","ttbargamma_madpy8_mc16cv5"),\
           'ttbarnohad':("ttbarnohad_powhpy8_mc16av5","ttbarnohad_powhpy8_mc16cv5"),\
           'ttV':("ttV_aMCpy8_mc16av5","ttV_aMCpy8_mc16cv5"),\
           'vjets':("vjets_mc16av5","vjets_mc16cv5")}

#define plot titles here
titles={'lep_Pt_0':('p^{T}_{l1} [GeV]', 'Events'), \
        'tau_pt_0':('p^{T}_{#tau_{1}} [GeV]', 'Events'), \
        'tau_pt_1':('p^{T}_{#tau_{2}} [GeV]', 'Events'), \
        'tau_BDTJetScore_0':('#tau_{1} BDTJetScore', 'Events'), \
        'tau_BDTJetScore_1':('#tau_{2} BDTJetScore', 'Events')}

import ROOT
from ROOT import TFile, THStack, TH1, kBlack, kDashed
from ROOT import TCanvas, TPad, TLegend, TLine, TArrow
from ROOT import gROOT, gStyle
import os, math
from math import sqrt, isnan, fabs

gROOT.LoadMacro("/global/homes/m/mszhou/work/ttHML/myttHAna/util/AtlasStyle.C")
gROOT.LoadMacro("/global/homes/m/mszhou/work/ttHML/myttHAna/util/AtlasUtils.C")

from ROOT import SetAtlasStyle, ATLAS_LABEL, myText
SetAtlasStyle()

def getRegionsVars():
    """ Get processed regions from hists produced """
    f=TFile("hists/%s.root" % inputsamples[0])
    keys=[name.GetName() for name in f.GetListOfKeys()]
    #first get all the region and var names of hists
    dupregions=[]
    dupvars=[]
    for key in keys:
      pos=key.find('_')
      dupregions.append(key[0:pos])
      dupvars.append(key[pos+1:len(key)])
    #strip out the repeated region names
    regions=[]
    for x in dupregions:
      if x not in regions:
         regions.append(x)
    #strip out the repeated var names
    varnames=[]
    for x in dupvars:
      if x not in varnames:
         varnames.append(x)
    print 'Regions are processed: '
    for region in regions:
      print region
    print 'variables are filled: '
    for varname in varnames:
      print varname
    return regions, varnames

regions, variables=getRegionsVars()

def addHists(region, variable, components):
    """read the hists from the same sample and add them together"""
    #first get one hist
    fhistfile=TFile("hists/%s.root" % components[0])
    total_hist=fhistfile.Get("%s_%s" % (region, variable))
    total_hist.SetDirectory(0) #don't destroy histogram while closing root file
    #then add the rest
    index=0
    for compo in components:
      histfile=TFile("hists/%s.root" % compo)
      hist=histfile.Get("%s_%s" % (region, variable))
      hist.SetDirectory(0)
      if index != 0: total_hist.Add(hist)
      index += 1
    return total_hist

def allHists():
    """get ALL the hists produced (already summed for each sample)"""
    all_hists={}
    for region in regions:
      for variable in variables:
        for i in processes:
            all_hists[region+"_"+variable+"_"+i]=addHists(region, variable, processes[i])
    return all_hists

def setmyStyle(hist):
    """set style for hist"""
    hist.SetLineColor(kBlack)
    histname=hist.GetName()
    return hist

def makeStack(mchists):
    """make stack plot"""
    stack=THStack("hs","")
    index=kBlack+1
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

def makeRatio(hist_data, mchists, hs):
    h_bkg=hs.GetStack().Last().Clone("h_bkg") #uncertainty band on stack hist
    h_ratio=hist_data.Clone("h_ratio") #ratio points in lower pad
    h_ratio_err=hist_data.Clone("h_ratio_err") #uncertainty band in lower pad
    h_bkg.SetMarkerSize(0)
    h_bkg.SetFillStyle(3253)
    h_bkg.SetFillColor(13)
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
    hists=allHists()
    for region in regions:
      os.mkdir("plots/%s" % region)
      for variable in variables:
          hist_data=hists[region+"_"+variable+"_data"]
          mchists=[]
          for i in processes:
              if i != 'data' :
                  temp=hists[region+"_"+variable+"_"+i]
                  mchists.append(temp)
          hs=makeStack(mchists)
          h_bkg, h_ratio, h_ratio_err, upArrowBins= makeRatio(hist_data, mchists, hs)
          c, pad1, pad2=createCanvasPads()
          XTitle, YTitle=(titles[variable])[0], (titles[variable])[1]
          #stack plot
          pad1.cd()
          leg=TLegend(0.60,0.70,0.90,0.90)
          leg.SetNColumns(2)
          leg.SetFillStyle(0);
          leg.SetBorderSize(0);
          leg.AddEntry(hist_data, "data", "pe")
          for i in processes:
               if i != 'data' : leg.AddEntry(hists[region+"_"+variable+"_"+i], i, "f")
          leg.AddEntry(h_bkg,"uncertainty",'f')
          Ymaximum = 3.5*hist_data.GetBinContent(hist_data.GetMaximumBin())
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

          c.SaveAs("plots/%s/%s.pdf" %(region, variable))
draw()
