#define ntp_cxx
#include "pos.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cmath>

void ntp::Loop()
{ Double_t P1_pos=0;
  Double_t P1_neg=0;
 Double_t P1_rec=0;
 
 Double_t P2_pos=0;
  Double_t P2_neg=0;
 Double_t P2_rec=0;
 
 Double_t sPi_pos=0;
  Double_t sPi_neg=0;
 Double_t sPi_rec=0;
 
 Double_t D0_pos=0;
  Double_t D0_neg=0;
 Double_t D0_rec=0;
 
 Double_t Dst_pos=0;
  Double_t Dst_neg=0;
 Double_t Dst_rec=0;
 


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
if (Dst_Reconstructed==1)
{
   Dst_rec++; 
    if (Dst_ID>0)
{
   Dst_pos++; 
}
if (Dst_ID<0)
{
   Dst_neg++;
} 
}  
       
if (D0_Reconstructed==1)
{
   D0_rec++; 
    if (D0_ID>0)
{
   D0_pos++; 
}
if (D0_ID<0)
{
   D0_neg++;
} 
}  
     
if (P2_Reconstructed==1)
{
   P2_rec++; 
    if (P2_ID>0)
{
   P2_pos++; 
}
if (P2_ID<0)
{
   P2_neg++;
} 
}  
       
if (P1_Reconstructed==1)
{
   P1_rec++; 
    if (P1_ID>0)
{
   P1_pos++; 
}
if (P1_ID<0)
{
   P1_neg++;
} 
}  
       
if (sPi_Reconstructed==1)
{
   sPi_rec++; 
    if (sPi_ID>0)
{
   sPi_pos++; 
}
if (sPi_ID<0)
{
   sPi_neg++;
} 
}         
      

      
      // if (Cut(ientry) < 0) continue;
   }

    Double_t c=nentries; 
 

       
    Double_t eff_P1_pos=P1_pos/c;
    Double_t eff_P1_neg=P1_neg/c;
 
    Double_t eff_P2_pos=P2_pos/c;
    Double_t eff_P2_neg=P2_neg/c;
 
    Double_t eff_sPi_pos=sPi_pos/c;
    Double_t eff_sPi_neg=sPi_neg/c;
 
    /*Double_t eff_D0_pos=D0_pos/nentries;
    Double_t eff_D0_neg=D0_neg/nentries;
 
    Double_t eff_Dst_pos=Dst_pos/nentries;
    Double_t eff_Dst_neg=Dst_neg/nentries;*/
 
    // print the number of recontructed events for each particle;
    Double_t P1_pos_err=(1/c)*sqrt(P1_pos*(c-P1_pos)/c);
    Double_t P1_neg_err=(1/c)*sqrt(P1_neg*(c-P1_neg)/c);
 
    Double_t P2_pos_err=(1/c)*sqrt(P2_pos*(c-P2_pos)/c);
    Double_t P2_neg_err=(1/c)*sqrt(P2_neg*(c-P2_neg)/c);
 
    Double_t sPi_pos_err=(1/c)*sqrt(sPi_pos*(c-sPi_pos)/c);
    Double_t sPi_neg_err=(1/c)*sqrt(sPi_neg*(c-sPi_neg)/c);
 
    /*Double_t D0_pos_err=(1/nentries)*sqrt(D0_pos*(nentries-D0_pos)/nentries);
    Double_t D0_neg_err=(1/nentries)*sqrt(D0_neg*(nentries-D0_neg)/nentries);
 
    Double_t Dst_pos_err=(1/nentries)*sqrt(Dst_pos*(nentries-Dst_pos)/nentries);
    Double_t Dst_neg_err=(1/nentries)*sqrt(Dst_neg*(nentries-Dst_neg)/nentries);*/
 
    // print the number of recontructed events for each particle;
    
    
    
    cout<<"Pions pos efficiency: "<< eff_P1_pos<<" +- "<< P1_pos_err  <<'\n';
    cout<<"Pions neg efficiency: "<< eff_P1_neg<<" +- "<< P1_neg_err  <<'\n';
    cout<<"Kaons pos efficiency: "<<eff_P2_pos <<" +- "<< P2_pos_err<<'\n';
    cout<<"Kaons neg efficiency: "<<eff_P2_neg <<" +- "<< P2_neg_err<<'\n';
    cout<<"Soft Pions pos efficiency: "<<eff_sPi_pos<<" +- "<< sPi_pos_err<<'\n';
    cout<<"Soft Pions neg efficiency: "<<eff_sPi_neg<<" +- "<< sPi_neg_err<<'\n';
    
   /* cout<<"D0 pos efficiency: "<<eff_D0_pos <<" +- "<< D0_pos_err<<'\n';
    cout<<"D0 neg efficiency: "<<eff_D0_neg <<" +- "<< D0_neg_err<<'\n';
    cout<<"D*+ pos efficiency: "<<eff_Dst_pos <<" +- "<< Dst_pos_err<<'\n';
    cout<<"D*+ neg efficiency: "<<eff_Dst_neg <<" +- "<< Dst_neg_err<<'\n';*/
        
 
 
 
 
 
 
 
 
 
 
 
}
