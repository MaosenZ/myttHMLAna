#ifdef NTUPLE_cxx

/*
 *This macro used for H2TauhadTaulep, where >=1 bjets, >=5 jets (minimal requirements) are required.
 Oct 2, 2018
 */

void NTUPLE::makeVariables(float &top_mass1, float &top_mass2, float & mT_lepmet, float &m_blepmin, 
          float &dphi_ltaumet, float &wmass1,float &wmass2, float &pt_lepminustau, float &m_ltau, 
          float &m_ltaumet, float &pt_sum_all, float &pt_sum_nonbjets){
       //inits, just in case they won't be filled
       top_mass1=0;
       top_mass2=0;
       mT_lepmet=0;
       m_blepmin=0;
       dphi_ltaumet=0;
       wmass1=0;
       wmass2=0;
       pt_lepminustau=-100;
       m_ltau=0;
       m_ltaumet=0;
       //define vectors here
       vector <TLorentzVector> jet_vecs; //store all jets
       vector <TLorentzVector> bjet_vecs; //b jets
       vector <TLorentzVector> nonbjet_vecs; //non b-jets
       TLorentzVector met_vec; //MET vector
       TLorentzVector lep_vec; //leading lepton vector
       TLorentzVector tau_vec; //leading tau vector
       TLorentzVector tmp_vec; //tmp

       for(unsigned int i=0;i<m_jet_pt->size();i++){
           if( !((*m_jet_passOR)[i] && (*m_jet_passTauOR)[i]) ) continue;
           tmp_vec.SetPtEtaPhiE( (*m_jet_pt)[i], (*m_jet_eta)[i], (*m_jet_phi)[i], (*m_jet_E)[i]);
           if ((*m_jet_flavor_weight_MV2c10)[i]>0.83)  bjet_vecs.push_back(tmp_vec);
           else nonbjet_vecs.push_back(tmp_vec);
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
      
          //$$$$$$--------Top Mass--------$$$$$$$ 
          top_mass1=(bjet_vec1 + jet_vecs[1] + jet_vecs[2]).M();//jet_vecs[0] of course should be bjet_vec1
          TLorentzVector tmp_tmp_vec(0,0,0,0);
          for(unsigned int i=3; i<jet_vecs.size();i++)  tmp_tmp_vec += jet_vecs[i];
          top_mass2=tmp_tmp_vec.M();
          //$$$$$$-------transverse mass between met and leading lepton: mT_lepmet--------$$$$$$$
          met_vec.SetPtEtaPhiE(MET_RefFinal_et,0,MET_RefFinal_phi,0);
          lep_vec.SetPtEtaPhiE(lep_Pt_0, lep_Eta_0, lep_Phi_0, lep_E_0);
          mT_lepmet=(met_vec + lep_vec).Mt();
          //$$$$$$------minimal mass between lepton and bjet:m_blepmin-------$$$$$$$$$
          float tmp_mass(9999e3);
          for(unsigned int i=0;i<bjet_vecs.size();i++) {
              float tmp_tmp_mass=(lep_vec + bjet_vecs[i]).M();
              if (tmp_tmp_mass<tmp_mass) {
                  tmp_mass=tmp_tmp_mass;
                  m_blepmin=tmp_mass;
              }
          }
          //$$$$$$------dphi between ltau system and met: dphi_ltaumet-------$$$$$$$$
          tau_vec.SetPtEtaPhiE(tau_pt_0, tau_eta_0, tau_phi_0, tau_E_0);
          dphi_ltaumet=fabs(met_vec.DeltaPhi(lep_vec + tau_vec));
          //$$$$$$------W masses: wmass1, wmass2--------$$$$$$$$$
          //The idea is to pair two unbtagged jets to be W mass, and reconstruct the mass of the remaining jets
          if(nonbjet_vecs.size()>=2){
             vector<float> W1mass_vecs;
             vector<float> W2mass_vecs;
             for(unsigned int i=0; i<nonbjet_vecs.size()-1;i++){
                 for(unsigned int j=i+1; j<nonbjet_vecs.size();j++){
                     W1mass_vecs.push_back((nonbjet_vecs[i]+nonbjet_vecs[j]).M());
                     TLorentzVector tmpW2_vec(0,0,0,0);
                     for(unsigned int k=0;k<nonbjet_vecs.size();k++){
                          if(k!=i && k!=j) tmpW2_vec+=nonbjet_vecs[k];
                     }
                     W2mass_vecs.push_back(tmpW2_vec.M());
                 }//end of j loop
             }//end of i loop 
             //sort W mass vectors, mass small-->big
             float tmpW1mass, tmpW2mass;
             for(unsigned int i=0; i<W1mass_vecs.size()-1; i++) {
                 for(unsigned int j=0; j<W1mass_vecs.size()-1-i; j++){
                     if(fabs(W1mass_vecs[j]-80385)>fabs(W1mass_vecs[j+1]-80385)){
                        tmpW1mass=W1mass_vecs[j]; tmpW2mass=W2mass_vecs[j];
                        W1mass_vecs[j]=W1mass_vecs[j+1]; W2mass_vecs[j]=W2mass_vecs[j+1];
                        W1mass_vecs[j+1]=tmpW1mass; W2mass_vecs[j+1]=tmpW2mass;
                     }
                 }
             }
             wmass1=W1mass_vecs[0]; wmass2=W2mass_vecs[0];    
          }//end of >2 non-btagged jets
          //$$$$$$$----------lepton pt minus tau pt: pt_lepminustau--------------$$$$$$$$$$
          pt_lepminustau=lep_Pt_0-tau_pt_0;
          //$$$$$$$----------invariant mass of lepton, met and tauhad: m_ltau, m_ltaumet-------$$$$$$$$$
          m_ltau=(lep_vec + tau_vec).M();
          m_ltaumet=(lep_vec + tau_vec + met_vec).M();
          //$$$$$$$----------Scalar sum of objects: pt_sum_all, pt_sum_nonbjets----------$$$$$$$$
          float jet_pt_sum(0);
          for(unsigned int i=0; i<jet_vecs.size(); i++){
              jet_pt_sum +=(jet_vecs[i]).Pt();
          }
          pt_sum_all=tau_vec.Pt()+lep_vec.Pt()+jet_pt_sum+met_vec.Pt();
          for(unsigned int i=0;i<nonbjet_vecs.size();i++) pt_sum_nonbjets += (nonbjet_vecs[i]).Pt();
       }//end of #jet selection 
     
}
#endif
