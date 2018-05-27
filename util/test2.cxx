#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void test2(){
   string prefix="/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21Skim/MytthAnaSkim_";
   string prepath="/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21Skim/";

   string inputlist=prefix+"data_combined_25ns_R21_data1516v5.list";
   ifstream inputfile;
   inputfile.open(inputlist.c_str());
   cout<<inputlist.c_str()<<endl;
   string line;
   if(inputfile.good()){
      cout<<"I'm here"<<endl;
   while (getline(inputfile, line)){
          TString ifile=prepath+line;
          cout<<ifile<<endl;
   }}

}
