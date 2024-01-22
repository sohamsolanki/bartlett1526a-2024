/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Soham Solanki                                             */
/*    Created:      Saturday, January 6, 2024                                 */
/*    Description:  1526A (Seniors): Competition Code                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftDou              digital_out   A               
// RightDou             digital_out   B               
// Controller1          controller                    
// LeftWing             digital_out   H               
// RightWing            digital_out   G               
// RightMotor           motor_group   1, 2            
// LeftMotor            motor_group   3, 4            
// CataP                motor         5               
// Intake               motor         6               
// Right2               motor         7               
// Left2                motor         8               
// Roti                 rotation      11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  vexcodeInit();
  Roti.setPosition(0.00, degrees);
  LeftMotor.setVelocity(100, percent);
  Left2.setVelocity(100, percent);
  RightMotor.setVelocity(100, percent);
  Right2.setVelocity(100, percent);
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  LeftMotor.spin(forward);
  Left2.spin(forward);
  RightMotor.spin(forward);
  Right2.spin(forward);
  wait(0.8, seconds);
  LeftMotor.spin(reverse);
  Left2.spin(reverse);
  RightMotor.spin(reverse);
  Right2.spin(reverse);
  wait(1.2, seconds);
  LeftMotor.stop();
  Left2.stop();
  RightMotor.stop();
  Right2.stop();
}

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
  LeftMotor.spin(type, percentage, vex::velocityUnits::pct);
  Left2.spin(type, percentage, vex::velocityUnits::pct);
}
void setRightDriveExpo (vex::directionType type, int percentage) {
  if (percentage >= 0) {
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
  } else {
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
    percentage = -percentage;
  }
  RightMotor.spin(type, percentage, vex::velocityUnits::pct);
  Right2.spin(type, percentage, vex::velocityUnits::pct);
}

void usercontrol(void) {
  while (1) {

    // Pneumatics (Wings) functions -- NOT WORKING (as of January 6, 9:49pm.) //
    if(Controller1.ButtonL1.pressing()) {
      LeftDou.set(true);
      RightDou.set(true);
    } else if (Controller1.ButtonL2.pressing()) {
      LeftDou.set(false);
      RightDou.set(false);
    }

    // Catapult code -- (as of January 6, 9:33pm.) //
    if (Controller1.ButtonRight.pressing()) {
      CataP.setVelocity(100, percent);
      CataP.spin(forward);
    } else if (Controller1.ButtonY.pressing()) {
      CataP.stop();
    }

    // Intake code. //
    if(Controller1.ButtonR1.pressing()) {
      Intake.setVelocity(100, percent);
      Intake.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.setVelocity(100, percent);
      Intake.spin(reverse);
    } else {
      Intake.stop();
    }

    // Calling drive code functions. //
    setLeftDriveExpo (vex::directionType::fwd, Controller1.Axis3.value());
    setRightDriveExpo (vex::directionType::fwd, Controller1.Axis2.value());

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
