/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FB_ABOT_ENGINE
 *** Description: Simple FB with one algorithm
 *** Version:
***     1.0: 2022-07-15/slava -  - 
 *************************************************************************/

#include "FB_ABOT_ENGINE.h"
#include <unistd.h>
#include "stdio.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_ABOT_ENGINE_gen.cpp"
#endif

GpioHandle handle;

DEFINE_FIRMWARE_FB(FORTE_FB_ABOT_ENGINE, g_nStringIdFB_ABOT_ENGINE)

const CStringDictionary::TStringId FORTE_FB_ABOT_ENGINE::scm_anDataInputNames[] = {g_nStringIdCMD, g_nStringIdDURATION};

const CStringDictionary::TStringId FORTE_FB_ABOT_ENGINE::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdINT};


const TDataIOID FORTE_FB_ABOT_ENGINE::scm_anEIWith[] = {0, 1, 255};
const TForteInt16 FORTE_FB_ABOT_ENGINE::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_ABOT_ENGINE::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_FB_ABOT_ENGINE::scm_anEOWith[] = {};
const TForteInt16 FORTE_FB_ABOT_ENGINE::scm_anEOWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_FB_ABOT_ENGINE::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_FB_ABOT_ENGINE::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  /*0, scm_anDataOutputNames, scm_anDataOutputTypeIds,*/
  0, nullptr
};

void stop(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 0);
    printf("FB tell: Stop\n");
}

void forward(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
    printf("FB tell: Forward\n");
}

void back(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 1);
    GpioOut(handle, 20, 1);
    GpioOut(handle, 21, 0);
    printf("FB tell: Back\n");
}

void turn_left(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
    printf("FB tell: Turn left\n");
}

void turn_right(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 0);
    printf("FB tell: Turn right\n");
}


void FORTE_FB_ABOT_ENGINE::alg_REQ(void) {
  int int_cmd = CMD();
  int duration = DURATION();
  printf("%d\n", duration);

  int dur_in_mksec = int(duration*1000);
  float dur_in_sec = float(duration/1000);
  printf("%f\n", dur_in_sec);

  /*int in1 = 12;
  int in2 = 13;
  int in3 = 20;
  int in4 = 21;
  int ena = 6;
  int enb = 26;*/

  /* initialize and setup gpio0 port */
  handle = NULL;
  
  if (GpioOpenPort("gpio0", &handle) || handle == GPIO_INVALID_HANDLE)
  {
    printf("GpioOpenPort failed\n");
    exit(-1);
  }
  else{
    printf("GpioOpenPort Ok\n");
    fprintf(stderr, "%d\n", handle);
  }

  GpioSetMode(handle, 12, GPIO_DIR_OUT);
  GpioSetMode(handle, 13, GPIO_DIR_OUT);
  GpioSetMode(handle, 20, GPIO_DIR_OUT);
  GpioSetMode(handle, 21, GPIO_DIR_OUT);
  GpioSetMode(handle, 6, GPIO_DIR_OUT);
  GpioSetMode(handle, 26, GPIO_DIR_OUT);

  GpioOut(handle, 6, 1);
  GpioOut(handle, 26, 1);

  switch (int_cmd) { 
  case 0:
    stop();
    //sleep(dur_in_sec);
    sleep(0.9);
    //usleep(dur_in_mksec);
    stop();
    break; 

  case 1: 
    forward();
    //sleep(dur_in_sec);
    sleep(0.9);
    //usleep(dur_in_mksec);
    stop();
    break; 

  case 2: 
    back();
    //sleep(dur_in_sec);
    sleep(0.9);
    //usleep(dur_in_mksec);
    stop();
    break; 

  case 3:  
    turn_left();
    //sleep(dur_in_sec);
    sleep(0.9);
    //usleep(dur_in_mksec);
    stop();
    break; 

  case 4:  
    turn_right();
    //sleep(dur_in_sec);
    sleep(0.9);
    //usleep(dur_in_mksec);
    stop();
    break;

  default: 
    printf("error cmd code\n");
    exit(1);
  }

  GpioOut(handle, 6, 0);
  GpioOut(handle, 26, 0);

  if(GpioClosePort(handle))
  {
    printf("GpioClosePort failed\n");
    exit(-1);
  }
  else{
    printf("GpioClosePort Ok\n");
  }
}


