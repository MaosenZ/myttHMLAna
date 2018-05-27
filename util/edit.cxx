#include <iostream>
#include <fstream>

using namespace std;

void edit(){
  const char* input="myttHAna/NTUPLE.h";

  fstream infile(input);
  string line;
  int numline=1;
  TString infilename(input);
  while(getline(infile,line)){
     TString numlinestr;
     if(line[0]=='b'&& line[1]=='_') {
        numlinestr=gSystem->GetFromPipe("grep -n b_ "+infilename+" |head -1 |cut -d \":\" -f 1");
        gSystem->Exec("sed -i '"+numlinestr+"d' "+ infilename);
     }
  }

}
