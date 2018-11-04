#ifdef NTUPLE_cxx

/*
 *This macro used for ttH->2l2tau, where >=1 bjets (minimal requirements) are required.
 Oct 30, 2018
 */

void NTUPLE::make2l2tauVariables(float & m_minlepb, float & dR_minlepb_tautau, float & m_tautau, 
             float & dR_ll, float & dR_ll_tautau, float & pt_sum_bjets){
       //inits, just in case they won't be filled
       m_minlepb=0;
       dR_minlepb_tautau=0;
       m_tautau=0;
       dR_ll=0;
       dR_ll_tautau=0;
       pt_sum_bjets=0;
       //define vectors here
       vector <TLorentzVector> jet_vecs; //store all jets
       vector <TLorentzVector> bjet_vecs; //b jets
       vector <TLorentzVector> nonbjet_vecs; //non b-jets
       TLorentzVector met_vec; //MET vector
       TLorentzVector lep1_vec; //leading lepton vector
       TLorentzVector lep2_vec; //sub leading lepton vector
       TLorentzVector tau1_vec; //leading tau vector
       TLorentzVector tau2_vec; //sub leading tau vector
       TLorentzVector tmp_vec; //tmp

       for(unsigned int i=0;i<m_jet_pt->size();i++){
           if( !((*m_jet_passOR)[i] && (*m_jet_passTauOR)[i]) ) continue;
           tmp_vec.SetPtEtaPhiE( (*m_jet_pt)[i], (*m_jet_eta)[i], (*m_jet_phi)[i], (*m_jet_E)[i]);
           if ((*m_jet_flavor_weight_MV2c10)[i]>0.83)  bjet_vecs.push_back(tmp_vec);
           else nonbjet_vecs.push_back(tmp_vec);
           jet_vecs.push_back(tmp_vec);
       }
       if(bjet_vecs.size()>=1) {
          tau1_vec.SetPtEtaPhiE(tau_pt_0, tau_eta_0, tau_phi_0, tau_E_0); 
          tau2_vec.SetPtEtaPhiE(tau_pt_1, tau_eta_1, tau_phi_1, tau_E_1);
          lep1_vec.SetPtEtaPhiE(lep_Pt_0, lep_Eta_0, lep_Phi_0, lep_E_0); 
          lep2_vec.SetPtEtaPhiE(lep_Pt_1, lep_Eta_1, lep_Phi_1, lep_E_1); 
          //
          TLorentzVector bjet_vec1=bjet_vecs[0];
          //
          /*float tmp_dR=99;
          for(unsigned int i=0; i<bjet_vecs.size(); i++) {
              float tmp_tmp_dR=lep1_vec.DeltaR(bjet_vecs[i]) > lep2_vec.DeltaR(bjet_vecs[i])?
                    lep2_vec.DeltaR(bjet_vecs[i]):lep1_vec.DeltaR(bjet_vecs[i]);
              float tmp_tmp_mass=lep1_vec.DeltaR(bjet_vecs[i]) > lep2_vec.DeltaR(bjet_vecs[i])?
                     (lep2_vec + bjet_vecs[i]).M():(lep1_vec + bjet_vecs[i]).M();
              float tmp_tmp_dRtautau=lep1_vec.DeltaR(bjet_vecs[i]) > lep2_vec.DeltaR(bjet_vecs[i])?
                     (lep2_vec + bjet_vecs[i]).DeltaR(tau1_vec + tau2_vec):(lep1_vec + bjet_vecs[i]).DeltaR(tau1_vec + tau2_vec);
              if(tmp_tmp_dR < tmp_dR){
                 tmp_dR=tmp_tmp_dR;
                 m_minlepb=tmp_tmp_mass;
                 dR_minlepb_tautau=tmp_tmp_dRtautau;
              }
              pt_sum_bjets += bjet_vecs[i].Pt();
          }//end of i*/
          float tmp_mass=9999e3;
          for(unsigned int i=0; i<bjet_vecs.size(); i++) {
              float tmp_tmp_mass=(lep1_vec + bjet_vecs[i]).M() > (lep2_vec + bjet_vecs[i]).M()?
                    (lep2_vec + bjet_vecs[i]).M():(lep1_vec + bjet_vecs[i]).M();
              float tmp_tmp_dRtautau=(lep1_vec + bjet_vecs[i]).M() > (lep2_vec + bjet_vecs[i]).M()?
                    (lep2_vec + bjet_vecs[i]).DeltaR(tau1_vec + tau2_vec):(lep1_vec + bjet_vecs[i]).DeltaR(tau1_vec + tau2_vec);
              if(tmp_tmp_mass < tmp_mass){
                 tmp_mass=tmp_tmp_mass;
                 m_minlepb=tmp_tmp_mass;
                 dR_minlepb_tautau=tmp_tmp_dRtautau;
              }
          }//end of i
          
          m_tautau=(tau1_vec + tau2_vec).M();
          dR_ll=lep1_vec.DeltaR(lep2_vec);
          dR_ll_tautau=(lep1_vec+lep2_vec).DeltaR(tau1_vec + tau2_vec);
       }//end of #jet selection 
     
}
#endif
