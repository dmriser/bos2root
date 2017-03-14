// ----------------------------------------------------------------------------------------
//   ________  ________  ________    _______  ________  ________  ________  _________   
//  |\   __  \|\   __  \|\   ____\  /  ___  \|\   __  \|\   __  \|\   __  \|\___   ___\ 
//  \ \  \|\ /\ \  \|\  \ \  \___|_/__/|_/  /\ \  \|\  \ \  \|\  \ \  \|\  \|___ \  \_| 
//   \ \   __  \ \  \\\  \ \_____  \__|//  / /\ \   _  _\ \  \\\  \ \  \\\  \   \ \  \  
//    \ \  \|\  \ \  \\\  \|____|\  \  /  /_/__\ \  \\  \\ \  \\\  \ \  \\\  \   \ \  \ 
//     \ \_______\ \_______\____\_\  \|\________\ \__\\ _\\ \_______\ \_______\   \ \__\
//      \|_______|\|_______|\_________\\|_______|\|__|\|__|\|_______|\|_______|    \|__|
//                         \|_________|                                                 
// ----------------------------------------------------------------------------------------
//                                                                                      
//      David Riser (Based entirely on bos2mu by Maurizio Ungaro)
//
//      University of Connecticut
//
//      March 14, 2017 
//
// ----------------------------------------------------------------------------------------




// -------------------
//    c++ standard 
// -------------------
#include <iostream>
#include <fstream>
using std::cout; 
using std::endl; 
using std::string; 

// -------------------
//   old CLAS stuff
// -------------------
extern "C"{
#include <ntypes.h>
#include <bostypes.h>
  //#include <pid.h>
  //#include <dc.h>
  //#include <sc.h>
  //#include <vertex.h>
  //#include <utility.h>
//#include <trk.h>        
//#include <trk_run_control.h>
  //#include <map_manager.h>

  void initbos();
  int fparm_c(char *);
  int dc_begin_run_(int *);
  void dc_set_def_();
  void trk_set_def_();
}

extern BOSbank bcs_;


// -------------------
//   this project 
// -------------------
#include "h22Event.h"
#include "Options.h"
#include "Utilities.h"

int main(int argc, char *argv[]){

  Options *opts = new Options(); 
  opts->set(argc, argv); 
  
  int eventsToProcess = (int) opts->args["N"].arg;

  if (!opts->ifiles.empty()){

    /// Try opening the file, put fortran command 
    // into char array to be used with fparm_c()
    char command[100];
    sprintf(command, "OPEN BOSINPUT UNIT=1 FILE=\"%s\" READ",opts->ifiles[0].c_str());

    // Currently breaks 
    initbos();

    if (fparm_c(command)){
      cout << opts->args["MSG"].args << " Opened bos file for reading: " << opts->ifiles[0] << endl; 

      // Create root tree 
      h22Event event;

      int numberOfEvents = 0; 
      while(getBOS(&bcs_, 1, (char*) "E") && numberOfEvents < eventsToProcess){

	// if no HEAD or HEVT or TGBI, no sense analyzing a physics event. 
	// If no HLS, info won't make much sense
	clasHEAD_t *HEAD = (clasHEAD_t *) getBank(&bcs_, "HEAD");
	clasHEVT_t *HEVT = (clasHEVT_t *) getBank(&bcs_, "HEVT");
	clasHLS_t  *HLS  = (clasHLS_t  *) getBank(&bcs_, "HLS");
	clasTGBI_t *TGBI = (clasTGBI_t *) getBank(&bcs_, "TGBI");
	clasCCPB_t *CCPB = (clasCCPB_t *) getBank(&bcs_, "CCPB");

	int type = 1000; 

 	if (HEAD){
	  type = HEAD->head[0].type;
	}

	// PART sector 0 generated particles
	clasPART_t *PART = NULL;
	if( (PART = (clasPART_t *) getGroup(&bcs_, "PART", 0)) ){
	  event.SetPARTInformation(PART); 
	}
	
	// EVNT particles
	clasEVNT_t *EVNT = NULL;
	if( (EVNT = (clasEVNT_t *) getGroup(&bcs_, "EVNT", 0)) ){

	    clasCCPB_t* CCPB = (clasCCPB_t*) getBank(&bcs_, "CCPB");
	    clasDCPB_t* DCPB = (clasDCPB_t*) getBank(&bcs_, "DCPB");
	    clasECPB_t* ECPB = (clasECPB_t*) getBank(&bcs_, "ECPB");
	    clasSCPB_t* SCPB = (clasSCPB_t*) getBank(&bcs_, "SCPB");

	    event.SetGPart(EVNT);
 
	    for(int i=0;i<EVNT->bank.nrow;i++){

	      event.SetEVNTInformation(EVNT, i); 

		if(CCPB){
		  event.SetCCInformation(CCPB, i);
		}

		if(DCPB){
		  event.SetDCInformation(DCPB, i);
		}

		if(ECPB){
		  event.SetECInformation(ECPB, i);
		}

		if(SCPB){
		  event.SetSCInformation(SCPB, i);
		}

	    }

	}

	
	// Fill output for this event 
	// and clean the banks 
	//	event.fChain->Fill();	
	event.WriteEvent(); 

	dropAllBanks(&bcs_, (char*) "E");
	dropAllBanks(&bcs_, (char*) "T");
	cleanBanks(&bcs_);

	numberOfEvents++; 
	if (numberOfEvents%(int)opts->args["PRINT"].arg == 0){
	  cout << opts->args["MSG"].args << " Processed " << numberOfEvents << endl; 
	}
	
      }	// End File Loop 
      
      // Write our converted file to disk
      TFile *outputFile = new TFile("out.root","recreate"); 
      outputFile  ->cd();


      event.fChain->Write();
      outputFile  ->Close();
      }
    }

    return 0; 
} 
