#input sample lists
inputsamples=("data","ttbar","ttbargamma","diboson","tth","Vjets","ttV","rare")
#input sample lists that going to be plotted
processes={'data':"data",\
           'ttbar':"ttbar",\
           'ttbargamma':"ttbargamma",\
           'diboson':"diboson",\
           'tth':"tth",\
           'Vjets':"Vjets",\
           'ttV':"ttV",\
           'rare':"rare"}

#define plot titles here
titles={'lep_Pt_0':('p^{T}_{l1} [GeV]', 'Events'), \
        'tau_pt_0':('p^{T}_{#tau_{1}} [GeV]', 'Events'), \
        'tau_pt_1':('p^{T}_{#tau_{2}} [GeV]', 'Events'), \
        'lep_Pt_0':('p^{T}_{#lep_{1}} [GeV]', 'Events'), \
        'lep_Pt_1':('p^{T}_{#lep_{2}} [GeV]', 'Events'), \
        'MVA1l2tau_weight':('BDT score', 'Events'), \
        'Mybdt':('BDT score', 'Events'), \
        'Mybdtx':('BDT score', 'Events'), \
        'nJets_OR_T':('nJets_OR_T', 'Events'), \
        'nJets_OR_T_MV2c10_70':('nJets_OR_T_MV2c10_70', 'Events'), \
        'HT_jets':('HT_jets [GeV]', 'Events'), \
        'jjdrmin_1l2tau':('#Delta R_{min}(jj)', 'Events'), \
        'mtautau_1l2tau':('M(#tau_{had}#tau_{had})', 'Events'), \
        'njets_1l2tau':('njets_1l2tau', 'Events'), \
        'nbjets_1l2tau':('nbjets_1l2tau', 'Events'), \
        'htjets_1l2tau':('htjets_1l2tau', 'Events'), \
        'tau_BDTJetScore_0':('#tau_{1} BDTJetScore', 'Events'), \
        'tau_BDTJetScore_1':('#tau_{2} BDTJetScore', 'Events'), \
        'tau_tight_0':('tau_tight_0', 'Events'), \
        'tau_tight_1':('tau_tight_1', 'Events'), \
        'tau_truthType_0':('tau_truthType_0','Events'),\
        'tau_truthType_1':('tau_truthType_1','Events'),\
        'tau_truthOrigin_1':('tau_truthOrigin_1','Events'),\
        'tau_truthOrigin_0':('tau_truthOrigin_0','Events'),\
        'maxeta':('#eta_{max}',"Events"),\
        'tau_eta_0':('#eta_{#tau0}',"Events"),\
        'tau_eta_1':('#eta_{#tau1}',"Events"),\
        'tau_tagWeightBin_0':("tau_tagWeightBin_0","Events"),\
        'tau_tagWeightBin_1':("tau_tagWeightBin_1","Events"),\
        'top1_mass':("Top1 Mass [GeV]", "Events"),\
        'top2_mass':("Top2 Mass [GeV]", "Events"),\
        'MET_RefFinal_et':("MET [GeV]", "Events"),\
        'mT_lepmet':("mT(lep,met) [GeV]", "Events"),\
        'm_blepmin':("minM(bjet,lep) [GeV]", "Events"),\
        'dphi_ltaumet':("#Delta#Phi(lep#tau_{had},met)", "Events"),\
        'wmass1':("W1 mass [GeV]","Events"),\
        'wmass2':("W2 mass [GeV]","Events"),\
        'pt_lepminustau':("pT(lep)-pT(tau) [GeV]", "Events"),\
        'm_ltau':("M(lep,#tau_{had}) [GeV]", "Events"),\
        'm_ltaumet':("M(lep,#tau_{had},met) [GeV]", "Events"),\
        'pt_sum_all':("pT_sum_all [GeV]","Events"),\
        'pt_sum_nonbjets':("pt_sum_nonbjets [GeV]","Events"),\
        'Mll01':("Mll01 [GeV]", "Events")
         }
titles_norm={'lep_Pt_0':('p^{T}_{l1} [GeV]', 'Normalized'), \
        'tau_pt_0':('p^{T}_{#tau_{1}} [GeV]', 'Normalized'), \
        'tau_pt_1':('p^{T}_{#tau_{2}} [GeV]', 'Normalized'), \
        'lep_Pt_0':('p^{T}_{#lep_{1}} [GeV]', 'Normalized'), \
        'lep_Pt_1':('p^{T}_{#lep_{2}} [GeV]', 'Normalized'), \
        'MVA1l2tau_weight':('BDT score', 'Normalized'), \
        'Mybdt':('BDT score', 'Normalized'), \
        'Mybdtx':('BDT score', 'Normalized'), \
        'nJets_OR_T':('nJets_OR_T', 'Normalized'), \
        'nJets_OR_T_MV2c10_70':('nJets_OR_T_MV2c10_70', 'Normalized'), \
        'HT_jets':('HT_jets [GeV]', 'Normalized'), \
        'jjdrmin_1l2tau':('#Delta R_{min}(jj)', 'Normalized'), \
        'mtautau_1l2tau':('M(#tau_{had}#tau_{had})', 'Normalized'), \
        'njets_1l2tau':('njets_1l2tau', 'Normalized'), \
        'nbjets_1l2tau':('nbjets_1l2tau', 'Normalized'), \
        'htjets_1l2tau':('htjets_1l2tau', 'Normalized'), \
        'tau_BDTJetScore_0':('#tau_{1} BDTJetScore', 'Normalized'), \
        'tau_BDTJetScore_1':('#tau_{2} BDTJetScore', 'Normalized'), \
        'tau_tight_0':('tau_tight_0', 'Normalized'), \
        'tau_tight_1':('tau_tight_1', 'Normalized'), \
        'tau_truthType_0':('tau_truthType_0','Normalized'),\
        'tau_truthType_1':('tau_truthType_1','Normalized'),\
        'tau_truthOrigin_1':('tau_truthOrigin_1','Normalized'),\
        'tau_truthOrigin_0':('tau_truthOrigin_0','Normalized'),\
        'maxeta':('#eta_{max}',"Normalized"),\
        'tau_eta_0':('#eta_{#tau0}',"Normalized"),\
        'tau_eta_1':('#eta_{#tau1}',"Normalized"),\
        'tau_tagWeightBin_0':("tau_tagWeightBin_0","Normalized"),\
        'tau_tagWeightBin_1':("tau_tagWeightBin_1","Normalized"),\
        'top1_mass':("Top1 Mass [GeV]", "Normalized"),\
        'top2_mass':("Top2 Mass [GeV]", "Normalized"),\
        'MET_RefFinal_et':("MET [GeV]", "Normalized"),\
        'mT_lepmet':("mT(lep,met) [GeV]", "Normalized"),\
        'm_blepmin':("minM(bjet,lep) [GeV]", "Normalized"),\
        'dphi_ltaumet':("#Delta#Phi(lep#tau_{had},met)", "Normalized"),\
        'wmass1':("W1 mass [GeV]","Normalized"),\
        'wmass2':("W2 mass [GeV]","Normalized"),\
        'pt_lepminustau':("pT(lep)-pT(tau) [GeV]", "Normalized"),\
        'm_ltau':("M(lep,#tau_{had}) [GeV]", "Normalized"),\
        'm_ltaumet':("M(lep,#tau_{had},met) [GeV]", "Normalized"),\
        'pt_sum_all':("pT_sum_all [GeV]","Normalized"),\
        'pt_sum_nonbjets':("pt_sum_nonbjets [GeV]","Normalized"),\
        'Mll01':("Mll01 [GeV]", "Normalized")
         }
