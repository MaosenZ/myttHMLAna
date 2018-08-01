#include "Root/NTUPLE.cxx"

void ApplyBDT(){
string samps[]={"tth","diboson","rare","ttV"};
//string samps[]={"data","ttbar"};

for(unsigned int i=0;i<4;i++){
    std::cout<<samps[i]<<std::endl;
    NTUPLE *ntuple=new NTUPLE(samps[i]);

    //TString path="/Users/mason/Desktop/myWork/ttHMLSamps/v6_02/nominal/";
    //path += samps[i]+"_bdt.root";
    //TFile *outfile=new TFile(path,"recreate");
    //TTree *tree=new TTree("nominal","");
    
    ntuple->applyBDT();

    //tree->Write();
    //outfile->Close();
}
}
