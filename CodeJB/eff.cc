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

  double Dst_pT,D0_pT, Pi_pT, K_pT, SPi_pT;

  double Dst_phi, D0_phi, Pi_phi, K_phi, SPi_phi;

  double Dst_theta, D0_theta, Pi_theta, K_theta, SPi_theta;

  double Dst_eta, D0_eta, Pi_eta, K_eta, SPi_eta;

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

  ntp->SetBranchStatus("Dst_THETA",1); ntp->SetBranchAddress("Dst_THETA", &(Dst_theta));
  ntp->SetBranchStatus("D0_THETA",1); ntp->SetBranchAddress("D0_THETA", &(D0_theta));
  ntp->SetBranchStatus("P1_THETA",1); ntp->SetBranchAddress("P1_THETA", &(Pi_theta));
  ntp->SetBranchStatus("P2_THETA",1); ntp->SetBranchAddress("P2_THETA", &(K_theta));
  ntp->SetBranchStatus("sPi_THETA",1); ntp->SetBranchAddress("sPi_THETA", &(SPi_theta));

  ntp->SetBranchStatus("Dst_ETA",1); ntp->SetBranchAddress("Dst_ETA", &(Dst_eta));
  ntp->SetBranchStatus("D0_ETA",1); ntp->SetBranchAddress("D0_ETA", &(D0_eta));
  ntp->SetBranchStatus("P1_ETA",1); ntp->SetBranchAddress("P1_ETA", &(Pi_eta));
  ntp->SetBranchStatus("P2_ETA",1); ntp->SetBranchAddress("P2_ETA", &(K_eta));
  ntp->SetBranchStatus("sPi_ETA",1); ntp->SetBranchAddress("sPi_ETA", &(SPi_eta));



  TH1F *h_pT_reco_SPi = new TH1F("h_pT_reco_SPi", ";p_{T}/MeV; reconstructed Events", 175, 100., 800.);
  TH1F *h_pT_reco_Pi = new TH1F("h_pT_reco_Pi", ";p_{T}/MeV; reconstructed Events", 250, 700., 5700.);
  TH1F *h_pT_reco_K = new TH1F("h_pT_reco_K", ";p_{T}/MeV; reconstructed Events", 275, 700., 6200.);
  TH1F *h_pT_reco_D0 = new TH1F("h_pT_reco_D0", ";p_{T}/MeV; reconstructed Events", 350, 2000., 9000.);
  TH1F *h_pT_reco_Dst = new TH1F("h_pT_reco_Dst", ";p_{T}/MeV; reconstructed Events", 370, 2200., 9600.);
  TH1F *h_pT_SPi = new TH1F("h_pT_SPi", ";p_{T}/MeV;Events", 175, 100., 800.);
  TH1F *h_pT_Pi = new TH1F("h_pT_Pi", ";p_{T}/MeV;Events", 250, 700., 5700.);
  TH1F *h_pT_K = new TH1F("h_pT_K", ";p_{T}/MeV;Events", 275, 700., 6200.);
  TH1F *h_pT_D0 = new TH1F("h_pT_D0", ";p_{T}/MeV;Events", 350, 2000., 9000.);
  TH1F *h_pT_Dst = new TH1F("h_pT_Dst", ";p_{T}/MeV;Events", 370, 2200., 9600.);

  TH1F *h_phi_reco_SPi = new TH1F("h_phi_reco_SPi", ";#phi; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_Pi = new TH1F("h_phi_reco_Pi", ";#phi; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_K = new TH1F("h_phi_reco_K", ";#phi; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_D0 = new TH1F("h_phi_reco_D0", ";#phi; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_reco_Dst = new TH1F("h_phi_reco_Dst", ";#phi; reconstructed Events", 100, -3.5, 3.5);
  TH1F *h_phi_SPi = new TH1F("h_phi_SPi", ";#phi;Events", 100, -3.5, 3.5);
  TH1F *h_phi_Pi = new TH1F("h_phi_Pi", ";#phi;Events", 100, -3.5, 3.5);
  TH1F *h_phi_K = new TH1F("h_phi_K", ";#phi;Events", 100, -3.5, 3.5);
  TH1F *h_phi_D0 = new TH1F("h_phi_D0", ";#phi;Events", 100, -3.5, 3.5);
  TH1F *h_phi_Dst = new TH1F("h_phi_Dst", ";#phi;Events", 100, -3.5, 3.5);

  TH1F *h_eta_reco_SPi = new TH1F("h_eta_reco_SPi", ";#eta; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_Pi = new TH1F("h_eta_reco_Pi", ";#eta; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_K = new TH1F("h_eta_reco_K", ";#eta; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_D0 = new TH1F("h_eta_reco_D0", ";#eta; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_reco_Dst = new TH1F("h_eta_reco_Dst", ";#eta; reconstructed Events", 100, 2.0, 4.5);
  TH1F *h_eta_SPi = new TH1F("h_eta_SPi", ";#eta;Events", 100, 2.0, 4.5);
  TH1F *h_eta_Pi = new TH1F("h_eta_Pi", ";#eta;Events", 100, 2.0, 4.5);
  TH1F *h_eta_K = new TH1F("h_eta_K", ";#eta;Events", 100, 2.0, 4.5);
  TH1F *h_eta_D0 = new TH1F("h_eta_D0", ";#eta;Events", 100, 2.0, 4.5);
  TH1F *h_eta_Dst = new TH1F("h_eta_Dst", ";#eta;Events", 100, 2.0, 4.5);

  TH1F *h_theta_reco_SPi = new TH1F("h_theta_reco_SPi", ";#theta; reconstructed Events", 100, 0.02, 0.2);
  TH1F *h_theta_reco_Pi = new TH1F("h_theta_reco_Pi", ";#theta; reconstructed Events", 100, 0.02, 0.24);
  TH1F *h_theta_reco_K = new TH1F("h_theta_reco_K", ";#theta; reconstructed Events", 100, 0.02, 0.24);
  TH1F *h_theta_reco_D0 = new TH1F("h_theta_reco_D0", ";#theta; reconstructed Events", 100, 0.02, 0.2);
  TH1F *h_theta_reco_Dst = new TH1F("h_theta_reco_Dst", ";#theta; reconstructed Events", 100, 0.02, 0.2);
  TH1F *h_theta_SPi = new TH1F("h_theta_SPi", ";#theta;Events", 100, 0.02, 0.2);
  TH1F *h_theta_Pi = new TH1F("h_theta_Pi", ";#theta;Events", 100, 0.02, 0.24);
  TH1F *h_theta_K = new TH1F("h_theta_K", ";#theta;Events", 100, 0.02, 0.24);
  TH1F *h_theta_D0 = new TH1F("h_theta_D0", ";#theta;Events", 100, 0.02, 0.2);
  TH1F *h_theta_Dst = new TH1F("h_theta_Dst", ";#theta;Events", 100, 0.02, 0.2);

  for(int i = 0; i < nEvents; ++i)
  {
    ntp->GetEvent(i);
    if (i % (nEvents/10) == 0)cout << "=== Event " << i/(nEvents/10) * 10 << "%" << endl;
    if(isPi_reco == 1)
    {
      nPi_reco+=1.;
      h_pT_reco_Pi->Fill(Pi_pT);
      h_phi_reco_Pi->Fill(Pi_phi);
      h_theta_reco_Pi->Fill(Pi_theta);
      h_eta_reco_Pi->Fill(Pi_eta);
    }
    if(isK_reco == 1)
    {
      nK_reco+=1.;
      h_pT_reco_K->Fill(K_pT);
      h_phi_reco_K->Fill(K_phi);
      h_theta_reco_K->Fill(K_theta);
      h_eta_reco_K->Fill(K_eta);
    }
    if(isSPi_reco == 1)
    {
      nSPi_reco+=1.;
      h_pT_reco_SPi->Fill(SPi_pT);
      h_phi_reco_SPi->Fill(SPi_phi);
      h_theta_reco_SPi->Fill(SPi_theta);
      h_eta_reco_SPi->Fill(SPi_eta);
    }
    if(isPi_reco == 1 && isK_reco == 1)
    {
      nD0_reco+=1.;
      h_pT_reco_D0->Fill(D0_pT);
      h_phi_reco_D0->Fill(D0_phi);
      h_theta_reco_D0->Fill(D0_theta);
      h_eta_reco_D0->Fill(D0_eta);
    }
    if((isPi_reco == 1 && isK_reco == 1) && isSPi_reco == 1)
    {
      nDst_reco+=1.;
      h_pT_reco_Dst->Fill(Dst_pT);
      h_phi_reco_Dst->Fill(Dst_phi);
      h_theta_reco_Dst->Fill(Dst_theta);
      h_eta_reco_Dst->Fill(Dst_eta);
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

    h_theta_Pi->Fill(Pi_theta);
    h_theta_SPi->Fill(SPi_theta);
    h_theta_K->Fill(K_theta);
    h_theta_D0->Fill(D0_theta);
    h_theta_Dst->Fill(Dst_theta);

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

  h_theta_reco_Pi->Divide(h_theta_Pi);
  h_theta_reco_K->Divide(h_theta_K);
  h_theta_reco_SPi->Divide(h_theta_SPi);
  h_theta_reco_D0->Divide(h_theta_D0);
  h_theta_reco_Dst->Divide(h_theta_Dst);

  h_eta_reco_Pi->Divide(h_eta_Pi);
  h_eta_reco_K->Divide(h_eta_K);
  h_eta_reco_SPi->Divide(h_eta_SPi);
  h_eta_reco_D0->Divide(h_eta_D0);
  h_eta_reco_Dst->Divide(h_eta_Dst);

  string output_hist_name;
  output_hist_name = "output/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");
  h_pT_reco_Pi->Write("output/h_pT_reco_Pi.pdf");
  h_pT_reco_K->Write("output/h_pT_reco_K.pdf");
  h_pT_reco_SPi->Write("output/h_pT_reco_SPi.pdf");
  h_pT_reco_D0->Write("output/h_pT_reco_D0.pdf");
  h_pT_reco_Dst->Write("output/h_pT_reco_Dst.pdf");

  h_phi_reco_Pi->Write("output/h_phi_reco_Pi.pdf");
  h_phi_reco_K->Write("output/h_phi_reco_K.pdf");
  h_phi_reco_SPi->Write("output/h_phi_reco_SPi.pdf");
  h_phi_reco_D0->Write("output/h_phi_reco_D0.pdf");
  h_phi_reco_Dst->Write("output/h_phi_reco_Dst.pdf");

  h_theta_reco_Pi->Write();
  h_theta_reco_K->Write();
  h_theta_reco_SPi->Write();
  h_theta_reco_D0->Write();
  h_theta_reco_Dst->Write();

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

  TCanvas *c1 = new TCanvas();

  h_pT_reco_Pi->Draw();
  c1->SaveAs("output/h_pT_reco_Pi.pdf");
  h_pT_reco_K->Draw();
  c1->SaveAs("output/h_pT_reco_K.pdf");
  h_pT_reco_SPi->Draw();
  c1->SaveAs("output/h_pT_reco_SPi.pdf");
  h_pT_reco_D0->Draw();
  c1->SaveAs("output/h_pT_reco_D0.pdf");
  h_pT_reco_Dst->Draw();
  c1->SaveAs("output/h_pT_reco_Dst.pdf");

  h_phi_reco_Pi->Draw();
  c1->SaveAs("output/h_phi_reco_Pi.pdf");
  h_phi_reco_K->Draw();
  c1->SaveAs("output/h_phi_reco_K.pdf");
  h_phi_reco_SPi->Draw();
  c1->SaveAs("output/h_phi_reco_SPi.pdf");
  h_phi_reco_D0->Draw();
  c1->SaveAs("output/h_phi_reco_D0.pdf");
  h_phi_reco_Dst->Draw();
  c1->SaveAs("output/h_phi_reco_Dst.pdf");

  h_theta_reco_Pi->Draw();
  c1->SaveAs("output/h_theta_reco_Pi.pdf");
  h_theta_reco_K->Draw();
  c1->SaveAs("output/h_theta_reco_K.pdf");
  h_theta_reco_SPi->Draw();
  c1->SaveAs("output/h_theta_reco_SPi.pdf");
  h_theta_reco_D0->Draw();
  c1->SaveAs("output/h_theta_reco_D0.pdf");
  h_theta_reco_Dst->Draw();
  c1->SaveAs("output/h_theta_reco_Dst.pdf");

  h_eta_reco_Pi->Draw();
  c1->SaveAs("output/h_eta_reco_Pi.pdf");
  h_eta_reco_K->Draw();
  c1->SaveAs("output/h_eta_reco_K.pdf");
  h_eta_reco_SPi->Draw();
  c1->SaveAs("output/h_eta_reco_SPi.pdf");
  h_eta_reco_D0->Draw();
  c1->SaveAs("output/h_eta_reco_D0.pdf");
  h_eta_reco_Dst->Draw();
  c1->SaveAs("output/h_eta_reco_Dst.pdf");
}
