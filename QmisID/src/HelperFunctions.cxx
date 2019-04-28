#ifdef QmisID_cxx
#include "TMath.h"

bool QmisID::EventSelections(){

  if (fCurrent != fChain->GetTreeNumber()){
      fCurrent = fChain->GetTreeNumber();
      m_SelectionsFormula->Notify();
  }

  if(m_SelectionsFormula->EvalInstance(0)) return true;

  return false;
}

//determine the electrons tight/anti-tight combination case
std::string QmisID::ElectronsCombIdx(){
 
 string idx="nn";//something wrong
 if (fCurrent != fChain->GetTreeNumber()){
      fCurrent = fChain->GetTreeNumber();
      m_Electron0TightFormula->Notify();
      m_Electron1TightFormula->Notify();
      m_Electron0AntiTightFormula->Notify();
      m_Electron1AntiTightFormula->Notify();
 }

 if(m_Electron0TightFormula->EvalInstance(0) && m_Electron1AntiTightFormula->EvalInstance(0) ) 
    idx="01";
 if(m_Electron0TightFormula->EvalInstance(0) && m_Electron1TightFormula->EvalInstance(0) )
    idx="00";
 if(m_Electron0AntiTightFormula->EvalInstance(0) && m_Electron1TightFormula->EvalInstance(0) )
    idx="10";
 if(m_Electron0AntiTightFormula->EvalInstance(0) && m_Electron1AntiTightFormula->EvalInstance(0) )
    idx="11";

  return idx;
}

//creat a map based on eta, pt binning for events, won't count crack region
std::map<string, double> QmisID::CreateCellMap(vector<float>eta_edges, vector<float>pt_edges){
 
  std::map<string, double> m;

  unsigned int Eta_edges_size;//nbins after removing crack region
  if(m_doAbsoluteEta) Eta_edges_size=m_crack_idx_pos?eta_edges.size()-1-1:eta_edges.size()-1;
  else Eta_edges_size=m_crack_idx_neg?eta_edges.size()-1-1-1:eta_edges.size()-1;

  for(unsigned int a=0;a<Eta_edges_size; a++){
     for(unsigned int b=0;b<pt_edges.size()-1; b++){
         for(unsigned int p=0; p<Eta_edges_size; p++){
             for(unsigned int q=0; q<pt_edges.size()-1; q++){
                 string key=std::to_string(a)+","+std::to_string(b)+":"+std::to_string(p)+","+std::to_string(q);
                 m[key]=0;
             }//end of q
         }//end of p
     }//end of b
  }//end of a

  return m;
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
                 if(m_doAbsoluteEta){
                    if ( fabs(eta0)>=m_eta_edges[a] && fabs(eta0)<m_eta_edges[a+1] &&
                         pt0>=m_pt_edges[b] && pt0<m_pt_edges[b+1] &&
                         fabs(eta1)>=m_eta_edges[p] && fabs(eta1)<m_eta_edges[p+1] &&
                         pt1>=m_pt_edges[q] && pt1<m_pt_edges[q+1] ){
                         if (m_crack_idx_pos>0){ 
                             if(a>m_crack_idx_pos && p<m_crack_idx_pos)
	                        key=el0idx+","+to_string(a-1)+","+to_string(b)+":"+el1idx+","+to_string(p)+","+to_string(q);
		             if(a>m_crack_idx_pos && p>m_crack_idx_pos)
              	                key=el0idx+","+std::to_string(a-1)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                             if(a<m_crack_idx_pos && p>m_crack_idx_pos)
                                key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p-1)+","+std::to_string(q);
                             if(a<m_crack_idx_pos && p<m_crack_idx_pos)
                                key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                         }//end if there is crack region set explicitly in config
                         else {
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                         }
                    }//
                 }//end of if doAbsoluteEta
                 else{
                    if ( eta0>=m_eta_edges[a] && eta0<m_eta_edges[a+1] &&
                         pt0>=m_pt_edges[b] && pt0<m_pt_edges[b+1] &&
                         eta1>=m_eta_edges[p] && eta1<m_eta_edges[p+1] &&
                         pt1>=m_pt_edges[q] && pt1<m_pt_edges[q+1] ){
                         if (m_crack_idx_neg>0){
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
                         }//end if there is crack region set explicitly in config
                         else {
                             key=el0idx+","+std::to_string(a)+","+std::to_string(b)+":"+el1idx+","+std::to_string(p)+","+std::to_string(q);
                         }
                    }//end of judge cell
                 }//end of not doAbsoluteEta
             }//end of q
         }//end of p
     }//end of b
  }//end of a

  return key;
}
#endif

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

//eg, 0,1,1:1,0,1  --->id,eta,pt:id,eta,pt
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

//construct the likelihood, notice this function must be called after CellMap are filled
void extern Likelihood(int & npar, double* gout, double & func, double *par, int flg){
  
  double likelihoods=0;
  double sf_os=0.957752, sf_ss=0.964547;
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
  for(it=ss_counts.begin(); it!=ss_counts.end(); ++it){
      string comb=it->first;

      //if (comb == "-1,-1:-1,-1") continue;

      double N_cell=sf_ss*ss_counts[comb] + sf_os*os_counts[comb];
      double N_ss=sf_ss*ss_counts[comb];
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
