#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  frdInit(false);
  gfxInitDefault();
  consoleInit(GFX_TOP, NULL);

  // This version or higher is required creating/swaping local accounts
  FRD_SetClientSdkVersion(0x70000c8);
  
  int const pretendo_act = 2;

  consoleClear();
  
  printf("\nplease to X_key\n");
  
  // Main loop
  while (aptMainLoop()) {
    hidScanInput();

    if (hidKeysDown() & KEY_X) {
      Result rc = FRDA_DeleteLocalAccount(pretendo_act);
      if(R_FAILED(rc)) {
         printf("Error: %08lx\n\n", rc);
      }else{
         printf("Success!  Will reboot on \"Start\"\n\n");
      }
    }
  }

  gfxExit();
  frdExit();
  return 0;
}

/*
int main(){

  int const pretendo_act = 2;

  frdInit(false);
  FRD_SetClientSdkVersion(0x70000c8);
  FRDA_DeleteLocalAccount(pretendo_act);
  frdExit();
  
  return 0;
  
}
*/
