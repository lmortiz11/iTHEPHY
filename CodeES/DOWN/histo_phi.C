#define ntp_cxx
#include "histo_phi.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ntp::Loop()
   
{ 
    Int_t f=0;
    TH1* h1=new TH1D("h1", "sPi_PHI", 50,-4,4);
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
          
    if (sPi_Reconstructed==1)
    {
        h1->Fill(sPi_PHI);
        f++;
    }
   }
 for (int i=0; i<50; i++)
          {    Double_t c=h1->GetBinContent(i);
              h1->SetBinContent(i, c/f);
          }
     TCanvas *c1 = new TCanvas("c1","c1",800,1000);
 h1->Draw();
}
