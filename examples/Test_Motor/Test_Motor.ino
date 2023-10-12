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
  Serial.println("Điều khiển động cơ kênh A...");
  Serial.println();

  Serial.println("Quay thuận 100%");
  demo.control_motor_channel_A(100, true);
  delay(5000);

  Serial.println("Quay ngược 50%");
  demo.control_motor_channel_A(50, false);
  delay(5000);

  Serial.println("Đứng yên");
  demo.control_motor_channel_A_stop();
  delay(5000);

  /* ----------------------------------------------------------------------- */

  Serial.println("Điều khiển động cơ kênh B...");
  Serial.println();

  Serial.println("Quay thuận 100%");
  demo.control_motor_channel_B(100, true);
  delay(5000);

  Serial.println("Quay ngược 50%");
  demo.control_motor_channel_B(50, false);
  delay(5000);

  Serial.println("Đứng yên");
  demo.control_motor_channel_B_stop();
  delay(5000);
}