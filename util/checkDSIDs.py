#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists
prepath="/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v6_02/"

samps=('tth','diboson','rare','ttV','data')
#samps=("tth",)
Noexists=[]

def isExist(dsid):

  #to see the file if exists
  if gSystem.AccessPathName("%s%s" % (prepath, dsid), kFileExists) == False:
     return 1
  else :
     return 0

for samp in samps:
      filename = "doc/%s.list" % samp
      with open(filename, "r") as myfile:
           dsids=myfile.read().splitlines()
           for dsid in dsids:
               if isExist(dsid) == 0:
                  print "%s of %s doesn't exist" % (dsid, samp)
