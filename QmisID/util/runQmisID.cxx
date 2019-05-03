#include "src/QmisID.cxx"
#include "src/FitZpeak.cxx"

static void usage(const string  &name) {

  cout << "Usage: " << name << " <option(s)>\n"
       << "Options:\n"
       << "\t--h  or --help   : help\n"
       << "\t--in             : input root file txt file\n"
       << "\t--conf           : path of configuration file\n"
       << "\t--sp             : step\n"
       << endl;
}

int main(int argc, char* argv[]){
 
  if(argc < 2) {
    cout << "At least 1 option needed. Type --h for help. Exiting!!" << endl;
    return 1 ;
  }

  string input;
  string sampleList = "";
  TString configFile;
  string step="";
  for(int i = 0; i < argc; ++i) {

    string arg = argv[i];

    if(arg == "--h") {
      usage( argv[0] );
      return 1;
    }
    else if(arg == "--in") {
      if(argc < 3) {
        cout << "--in requires one argument. Exiting!!" << endl;
        return 1;
      }
      input = argv[++i];
      if(input != "--h" && input != "--conf" && input != "--me" && input!= "--sp") sampleList = input;
    }
    else if(arg == "--conf") {
      if(argc < 5) {
        cout << "--conf requires one argument. Exiting!!" << endl;
        return 1;
      }
      input = argv[++i];
      if(input != "--h" && input != "--in" && input != "--me" && input!= "--sp") configFile = input;
    }
    else if(arg == "--sp") {
      if(argc < 7) {
        cout << "--sp requires one argument. Exiting!!" << endl;
        return 1;
      }
      input = argv[++i];
      if(input != "--h" && input != "--in" && input != "--me" && input != "--conf") step = input;
    }
  }

  if(sampleList == "") {
    cout << "No Input file list found. Exiting!!" << endl;
    return 1;
  }
  if(configFile == "") {
    cout << "No configuration file found. Exiting!!" << endl;
    return 1;
  }
  if(step == ""){
     cout << "No step set. Exiting!!"<<endl;
     return 1;
  } 
  //TString ConfigFile="config/QmisID.conf";
  gSystem->ExpandPathName(configFile);

  QmisID qmisid;

  qmisid.ReadFiles(sampleList,"nominal");

  qmisid.ReadConfig(configFile);

  if(step=="f") qmisid.FitZpeak();

  if(step=="w") qmisid.FillCells();

  if(step=="m") qmisid.Minimize();

  return 0;  
}
