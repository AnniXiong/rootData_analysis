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
     
     int pt_number = 50;
     int n_number = 20;
     
     float pt_array[pt_number];
     int n_array[n_number];
     
     FILE *nfile =fopen("output/Jets_n.coe","rb"); 
     FILE *ptfile =fopen("output/Jets_pt.coe","rb"); 
     if (!nfile || !ptfile) {printf("Unable to open files!"); return 1;}
	
	 //read in jet number
	 for(int i =0; i<n_number; i++){ fread(&n_array[i], sizeof(int),1,nfile);}
	 cout << "jet number ready !"<< endl;
	 for(int f =0; f<n_number; f++){printf("%d, ",n_array[f]);}
	 cout << "finished processing n data"<<endl;
	 cout << " "<<endl;
	 
	 //print out 50 pt data and 20 n data, then check against the decimal output
	 for(int k =0; k<pt_number; k++){fread(&pt_array[k], sizeof(float),1,ptfile);}
	 for(int j =0; j<pt_number; j++){printf("%4.2f, ",pt_array[j]);}
	 	 		 
	 fclose(nfile);
	 fclose(ptfile);
	 
	 return 0;
}