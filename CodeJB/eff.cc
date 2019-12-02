#include "eff.h"

void eff(string dir, string sample)
{
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain("ntp");
  ntp->Add(input_name.c_str());
  
  int nEvents = ntp->GetEntries();
  double nDst_reco = 0.;
  double nD0_reco = 0.;
  double nPi_reco = 0.;
  double nK_reco = 0.;
  double nSPi_reco = 0.;
  
  double Dst_pT = 0.;
  double D0_pT = 0.;
  double Pi_pT = 0.;
  double K_pT = 0.;
  double SPi_pT = 0.;
  
  double Dst_phi = 0.;
  double D0_phi = 0.;
  double Pi_phi = 0.;
  double K_phi = 0.;
  double SPi_phi = 0.;
  
  double Dst_eta = 0.;
  double D0_eta = 0.;
  double Pi_eta = 0.;
  double K_eta = 0.;
  double SPi_eta = 0.;
  int  isPi_reco, isK_reco, isSPi_reco;
  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("P1_Reconstructed",1); ntp->SetBranchAddress("P1_Reconstructed", &(isPi_reco));
  ntp->SetBranchStatus("P2_Reconstructed",1); ntp->SetBranchAddress("P2_Reconstructed", &(isK_reco));
  ntp->SetBranchStatus("sPi_Reconstructed",1); ntp->SetBranchAddress("sPi_Reconstructed", &(isSPi_reco));
  
  ntp->SetBranchStatus("Dst_PT",1); ntp->SetBranchAddress("Dst_PT", &(Dst_pT));
  ntp->SetBranchStatus("D0_PT",1); ntp->SetBranchAddress("D0_PT", &(D0_pT));
  ntp->SetBranchStatus("P1_PT",1); ntp->SetBranchAddress("P1_PT", &(Pi_pT));
  ntp->SetBranchStatus("P2_PT",1); ntp->SetBranchAddress("P2_PT", &(K_pT));
  ntp->SetBranchStatus("sPi_PT",1); ntp->SetBranchAddress("sPi_PT", &(SPi_pT));
  
  ntp->SetBranchStatus("Dst_PHI",1); ntp->SetBranchAddress("Dst_PHI", &(Dst_phi));
  ntp->SetBranchStatus("D0_PHI",1); ntp->SetBranchAddress("D0_PHI", &(D0_phi));
  ntp->SetBranchStatus("P1_PHI",1); ntp->SetBranchAddress("P1_PHI", &(Pi_phi));
  ntp->SetBranchStatus("P2_PHI",1); ntp->SetBranchAddress("P2_PHI", &(K_phi));
  ntp->SetBranchStatus("sPi_PHI",1); ntp->SetBranchAddress("sPi_PHI", &(SPi_phi));
  
  ntp->SetBranchStatus("Dst_ETA",1); ntp->SetBranchAddress("Dst_ETA", &(Dst_eta));
  ntp->SetBranchStatus("D0_ETA",1); ntp->SetBranchAddress("D0_ETA", &(D0_eta));
  ntp->SetBranchStatus("P1_ETA",1); ntp->SetBranchAddress("P1_ETA", &(Pi_eta));
  ntp->SetBranchStatus("P2_ETA",1); ntp->SetBranchAddress("P2_ETA", &(K_eta));
  ntp->SetBranchStatus("sPi_ETA",1); ntp->SetBranchAddress("sPi_ETA", &(SPi_eta));

  
  
  TH1F *h_pT_reco_SPi = new TH1F("h_pT_reco_SPi", ";p_T/MeV; reconstructed Events", 250, 100., 800.);
  TH1F *h_pT_reco_Pi = new TH1F("h_pT_reco_Pi", ";p_T/MeV; reconstructed Events", 250, 700., 5700.);
  TH1F *h_pT_reco_K = new TH1F("h_pT_reco_K", ";p_T/MeV; reconstructed Events", 275, 700., 6200.);
  TH1F *h_pT_reco_D0 = new TH1F("h_pT_reco_D0", ";p_T/MeV; reconstructed Events", 350, 2000., 9000.);
  TH1F *h_pT_reco_Dst = new TH1F("h_pT_reco_Dst", ";p_T/MeV; reconstructed Events", 370, 2200., 9600.);
  TH1F *h_pT_SPi = new TH1F("h_pT_SPi", ";p_T/MeV;Events", 250, 100., 800.);
  TH1F *h_pT_Pi = new TH1F("h_pT_Pi", ";p_T/MeV;Events", 250, 700., 5700.);
  TH1F *h_pT_K = new TH1F("h_pT_K", ";p_T/MeV;Events", 275, 700., 6200.);
  TH1F *h_pT_D0 = new TH1F("h_pT_D0", ";p_T/MeV;Events", 350, 2000., 9000.);
  TH1F *h_pT_Dst = new TH1F("h_pT_Dst", ";p_T/MeV;Events", 370, 2200., 9600.);
  
  TH1F *h_phi_reco_SPi = new TH1F("h_phi_reco_SPi", ";p_T/MeV; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_Pi = new TH1F("h_phi_reco_Pi", ";p_T/MeV; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_K = new TH1F("h_phi_reco_K", ";p_T/MeV; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_D0 = new TH1F("h_phi_reco_D0", ";p_T/MeV; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_Dst = new TH1F("h_phi_reco_Dst", ";p_T/MeV; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_SPi = new TH1F("h_phi_SPi", ";p_T/MeV;Events", 100, -3.5, 3.5);
  TH1F *h_phi_Pi = new TH1F("h_phi_Pi", ";p_T/MeV;Events", 100, -3.5, 3.5);
  TH1F *h_phi_K = new TH1F("h_phi_K", ";p_T/MeV;Events", 100, -3.5, 3.5);
  TH1F *h_phi_D0 = new TH1F("h_phi_D0", ";p_T/MeV;Events", 100, -3.5, 3.5);
  TH1F *h_phi_Dst = new TH1F("h_phi_Dst", ";p_T/MeV;Events", 100, -3.5, 3.5);
  
  TH1F *h_eta_reco_SPi = new TH1F("h_eta_reco_SPi", ";p_T/MeV; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_Pi = new TH1F("h_eta_reco_Pi", ";p_T/MeV; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_K = new TH1F("h_eta_reco_K", ";p_T/MeV; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_D0 = new TH1F("h_eta_reco_D0", ";p_T/MeV; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_Dst = new TH1F("h_eta_reco_Dst", ";p_T/MeV; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_SPi = new TH1F("h_eta_SPi", ";p_T/MeV;Events", 100, 2.0, 4.5);
  TH1F *h_eta_Pi = new TH1F("h_eta_Pi", ";p_T/MeV;Events", 100, 2.0, 4.5);
  TH1F *h_eta_K = new TH1F("h_eta_K", ";p_T/MeV;Events", 100, 2.0, 4.5);
  TH1F *h_eta_D0 = new TH1F("h_eta_D0", ";p_T/MeV;Events", 100, 2.0, 4.5);
  TH1F *h_eta_Dst = new TH1F("h_eta_Dst", ";p_T/MeV;Events", 100, 2.0, 4.5);
  
  for(int i = 0; i < nEvents; ++i)
  {
    ntp->GetEvent(i);
    if (i % (nEvents/10) == 0)cout << "=== Event " << i/(nEvents/10) * 10 << "%" << endl;
    if(isPi_reco == 1)
    {
      nPi_reco+=1.;
      h_pT_reco_Pi->Fill(Pi_pT);
      h_phi_reco_Pi->Fill(Pi_phi);
      h_eta_reco_Pi->Fill(Pi_eta);
    }
    if(isK_reco == 1)
    {
      nK_reco+=1.;
      h_pT_reco_K->Fill(K_pT);
      h_phi_reco_K->Fill(K_phi);
      h_eta_reco_K->Fill(K_eta);
    }
    if(isSPi_reco == 1)
    {
      nSPi_reco+=1.;
      h_pT_reco_SPi->Fill(SPi_pT);
      h_phi_reco_SPi->Fill(SPi_phi);
      h_eta_reco_SPi->Fill(SPi_eta);
    }
    if(isPi_reco == 1 && isK_reco == 1)
    {
      nD0_reco+=1.;
      h_pT_reco_D0->Fill(D0_pT);
      h_phi_reco_D0->Fill(D0_phi);
      h_eta_reco_D0->Fill(D0_eta);
    }
    if((isPi_reco == 1 && isK_reco == 1) && isSPi_reco == 1)
    {
      nDst_reco+=1.;
      h_pT_reco_Dst->Fill(Dst_pT);
      h_phi_reco_D0->Fill(Dst_phi);
      h_eta_reco_D0->Fill(Dst_eta);
    }
    h_pT_Pi->Fill(Pi_pT);
    h_pT_SPi->Fill(SPi_pT);
    h_pT_K->Fill(K_pT);
    h_pT_D0->Fill(D0_pT);
    h_pT_Dst->Fill(Dst_pT);
    
    h_phi_Pi->Fill(Pi_phi);
    h_phi_SPi->Fill(SPi_phi);
    h_phi_K->Fill(K_phi);
    h_phi_D0->Fill(D0_phi);
    h_phi_Dst->Fill(Dst_phi);
    
    h_eta_Pi->Fill(Pi_eta);
    h_eta_SPi->Fill(SPi_eta);
    h_eta_K->Fill(K_eta);
    h_eta_D0->Fill(D0_eta);
    h_eta_Dst->Fill(Dst_eta);
  }
  h_pT_reco_Pi->Divide(h_pT_Pi);
  h_pT_reco_K->Divide(h_pT_K);
  h_pT_reco_SPi->Divide(h_pT_SPi);
  h_pT_reco_D0->Divide(h_pT_D0);
  h_pT_reco_Dst->Divide(h_pT_Dst);
  
  h_phi_reco_Pi->Divide(h_phi_Pi);
  h_phi_reco_K->Divide(h_phi_K);
  h_phi_reco_SPi->Divide(h_phi_SPi);
  h_phi_reco_D0->Divide(h_phi_D0);
  h_phi_reco_Dst->Divide(h_phi_Dst);
  
  h_eta_reco_Pi->Divide(h_eta_Pi);
  h_eta_reco_K->Divide(h_eta_K);
  h_eta_reco_SPi->Divide(h_eta_SPi);
  h_eta_reco_D0->Divide(h_eta_D0);
  h_eta_reco_Dst->Divide(h_eta_Dst);
  
  string output_hist_name;
  output_hist_name = "output/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");
  h_pT_reco_Pi->Write();
  h_pT_reco_K->Write();
  h_pT_reco_SPi->Write();
  h_pT_reco_D0->Write();
  h_pT_reco_Dst->Write();
  
  h_phi_reco_Pi->Write();
  h_phi_reco_K->Write();
  h_phi_reco_SPi->Write();
  h_phi_reco_D0->Write();
  h_phi_reco_Dst->Write();
 
  h_eta_reco_Pi->Write();
  h_eta_reco_K->Write();
  h_eta_reco_SPi->Write();
  h_eta_reco_D0->Write();
  h_eta_reco_Dst->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();
  
  cout << "Reconstructed number of pions: " << nPi_reco << ", eff.: " << nPi_reco/nEvents << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco << ", eff.: " << nK_reco/nEvents << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco << ", eff.: " << nSPi_reco/nEvents << endl;
  cout << "Reconstructed number of D0: " << nD0_reco << ", eff.: " << nD0_reco/nEvents << endl;
  cout << "Reconstructed number of D*: " << nDst_reco << ", eff.: " << nDst_reco/nEvents << endl;
}
