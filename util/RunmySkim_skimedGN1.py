#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists
#from ROOT import gSystem
#gSystem.Load("Root/mySkim_C")
#from ROOT import mySkim
import sys

samp=sys.argv[1]
prepath="/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV6/"
outpath="/global/homes/m/mszhou/work/ttHML/GN1Samps/dilep_looseleps/"

#samps=('tth','diboson','rare','ttV','ttbar')
#samps=("data",)
#trees=("nominal",)
trees=("nominal",)
Noexists=[]

def Skim(dsid, treename):
 
  #to see the file if exists
  if gSystem.AccessPathName("%s%s" % (prepath, dsid), kFileExists) == False:
  
     f1=TFile("%s%s" % (prepath, dsid))
     tree=f1.Get(treename)

     #skim here
     outputname="%s%s" % (outpath, dsid)
     f2=TFile("%s%s" % (outpath, dsid),"recreate")
     outtree = tree.CopyTree("passEventCleaning && (onelep_type||dilep_type||trilep_type||quadlep_type) && ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 ))||(RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))) && dilep_type>0 && nTaus_OR_Pt25==2") 
     outtree.Write()
     f2.Close()
  else:
     print "Error: %s does not exists" % dsid

for tree in trees:
    #for samp in samps:
        filename = "/global/homes/m/mszhou/work/ttHML/myttHMLAna/doc/%s.list" % samp
        with open(filename, "r") as myfile:
             dsids=myfile.read().splitlines()
             for dsid in dsids:
                 if dsid[0]=='#': continue
                 print 'Tree: %s, skimming (copying) %s of %s' % (tree, dsid, samp)
                 Skim(dsid, tree)
