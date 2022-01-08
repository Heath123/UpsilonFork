#include "main.h"
#include "keyboard.h"
#include "platform.h"
//#include "driver/common.h"
#include <libndls.h>
extern "C" {
  #include <n2DLib.h>
}

#include <assert.h>
#include <ion/events.h>
#include <string.h>

//static bool was_plugged = false;

namespace Ion {
namespace Events {


Event getPlatformEvent() {
  Event result = None;
  t_key scanResult;
  
  //if (Ion::Simulator::CommonDriver::isPlugged() && !was_plugged) {
  //  was_plugged = true;
  //  return USBPlug;
  //}
  //
  //if (!Ion::Simulator::CommonDriver::isPlugged() && was_plugged) {
  //  was_plugged = false;
  //}
  

  get_key_pressed(&scanResult);

  if (isKey(scanResult, KEY_NSPIRE_SCRATCHPAD)) {
    return Termination;
  }
  
  if (!Simulator::Keyboard::scanHandlesKey(scanResult)) {
    //strlcpy(sharedExternalTextBuffer(), event.text, sharedExternalTextBufferSize);
    //return ExternalText;
    // !! Handle Nspire text input here
  }

  return result;
}


}
}
