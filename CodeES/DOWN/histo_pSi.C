#define ntp_cxx
#include "histo_pSi.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ntp::Loop()
   
{ 
    

    
    TH1* h1_phi_rec=new TH1D("h1", "sPi_PHI_reco", 50,-4,4);
    TH1* h2_phi=new TH1D("h2", "sPi_PHI", 50,-4,4);
    
    TH1* h1_eta_rec=new TH1D("h1", "sPi_eta_reco", 50,0,5);
    TH1* h2_eta=new TH1D("h2", "sPi_eta", 50,0,5);
    
    TH1* h1_pt_rec=new TH1D("h1", "sPi_PT_reco", 50,0,900);
    TH1* h2_pt=new TH1D("h1", "sPi_PT_reco", 50,0,900);
    
    TH1* h1_theta_rec=new TH1D("h1", "sPi_THETA_reco", 50,0,0.2);
    TH1* h2_theta=new TH1D("h1", "sPi_THETA_reco", 50,0,0.2);
    
    
    
//   In a ROOT session, you can do:
//      root> .L ntp.C
//      root> ntp t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
 
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
    
       
    h2_phi->Fill(sPi_PHI);
    h2_eta->Fill(sPi_ETA);
    h2_pt->Fill(sPi_PT);
    h2_theta->Fill(sPi_THETA);
    
       if (sPi_Reconstructed==1)
    {
        h1_phi_rec->Fill(sPi_PHI);
        h1_eta_rec->Fill(sPi_ETA);    
        h1_pt_rec->Fill(sPi_PT);
        h1_theta_rec->Fill(sPi_THETA);
    }
       
   }
    
    
TH1 *h3_phi = (TH1*)h1_phi_rec->Clone("h3_phi"); h3_phi->Divide(h1_phi_rec,h2_phi);
TH1 *h3_eta = (TH1*)h1_eta_rec->Clone("h3_eta"); h3_eta->Divide(h1_eta_rec,h2_eta);
TH1 *h3_pt = (TH1*)h1_pt_rec->Clone("h3_pt"); h3_pt->Divide(h1_pt_rec,h2_pt);
TH1 *h3_theta = (TH1*)h1_theta_rec->Clone("h3_theta"); h3_theta->Divide(h1_theta_rec,h2_theta);

TCanvas * c1= new TCanvas("c1","c1",400,10,600,400);
c1->Divide(2,2);
c1->cd(1);
h3_phi->Draw();
c1->cd(2);
h3_eta->Draw(); 
c1->cd(3);
h3_pt->Draw(); 
c1->cd(4);
h3_theta->Draw(); 
    
    
    
    
    
}
