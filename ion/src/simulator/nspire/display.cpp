#include "display.h"
#include "framebuffer.h"
#include <ion/display.h>
#include <string.h>

namespace Ion {
namespace Simulator {
namespace Display {

void init() {
  lcd_init(SCR_320x240_565);
}

void quit() {
  lcd_init(SCR_TYPE_INVALID);
}

void draw() {
  static const bool has_colors_cache = has_colors;

  if (has_colors_cache) {
    // same as lcd_blit((void*)Framebuffer::address(), SCR_320x240_565)
    memcpy(REAL_SCREEN_BASE_ADDRESS, (void*)Framebuffer::address(), 320 * 240 * sizeof(uint16_t));
  } else {  // invert screen color if running on classic
    for (unsigned int i = 0; i < 320 * 240; i++) {
      reinterpret_cast<uint16_t*>(REAL_SCREEN_BASE_ADDRESS)[i] = 0xFFFF - Framebuffer::address()[i];
    }
  }
}

}
}
}
