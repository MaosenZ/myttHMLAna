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
        'MVA1l2tau_weight':('BDT score', 'Events'), \
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
         }
