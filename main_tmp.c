#include "croot_tmp.h"
#include "croot_tmp.C"
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

int main_tmp (){
	
	croot_tmp event_object;
	event_object.Loop();
	cout << "Events processing finished"<<endl;
	
	return 0;

}



