//////////////////////////////////////
/*

  Options.h 
  
  Almost entirely the same as CLAS_Event
  from Mauri. 
 
*/
//////////////////////////////////////

#ifndef OPTIONS_H
#define OPTIONS_H

// c++ includes 
#include <map>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::map;

// my includes 
class opts
{
 public:
  double  arg;  ///< double assigned to argument.
  string args;  ///< string assigned to argument.
  string name;  ///< name to be displayed for the argument variable.
  string help;  ///< help for the argument variable.
  int    type;  ///< 0 = number, 1 = string
};

class Options
{

 public:
  Options();
  ~Options();

  // datatypes 
  map<string,opts> args;
  vector<string> ifiles;

  // member functions 
  void set(int,char**);

};

#endif
