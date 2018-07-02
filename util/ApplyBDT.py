import ROOT
from ROOT import gSystem
gSystem.Load('Root/NTUPLE_cxx')
from ROOT import NTUPLE, TFile, TTree

#samps=('tth','diboson','rare','ttV')
samps=("tth",)

for samp in samps:
    
    ntuple=NTUPLE(samp)
    outfile=TFile("/Users/mason/Desktop/myWork/ttHMLSamps/v6_02/nominal/%s_bdt.root" % samp,"recreate")
    tree=TTree("nominal","nominal")
    ntuple.applyBDT(tree)
    tree.Write()
    outfile.Close()
