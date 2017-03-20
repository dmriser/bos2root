#ifndef ntuple_cxx
#define ntuple_cxx


// --------------------
// old CLAS stuff
// --------------------
#include <cmath>


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "NTupleStructure.h"

// --------------------
// old CLAS stuff
// --------------------
extern "C"{
#include <ntypes.h>
#include <bostypes.h>
}

// --------------------
#include "Utilities.h"

NTupleStructure::NTupleStructure(){
    fChain = new TTree("h22","h22");
    Init();
    SetZero();
}

NTupleStructure::~NTupleStructure(){
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

void NTupleStructure::Init(){

    // Set branch addresses and branch pointers
    if (!fChain) return;

    b_gpart   = fChain->Branch("gpart",   &gpart,   "gpart/I");
    b_evntid  = fChain->Branch("evntid",  &evntid,  "evntid/I");
    b_ihel    = fChain->Branch("ihel",    &ihel,    "ihel/F");
    b_q_l     = fChain->Branch("q_l",     &q_l,     "q_l/F");
    b_tr_time = fChain->Branch("tr_time", &tr_time, "tr_time/F");
    b_q       = fChain->Branch("q",       q,        "q[gpart]/I");
    b_p       = fChain->Branch("p",       p,        "p[gpart]/F");
    b_b       = fChain->Branch("b",       b,        "b[gpart]/F");
    b_cx      = fChain->Branch("cx",      cx,       "cx[gpart]/F");
    b_cy      = fChain->Branch("cy",      cy,       "cy[gpart]/F");
    b_cz      = fChain->Branch("cz",      cz,       "cz[gpart]/F");
    b_vx      = fChain->Branch("vx",      vx,       "vx[gpart]/F");
    b_vy      = fChain->Branch("vy",      vy,       "vy[gpart]/F");
    b_vz      = fChain->Branch("vz",      vz,       "vz[gpart]/F");
    b_dc_sect = fChain->Branch("dc_sect", dc_sect,  "dc_sect[gpart]/I");
    b_tl1_cx  = fChain->Branch("tl1_cx",  tl1_cx,   "tl1_cx[gpart]/F");
    b_tl1_cy  = fChain->Branch("tl1_cy",  tl1_cy,   "tl1_cy[gpart]/F");
    b_ec_sect = fChain->Branch("ec_sect", ec_sect,  "ec_sect[gpart]/I");
    b_ec_r    = fChain->Branch("ec_r",    ec_r,     "ec_r[gpart]/F");
    b_ec_t    = fChain->Branch("ec_t",    ec_t,     "ec_t[gpart]/F");
    b_ec_ei   = fChain->Branch("ec_ei",   ec_ei,    "ec_ei[gpart]/F");
    b_ec_eo   = fChain->Branch("ec_eo",   ec_eo,    "ec_eo[gpart]/F");
    b_etot    = fChain->Branch("etot",    etot,     "etot[gpart]/F");
    b_cc_sect = fChain->Branch("cc_sect", cc_sect,  "cc_sect[gpart]/I");
    b_cc_segm = fChain->Branch("cc_segm", cc_segm,  "cc_segm[gpart]/I");
    b_cc_r    = fChain->Branch("cc_r",    cc_r,     "cc_r[gpart]/F");
    b_cc_t    = fChain->Branch("cc_t",    cc_t,     "cc_t[gpart]/F");
    b_nphe    = fChain->Branch("nphe",    nphe,     "nphe[gpart]/I");
    b_cc_c2   = fChain->Branch("cc_c2",   cc_c2,    "cc_c2[gpart]/F");
    b_sc_sect = fChain->Branch("sc_sect", sc_sect,  "sc_sect[gpart]/I");
    b_sc_r    = fChain->Branch("sc_r",    sc_r,     "sc_r[gpart]/F");
    b_sc_t    = fChain->Branch("sc_t",    sc_t,     "sc_t[gpart]/F");
    b_edep    = fChain->Branch("edep",    edep,     "edep[gpart]/F");
    b_sc_pd   = fChain->Branch("sc_pd",   sc_pd,    "sc_pd[gpart]/I");
    b_ech_x   = fChain->Branch("ech_x",   ech_x,    "ech_x[gpart]/F");
    b_ech_y   = fChain->Branch("ech_y",   ech_y,    "ech_y[gpart]/F");
    b_ech_z   = fChain->Branch("ech_z",   ech_z,    "ech_z[gpart]/F");
    b_tl1_x   = fChain->Branch("tl1_x",   tl1_x,    "tl1_x[gpart]/F");
    b_tl1_y   = fChain->Branch("tl1_y",   tl1_y,    "tl1_y[gpart]/F");
    b_tl1_z   = fChain->Branch("tl1_z",   tl1_z,    "tl1_z[gpart]/F");
    b_tl3_x   = fChain->Branch("tl3_x",   tl3_x,    "tl3_x[gpart]/F");
    b_tl3_y   = fChain->Branch("tl3_y",   tl3_y,    "tl3_y[gpart]/F");
    b_tl3_z   = fChain->Branch("tl3_z",   tl3_z,    "tl3_z[gpart]/F");
    b_tl3_cx  = fChain->Branch("tl3_cx",  tl3_cx,   "tl3_cx[gpart]/F");
    b_tl3_cy  = fChain->Branch("tl3_cy",  tl3_cy,   "tl3_cy[gpart]/F");
    b_tl3_cz  = fChain->Branch("tl3_cz",  tl3_cz,   "tl3_cz[gpart]/F");
    b_id      = fChain->Branch("id",      id,       "id[gpart]/I");

    // Monte Carlo banks with array size mcnentr
    b_mcnentr = fChain->Branch("mcnentr", &mcnentr, "mcnentr/I");
    b_mcnpart = fChain->Branch("mcnpart", &mcnpart, "mcnpart/I");
    b_mcst    = fChain->Branch("mcst",    mcst,     "mcst[mcnentr]/F");
    b_mcid    = fChain->Branch("mcid",    mcid,     "mcid[mcnentr]/I");
    b_mcpid   = fChain->Branch("mcpid",   mcpid,    "mcpid[mcnentr]/I");
    b_mctheta = fChain->Branch("mctheta", mctheta,  "mctheta[mcnentr]/F");
    b_mcphi   = fChain->Branch("mcphi",   mcphi,    "mcphi[mcnentr]/F");
    b_mcp     = fChain->Branch("mcp",     mcp,      "mcp[mcnentr]/F");
    b_mcm     = fChain->Branch("mcm",     mcm,      "mcm[mcnentr]/F");
    b_mcvx    = fChain->Branch("mcvx",    mcvx,     "mcvx[mcnentr]/F");
    b_mcvy    = fChain->Branch("mcvy",    mcvy,     "mcvy[mcnentr]/F");
    b_mcvz    = fChain->Branch("mcvz",    mcvz,     "mcvz[mcnentr]/F");
    b_mctof   = fChain->Branch("mctof",   mctof,    "mctof[mcnentr]/F");

    /*
   fChain->Branch("nprt", &nprt, &b_nprt);
   fChain->Branch("pidpart", pidpart, &b_pidpart);
   fChain->Branch("xpart", xpart, &b_xpart);
   fChain->Branch("ypart", ypart, &b_ypart);
   fChain->Branch("zpart", zpart, &b_zpart);
   fChain->Branch("epart", epart, &b_epart);
   fChain->Branch("pxpart", pxpart, &b_pxpart);
   fChain->Branch("pypart", pypart, &b_pypart);
   fChain->Branch("pzpart", pzpart, &b_pzpart);
   fChain->Branch("qpart", qpart, &b_qpart);
   fChain->Branch("Ipart10", Ipart10, &b_Ipart10);
   fChain->Branch("Rpart11", Rpart11, &b_Rpart11);
   fChain->Branch("Rpart12", Rpart12, &b_Rpart12);
   fChain->Branch("Ipart13", Ipart13, &b_Ipart13);
   */

}

void NTupleStructure::SetZero(){

    // Initialize to zero everything
    evntid   = 0;
    ihel     = 0;
    q_l      = 0.0;
    tr_time  = 0.0;
    gpart    = 0;
    cc_point = 0;
    dc_point = 0;
    ec_point = 0;
    sc_point = 0;
    status   = 0;
    mcnentr  = 0;
    mcnpart  = 0;

    for(int i=0; i<40; i++){

        q[i]       = 0;
        p[i]       = 0.0;
        b[i]       = 0.0;
        cx[i]      = 0.0;
        cy[i]      = 0.0;
        cz[i]      = 0.0;
        vz[i]      = 0.0;
        dc_sect[i] = 0;
        tl1_cx[i]  = 0.0;
        tl1_cy[i]  = 0.0;
        ec_sect[i] = 0;
        ec_r[i]    = 0.0;
        ec_t[i]    = 0.0;
        ec_ei[i]   = 0.0;
        ec_eo[i]   = 0.0;
        etot[i]    = 0.0;
        cc_sect[i] = 0;
        cc_r[i]    = 0.0;
        cc_t[i]    = 0.0;
        nphe[i]    = 0;
        cc_c2[i]   = 0.0;
        sc_sect[i] = 0;
        sc_r[i]    = 0.0;
        sc_t[i]    = 0.0;
        edep[i]    = 0.0;
        sc_pd[i]   = 0;
        cc_segm[i] = 0;
        ech_x[i]   = 0.0;
        ech_y[i]   = 0.0;
        ech_z[i]   = 0.0;
        tl1_x[i]   = 0.0;
        tl1_y[i]   = 0.0;
        tl1_z[i]   = 0.0;
        tl3_x[i]   = 0.0;
        tl3_y[i]   = 0.0;
        tl3_z[i]   = 0.0;
        tl3_cx[i]  = 0.0;
        tl3_cy[i]  = 0.0;
        tl3_cz[i]  = 0.0;
        id[i]      = 0;
        vx[i]      = 0.0;
        vy[i]      = 0.0;

        // mc
        mcst[i]    = 0;
        mcid[i]    = 0;
        mcpid[i]   = 0;
        mctheta[i] = 0.0;
        mcphi[i]   = 0.0;
        mcp[i]     = 0.0;
        mcm[i]     = 0.0;
        mcvx[i]    = 0.0;
        mcvy[i]    = 0.0;
        mcvz[i]    = 0.0;
        mctof[i]   = 0.0;
    }

}

void NTupleStructure::WriteEvent(){
    fChain->Fill();
}

void NTupleStructure::SetCCInformation(clasCCPB_t *CCPB, int index){

    if(cc_point){
        nphe[index]    = (Int_t)   CCPB->ccpb[cc_point-1].nphe;
        cc_t[index]    = (Float_t) CCPB->ccpb[cc_point-1].time;
        cc_r[index]    = (Float_t) CCPB->ccpb[cc_point-1].path;
        cc_segm[index] = (Int_t)   CCPB->ccpb[cc_point-1].status;
        cc_sect[index] = (Int_t)   CCPB->ccpb[cc_point-1].scsght/100;
        cc_c2[index]   = (Float_t) CCPB->ccpb[cc_point-1].chi2cc;
    }

}

void NTupleStructure::SetDCInformation(clasDCPB_t *DCPB, clasTBLA_t *TBLA, int index){

    if(dc_point){
        // How do we set tl1_* ?
      //      tl1_x[index] = TBLA->tbla[dc_point-1].pos.x; 
      //      tl1_y[index] = TBLA->tbla[dc_point-1].pos.y; 
      //      tl1_z[index] = TBLA->tbla[dc_point-1].pos.z; 

      int sec = DCPB->dcpb[dc_point-1].sctr/100;
      int trk = DCPB->dcpb[dc_point-1].sctr%100;

      if(TBLA)
	for(int t=0;t<TBLA->bank.nrow;t++){
	    int tbla_trk = TBLA->tbla[t].trk_pln/100;
	    int tbla_pln = TBLA->tbla[t].trk_pln%100;
	    if(1){ //(tbla_trk == trk && (tbla_pln == 5 || tbla_pln == 18 || tbla_pln == 29)){
	      tl1_x[index] = TBLA->tbla[t].pos.x;
	      tl1_y[index] = TBLA->tbla[t].pos.y;
	      tl1_z[index] = TBLA->tbla[t].pos.z;
	    }
	  }
      
      tl3_x[index]   = DCPB->dcpb[dc_point-1].x_sc;
      tl3_y[index]   = DCPB->dcpb[dc_point-1].y_sc;
      tl3_z[index]   = DCPB->dcpb[dc_point-1].z_sc;
      tl3_cx[index]  = DCPB->dcpb[dc_point-1].cx_sc;
      tl3_cy[index]  = DCPB->dcpb[dc_point-1].cy_sc;
      tl3_cz[index]  = DCPB->dcpb[dc_point-1].cz_sc;
      
      dc_sect[index] = (Int_t) DCPB->dcpb[dc_point-1].sctr/100;
    }

}

void NTupleStructure::SetECInformation(clasECPB_t *ECPB, int index){

    if(ec_point){
        ec_sect[index] = (Int_t) ECPB->ecpb[ec_point-1].scht/100;
        etot[index]    = ECPB->ecpb[ec_point-1].etot;
        ec_ei[index]   = ECPB->ecpb[ec_point-1].ein;
        ec_eo[index]   = ECPB->ecpb[ec_point-1].eout;
        ec_t[index]    = ECPB->ecpb[ec_point-1].time;
        ec_r[index]    = ECPB->ecpb[ec_point-1].path;
        ech_x[index]   = ECPB->ecpb[ec_point-1].x;
        ech_y[index]   = ECPB->ecpb[ec_point-1].y;
        ech_z[index]   = ECPB->ecpb[ec_point-1].z;
    }

}

void NTupleStructure::SetSCInformation(clasSCPB_t *SCPB, int index){

    if(sc_point){
        int sector     = SCPB->scpb[sc_point-1].scpdht/10000;
        int paddle     = (SCPB->scpb[sc_point-1].scpdht%10000)/100;
        sc_pd[index]   = 10000*sector+paddle;
        edep[index]    = SCPB->scpb[sc_point-1].edep;
        sc_t[index]    = SCPB->scpb[sc_point-1].time;
        sc_r[index]    = SCPB->scpb[sc_point-1].path;
        sc_sect[index] = sector;
    }

}

void NTupleStructure::SetHEADInformation(clasHEAD_t *HEAD){

}

void NTupleStructure::SetHEVTInformation(clasHEVT_t *HEVT){

}

void NTupleStructure::SetEVNTInformation(clasEVNT_t *EVNT, int index){
    //  if(EVNT->evnt[index].pmom == 0) return;

    id[index] = (Int_t)   EVNT->evnt[index].id;
    q[index]  = (Int_t)   EVNT->evnt[index].charge;
    cx[index] = (Float_t) EVNT->evnt[index].dir_cos.x;
    cy[index] = (Float_t) EVNT->evnt[index].dir_cos.y;
    cz[index] = (Float_t) EVNT->evnt[index].dir_cos.z;
    p[index]  = (Float_t) EVNT->evnt[index].pmom;
    b[index]  = (Float_t) EVNT->evnt[index].betta;
    vx[index] = (Float_t) EVNT->evnt[index].vert.x;
    vy[index] = (Float_t) EVNT->evnt[index].vert.y;
    vz[index] = (Float_t) EVNT->evnt[index].vert.z;

    cc_point = EVNT->evnt[index].ccstat;
    dc_point = EVNT->evnt[index].dcstat;
    ec_point = EVNT->evnt[index].ecstat;
    sc_point = EVNT->evnt[index].scstat;
    status   = EVNT->evnt[index].status;
}

void NTupleStructure::SetPARTInformation(clasPART_t *PART){

    for(int i=0; i<PART->bank.nrow; i++){
        mcnentr  = PART->bank.nrow;
        mcid[i]  = (Short_t) getPDGFromGEANT(PART->part[i].pid);
        mcpid[i] = (Short_t) PART->part[i].pid;
        q[i]     = (Short_t) PART->part[i].q;
        mcp[i]   = (Float_t)   sqrt( pow(PART->part[i].p.space.x,2) +
                                     pow(PART->part[i].p.space.y,2) +
                                     pow(PART->part[i].p.space.z,2));

        mcvx[i] = (Float_t)   PART->part[i].vert.x;
        mcvy[i] = (Float_t)   PART->part[i].vert.y;
        mcvz[i] = (Float_t)   PART->part[i].vert.z;

        double cx    = PART->part[i].p.space.x/mcp[i];
        double cy    = PART->part[i].p.space.y/mcp[i];
        double cz    = PART->part[i].p.space.z/mcp[i];

        mctheta[i]  = acos(cz)     *to_degrees;
        mcphi[i]    = atan2(cy,cx) *to_degrees;
    }

}

void NTupleStructure::SetScalarInformation(clasTRGS_t *TRGS){

  // Will be scaled value still. 
  q_l = TRGS->trgs[0].fcup_g2/1000; 

}

#endif
