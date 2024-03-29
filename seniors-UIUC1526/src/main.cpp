// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Left1                motor         1               
// Left2                motor         2               
// Left3                motor_group   3, 4            
// Right1               motor         5               
// Right2               motor         6               
// Right3               motor_group   7, 8            
// Intake               motor         9               
// Sol1                 digital_out   A               
// Sol2                 digital_out   B               
// Sol3                 digital_out   C               
// Sol4                 digital_out   D               
// Sol5                 digital_out   E               
// Sol6                 digital_out   F               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ssolanki                                                  */
/*    Created:      February 5, 2024                                          */
/*    Description:  UIUC Cornfield Clash Code                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "gifclass.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Left1                motor         1               
// Left2                motor         2               
// Left3                motor_group   3, 4            
// Right1               motor         5               
// Right2               motor         6               
// Right3               motor_group   7, 8            
// Intake               motor         9               
// Sol1                 digital_out   A               
// Sol2                 digital_out   B               
// Sol3                 digital_out   C               
// Sol4                 digital_out   D               
// Sol5                 digital_out   E               
// Sol6                 digital_out   F               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  vexcodeInit();
  Left1.setStopping(coast);
  Left2.setStopping(coast);
  Left3.setStopping(coast);
  Right1.setStopping(coast);
  Right2.setStopping(coast);
  Right3.setStopping(coast);
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Intake.setVelocity(100, percent);
  Intake.spin(forward);
  Left1.setVelocity(19.5, percent);
  Left2.setVelocity(19.5, percent);
  Left3.setVelocity(19.5, percent);
  Right1.setVelocity(19.5, percent);
  Right2.setVelocity(19.5, percent);
  Right3.setVelocity(19.5, percent);
  
  // chassis.drive_distance(7);
  Left1.spin(forward);
  Left2.spin(forward);
  Left3.spin(forward);
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(0.7, seconds);
  // chassis.drive_distance(-8.5);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(0.75, seconds);
  // chassis.drive_distance(-7.5);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(0.75, seconds);
  // chassis.drive_distance(-8);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(0.6, seconds);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(.3, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();

  // chassis.drive_distance(-16);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(1.6, seconds);

  wait(.1, sec);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(.3, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();

  wait(.2, sec);

  // chassis.drive_distance(-15);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(1.3, seconds);
  // chassis.drive_distance(15);
  Left1.spin(forward);
  Left2.spin(forward);
  Left3.spin(forward);
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(1.3, seconds);

  wait(.1, sec);

  //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(1.2, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop();

  // chassis.drive_distance(12);
  Left1.spin(forward);
  Left2.spin(forward);
  Left3.spin(forward);
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(1.2, seconds);
  // chassis.drive_distance(-6);
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  Right1.spin(reverse);
  Right2.spin(reverse);
  Right3.spin(reverse);
  wait(0.6, seconds);

   //left side
  Left1.spin(reverse);
  Left2.spin(reverse);
  Left3.spin(reverse);
  //right side
  Right1.spin(forward);
  Right2.spin(forward);
  Right3.spin(forward);
  wait(1.4, sec);
  Left1.stop();
  Left2.stop();
  Left3.stop();
  Right1.stop();
  Right2.stop();
  Right3.stop(); }

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

// Drive Code (Exponential): DO NOT TOUCH UNLESS NEEDED! //
void setLeftDriveExpo (vex::directionType type, int percentage) {
  if (percentage >= 0) {
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
  } else {
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
    percentage = -percentage;
  }
  Left1.spin(type, percentage, vex::velocityUnits::pct);
  Left2.spin(type, percentage, vex::velocityUnits::pct);
  Left3.spin(type, percentage, vex::velocityUnits::pct);

}
void setRightDriveExpo (vex::directionType type, int percentage) {
  if (percentage >= 0) {
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
  } else {
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
    percentage = -percentage;
  }
  Right1.spin(type, percentage, vex::velocityUnits::pct);
  Right2.spin(type, percentage, vex::velocityUnits::pct);
  Right3.spin(type, percentage, vex::velocityUnits::pct);
}

void usercontrol(void) {
  while (1) {
    // Intake code. //
    if (Controller1.ButtonR1.pressing()) {
      Intake.setVelocity(100, percent);
      Intake.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.setVelocity(100, percent);
      Intake.spin(reverse);
    } else {
      Intake.stop();
    }

    // Intake lift (solenoids). //
    if (Controller1.ButtonRight.pressing()) {
      Sol1.set(true);
      Sol2.set(true);
    }
    if (Controller1.ButtonY.pressing()) {
      Sol1.set(false);
      Sol2.set(false);
    }

    // Wings. //
    if(Controller1.ButtonL1.pressing()) {
      Sol3.set(true);
      Sol4.set(true);
    }
    if (Controller1.ButtonL2.pressing()) {
      Sol3.set(false);
      Sol4.set(false);
    }

    // Hang release. //
    if (Controller1.ButtonLeft.pressing()) {
      Sol5.set(true);
      Sol6.set(true);
    }

    // Calling drive code functions. //
    setLeftDriveExpo (vex::directionType::fwd, Controller1.Axis3.value());
    setRightDriveExpo (vex::directionType::fwd, Controller1.Axis2.value());

    vex::brain Brain;

    wait(20, msec);
  }
}
// do not touch!
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}