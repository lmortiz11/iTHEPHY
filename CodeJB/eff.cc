#include "eff.h"



void fill_hist(vector<TH1F*> v_hist, vector<TH1F*> v_hist_reco, vector<double> v_var, int is_reco)
{
  int size = v_hist.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist.at(i)->Fill(v_var.at(i));
    if(is_reco == 1)
    {
      v_hist_reco.at(i)->Fill(v_var.at(i));
    }
  }
}

void eff(string dir, string sample)
{
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain("ntp");
  ntp->Add(input_name.c_str());

  int nEvents = ntp->GetEntries();
  double n_pos = 0.;
  double n_neg = 0.;
  
  double nDst_reco = 0.;
  double nD0_reco = 0.;
  double nPi_reco = 0.;
  double nK_reco = 0.;
  double nSPi_reco = 0.;
/*
  double nDst_reco_pos = 0.;
  double nD0_reco_pos = 0.;
  double nPi_reco_pos = 0.;
  double nK_reco_pos = 0.;
  double nSPi_reco_pos = 0.;*/

  double Dst_pT, D0_pT, Pi_pT, K_pT, SPi_pT;

  double Dst_phi, D0_phi, Pi_phi, K_phi, SPi_phi;

  double Dst_theta, D0_theta, Pi_theta, K_theta, SPi_theta;

  double Dst_eta, D0_eta, Pi_eta, K_eta, SPi_eta;

  int Dst_ID, D0_ID, Pi_ID, K_ID, SPi_ID;

  int  isPi_reco, isK_reco, isSPi_reco, isD0_reco, isDst_reco;
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

  ntp->SetBranchStatus("Dst_ID",1); ntp->SetBranchAddress("Dst_ID", &(Dst_ID));
  ntp->SetBranchStatus("D0_ID",1); ntp->SetBranchAddress("D0_ID", &(D0_ID));
  ntp->SetBranchStatus("P1_ID",1); ntp->SetBranchAddress("P1_ID", &(Pi_ID));
  ntp->SetBranchStatus("P2_ID",1); ntp->SetBranchAddress("P2_ID", &(K_ID));
  ntp->SetBranchStatus("sPi_ID",1); ntp->SetBranchAddress("sPi_ID", &(SPi_ID));

  vector<double> v_Pi_var = {Pi_pT, Pi_phi, Pi_theta, Pi_eta}
  vector<double> v_K_var = {K_pT, K_phi, K_theta, K_eta}
  vector<double> v_SPi_var = {SPi_pT, SPi_phi, SPi_theta, SPi_eta}
  vector<double> v_D0_var = {D0_pT, D0_phi, D0_theta, D0_eta}
  vector<double> v_Dst_var = {Dst_pT, Dst_phi, Dst_theta, Dst_eta}
  

  TH1F *h_pT_reco_SPi = new TH1F("h_pT_reco_SPi", ";p_{T}/MeV; reconstructed Events", 35, 100., 800.);
  TH1F *h_pT_reco_Pi = new TH1F("h_pT_reco_Pi", ";p_{T}/MeV; reconstructed Events", 50, 700., 5700.);
  TH1F *h_pT_reco_K = new TH1F("h_pT_reco_K", ";p_{T}/MeV; reconstructed Events", 57, 700., 6200.);
  TH1F *h_pT_reco_D0 = new TH1F("h_pT_reco_D0", ";p_{T}/MeV; reconstructed Events", 70, 2000., 9000.);
  TH1F *h_pT_reco_Dst = new TH1F("h_pT_reco_Dst", ";p_{T}/MeV; reconstructed Events", 74, 2200., 9600.);
  TH1F *h_pT_SPi = new TH1F("h_pT_SPi", ";p_{T}/MeV;Events", 35, 100., 800.);
  TH1F *h_pT_Pi = new TH1F("h_pT_Pi", ";p_{T}/MeV;Events", 50, 700., 5700.);
  TH1F *h_pT_K = new TH1F("h_pT_K", ";p_{T}/MeV;Events", 57, 700., 6200.);
  TH1F *h_pT_D0 = new TH1F("h_pT_D0", ";p_{T}/MeV;Events", 70, 2000., 9000.);
  TH1F *h_pT_Dst = new TH1F("h_pT_Dst", ";p_{T}/MeV;Events", 74, 2200., 9600.);

  TH1F *h_phi_reco_SPi = new TH1F("h_phi_reco_SPi", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Pi = new TH1F("h_phi_reco_Pi", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_K = new TH1F("h_phi_reco_K", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_D0 = new TH1F("h_phi_reco_D0", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Dst = new TH1F("h_phi_reco_Dst", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_SPi = new TH1F("h_phi_SPi", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Pi = new TH1F("h_phi_Pi", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_K = new TH1F("h_phi_K", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_D0 = new TH1F("h_phi_D0", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Dst = new TH1F("h_phi_Dst", ";#phi;Events", 50, -3.5, 3.5);

  TH1F *h_eta_reco_SPi = new TH1F("h_eta_reco_SPi", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Pi = new TH1F("h_eta_reco_Pi", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_K = new TH1F("h_eta_reco_K", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_D0 = new TH1F("h_eta_reco_D0", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Dst = new TH1F("h_eta_reco_Dst", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_SPi = new TH1F("h_eta_SPi", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Pi = new TH1F("h_eta_Pi", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_K = new TH1F("h_eta_K", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_D0 = new TH1F("h_eta_D0", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Dst = new TH1F("h_eta_Dst", ";#eta;Events", 50, 2.0, 4.5);

  TH1F *h_theta_reco_SPi = new TH1F("h_theta_reco_SPi", ";#theta; reconstructed Events", 50, 0.02, 0.2);
  TH1F *h_theta_reco_Pi = new TH1F("h_theta_reco_Pi", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_K = new TH1F("h_theta_reco_K", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_D0 = new TH1F("h_theta_reco_D0", ";#theta; reconstructed Events", 50, 0.02, 0.2);
  TH1F *h_theta_reco_Dst = new TH1F("h_theta_reco_Dst", ";#theta; reconstructed Events", 50, 0.02, 0.2);
  TH1F *h_theta_SPi = new TH1F("h_theta_SPi", ";#theta;Events", 50, 0.02, 0.2);
  TH1F *h_theta_Pi = new TH1F("h_theta_Pi", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_K = new TH1F("h_theta_K", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_D0 = new TH1F("h_theta_D0", ";#theta;Events", 50, 0.02, 0.2);
  TH1F *h_theta_Dst = new TH1F("h_theta_Dst", ";#theta;Events", 50, 0.02, 0.2);
  h_pT_reco_Pi->Sumw2();
  h_pT_reco_K->Sumw2();
  h_pT_reco_SPi->Sumw2();
  h_pT_reco_D0->Sumw2();
  h_pT_reco_Dst->Sumw2();
  h_phi_reco_Pi->Sumw2();
  h_phi_reco_K->Sumw2();
  h_phi_reco_SPi->Sumw2();
  h_phi_reco_D0->Sumw2();
  h_phi_reco_Dst->Sumw2();
  h_theta_reco_Pi->Sumw2();
  h_theta_reco_K->Sumw2();
  h_theta_reco_SPi->Sumw2();
  h_theta_reco_D0->Sumw2();
  h_theta_reco_Dst->Sumw2();
  h_eta_reco_Pi->Sumw2();
  h_eta_reco_K->Sumw2();
  h_eta_reco_SPi->Sumw2();
  h_eta_reco_D0->Sumw2();
  h_eta_reco_Dst->Sumw2();
    
  vector<TH1F*> v_Pi_hist_reco = {h_pT_reco_Pi, h_phi_reco_Pi, h_theta_reco_Pi, h_eta_reco_Pi}
  vector<TH1F*> v_SPi_hist_reco = {h_pT_reco_SPi, h_phi_reco_SPi, h_theta_reco_SPi, h_eta_reco_SPi}
  vector<TH1F*> v_K_hist_reco = {h_pT_reco_K, h_phi_reco_K, h_theta_reco_K, h_eta_reco_K}
  vector<TH1F*> v_D0_hist_reco = {h_pT_reco_D0, h_phi_reco_D0, h_theta_reco_D0, h_eta_reco_D0}
  vector<TH1F*> v_Dst_hist_reco = {h_pT_reco_Dst, h_phi_reco_Dst, h_theta_reco_Dst, h_eta_reco_Dst}
  
  vector<TH1F*> v_Pi_hist = {h_pT_Pi, h_phi_Pi, h_theta_Pi, h_eta_Pi}
  vector<TH1F*> v_SPi_hist = {h_pT_SPi, h_phi_SPi, h_theta_SPi, h_eta_SPi}
  vector<TH1F*> v_K_hist = {h_pT_K, h_phi_K, h_theta_K, h_eta_K}
  vector<TH1F*> v_D0_hist = {h_pT_D0, h_phi_D0, h_theta_D0, h_eta_D0}
  vector<TH1F*> v_Dst_hist = {h_pT_Dst, h_phi_Dst, h_theta_Dst, h_eta_Dst}
  
  for(int i = 0; i < nEvents; ++i)
  {
    ntp->GetEvent(i);
    if (i % (nEvents/10) == 0)cout << "=== Event " << i/(nEvents/10) * 10 << "%" << endl;
    hist_fill(v_Pi_hist, v_Pi_hist_reco, v_Pi_var, isPi_reco);
    hist_fill(v_K_hist, v_K_hist_reco, v_K_var, isK_reco);
    hist_fill(v_SPi_hist, v_SPi_hist_reco, v_SPi_var, isSPi_reco);
    hist_fill(v_D0_hist, v_D0_hist_reco, v_D0_var, isD0_reco);
    hist_fill(v_Dst_hist, v_Dst_hist_reco, v_Dst_var, isDst_reco);
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

/*  cout << "Reconstructed number of pions: " << nPi_reco << ", eff.: " << nPi_reco/nEvents << " +/- " << sqrt( nPi_reco + pow(nPi_reco, 2.) / nEvents)/nEvents << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco << ", eff.: " << nK_reco/nEvents << " +/- " << sqrt( nK_reco + pow(nK_reco, 2.) / nEvents)/nEvents << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco << ", eff.: " << nSPi_reco/nEvents << " +/- " << sqrt( nSPi_reco + pow(nSPi_reco, 2.) / nEvents)/nEvents  << endl;
  cout << "Reconstructed number of D0: " << nD0_reco << ", eff.: " << nD0_reco/nEvents << " +/- " << sqrt( nD0_reco + pow(nD0_reco, 2.) / nEvents)/nEvents << endl;
  cout << "Reconstructed number of D*: " << nDst_reco << ", eff.: " << nDst_reco/nEvents << " +/- " << sqrt( nDst_reco + pow(nDst_reco, 2.) / nEvents)/nEvents  << endl;
*/
  cout << "Reconstructed number of pions: " << nPi_reco << ", eff.: " << nPi_reco/n_pos << " +/- " << sqrt( nPi_reco + pow(nPi_reco, 2.) / n_pos)/n_pos << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco << ", eff.: " << nK_reco/n_pos << " +/- " << sqrt( nK_reco + pow(nK_reco, 2.) / n_pos)/n_pos << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco << ", eff.: " << nSPi_reco/n_pos << " +/- " << sqrt( nSPi_reco + pow(nSPi_reco, 2.) / n_pos)/n_pos  << endl;
  cout << "Reconstructed number of D0: " << nD0_reco << ", eff.: " << nD0_reco/n_pos << " +/- " << sqrt( nD0_reco + pow(nD0_reco, 2.) / n_pos)/n_pos << endl;
  cout << "Reconstructed number of D*: " << nDst_reco << ", eff.: " << nDst_reco/n_pos << " +/- " << sqrt( nDst_reco + pow(nDst_reco, 2.) / n_pos)/n_pos  << endl;


  TCanvas *c1 = new TCanvas();

  gStyle->SetOptStat(0);

  h_pT_reco_Pi->Draw();
  h_pT_reco_Pi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_pT_reco_Pi.pdf");
  h_pT_reco_K->Draw();
  h_pT_reco_K->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_pT_reco_K.pdf");
  h_pT_reco_SPi->Draw();
  h_pT_reco_SPi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_pT_reco_SPi.pdf");
  h_pT_reco_D0->Draw();
  h_pT_reco_D0->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_pT_reco_D0.pdf");
  h_pT_reco_Dst->Draw();
  h_pT_reco_Dst->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_pT_reco_Dst.pdf");

  h_phi_reco_Pi->Draw();
  h_phi_reco_Pi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_phi_reco_Pi.pdf");
  h_phi_reco_K->Draw();
  h_phi_reco_K->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_phi_reco_K.pdf");
  h_phi_reco_SPi->Draw();
  h_phi_reco_SPi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_phi_reco_SPi.pdf");
  h_phi_reco_D0->Draw();
  h_phi_reco_D0->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_phi_reco_D0.pdf");
  h_phi_reco_Dst->Draw();
  h_phi_reco_Dst->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_phi_reco_Dst.pdf");

  h_theta_reco_Pi->Draw();
  h_theta_reco_Pi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_theta_reco_Pi.pdf");
  h_theta_reco_K->Draw();
  h_theta_reco_K->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_theta_reco_K.pdf");
  h_theta_reco_SPi->Draw();
  h_theta_reco_SPi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_theta_reco_SPi.pdf");
  h_theta_reco_D0->Draw();
  h_theta_reco_D0->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_theta_reco_D0.pdf");
  h_theta_reco_Dst->Draw();
  h_theta_reco_Dst->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_theta_reco_Dst.pdf");

  h_eta_reco_Pi->Draw();
  h_eta_reco_Pi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_eta_reco_Pi.pdf");
  h_eta_reco_K->Draw();
  h_eta_reco_K->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_eta_reco_K.pdf");
  h_eta_reco_SPi->Draw();
  h_eta_reco_SPi->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_eta_reco_SPi.pdf");
  h_eta_reco_D0->Draw();
  h_eta_reco_D0->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_eta_reco_D0.pdf");
  h_eta_reco_Dst->Draw();
  h_eta_reco_Dst->Draw("hist same");
  c1->SaveAs("output/up_pdf/h_eta_reco_Dst.pdf");
}
