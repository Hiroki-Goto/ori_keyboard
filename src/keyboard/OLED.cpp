#include <U8glib.h>

#include "OLED.h"

#define led_pin 14
//U8GLIB_SSD1306_128X64 u8g(4, 5, 6, 7);
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

OLED::OLED(int a){
    pinMode(led_pin,OUTPUT);
    digitalWrite(led_pin, LOW);

    u8g.setColorIndex(1);         // pixel on
}

void OLED::display(keyboradState *keyboard_state){

    char layer_str = "aaa";

    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_unifont);
      //u8g.drawStr( 0, 22, "%s",nya);
      u8g.setScale2x2();
      u8g.setPrintPos(0, 22);
      switch(keyboard_state->current_layer){
          case _DEFAULT:
              u8g.print("Default");
          break;

          case _RAISE:
              u8g.print("Raise");
          break;

          case _ROWER:
              u8g.print("Rower");
          break;

          default:
              u8g.print("None");
          break;
      }

    } while ( u8g.nextPage() );
}
