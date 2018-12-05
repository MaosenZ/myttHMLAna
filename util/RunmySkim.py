#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists
#from ROOT import gSystem
#gSystem.Load("Root/mySkim_C")
#from ROOT import mySkim
import sys

samp=sys.argv[1]
prepath="/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v8_02/"
outpath="/eos/atlas/user/m/mzhou/ttHMLSamps/v8_02/"

#samps=('tth','diboson','rare','ttV','ttbar')
#samps=('Vjets',"ttbar",'ttbargamma')
#trees=("nominal",)
trees=("nominal",\
 "EG_RESOLUTION_ALL__1down",\
 "EG_RESOLUTION_ALL__1up",\
 "EG_SCALE_AF2__1down",\
 "EG_SCALE_AF2__1up",\
 "EG_SCALE_ALL__1down",\
 "EG_SCALE_ALL__1up",\
 "JET_CategoryReduction_JET_BJES_Response__1down",\
 "JET_CategoryReduction_JET_BJES_Response__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Detector1__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Detector1__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed1__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed1__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed2__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed2__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed3__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Mixed3__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling1__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling1__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling2__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling2__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling3__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling3__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling4__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Modelling4__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical1__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical1__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical2__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical2__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical3__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical3__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical4__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical4__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical5__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical5__1up",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical6__1down",\
 "JET_CategoryReduction_JET_EffectiveNP_Statistical6__1up",\
 "JET_CategoryReduction_JET_EtaIntercalibration_Modelling__1down",\
 "JET_CategoryReduction_JET_EtaIntercalibration_Modelling__1up",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_highE__1down",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_highE__1up",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_negEta__1down",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_negEta__1up",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_posEta__1down",\
 "JET_CategoryReduction_JET_EtaIntercalibration_NonClosure_posEta__1up",\
 "JET_CategoryReduction_JET_EtaIntercalibration_TotalStat__1down",\
 "JET_CategoryReduction_JET_EtaIntercalibration_TotalStat__1up",\
 "JET_CategoryReduction_JET_Flavor_Composition__1down",\
 "JET_CategoryReduction_JET_Flavor_Composition__1up",\
 "JET_CategoryReduction_JET_Flavor_Response__1down",\
 "JET_CategoryReduction_JET_Flavor_Response__1up",\
 "JET_CategoryReduction_JET_Pileup_OffsetMu__1down",\
 "JET_CategoryReduction_JET_Pileup_OffsetMu__1up",\
 "JET_CategoryReduction_JET_Pileup_OffsetNPV__1down",\
 "JET_CategoryReduction_JET_Pileup_OffsetNPV__1up",\
 "JET_CategoryReduction_JET_Pileup_PtTerm__1down",\
 "JET_CategoryReduction_JET_Pileup_PtTerm__1up",\
 "JET_CategoryReduction_JET_Pileup_RhoTopology__1down",\
 "JET_CategoryReduction_JET_Pileup_RhoTopology__1up",\
 "JET_CategoryReduction_JET_PunchThrough_MC16__1down",\
 "JET_CategoryReduction_JET_PunchThrough_MC16__1up",\
 "JET_CategoryReduction_JET_SingleParticle_HighPt__1down",\
 "JET_CategoryReduction_JET_SingleParticle_HighPt__1up",\
 "JET_JER_SINGLE_NP__1up",\
 "MET_SoftTrk_ResoPara",\
 "MET_SoftTrk_ResoPerp",\
 "MET_SoftTrk_ScaleDown",\
 "MET_SoftTrk_ScaleUp",\
 "MUON_ID__1down",\
 "MUON_ID__1up",\
 "MUON_MS__1down",\
 "MUON_MS__1up",\
 "MUON_SAGITTA_RESBIAS__1down",\
 "MUON_SAGITTA_RESBIAS__1up",\
 "MUON_SAGITTA_RHO__1down",\
 "MUON_SAGITTA_RHO__1up",\
 "MUON_SCALE__1down",\
 "MUON_SCALE__1up",\
 "TAUS_TRUEHADTAU_SME_TES_DETECTOR__1down",\
 "TAUS_TRUEHADTAU_SME_TES_DETECTOR__1up",\
 "TAUS_TRUEHADTAU_SME_TES_INSITU__1down",\
 "TAUS_TRUEHADTAU_SME_TES_INSITU__1up",\
 "TAUS_TRUEHADTAU_SME_TES_MODEL__1down",\
 "TAUS_TRUEHADTAU_SME_TES_MODEL__1up")	
Noexists=[]

def Skim(dsid, treename):
 
  #to see the file if exists
  if gSystem.AccessPathName("%s%s" % (prepath, dsid), kFileExists) == False:
  
     f1=TFile("%s%s" % (prepath, dsid))
     tree=f1.Get(treename)

     #skim here
     outputname="%s%s" % (outpath, dsid)
     f2=TFile("%s%s" % (outpath, dsid),"update")
     outtree = tree.CopyTree("passEventCleaning && (onelep_type||dilep_type||trilep_type||quadlep_type) && ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 ))||(RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))) && onelep_type>0 && ( abs(lep_ID_0)==13 ||((abs(lep_ID_0)==11)&&lep_isTightLH_0)) &&lep_isTrigMatch_0 && lep_Pt_0>27e3 && lep_isolationFixedCutLoose_0 && nTaus_OR_Pt25==2 && nJets_OR_T>=3 && nJets_OR_T_MV2c10_70>=1 && tau_tagWeightBin_1<4 && tau_tagWeightBin_0 <4") #skip MVA1l2tau_weight>0.5 tau_charge_0*tau_charge_1<0 and tau_tight_0 && tau_tight_1
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
