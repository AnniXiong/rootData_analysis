#include "croot_tmp.h"
#include "croot_tmp.C"
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

int main_tmp (){
	
	
	
	TH1F *jet_n = new TH1F("Njet","",70,0,70);
	
	
	
	croot_tmp event_object;
	event_object.Loop(jet_n);
	
	cout << "Events processing finished."<<endl;
	
	return 0;

}



