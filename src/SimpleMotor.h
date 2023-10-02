#ifndef SIMPLE_MOTOR_H
#define SIMPLE_MOTOR_H

/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include <Arduino.h>

/* ------------------------------------------------------------------------- */
/*                                   CLASS                                   */
/* ------------------------------------------------------------------------- */

class SimpleMotor
{
public:
  /* ------------------------------- HÀM TẠO ------------------------------- */
  SimpleMotor(
      int pinIn1, int pinIn2,
      int pinIn3, int pinIn4);

  /* ----------------------------- HÀM SỬ DỤNG ----------------------------- */

  // Điều khiển xe đi thẳng tới
  void go_forward(int speed);

  // Điều khiển xe đi thẳng, rẽ trái
  void go_forward_left(int speed);

  // Điều khiển xe đi thẳng, rẽ phải
  void go_forward_right(int speed);

  // Điều khiển xe đi lùi
  void go_back(int speed);

  // Điều khiển xe đi lùi. rẽ trái
  void go_back_left(int speed);

  // Điều khiển xe đi lùi. rẽ phải
  void go_back_right(int speed);

  // Điều khiển xe xoay trái
  void rotate_left(int speed);

  // Điều khiển xe xoay phải
  void rotate_right(int speed);

  // Điều khiển xe di chuyển (tùy chỉnh)
  void go_custom(int speedLeft, int speedRight);

  // Điều khiển dừng xe lại
  void stop();

private:
  /* --------------------------------- BIẾN -------------------------------- */
  int _pinIn1;
  int _pinIn2;
  int _pinIn3;
  int _pinIn4;

  /* ------------------------- HÀM ĐIỀU KHIỂN MOTOR ------------------------ */

  // Điều khiển Motor bên Phải quay tới
  void motor_right_rotate_forward(int PWM);

  // Điều khiển Motor bên Trái quay tới
  void motor_left_rotate_forward(int PWM);

  // Điều khiển Motor bên Phải quay lùi
  void motor_right_rotate_reverse(int PWM);

  // Điều khiển Motor bên Trái quay lùi
  void motor_left_rotate_reverse(int PWM);

  // Điều khiển Motor bên Phải dừng lại
  void motor_right_stop();

  // Điều khiển Motor bên Trái dừng lại
  void motor_left_stop();
};

/* ------------------------------------------------------------------------- */

#endif