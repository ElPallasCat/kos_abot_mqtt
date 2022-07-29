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


/*void gpio_set_mode(GpioHandle handle, int pin){
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

void gpio_motor_on(GpioHandle handle, int ena, int enb){
  if (GpioOut(handle, ena, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, enb, 1)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}

void gpio_motor_off(GpioHandle handle, int ena, int enb){
  if (GpioOut(handle, ena, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
  if (GpioOut(handle, enb, 0)){
    printf("GpioOut set failed\n");
    exit(-1);
  }
}*/

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


void FORTE_FB_ABOT_ENGINE::alg_REQ(void) {
  int int_cmd = CMD();
  int duration = DURATION();

  int dur_in_sec = int(duration*1000);
  //printf("dur_in_sec\n"); 
  //printf("%d\n", dur_in_sec); 

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
  }

  /*gpio_set_mode(handle, in1);
  gpio_set_mode(handle, in2);
  gpio_set_mode(handle, in3);
  gpio_set_mode(handle, in4);
  gpio_set_mode(handle, ena);
  gpio_set_mode(handle, enb);

  gpio_motor_on(handle, ena, enb);*/

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
    printf("stop\n"); 

    stop();
    usleep(dur_in_sec);
    stop();
    break; 

  case 1: 
    printf("moving forward\n");

    forward();
    usleep(dur_in_sec);
    stop();
    printf("moving forward OK\n");
    break; 

  case 2: 
    printf("moving back\n");

    back();
    usleep(dur_in_sec);
    stop();
    break; 

  case 3:  
    printf("rotate left\n"); 

    turn_left();
    usleep(dur_in_sec);
    stop();
    break; 

  case 4:  
    printf("rotate right\n");

    turn_right();
    usleep(dur_in_sec);
    stop();
    break;

  default: 
    printf("error cmd code\n");
    exit(1);
  }

  //gpio_motor_off(handle, ena, enb);

  if(GpioClosePort(handle))
  {
    printf("GpioClosePort failed\n");
    exit(-1);
  }
}


