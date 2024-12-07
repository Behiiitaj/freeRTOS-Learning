/*
** Contains all data specific to a device model (pcb design,
** gpio pins,...).
** All models must define two macros:
**  - ONEWIRE_NUMBER, number of onewire slots
**  - ONEWIRE_PINS, a list of onewire pins
**  - RS_NUMBER, number of RS slots
**  - RS_PINS_**, lists of RX, TX and direction pins for RS-type sensors
*/

#if !defined(JAM_BOARD)
#define JAM_BOARD

#ifdef MODEL3
  #define ONEWIRE_NUMBER 0
  #define ONEWIRE_PINS ((const int[]){})
  #define RS_NUMBER 1
  #define RS_PIN_RX 17
  #define RS_PIN_TX 15
  #define RS_PIN_DR 16

  #define LCD_MOSI 8
  #define LCD_MISO 18
  #define LCD_CS 3
  #define LCD_DC 9
  #define LCD_CLK 11
  #define LCD_RST 12
  #define LCD_BACKLIGHT 13

  #define SCREEN_WIDTH 240
  #define SCREEN_HEIGHT 320

  #define BOOGH_PIN 7

  #define BUTTON_NUMBER 4
  #define BUTTON_PINS ((const int[]){39, 40, 41, 42})

  #define SDA_RTC_PIN 1
  #define SCL_RTC_PIN 2

  //#define ENC_MOSI 48
  //#define ENC_MISO 21
  //#define ENC_RST 38
  //#define ENC_CS 45
  //#define ENC_CLK 47
  //#define ENC_WOL 36
  //#define ENC_INT 37

  #define POWERCUT 14
  
  #define V_BAT 10

  #define SIM800_RX 5
  #define SIM800_TX 6
  #define SIM800_POWER 4

  //#define USB_DMINUS 19
  //#define USB_DPLUS 20
#endif

#ifdef MODEL4
  #define ONEWIRE_NUMBER 4
  #define ONEWIRE_PINS ((const int[]){21,47,48,38})
  #define RS_NUMBER 1
  #define RS_PIN_RX 17
  #define RS_PIN_TX 15
  #define RS_PIN_DR 16

  #define LCD_MOSI 8
  #define LCD_MISO 18
  #define LCD_CS 3
  #define LCD_DC 9
  #define LCD_CLK 11
  #define LCD_RST 12
  #define LCD_BACKLIGHT 13

  #define SCREEN_WIDTH 240
  #define SCREEN_HEIGHT 320

  #define BOOGH_PIN 7

  #define BUTTON_NUMBER 4
  #define BUTTON_PINS ((const int[]){39, 40, 41, 42})

  #define SDA_RTC_PIN 1
  #define SCL_RTC_PIN 2

  #define POWERCUT 14
  
  #define V_BAT 10

  #define SIM800_RX 5
  #define SIM800_TX 6
  #define SIM800_POWER 4

  //#define USB_DMINUS 19
  //#define USB_DPLUS 20
#endif

enum ButtonName {
  BUTTON_CANCEL,
  BUTTON_OK,
  BUTTON_UP,
  BUTTON_DOWN
};

#define ONEWIRE_LAST (ONEWIRE_NUMBER - 1)

#endif // JAM_BOARD