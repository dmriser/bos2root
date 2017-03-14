//////////////////////////////////////
/*
 
 Options.cxx
 
 */
//////////////////////////////////////

#ifndef OPTIONS_CXX
#define OPTIONS_CXX

// c++ includes
#include <cstdlib>
#include <fstream>
#include <map>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// my includes
#include "Options.h"

Options::Options(){
    // Setup Options
    args["N"].arg  = 0;
    args["N"].type = 0;
    args["N"].name = "Max number of events to process";
    args["N"].help = "Max number of events to process";
    
    args["BEAM_E"].arg  = 5.498;
    args["BEAM_E"].type = 0;
    args["BEAM_E"].name = "Beam Energy";
    args["BEAM_E"].help = "Beam Energy";
 
    args["PRINT"].arg  = 100000;
    args["PRINT"].type = 0;
    args["PRINT"].name = "Print message every number of events";
    args["PRINT"].help = "Print message every number of events";
    
    args["VERBOSE"].arg  = 0;
    args["VERBOSE"].type = 0;
    args["VERBOSE"].name = "Verbosity Status";
    args["VERBOSE"].help = "Verbosity Status (0-False, 1-True)";

    args["OUT"].args = "out.root";
    args["OUT"].type = 1;
    args["OUT"].name = "Output Root File";
    args["OUT"].help = "Output Root File";

    args["MSG"].args = " [bos2root22] : ";
    args["MSG"].type = 1;
    args["MSG"].name = "Log Message";
}

Options::~Options(){
}

void Options::set(int argc, char*argv[]){
    string arg;
    string com, com2;
    string opt;
    cout << endl;
    string comp;
    
    map<string, opts>::iterator itm;
    
    
    // If Maps option are specified, overriding default
    for(int i=1; i<argc; i++)
    {
        arg = argv[i];
        map<string, opts>::iterator itm;
        for(itm = args.begin(); itm != args.end(); itm++)
        {
            com = "-" + itm->first + "=";
            comp.assign(arg, 0, arg.find("=") + 1);
            if(comp == com)
            {
                opt.assign(arg, com.size(), arg.size()-com.size());
                itm->second.args = opt;
                itm->second.arg  = atof(opt.c_str());
                cout <<  " >>> Options: " << itm->second.name << " set to: " ;
                if(itm->second.type) cout << itm->second.args;
                else cout << itm->second.arg  ;
                cout << endl;
            }
        }
    }
    
    // If argument is a file, adding it to the list of files
    for(int i=1; i<argc; i++)
    {
        ifstream isFile(argv[i], ios::in | ios::binary);
        if(isFile) ifiles.push_back(argv[i]);
    }
    
    cout << endl;
    
    for(unsigned int i=0; i<ifiles.size(); i++)
        cout << " Input file found: " << ifiles[i] << endl;
    
    cout << endl;
}

#endif
