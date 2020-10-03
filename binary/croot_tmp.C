#define croot_tmp_cxx
#include "croot_tmp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <TLorentzVector.h>

void croot_tmp:: decToBinary(FILE *fo, int n, const int precision) 
{ 
    // array to store binary number 
    int binaryNum[precision]; 
    int i = 0; //count number of digits needed
    while (n > 0) { 
        // store remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    std::string s;
	char const *pchar;
	for (int j = precision - 1; j >= 0; j--) {
	   if(j>=i){
	        fprintf(fo, "%s", "0");
            //cout << j <<", "<<"0" <<endl;
       } else if (j<i) {
            s = std::to_string(binaryNum[j]);
	        pchar = s.c_str();
            fprintf(fo, "%s", pchar);
            //cout << j <<", "<<binaryNum[j]<<endl;
        }
	}
} 


void croot_tmp::Loop() {

	fChain->SetBranchStatus("*",0);  // disable all branches
    fChain->SetBranchStatus("AntiKt4LCTopoJets_*",1);  // activate branchname
    
    if (fChain == 0) return;
    Long64_t nentries = fChain->GetEntriesFast();
    nentries = 20;
    Long64_t nbytes = 0, nb = 0;
   
    //creating the decimal files
    FILE *fout_pt = fopen("output/ZvvHbb_AntiKt4LCTopoJets_pt.dat", "w");
    FILE *fout_n = fopen("output/ZvvHbb_AntiKt4LCTopoJets_n.dat", "w");
    FILE *fout_m = fopen("output/ZvvHbb_AntiKt4LCTopoJets_m.dat", "w");

    //creating binary files
    FILE *fout_pt_b = fopen("output/Jets_pt.coe", "wb");
    FILE *fout_n_b = fopen("output/Jets_n.coe", "wb");
   
    //creating binary Ascii files
    FILE *fout_pt_b_as = fopen("output/Jets_ascii_pt.coe", "w");
    FILE *fout_n_b_as = fopen("output/Jets_ascii_n.coe", "w");
    
    
    //TH1F *jet_n = new TH1F("Njet","",50,0,70);
    //TH1F *mjj = new TH1F ("mjj_ZvvHbb125","", 50, 0, 600);
   
//Start of event loop 
	for (Long64_t jentry=0; jentry<nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      std::cout <<"jentry------------ "<< jentry <<endl;
      
      // AntiKt4LCTopoJets_n/pt are names declared in the header file 
      std::cout << AntiKt4LCTopoJets_n << endl;
      //jet_n ->Fill (AntiKt4LCTopoJets_n);
      fprintf (fout_n, "%i ", AntiKt4LCTopoJets_n);
      decToBinary(fout_n_b_as,AntiKt4LCTopoJets_n,32);
      //fprintf(fout_n_b_as, "%i", bin_conversion((int)AntiKt4LCTopoJets_n));
      
      
      //Writing to binary pt
      fwrite(&AntiKt4LCTopoJets_n, sizeof(int), 1, fout_n_b);
      
      std:: vector<float> &ptr = *AntiKt4LCTopoJets_pt;
      std:: vector<float> &mr = *AntiKt4LCTopoJets_m;
      std:: vector<float> &etar = *AntiKt4LCTopoJets_eta;
      std:: vector<float> &phir = *AntiKt4LCTopoJets_phi;
      std:: vector<TLorentzVector> jetlist; 
      
      
      //so that the binary data can be written from this array to file
      int max_jet_number = 30; //can process at most 50 jets for event
      float pt_tmp[max_jet_number];
      float place_holder = 0.0;
      
      //Loop through each jet in one event
      for (int i =0; i< AntiKt4LCTopoJets_n; i++) {
        TLorentzVector jet;
        jet.SetPtEtaPhiM (ptr[i], etar[i], phir[i], mr[i]);
        jetlist.push_back (jet);
        
      	std:: cout <<ptr[i] << ",  ";
      	//std:: cout <<"M" <<mr[i] << ",  ";
      	fprintf(fout_pt, "%i ",(int)ptr[i]);
      	fprintf(fout_m, "%i ", (int)mr[i]);
      	
      }

	  // Writing out fixed pt arries (FPGA needs to know exactly how much resources 
	  // to allocate before processing an evnt)
	  // if vector is longer than max_jet_number--> some pt's are cut off
	  // if vector is shorter than max_jet_number--> FPGA's will allocate extra reso, add zeros
	  
      for (int i =0; i< max_jet_number; i++) {
      	if (AntiKt4LCTopoJets_n >= max_jet_number){
      		fwrite(&ptr[i], sizeof(float), 1, fout_pt_b);
      		decToBinary(fout_pt_b_as,(int)ptr[i],32);
      	} else if (AntiKt4LCTopoJets_n < max_jet_number){
      		if (i < AntiKt4LCTopoJets_n){
        		//Writing to binary pt
        		fwrite(&ptr[i], sizeof(float), 1, fout_pt_b);
        		decToBinary(fout_pt_b_as, (int)ptr[i],32);
        	} else if(i >= AntiKt4LCTopoJets_n){
        		fwrite(&place_holder, sizeof(float), 1, fout_pt_b);
        		fprintf(fout_pt_b_as, "%s", "00000000000000000000000000000000");
        		
        	}
        }
      }
      
      fprintf(fout_pt, "\n");
      fprintf(fout_m, "\n");
      std::cout << ""<<endl;

      } //end of the event loop
    
     fclose(fout_pt);
     fclose(fout_n);
     fclose(fout_m);
     fclose(fout_pt_b);
     fclose(fout_n_b);
     fclose(fout_pt_b_as);
     fclose(fout_n_b_as);
    
}



