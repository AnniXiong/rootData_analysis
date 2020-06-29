#define croot_tmp_cxx
#include "croot_tmp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

#include <stdlib.h>
#include <stdio.h>

#include <TLorentzVector.h>

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
   FILE *fout_m = fopen("output/ZvvHbb_AntiKt4LCTopoJets_m.dat", "w");

   //writing binary files
   FILE *fout_pt_b = fopen("output/Jets_pt.coe", "wb");
   FILE *fout_n_b = fopen("output/Jets_n.coe", "wb");
   
   TH1F *jet_n = new TH1F("Njet","",50,0,70);
   TH1F *jet_n_L20 = new TH1F("Njet_L20", "",50,0,70);
   TH1F *jet_n_L50 = new TH1F("Njet_L50", "",50, 0,70);
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
      
        
      // Fill jet_number_L histograms if the event has at least one jet with pt larger than 30/50 GeV
      int L30 = 0;
      int L50 = 0;
      
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
      	
      	if ((int)ptr[i] > 30000) L30+=1;
      	if ((int)ptr[i] > 50000) L50+=1;
      }
      
        if (L30 > 0) jet_n_L20 ->Fill (L30);
        if (L50 > 0) jet_n_L50 ->Fill (L50);
        mjj ->Fill ( (jetlist[0]+ jetlist[1]).M()/1000 );
      
        //cout <<"" <<endl;
        //cout << ": L30 "<< L30 << " L50 " << L50 << ",  Out of total number " << AntiKt4LCTopoJets_n <<", mjj: " << (jetlist[0] + jetlist[1]).M()/1000 << endl;
        //cout << "mjj details " << jetlist[0].Pt() << " " << jetlist[0].M() << " " << jetlist[1].Pt() << " "<< jetlist[1].M() << " " <<jetlist[0].M() + jetlist[1].M()<< endl;
      
       L30 = 0 ; L50 = 0;
      
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
    jet_n_L20 -> SetLineColor(2);
    jet_n_L50 -> SetLineColor(3);
    
    TFile *f = new TFile ("output/plot.root", "recreate");
	jet_n ->Write ();
	jet_n_L20 ->Write ();
	jet_n_L50 ->Write ();
	mjj -> Write ();
	f-> Close();
	
	
	//stacking the Jet_number plots
	string hist_obj1 = "Njet";
	string hist_obj2 = "Njet_L20";
	string hist_obj3 = "Njet_L50";
	
	THStack *stack = new THStack("hs","");
	TFile* file = new TFile ("output/plot.root");
    TH1F* h1 = (TH1F*) gDirectory->Get(hist_obj1.c_str());
    stack->Add(h1);
    TH1F* h2 = (TH1F*) gDirectory->Get(hist_obj2.c_str());
    stack->Add(h2);
    TH1F* h3 = (TH1F*) gDirectory->Get(hist_obj3.c_str());
    stack->Add(h3);
    
    TCanvas *canvas = new TCanvas("canvas","canvas",10,10,600,400);
    stack->Draw ("nostack");
    
    TLegend *legend2 = new TLegend(0.7,.75,.9,.9,0);
    legend2->AddEntry(h1,"Number of jets");
    legend2->AddEntry(h2,"Njets with pt > 30GeV");
    legend2->AddEntry(h3,"Njets with pt > 50GeV");
    legend2->Draw();
    
    stack->GetXaxis()->SetTitle("number of jets");
    stack->GetYaxis()->SetTitle("# of events");
    canvas-> Modified();
    
    TFile *f1 = new TFile ("output/plot_stack.root", "recreate");
    canvas ->Write();

}
