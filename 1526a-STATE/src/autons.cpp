#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
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
  /*
  // TURNING // 
  //left side
  Left1.spin(forward);
  Left2.spin(forward);
  Left3.spin(forward);
  Left4.spin(forward);

  //right side
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  Right4.spin(reverse);

  wait(1.4, sec);

  Left1.stop();
  Left2.stop();
  Left3.stop();
  Left4.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();
  Right4.stop();

  wait(0.2, seconds);

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

  // Drive FORWARD and BACK //
  // forward
  chassis.drive_distance(10);
  // back
  chassis.drive_distance(-10);
  */

  // NEWEWEWEWE
  
  Intake.setVelocity(100, percent);
  Intake.spin(forward);
  chassis.drive_distance(7);
  chassis.drive_distance(-8.5);
  chassis.drive_distance(-7.5);
  chassis.drive_distance(-8);

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
/* void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}
*/