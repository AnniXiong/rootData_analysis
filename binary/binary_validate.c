// attempt to validate the binary data for n and pt information
// 1st step: check the first pt_number pt data and n_number n data(from n_number events)

#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

//reading data
int binary_validate () { 	
     
     //data from two files will be read into these two arries
     //Note pt data file needs to have al least pt_number (float) data
     //and n file needs to have n_number (int) data
     
     int max_jet_number = 30;
     int pt_number = max_jet_number*10;
     int n_number = 20;
     
     float pt_array[max_jet_number];
     int n_array[n_number];
     
     FILE *nfile =fopen("output/Jets_n.coe","rb"); 
     FILE *ptfile =fopen("output/Jets_pt.coe","rb"); 
     if (!nfile || !ptfile) {printf("Unable to open files!"); return 1;}
	
	 //Read in jet number
	 for(int i =0; i<n_number; i++){ fread(&n_array[i], sizeof(int),1,nfile);}
	 cout << "jet number ready !"<< endl;
	 for(int f =0; f<n_number; f++){printf("%d, ",n_array[f]);}
	 cout << "finished processing n data\n"<<endl;
	
	 //Read in pt data
	 for (int k=0; k<n_number; k++){
	 	cout <<"--->Event" << k <<": ";
	 	fread(&pt_array, sizeof(pt_array),1,ptfile);
	 	for(int j=0; j<max_jet_number; j++){printf("%4.2f, ",pt_array[j]);}
	 	//clear pt_array for the next event
	 	for (int p=0; p < max_jet_number; p++) {pt_array[p] = 0.0;}
	 	cout<<"\n"<<endl;
	 	
	 }
	 		 
	 fclose(nfile);
	 fclose(ptfile);
	 
	 return 0;
}