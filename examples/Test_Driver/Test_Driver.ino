/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "SimpleMotor.h"

/* ------------------------------------------------------------------------- */
/*                                   DEFINE                                  */
/* ------------------------------------------------------------------------- */

/**
 * PIN_IN2 kết nối Driver L298
 *
 * Phần cấp nguồn cho Driver
 * +12V - ... có thể cấp nguồn trong khoảng 9V~6V
 * GND  - GND
 *
 * Dùng Jumper kết nối (mặc định)
 * ENA  - 5V
 * ENB  - 5V
 *
 * L298 : Arduino
 * IN1  : D4
 * IN2  : D5 (~)
 * IN3  : D6 (~)
 * IN4  : D7
 */
#define PIN_IN1 4 //! D4
#define PIN_IN2 5 //! D5 (~)
#define PIN_IN3 6 //! D6 (~)
#define PIN_IN4 7 //! D7

/* ------------------------------------------------------------------------- */
/*                              CHECK AT COMPILE                             */
/* ------------------------------------------------------------------------- */

/**
 * Đoạn code này để Trình biên dịch xác định bạn có sử dụng đúng bo Uno hoặc Mega ko?
 * Cũng như nó sẽ kiểm tra trước các chân "PIN_IN2" và "PIN_IN3" có tính năng PWM ko
 *
 * Nếu thỏa mãn đúng các điều kiện, Trình biên dịch mới cho phép biên dịch code
 * Ngược lại sẽ thông báo lỗi và dừng quá trình nạp code
 *
 * ! Nếu bạn chắc chắn mình sử dụng đúng, có thể xóa đi đoạn code này
 */
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
// Arduino Uno
static_assert(
    PIN_IN2 == 3 || PIN_IN2 == 5 || PIN_IN2 == 6 || PIN_IN2 == 9 || PIN_IN2 == 10 || PIN_IN2 == 11,
    "Error: PIN_IN2 does not support PWM on Arduino Uno.");
static_assert(
    PIN_IN3 == 3 || PIN_IN3 == 5 || PIN_IN3 == 6 || PIN_IN3 == 9 || PIN_IN3 == 10 || PIN_IN3 == 11,
    "Error: PIN_IN3 does not support PWM on Arduino Uno.");
#elif defined(__AVR_ATmega2560__)
// Arduino Mega
static_assert(
    PIN_IN2 == 2 || PIN_IN2 == 3 || PIN_IN2 == 4 || PIN_IN2 == 5 || PIN_IN2 == 6 || PIN_IN2 == 7 ||
        PIN_IN2 == 8 || PIN_IN2 == 9 || PIN_IN2 == 10 || PIN_IN2 == 11 || PIN_IN2 == 12 || PIN_IN2 == 44 ||
        PIN_IN2 == 45 || PIN_IN2 == 46,
    "Error: PIN_IN2 does not support PWM on Arduino Mega.");
static_assert(
    PIN_IN3 == 2 || PIN_IN3 == 3 || PIN_IN3 == 4 || PIN_IN3 == 5 || PIN_IN3 == 6 || PIN_IN3 == 7 ||
        PIN_IN3 == 8 || PIN_IN3 == 9 || PIN_IN3 == 10 || PIN_IN3 == 11 || PIN_IN3 == 12 || PIN_IN3 == 44 ||
        PIN_IN3 == 45 || PIN_IN3 == 46,
    "Error: PIN_IN3 does not support PWM on Arduino Mega.");
#else
#error "Unsupported board. Compilation error!"
#endif

/* ------------------------------------------------------------------------- */
/*                                   OBJECT                                  */
/* ------------------------------------------------------------------------- */

SimpleMotor demo(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);

/* ------------------------------------------------------------------------- */
/*                                RUN ONE TIME                               */
/* ------------------------------------------------------------------------- */

void setup()
{
  Serial.begin(115200);
}

/* ------------------------------------------------------------------------- */
/*                                    MAIN                                   */
/* ------------------------------------------------------------------------- */

void loop()
{
  Serial.println("Điều khiển xe...");
  Serial.println();

  /* --------------------------------------------------------------------- */

  Serial.println("Đi thẳng");
  demo.go_forward(255);
  delay(5000);

  Serial.println("Đi thẳng, rẽ trái");
  demo.go_forward_left(255);
  delay(5000);

  Serial.println("Đi thẳng, rẽ phải");
  demo.go_forward_right(255);
  delay(5000);

  /* ----------------------------------------------------------------------- */

  Serial.println("Đi lùi");
  demo.go_back(255);
  delay(5000);

  Serial.println("Đi lùi, rẽ trái");
  demo.go_back_left(255);
  delay(5000);

  Serial.println("Đi lùi, rẽ phải");
  demo.go_back_right(255);
  delay(5000);

  /* ----------------------------------------------------------------------- */

  Serial.println("Xoay trái");
  demo.rotate_left(255);
  delay(5000);

  Serial.println("Xoay phải");
  demo.rotate_right(255);
  delay(5000);

  /* ----------------------------------------------------------------------- */

  Serial.println("Dừng lại");
  demo.stop();
  delay(5000);

  /* ----------------------------------------------------------------------- */

  Serial.println("Hàm go_custom() điều khiển độc lập 2 bánh xe");
  Serial.println("Lần lượt là bánh xe bên Trái và bên Phải");
  Serial.println();
  Serial.println("Giá trị (+) bánh xe quay tới");
  Serial.println("Giá trị (-) bánh xe quay lùi");
  Serial.println();
  Serial.println("Giá trị tốc độ từ (-255) đến (+255)");
  Serial.println();

  Serial.println("-50 ; +50");
  demo.go_custom(-50, 50);
  delay(5000);

  Serial.println("100 ; -100");
  demo.go_custom(100, -100);
  delay(5000);

  Serial.println("0 ; +255");
  demo.go_custom(0, 255);
  delay(5000);

  Serial.println("-255 ; 0");
  demo.go_custom(-255, 0);
  delay(5000);
}