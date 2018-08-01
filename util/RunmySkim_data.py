#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists
#from ROOT import gSystem
#gSystem.Load("Root/mySkim_C")
#from ROOT import mySkim
import sys

samp=sys.argv[1]
prepath="/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v6_04/"
outpath="/eos/atlas/user/m/mzhou/ttHMLSamps/v6_04/"

#samps=('tth','diboson','rare','ttV','ttbar')
samps=("data",)
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
     f2=TFile("%s%s" % (outpath, dsid),"update")
     outtree = tree.CopyTree("passEventCleaning && (onelep_type||dilep_type||trilep_type||quadlep_type) && ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 ))||(RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))) && onelep_type>0 && ( abs(lep_ID_0)==13 ||((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 && nTaus_OR_Pt25==2 &&tau_tight_0 && tau_tight_1 && nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 && tau_tagWeightBin_1<4 && tau_tagWeightBin_0 <4") #skip MVA1l2tau_weight>0.5 tau_charge_0*tau_charge_1<0
     outtree.Write()
     f2.Close()
  else:
     print "Error: %s does not exists" % dsid

for tree in trees:
    #for samp in samps:
        filename = "/afs/cern.ch/user/m/mzhou/work/private/myttHAna/doc/%s.list" % samp
        with open(filename, "r") as myfile:
             dsids=myfile.read().splitlines()
             for dsid in dsids:
                 if dsid[0]=='#': continue
                 print 'Tree: %s, skimming (copying) %s of %s' % (tree, dsid, samp)
                 Skim(dsid, tree)
