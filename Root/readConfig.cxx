#include<iostream>
#include<string>
#include <fstream>

using namespace std;

void readConfig(const char* inputfile, vector<string> & m_Algorithms, vector<string> & m_Regions, vector<string> & m_Samples, bool & m_commonSelections){ 

  ifstream ifile(inputfile, ifstream::in);
  string delimiter=" ";
  string line;
  vector<string> lines;
  while(getline(ifile, line)){
     if(line[0]=='#') continue;
     lines.push_back(line);
  }

  for(unsigned int i=0;i<lines.size();i++){
      size_t pos=0;
      string def, token;
      string thisline=lines[i];
      int index=0;
      cout<<lines[i]<<endl;
      while ( (pos=thisline.find(delimiter)) != string::npos){
          token=thisline.substr(0, pos);
          cout<<token<<endl;
          if(index==0) def=token;

          if(def=="Algorithms" && index > 0){
             m_Algorithms.push_back(token);
          }
  
          if(def=="Regions" && index > 0){
             m_Regions.push_back(token);
          }
 
          if(def=="Samples" && index > 0){
             m_Samples.push_back(token);
          }

          if(def=="commonSelections" && index > 0){
             if(token=="yes" || token=="true") m_commonSelections=true;
          }

          thisline.erase(0, pos+delimiter.length());
          index++;
      }
  }
  ifile.close();
}
