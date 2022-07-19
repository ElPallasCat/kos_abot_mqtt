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

GpioHandle handle = NULL;

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


void gpio_set_mode(GpioHandle handle, int pin){
  if (GpioSetMode(handle, pin, GPIO_DIR_OUT)){
    printf("GpioSetMode for GPIO%d failed\n", pin);
    exit(-1);
  }
}


void set_stop(GpioHandle handle, int in1, int in2, int in3, int in4){
  // code: in1,in2,in3,in4 = 0,0,0,0
  if (GpioOut(handle, in1, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in2, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in3, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in4, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}


void set_forward(GpioHandle handle, int in1, int in2, int in3, int in4){
  // code: in1,in2,in3,in4 = 1,0,0,1
  if (GpioOut(handle, in1, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in2, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in3, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in4, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}


void set_back(GpioHandle handle, int in1, int in2, int in3, int in4){
  // code: in1,in2,in3,in4 = 0,1,1,0
  if (GpioOut(handle, in1, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in2, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in3, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in4, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}


void set_left(GpioHandle handle, int in1, int in2, int in3, int in4){
  // code: in1,in2,in3,in4 = 0,0,0,1
  if (GpioOut(handle, in1, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in2, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in3, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in4, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}


void set_right(GpioHandle handle, int in1, int in2, int in3, int in4){
  // code: in1,in2,in3,in4 = 1,0,0,0
  if (GpioOut(handle, in1, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in2, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in3, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, in4, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}


void FORTE_FB_ABOT_ENGINE::alg_REQ(void) {
  int int_cmd = CMD();
  int duration = DURATION();

  int dur_in_sec = int(duration*1000);
  //printf("dur_in_sec\n"); 
  //printf("%d\n", dur_in_sec); 

  int in1 = 12;
  int in2 = 13;
  int in3 = 20;
  int in4 = 21;
  int ena = 6;
  int enb = 26;

  /* initialize and setup gpio0 port */
  
  if (GpioOpenPort("gpio0", &handle) || handle == GPIO_INVALID_HANDLE)
  {
    printf("GpioOpenPort failed\n");
    exit(-1);
  }
  else{
    printf("GpioOpenPort Ok\n");
  }

  gpio_set_mode(handle, in1);
  gpio_set_mode(handle, in2);
  gpio_set_mode(handle, in3);
  gpio_set_mode(handle, in4);
  gpio_set_mode(handle, ena);
  gpio_set_mode(handle, enb);

  switch (int_cmd) { 
  case 0:
    printf("stop\n"); 

    set_stop(handle, in1, in2, in3, in4);
    /*GpioOut(handle, in1, 0);
    GpioOut(handle, in2, 0);
    GpioOut(handle, in3, 0);
    GpioOut(handle, in4, 0);*/
    sleep(1);
    set_stop(handle, in1, in2, in3, in4);
    /*GpioOut(handle, in1, 0);
    GpioOut(handle, in2, 0);
    GpioOut(handle, in3, 0);
    GpioOut(handle, in4, 0);*/
    break; 

  case 1: 
    printf("moving forward\n");

    set_forward(handle, in1, in2, in3, in4);
    sleep(1);
    set_stop(handle, in1, in2, in3, in4);
    printf("moving forward OK\n");
    break; 

  case 2: 
    printf("moving back\n");

    set_back(handle, in1, in2, in3, in4);
    sleep(1);
    set_stop(handle, in1, in2, in3, in4);
    break; 

  case 3:  
    printf("rotate left\n"); 

    set_left(handle, in1, in2, in3, in4);
    sleep(1);
    set_stop(handle, in1, in2, in3, in4);
    /*GpioOut(handle, in1, 0);
    GpioOut(handle, in2, 0);
    GpioOut(handle, in3, 0);
    GpioOut(handle, in4, 1);
    sleep(1);
    //set_stop(handle, in1, in2, in3, in4);
    GpioOut(handle, in1, 0);
    GpioOut(handle, in2, 0);
    GpioOut(handle, in3, 0);
    GpioOut(handle, in4, 0);*/
    break; 

  case 4:  
    printf("rotate right\n");

    set_right(handle, in1, in2, in3, in4);
    //usleep(dur_in_sec);
    sleep(1);
    set_stop(handle, in1, in2, in3, in4);
    break;

  default: 
    printf("error cmd code\n");
    exit(1);
  }

  if(GpioClosePort(handle))
  {
    printf("GpioClosePort failed\n");
    exit(-1);
  }
}


