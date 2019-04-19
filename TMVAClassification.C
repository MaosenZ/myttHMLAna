/*
 *Maosen Zhou, 4/10/2019
 */
void TMVAClassification(){
  //Declare Factory
  TMVA::Tools::Instance();
  auto inputFile_Sig=TFile::Open("hists/tth.root");
  auto inputFile_Bkg=TFile::Open("hists/ttbar.root");
  auto outputFile=TFile::Open("BDTG_train.root","RECREATE");

  TMVA::Factory factory("TMVAClassification",outputFile, "!V:ROC:!Correlations:!Silent:Color:!DrawProgressBar:AnalysisType=Classification" );
  //Declare DataLoader
  TMVA::DataLoader loader("dataset");
  
  loader.AddVariable("mindR_lepj");
  loader.AddVariable("avdR_jj");
  loader.AddVariable("dR_tautau");
  loader.AddVariable("mindR_tau1j");
  loader.AddVariable("mindR_tau2j");
  loader.AddVariable("dR_leptau1");
  loader.AddVariable("dR_ssleptau");
  loader.AddVariable("mT_l1");
  loader.AddVariable("pT_top");
  loader.AddVariable("m_top");
  loader.AddVariable("costheta_tautau");
 
  //setup Datasets
  TTree *tsignal, *tbackground;
  inputFile_Sig->GetObject("minitree", tsignal);
  inputFile_Bkg->GetObject("minitree", tbackground);

  //TCut mycuts="OneL2tauOSnoBDTtruth";
  //TCut mycutb="OneL2tauOSnoBDT || OneL2tauSSnoBDT";
  TCut mycuts="", mycutb="";
  //loader.AddSignalTree    (tsignal,     1.0);   //signal weight  = 1
  //loader.AddBackgroundTree(tbackground, 1.0);   //background weight 
  std::vector<Double_t> vars( 11 ); // vector has size of number of input variables
  Float_t treevars[11]; 
  Int_t       EventNumber; 
  Int_t       OneL2tauOSnoBDTtruth;
  Int_t       OneL2tauOSnoBDT;
  Int_t       OneL2tauSSnoBDT;
  // Signal
  tsignal->SetBranchAddress("mindR_lepj" ,      &treevars[0]);
  tsignal->SetBranchAddress("avdR_jj" ,         &treevars[1]);
  tsignal->SetBranchAddress("dR_tautau" ,       &treevars[2]);
  tsignal->SetBranchAddress("mindR_tau1j" ,     &treevars[3]);
  tsignal->SetBranchAddress("mindR_tau2j" ,     &treevars[4]);
  tsignal->SetBranchAddress("dR_leptau1" ,      &treevars[5]);
  tsignal->SetBranchAddress("dR_ssleptau" ,     &treevars[6]);
  tsignal->SetBranchAddress("mT_l1" ,           &treevars[7]);
  tsignal->SetBranchAddress("pT_top" ,          &treevars[8]);
  tsignal->SetBranchAddress("m_top" ,           &treevars[9]);
  tsignal->SetBranchAddress("costheta_tautau" , &treevars[10]);
  tsignal->SetBranchAddress("EventNumber" ,     &EventNumber);
  tsignal->SetBranchAddress("OneL2tauOSnoBDTtruth" ,     &OneL2tauOSnoBDTtruth);
  tsignal->SetBranchAddress("OneL2tauOSnoBDT" ,     &OneL2tauOSnoBDT);
  tsignal->SetBranchAddress("OneL2tauSSnoBDT" ,     &OneL2tauSSnoBDT);
  for (UInt_t i=0; i<tsignal->GetEntries(); i++) {
     tsignal->GetEntry(i);
     if (!OneL2tauOSnoBDTtruth) continue;
     for (UInt_t ivar=0; ivar<11; ivar++) vars[ivar] = treevars[ivar];
     // add training and test events; here: odd evevts is training, even is testing
     // note that the weight can also be event-wise
     if (EventNumber%2==1) loader.AddSignalTrainingEvent( vars, 1. );
     else                  loader.AddSignalTestEvent    ( vars, 1. );
  }
 
  // Background
  tbackground->SetBranchAddress("mindR_lepj" ,      &treevars[0]);
  tbackground->SetBranchAddress("avdR_jj" ,         &treevars[1]);
  tbackground->SetBranchAddress("dR_tautau" ,       &treevars[2]);
  tbackground->SetBranchAddress("mindR_tau1j" ,     &treevars[3]);
  tbackground->SetBranchAddress("mindR_tau2j" ,     &treevars[4]);
  tbackground->SetBranchAddress("dR_leptau1" ,      &treevars[5]);
  tbackground->SetBranchAddress("dR_ssleptau" ,     &treevars[6]);
  tbackground->SetBranchAddress("mT_l1" ,           &treevars[7]);
  tbackground->SetBranchAddress("pT_top" ,          &treevars[8]);
  tbackground->SetBranchAddress("m_top" ,           &treevars[9]);
  tbackground->SetBranchAddress("costheta_tautau" , &treevars[10]);
  tbackground->SetBranchAddress("EventNumber" ,     &EventNumber);
  tbackground->SetBranchAddress("OneL2tauOSnoBDTtruth" ,     &OneL2tauOSnoBDTtruth);
  tbackground->SetBranchAddress("OneL2tauOSnoBDT" ,     &OneL2tauOSnoBDT);
  tbackground->SetBranchAddress("OneL2tauSSnoBDT" ,     &OneL2tauSSnoBDT);  
  for (UInt_t i=0; i<tbackground->GetEntries(); i++) {
     tbackground->GetEntry(i);
     if(!(OneL2tauOSnoBDT || OneL2tauSSnoBDT )) continue;
     for (UInt_t ivar=0; ivar<11; ivar++) vars[ivar] = treevars[ivar];
     // add training and test events; here: odd half is training, even is testing
     // note that the weight can also be event-wise
     if (EventNumber%2==1) loader.AddBackgroundTrainingEvent( vars, 1. );
     else                  loader.AddBackgroundTestEvent    ( vars, 1. );
  }
  
  loader.PrepareTrainingAndTestTree(mycuts, mycutb,
                           //"nTrain_Signal=1000:nTrain_Background=1000:SplitMode=Random:NormMode=NumEvents:!V" ); 
                           "SplitMode=Random:NormMode=NumEvents:!V" ); 
  //First dataset
  factory.BookMethod( &loader, TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=200:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );
  factory.BookMethod(&loader,TMVA::Types::kBDT, "BDT",
                   "!V:NTrees=200:MinNodeSize=2.5%:MaxDepth=2:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" ); 
  
  //Train methods
  factory.TrainAllMethods();
  //Test and evaluate methods
  factory.TestAllMethods();
  factory.EvaluateAllMethods();
  
  //Plot ROC Curve
  auto c1=factory.GetROCCurve(&loader);
  c1->Draw();
  outputFile->Close();

  std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
  std::cout << "==> TMVARegression is done!" << std::endl;

  // Launch the GUI for the root macros
  //if (!gROOT->IsBatch()) TMVA::TMVAGui( outputFile->GetName() );
}
