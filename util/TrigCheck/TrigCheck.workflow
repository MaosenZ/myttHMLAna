I was asked to check gain of using lepton+tau triggers for tau channels of ttHML.
Based on the feedback, trigger group will decide keep or remove those triggers from trigger menu.
Here is the workflow of this check:

1.Get the AOD samples, and parse to HIGG8D1 
https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/DerivationProductionTeam
Read 'After a MC sample is produced' section
And submit HIGG8D1 derivation
(I was using p3652 that corresponds to 21.2.44.0)

2.Once derivation is done, parse DAOD to ttHML GN1 framework to make ntuples
https://gitlab.cern.ch/atlasHTop/ttHMultiAna?nav_source=navbar
Open mc config file, modify 'PRWConfigFiles' and add all the to-be-checked triggers in 'TRIGDEC' 
(Since these special samples are mc16e and have very low statistics, to make GN1 working, I had to use mc16d pileup reweighting root file. But if new samples have more statistics, you may follow https://twiki.cern.ch/twiki/bin/view/AtlasProtected/ExtendedPileupReweighting#GenerateMC16 and make right pile-up reweighting files. However! We don'tcare about pile-up reweighting at all! All of this is only to make GN1 working, in fact, we need a flat pile-up distribution (in pricinple we can make one), so in final yields counting, 'pileupEventWeight_090' should be removed)

3.Get the GN1 ntuples and get the macro. Run it and log the results here:

