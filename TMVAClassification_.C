/*
 *Maosen Zhou, 4/10/2019
 */
void TMVAClassification_(){

  //read in vars which will be used in training
  std::ifstream inhists("trainning_vars.list", ifstream::in);
  string line, trainvar;
  std::vector<TString> trainvars;
  int numvars=0;
  if(inhists.is_open()){
     while ( getline(inhists,line) ){
        if(line[0]=='#') continue;
        std::istringstream iss(line);
        iss >> trainvar;
        trainvars.push_back(trainvar);
        numvars++;
     }
  }
  //Declare Factory
  TMVA::Tools::Instance();
  auto inputFile_Sig=TFile::Open("hists/tth.root");
  auto inputFile_Bkg=TFile::Open("hists/ttbar_allgen.root");
  auto outputFile=TFile::Open("BDTG_train.root","RECREATE");

  TMVA::Factory factory("TMVAClassification",outputFile, "!V:ROC:!Correlations:!Silent:Color:!DrawProgressBar:AnalysisType=Classification" );
  //Declare DataLoader
  TMVA::DataLoader loader("dataset");
 
  for(int i=0;i<numvars;i++) loader.AddVariable(trainvars[i]); 
 
  //setup Datasets
  TTree *tsignal, *tbackground;
  inputFile_Sig->GetObject("minitree", tsignal);
  inputFile_Bkg->GetObject("minitree", tbackground);

  //TCut mycuts="OneL2tauOSnoBDTtruth";
  //TCut mycutb="OneL2tauOSnoBDT || OneL2tauSSnoBDT";
  TCut mycuts="", mycutb="";
  //loader.AddSignalTree    (tsignal,     1.0);   //signal weight  = 1
  //loader.AddBackgroundTree(tbackground, 1.0);   //background weight 
  std::vector<Double_t> vars( numvars ); // vector has size of number of input variables
  Float_t treevars[numvars]; 
  Int_t       EventNumber; 
  Int_t       OneL2tauOSnoBDTtruth;
  Int_t       OneL2tauOSnoBDT;
  Int_t       OneL2tauSSnoBDT;
  Int_t       OneL2tauLMMOS;
  Int_t       OneL2tauLMMSS;
  // Signal
  for(int i=0;i<numvars;i++) tsignal->SetBranchAddress(trainvars[i], &treevars[i]);
  tsignal->SetBranchAddress("EventNumber" ,     &EventNumber);
  tsignal->SetBranchAddress("OneL2tauOSnoBDTtruth" ,     &OneL2tauOSnoBDTtruth);
  tsignal->SetBranchAddress("OneL2tauOSnoBDT" ,     &OneL2tauOSnoBDT);
  tsignal->SetBranchAddress("OneL2tauSSnoBDT" ,     &OneL2tauSSnoBDT);
  tsignal->SetBranchAddress("OneL2tauLMMOS" ,     &OneL2tauLMMOS);
  tsignal->SetBranchAddress("OneL2tauLMMSS" ,     &OneL2tauLMMSS);
  for (UInt_t i=0; i<tsignal->GetEntries(); i++) {
     tsignal->GetEntry(i);
     if (!OneL2tauOSnoBDTtruth) continue;
     for (UInt_t ivar=0; ivar<numvars; ivar++) vars[ivar] = treevars[ivar];
     // add training and test events; here: odd evevts is training, even is testing
     // note that the weight can also be event-wise
     if (EventNumber%2==1) loader.AddSignalTrainingEvent( vars, 1. );
     else                  loader.AddSignalTestEvent    ( vars, 1. );
  }
 
  // Background
  for(int i=0;i<numvars;i++) tbackground->SetBranchAddress(trainvars[i], &treevars[i]);
  tbackground->SetBranchAddress("EventNumber" ,     &EventNumber);
  tbackground->SetBranchAddress("OneL2tauOSnoBDTtruth" ,     &OneL2tauOSnoBDTtruth);
  tbackground->SetBranchAddress("OneL2tauOSnoBDT" ,     &OneL2tauOSnoBDT);
  tbackground->SetBranchAddress("OneL2tauSSnoBDT" ,     &OneL2tauSSnoBDT);  
  tbackground->SetBranchAddress("OneL2tauLMMOS" ,     &OneL2tauLMMOS);  
  tbackground->SetBranchAddress("OneL2tauLMMSS" ,     &OneL2tauLMMSS);  

  for (UInt_t i=0; i<tbackground->GetEntries(); i++) {
     tbackground->GetEntry(i);
     //if(!(OneL2tauOSnoBDT || OneL2tauSSnoBDT )) continue;
     if(!(OneL2tauLMMOS || OneL2tauLMMSS )) continue;
     for (UInt_t ivar=0; ivar<numvars; ivar++) vars[ivar] = treevars[ivar];
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
                           "!H:!V:NTrees=150:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );
  //factory.BookMethod(&loader,TMVA::Types::kBDT, "BDT",
  //                 "!V:NTrees=200:MinNodeSize=2.5%:MaxDepth=2:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" ); 
  
  //Train methods
  factory.TrainAllMethods();
  //Test and evaluate methods
  factory.TestAllMethods();
  factory.EvaluateAllMethods();
  
  //Plot ROC Curve
  TGraph* c1=factory.GetROCCurve(&loader, "BDTG", kTRUE);
  c1->Write();
  //c1->Draw();
  outputFile->Close();

  std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
  std::cout << "==> TMVARegression is done!" << std::endl;

  // Launch the GUI for the root macros
  if (!gROOT->IsBatch()) TMVA::TMVAGui( outputFile->GetName() );
}
