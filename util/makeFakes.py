import ROOT
from ROOT import TFile, TH1
from ROOT import gROOT
import mytools
from mytools import *

#fakes = SS(data)-SS(real)+OS(real)
#regions={'SS':'OneL2tauSS','truthSS':'OneL2tauSStruth','truthOS':'OneL2tauSRtruth','OS':'OneL2tauSR'}
regions={'SS':'OneL2taulowBDTSS','truthSS':'OneL2taulowBDTSStruth','truthOS':'OneL2taulowBDTOStruth','OS':'OneL2taulowBDTOS'}

bkgs=("ttbar","ttbargamma","diboson","Vjets","ttV","rare")

another_regions, variables=getRegionsVars("ttbar")

def getHists(samp,region):
    '''get all hists in one region of stored sample'''
    fdata=TFile("hists/%s.root" %samp)
    hists=[]
    for idx in variables:
        hist=fdata.Get("%s_%s" %(region, idx))
        hist.SetDirectory(0)
        hists.append(hist)
    return hists

def sumMCHists(region):
    '''sum over the bkg hists'''
    allhists=[]
    for idx in bkgs:
        hists=getHists(idx, region)
        allhists.append(hists)
    sumhists=allhists[0] #initization
    for idx in range(len(allhists)):
        if idx==0 : continue
        for idy in range(len(allhists[idx])):
            sumhists[idy].Add(allhists[idx][idy])
    return sumhists

#save fakes to histograms
histsSS_data=getHists('data',regions['SS'])
histsSS_truth=sumMCHists(regions['truthSS'])
hists_fake=getHists('data',regions['SS'])
outfile=TFile("hists/fakes.root","recreate")
for idx in range(len(histsSS_data)):
    hists_fake[idx].Add(histsSS_truth[idx],-1.)
    hists_fake[idx].Write()
outfile.Close()

#print out
histsSS_mc=sumMCHists(regions['SS'])
histsOS_mc=sumMCHists(regions['OS'])
histsOS_truth=sumMCHists(regions['truthOS'])
histsOS_data=getHists('data',regions['OS'])

num_ssdata, err_ssdata=calentries(histsSS_data[0])
num_ssmc, err_ssmc=calentries(histsSS_mc[0])
num_sstruth, err_sstruth=calentries(histsSS_truth[0])
num_osdata, err_osdata=calentries(histsOS_data[0])
num_osmc, err_osmc=calentries(histsOS_mc[0])
num_fake, err_fake=calentries(hists_fake[0])
num_ostruth, err_ostruth=calentries(histsOS_truth[0])
num_exp=num_ssdata-num_sstruth+num_ostruth
err_exp=sqrt(pow(err_ssdata,2)+pow(err_sstruth,2)+pow(err_ostruth,2))
#num_ratio=num_osdata/num_exp
num_ratio=num_exp/num_osdata
err_ratio=num_ratio*sqrt(pow(err_exp/num_exp,2))

print '&SSData     &SSMC     &SStruth      &OSMC       &OStruth	     &Exp.	&OSData		&Ratio \\\\'
print '&%.2f$\pm$%.2f    &%.2f$\pm$%.2f    &%.2f$\pm$%.2f    &%.2f$\pm$%.2f     & %.2f$\pm$%.2f      &%.2f$\pm$%.2f      &%s         & %.2f$\pm$%.2f \\\\' \
       %(num_ssdata, err_ssdata, num_ssmc, err_ssmc, num_sstruth, err_sstruth, num_osmc, err_osmc, \
         num_ostruth, err_ostruth, num_exp, err_exp, num_osdata, num_ratio, err_ratio)

