#ifdef QmisID_cxx
#ifndef internal_funcs
#define internal_funcs
#include "TMath.h"

void QmisID::FormulaUpdate(){
  if (fCurrent != fChain->GetTreeNumber()){
      fCurrent = fChain->GetTreeNumber();
      m_FitZSelectionsFormula->Notify();
      m_SelectionsFormula->Notify();
      m_Electron0TightFormula->Notify();
      m_Electron1TightFormula->Notify();
      m_Electron0AntiTightFormula->Notify();
      m_Electron1AntiTightFormula->Notify();
 }
}

bool QmisID::FitZEventSelections(){

  if(m_FitZSelectionsFormula->EvalInstance()) return true;

  return false;
}

bool QmisID::EventSelections(){

  if(m_SelectionsFormula->EvalInstance()) return true;

  return false;
}

//determine the electrons tight/anti-tight combination case
std::string QmisID::ElectronsCombIdx(){
 
 string idx="nn";//something wrong

 if(m_Electron0TightFormula->EvalInstance() && m_Electron1AntiTightFormula->EvalInstance() ) 
    idx="01";
 if(m_Electron0TightFormula->EvalInstance() && m_Electron1TightFormula->EvalInstance() )
    idx="00";
 if(m_Electron0AntiTightFormula->EvalInstance() && m_Electron1TightFormula->EvalInstance() )
    idx="10";
 if(m_Electron0AntiTightFormula->EvalInstance() && m_Electron1AntiTightFormula->EvalInstance() )
    idx="11";

  return idx;
}

//sort out each event's cell in the map
std::string QmisID::SortOutCell(string idx, Float_t eta0, Float_t pt0, Float_t eta1, Float_t pt1){

  std::string key="-1,-1,-1:-1,-1,-1";
  //encap pt overflow
  if (pt0 >= m_pt_edges[m_pt_edges.size()-1]) pt0=m_pt_edges[m_pt_edges.size()-1]*0.99;
  if (pt1 >= m_pt_edges[m_pt_edges.size()-1]) pt1=m_pt_edges[m_pt_edges.size()-1]*0.99;
  //interpret electronsCombIdx
  string el0idx(1, idx[0]) ;
  string el1idx(1, idx[1]) ;
  
  for(unsigned int a=0;a<m_eta_edges.size()-1; a++){
     for(unsigned int b=0;b<m_pt_edges.size()-1; b++){
         for(unsigned int p=0; p<m_eta_edges.size()-1; p++){
             for(unsigned int q=0; q<m_pt_edges.size()-1; q++){
                 if ( eta0>=m_eta_edges[a] && eta0<m_eta_edges[a+1] &&
                      pt0>=m_pt_edges[b] && pt0<m_pt_edges[b+1] &&
                      eta1>=m_eta_edges[p] && eta1<m_eta_edges[p+1] &&
                      pt1>=m_pt_edges[q] && pt1<m_pt_edges[q+1] ){
                      if (m_crack_idx_neg>=0 && m_crack_idx_pos>=0){//eta binnings are sysmmetric around 0
                          if(a<m_crack_idx_neg && p<m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a<m_crack_idx_neg && p>m_crack_idx_neg && p<m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                          if(a<m_crack_idx_neg && p>m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-2)+","+std::to_string(q);
                          if(a>m_crack_idx_neg && a<m_crack_idx_pos && p<m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a>m_crack_idx_neg && a<m_crack_idx_pos && p>m_crack_idx_neg && p<m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
		          if(a>m_crack_idx_neg && p>m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-2)+","+std::to_string(q);
		          if(a>m_crack_idx_pos && p<m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a-2)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
		          if(a>m_crack_idx_pos && p>m_crack_idx_neg && p<m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-2)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
		          if(a>m_crack_idx_pos && p>m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-2)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-2)+","+std::to_string(q);
                      }//end if crack region are sysmmetric around 0
                      if (m_crack_idx_neg>=0 && m_crack_idx_pos<0){//only consider negative eta
                          if(a<m_crack_idx_neg && p<m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a<m_crack_idx_neg && p>m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                          if(a>m_crack_idx_neg && p<m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a>m_crack_idx_neg && p>m_crack_idx_neg)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                      }//end if negative eta
                      if (m_crack_idx_neg<0 && m_crack_idx_pos>=0){//only consider positive eta
                          if(a<m_crack_idx_pos && p<m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a<m_crack_idx_pos && p>m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                          if(a>m_crack_idx_pos && p<m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                          if(a>m_crack_idx_pos && p>m_crack_idx_pos)
                             key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                      }//end if positive eta
                      if(m_crack_idx_neg<0 && m_crack_idx_pos<0) {
                          key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                      }//end if there is no crack region set in config
                 }//end of judge cell
             }//end of q
         }//end of p
     }//end of b
  }//end of a

  return key;
}
#endif
#endif

//Below are some external helper functions, which don't (directly) rely on QmisID class;
//But still use some variables (that will be assigned by QmisID init)declared in mySpace.
#ifndef external_funcs
#define external_funcs

void InterpString(string s, vector<float> & f){

  string delimiter=",";
  size_t pos=0;
  string token;
  while ( (pos=s.find(delimiter)) != string::npos){
          token=s.substr(0, pos);
          //cout<<token<<endl;
          f.push_back(std::stof(token));
          s.erase(0, pos+delimiter.length());
  }
  f.push_back(std::stof(s)); //last element
}

//eg, 0,1,1:1,0,1  --->id0,eta0,pt0:id1,eta1,pt1
void InterpString(string s, int &a, int & i , int &j, int & b, int &p, int &q){

  string delimiter=":";
  size_t pos=0;
  string s1, s2;
  while ( (pos=s.find(delimiter)) != string::npos){
          s1=s.substr(0, pos);
          s.erase(0, pos+delimiter.length());
  }
  s2=s; //last element

  vector<float>f1;
  vector<float>f2;
  InterpString(s1, f1);
  InterpString(s2, f2);
  a=f1[0];
  i=f1[1];
  j=f1[2];
  b=f2[0];
  p=f2[1];
  q=f2[2];
}

//locate the index of crack region
int LocateCrackIdx(string s, string target){
  int idx=-1;

  string delimiter=",";
  size_t pos=0;
  int index=0;
  string token;
  while ( (pos=s.find(delimiter)) != string::npos){
          token=s.substr(0, pos);
          if(token == target) idx=index;
          s.erase(0, pos+delimiter.length());
          index ++;
  }
  if (s==target) idx = index+1;
  return idx;
}

//creat a map based on electron_def, eta, pt binning for events, won't count crack region
std::map<string, double> CreateCellMap(int Nbins_ID, int Nbins_Eta_WOCRK, int Nbins_Pt){

  std::map<string, double> m;

  for (int i=0; i<Nbins_ID; i++){
       for(int a=0;a<Nbins_Eta_WOCRK; a++){
           for(int b=0;b<Nbins_Pt; b++){
               for(int j=0; j<Nbins_ID; j ++){
                   for(int p=0; p<Nbins_Eta_WOCRK; p++){
                       for(int q=0; q<Nbins_Pt; q++){
                           string key=std::to_string(i)+","+std::to_string(a)+","+std::to_string(b)+":"+
                                      std::to_string(j)+","+std::to_string(p)+","+std::to_string(q);
                           m[key]=0;
                       }//end of q
                   }//end of p
               }//end of j
           }//end of b
       }//end of a
  }//end of i

  return m;
}

//00, tight-tight; 11, antitight-antitight; 01, tight-antitight; 10, antitight-tight
bool passElectronsCase(string evt_type, int Case){

      bool pass=false;
      switch(Case){
         case 1:  //both tight
           { if (evt_type=="00") {pass=true; } }
           break;
         case 2: //both anti-tight
           { if (evt_type=="11") {pass=true; } }
           break;
         case 3: //one tight, one anti-tight
           { if (evt_type=="01" || evt_type=="10") { pass=true; } }
           break;
         case 4: //case 1 || case 3
           { if (evt_type=="00" || evt_type=="01" || evt_type=="10") {
                 pass=true;
             }
           }
           break;
         case 5: // case 1 || case 2 || case 3
           { if (evt_type=="00" || evt_type=="11" || evt_type=="01" || evt_type=="10") {
                 pass=true;
             }
           }
           break;
         default : { cout<<"Error: The ElectronsCase must be in {1..5} !"<<endl; return false; }
      }

      return pass;
}

//to read the sf stored in txt file
void ReadSFs(string type, float &sf){
 
  string inputsftxt=m_RunName+"/sf_";
  inputsftxt += type+".txt"; 
  ifstream sf_file(inputsftxt.c_str(),ifstream::in);
  string line;
  while(getline(sf_file,line)){
     const char* readline=line.c_str();
     sscanf(readline,"%f",&sf);
  }
}

//to read the SS/OS maps obtained in FillCellMap
void ReadCellMap(string type, std::map<string, double > &Counts){
 
  string inputmaptxt=m_RunName+"/yields_";
  inputmaptxt += type+".txt";
  ifstream map_file(inputmaptxt.c_str(),ifstream::in);
  string line;
  string key;
  double val;
  cout<<inputmaptxt.c_str()<<endl;
  while(getline(map_file,line)){
     size_t pos=line.find(" ");
     key=line.substr(0, pos);
     line.erase(0, pos+1);
     const char* readline=line.c_str();
     sscanf(readline,"%lf", &val);
     Counts[key]=val;
     cout<<key<<" "<<val<<endl;
  }

}
//construct the likelihood, notice this function must be called after CellMap are filled
void extern Likelihood(int & npar, double* gout, double & func, double *par, int flg){
  
  double likelihoods=0;
  float sf_os, sf_ss;
  //first read the scale factors obtained in previous step
  ReadSFs("OS",sf_os);
  ReadSFs("SS",sf_ss);

  //assign minimizer's parameters to actual rates pars
  double temp_par[nbins_id][nbins_eta_wocrk][nbins_pt];
  int index=0;
  for(int a=0;a<nbins_id; a++){
      for(int i=0;i<nbins_eta_wocrk;i++){
          for(int j=0;j<nbins_pt;j++){
              temp_par[a][i][j]=par[index];
              index++;
          }
      }
  }  
  //cout<<index<<endl;
  
  //sum over all cells
  std::map<string, double>::iterator it;
  for(it=SS_Counts.begin(); it!=SS_Counts.end(); ++it){
      string comb=it->first;

      if (comb == "-1,-1,-1:-1,-1,-1") continue;

      double N_cell=sf_ss*SS_Counts[comb] + sf_os*OS_Counts[comb];
      double N_ss=sf_ss*SS_Counts[comb];
      if (N_cell<=0 ) continue;
      //cout<<N_cell<<" "<<N_ss<<endl;
      //first interpret ij for each electron
      int a, i, j, b, p, q;
      InterpString(comb, a, i, j, b, p, q);
      likelihoods += TMath::Log(N_cell*(temp_par[a][i][j]+temp_par[b][p][q]))*N_ss-N_cell*(temp_par[a][i][j]+temp_par[b][p][q]);
  }

  func=-1*likelihoods;
  //cout<<"---------------------Constructed Likelihood-----------------------"<<endl;
  //cout<<"      "<<func<<endl; 
  //cout<<"------------------------------------------------------------------"<<endl;
}
#endif
