/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include "SimpleMotor.h"

/* ------------------------------------------------------------------------- */
/*                                  HÀM TẠO                                  */
/* ------------------------------------------------------------------------- */

SimpleMotor::SimpleMotor(
    int pinIn1, int pinIn2,
    int pinIn3, int pinIn4)
{
  _pinIn1 = pinIn1;
  _pinIn2 = pinIn2;
  _pinIn3 = pinIn3;
  _pinIn4 = pinIn4;

  pinMode(_pinIn1, OUTPUT);
  pinMode(_pinIn2, OUTPUT);
  pinMode(_pinIn3, OUTPUT);
  pinMode(_pinIn4, OUTPUT);
}

/* ------------------------------------------------------------------------- */
/*                                HÀM SỬ DỤNG                                */
/* ------------------------------------------------------------------------- */

/**
 * Điều khiển xe đi thẳng tới
 *
 * Motor bên Trái đi tới (+)
 * Motor bên Phải đi tới (+)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_forward(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_forward(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_forward(speed);
}

/**
 * Điều khiển xe đi thẳng, rẽ trái
 *
 * Motor bên Trái đi tới, chậm hơn 1/2 (+)
 * Motor bên Phải đi tới (+)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_forward_left(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_forward(speed / 2);

  // Xử lý motor bên Phải
  motor_right_rotate_forward(speed);
}

/**
 * Điều khiển xe đi thẳng, rẽ phải
 *
 * Motor bên Trái đi tới (+)
 * Motor bên Phải đi tới, chậm hơn 1/2 (+)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_forward_right(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_forward(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_forward(speed / 2);
}

/* ------------------------------------------------------------------------- */

/**
 * Điều khiển xe đi lùi
 *
 * Motor bên Trái đi lùi (-)
 * Motor bên Phải đi lùi (-)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_back(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_reverse(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_reverse(speed);
}

/**
 * Điều khiển xe đi lùi, rẽ trái
 *
 * Motor bên Trái đi lùi, chậm hơn 1/2 (-)
 * Motor bên Phải đi lùi (-)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_back_left(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_reverse(speed / 2);

  // Xử lý motor bên Phải
  motor_right_rotate_reverse(speed);
}

/**
 * Điều khiển xe đi lùi, rẽ phải
 *
 * Motor bên Trái đi lùi (-)
 * Motor bên Phải đi lùi, chậm hơn 1/2 (-)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::go_back_right(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_reverse(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_reverse(speed / 2);
}

/* ------------------------------------------------------------------------- */

/**
 * Điều khiển xe xoay trái
 *
 * Motor bên Trái đi lùi (-)
 * Motor bên Phải đi tới (+)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::rotate_left(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_reverse(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_forward(speed);
}

/**
 * Điều khiển xe xoay phải
 *
 * Motor bên Trái đi tới (+)
 * Motor bên Phải đi lùi (-)
 *
 * Đơn vị (~pwm)
 * Phạm vi [0 : 255]
 */
void SimpleMotor::rotate_right(int speed)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speed, 0, 255);

  // Xử lý motor bên Trái
  motor_left_rotate_forward(speed);

  // Xử lý motor bên Phải
  motor_right_rotate_reverse(speed);
}

/* ------------------------------------------------------------------------- */

/**
 * Điều khiển xe di chuyển (tùy chỉnh)
 *
 * Giá trị dương (+), bánh xe quay hướng đi tới
 * Giá trị âm (-), bánh xe quay hướng đi lùi
 *
 * Đơn vị (~pwm)
 * Phạm vi [-255 : +255]
 */
void SimpleMotor::go_custom(int speedLeft, int speedRight)
{
  // Lọc giá trị tốc độ nhận được
  constrain(speedLeft, -255, 255);
  constrain(speedRight, -255, 255);

  // Xử lý motor bên Trái
  if (speedLeft >= 0)
    motor_left_rotate_forward(speedLeft);
  else
    motor_left_rotate_reverse(-speedLeft);

  // Xử lý motor bên Phải
  if (speedRight >= 0)
    motor_right_rotate_forward(speedRight);
  else
    motor_right_rotate_reverse(-speedRight);
}

/**
 * Điều khiển dừng xe lại
 *
 * Dừng motor bên Trái
 * Dừng motor bên Phải
 */
void SimpleMotor::stop()
{
  motor_left_stop();
  motor_right_stop();
}

/* ------------------------------------------------------------------------- */
/*                            HÀM ĐIỀU KHIỂN MOTOR                           */
/* ------------------------------------------------------------------------- */

// Điều khiển Motor bên Phải quay tới
void SimpleMotor::motor_right_rotate_forward(int PWM)
{
  digitalWrite(_pinIn4, LOW);
  analogWrite(_pinIn3, PWM);
}

// Điều khiển Motor bên Trái quay tới
void SimpleMotor::motor_left_rotate_forward(int PWM)
{
  analogWrite(_pinIn2, PWM);
  digitalWrite(_pinIn1, LOW);
}

/* ------------------------------------------------------------------------- */

// Điều khiển Motor bên Phải quay lùi
void SimpleMotor::motor_right_rotate_reverse(int PWM)
{
  digitalWrite(_pinIn4, HIGH);
  analogWrite(_pinIn3, 255 - PWM);
}

// Điều khiển Motor bên Trái quay lùi
void SimpleMotor::motor_left_rotate_reverse(int PWM)
{
  analogWrite(_pinIn2, 255 - PWM);
  digitalWrite(_pinIn1, HIGH);
}

/* ------------------------------------------------------------------------- */

// Điều khiển Motor bên Phải dừng lại
void SimpleMotor::motor_right_stop()
{
  digitalWrite(_pinIn3, LOW);
  digitalWrite(_pinIn4, LOW);
}

// Điều khiển Motor bên Trái dừng lại
void SimpleMotor::motor_left_stop()
{
  digitalWrite(_pinIn1, LOW);
  digitalWrite(_pinIn2, LOW);
}

/* ------------------------------------------------------------------------- */