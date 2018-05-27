#ifdef NTUPLE_cxx

inline bool NTUPLE::commonSelections(){
      
       // !!! if regular variable doesn't wrok, try input_branches["var_name"].c (c, f, and i means bool/char, float and int, respectively)
       
       bool basic_selection = passEventCleaning && (onelep_type||dilep_type||trilep_type||quadlep_type);
       basic_selection &= ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose )) || (RunYear==2016 && ( HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))|| (RunYear==2017 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 ||HLT_e140_lhloose_nod0 ))||
(RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1)) ||
(RunYear==2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))||
(RunYear==2017&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))) ;
      // bool trig_match =(lep_isTrigMatch_0 || lep_isTrigMatch_1 || lep_isTrigMatch_2 || lep_isTrigMatch_3 || matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);

       if(basic_selection ) return true;

       else return false;
}
#endif
