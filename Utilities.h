#ifndef utils_h
#define utils_h

#include <iostream>
#include <vector>

#define to_degrees 57.295779
#define to_radians 0.0174533

inline int getPDGFromGEANT(int GEANT){

  if(GEANT == 1){ return 22; }
  if(GEANT == 3){ return 11; }
  if(GEANT == 13){ return 2112; }
  if(GEANT == 14){ return 2212; }
  if(GEANT == 7){ return 111; }
  if(GEANT == 8){ return 211; }
  if(GEANT == 9){ return -211; }

  
  return 0; 
}


#endif
