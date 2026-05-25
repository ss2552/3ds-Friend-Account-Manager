#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NASC_ENV_Test 1

int main(){
  nsInit();
  frdInit(false);
  gfxInitDefault();
  consoleInit(GFX_TOP, NULL);

  // This version or higher is required creating/swaping local accounts
  FRD_SetClientSdkVersion(0x70000c8);
  
  int const pretendo_act = 2;

  print("\n\n\n");
  printf("please to X\n");
  // printf("Press Y to use nintendo account\n");
  printf("Press A to create a new account 2\n");
  printf("exit to SELECT\n");
  printf("Reboot on START\n");

  printf("\n");
  
  while (aptMainLoop()){
    
    hidScanInput();
    u32 kDown = hidKeysDown();
    
    if (kDown & KEY_X){
      Result rc = FRDA_DeleteLocalAccount(pretendo_act);
      if(R_FAILED(rc)){
         printf("Error: %08lx", rc);
      }else{
         printf("Success!: %08lx", rc);
      }
      printf("\n");
    }

    /*
    if (kDown & KEY_Y) {
      printf("Using nintendo account\n");
      Result rc
      
      rc = FRDA_UnLoadLocalAccount(1);
      if(R_FAILED(rc)){
         printf("Error: %08lx", rc);
      }
      
      printf("\n");
      
      rc = FRDA_LoadLocalAccount(1);
      if(R_FAILED(rc)){
         printf("Error: %08lx", rc);
      }
      
      printf("\n");
      
    }
    */

    if (kDown & KEY_A) {
      printf("Creating pretendo account\n");
      // (Re)Create the friend account
      Result rc = FRDA_CreateLocalAccount(pretendo_act, (u8)NASC_ENV_Test, 0, 1);
      if(R_FAILED(rc)){
         printf("Error: %08lx", rc);
      }else{
         printf("Success!: %08lx", rc);
      }
      printf("\n");
    }
    
    if(kDown & KEY_START){
      NS_RebootSystem();
    }
    
    if(kDown & KEY_SELECT){
      break;
    }
    
  }

  gfxExit();
  frdExit();
  nsExit();
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
