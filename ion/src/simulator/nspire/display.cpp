#include "display.h"
#include "framebuffer.h"
#include <ion/display.h>
#include <string.h>

namespace Ion {
namespace Simulator {
namespace Display {

void* pixels;

void init() {
  pixels = nullptr;
}

void quit() {
  pixels = nullptr;
}

void draw() {
  pixels = BUFF_BASE_ADDRESS;
  memcpy(pixels, Framebuffer::address(), sizeof(KDColor)*Ion::Display::Width*Ion::Display::Height);  // Both RGB888
  updateScreen();
}

}
}
}
