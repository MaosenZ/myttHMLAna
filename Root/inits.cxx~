#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "TH1F.h"

void initHists(std::map<string, TH1F* > & TH1Fs, std::vector<string> regions,  const char * histspath){

   //read in defined hists
   std::ifstream inhists(histspath, ifstream::in);
   string line, var, name, vartype;
   int Nbins;
   float Xmin, Xmax;
   if(inhists.is_open()){
      while ( getline(inhists,line) ){
         if(line[0]=='#') continue;
         std::istringstream iss(line);
         iss >> var >> Nbins >> Xmin >> Xmax >> vartype;
         //auto th1f=std::shared_ptr<TH1F>( new TH1F(var.c_str(),"",Nbins,Xmin,Xmax) );
         for(unsigned int i=0; i<regions.size();i++){
             name=regions[i]+"_"+var+"_"+vartype;
             TH1Fs[name]=new TH1F(name.c_str(),"",Nbins,Xmin,Xmax);
             //TH1Fs[var]=std::make_shared<TH1F>();
             TH1Fs[name]->Sumw2();
         }
      }
      inhists.close();
   }
   else std::cout << "Unable to open "<< histspath << std::endl;
}

void initTree(TTree * tree, std::vector<string> regions, const char* histspath){
    //define region variables here
    for(unsigned int i=0; i<regions.size();i++){
      tree->Branch((regions[i]).c_str(), &output_branches[regions[i]].i);
    }
    //weight
    tree->Branch("weight", &output_branches["weight"].d);
   //read in defined variables in hists
   std::ifstream inhists(histspath, ifstream::in);
   string line, var, name, vartype;
   int Nbins;
   float Xmin, Xmax;
   if(inhists.is_open()){
      while ( getline(inhists,line) ){
         if(line[0]=='#') continue;
         std::istringstream iss(line);
         iss >> var >> Nbins >> Xmin >> Xmax >> vartype;
         if (vartype=="F") tree->Branch(var.c_str(), &output_branches[var].f);
         if (vartype=="I") tree->Branch(var.c_str(), &output_branches[var].i);
         if (vartype=="D") tree->Branch(var.c_str(), &output_branches[var].d);
         if (vartype=="B") tree->Branch(var.c_str(), &output_branches[var].c);
      }
      inhists.close();
   }
   else std::cout << "Unable to open "<< histspath << std::endl;  
}
