#include "Root/NTUPLE.cxx"
#include "Root/readConfig.cxx"
#include "Root/inits.cxx"

int main(int argc, char** argv){
  
  const char *config=argv[1];

  readConfig(config, m_Algorithms, m_Regions, m_Samples, m_commonSelections);

  const char* histtxt="config/hists.def";
  for(unsigned int i=0;i<m_Samples.size();i++){

      cout<<"$$$$$$$$$$-------------------$$$$$$$$$$$$$$$"<<endl;
      cout<<"Begin processing "<<m_Samples[i]<<endl; 
      cout<<"$$$$$$$$$$-------------------$$$$$$$$$$$$$$$"<<endl;
      NTUPLE *ntuple=new NTUPLE(m_Samples[i]);

      map<string, TH1F*> TH1Fs;
      initHists(TH1Fs, m_Regions, histtxt);
     
      TTree *minitree=new TTree("minitree","minitree");
      initTree(minitree, m_Regions, histtxt);

      ntuple->fillHistsMiniTree(TH1Fs, minitree);
 
      TString outputname("hists/"); outputname += m_Samples[i]+".root";
      TFile *output=new TFile(outputname,"recreate");

      for(map<string, TH1F*>::iterator it=TH1Fs.begin(); it!=TH1Fs.end(); it++){
          string var=it->first;
          TH1Fs[var]->Write();
      }
      minitree->Write();

      cout<<"$$$$$$$$$$-------------------$$$$$$$$$$$$$$$"<<endl;
      cout<<"End processing "<<m_Samples[i]<<endl;
      cout<<"$$$$$$$$$$-------------------$$$$$$$$$$$$$$$"<<endl;
      output->Close();
      delete ntuple;
  }
  return 0;
}
