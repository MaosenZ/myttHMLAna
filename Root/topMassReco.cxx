#ifdef NTUPLE_cxx

void NTUPLE::topMassReco(float &top_mass1, float &top_mass2){

       top_mass1=0;
       top_mass2=0;

       vector <TLorentzVector> jet_vecs;
       vector <TLorentzVector> bjet_vecs;
       TLorentzVector tmp_vec;
       for(unsigned int i=0;i<m_jet_pt->size();i++){
           if( !((*m_jet_passOR)[i] && (*m_jet_passTauOR)[i]) ) continue;
           tmp_vec.SetPtEtaPhiE( (*m_jet_pt)[i], (*m_jet_eta)[i], (*m_jet_phi)[i], (*m_jet_E)[i]);
           if ((*m_jet_flavor_weight_MV2c10)[i]>0.83)  bjet_vecs.push_back(tmp_vec);
           jet_vecs.push_back(tmp_vec);
       }
       if(bjet_vecs.size()>=1 && jet_vecs.size()>=5) {
          //top1 mass is reconstructed by leading b jet and two closest jets (no matter b-tagged or not)
          //top2 mass is just the invariant mass of all the remaining jets.
          TLorentzVector bjet_vec1=bjet_vecs[0];
          //sort jets based on deltaR with bjet1, small->big
          for(unsigned int i=0; i<jet_vecs.size()-1; i++) {
              for(unsigned int j=0; j<jet_vecs.size()-1-i; j++){
                  if(bjet_vec1.DeltaR(jet_vecs[j]) > bjet_vec1.DeltaR(jet_vecs[j+1])) {
                     tmp_vec=jet_vecs[j];
                     jet_vecs[j]=jet_vecs[j+1];
                     jet_vecs[j+1]=tmp_vec;
                  }
              }//end of j
          }//end of i
          
          top_mass1=(bjet_vec1 + jet_vecs[1] + jet_vecs[2]).M();//jet_vecs[0] of course should be bjet_vec1
          //cout<<"Validation: "<<jet_vecs[3].M()<<endl;
          TLorentzVector tmp_tmp_vec(0,0,0,0);
          for(unsigned int i=3; i<jet_vecs.size();i++)  tmp_tmp_vec += jet_vecs[i];
          top_mass2=tmp_tmp_vec.M();
       }

}
#endif
