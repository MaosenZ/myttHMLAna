#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "TH1F.h"

void initHists(std::map<string, std::unique_ptr<TH1F> > & TH1Fs, std::vector<string> regions,  const char * histspath){

   //read in defined hists
   std::ifstream inhists(histspath, ifstream::in);
   string line, var, name, vartype;
   int Nbins;
   float Xmin, Xmax;
   if(inhists.is_open()){
      while ( getline(inhists,line) ){
         if(line[0]=='#') continue;
         std::istringstream iss(line);
         //iss >> var >> Nbins >> Xmin >> Xmax >> vartype;
         //deal with varied bin width
         std::vector<string> tmp_strings;
         string tmp_string;
         while (iss >> tmp_string) tmp_strings.push_back(tmp_string); 
         var=tmp_strings[0];
         vartype=tmp_strings[tmp_strings.size()-1];
         Nbins=std::stoi(tmp_strings[1]);
         //deal with varied bin width
         bool isVariedBins=false;
           //can't interprete variable length
         float *bin_edges=new float[Nbins+1];
         if (tmp_strings.size()-3>2) {
             isVariedBins=true;
             for(unsigned int i=0; i< tmp_strings.size()-3;i++){
                 bin_edges[i]=std::stof(tmp_strings[i+2]);
             }
         }
         else {
            Xmin=std::stoi(tmp_strings[2]);
            Xmax=std::stoi(tmp_strings[3]);
         }
               
         //auto th1f=std::shared_ptr<TH1F>( new TH1F(var.c_str(),"",Nbins,Xmin,Xmax) );
         for(unsigned int i=0; i<regions.size();i++){
             name=regions[i]+"_"+var+"_"+vartype;
             //if (isVariedBins==true) TH1Fs[name]=new TH1F(name.c_str(),"", Nbins, bin_edges);
             //else TH1Fs[name]=new TH1F(name.c_str(),"",Nbins,Xmin,Xmax);
             if (isVariedBins==true) TH1Fs[name]=std::make_unique<TH1F> (name.c_str(),"", Nbins, bin_edges);
             else TH1Fs[name]=std::make_unique<TH1F> (name.c_str(),"",Nbins,Xmin,Xmax);
             //TH1Fs[var]=std::make_shared<TH1F>();
             TH1Fs[name]->Sumw2();
         }
         delete[] bin_edges;
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
    //weight, EventNumber, RunNumber
    tree->Branch("weight", &output_branches["weight"].d);
    tree->Branch("EventNumber", &output_branches["EventNumber"].i);
    tree->Branch("RunNumber", &output_branches["RunNumber"].i);
   //read in defined variables in hists
   std::ifstream inhists(histspath, ifstream::in);
   string line, var, name, vartype;
   //int Nbins;
   //float Xmin, Xmax;
   if(inhists.is_open()){
      while ( getline(inhists,line) ){
         if(line[0]=='#') continue;
         std::istringstream iss(line);
         std::vector<string> tmp_strings;
         string tmp_string;
         while (iss >> tmp_string) tmp_strings.push_back(tmp_string);
         var=tmp_strings[0];
         vartype=tmp_strings[tmp_strings.size()-1];
         if (vartype=="F") tree->Branch(var.c_str(), &output_branches[var].f);
         if (vartype=="I") tree->Branch(var.c_str(), &output_branches[var].i);
         if (vartype=="D") tree->Branch(var.c_str(), &output_branches[var].d);
         if (vartype=="B") tree->Branch(var.c_str(), &output_branches[var].c);
      }
      inhists.close();
   }
   else std::cout << "Unable to open "<< histspath << std::endl;  
}
