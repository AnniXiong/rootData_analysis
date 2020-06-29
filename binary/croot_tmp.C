#define croot_tmp_cxx
#include "croot_tmp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

#include <stdlib.h>
#include <stdio.h>

#include <TLorentzVector.h>

void croot_tmp::Loop() {

	fChain->SetBranchStatus("*",0);  // disable all branches
    fChain->SetBranchStatus("AntiKt4LCTopoJets_*",1);  // activate branchname
    
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
    nentries = 20;

    Long64_t nbytes = 0, nb = 0;
   
    FILE *fout_pt = fopen("output/ZvvHbb_AntiKt4LCTopoJets_pt.dat", "w");
    FILE *fout_n = fopen("output/ZvvHbb_AntiKt4LCTopoJets_n.dat", "w");
    FILE *fout_m = fopen("output/ZvvHbb_AntiKt4LCTopoJets_m.dat", "w");

    //writing binary files
    FILE *fout_pt_b = fopen("output/Jets_pt.coe", "wb");
    FILE *fout_n_b = fopen("output/Jets_n.coe", "wb");
   
    TH1F *jet_n = new TH1F("Njet","",50,0,70);
    TH1F *mjj = new TH1F ("mjj_ZvvHbb125","", 50, 0, 600);
   
   
	for (Long64_t jentry=0; jentry<nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      std::cout <<"jentry------------ "<< jentry <<endl;
      
      // AntiKt4LCTopoJets_n/pt are names declared in the header file 
      std::cout << AntiKt4LCTopoJets_n << endl;
      jet_n ->Fill (AntiKt4LCTopoJets_n);
      fprintf (fout_n, "%i ", AntiKt4LCTopoJets_n);
      
      //Writing to binary pt
      fwrite(&AntiKt4LCTopoJets_n, sizeof(int), 1, fout_n_b);
      
      std:: vector<float> &ptr = *AntiKt4LCTopoJets_pt;
      std:: vector<float> &mr = *AntiKt4LCTopoJets_m;
      std:: vector<float> &etar = *AntiKt4LCTopoJets_eta;
      std:: vector<float> &phir = *AntiKt4LCTopoJets_phi;
      std:: vector<TLorentzVector> jetlist; 
      
      
      //Loop through each jet in one event
      for (int i =0; i< AntiKt4LCTopoJets_n; i++) {
        TLorentzVector jet;
        jet.SetPtEtaPhiM (ptr[i], etar[i], phir[i], mr[i]);
        jetlist.push_back (jet);
        
      	std:: cout <<"pt" <<ptr[i] << ",  ";
      	//std:: cout <<"M" <<mr[i] << ",  ";
      	fprintf(fout_pt, "%i ",(int)ptr[i]);
      	fprintf(fout_m, "%i ", (int)mr[i]);
          
        //Writing to binary pt
        fwrite(&ptr[i], sizeof(float), 1, fout_pt_b);
      	
      }
      
        mjj ->Fill ( (jetlist[0]+ jetlist[1]).M()/1000 );
      
      
        fprintf(fout_pt, "\n");
        fprintf(fout_m, "\n");
        std::cout << ""<<endl;
      
    }
    
     fclose(fout_pt);
     fclose(fout_n);
     fclose(fout_m);
     fclose(fout_pt_b);
     fclose(fout_n_b);
    
     jet_n -> SetLineColor(1);
    
     TFile *f = new TFile ("output/plot.root", "recreate");
	 jet_n ->Write ();
	 mjj -> Write ();
	 f-> Close();
}
