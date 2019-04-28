#ifndef mySpace_h
#define mySpace_h
#include <string>
#include <map>
#include <iostream>
#include <string>

namespace mySpace {
 
  float GeV(1000.);//just in case the input ntuples use MeV
  //maps for SS/OS events
  std::map<std::string, double> ss_counts;
  std::map<std::string, double> os_counts;  

  //nbins
  int nbins_eta_wocrk; //nbins after removing crack region(if there is)
  int nbins_eta;
  int nbins_pt;
  int nbins_id; //nbins of electron defitions, can be 1 or 2
}
#endif
