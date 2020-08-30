#define croot_tmp_cxx
#include "croot_tmp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGraph.h>

#include <stdlib.h>
#include <stdio.h>

#include <TLorentzVector.h>

void croot_tmp::Loop()
{

    fChain->SetBranchStatus("*",0);  // disable all branches
    fChain->SetBranchStatus("AntiKt4LCTopoJets_*",1);  // activate branchname
    
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
    //nentries = 100;
    Long64_t nbytes = 0, nb = 0;
    int Total_numberJets = 0;
  
    //histogram definition
    TH1F *jet_n = new TH1F("Njet","",70,0,70);
    TH1F *jet_n_Ptcut_30 = new TH1F("Njet_Ptcut_30","",70,0,70);
   
    TH1F *jet_n_L20 = new TH1F("Njet_L20", "",70,0,70);
    TH1F *jet_n_L50 = new TH1F("Njet_L50", "",70, 0,70);
    TH1F *mjj = new TH1F ("mjj_ZvvHbb125","", 100, 0, 1000);
    TH1F *mm_all = new TH1F ("mm_all_ZvvHbb125","", 100, 0, 1000);
    TH1F *mm_lead = new TH1F ("mm_lead_ZvvHbb125","", 100, 0, 1000);
    TH1F *pt_jj = new TH1F ("pt_jj_ZvvHbb125","", 50, 0, 600);
    TH1F *eta_jj = new TH1F ("eta_jj_ZvvHbb125","", 50, -7, 7);
    TH1F *phi_jj = new TH1F ("phi_jj_ZvvHbb125","", 50, -3.5, 3.5);
    
    Float_t mjj_array[nentries];
    Float_t mm_array[nentries];
    
    std:: vector<float> eta_array_pass;
    std:: vector<float> eta_array_Nopass;
    std:: vector<float> phi_array_pass;
    std:: vector<float> phi_array_Nopass;
    
   
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
       std::cout <<"Event ------------"<< AntiKt4LCTopoJets_n <<" jets  "<<endl;
       // Fill jet_number_L histograms if the event has at least one jet with pt larger than 30/50 GeV
       int L30 = 0;
       int L50 = 0;
       L30 = 0 ; L50 = 0;
       int pt_cut = 30000;
       float MSum_GeV;
    
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   
       nbytes += nb;
      
       std:: vector<float> &ptr = *AntiKt4LCTopoJets_pt;
       std:: vector<float> &mr = *AntiKt4LCTopoJets_m;
       std:: vector<float> &etar = *AntiKt4LCTopoJets_eta;
       std:: vector<float> &phir = *AntiKt4LCTopoJets_phi;
       std:: vector<TLorentzVector> jetlist; 
       std:: vector<float> mm_list;
      
      //prepare TLorentzVector for each jet in the event
      for (int i =0; i< AntiKt4LCTopoJets_n; i++) {
        TLorentzVector jet;
        jet.SetPtEtaPhiM (ptr[i], etar[i], phir[i], mr[i]);
        jetlist.push_back (jet);
        
        if ((int)ptr[i] > 30000) L30+=1;
      	if ((int)ptr[i] > 50000) L50+=1;
      	
      	//std:: cout <<"phi: " <<phir[i] << ",  ";
      	//std:: cout <<"eta: " <<etar[i] << ",  ";
      	
      	
      	
      	if(ptr[i]>pt_cut) {
      		eta_array_pass.push_back(etar[i]);
       	  	phi_array_pass.push_back(phir[i]);
       	} else {
       		eta_array_Nopass.push_back(etar[i]);
       		phi_array_Nopass.push_back(phir[i]);
        }
          
      }
	
        Total_numberJets+= AntiKt4LCTopoJets_n;
      	cout <<"" <<endl;
        if (L30 > 0) jet_n_L20 ->Fill (L30);
        if (L50 > 0) jet_n_L50 ->Fill (L50);
        

        // AntiKt4LCTopoJets_n/pt are names declared in the header file 
        jet_n ->Fill (AntiKt4LCTopoJets_n);
        if((jetlist[0].Pt()>pt_cut) && (jetlist[1].Pt()>pt_cut)){
        	mjj ->Fill ( (jetlist[0]+ jetlist[1]).M()/1000. );
        }
        mjj_array[jentry] = (jetlist[0]+ jetlist[1]).M()/1000.;
        pt_jj->Fill((jetlist[0]+ jetlist[1]).Pt()/1000.);
        eta_jj->Fill((jetlist[0]+ jetlist[1]).Eta());
        phi_jj->Fill((jetlist[0]+ jetlist[1]).Phi());
        
        //Calculate all combinations of MM
        for (int j=0; j<mr.size()-1;j++){
      	  for (int k=1; k<mr.size()-j;k++){
      	  	 MSum_GeV = (jetlist[j]+jetlist[j+k]).M()/1000.;
      	  	 
        	 //if((jetlist[j].Pt()>pt_cut) && (jetlist[j+k].Pt()>pt_cut)){
        	 	mm_all->Fill(MSum_GeV);
        	 	mm_list.push_back(MSum_GeV);
        	 //}else{
        	 	//mm_list.push_back(-1);
        	 
        	 //}
             //std::cout << MSum_GeV <<", ";
           } 
         	 //std::cout << ""<<endl;
         }
    
    
    	//for (const float & va: mm_list ){cout << va << ", ";}


        //Calculate largest combined MM 
        float first_max = *max_element(mm_list.begin(), mm_list.end());
        auto it = find(mm_list.begin(), mm_list.end(), first_max);
    
        // If element was found, find the position of the element
        if (it != mm_list.end()) { 
            int first_index = distance(mm_list.begin(), it); 
        } else { 
      	    cout << "not found, -1" << endl; 
        } 
      
        if (first_max >0){mm_lead->Fill(first_max);}
        cout << "first max: " << first_max <<endl;
        mm_array[jentry]= first_max;
        
        
        //cout <<"" <<endl;
        //cout << ": L30 "<< L30 << " L50 " << L50 << ",  Out of total number " << AntiKt4LCTopoJets_n <<", mjj: " << (jetlist[0] + jetlist[1]).M()/1000 << endl;
        //cout << "mjj details " <<"pt1: " <<jetlist[0].Pt() << " " <<"m1: " <<jetlist[0].M() << " " <<"pt2: "<< jetlist[1].Pt() << " "<<"m2: "<< jetlist[1].M() << " " <<jetlist[0].M() + jetlist[1].M()<< endl;
        //cout <<"" <<endl;
        //cout << "mjj with lead pt: "<<(jetlist[0]+ jetlist[1]).M()/1000. <<endl;
        //cout <<""<<endl;
        //cout << "Max Ele = "<< first_max <<",at pos: "<< first_index<<" ,sec max: " << second_max <<" ,at pos: "<< second_index<<endl; 
        //std::cout << "-----------"<<endl;  
      
   } //end of event loop
   
   
       const int passed_size = eta_array_pass.size();
       const int Nopassed_size = eta_array_Nopass.size();
   	   float eta_pass[passed_size];
   	   float eta_Nopass[Nopassed_size];
       float phi_pass[passed_size];
       float phi_Nopass[Nopassed_size];
        
	   std::copy(eta_array_pass.begin(), eta_array_pass.end(), eta_pass);
	   std::copy(eta_array_Nopass.begin(), eta_array_Nopass.end(), eta_Nopass);
	   std::copy(phi_array_pass.begin(), phi_array_pass.end(), phi_pass);
	   std::copy(phi_array_Nopass.begin(), phi_array_Nopass.end(), phi_Nopass);
		
   
    cout << "the total number of jets is" << Total_numberJets <<endl;
    cout << passed_size << "jets passed the pt cut and "<< Nopassed_size <<"jets didn't pass the selection"<<endl;
    /*
    for (int a=0;a<passed_size;a++) {
		cout << eta_pass[a] << " "<< phi_pass[a]<<endl;
	}
	cout <<""<<endl;
	 for (int b=0;b<Nopassed_size;b++) {
		cout << eta_Nopass[b] << " " << phi_Nopass[b]<<endl;;
	}
   */
   
    TFile *f = new TFile ("output/plot.root", "recreate");
	jet_n ->Write ();
	jet_n_L20 ->Write ();
	jet_n_L50 ->Write ();
	mjj -> Write ();
	pt_jj -> Write ();
	eta_jj -> Write ();
	phi_jj -> Write ();
	mm_all->Write();
	mm_lead->Write();
	//mjj_mm_lead->Write();
    f-> Close();
    
	//mjj_mm_lead->Draw("A*");
	
	TGraph *EvnDisplay_Nopass = new TGraph(Nopassed_size,eta_Nopass, phi_Nopass);
	EvnDisplay_Nopass->SetMarkerColor(4);
	EvnDisplay_Nopass->GetXaxis()->SetTitle("eta");
	EvnDisplay_Nopass->GetYaxis()->SetTitle("phi");
    EvnDisplay_Nopass->Draw("A*");
    
    TGraph *EvnDisplay_pass = new TGraph(passed_size,eta_pass, phi_pass);
	EvnDisplay_pass->SetMarkerColor(3);
    EvnDisplay_pass->SetMarkerStyle(3);
    EvnDisplay_pass->Draw("P");

	TLegend *legend1 = new TLegend(0.7,.75,.9,.9,0);
    legend1->AddEntry(EvnDisplay_pass,"jets with pt > 30GeV");
    legend1->AddEntry(EvnDisplay_Nopass,"jets with pt < 30GeV");
    legend1->Draw();
    
	
	/*
	jet_n -> SetLineColor(1);
    jet_n_L20 -> SetLineColor(2);
    jet_n_L50 -> SetLineColor(3);
	
	//produce the scatter plot
	TGraph *mjj_mm_lead = new TGraph(nentries, mjj_array, mm_array);
	mjj_mm_lead->SetMarkerColor(4);
    mjj_mm_lead->SetMarkerStyle(21);
    mjj_mm_lead->SetTitle("Correlation plot");
    mjj_mm_lead->GetXaxis()->SetTitle("mjj(GeV)");
    mjj_mm_lead->GetYaxis()->SetTitle("Largest combined mass(GeV)");
    
	//stacking the histograms
	string hist_obj1 = "mm_all_ZvvHbb125";
	string hist_obj2 = "mm_lead_ZvvHbb125";
    string hist_obj3 = "mjj_ZvvHbb125";
	
	THStack *stack = new THStack("histo stack","");
	TFile* file = new TFile ("output/plot.root");
    TH1F* h1 = (TH1F*) gDirectory->Get(hist_obj1.c_str());
    h1->SetLineColor(1);
    stack->Add(h1);
    TH1F* h2 = (TH1F*) gDirectory->Get(hist_obj2.c_str());
    h2->SetLineColor(2);
    stack->Add(h2);
    TH1F* h3 = (TH1F*) gDirectory->Get(hist_obj3.c_str());
    h3->SetLineColor(3);
    stack->Add(h3);
    TCanvas *canvas = new TCanvas("canvas","canvas",10,10,600,400);
	stack->Draw ("nostack");
	
    TLegend *legend2 = new TLegend(0.7,.75,.9,.9,0);
    legend2->AddEntry(h1,"all combination mjj");
    legend2->AddEntry(h2,"largest combined mjj");
    legend2->AddEntry(h3,"Lead pt mjj");
    legend2->Draw();
    
    //stack->GetXaxis()->SetTitle("number of jets");
    //stack->GetYaxis()->SetTitle("# of events");
    //canvas-> Modified();
    
    TFile *f1 = new TFile ("output/stack_plot.root", "recreate");
    canvas->Write();
    */
}
