#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 2.5, 2.5, 20, 2.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
Intake.setVelocity(100, percent);
  Intake.spin(forward);
  chassis.drive_distance(7);
  chassis.drive_distance(-24);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Left4.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  Right4.spin(forward);
  wait(.7, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Left4.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();
  Right4.stop();

  chassis.drive_distance(-16);

  wait(.1, sec);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Left4.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  Right4.spin(forward);
  wait(.8, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Left4.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();
  Right4.stop();

  wait(.2, sec);

  chassis.drive_distance(-15);
  chassis.drive_distance(15);

  wait(.1, sec);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Left4.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  Right4.spin(forward);
  wait(2.65, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Left4.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();
  Right4.stop();

  chassis.drive_distance(12);
  chassis.drive_distance(-6);

  wait(.1, sec);

   //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Left4.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  Right4.spin(forward);
  wait(1.4, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Left4.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();
  Right4.stop();

  Intake.stop();
}

void turn_test(){
}

void swing_test(){
}

void full_test(){
}

void odom_test(){
}

void tank_odom_test(){
}

void holonomic_odom_test(){
}