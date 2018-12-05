#ifdef NTUPLE_cxx

/*
 *This macro used for ttH->1l2tau, where >=1 bjets (minimal requirements) are required.
 Dec 3, 2018
 */

void NTUPLE::makeCMSVariables(float & mindR_lepj, float & mT_l1, float & avdR_jj, 
             float & pT_top, float & dR_tautau, float & costheta_tautau, float & mindR_tau1j,
             float & mindR_tau2j, float & dR_leptau1, float & dR_ssleptau, float & m_top){
       //inits, just in case they won't be filled
       mindR_lepj=-1;
       mT_l1=-1;
       avdR_jj=-1;
       pT_top=-1;
       dR_tautau=-1;
       costheta_tautau=-1;
       mindR_tau1j=-1;
       mindR_tau2j=-1;
       dR_leptau1=-1;
       dR_ssleptau=-1;
       m_top=-1;
       //define vectors here
       vector <TLorentzVector> jet_vecs; //store all jets
       vector <TLorentzVector> bjet_vecs; //b jets
       vector <TLorentzVector> nonbjet_vecs; //non b-jets
       TLorentzVector met_vec; //MET vector
       TLorentzVector lep1_vec; //leading lepton vector
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
          //cout<<"start here"<<endl;
          float tmp_dR_lepj=99, tmp_dR_tau1j=99, tmp_dR_tau2j=99;
          float counts=0, dRjj=0;
          for(unsigned int i=0; i<jet_vecs.size();i++){
              //$$$---mindR_lepj, min dR between lepton and jets---$$$
	      if(lep1_vec.DeltaR(jet_vecs[i]) < tmp_dR_lepj){
                 tmp_dR_lepj=lep1_vec.DeltaR(jet_vecs[i]);
	         mindR_lepj=tmp_dR_lepj; 
              }
              //$$---mindR_tau1j, min dR between tau1 and jets---$$$
              if(tau1_vec.DeltaR(jet_vecs[i]) < tmp_dR_tau1j){
                 tmp_dR_tau1j=tau1_vec.DeltaR(jet_vecs[i]);
                 mindR_tau1j=tmp_dR_tau1j;
              }
              //$$---mindR_tau2j, min dR between tau2 and jets---$$$
              if(tau2_vec.DeltaR(jet_vecs[i]) < tmp_dR_tau2j){
                 tmp_dR_tau2j=tau2_vec.DeltaR(jet_vecs[i]);
                 mindR_tau2j=tmp_dR_tau2j;
              }
              //$$$---avdR_jj, average dR of jj---$$$
              for(unsigned int j=i+1;j<jet_vecs.size();j++){
                  dRjj+=jet_vecs[i].DeltaR(jet_vecs[j]);
              }
          }//end of jet loop i
          avdR_jj=dRjj/counts;
          //top1 is reconstructed by leading b jet and two closest jets (no matter b-tagged or not)
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
          pT_top=(bjet_vec1 + jet_vecs[0] + jet_vecs[1]).Pt();
          m_top=(bjet_vec1 + jet_vecs[0] + jet_vecs[1]).M(); 
          //$$$---mT_l1, transverse mass of leading lepton---$$$
          mT_l1=lep1_vec.Mt();
          //$$$---dR_tautau, dR of tautau---$$$$
          dR_tautau=tau1_vec.DeltaR(tau2_vec);
          //$$$---dR_leptau1, dR of lepton and leading tau---$$$ 
          dR_leptau1=lep1_vec.DeltaR(tau1_vec);
          //$$$---dR_ssleptau, dR of same-signed lepton and tau---$$$
          dR_ssleptau=lep_ID_0*tau_charge_0<0?lep1_vec.DeltaR(tau1_vec):lep1_vec.DeltaR(tau2_vec);
          // Finally $$$---costheta_tautau: costheta star of tautau---$$$
          TLorentzVector tautau=tau1_vec + tau2_vec;
          tau1_vec.Boost(-tautau.BoostVector());
          costheta_tautau=fabs(tau1_vec.CosTheta()); 
       }//end of #jet selection 
     
}
#endif
