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


#include <TEllipse.h>
#include <TPolyLine.h>
#include <TPaveText.h>
#include <TText.h>
#include <string>


void croot_tmp::Loop(TH1F *jet_n) {

    fChain->SetBranchStatus("*",0);  // disable all branches
    fChain->SetBranchStatus("AntiKt4LCTopoJets_*",1);  // activate branchname
    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
    nentries = 36;
    Long64_t nbytes = 0, nb = 0;
    int Total_numberJets = 0;
    int EventDisplaynumber = 35;
  
    //histogram definition
   
    TH1F *jet_n_Ptcut_30 = new TH1F("Njet_Ptcut_30","",70,0,70);
   
    TH1F *jet_n_L20 = new TH1F("Njet_L20", "",70,0,70);
    TH1F *jet_n_L50 = new TH1F("Njet_L50", "",70, 0,70);
    TH1F *mjj = new TH1F ("mjj_ZvvHbb125","", 100, 0, 1000);
    TH1F *mm_all = new TH1F ("mm_all_ZvvHbb125","", 100, 0, 1000);
    TH1F *mm_lead = new TH1F ("mm_lead_ZvvHbb125","", 160, 0, 1600);
    TH1F *pt_jj = new TH1F ("pt_jj_ZvvHbb125","", 60, 0, 600);
    TH1F *eta_jj = new TH1F ("eta_jj_ZvvHbb125","", 50, -7, 7);
    TH1F *phi_jj = new TH1F ("phi_jj_ZvvHbb125","", 50, -3.5, 3.5);
    
    Float_t mjj_array[nentries];
    Float_t mm_array[nentries];
    Float_t max_mm_eta[2*nentries];
    Float_t max_mm_phi[2*nentries];
    
    std:: vector<float> eta_array_pass;
    std:: vector<float> eta_array_Nopass;
    std:: vector<float> phi_array_pass;
    std:: vector<float> phi_array_Nopass;
    
   
    for (Long64_t jentry=0; jentry<nentries; jentry++) {
       
       // Fill jet_number_L histograms if the event has at least one jet with pt larger than 30/50 GeV
       int L30 = 0;
       int L50 = 0;
       L30 = 0 ; L50 = 0;
       int pt_cut = 30000;
       float MSum_GeV;
       int first_index;
    
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
       std:: vector<float> eta_list;
       std:: vector<float> phi_list;
       std:: vector<int> mm_index_1;
       std:: vector<int> mm_index_2;
       
       
       std::cout <<"Event ------------"<<jentry<<" with "<< AntiKt4LCTopoJets_n <<" jets  "<<endl;
      
      //prepare TLorentzVector for each jet in the event
      for (int i =0; i< AntiKt4LCTopoJets_n; i++) {
        TLorentzVector jet;
        jet.SetPtEtaPhiM (ptr[i], etar[i], phir[i], mr[i]);
        jetlist.push_back (jet);
        
        if ((int)ptr[i] > 30000) L30+=1;
      	if ((int)ptr[i] > 50000) L50+=1;
      	
      	//std:: cout << ptr[i]<<", "<<etar[i]<<", "<<phir[i] <<", "<<mr[i]<<"--  ";
      	
      	
      	
      	if(ptr[i]>pt_cut) {
      		eta_array_pass.push_back(etar[i]);
       	  	phi_array_pass.push_back(phir[i]);
       	} else {
       		eta_array_Nopass.push_back(etar[i]);
       		phi_array_Nopass.push_back(phir[i]);
        }
          
      }//end of jet loop
	
		TLorentzVector met_tv =  MET (jetlist);
		float met_stv;
		met_stv = met_tv.Et();
		cout << ""<<endl;
		cout << "Summed TLvector has "<< met_tv.Px() <<", "<< met_tv.Py() <<", " << met_tv.Pz() <<", " <<met_tv.E()<<endl;
		cout << "The missing met is "<< met_stv <<"with pt: "<< met_tv.Pt()<<","<<met_tv.M()<<endl;
		
        
        Total_numberJets+= AntiKt4LCTopoJets_n;
      	cout <<"----" <<endl;
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
        
        std:: cout <<"1st jet P" <<jetlist[0].Px() <<", "<<jetlist[0].Py()<<", "<<jetlist[0].Pz() <<", "<<jetlist[0].E()<<", "<<jetlist[0].Pt()<<"--  "<<endl;
        std:: cout <<"2nd jet P" <<jetlist[1].Px() <<", "<<jetlist[1].Py()<<", "<<jetlist[1].Pz() <<", "<<jetlist[1].E()<<", "<<jetlist[1].Pt()<<"--  "<<endl;
        
        //Calculate all combinations of MM
        for (int j=0; j<mr.size()-1;j++){
      	  for (int k=1; k<mr.size()-j;k++){
      	  	 MSum_GeV = (jetlist[j]+jetlist[j+k]).M()/1000.;
      	  	 
      	  	 mm_index_1.push_back(j);
      	  	 mm_index_2.push_back(j+k);
        	 //if((jetlist[j].Pt()>pt_cut) && (jetlist[j+k].Pt()>pt_cut)){
        	     mm_all->Fill(MSum_GeV);
        	 	 mm_list.push_back(MSum_GeV);
        	 	 eta_list.push_back(jetlist[j].Eta());
        	 	 eta_list.push_back(jetlist[j+k].Eta());
        	 	 phi_list.push_back(jetlist[j].Phi());
        	 	 phi_list.push_back(jetlist[j+k].Phi());
        	 /*}else{
        	    mm_list.push_back(-1);
        	    eta_list.push_back(0);
        	 	eta_list.push_back(0);
        	 	phi_list.push_back(0);
        	 	phi_list.push_back(0);
        	 
        	 }*/
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
            first_index = distance(mm_list.begin(), it); 
        } else { 
      	    cout << "not found, -1" << endl; 
        } 
      
        
        //cout << "first max: " << first_max <<" at "<<first_index<<endl;
        mm_array[jentry]= first_max;
        
        	if(first_max>0){mm_lead->Fill(first_max);}
        	max_mm_eta[jentry*2] = eta_list[first_index*2];
        	max_mm_eta[jentry*2+1] = eta_list[first_index*2+1];
        	max_mm_phi[jentry*2] = phi_list[first_index*2];
        	max_mm_phi[jentry*2+1] = phi_list[first_index*2+1];
		
		//---------------------//
		//Run the event display//
		//---------------------//
		
		if (jentry== EventDisplaynumber){EventDisplay(met_tv, jentry, AntiKt4LCTopoJets_n, mm_index_1[first_index], mm_index_2[first_index], ptr, etar, phir, mr);}
        cout <<"" <<endl;
        cout << "jet " << mm_index_1[first_index] << "and jet "<< mm_index_2[first_index] << "make the largest mass comb"<<endl;
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
       float max_eta[2*nentries];
       float max_phi[2*nentries];
       
       for (int c=0; c<nentries;c++){
       		
       		//cout << max_mm_eta[c*2]<<", "<< max_mm_phi[c*2]<<"; ";
       		//cout << max_mm_eta[c*2+1]<<" "<< max_mm_phi[c*2+1]<< endl;
       }
        
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
	/*
	TGraph *EvnDisplay_Nopass = new TGraph(Nopassed_size,eta_Nopass, phi_Nopass);
	EvnDisplay_Nopass->SetMarkerColor(4);
	EvnDisplay_Nopass->GetXaxis()->SetTitle("eta");
	EvnDisplay_Nopass->GetYaxis()->SetTitle("phi");
    EvnDisplay_Nopass->Draw("A*");
    
    TGraph *EvnDisplay_pass = new TGraph(passed_size,eta_pass, phi_pass);
	EvnDisplay_pass->SetMarkerColor(3);
    EvnDisplay_pass->SetMarkerStyle(3);
    EvnDisplay_pass->Draw("P");
    
    TGraph *EvnDisplay_max_mm = new TGraph(nentries*2, max_mm_eta, max_mm_phi);
	EvnDisplay_max_mm->SetMarkerColor(2);
    EvnDisplay_max_mm->SetMarkerStyle(3);
    EvnDisplay_max_mm->Draw("P");

	
	TLegend *legend1 = new TLegend(0.7,.75,.9,.9,0);
    legend1->AddEntry(EvnDisplay_pass,"jets with pt > 30GeV");
    legend1->AddEntry(EvnDisplay_Nopass,"jets with pt < 30GeV");
    legend1->AddEntry(EvnDisplay_max_mm,"jets from max combined mass and both jets pt > 30GeV");
    legend1->Draw();
    
	
	
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

void croot_tmp::EventDisplay(TLorentzVector metTLv, Int_t EvnID, Int_t jetN, int index1, int index2, vector <float> &pt, vector <float> &eta, vector <float> &phi, vector <float> &m ) {
	
	//cout <<"Displaying event number "<< EvnID << "which has "<< jetN << "jets"<<endl;
	vector <TLorentzVector> jv;
	
	float eta_a[jetN];
	float phi_a[jetN];
	std:: copy(eta.begin(), eta.end(), eta_a);
	std:: copy(phi.begin(), phi.end(), phi_a);
	
	
	TCanvas* c1 = new TCanvas("c1","Examples of Gaxis",200,10,700,500);
	
	//TH2F *hpx = new TH2F("hpx","Fix TGraph range",20,-3,3,10,-2,2);
	//hpx->SetStats(kFALSE);
	//hpx->Draw();
	
	// to have fixed plotting range
	float x_range[4] = {-5,-5,6,6};
	float y_range[4] = {-3.5,6,-3.5,6};
	
	TGraph *g_range = new TGraph(4,x_range,y_range);
		
	g_range->SetTitle("Event 35");
	g_range->SetMarkerColor(17);
	g_range->SetMarkerSize(0.5);
	g_range->GetXaxis()->SetTitle("#eta");
	g_range->GetYaxis()->SetTitle("#phi");
	g_range->Draw("A*");
	
	TGraph *g = new TGraph(jetN,eta_a,phi_a);
	g->SetMarkerColor(4);
	g->SetMarkerSize(0.3);
	
	g->Draw("*");

	for(int i = 0; i<jetN;i++){
		TLorentzVector jet;
		jet.SetPtEtaPhiM(pt[i],eta[i],phi[i],m[i]);
		jv.push_back(jet);
	
		TEllipse *e; e = new TEllipse (eta[i],phi[i],0.4, 0);
		e->Draw();
		TEllipse *e_lead_pt; e_lead_pt = new TEllipse (eta[i],phi[i],0.35, 0);
		TEllipse *e_30_pt; e_30_pt = new TEllipse (eta[i],phi[i],0.3, 0);
		TEllipse *e_max; e_max = new TEllipse (eta[i],phi[i],0.24, 0);
		
		if(i < 2){	
			e_lead_pt->SetLineColor(8);
			e_lead_pt->SetLineWidth(3);
			e_lead_pt ->Draw();
		}
		if(pt[i] > 30000){	
			e_30_pt->SetLineColor(4);
			e_30_pt->SetLineWidth(3);
			e_30_pt->Draw();
		}
		if((i==index1) || (i==index2)){
			e_max->SetLineColor(2);
			e_max->SetLineWidth(3);
			e_max->Draw();
		}
		
		//Labeling the pt's on each ellipse
		std::string s;
		char const *pchar;
		TText *t;
		s = std::to_string((int)(pt[i]/1000));
		pchar = s.c_str();
		t = new TText (eta[i]-0.15,phi[i]-0.15,pchar);
		t->SetTextSize(0.04);
		t->SetTextFont(82);
		t->Draw();
}
		
		//label the missing Et
		std::string met_s = std::to_string((int)(metTLv.Et()/1000));
		char const *met_pchar = met_s.c_str();
		TText *met_t = new TText(-4, metTLv.Phi()+0.15, met_pchar); 
		met_t->SetTextSize(0.04);
		met_t->SetTextFont(102);
		met_t->Draw();
		//Draw the MET line
		TLine *lmet = new TLine(-5.6, metTLv.Phi(), 5.6, metTLv.Phi());
		lmet->Draw();
		
		std::string parent_pt = std::to_string((int)((jv[0]+jv[1]).Pt()/1000));
		char const *parent_pchar = parent_pt.c_str();
		std::string parent_eta = std::to_string((jv[0]+jv[1]).Eta());
		char const *parent_etachar = parent_eta.c_str();
		std::string parent_phi = std::to_string((jv[0]+jv[1]).Phi());
		char const *parent_phichar = parent_phi.c_str();
		
		
		TPaveText *PT = new TPaveText (3.5,4.5,6.5,6.5);
		PT->AddText("Parent particle info (pt, #eta, #phi)");
		PT->AddText(parent_pchar);
		PT->AddText(parent_etachar);
		PT->AddText(parent_phichar);
		PT->Draw();


}

//This function is to calculate the transverse energy of the final state jets
TLorentzVector croot_tmp::MET (vector <TLorentzVector> jetlist){
	TLorentzVector Summed_tv;
	// j< 2 mean to only include the 1st two jets for MET calculation
	for (int j=0;j<2;j++){Summed_tv += jetlist[j];}
		Summed_tv.SetPxPyPzE(-Summed_tv.Px(), -Summed_tv.Py(), -Summed_tv.Pz(), Summed_tv.E());
	return Summed_tv;
}