// #include "./frda.h"
#include <3ds/services/frd.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int const pretendo_act = 2;
  
  nsInit();
  // frdAInit();
  frdInit();
  gfxInitDefault();
  consoleInit(GFX_TOP, NULL);

  // This version or higher is required creating/swaping local accounts
  FRDA_SetClientSdkVersion(0x70000c8);

  printf("Friend account manager\n");
  printf("Press \"Start\" to quit or reboot\n");
  printf("Press \"X\" to delete account 2\n");

  // Main loop
  while (aptMainLoop()) {
    gspWaitForVBlank();
    gfxSwapBuffers();
    hidScanInput();

    // Your code goes here
    u32 kDown = hidKeysDown();
    if (kDown & KEY_START) {
      NS_RebootSystem();
    } else {
      break;  // break in order to return to hbmenu
    }

    if (kDown & KEY_X) {
      printf("Using local account Id 1...\n");
      handleResult(FRDA_DeleteLocalAccount(pretendo_act));
    }

  }

  gfxExit();
  frdExit();
  nsExit();
  return 0;
}
