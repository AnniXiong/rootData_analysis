//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 25 11:51:08 2019 by ROOT version 6.09/03
// from TTree mytree/mytree
// found on file: user.cylin.8535524.OUTPUT._000002.root
//////////////////////////////////////////////////////////

#ifndef croot_tmp_h
#define croot_tmp_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <stdlib.h>
#include <stdio.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class croot_tmp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *scells_Et;
   vector<float>   *scells_time;
   vector<unsigned int> *scells_provenance;
   vector<unsigned int> *scells_quality;
   vector<float>   *gTowerEt;
   vector<float>   *gTowerPhiWeighted;
   vector<float>   *gTowerEtaWeighted;
   vector<int>     *gTowerNCells;
   vector<float>   *gTowerEt_EM;
   vector<float>   *gTowerPhi_EM;
   vector<float>   *gTowerEta_EM;
   vector<float>   *gTowerPhiWeighted_EM;
   vector<float>   *gTowerEtaWeighted_EM;
   vector<int>     *gTowerNCells_EM;
   vector<float>   *gTowerEt_Had;
   vector<float>   *gTowerPhi_Had;
   vector<float>   *gTowerEta_Had;
   vector<float>   *gTowerPhiWeighted_Had;
   vector<float>   *gTowerEtaWeighted_Had;
   vector<int>     *gTowerNCells_Had;
   vector<float>   *jTowerEt;
   vector<int>     *jTowerNCells;
   vector<float>   *jTowerEt_EM;
   vector<int>     *jTowerNCells_EM;
   vector<float>   *jTowerEt_Had;
   vector<int>     *jTowerNCells_Had;
   vector<float>   *Run2_TT_eta;
   vector<float>   *Run2_TT_phi;
   vector<float>   *Run2_TT_JEP_Et;
   vector<float>   *Run2_TT_CP_Et;
   vector<bool>    *Run2_TT_IsTile;
   vector<unsigned int> *Run2_TT_CoolID;
   vector<float>   *Run2_L1Jet_Et;
   vector<float>   *Run2_L1Jet_eta;
   vector<float>   *Run2_L1Jet_phi;
   vector<float>   *Run2_AntiKt4TT_Et;
   vector<float>   *Run2_AntiKt4TT_eta;
   vector<float>   *Run2_AntiKt4TT_phi;
   vector<float>   *ConeGJet10_Et;
   vector<float>   *ConeGJet10_eta;
   vector<float>   *ConeGJet10_phi;
   vector<int>     *ConeGJet10_seedIndex;
   vector<float>   *JFexJet_Et;
   vector<float>   *JFexJet_eta;
   vector<float>   *JFexJet_phi;
   vector<float>   *AntiKt10gT_Et;
   vector<float>   *AntiKt10gT_eta;
   vector<float>   *AntiKt10gT_phi;
   vector<float>   *AntiKt4jT_Et;
   vector<float>   *AntiKt4jT_eta;
   vector<float>   *AntiKt4jT_phi;
   Int_t           AntiKt10LCTopoJets_n;
   vector<float>   *AntiKt10LCTopoJets_pt;
   vector<float>   *AntiKt10LCTopoJets_eta;
   vector<float>   *AntiKt10LCTopoJets_phi;
   vector<float>   *AntiKt10LCTopoJets_m;
   Int_t           AntiKt4LCTopoJets_n;
   vector<float>   *AntiKt4LCTopoJets_pt;
   vector<float>   *AntiKt4LCTopoJets_eta;
   vector<float>   *AntiKt4LCTopoJets_phi;
   vector<float>   *AntiKt4LCTopoJets_m;
   Int_t           CamKt12LCTopoJets_n;
   vector<float>   *CamKt12LCTopoJets_pt;
   vector<float>   *CamKt12LCTopoJets_eta;
   vector<float>   *CamKt12LCTopoJets_phi;
   vector<float>   *CamKt12LCTopoJets_m;
   Int_t           AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_n;
   vector<int>     *AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m;
   Int_t           AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_n;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi;
   vector<float>   *AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m;
   Int_t           AntiKt10TruthJets_n;
   vector<float>   *AntiKt10TruthJets_pt;
   vector<float>   *AntiKt10TruthJets_eta;
   vector<float>   *AntiKt10TruthJets_phi;
   vector<float>   *AntiKt10TruthJets_m;
   Int_t           AntiKt4TruthJets_n;
   vector<float>   *AntiKt4TruthJets_pt;
   vector<float>   *AntiKt4TruthJets_eta;
   vector<float>   *AntiKt4TruthJets_phi;
   vector<float>   *AntiKt4TruthJets_m;
   Int_t           CamKt12TruthJets_n;
   vector<float>   *CamKt12TruthJets_pt;
   vector<float>   *CamKt12TruthJets_eta;
   vector<float>   *CamKt12TruthJets_phi;
   vector<float>   *CamKt12TruthJets_m;
   Float_t         JFexMET;
   Float_t         JFexMET_phi;
   Float_t         MET_Truth_NonInt_mpx;
   Float_t         MET_Truth_NonInt_mpy;
   Float_t         MET_Truth_NonInt_sumet;
   Float_t         MET_Truth_Int_mpx;
   Float_t         MET_Truth_Int_mpy;
   Float_t         MET_Truth_Int_sumet;
   Float_t         MET_Truth_IntOut_mpx;
   Float_t         MET_Truth_IntOut_mpy;
   Float_t         MET_Truth_IntOut_sumet;
   Float_t         MET_Truth_IntMuons_mpx;
   Float_t         MET_Truth_IntMuons_mpy;
   Float_t         MET_Truth_IntMuons_sumet;
   Float_t         MET_Truth_IntCentral_mpx;
   Float_t         MET_Truth_IntEndCap_mpx;
   Float_t         MET_Truth_IntForward_mpx;
   Float_t         MET_Truth_IntCentral_mpy;
   Float_t         MET_Truth_IntEndCap_mpy;
   Float_t         MET_Truth_IntForward_mpy;
   Float_t         MET_Truth_IntCentral_sumet;
   Float_t         MET_Truth_IntEndCap_sumet;
   Float_t         MET_Truth_IntForward_sumet;
   Int_t           eventNumber;
   Float_t         weight;
   vector<float>   *mcEventWeight;
   Float_t         actualIntPerCross;
   Float_t         averageIntPerCross;
   Int_t           PileUp_inTime_MinBias;
   Int_t           distFrontBunchTrain;
   Int_t           BCID;
   Float_t         Kt4LCTopoEventShape_Density;
   Float_t         Kt4LCTopoEventShape_DensityArea;
   Float_t         Kt4LCTopoEventShape_DensitySigma;
   Float_t         Kt4EMTopoEventShape_Density;
   Float_t         Kt4EMTopoEventShape_DensityArea;
   Float_t         Kt4EMTopoEventShape_DensitySigma;
   Float_t         Kt4EMPFlowEventShape_Density;
   Float_t         Kt4EMPFlowEventShape_DensityArea;
   Float_t         Kt4EMPFlowEventShape_DensitySigma;

   // List of branches
   TBranch        *b_scells_Et;   //!
   TBranch        *b_scells_time;   //!
   TBranch        *b_scells_provenance;   //!
   TBranch        *b_scells_quality;   //!
   TBranch        *b_gTowerEt;   //!
   TBranch        *b_gTowerPhiWeighted;   //!
   TBranch        *b_gTowerEtaWeighted;   //!
   TBranch        *b_gTowerNCells;   //!
   TBranch        *b_gTowerEt_EM;   //!
   TBranch        *b_gTowerPhi_EM;   //!
   TBranch        *b_gTowerEta_EM;   //!
   TBranch        *b_gTowerPhiWeighted_EM;   //!
   TBranch        *b_gTowerEtaWeighted_EM;   //!
   TBranch        *b_gTowerNCells_EM;   //!
   TBranch        *b_gTowerEt_Had;   //!
   TBranch        *b_gTowerPhi_Had;   //!
   TBranch        *b_gTowerEta_Had;   //!
   TBranch        *b_gTowerPhiWeighted_Had;   //!
   TBranch        *b_gTowerEtaWeighted_Had;   //!
   TBranch        *b_gTowerNCells_Had;   //!
   TBranch        *b_jTowerEt;   //!
   TBranch        *b_jTowerNCells;   //!
   TBranch        *b_jTowerEt_EM;   //!
   TBranch        *b_jTowerNCells_EM;   //!
   TBranch        *b_jTowerEt_Had;   //!
   TBranch        *b_jTowerNCells_Had;   //!
   TBranch        *b_Run2_TT_eta;   //!
   TBranch        *b_Run2_TT_phi;   //!
   TBranch        *b_Run2_TT_JEP_Et;   //!
   TBranch        *b_Run2_TT_CP_Et;   //!
   TBranch        *b_Run2_TT_IsTile;   //!
   TBranch        *b_Run2_TT_CoolID;   //!
   TBranch        *b_Run2_L1Jet_Et;   //!
   TBranch        *b_Run2_L1Jet_eta;   //!
   TBranch        *b_Run2_L1Jet_phi;   //!
   TBranch        *b_Run2_AntiKt4TT_Et;   //!
   TBranch        *b_Run2_AntiKt4TT_eta;   //!
   TBranch        *b_Run2_AntiKt4TT_phi;   //!
   TBranch        *b_ConeGJet10_Et;   //!
   TBranch        *b_ConeGJet10_eta;   //!
   TBranch        *b_ConeGJet10_phi;   //!
   TBranch        *b_ConeGJet10_seedIndex;   //!
   TBranch        *b_JFexJet_Et;   //!
   TBranch        *b_JFexJet_eta;   //!
   TBranch        *b_JFexJet_phi;   //!
   TBranch        *b_AntiKt10gT_Et;   //!
   TBranch        *b_AntiKt10gT_eta;   //!
   TBranch        *b_AntiKt10gT_phi;   //!
   TBranch        *b_AntiKt4jT_Et;   //!
   TBranch        *b_AntiKt4jT_eta;   //!
   TBranch        *b_AntiKt4jT_phi;   //!
   TBranch        *b_AntiKt10LCTopoJets_n;   //!
   TBranch        *b_AntiKt10LCTopoJets_pt;   //!
   TBranch        *b_AntiKt10LCTopoJets_eta;   //!
   TBranch        *b_AntiKt10LCTopoJets_phi;   //!
   TBranch        *b_AntiKt10LCTopoJets_m;   //!
   TBranch        *b_AntiKt4LCTopoJets_n;   //!
   TBranch        *b_AntiKt4LCTopoJets_pt;   //!
   TBranch        *b_AntiKt4LCTopoJets_eta;   //!
   TBranch        *b_AntiKt4LCTopoJets_phi;   //!
   TBranch        *b_AntiKt4LCTopoJets_m;   //!
   TBranch        *b_CamKt12LCTopoJets_n;   //!
   TBranch        *b_CamKt12LCTopoJets_pt;   //!
   TBranch        *b_CamKt12LCTopoJets_eta;   //!
   TBranch        *b_CamKt12LCTopoJets_phi;   //!
   TBranch        *b_CamKt12LCTopoJets_m;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_n;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_n;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi;   //!
   TBranch        *b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m;   //!
   TBranch        *b_AntiKt10TruthJets_n;   //!
   TBranch        *b_AntiKt10TruthJets_pt;   //!
   TBranch        *b_AntiKt10TruthJets_eta;   //!
   TBranch        *b_AntiKt10TruthJets_phi;   //!
   TBranch        *b_AntiKt10TruthJets_m;   //!
   TBranch        *b_AntiKt4TruthJets_n;   //!
   TBranch        *b_AntiKt4TruthJets_pt;   //!
   TBranch        *b_AntiKt4TruthJets_eta;   //!
   TBranch        *b_AntiKt4TruthJets_phi;   //!
   TBranch        *b_AntiKt4TruthJets_m;   //!
   TBranch        *b_CamKt12TruthJets_n;   //!
   TBranch        *b_CamKt12TruthJets_pt;   //!
   TBranch        *b_CamKt12TruthJets_eta;   //!
   TBranch        *b_CamKt12TruthJets_phi;   //!
   TBranch        *b_CamKt12TruthJets_m;   //!
   TBranch        *b_JFexMET;   //!
   TBranch        *b_JFexMET_phi;   //!
   TBranch        *b_MET_Truth_NonInt_mpx;   //!
   TBranch        *b_MET_Truth_NonInt_mpy;   //!
   TBranch        *b_MET_Truth_NonInt_sumet;   //!
   TBranch        *b_MET_Truth_Int_mpx;   //!
   TBranch        *b_MET_Truth_Int_mpy;   //!
   TBranch        *b_MET_Truth_Int_sumet;   //!
   TBranch        *b_MET_Truth_IntOut_mpx;   //!
   TBranch        *b_MET_Truth_IntOut_mpy;   //!
   TBranch        *b_MET_Truth_IntOut_sumet;   //!
   TBranch        *b_MET_Truth_IntMuons_mpx;   //!
   TBranch        *b_MET_Truth_IntMuons_mpy;   //!
   TBranch        *b_MET_Truth_IntMuons_sumet;   //!
   TBranch        *b_MET_Truth_IntCentral_mpx;   //!
   TBranch        *b_MET_Truth_IntEndCap_mpx;   //!
   TBranch        *b_MET_Truth_IntForward_mpx;   //!
   TBranch        *b_MET_Truth_IntCentral_mpy;   //!
   TBranch        *b_MET_Truth_IntEndCap_mpy;   //!
   TBranch        *b_MET_Truth_IntForward_mpy;   //!
   TBranch        *b_MET_Truth_IntCentral_sumet;   //!
   TBranch        *b_MET_Truth_IntEndCap_sumet;   //!
   TBranch        *b_MET_Truth_IntForward_sumet;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_mcEventWeight;   //!
   TBranch        *b_actualIntPerCross;   //!
   TBranch        *b_averageIntPerCross;   //!
   TBranch        *b_PileUp_inTime_MinBias;   //!
   TBranch        *b_distFrontBunchTrain;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_Kt4LCTopoEventShape_Density;   //!
   TBranch        *b_Kt4LCTopoEventShape_DensityArea;   //!
   TBranch        *b_Kt4LCTopoEventShape_DensitySigma;   //!
   TBranch        *b_Kt4EMTopoEventShape_Density;   //!
   TBranch        *b_Kt4EMTopoEventShape_DensityArea;   //!
   TBranch        *b_Kt4EMTopoEventShape_DensitySigma;   //!
   TBranch        *b_Kt4EMPFlowEventShape_Density;   //!
   TBranch        *b_Kt4EMPFlowEventShape_DensityArea;   //!
   TBranch        *b_Kt4EMPFlowEventShape_DensitySigma;   //!

   croot_tmp(TTree *tree=0);
   virtual ~croot_tmp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     decToBinary (FILE *fo, int n, const int precision);
};

#endif

#ifdef croot_tmp_cxx
croot_tmp::croot_tmp(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/user.cylin.8535524.OUTPUT._000002.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("data/user.cylin.8535524.OUTPUT._000002.root");
      }
      f->GetObject("mytree",tree);

   }
   Init(tree);
}

croot_tmp::~croot_tmp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t croot_tmp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t croot_tmp::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void croot_tmp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   scells_Et = 0;
   scells_time = 0;
   scells_provenance = 0;
   scells_quality = 0;
   gTowerEt = 0;
   gTowerPhiWeighted = 0;
   gTowerEtaWeighted = 0;
   gTowerNCells = 0;
   gTowerEt_EM = 0;
   gTowerPhi_EM = 0;
   gTowerEta_EM = 0;
   gTowerPhiWeighted_EM = 0;
   gTowerEtaWeighted_EM = 0;
   gTowerNCells_EM = 0;
   gTowerEt_Had = 0;
   gTowerPhi_Had = 0;
   gTowerEta_Had = 0;
   gTowerPhiWeighted_Had = 0;
   gTowerEtaWeighted_Had = 0;
   gTowerNCells_Had = 0;
   jTowerEt = 0;
   jTowerNCells = 0;
   jTowerEt_EM = 0;
   jTowerNCells_EM = 0;
   jTowerEt_Had = 0;
   jTowerNCells_Had = 0;
   Run2_TT_eta = 0;
   Run2_TT_phi = 0;
   Run2_TT_JEP_Et = 0;
   Run2_TT_CP_Et = 0;
   Run2_TT_IsTile = 0;
   Run2_TT_CoolID = 0;
   Run2_L1Jet_Et = 0;
   Run2_L1Jet_eta = 0;
   Run2_L1Jet_phi = 0;
   Run2_AntiKt4TT_Et = 0;
   Run2_AntiKt4TT_eta = 0;
   Run2_AntiKt4TT_phi = 0;
   ConeGJet10_Et = 0;
   ConeGJet10_eta = 0;
   ConeGJet10_phi = 0;
   ConeGJet10_seedIndex = 0;
   JFexJet_Et = 0;
   JFexJet_eta = 0;
   JFexJet_phi = 0;
   AntiKt10gT_Et = 0;
   AntiKt10gT_eta = 0;
   AntiKt10gT_phi = 0;
   AntiKt4jT_Et = 0;
   AntiKt4jT_eta = 0;
   AntiKt4jT_phi = 0;
   AntiKt10LCTopoJets_pt = 0;
   AntiKt10LCTopoJets_eta = 0;
   AntiKt10LCTopoJets_phi = 0;
   AntiKt10LCTopoJets_m = 0;
   AntiKt4LCTopoJets_pt = 0;
   AntiKt4LCTopoJets_eta = 0;
   AntiKt4LCTopoJets_phi = 0;
   AntiKt4LCTopoJets_m = 0;
   CamKt12LCTopoJets_pt = 0;
   CamKt12LCTopoJets_eta = 0;
   CamKt12LCTopoJets_phi = 0;
   CamKt12LCTopoJets_m = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi = 0;
   AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m = 0;
   AntiKt10TruthJets_pt = 0;
   AntiKt10TruthJets_eta = 0;
   AntiKt10TruthJets_phi = 0;
   AntiKt10TruthJets_m = 0;
   AntiKt4TruthJets_pt = 0;
   AntiKt4TruthJets_eta = 0;
   AntiKt4TruthJets_phi = 0;
   AntiKt4TruthJets_m = 0;
   CamKt12TruthJets_pt = 0;
   CamKt12TruthJets_eta = 0;
   CamKt12TruthJets_phi = 0;
   CamKt12TruthJets_m = 0;
   mcEventWeight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("scells_Et", &scells_Et, &b_scells_Et);
   fChain->SetBranchAddress("scells_time", &scells_time, &b_scells_time);
   fChain->SetBranchAddress("scells_provenance", &scells_provenance, &b_scells_provenance);
   fChain->SetBranchAddress("scells_quality", &scells_quality, &b_scells_quality);
   fChain->SetBranchAddress("gTowerEt", &gTowerEt, &b_gTowerEt);
   fChain->SetBranchAddress("gTowerPhiWeighted", &gTowerPhiWeighted, &b_gTowerPhiWeighted);
   fChain->SetBranchAddress("gTowerEtaWeighted", &gTowerEtaWeighted, &b_gTowerEtaWeighted);
   fChain->SetBranchAddress("gTowerNCells", &gTowerNCells, &b_gTowerNCells);
   fChain->SetBranchAddress("gTowerEt_EM", &gTowerEt_EM, &b_gTowerEt_EM);
   fChain->SetBranchAddress("gTowerPhi_EM", &gTowerPhi_EM, &b_gTowerPhi_EM);
   fChain->SetBranchAddress("gTowerEta_EM", &gTowerEta_EM, &b_gTowerEta_EM);
   fChain->SetBranchAddress("gTowerPhiWeighted_EM", &gTowerPhiWeighted_EM, &b_gTowerPhiWeighted_EM);
   fChain->SetBranchAddress("gTowerEtaWeighted_EM", &gTowerEtaWeighted_EM, &b_gTowerEtaWeighted_EM);
   fChain->SetBranchAddress("gTowerNCells_EM", &gTowerNCells_EM, &b_gTowerNCells_EM);
   fChain->SetBranchAddress("gTowerEt_Had", &gTowerEt_Had, &b_gTowerEt_Had);
   fChain->SetBranchAddress("gTowerPhi_Had", &gTowerPhi_Had, &b_gTowerPhi_Had);
   fChain->SetBranchAddress("gTowerEta_Had", &gTowerEta_Had, &b_gTowerEta_Had);
   fChain->SetBranchAddress("gTowerPhiWeighted_Had", &gTowerPhiWeighted_Had, &b_gTowerPhiWeighted_Had);
   fChain->SetBranchAddress("gTowerEtaWeighted_Had", &gTowerEtaWeighted_Had, &b_gTowerEtaWeighted_Had);
   fChain->SetBranchAddress("gTowerNCells_Had", &gTowerNCells_Had, &b_gTowerNCells_Had);
   fChain->SetBranchAddress("jTowerEt", &jTowerEt, &b_jTowerEt);
   fChain->SetBranchAddress("jTowerNCells", &jTowerNCells, &b_jTowerNCells);
   fChain->SetBranchAddress("jTowerEt_EM", &jTowerEt_EM, &b_jTowerEt_EM);
   fChain->SetBranchAddress("jTowerNCells_EM", &jTowerNCells_EM, &b_jTowerNCells_EM);
   fChain->SetBranchAddress("jTowerEt_Had", &jTowerEt_Had, &b_jTowerEt_Had);
   fChain->SetBranchAddress("jTowerNCells_Had", &jTowerNCells_Had, &b_jTowerNCells_Had);
   fChain->SetBranchAddress("Run2_TT_eta", &Run2_TT_eta, &b_Run2_TT_eta);
   fChain->SetBranchAddress("Run2_TT_phi", &Run2_TT_phi, &b_Run2_TT_phi);
   fChain->SetBranchAddress("Run2_TT_JEP_Et", &Run2_TT_JEP_Et, &b_Run2_TT_JEP_Et);
   fChain->SetBranchAddress("Run2_TT_CP_Et", &Run2_TT_CP_Et, &b_Run2_TT_CP_Et);
   fChain->SetBranchAddress("Run2_TT_IsTile", &Run2_TT_IsTile, &b_Run2_TT_IsTile);
   fChain->SetBranchAddress("Run2_TT_CoolID", &Run2_TT_CoolID, &b_Run2_TT_CoolID);
   fChain->SetBranchAddress("Run2_L1Jet_Et", &Run2_L1Jet_Et, &b_Run2_L1Jet_Et);
   fChain->SetBranchAddress("Run2_L1Jet_eta", &Run2_L1Jet_eta, &b_Run2_L1Jet_eta);
   fChain->SetBranchAddress("Run2_L1Jet_phi", &Run2_L1Jet_phi, &b_Run2_L1Jet_phi);
   fChain->SetBranchAddress("Run2_AntiKt4TT_Et", &Run2_AntiKt4TT_Et, &b_Run2_AntiKt4TT_Et);
   fChain->SetBranchAddress("Run2_AntiKt4TT_eta", &Run2_AntiKt4TT_eta, &b_Run2_AntiKt4TT_eta);
   fChain->SetBranchAddress("Run2_AntiKt4TT_phi", &Run2_AntiKt4TT_phi, &b_Run2_AntiKt4TT_phi);
   fChain->SetBranchAddress("ConeGJet10_Et", &ConeGJet10_Et, &b_ConeGJet10_Et);
   fChain->SetBranchAddress("ConeGJet10_eta", &ConeGJet10_eta, &b_ConeGJet10_eta);
   fChain->SetBranchAddress("ConeGJet10_phi", &ConeGJet10_phi, &b_ConeGJet10_phi);
   fChain->SetBranchAddress("ConeGJet10_seedIndex", &ConeGJet10_seedIndex, &b_ConeGJet10_seedIndex);
   fChain->SetBranchAddress("JFexJet_Et", &JFexJet_Et, &b_JFexJet_Et);
   fChain->SetBranchAddress("JFexJet_eta", &JFexJet_eta, &b_JFexJet_eta);
   fChain->SetBranchAddress("JFexJet_phi", &JFexJet_phi, &b_JFexJet_phi);
   fChain->SetBranchAddress("AntiKt10gT_Et", &AntiKt10gT_Et, &b_AntiKt10gT_Et);
   fChain->SetBranchAddress("AntiKt10gT_eta", &AntiKt10gT_eta, &b_AntiKt10gT_eta);
   fChain->SetBranchAddress("AntiKt10gT_phi", &AntiKt10gT_phi, &b_AntiKt10gT_phi);
   fChain->SetBranchAddress("AntiKt4jT_Et", &AntiKt4jT_Et, &b_AntiKt4jT_Et);
   fChain->SetBranchAddress("AntiKt4jT_eta", &AntiKt4jT_eta, &b_AntiKt4jT_eta);
   fChain->SetBranchAddress("AntiKt4jT_phi", &AntiKt4jT_phi, &b_AntiKt4jT_phi);
   fChain->SetBranchAddress("AntiKt10LCTopoJets_n", &AntiKt10LCTopoJets_n, &b_AntiKt10LCTopoJets_n);
   fChain->SetBranchAddress("AntiKt10LCTopoJets_pt", &AntiKt10LCTopoJets_pt, &b_AntiKt10LCTopoJets_pt);
   fChain->SetBranchAddress("AntiKt10LCTopoJets_eta", &AntiKt10LCTopoJets_eta, &b_AntiKt10LCTopoJets_eta);
   fChain->SetBranchAddress("AntiKt10LCTopoJets_phi", &AntiKt10LCTopoJets_phi, &b_AntiKt10LCTopoJets_phi);
   fChain->SetBranchAddress("AntiKt10LCTopoJets_m", &AntiKt10LCTopoJets_m, &b_AntiKt10LCTopoJets_m);
   fChain->SetBranchAddress("AntiKt4LCTopoJets_n", &AntiKt4LCTopoJets_n, &b_AntiKt4LCTopoJets_n);
   fChain->SetBranchAddress("AntiKt4LCTopoJets_pt", &AntiKt4LCTopoJets_pt, &b_AntiKt4LCTopoJets_pt);
   fChain->SetBranchAddress("AntiKt4LCTopoJets_eta", &AntiKt4LCTopoJets_eta, &b_AntiKt4LCTopoJets_eta);
   fChain->SetBranchAddress("AntiKt4LCTopoJets_phi", &AntiKt4LCTopoJets_phi, &b_AntiKt4LCTopoJets_phi);
   fChain->SetBranchAddress("AntiKt4LCTopoJets_m", &AntiKt4LCTopoJets_m, &b_AntiKt4LCTopoJets_m);
   fChain->SetBranchAddress("CamKt12LCTopoJets_n", &CamKt12LCTopoJets_n, &b_CamKt12LCTopoJets_n);
   fChain->SetBranchAddress("CamKt12LCTopoJets_pt", &CamKt12LCTopoJets_pt, &b_CamKt12LCTopoJets_pt);
   fChain->SetBranchAddress("CamKt12LCTopoJets_eta", &CamKt12LCTopoJets_eta, &b_CamKt12LCTopoJets_eta);
   fChain->SetBranchAddress("CamKt12LCTopoJets_phi", &CamKt12LCTopoJets_phi, &b_CamKt12LCTopoJets_phi);
   fChain->SetBranchAddress("CamKt12LCTopoJets_m", &CamKt12LCTopoJets_m, &b_CamKt12LCTopoJets_m);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_n", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_n, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_n);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_nsj);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_pt);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_eta);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_phi);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m", &AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5Jets_m);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_n", &AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_n, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_n);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt", &AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_pt);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta", &AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_eta);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi", &AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_phi);
   fChain->SetBranchAddress("AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m", &AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m, &b_AntiKt10LCTopoTrimmedSmallR20PtFrac5SubJets_m);
   fChain->SetBranchAddress("AntiKt10TruthJets_n", &AntiKt10TruthJets_n, &b_AntiKt10TruthJets_n);
   fChain->SetBranchAddress("AntiKt10TruthJets_pt", &AntiKt10TruthJets_pt, &b_AntiKt10TruthJets_pt);
   fChain->SetBranchAddress("AntiKt10TruthJets_eta", &AntiKt10TruthJets_eta, &b_AntiKt10TruthJets_eta);
   fChain->SetBranchAddress("AntiKt10TruthJets_phi", &AntiKt10TruthJets_phi, &b_AntiKt10TruthJets_phi);
   fChain->SetBranchAddress("AntiKt10TruthJets_m", &AntiKt10TruthJets_m, &b_AntiKt10TruthJets_m);
   fChain->SetBranchAddress("AntiKt4TruthJets_n", &AntiKt4TruthJets_n, &b_AntiKt4TruthJets_n);
   fChain->SetBranchAddress("AntiKt4TruthJets_pt", &AntiKt4TruthJets_pt, &b_AntiKt4TruthJets_pt);
   fChain->SetBranchAddress("AntiKt4TruthJets_eta", &AntiKt4TruthJets_eta, &b_AntiKt4TruthJets_eta);
   fChain->SetBranchAddress("AntiKt4TruthJets_phi", &AntiKt4TruthJets_phi, &b_AntiKt4TruthJets_phi);
   fChain->SetBranchAddress("AntiKt4TruthJets_m", &AntiKt4TruthJets_m, &b_AntiKt4TruthJets_m);
   fChain->SetBranchAddress("CamKt12TruthJets_n", &CamKt12TruthJets_n, &b_CamKt12TruthJets_n);
   fChain->SetBranchAddress("CamKt12TruthJets_pt", &CamKt12TruthJets_pt, &b_CamKt12TruthJets_pt);
   fChain->SetBranchAddress("CamKt12TruthJets_eta", &CamKt12TruthJets_eta, &b_CamKt12TruthJets_eta);
   fChain->SetBranchAddress("CamKt12TruthJets_phi", &CamKt12TruthJets_phi, &b_CamKt12TruthJets_phi);
   fChain->SetBranchAddress("CamKt12TruthJets_m", &CamKt12TruthJets_m, &b_CamKt12TruthJets_m);
   fChain->SetBranchAddress("JFexMET", &JFexMET, &b_JFexMET);
   fChain->SetBranchAddress("JFexMET_phi", &JFexMET_phi, &b_JFexMET_phi);
   fChain->SetBranchAddress("MET_Truth_NonInt_mpx", &MET_Truth_NonInt_mpx, &b_MET_Truth_NonInt_mpx);
   fChain->SetBranchAddress("MET_Truth_NonInt_mpy", &MET_Truth_NonInt_mpy, &b_MET_Truth_NonInt_mpy);
   fChain->SetBranchAddress("MET_Truth_NonInt_sumet", &MET_Truth_NonInt_sumet, &b_MET_Truth_NonInt_sumet);
   fChain->SetBranchAddress("MET_Truth_Int_mpx", &MET_Truth_Int_mpx, &b_MET_Truth_Int_mpx);
   fChain->SetBranchAddress("MET_Truth_Int_mpy", &MET_Truth_Int_mpy, &b_MET_Truth_Int_mpy);
   fChain->SetBranchAddress("MET_Truth_Int_sumet", &MET_Truth_Int_sumet, &b_MET_Truth_Int_sumet);
   fChain->SetBranchAddress("MET_Truth_IntOut_mpx", &MET_Truth_IntOut_mpx, &b_MET_Truth_IntOut_mpx);
   fChain->SetBranchAddress("MET_Truth_IntOut_mpy", &MET_Truth_IntOut_mpy, &b_MET_Truth_IntOut_mpy);
   fChain->SetBranchAddress("MET_Truth_IntOut_sumet", &MET_Truth_IntOut_sumet, &b_MET_Truth_IntOut_sumet);
   fChain->SetBranchAddress("MET_Truth_IntMuons_mpx", &MET_Truth_IntMuons_mpx, &b_MET_Truth_IntMuons_mpx);
   fChain->SetBranchAddress("MET_Truth_IntMuons_mpy", &MET_Truth_IntMuons_mpy, &b_MET_Truth_IntMuons_mpy);
   fChain->SetBranchAddress("MET_Truth_IntMuons_sumet", &MET_Truth_IntMuons_sumet, &b_MET_Truth_IntMuons_sumet);
   fChain->SetBranchAddress("MET_Truth_IntCentral_mpx", &MET_Truth_IntCentral_mpx, &b_MET_Truth_IntCentral_mpx);
   fChain->SetBranchAddress("MET_Truth_IntEndCap_mpx", &MET_Truth_IntEndCap_mpx, &b_MET_Truth_IntEndCap_mpx);
   fChain->SetBranchAddress("MET_Truth_IntForward_mpx", &MET_Truth_IntForward_mpx, &b_MET_Truth_IntForward_mpx);
   fChain->SetBranchAddress("MET_Truth_IntCentral_mpy", &MET_Truth_IntCentral_mpy, &b_MET_Truth_IntCentral_mpy);
   fChain->SetBranchAddress("MET_Truth_IntEndCap_mpy", &MET_Truth_IntEndCap_mpy, &b_MET_Truth_IntEndCap_mpy);
   fChain->SetBranchAddress("MET_Truth_IntForward_mpy", &MET_Truth_IntForward_mpy, &b_MET_Truth_IntForward_mpy);
   fChain->SetBranchAddress("MET_Truth_IntCentral_sumet", &MET_Truth_IntCentral_sumet, &b_MET_Truth_IntCentral_sumet);
   fChain->SetBranchAddress("MET_Truth_IntEndCap_sumet", &MET_Truth_IntEndCap_sumet, &b_MET_Truth_IntEndCap_sumet);
   fChain->SetBranchAddress("MET_Truth_IntForward_sumet", &MET_Truth_IntForward_sumet, &b_MET_Truth_IntForward_sumet);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
   fChain->SetBranchAddress("actualIntPerCross", &actualIntPerCross, &b_actualIntPerCross);
   fChain->SetBranchAddress("averageIntPerCross", &averageIntPerCross, &b_averageIntPerCross);
   fChain->SetBranchAddress("PileUp_inTime_MinBias", &PileUp_inTime_MinBias, &b_PileUp_inTime_MinBias);
   fChain->SetBranchAddress("distFrontBunchTrain", &distFrontBunchTrain, &b_distFrontBunchTrain);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("Kt4LCTopoEventShape_Density", &Kt4LCTopoEventShape_Density, &b_Kt4LCTopoEventShape_Density);
   fChain->SetBranchAddress("Kt4LCTopoEventShape_DensityArea", &Kt4LCTopoEventShape_DensityArea, &b_Kt4LCTopoEventShape_DensityArea);
   fChain->SetBranchAddress("Kt4LCTopoEventShape_DensitySigma", &Kt4LCTopoEventShape_DensitySigma, &b_Kt4LCTopoEventShape_DensitySigma);
   fChain->SetBranchAddress("Kt4EMTopoEventShape_Density", &Kt4EMTopoEventShape_Density, &b_Kt4EMTopoEventShape_Density);
   fChain->SetBranchAddress("Kt4EMTopoEventShape_DensityArea", &Kt4EMTopoEventShape_DensityArea, &b_Kt4EMTopoEventShape_DensityArea);
   fChain->SetBranchAddress("Kt4EMTopoEventShape_DensitySigma", &Kt4EMTopoEventShape_DensitySigma, &b_Kt4EMTopoEventShape_DensitySigma);
   fChain->SetBranchAddress("Kt4EMPFlowEventShape_Density", &Kt4EMPFlowEventShape_Density, &b_Kt4EMPFlowEventShape_Density);
   fChain->SetBranchAddress("Kt4EMPFlowEventShape_DensityArea", &Kt4EMPFlowEventShape_DensityArea, &b_Kt4EMPFlowEventShape_DensityArea);
   fChain->SetBranchAddress("Kt4EMPFlowEventShape_DensitySigma", &Kt4EMPFlowEventShape_DensitySigma, &b_Kt4EMPFlowEventShape_DensitySigma);
   Notify();
}

Bool_t croot_tmp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void croot_tmp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t croot_tmp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef croot_tmp_cxx
