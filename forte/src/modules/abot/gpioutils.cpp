#include <unistd.h>
#include <stdio.h>
#include <chrono>
#include <thread>

#include "gpioutils.h"


GpioHandle handle;

void stop(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 0);
    printf("stop\n");
}
void forward(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
    printf("move forward\n");
}
void back(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 1);
    GpioOut(handle, 20, 1);
    GpioOut(handle, 21, 0);
    printf("move back\n");
}
void turn_left(){
    GpioOut(handle, 12, 0);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 1);
    printf("turn left\n");
}
void turn_right(){
    GpioOut(handle, 12, 1);
    GpioOut(handle, 13, 0);
    GpioOut(handle, 20, 0);
    GpioOut(handle, 21, 0);
    printf("turn right\n");
}


void ABotEngines::ABotEngines () {
  if (GpioOpenPort("gpio0", &handle) || handle == GPIO_INVALID_HANDLE)
  {
    printf("GpioOpenPort failed\n");
  }
  else{
    printf("GpioOpenPort Ok\n");
  }
  GpioSetMode(handle, 12, GPIO_DIR_OUT);
  GpioSetMode(handle, 13, GPIO_DIR_OUT);
  GpioSetMode(handle, 20, GPIO_DIR_OUT);
  GpioSetMode(handle, 21, GPIO_DIR_OUT);
  GpioSetMode(handle, 6, GPIO_DIR_OUT);
  GpioSetMode(handle, 26, GPIO_DIR_OUT);
}

void ABotEngines::forward (unsigned int duration) {
    forward();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();
}

void ABotEngines::left (unsigned int duration) {
    turn_left();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();

}

void ABotEngines::right (unsigned int duration) {
    turn_right();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();

}

void ABotEngines::back (unsigned int duration) {
    back();
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    stop();

}

void ABotEngines::stop () {
    stop();
}

