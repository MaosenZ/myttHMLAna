import ROOT
from ROOT import gSystem
gSystem.Load('Root/NTUPLE_cxx')
from ROOT import NTUPLE

ntuple=NTUPLE('ttbar')

ntuple.cutFlow()
