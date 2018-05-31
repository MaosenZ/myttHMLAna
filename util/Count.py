
bkgs=("ttbar","ttbargamma","diboson","Vjets","ttV","rare")
region='1l2tauLTM'
histname="%s_MVA1l2tau_weight_F" % region
print histname

import ROOT
from ROOT import TFile, TH1
from ROOT import gROOT
import mytools
from mytools import calentries, medianZ

def countbkgs():
    '''count all bkg entries'''
    total_bkg=0
    err2_bkg=0
    for bkg in bkgs:
        histfile=TFile("hists/%s.root" % bkg)
        hist=histfile.Get(histname)
        hist.SetDirectory(0)
        tmp_count, err_count=calentries(hist)
        total_bkg += tmp_count
        err2_bkg += pow(err_count, 2)
    return total_bkg, sqrt(err2_bkg)

sigfile=TFile("hists/tth.root")
hist_sig=sigfile.Get(histname)
hist_sig.SetDirectory(0)
count_sig, err_sig=calentries(hist_sig)

datafile=TFile("hists/data.root")
hist_data=datafile.Get(histname)
hist_data.SetDirectory(0)
count_data=calentries(hist_data)
count_bkg, err_bkg=countbkgs()
Z=medianZ(count_sig, count_bkg)

print "region           S               B               Z"
print "%s	    %.2f$\pm$%.2f      %.2f$\pm$%.2f   %.2f$\pm$%.2f	   %.2f" %(region, count_sig, err_sig, count_bkg,err_bkg, Z)
