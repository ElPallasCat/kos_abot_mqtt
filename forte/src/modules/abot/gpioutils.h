#ifndef gpioutils_h
#define gpioutils_h


#include <gpio/gpio.h>
#include <stdbool.h>


class ABotEngines {

  static ABotEngines* _instance = nullptr;
public:
  
  static ABotEngines* instance() {
    if(!_instance) {
      _instance = new ABotEngines();
    }
    return _instance;
  } 

  void forward (unsigned int duration);
  void left (unsigned int duration);
  void right (unsigned int duration);
  void back (unsigned int duration);
  void stop ();

private:
  ABotEngines();


};

#endif