#include "eff.h"

void eff(string dir, string sample)
{
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain("ntp");
  ntp->Add(input_name.c_str());
  
  float nEvents = ntp->GetEntries();
  float nDst_reco = 0.;
  float nD0_reco = 0.;
  float nPi_reco = 0.;
  float nK_reco = 0.;
  float nSPi_reco = 0.;
  int  isPi_reco, isK_reco, isSPi_reco;
  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("P1_Reconstructed",1); ntp->SetBranchAddress("P1_Reconstructed", &(isPi_reco));
  ntp->SetBranchStatus("P2_Reconstructed",1); ntp->SetBranchAddress("P2_Reconstructed", &(isK_reco));
  ntp->SetBranchStatus("sPi_Reconstructed",1); ntp->SetBranchAddress("sPi_Reconstructed", &(isSPi_reco));
  

  
  for(int i = 0; i < nEvents; ++i)
  {
    ntp->GetEvent(i);
    if(isPi_reco == 1) nPi_reco+=1.;
    if(isK_reco == 1) nK_reco+=1.;
    if(isSPi_reco == 1) nSPi_reco+=1.;
    if(isPi_reco == 1 && isK_reco == 1) nD0_reco+=1.;
    if((isPi_reco == 1 && isK_reco == 1) && isSPi_reco == 1) nDst_reco+=1.;
  }
  
  cout << "Reconstructed number of pions: " << nPi_reco << ", eff.: " << nPi_reco/nEvents << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco << ", eff.: " << nK_reco/nEvents << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco << ", eff.: " << nSPi_reco/nEvents << endl;
  cout << "Reconstructed number of D0: " << nD0_reco << ", eff.: " << nD0_reco/nEvents << endl;
  cout << "Reconstructed number of D*: " << nDst_reco << ", eff.: " << nDst_reco/nEvents << endl;
}
