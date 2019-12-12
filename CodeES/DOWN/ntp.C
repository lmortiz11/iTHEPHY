#define ntp_cxx
#include "ntp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <cmath>

void ntp::Loop()
{
    Double_t p1_rec=0;
    Double_t p2_rec=0;
    Double_t spi_rec=0;
    Double_t D0_rec=0;
    Double_t Dst_rec=0;
    Double_t c=0;
    

    
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
    
       
// here starts what i've done: just counting the number of events reconstructed for each particle;
       
       if (P1_Reconstructed==1)
       {
        p1_rec++;
       };
       
       if (P2_Reconstructed==1)
       {
        p2_rec++;
       };
       
       if (sPi_Reconstructed==1)
       {
        spi_rec++;
       };
      
       if (P1_Reconstructed==1 && P2_Reconstructed==1)
       {
        D0_rec++;
       };
      
       if (P1_Reconstructed==1 && P2_Reconstructed==1 && sPi_Reconstructed==1)
       {
        Dst_rec++;
       };
       
      // if (Cut(ientry) < 0) continue;
       
     c++;  
       
   }
    Double_t eff_p1=p1_rec/c;
    Double_t eff_p2=p2_rec/c;
    Double_t eff_spi=spi_rec/c;
    Double_t eff_D0=D0_rec/c;
    Double_t eff_Dst=Dst_rec/c;
    // print the number of recontructed events for each particle;
    Double_t p1_err=(1/c)*sqrt(p1_rec*(c-p1_rec)/c);
    Double_t p2_err=(1/c)*sqrt(p2_rec*(c-p2_rec)/c);
    Double_t spi_err=(1/c)*sqrt(spi_rec*(c-spi_rec)/c);
    Double_t D0_err=(1/c)*sqrt(D0_rec*(c-D0_rec)/c);
    Double_t Dst_err=(1/c)*sqrt(Dst_rec*(c-Dst_rec)/c);
    // print the number of recontructed events for each particle;
    
    cout << "pions: "<<p1_rec<<'\n'<<"kaons: "<<p2_rec<<'\n'<<"soft pions: "<<spi_rec<<'\n'<<"D0: "<<D0_rec<<'\n'<<"D*+: "<<Dst_rec<<endl;
    
    
    cout<<"Pions efficiency: "<< eff_p1<<" +- "<< p1_err  <<'\n';
    cout<<"Kaons efficiency: "<<eff_p2 <<" +- "<< p2_err<<'\n';
    cout<<"Soft Pions efficiency: "<<eff_spi<<" +- "<< spi_err<<'\n';
    cout<<"D0 efficiency: "<<eff_D0 <<" +- "<< D0_err<<'\n';
    cout<<"D0 efficiency: "<<eff_D0 <<'\n';
    cout<<"D*+ efficiency: "<<eff_Dst <<" +- "<< Dst_err<<'\n';
        
}
