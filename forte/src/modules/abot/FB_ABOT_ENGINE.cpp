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
#include <chrono>
#include <thread>
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
}

void forward(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
}

void back(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 1);
    GpioOut(handle, 20, 1);
    GpioOut(handle, 21, 0);
}

void turn_left(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
}

void turn_right(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 0);
}

/*unsigned int ms2sec(unsigned int ms){
float sec = 0.0;

}*/


void FORTE_FB_ABOT_ENGINE::alg_REQ(void) {
  int int_cmd = CMD();
  unsigned int duration = DURATION();
  //printf("%d\n", duration);

  //int dur_in_mksec = int(duration*1000);
  //printf("%d\n", dur_in_mksec);
  //float dur_in_sec = float(duration/1000);
  //printf("%f\n", dur_in_sec);

  //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

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
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();
    break; 

  case 1: 
    forward();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();
    break; 

  case 2: 
    back();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();
    break; 

  case 3:  
    turn_left();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();
    break; 

  case 4:  
    turn_right();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
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


