
#include <TFile.h>
#include <TH1D.h>
#include <TRandom3.h>
#include <TTree.h>
#include <cmath>
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include <TH1F.h>
#include <TH2F.h>

void eff()
{
   
   TChain *ntp = new TChain("ntp");
   ntp->Add("minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  
   Long64_t nentries = ntp->GetEntries();

   float nPi_recons=0.;
   float nK_recons=0;
   float nsPi_recons=0;
   float nD0_recons=0;
   float nDst_recons=0; 
   
   float nPi_recons_p=0.;
   float nK_recons_p=0;
   float nsPi_recons_p=0;
   float nD0_recons_p=0;
   float nDst_recons_p=0;

   float nPi_recons_n=0.;
   float nK_recons_n=0;
   float nsPi_recons_n=0;
   float nD0_recons_n=0;
   float nDst_recons_n=0;

 

   float n_Pi_p=0;
   float n_K_p=0;
   float n_sPi_p=0;
   float n_D0_p=0;
   float n_Dst_p=0;

   float n_Pi_n=0;
   float n_K_n=0;
   float n_sPi_n=0;
   float n_D0_n=0;
   float n_Dst_n=0;

   Int_t  Pi_recons, K_recons, sPi_recons, Pi_ID, K_ID,sPi_ID, D0_ID,Dst_ID;
   double Dst_ETA, Dst_PHI, Dst_PT, Dst_THETA;
   double D0_ETA, D0_PHI, D0_PT, D0_THETA;
   double P1_ETA, P1_PHI, P1_PT, P1_THETA;
   double P2_ETA, P2_PHI, P2_PT, P2_THETA;
   double sPi_ETA, sPi_PHI, sPi_PT, sPi_THETA;

 

   //Disable all the Branches
   ntp->SetBranchStatus("*",0);
   //Activate branchesname
   ntp->SetBranchStatus("P1_Reconstructed",1);
   ntp->SetBranchAddress("P1_Reconstructed", &(Pi_recons));
   ntp->SetBranchStatus("P2_Reconstructed",1);
   ntp->SetBranchAddress("P2_Reconstructed", &(K_recons));
   ntp->SetBranchStatus("sPi_Reconstructed",1);
   ntp->SetBranchAddress("sPi_Reconstructed", &(sPi_recons));

   ntp->SetBranchStatus("Dst_ETA",1);
   ntp->SetBranchAddress("Dst_ETA", &(Dst_ETA));
   ntp->SetBranchStatus("Dst_PHI",1);
   ntp->SetBranchAddress("Dst_PHI", &(Dst_PHI));
   ntp->SetBranchStatus("Dst_PT",1);
   ntp->SetBranchAddress("Dst_PT", &(Dst_PT));
   ntp->SetBranchStatus("Dst_THETA",1);
   ntp->SetBranchAddress("Dst_THETA", &(Dst_THETA));

   ntp->SetBranchStatus("D0_ETA",1);
   ntp->SetBranchAddress("D0_ETA", &(D0_ETA));
   ntp->SetBranchStatus("D0_PHI",1);
   ntp->SetBranchAddress("D0_PHI", &(D0_PHI));
   ntp->SetBranchStatus("D0_PT",1);
   ntp->SetBranchAddress("D0_PT", &(D0_PT));
   ntp->SetBranchStatus("D0_THETA",1);
   ntp->SetBranchAddress("D0_THETA", &(D0_THETA));

   ntp->SetBranchStatus("P1_ETA",1);
   ntp->SetBranchAddress("P1_ETA", &(P1_ETA));
   ntp->SetBranchStatus("P1_PHI",1);
   ntp->SetBranchAddress("P1_PHI", &(P1_PHI));
   ntp->SetBranchStatus("P1_PT",1);
   ntp->SetBranchAddress("P1_PT", &(P1_PT));
   ntp->SetBranchStatus("P1_THETA",1);
   ntp->SetBranchAddress("P1_THETA", &(P1_THETA));

   ntp->SetBranchStatus("P2_ETA",1);
   ntp->SetBranchAddress("P2_ETA", &(P2_ETA));
   ntp->SetBranchStatus("P2_PHI",1);
   ntp->SetBranchAddress("P2_PHI", &(P2_PHI));
   ntp->SetBranchStatus("P2_PT",1);
   ntp->SetBranchAddress("P2_PT", &(P2_PT));
   ntp->SetBranchStatus("P2_THETA",1);
   ntp->SetBranchAddress("P2_THETA", &(P2_THETA));

   ntp->SetBranchStatus("sPi_ETA",1);
   ntp->SetBranchAddress("sPi_ETA", &(sPi_ETA));
   ntp->SetBranchStatus("sPi_PHI",1);
   ntp->SetBranchAddress("sPi_PHI", &(sPi_PHI));
   ntp->SetBranchStatus("sPi_PT",1);
   ntp->SetBranchAddress("sPi_PT", &(sPi_PT));
   ntp->SetBranchStatus("sPi_THETA",1);
   ntp->SetBranchAddress("sPi_THETA", &(sPi_THETA));
   
      
   
   ntp->SetBranchStatus("P1_ID",1);
   ntp->SetBranchAddress("P1_ID",& (Pi_ID));
   ntp->SetBranchStatus("P2_ID",1);
   ntp->SetBranchAddress("P2_ID",& (K_ID));
   ntp->SetBranchStatus("sPi_ID",1);
   ntp->SetBranchAddress("sPi_ID",& (sPi_ID));
   ntp->SetBranchStatus("D0_ID",1);
   ntp->SetBranchAddress("D0_ID",& (D0_ID));
   ntp->SetBranchStatus("Dst_ID",1);
   ntp->SetBranchAddress("Dst_ID",& (Dst_ID));
   ntp->SetBranchStatus("sPi_PT",1);
   ntp->SetBranchAddress("sPi_PT", & (sPi_PT));

  
  

   //Book histograms
   
   //Soft pion
   
   TH1F* sPi_Preco_phi=new TH1F("h1", "sPi_Preco_Phi", 50,-4,4);
   TH1F* sPi_p_phi=new TH1F("h2", "sPi_p_Phi", 50,-4,4);
   TH1F* sPi_Nrec_phi=new TH1F("h1", "sPi_Nrec_Phi", 50,-4,4);
   TH1F* sPi_n_phi=new TH1F("h2", "sPi_n_Phi", 50,-4,4);
    
   TH1F* sPi_Prec_eta=new TH1F("h1", "sPi_Prec_eta", 50,0,5);
   TH1* sPi_p_eta=new TH1F("h2", "sPi_p_eta", 50,0,5);
   TH1F* sPi_Nrec_eta=new TH1F("h1", "sPi_Nrec_eta", 50,0,5);
   TH1* sPi_n_eta=new TH1F("h2", "sPi_eta_neg", 50,0,5);
    
   TH1F* sPi_Prec_pt=new TH1F("h1", "sPi_Prec_PT", 50,0,900);
   TH1* sPi_p_pt=new TH1F("h1", "sPi_p_PT", 50,0,900);
   TH1F* sPi_Nrec_pt=new TH1F("h1", "sPi_Nreco_PT", 50,0,900);
   TH1* sPi_n_pt=new TH1F("h1", "sPi_n_PT", 50,0,900);
    
   TH1F* sPi_Prec_theta=new TH1F("h1", "sPi_Prec_Theta", 50,0,0.2);
   TH1F* sPi_p_theta=new TH1F("h2", "sPi_p_Theta", 50,0,0.2);
   TH1F* sPi_Nrec_theta=new TH1F("h1", "sPi_Nrec_Theta", 50,0,0.2);
   TH1F* sPi_n_theta=new TH1F("h2", "sPi_n_Theta", 50,0,0.2);
   
//------------Pion---------------- 
 
   TH1F* pi_Prec_phi=new TH1F("h1", "Pi_Prec_Phi", 50,-4,4);
   TH1F* pi_p_phi=new TH1F("h2", "Pi_p_Phi", 50,-4,4);
   TH1F* pi_Nrec_phi=new TH1F("h1", "Pi_Nrec_Phi", 50,-4,4);
   TH1F* pi_n_phi=new TH1F("h2", "Pi_n_Phi", 50,-4,4);
 
    
   TH1F* pi_Prec_eta=new TH1F("h1", "Pi_Prec_eta", 50,0,5);
   TH1* pi_p_eta=new TH1F("h2", "Pi_p_eta", 50,0,5);
   TH1F* pi_Nrec_eta=new TH1F("h1", "Pi_Nrec_eta", 50,0,5);
   TH1* pi_n_eta=new TH1F("h2", "Pi_n_eta", 50,0,5);
    
   TH1F* pi_Prec_pt=new TH1F("h1", "Pi_Prec_PT", 50,0,6000);
   TH1* pi_p_pt=new TH1F("h2", "Pi_p_PT", 50,0,6000);
   TH1F* pi_Nrec_pt=new TH1F("h1", "Pi_Nrec_PT", 50,0,6000);
   TH1* pi_n_pt=new TH1F("h2", "Pi_n_PT", 50,0,6000);
    
   TH1* pi_Prec_theta=new TH1F("h1", "Pi_Prec_Theta", 50,0,0.3);
   TH1F* pi_p_theta=new TH1F("h2", "Pi_p_Theta", 50,0,0.3);
   TH1* pi_Nrec_theta=new TH1F("h1", "Pi_Nrec_Theta", 50,0,0.5);
   TH1F* pi_n_theta=new TH1F("h2", "Pi_n_Theta", 50,0,0.5);
//---------------kaon--------------
 
   TH1F* K_Prec_phi=new TH1F("h1", "K_Prec_Phi", 50,-4,4);
   TH1F* K_p_phi=new TH1F("h2", "K_p_Phi", 50,-4,4);
   TH1F* K_Nrec_phi=new TH1F("h1", "K__Nrec_Phi", 50,-4,4);
   TH1F* K_n_phi=new TH1F("h2", "K_n_Phi", 50,-4,4);
    
   TH1F* K_Prec_eta=new TH1F("h1", "K_Prec_eta", 50,0,5);
   TH1* K_p_eta=new TH1F("h2", "K_p_eta", 50,0,5);
   TH1F* K_Nrec_eta=new TH1F("h1", "K_Nrec_eta", 50,0,5);
   TH1* K_n_eta=new TH1F("h2", "K_n_eta", 50,0,5);
    
   TH1F* K_Prec_pt=new TH1F("h1", "K_Prec_PT", 50,0,9000);
   TH1* K_p_pt=new TH1F("h2", "K_p_PT", 50,0,9000);
   TH1F* K_Nrec_pt=new TH1F("h1", "K_Nrec_PT", 50,0,9000);
   TH1* K_n_pt=new TH1F("h2", "K_n_PT", 50,0,9000);
    
   TH1F* K_Prec_theta=new TH1F("h1", "K_Prec_Theta", 50,0,0.3);
   TH1F* K_p_theta=new TH1F("h2", "K_p_Theta", 50,0,0.3);
   TH1F* K_Nrec_theta=new TH1F("h1", "K_Nrec_Theta", 50,0,0.5);
   TH1F* K_n_theta=new TH1F("h2", "K_n_Theta", 50,0,0.5);
 
 //-----------------D0----------
 
   TH1F* D0_Prec_phi=new TH1F("h1", "D0_Prec_phi", 50,-4,4);
   TH1F* D0_p_phi=new TH1F("h2", "D0_p_phi", 50,-4,4);
   TH1F* D0_Nrec_phi=new TH1F("h1", "D0_Nrec_phi", 50,-4,4);
   TH1F* D0_n_phi=new TH1F("h2", "D0_n_phi", 50,-4,4);
    
   TH1F* D0_Prec_eta=new TH1F("h1", "DO_Prec_eta", 50,0,5);
   TH1* D0_p_eta=new TH1F("h2", "D0_p_eta", 50,0,5);
   TH1F* D0_Nrec_eta=new TH1F("h1", "DO_Nrec_eta", 50,0,5);
   TH1* D0_n_eta=new TH1F("h2", "D0_n_eta", 50,0,5);
    
   TH1F* D0_Prec_pt=new TH1F("h1", "D0_Prec_PT", 50,0,9000);
   TH1* D0_p_pt=new TH1F("h2", "D0_p_PT", 50,0,9000);
   TH1F* D0_Nrec_pt=new TH1F("h1", "D0_Nrec_PT", 50,0,9000);
   TH1* D0_n_pt=new TH1F("h2", "D0_n_PT", 50,0,9000);
    
    
   TH1F* D0_Prec_theta=new TH1F("h1", "D0_Prec_Theta", 50,0,0.2);
   TH1F* D0_p_theta=new TH1F("h2", "D0_p_Theta", 50,0,0.2);
   TH1F* D0_Nrec_theta=new TH1F("h1", "D0_Nrec_Theta", 50,0,0.2);
   TH1F* D0_n_theta=new TH1F("h2", "D0_n_Theta", 50,0,0.2);
 
 //----------------Dst------------
 
   TH1F* Dst_Prec_phi=new TH1F("h1", "Dst_Prec_phi", 50,-4,4);
   TH1F* Dst_p_phi=new TH1F("h2", "Dst_p_phi", 50,-4,4);
   TH1F* Dst_Nrec_phi=new TH1F("h1", "Dst_Nrec_phi", 50,-4,4);
   TH1F* Dst_n_phi=new TH1F("h2", "Dst_n_phi", 50,-4,4);
    
   TH1F* Dst_Prec_eta=new TH1F("h1", "Dst_Prec_eta", 50,0,5);
   TH1* Dst_p_eta=new TH1F("h2", "Dst_p_eta", 50,0,5);
   TH1F* Dst_Nrec_eta=new TH1F("h1", "Dst_Nrec_eta", 50,0,5);
   TH1* Dst_n_eta=new TH1F("h2", "Dst_n_eta", 50,0,5);
    
   TH1F* Dst_Prec_pt=new TH1F("h1", "Dst_Prec_PT", 50,0,10000);
   TH1* Dst_p_pt=new TH1F("h2", "Dst_p_PT", 50,0,10000);
   TH1F* Dst_Nrec_pt=new TH1F("h1", "Dst_Nrec_PT", 50,0,10000);
   TH1* Dst_n_pt=new TH1F("h2", "Dst_n_PT", 50,0,10000);
 
    
   TH1F* Dst_Prec_theta=new TH1F("h1", "Dst_Prec_Theta", 50,0,0.2);
   TH1F* Dst_p_theta=new TH1F("h2", "Dst_p_Theta", 50,0,0.2);
   TH1F* Dst_Nrec_theta=new TH1F("h1", "Dst_Nrec_Theta", 50,0,0.2);
   TH1F* Dst_n_theta=new TH1F("h2", "Dst_n_Theta", 50,0,0.2);
   
   
   //Loop for all events
   for(Int_t entry=0;entry<nentries; ++entry){
    ntp->GetEntry(entry);
    //Count the number of pions reconstructed
    if(Pi_recons==1) nPi_recons+=1;
    //Count the number of kaons reconstructed
    if(K_recons==1) nK_recons+=1;
    //Count the number of soft pions reconstructed
    if(sPi_recons==1)nsPi_recons+=1;
    //Count the number of D0 recontructed
    if(K_recons==1 && Pi_recons==1) nD0_recons+=1;
    //Count the number of D* reconstructed
    if(K_recons==1 && Pi_recons==1 && sPi_recons==1) nDst_recons+=1;
    
    //////////For positive charge//////////////
    
    //Count the number of positive pions reconstructed
    if(Pi_recons==1 && Pi_ID>0 )
      { nPi_recons_p+=1;
	
	pi_Prec_theta->Fill(P1_THETA); 
	pi_Prec_pt->Fill(P1_PT);  
	pi_Prec_phi->Fill(P1_PHI);  
	pi_Prec_eta->Fill(P1_ETA);
      }
   
   
    
    //Count the number of possitive kaons reconstructed
    if(K_recons==1 && K_ID>0)
      { nK_recons_p+=1;
	 K_Prec_theta->Fill(P2_THETA);
	 K_Prec_pt->Fill(P2_PT);
	 K_Prec_phi->Fill(P2_PHI);       
	 K_Prec_eta->Fill(P2_ETA);
      }
    //Count the number of positive soft pions reconstructed
    if(sPi_recons==1 && sPi_ID>0)
      { nsPi_recons_p+=1;
	sPi_Prec_pt->Fill(sPi_PT);
	sPi_Preco_phi->Fill(sPi_PHI);
	sPi_Prec_eta->Fill(sPi_ETA);
	sPi_Prec_theta->Fill(sPi_THETA);
      }
    
    //Count the number of positive D0 recontructed
    if(K_recons==1 && Pi_recons==1 && D0_ID>0 )
      { nD0_recons_p+=1;
	D0_Prec_phi->Fill(D0_PHI);
	D0_p_eta->Fill(D0_ETA);
	D0_Prec_pt->Fill(D0_PT);
	D0_Prec_theta->Fill(D0_THETA);
      }
    //Count the number of positive D* reconstructed
    if(K_recons==1 && Pi_recons==1 && sPi_recons==1 && Dst_ID>0)
      {
	 nDst_recons_p+=1;
	 Dst_Prec_eta->Fill(Dst_ETA);
	 Dst_Prec_phi->Fill(Dst_PHI);
	 Dst_Prec_pt->Fill(Dst_PT);
	 Dst_Prec_theta->Fill(Dst_THETA);
      } 
    
    //////////For negative charge//////////////
    
    //Count the number of negative  pions reconstructed
    if(Pi_recons==1 && Pi_ID<0 )
      { nPi_recons_n+=1;
	 pi_Nrec_eta->Fill(P1_ETA);
	 pi_Nrec_phi->Fill(P1_PHI);      
	 pi_Nrec_pt->Fill(P1_PT);
	 pi_Nrec_theta->Fill(P1_THETA);
      }
    
    //Count the number of negative kaons reconstructed
    if(K_recons==1 && K_ID<0)
      { nK_recons_n+=1;
	K_Nrec_eta->Fill(P2_ETA);
	K_Nrec_phi->Fill(P2_PHI);      
	K_Nrec_pt->Fill(P2_PT);
	K_Nrec_theta->Fill(P2_THETA);
      }
    
    //Count the number of negative soft pions reconstructed
    if(sPi_recons==1 && sPi_ID<0)
      { nsPi_recons_n+=1;
	sPi_Nrec_eta->Fill(sPi_ETA);
	sPi_Nrec_phi->Fill(sPi_PHI);
	sPi_Nrec_pt->Fill(sPi_PT);
	sPi_Nrec_theta->Fill(sPi_THETA);
      }
    
    //Count the number of negative D0 recontructed
    if(K_recons==1 && Pi_recons==1 && D0_ID<0 )
      { nD0_recons_n+=1;
        D0_Nrec_phi->Fill(D0_PHI);
	D0_Nrec_eta->Fill(D0_ETA);
	D0_Nrec_pt->Fill(D0_PT);
	D0_Nrec_theta->Fill(D0_THETA);
      }
    //Count the number of negative D* reconstructed
    if(K_recons==1 && Pi_recons==1 && sPi_recons==1 && Dst_ID<0)
      { nDst_recons_n+=1;
	Dst_Nrec_eta->Fill(Dst_ETA);
	Dst_Nrec_phi->Fill(Dst_PHI);
	Dst_Nrec_pt->Fill(Dst_PT);
	Dst_Nrec_theta->Fill(Dst_THETA);
      }

    //Positive entrance
    // float n_Pi_p=0;
    if (Pi_ID>0)
      { n_Pi_p+=1;
	pi_p_theta->Fill(P1_THETA); 
	pi_p_pt->Fill(P1_PT);  
	pi_p_phi->Fill(P1_PHI);  
	pi_p_eta->Fill(P1_ETA);
      }

    // float n_K_p=0;
    if (K_ID>0)
      { n_K_p+=1;
	K_p_theta->Fill(P2_THETA);
	K_p_pt->Fill(P2_PT);
	K_p_phi->Fill(P2_PHI);       
	K_p_eta->Fill(P2_ETA);
      }
    //soft pion
    if (sPi_ID>0)
      { n_sPi_p+=1;
	sPi_p_pt->Fill(sPi_PT);
	sPi_p_phi->Fill(sPi_PHI);
	sPi_p_eta->Fill(sPi_ETA);
	sPi_p_theta->Fill(sPi_THETA);
      }	

   
    //float n_D0_p=0;
    if (D0_ID>0)
      { n_D0_p+=1;
        D0_p_phi->Fill(D0_PHI);
	D0_p_eta->Fill(D0_ETA);
	D0_p_pt->Fill(D0_PT);
	D0_p_theta->Fill(D0_THETA);
      }
    
    //float n_Dst_p=0;
    if (Dst_ID>0)
      { n_Dst_p+=1;
	Dst_p_phi->Fill(Dst_PHI);
	Dst_p_eta->Fill(Dst_ETA);
        Dst_p_pt->Fill(Dst_PT);
	Dst_p_theta->Fill(Dst_THETA);
      }
	

     //Negative entrance
    
    //float n_Pi_n=0;
    if (Pi_ID<0)
      { n_Pi_n+=1;
	pi_n_eta->Fill(P1_ETA);
	pi_n_phi->Fill(P1_PHI);      
	pi_n_pt->Fill(P1_PT);
	pi_n_theta->Fill(P1_THETA);
      }

    //float n_K_n=0;
    if (K_ID<0)
      { n_K_n+=1;
	K_n_eta->Fill(P2_ETA);
	K_n_phi->Fill(P2_PHI);      
	K_n_pt->Fill(P2_PT);
	K_n_theta->Fill(P2_THETA);
      }

    //soft pion
    if (sPi_ID>0)
      { n_sPi_n+=1;
        sPi_n_eta->Fill(sPi_ETA);
	sPi_n_phi->Fill(sPi_PHI);
	sPi_n_pt->Fill(sPi_PT);
	sPi_n_theta->Fill(sPi_THETA);
      }
	
    

    //float n_D0_n=0;
    if (D0_ID<0)
      { n_D0_n+=1;
        D0_n_phi->Fill(D0_PHI);
	D0_n_eta->Fill(D0_ETA);
	D0_n_pt->Fill(D0_PT);
	D0_n_theta->Fill(D0_THETA);
      }

    //float n_Dst_n=0;
    if (Dst_ID<0)
      { n_Dst_n+=1;
	Dst_n_eta->Fill(Dst_ETA);
	Dst_n_phi->Fill(Dst_PHI);
	Dst_n_pt->Fill(Dst_PT);
	Dst_n_theta->Fill(Dst_THETA);
      }
		   
   
    
 
  }
  

   

   //Total efficiencies
   float Pi_eff=nPi_recons/nentries;
   float K_eff = nK_recons/nentries;
   float sPi_eff= nsPi_recons/nentries;
   float D0_eff = nD0_recons/nentries;
   float Dst_eff =nDst_recons/nentries;

   float Pi_eff_error=sqrt(nPi_recons*(nentries-nPi_recons)/pow(nentries,3));
   float K_eff_error=sqrt(nK_recons*(nentries-nK_recons)/pow(nentries,3));
   float sPi_eff_error=sqrt(nsPi_recons*(nentries-nsPi_recons)/pow(nentries,3));
   float D0_eff_error =sqrt(nD0_recons*(nentries-nD0_recons)/pow(nentries,3));
   float Dst_eff_error =sqrt(nDst_recons*(nentries-nDst_recons)/pow(nentries,3));
   

   //Efficiencies for positive charge
   float Pi_p_eff =nPi_recons_p/n_Pi_p;
   float K_p_eff= nK_recons_p/n_K_p;
   float sPi_p_eff= nsPi_recons_p/n_sPi_p;
   float D0_p_eff= nD0_recons_p/n_D0_p;
   float Dst_p_eff = nDst_recons_p/n_Dst_p;

   float Pi_p_eff_error=sqrt(nPi_recons_p*(n_Pi_p-nPi_recons_p)/pow(n_Pi_p,3));
   float K_p_eff_error=sqrt(nK_recons_p*(n_K_p-nK_recons_p)/pow(n_K_p,3));
   float sPi_p_eff_error=sqrt(nsPi_recons_p*(n_sPi_p-nsPi_recons_p)/pow(n_sPi_p,3));
   float D0_p_eff_error =sqrt(nD0_recons_p*(n_D0_p-nD0_recons_p)/pow(n_D0_p,3));
   float Dst_p_eff_error =sqrt(nDst_recons_p*(n_Dst_p-nDst_recons_p)/pow(n_Dst_p,3));
   

   //Efficiencies and errors for negative charge
   float Pi_n_eff =nPi_recons_n/n_Pi_n;
   float K_n_eff= nK_recons_n/n_K_n;
   float sPi_n_eff= nsPi_recons_n/n_sPi_n;
   float D0_n_eff= nD0_recons_n/n_D0_n;
   float Dst_n_eff = nDst_recons_n/n_Dst_n;

   float Pi_n_eff_error=sqrt(nPi_recons_n*(n_Pi_n-nPi_recons_n)/pow(n_Pi_n,3));
   float K_n_eff_error=sqrt(nK_recons_n*(n_K_n-nK_recons_n)/pow(n_K_n,3));
   float sPi_n_eff_error=sqrt(nsPi_recons_n*(n_sPi_n-nsPi_recons_n)/pow(n_sPi_n,3));
   float D0_n_eff_error =sqrt(nD0_recons_n*(n_D0_n-nD0_recons_n)/pow(n_D0_n,3));
   float Dst_n_eff_error =sqrt(nDst_recons_n*(n_Dst_n-nDst_recons_n)/pow(n_Dst_n,3));
   ///////////////////////
   // deviation
   float Pim =Pi_p_eff -Pi_n_eff;
   float Pip =Pi_p_eff +Pi_n_eff;
   float pi_des= Pim/Pip;

   float sPim =sPi_p_eff -sPi_n_eff;
   float sPip =sPi_p_eff +sPi_n_eff;
   float spi_des= sPim/sPip;

   float kp= K_p_eff +K_n_eff;
   float km= K_p_eff -K_n_eff;
   float k_des=km/kp;

   float D0p= D0_p_eff +D0_n_eff;
   float D0m=D0_p_eff -D0_n_eff;
   float D0_des= D0m/D0p;

   float Dstp=Dst_p_eff +Dst_n_eff;
   float Dstm= Dst_p_eff -Dst_n_eff;
   float Dst_des= Dstm/Dstp;

   //errors
   float Pi_des_error=2*sqrt(pow(( Pi_p_eff*Pi_n_eff_error),2)+pow((Pi_n_eff*Pi_p_eff_error),2))/(Pi_p_eff+Pi_n_eff);

   float sPi_des_error=2*sqrt(pow(( sPi_p_eff*sPi_n_eff_error),2)+pow((sPi_n_eff*sPi_p_eff_error),2))/(sPi_p_eff+sPi_n_eff);

    float K_des_error=2*sqrt(pow(( K_p_eff*K_n_eff_error),2)+pow((K_n_eff*K_p_eff_error),2))/(K_p_eff+K_n_eff);

    float D0_des_error=2*sqrt(pow(( D0_p_eff*D0_n_eff_error),2)+pow((D0_n_eff*D0_p_eff_error),2))/(D0_p_eff+D0_n_eff);

    float Dst_des_error=2*sqrt(pow(( Dst_p_eff*Dst_n_eff_error),2)+pow((Dst_n_eff*Dst_p_eff_error),2))/(Dst_p_eff+Dst_n_eff);

   
     


   ///////////////

  cout << "Number of Events: "<< nentries<< endl;
  cout<<"npi_recons"<<nPi_recons<<endl;
  cout <<"Pion Efficieny: "<<Pi_eff <<"+-"<<Pi_eff_error<< endl;
  cout <<"Soft Pion Efficieny: "<<sPi_eff <<"+-"<<sPi_eff_error<< endl;
  cout << "Kaon Efficiency: " << K_eff <<"+-"<<K_eff_error<< endl;
  cout << "D0 Efficiency: " << D0_eff << "+-"<<D0_eff_error<<endl;
  cout << "Dst Efficiency: " << Dst_eff << "+-"<<Dst_eff_error<<endl;
  cout <<"-------------Positive-----------"<<endl;
  cout << "Positive Pion  Eff:"<< Pi_p_eff<<"+-"<<Pi_p_eff_error<<endl;
  cout << "Positive Soft Pion  Eff:"<< sPi_p_eff<<"+-"<<sPi_p_eff_error<<endl;
  cout << "Positive kaon  Eff:"<< K_p_eff<<"+-"<<K_p_eff_error<<endl;
  cout << "Positive D0  Eff:"<< D0_p_eff<<"+-"<<D0_p_eff_error<<endl;		  cout << "Positive Dst  Eff:"<< Dst_p_eff<<"+-"<<Dst_p_eff_error<<endl;
  cout <<"------Negative--------------"<<endl;
  cout << "Negative Pion  Eff:"<< Pi_n_eff<<"+-"<<Pi_n_eff_error<<endl;
  cout << "Negative Soft Pion  Eff:"<< sPi_n_eff<<"+-"<<sPi_n_eff_error<<endl;
  cout << "Negative kaon  Eff:"<< K_n_eff<<"+-"<<K_n_eff_error<<endl;
  cout << " NegativeD0  Eff:"<< D0_n_eff<<"+-"<<D0_n_eff_error<<endl;
  cout<<n_Dst_n<<endl;
  cout << "Negative Dst  Eff:"<< Dst_n_eff<<"+-"<<Dst_n_eff_error<<endl;

  cout<<"------desviations------"<<endl;
  cout<<"pion deviation : "<<pi_des<<"+-"<< Pi_des_error<<endl;
  cout<<"Soft pion deviation : "<<spi_des<<"+-"<< sPi_des_error<<endl;
  cout<<"Kaon deviation : "<<k_des<<"+-"<< K_des_error<<endl;
  cout<<"D0 deviation : "<<D0_des<<"+-"<< D0_des_error<<endl;
  cout<<"Dst deviation : "<<Dst_des<<"+-"<< Dst_des_error<<endl;

pi_Prec_phi->Sumw2();
pi_p_phi->Sumw2();
pi_Nrec_phi->Sumw2();
pi_n_phi->Sumw2();
    
pi_Prec_eta->Sumw2();
pi_p_eta->Sumw2();
pi_Nrec_eta->Sumw2();
pi_n_eta->Sumw2();
    
pi_Prec_pt->Sumw2();
pi_p_pt->Sumw2();
pi_Nrec_pt->Sumw2();
pi_n_pt->Sumw2();
    
pi_Prec_theta->Sumw2();
pi_p_theta->Sumw2();
pi_Nrec_theta->Sumw2();
pi_n_theta->Sumw2();
// -------------
K_Prec_phi->Sumw2();
K_p_phi->Sumw2();
K_Nrec_phi->Sumw2();
K_n_phi->Sumw2();
    
K_Prec_eta->Sumw2();
K_p_eta->Sumw2();
K_Nrec_eta->Sumw2();
K_n_eta->Sumw2();
    
K_Prec_pt->Sumw2();
K_p_pt->Sumw2();
K_Nrec_pt->Sumw2();
K_n_pt->Sumw2();
    
K_Prec_theta->Sumw2();
K_p_theta->Sumw2();
K_Nrec_theta->Sumw2();
K_n_theta->Sumw2();
//-------------------
  
sPi_Preco_phi->Sumw2();
sPi_p_phi->Sumw2();
sPi_Nrec_phi->Sumw2();
sPi_n_phi->Sumw2();
    
sPi_Prec_eta->Sumw2();
sPi_p_eta->Sumw2();
sPi_Nrec_eta->Sumw2();
sPi_n_eta->Sumw2();
    
sPi_Prec_pt->Sumw2();
sPi_p_pt->Sumw2();
sPi_Nrec_pt->Sumw2();
sPi_n_pt->Sumw2();
    
sPi_Prec_theta->Sumw2();
sPi_p_theta->Sumw2();
sPi_Nrec_theta->Sumw2();
sPi_n_theta->Sumw2(); 
//---------------------- 

D0_Prec_phi->Sumw2();
D0_p_phi->Sumw2();
D0_Nrec_phi->Sumw2();
D0_n_phi->Sumw2();
    
D0_Prec_eta->Sumw2();
D0_p_eta->Sumw2();
D0_Nrec_eta->Sumw2();
D0_n_eta->Sumw2();
    
D0_Prec_pt->Sumw2();
D0_p_pt->Sumw2();
D0_Nrec_pt->Sumw2();
D0_n_pt->Sumw2();
    
D0_Prec_theta->Sumw2();
D0_p_theta->Sumw2();
D0_Nrec_theta->Sumw2();
D0_n_theta->Sumw2(); 
//----------------------
Dst_Prec_phi->Sumw2();
Dst_p_phi->Sumw2();
Dst_Nrec_phi->Sumw2();
Dst_n_phi->Sumw2();
    
Dst_Prec_eta->Sumw2();
Dst_p_eta->Sumw2();
Dst_Nrec_eta->Sumw2();
Dst_n_eta->Sumw2();
    
Dst_Prec_pt->Sumw2();
Dst_p_pt->Sumw2();
Dst_Nrec_pt->Sumw2();
Dst_n_pt->Sumw2();
    
Dst_Prec_theta->Sumw2();
Dst_p_theta->Sumw2();
Dst_Nrec_theta->Sumw2();
Dst_n_theta->Sumw2(); 
//---------------------- 

 
TH1F *h3_sPi_p_phi = (TH1F*)sPi_Preco_phi->Clone("h3_phi_pos"); h3_sPi_p_phi->Divide(sPi_Preco_phi,sPi_p_phi);
 TH1F *h3_sPi_n_phi = (TH1F*)sPi_Nrec_phi->Clone("h3_phi_neg"); h3_sPi_n_phi->Divide(sPi_Nrec_phi,sPi_n_phi);
 
 TH1F *h3_sPi_p_eta = (TH1F*)sPi_Prec_eta->Clone("h3_sPi_p_eta"); h3_sPi_p_eta->Divide(sPi_Prec_eta,sPi_p_eta);
 TH1F *h3_sPi_n_eta = (TH1F*)sPi_Nrec_eta->Clone("h3_sPi_n_eta"); h3_sPi_n_eta->Divide(sPi_Nrec_eta,sPi_n_eta);

 TH1F *h3_sPi_p_pt = (TH1F*)sPi_Prec_pt->Clone("h3_sPi_p_pt"); h3_sPi_p_pt->Divide(sPi_Prec_pt,sPi_p_pt);
  TH1F *h3_sPi_n_pt = (TH1F*)sPi_Nrec_pt->Clone("h3_sPi_n_pt"); h3_sPi_n_pt->Divide(sPi_Nrec_pt,sPi_n_pt);

 TH1F *h3_sPi_p_theta = (TH1F*)sPi_Prec_theta->Clone("h3_sPi_p_theta"); h3_sPi_p_theta->Divide(sPi_Prec_theta,sPi_p_theta);
 TH1F *h3_sPi_n_theta = (TH1F*)sPi_Nrec_theta->Clone("h3_sPi_n_theta"); h3_sPi_n_theta->Divide(sPi_Nrec_theta,sPi_n_theta);
  
 //---------------
 TH1F *h3_pi_p_phi = (TH1F*)pi_Prec_phi->Clone("h3_pi_p_phi"); h3_pi_p_phi->Divide(pi_Prec_phi,pi_p_phi);
 TH1F *h3_pi_n_phi = (TH1F*)pi_Nrec_phi->Clone("h3_pi_n_phi"); h3_pi_n_phi->Divide(pi_Nrec_phi,pi_n_phi);
 
 TH1F *h3_pi_p_eta = (TH1F*)pi_Prec_eta->Clone("h3_pi_p_eta"); h3_pi_p_eta->Divide(pi_Prec_eta,pi_p_eta);
 TH1F *h3_pi_n_eta = (TH1F*)pi_Nrec_eta->Clone("h3_pi_n_eta"); h3_pi_n_eta->Divide(pi_Nrec_eta,pi_n_eta);

  TH1F *h3_pi_p_pt = (TH1F*)pi_Prec_pt->Clone("h3_pi_p_pt"); h3_pi_p_pt->Divide(pi_Prec_pt,pi_p_pt);
  TH1F *h3_pi_n_pt = (TH1F*)pi_Nrec_pt->Clone("h3_pi_n_pt"); h3_pi_n_pt->Divide(pi_Nrec_pt,pi_n_pt);

 TH1F *h3_pi_p_theta = (TH1F*)pi_Prec_theta->Clone("h3_pi_p_theta"); h3_pi_p_theta->Divide(pi_Prec_theta,pi_p_theta);
 TH1F *h3_pi_n_theta = (TH1F*)pi_Nrec_theta->Clone("h3_pi_n_theta"); h3_pi_n_theta->Divide(pi_Nrec_theta,pi_n_theta);
 //---------
  TH1F *h3_K_p_phi = (TH1F*)K_Prec_phi->Clone("h3_K_p_phi"); h3_K_p_phi->Divide(K_Prec_phi,K_p_phi);
 TH1F *h3_K_n_phi = (TH1F*)K_Nrec_phi->Clone("h3_K_n_phi"); h3_K_n_phi->Divide(K_Nrec_phi,K_n_phi);
 
 TH1F *h3_K_p_eta = (TH1F*)K_Prec_eta->Clone("h3_K_p_eta"); h3_K_p_eta->Divide(K_Prec_eta,K_p_eta);
 TH1F *h3_K_n_eta = (TH1F*)K_Nrec_eta->Clone("h3_K_n_eta"); h3_K_n_eta->Divide(K_Nrec_eta,K_n_eta);

 TH1F *h3_K_p_pt = (TH1F*)K_Prec_pt->Clone("h3_K_p_pt"); h3_K_p_pt->Divide(K_Prec_pt,K_p_pt);
  TH1F *h3_K_n_pt = (TH1F*)K_Nrec_pt->Clone("h3_K_n_pt"); h3_K_n_pt->Divide(K_Nrec_pt,K_n_pt);

 TH1F *h3_K_p_theta = (TH1F*)K_Prec_theta->Clone("h3_K_p_theta"); h3_K_p_theta->Divide(K_Prec_theta,K_p_theta);
 TH1F *h3_K_n_theta = (TH1F*)K_Nrec_theta->Clone("h3_K_n_theta"); h3_K_n_theta->Divide(K_Nrec_theta,K_n_theta);
 
 //-----------------
  TH1F *h3_D0_p_phi = (TH1F*)D0_Prec_phi->Clone("h3_D0_p_phi"); h3_D0_p_phi->Divide(D0_Prec_phi,D0_p_phi);
 TH1F *h3_D0_n_phi = (TH1F*)D0_Nrec_phi->Clone("h3_D0_n_phi"); h3_D0_n_phi->Divide(D0_Nrec_phi,D0_n_phi);
 
 TH1F *h3_D0_p_eta = (TH1F*)D0_Prec_eta->Clone("h3_D0_Prec_eta"); h3_D0_p_eta->Divide(D0_Prec_eta,D0_p_eta);
 TH1F *h3_D0_n_eta = (TH1F*)D0_Nrec_eta->Clone("h3_D0_n_eta"); h3_D0_n_eta->Divide(D0_Nrec_eta,D0_n_eta);

 TH1F *h3_D0_p_pt = (TH1F*)D0_Prec_pt->Clone("h3_D0_p_pt"); h3_D0_p_pt->Divide(D0_Prec_pt,D0_p_pt);
  TH1F *h3_D0_n_pt = (TH1F*)D0_Nrec_pt->Clone("h3_D0_n_pt"); h3_D0_n_pt->Divide(D0_Nrec_pt,D0_n_pt);

 TH1F *h3_D0_p_theta = (TH1F*)D0_Prec_theta->Clone("h3_D0_p_theta"); h3_D0_p_theta->Divide(D0_Prec_theta,D0_p_theta);
 TH1F *h3_D0_n_theta = (TH1F*)D0_Nrec_theta->Clone("h3_D0_n_theta"); h3_D0_n_theta->Divide(D0_Nrec_theta,D0_n_theta);
 
 
//--------
 
   TH1F *h3_Dst_p_phi = (TH1F*)Dst_Prec_phi->Clone("h3_Dst_p_phi"); h3_Dst_p_phi->Divide(Dst_Prec_phi,Dst_p_phi);
 TH1F *h3_Dst_n_phi = (TH1F*)Dst_Nrec_phi->Clone("h3_Dst_n_phi"); h3_Dst_n_phi->Divide(Dst_Nrec_phi,Dst_n_phi);
 
 TH1F *h3_Dst_p_eta = (TH1F*)Dst_Prec_eta->Clone("h3_Dst_p_eta"); h3_Dst_p_eta->Divide(Dst_Prec_eta,Dst_p_eta);
 TH1F *h3_Dst_n_eta = (TH1F*)Dst_Nrec_eta->Clone("h3_Dst_n_eta"); h3_Dst_n_eta->Divide(Dst_Nrec_eta,Dst_n_eta);

 TH1F *h3_Dst_p_pt = (TH1F*)Dst_Prec_pt->Clone("h3_Dst_p_pt"); h3_Dst_p_pt->Divide(Dst_Prec_pt,Dst_p_pt);
  TH1F *h3_Dst_n_pt = (TH1F*)Dst_Nrec_pt->Clone("h3_Dst_n_pt"); h3_Dst_n_pt->Divide(Dst_Nrec_pt,Dst_n_pt);

 TH1F *h3_Dst_p_theta = (TH1F*)Dst_Prec_theta->Clone("h3_Dst_p_theta"); h3_Dst_p_theta->Divide(Dst_Prec_theta,Dst_p_theta);
 TH1F *h3_Dst_n_theta = (TH1F*)Dst_Nrec_theta->Clone("h3_Dst_n_theta"); h3_Dst_n_theta->Divide(Dst_Nrec_theta,Dst_n_theta);

 //////////////////////////////
 pi_Prec_phi->Add(pi_Nrec_phi,-1);
 pi_Nrec_phi->Add(pi_Prec_phi,-1);
 pi_Prec_phi->Divide(pi_Nrec_phi);

 pi_Prec_eta->Add(pi_Nrec_eta,-1);
 pi_Nrec_eta->Add(pi_Prec_eta,-1);
 pi_Prec_eta->Divide(pi_Nrec_eta);

 pi_Prec_pt->Add(pi_Nrec_pt,-1);
 pi_Nrec_pt->Add(pi_Prec_pt,-1);
 pi_Prec_pt->Divide(pi_Nrec_pt);

 pi_Prec_theta->Add(pi_Nrec_theta,-1);
 pi_Nrec_theta->Add(pi_Prec_theta,-1);
 pi_Prec_theta->Divide(pi_Nrec_theta);
 //
 K_Prec_phi->Add(K_Nrec_phi,-1);
 K_Nrec_phi->Add(K_Prec_phi,-1);
 K_Prec_phi->Divide(K_Nrec_phi);

 K_Prec_eta->Add(K_Nrec_eta,-1);
 K_Nrec_eta->Add(K_Prec_eta,-1);
 K_Prec_eta->Divide(K_Nrec_eta);

 K_Prec_pt->Add(K_Nrec_pt,-1);
 K_Nrec_pt->Add(K_Prec_pt,-1);
 K_Prec_pt->Divide(K_Nrec_pt);

 K_Prec_theta->Add(K_Nrec_theta,-1);
 K_Nrec_theta->Add(K_Prec_theta,-1);
 K_Prec_theta->Divide(K_Nrec_theta);
 //
 sPi_Preco_phi->Add(sPi_Nrec_phi,-1);
 sPi_Nrec_phi->Add(sPi_Preco_phi,-1);
 sPi_Preco_phi->Divide(sPi_Nrec_phi);

 sPi_Prec_eta->Add(sPi_Nrec_eta,-1);
 sPi_Nrec_eta->Add(sPi_Prec_eta,-1);
 sPi_Prec_eta->Divide(sPi_Nrec_eta);

 sPi_Prec_pt->Add(sPi_Nrec_pt,-1);
 sPi_Nrec_pt->Add(sPi_Prec_pt,-1);
 sPi_Prec_pt->Divide(sPi_Nrec_pt);

 sPi_Prec_theta->Add(sPi_Nrec_theta,-1);
 sPi_Nrec_theta->Add(sPi_Prec_theta,-1);
 sPi_Prec_theta->Divide(sPi_Nrec_theta);
 //
 D0_Prec_phi->Add(D0_Nrec_phi,-1);
 D0_Nrec_phi->Add(D0_Prec_phi,-1);
 D0_Prec_phi->Divide(D0_Nrec_phi);

 D0_Prec_eta->Add(D0_Nrec_eta,-1);
 D0_Nrec_eta->Add(D0_Prec_eta,-1);
 D0_Prec_eta->Divide(D0_Nrec_eta);

 D0_Prec_pt->Add(D0_Nrec_pt,-1);
 D0_Nrec_pt->Add(D0_Prec_pt,-1);
 D0_Prec_pt->Divide(D0_Nrec_pt);

 D0_Prec_theta->Add(D0_Nrec_theta,-1);
 D0_Nrec_theta->Add(D0_Prec_theta,-1);
 D0_Prec_theta->Divide(D0_Nrec_theta);
 //
 Dst_Prec_phi->Add(Dst_Nrec_phi,-1);
 Dst_Nrec_phi->Add(Dst_Prec_phi,-1);
 Dst_Prec_phi->Divide(Dst_Nrec_phi);

 Dst_Prec_eta->Add(Dst_Nrec_eta,-1);
 Dst_Nrec_eta->Add(Dst_Prec_eta,-1);
 Dst_Prec_eta->Divide(Dst_Nrec_eta);

 Dst_Prec_pt->Add(Dst_Nrec_pt,-1);
 Dst_Nrec_pt->Add(Dst_Prec_pt,-1);
 Dst_Prec_pt->Divide(Dst_Nrec_pt);

 Dst_Prec_theta->Add(Dst_Nrec_theta,-1);
 Dst_Nrec_theta->Add(Dst_Prec_theta,-1);
 Dst_Prec_theta->Divide(Dst_Nrec_theta);
 
 //////////////////////////////
 
 
TCanvas *sPi_Precons= new TCanvas("sPi_Precons","sPi_Precons",400,10,600,400);
  sPi_Precons->Print("sPi.pdf(","pdf");
sPi_Precons->Divide(2,2);
 sPi_Precons->cd(1);

h3_sPi_p_phi->Draw("E");
h3_sPi_p_phi->Draw("hist same");

 sPi_Precons->cd(2);
h3_sPi_p_eta->Draw("E"); 
h3_sPi_p_eta->Draw("hist same"); 

 sPi_Precons->cd(3);
h3_sPi_p_pt->Draw("E"); 
h3_sPi_p_pt->Draw("hist same");
 
 sPi_Precons->cd(4);
h3_sPi_p_theta->Draw("E"); 
h3_sPi_p_theta->Draw("hist same");
 sPi_Precons->Print("sPi.pdf","pdf");
 
 
TCanvas * sPi_Nrecons= new TCanvas("sPi_Nrecons","sPi_Nrecons",400,10,600,400);
sPi_Nrecons->Divide(2,2);
sPi_Nrecons->cd(1);
h3_sPi_n_phi->Draw("E");
h3_sPi_n_phi->Draw("hist same"); 
sPi_Nrecons->cd(2);
h3_sPi_n_eta->Draw("E"); 
h3_sPi_n_eta->Draw("hist same"); 
 
sPi_Nrecons->cd(3);
h3_sPi_n_pt->Draw("E"); 
h3_sPi_n_pt->Draw("hist same"); 
 
sPi_Nrecons->cd(4);
h3_sPi_n_theta->Draw("E"); 
h3_sPi_n_theta->Draw("hist same");
 
 sPi_Nrecons->Print("sPi.pdf)","pdf");
 
 //--------
 
 
  TCanvas * Pi_Precon= new TCanvas("Pi_Precon","Pi_Precon",400,10,600,400);
   Pi_Precon->Print("Pi.pdf(","pdf");
Pi_Precon->Divide(2,2);
Pi_Precon->cd(1);
h3_pi_p_phi->Draw("E");
h3_pi_p_phi->Draw("hist same");
 
Pi_Precon->cd(2);
h3_pi_p_eta->Draw("E"); 
h3_pi_p_eta->Draw("hist same"); 
 
Pi_Precon->cd(3);
h3_pi_p_pt->Draw("E"); 
h3_pi_p_pt->Draw("hist same"); 
 
Pi_Precon->cd(4);
h3_pi_p_theta->Draw("E"); 
h3_pi_p_theta->Draw("hist same"); 
 Pi_Precon->Print("Pi.pdf","pdf");
 
TCanvas * Pi_Nrecons= new TCanvas("Pi_Nrecons","Pi_Nrecons",400,10,600,400);
Pi_Nrecons->Divide(2,2);
Pi_Nrecons->cd(1);
h3_pi_n_phi->Draw("A");
h3_pi_n_phi->Draw("hist same");
 
Pi_Nrecons->cd(2);
h3_pi_n_eta->Draw("E"); 
h3_pi_n_eta->Draw("hist same"); 
 
Pi_Nrecons->cd(3);
h3_pi_n_pt->Draw("E"); 
h3_pi_n_pt->Draw("hist same"); 
 
Pi_Nrecons->cd(4);
h3_pi_n_theta->Draw("E"); 
h3_pi_n_theta->Draw("hist same");
 Pi_Nrecons->Print("Pi.pdf)","pdf");


  //-------
   TCanvas * K_Precons= new TCanvas("K_Precons","K_Precons",400,10,600,400);
   K_Precons->Print("K.pdf(","pdf");
K_Precons->Divide(2,2);
K_Precons->cd(1);
h3_K_p_phi->Draw("E");
h3_K_p_phi->Draw("hist same");
 
K_Precons->cd(2);
h3_K_p_eta->Draw("E"); 
h3_K_p_eta->Draw("hist same"); 
 
K_Precons->cd(3);
h3_K_p_pt->Draw("E");
h3_K_p_pt->Draw("hist same"); 
 
K_Precons->cd(4);
h3_K_p_theta->Draw("E"); 
h3_K_p_theta->Draw("hist same");
 K_Precons->Print("K.pdf","pdf");
 
TCanvas * K_Nrecons= new TCanvas("K_Nrecons","K_Nrecons",400,10,600,400);
K_Nrecons->Divide(2,2);
K_Nrecons->cd(1);
h3_K_n_phi->Draw("E");
h3_K_n_phi->Draw("hist same");
 
K_Nrecons->cd(2);
h3_K_n_eta->Draw("E"); 
h3_K_n_eta->Draw("hist same"); 
 
K_Nrecons->cd(3);
h3_K_n_pt->Draw("E"); 
h3_K_n_pt->Draw("hist same"); 
 
K_Nrecons->cd(4);
h3_K_n_theta->Draw("E"); 
h3_K_n_theta->Draw("hist same");
 K_Nrecons->Print("K.pdf)","pdf");
 
 
 //-----
 
TCanvas * D0_Precons= new TCanvas("D0_Precons","D0_Precons",400,10,600,400);
 D0_Precons->Print("D0.pdf(","pdf");
D0_Precons->Divide(2,2);
D0_Precons->cd(1);
h3_D0_p_phi->Draw("E");
h3_D0_p_phi->Draw("hist same");
 
D0_Precons->cd(2);
h3_D0_p_eta->Draw("E"); 
h3_D0_p_eta->Draw("hist same"); 
 
D0_Precons->cd(3);
h3_D0_p_pt->Draw("E"); 
h3_D0_p_pt->Draw("hist same"); 
 
D0_Precons->cd(4);
h3_D0_p_theta->Draw("E"); 
h3_D0_p_theta->Draw("hist same");
 D0_Precons->Print("D0.pdf","pdf");
 
 
TCanvas * D0_Nrecons= new TCanvas("D0_Nrecons","D0_Nrecons",400,10,600,400);
D0_Nrecons->Divide(2,2);
D0_Nrecons->cd(1);
h3_D0_n_phi->Draw("E");
h3_D0_n_phi->Draw("hist same");
 
D0_Nrecons->cd(2);
h3_D0_n_eta->Draw("E"); 
h3_D0_n_eta->Draw("hist same"); 
 
D0_Nrecons->cd(3);
h3_D0_n_pt->Draw("E"); 
h3_D0_n_pt->Draw("hist same");

 
D0_Nrecons->cd(4);
h3_D0_n_theta->Draw("E"); 
h3_D0_n_theta->Draw("hist same"); 
 D0_Nrecons->Print("D0.pdf)","pdf");
 
 //------
    TCanvas * Dst_Precons= new TCanvas("Dst_Precons","Dst_Precons",400,10,600,400);
    Dst_Precons->Print("Dst.pdf(","pdf");
Dst_Precons->Divide(2,2);
Dst_Precons->cd(1);
h3_Dst_p_phi->Draw("E");
h3_Dst_p_phi->Draw("hist same");
 
Dst_Precons->cd(2);
h3_Dst_p_eta->Draw("E"); 
h3_Dst_p_eta->Draw("hist same"); 
 
Dst_Precons->cd(3);
h3_Dst_p_pt->Draw("E"); 
h3_Dst_p_pt->Draw("hist same"); 
 
Dst_Precons->cd(4);
h3_Dst_p_theta->Draw("E"); 
h3_Dst_p_theta->Draw("hist same");
 Dst_Precons->Print("Dst.pdf","pdf");
 
 
TCanvas * Dst_Nrecons= new TCanvas("Dst_Nrecons","Dst_Nrecons",400,10,600,400);
Dst_Nrecons->Divide(2,2);
Dst_Nrecons->cd(1);
h3_Dst_n_phi->Draw("E");
h3_Dst_n_phi->Draw("hist same");
 
Dst_Nrecons->cd(2);
h3_Dst_n_eta->Draw("E"); 
h3_Dst_n_eta->Draw("hist same"); 

Dst_Nrecons->cd(3);
h3_Dst_n_pt->Draw("E"); 
h3_Dst_n_pt->Draw("hist same"); 
 
Dst_Nrecons->cd(4);
h3_Dst_n_theta->Draw("E"); 
h3_Dst_n_theta->Draw("hist same"); 
 
 Dst_Nrecons->Print("Dst.pdf)","pdf");

 ///////////////////////////7
  TCanvas * piAssym= new TCanvas("piAssym","piAssym",400,10,600,400);
piAssym->Divide(2,2);
piAssym->cd(1);
pi_Prec_phi->Draw("E"); 
piAssym->cd(2);
pi_Prec_eta->Draw("E");
piAssym->cd(3);
pi_Prec_pt->Draw("E");
piAssym->cd(4);
pi_Prec_theta->Draw("E");
piAssym ->SaveAs("piAssymetry.pdf");

  TCanvas * KAssym= new TCanvas("KAssym","KAssym",400,10,600,400);
KAssym->Divide(2,2);
KAssym->cd(1);
K_Prec_phi->Draw("E"); 
KAssym->cd(2);
K_Prec_eta->Draw("E");
KAssym->cd(3);
K_Prec_pt->Draw("E");
KAssym->cd(4);
K_Prec_theta->Draw("E");
KAssym ->SaveAs("KAssymetry.pdf");

  TCanvas * sPiAssym= new TCanvas("sPiAssym","sPiAssym",400,10,600,400);
sPiAssym->Divide(2,2);
sPiAssym->cd(1);
sPi_Preco_phi->Draw("E"); 
sPiAssym->cd(2);
sPi_Prec_eta->Draw("E");
sPiAssym->cd(3);
sPi_Prec_pt->Draw("E");
sPiAssym->cd(4);
sPi_Prec_theta->Draw("E");
sPiAssym ->SaveAs("sPiAssymetry.pdf");

  TCanvas * D0Assym= new TCanvas("D0Assym","D0Assym",400,10,600,400);
D0Assym->Divide(2,2);
D0Assym->cd(1);
D0_Prec_phi->Draw("E"); 
D0Assym->cd(2);
D0_Prec_eta->Draw("E");
D0Assym->cd(3);
D0_Prec_pt->Draw("E");
D0Assym->cd(4);
D0_Prec_theta->Draw("E");
D0Assym ->SaveAs("D0Assymetry.pdf");

  TCanvas * DstAssym= new TCanvas("DstAssym","DstAssym",400,10,600,400);
DstAssym->Divide(2,2);
DstAssym->cd(1);
Dst_Prec_phi->Draw("E"); 
DstAssym->cd(2);
Dst_Prec_eta->Draw("E");
DstAssym->cd(3);
Dst_Prec_pt->Draw("E");
DstAssym->cd(4);
Dst_Prec_theta->Draw("E");
DstAssym ->SaveAs("DstAssymetry.pdf");

 

 

 
}
