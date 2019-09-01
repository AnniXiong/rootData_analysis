#define croot_tmp_cxx
#include "croot_tmp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

#include <stdlib.h>
#include <stdio.h>

void croot_tmp::Loop()
{
//   In a ROOT session, you can do:
//      root> .L croot_tmp.C
//      root> croot_tmp t
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
    fChain->SetBranchStatus("*",0);  // disable all branches
    fChain->SetBranchStatus("AntiKt4LCTopoJets_*",1);  // activate branchname
    
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   nentries = 20;

   Long64_t nbytes = 0, nb = 0;
   
   FILE *fout_pt = fopen("output/ZvvHbb_AntiKt4LCTopoJets_pt.dat", "w");
   FILE *fout_n = fopen("output/ZvvHbb_AntiKt4LCTopoJets_n.dat", "w");
   TH1F *jet_n = new TH1F("Njet","",50,0,100);
   TH1F *jet_n_L20 = new TH1F("Njet_L20", "",50,0,100);
   TH1F *jet_n_L50 = new TH1F("Njet_L50", "",50, 0,100);
   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      
      std::cout <<"jentry"<< jentry <<endl;
      
      // AntiKt4LCTopoJets_n/pt are names declared in the header file 
      std::cout << AntiKt4LCTopoJets_n << endl;
      jet_n ->Fill (AntiKt4LCTopoJets_n);
      fprintf (fout_n, "%i ", AntiKt4LCTopoJets_n);
      
      
      std:: vector<float> &ptr = *AntiKt4LCTopoJets_pt;
      
      for (int i =0; i< AntiKt4LCTopoJets_n; i++) {
      	std:: cout <<"m "<<ptr[i] << ",  ";
      	fprintf(fout_pt, "%i ",(int)ptr[i]);
      }
      
      
        fprintf(fout_pt, "\n");
        std::cout << ""<<endl;
   }
    
	TFile *f = new TFile ("output/plot.root", "recreate");
	jet_n ->Write ();
	f-> Close();

}
