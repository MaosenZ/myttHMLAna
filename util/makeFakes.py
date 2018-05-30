import ROOT
from ROOT import TFile, TH1
from ROOT import gROOT
import mytools
from mytools import calentries

#fakes = SS(data)-SS(real)+OS(real)
#regions={'SS':'1l2tauSS','truthSS':'1l2tauSStruth','truthOS':'1l2tauSRtruth','OS':'1l2tauSR'}
regions={'SS':'1l2taulowBDTSS','truthSS':'1l2taulowBDTSStruth','truthOS':'1l2taulowBDTOStruth','OS':'1l2taulowBDTOS'}

bkgs=("ttbar","ttbargamma","diboson","Vjets","ttV","rare")

def getVars():
    """ Get all variables in hists """
    f=TFile("hists/data.root")
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

print 'SSData     SSMC     SStruth      OSMC         OStruth		Exp.		OSData		Ratio'
print '%s         %s       %s           %s           %s                 %s              %s          %s' \
      %(calentries(histsSS_data[0]), calentries(histsSS_mc[0]), calentries(histsSS_truth[0]), \
      calentries(histsOS_mc[0]), calentries(histsOS_truth[0]), calentries(hists_fake[0])+calentries(histsOS_truth[0]), calentries(histsOS_data[0]), (calentries(hists_fake[0])+calentries(histsOS_truth[0]))/calentries(histsOS_data[0]))
