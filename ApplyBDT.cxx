#include "Root/NTUPLE.cxx"

void ApplyBDT(){
//string samps[]={"tth","diboson","rare","ttV"};
string samps[]={"tth"};

for(int i=0;i<1;i++){
    
    NTUPLE *ntuple=new NTUPLE(samps[i]);
    TString path="/eos/atlas/user/m/mzhou/ttHMLSamps/v6_02/nominal/";
    path += samps[i]+"_bdt.root";
    TFile *outfile=new TFile(path,"recreate");
    TTree *tree=new TTree("nominal","nominal");
    ntuple->applyBDT(tree);
    tree->Write();
    outfile->Close();
}
}
