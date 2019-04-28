#include "src/QmisID.cxx"

int main(){
  
  TString ConfigFile="QmisID.config";
  gSystem->ExpandPathName(ConfigFile);

  QmisID qmisid;

  //qmisid.ReadFiles("mini.root","minitree");
  qmisid.ReadFiles("group.phys-higgs.16489726._000010.output.root","nominal");

  qmisid.Init(ConfigFile);

  qmisid.FillCells();

  //qmisid.Minimize();
  return 1;  
}
