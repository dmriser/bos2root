#ifndef ntuple_h
#define nutple_h


// -----------------
//   c++ standard  
// -----------------

// -----------------
//  old CLAS stuff
// -----------------
extern "C"{
#include <ntypes.h>
#include <bostypes.h>
}

// -----------------
//   cern root 
// -----------------
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class NTupleStructure {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           evntid;
   Int_t           ihel;
   Float_t         q_l;
   Float_t         tr_time;
   Int_t           gpart;
   Int_t           q[40];   //[gpart]
   Float_t         p[40];   //[gpart]
   Float_t         b[40];   //[gpart]
   Float_t         cx[40];   //[gpart]
   Float_t         cy[40];   //[gpart]
   Float_t         cz[40];   //[gpart]
   Float_t         vz[40];   //[gpart]
   Int_t           dc_sect[40];   //[gpart]
   Float_t         tl1_cx[40];   //[gpart]
   Float_t         tl1_cy[40];   //[gpart]
   Int_t           ec_sect[40];   //[gpart]
   Float_t         ec_r[40];   //[gpart]
   Float_t         ec_t[40];   //[gpart]
   Float_t         ec_ei[40];   //[gpart]
   Float_t         ec_eo[40];   //[gpart]
   Float_t         etot[40];   //[gpart]
   Int_t           cc_sect[40];   //[gpart]
   Float_t         cc_r[40];   //[gpart]
   Float_t         cc_t[40];   //[gpart]
   Int_t           nphe[40];   //[gpart]
   Float_t         cc_c2[40];   //[gpart]
   Int_t           sc_sect[40];   //[gpart]
   Float_t         sc_r[40];   //[gpart]
   Float_t         sc_t[40];   //[gpart]
   Float_t         edep[40];   //[gpart]
   Int_t           sc_pd[40];   //[gpart]
   Int_t           cc_segm[40];   //[gpart]
   Float_t         ech_x[40];   //[gpart]
   Float_t         ech_y[40];   //[gpart]
   Float_t         ech_z[40];   //[gpart]
   Float_t         tl1_x[40];   //[gpart]
   Float_t         tl1_y[40];   //[gpart]
   Float_t         tl1_z[40];   //[gpart]
   Float_t         tl3_x[40];   //[gpart]
   Float_t         tl3_y[40];   //[gpart]
   Float_t         tl3_z[40];   //[gpart]
   Float_t         tl3_cx[40];   //[gpart]
   Float_t         tl3_cy[40];   //[gpart]
   Float_t         tl3_cz[40];   //[gpart]
   Int_t           id[40];   //[gpart]
   Float_t         vx[40];   //[gpart]
   Float_t         vy[40];   //[gpart]
   Int_t           nprt;
   Int_t           pidpart[20];   //[nprt]
   Float_t         xpart[20];   //[nprt]
   Float_t         ypart[20];   //[nprt]
   Float_t         zpart[20];   //[nprt]
   Float_t         epart[20];   //[nprt]
   Float_t         pxpart[20];   //[nprt]
   Float_t         pypart[20];   //[nprt]
   Float_t         pzpart[20];   //[nprt]
   Float_t         qpart[20];   //[nprt]
   Int_t           Ipart10[20];   //[nprt]
   Float_t         Rpart11[20];   //[nprt]
   Float_t         Rpart12[20];   //[nprt]
   Int_t           Ipart13[20];   //[nprt]
   Int_t           mcnentr;
   Int_t           mcnpart;
   Int_t           mcst[40];   //[mcnentr]
   Int_t           mcid[40];   //[mcnentr]
   Int_t           mcpid[40];   //[mcnentr]
   Float_t         mctheta[40];   //[mcnentr]
   Float_t         mcphi[40];   //[mcnentr]
   Float_t         mcp[40];   //[mcnentr]
   Float_t         mcm[40];   //[mcnentr]
   Float_t         mcvx[40];   //[mcnentr]
   Float_t         mcvy[40];   //[mcnentr]
   Float_t         mcvz[40];   //[mcnentr]
   Float_t         mctof[40];   //[mcnentr]


   // Set by HEVT 
   int cc_point; 
   int dc_point; 
   int ec_point;    
   int sc_point; 
   int status; 


   // List of branches
   TBranch        *b_evntid;   //!
   TBranch        *b_ihel;   //!
   TBranch        *b_q_l;   //!
   TBranch        *b_tr_time;   //!
   TBranch        *b_gpart;   //!
   TBranch        *b_q;   //!
   TBranch        *b_p;   //!
   TBranch        *b_b;   //!
   TBranch        *b_cx;   //!
   TBranch        *b_cy;   //!
   TBranch        *b_cz;   //!
   TBranch        *b_vz;   //!
   TBranch        *b_dc_sect;   //!
   TBranch        *b_tl1_cx;   //!
   TBranch        *b_tl1_cy;   //!
   TBranch        *b_ec_sect;   //!
   TBranch        *b_ec_r;   //!
   TBranch        *b_ec_t;   //!
   TBranch        *b_ec_ei;   //!
   TBranch        *b_ec_eo;   //!
   TBranch        *b_etot;   //!
   TBranch        *b_cc_sect;   //!
   TBranch        *b_cc_r;   //!
   TBranch        *b_cc_t;   //!
   TBranch        *b_nphe;   //!
   TBranch        *b_cc_c2;   //!
   TBranch        *b_sc_sect;   //!
   TBranch        *b_sc_r;   //!
   TBranch        *b_sc_t;   //!
   TBranch        *b_edep;   //!
   TBranch        *b_sc_pd;   //!
   TBranch        *b_cc_segm;   //!
   TBranch        *b_ech_x;   //!
   TBranch        *b_ech_y;   //!
   TBranch        *b_ech_z;   //!
   TBranch        *b_tl1_x;   //!
   TBranch        *b_tl1_y;   //!
   TBranch        *b_tl1_z;   //!
   TBranch        *b_tl3_x;   //!
   TBranch        *b_tl3_y;   //!
   TBranch        *b_tl3_z;   //!
   TBranch        *b_tl3_cx;   //!
   TBranch        *b_tl3_cy;   //!
   TBranch        *b_tl3_cz;   //!
   TBranch        *b_id;   //!
   TBranch        *b_vx;   //!
   TBranch        *b_vy;   //!
   TBranch        *b_nprt;   //!
   TBranch        *b_pidpart;   //!
   TBranch        *b_xpart;   //!
   TBranch        *b_ypart;   //!
   TBranch        *b_zpart;   //!
   TBranch        *b_epart;   //!
   TBranch        *b_pxpart;   //!
   TBranch        *b_pypart;   //!
   TBranch        *b_pzpart;   //!
   TBranch        *b_qpart;   //!
   TBranch        *b_Ipart10;   //!
   TBranch        *b_Rpart11;   //!
   TBranch        *b_Rpart12;   //!
   TBranch        *b_Ipart13;   //!
   TBranch        *b_mcnentr;   //!
   TBranch        *b_mcnpart;   //!
   TBranch        *b_mcst;   //!
   TBranch        *b_mcid;   //!
   TBranch        *b_mcpid;   //!
   TBranch        *b_mctheta;   //!
   TBranch        *b_mcphi;   //!
   TBranch        *b_mcp;   //!
   TBranch        *b_mcm;   //!
   TBranch        *b_mcvx;   //!
   TBranch        *b_mcvy;   //!
   TBranch        *b_mcvz;   //!
   TBranch        *b_mctof;   //!

   NTupleStructure();
   virtual ~NTupleStructure();
   virtual void     Init();
   void SetZero();
   void SetGPart(clasEVNT_t *EVNT){ gpart = EVNT->bank.nrow; }

   void SetCCInformation(clasCCPB_t *CCPB, int index);
   void SetDCInformation(clasDCPB_t *DCPB, int index);
   void SetECInformation(clasECPB_t *ECPB, int index);
   void SetSCInformation(clasSCPB_t *SCPB, int index);
   void SetScalarInformation(clasTRGS_t *TRGS); 

   void SetPARTInformation(clasPART_t *PART);
   void SetHEADInformation(clasHEAD_t *HEAD);
   void SetHEVTInformation(clasHEVT_t *HEVT);
   void SetEVNTInformation(clasEVNT_t *EVNT, int index);

   void WriteEvent();
};

#endif
