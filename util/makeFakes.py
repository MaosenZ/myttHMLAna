import ROOT
from ROOT import TFile

#fakes = SS(data)-SS(real)+OS(real)
regions={'dataSS':'1l2tauSS','truthSS':'1l2tauSStruth','truthOS':'1l2tauSRtruth'}

bkgs=("ttbar","ttbargamma","diboson","Vjets","ttV","rare")

def getVars():
    """ Get and add all mc hists """
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

outfile=TFile("hists/fakes.root","recreate")

fdata=TFile("hists/data.root")
variables=getVars()
hists_dataSS=[]
for idx in variables
    hist_dataSS=fdata.Get("%s_%s" %(regions['dataSS'], idx))
    hists_dataSS.SetDirectory(0) 
    hists_dataSS.append(hist_dataSS)

for idx in bkgs:
    fhist=TFile("hists/%s.root" % bkgs[idx])
    
