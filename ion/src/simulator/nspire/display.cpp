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
  lcd_blit((void*)Framebuffer::address(), SCR_320x240_565);
}

}
}
}
