// #include "./frda.h"
// #include <3ds/services/frd.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int const pretendo_act = 2;

  frdInit(false);

  // This version or higher is required creating/swaping local accounts
  // FRD_SetClientSdkVersion(0x70000c8);

  FRDA_DeleteLocalAccount(pretendo_act);
  
  frdExit();
  return 0;
}
