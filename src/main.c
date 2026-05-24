#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define handleResult(action)                          \
  Result rc = action;                                 \
  if (R_FAILED(rc)) {                                 \
    printf("Error: %08lx\n\n", rc);                   \
  } else {                                            \
    hasTakenAction = true;                            \
    printf("Success!  Will reboot on \"Start\"\n\n"); \
  }

int main() {
  frdInit(false);
  gfxInitDefault();
  consoleInit(GFX_TOP, NULL);

  // This version or higher is required creating/swaping local accounts
  FRDA_SetClientSdkVersion(0x70000c8);
  
  int const pretendo_act = 2;

  consoleClear();
  
  printf("please to X_key  ¥n");
  
  // Main loop
  while (aptMainLoop()) {
    hidScanInput();

    if (kDown & KEY_X) {
      handleResult(FRDA_DeleteLocalAccount(pretendo_act));
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
