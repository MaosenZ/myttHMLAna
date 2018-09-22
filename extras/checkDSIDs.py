#!/usr/bin/env python

import ROOT
from ROOT import TFile, TTree, gSystem, kFileExists
prepath="/eos/atlas/atlascerngroupdisk/phys-higgs/HSG8/multilepton_Run2_Summer18/GN2/v6_04/"

samps=('tth','diboson','rare','ttV','data','ttbar')
#samps=("tth",)
Noexists=[]

def isExist(dsid):

  #to see the file if exists
  exist=1
  if gSystem.AccessPathName("%s%s" % (prepath, dsid), kFileExists) == False:
     exist = 1
  else :
     exist = 0
  return exist

for samp in samps:
      filename = "doc/%s.list" % samp
      outfile=open("hadd_%s.sh" % samp, "w+")
      with open(filename, "r") as myfile:
           dsids=myfile.read().splitlines()
           for dsid in dsids:
               if isExist(dsid) == 0:
                  print "%s of %s doesn't exist" % (dsid, samp)
               if isExist(dsid) == 1:
                  outfile.write("%s \\\n" % dsid)
      outfile.close()
