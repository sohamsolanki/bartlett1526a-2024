/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Soham Solanki and Raiyan Hasan                            */
/*    Created:      October 15, 2023                                          */
/*    Description:  1526A - November Code                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightMotor           motor_group   1, 2            
// LeftMotor            motor_group   3, 4            
// Motor5               motor         5               
// Motor6               motor         6               
// Right2               motor         8               
// Left2                motor         7               
// Intake               digital_out   A               
// PistonLeft           digital_out   B               
// PistonRight          digital_out   C               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts goes here
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  /* LeftMotor.spin(forward);
  RightMotor.spin(forward);
  Left2.spin(forward);
  Right2.spin(forward);
  wait(1.97, sec);
  LeftMotor.stop();
  RightMotor.stop();
  Left2.stop();
  Right2.stop(); */
  
  LeftMotor.spin(forward);
  RightMotor.spin(reverse);
  Left2.spin(reverse);
  Right2.spin(forward);
  wait(1.95, sec);
  LeftMotor.stop();
  RightMotor.stop();
  Left2.stop();
  Right2.stop();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

// EXPONENTIAL DRIVE CODE FUNCTIONS //
void setLeftDriveExpo (vex::directionType type, int percentage) {
  if (percentage >= 0) {
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
  } else {
    percentage = -percentage;
    percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
    percentage = -percentage;
  }
  LeftMotor.spin(type, percentage, vex::velocityUnits::pct);
  Right2.spin(type, percentage, vex::velocityUnits::pct);
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
  Left2.spin(type, percentage, vex::velocityUnits::pct);
}

// FUNCTIONS FOR INTAKE //
bool switchOn = false;
bool switchOff = true;

void intakeon(void) {
  switchOn = true;
  switchOff = false;
}

void intakeoff(void) {
  switchOn = false;
  switchOff = true;
}

// FUNCTIONS FOR CATAPULT //
bool cataOn = false;
bool cataOff = true;

void pulton(void) {
  cataOn = true;
  cataOff = false;
}

void pultoff(void) {
  cataOn = false;
  cataOff = true;
}

// FUNCTIONS FOR DOUBLE ACTING PISTONS //
bool pistOn = false;
bool pistOff = true;

void onon(void) {
  pistOn = true;
  pistOff = false;
}

void onoff(void) {
  pistOn = false;
  pistOff = true;
}

void usercontrol(void) {
  while (1) {
    // calling drivecode functions //
    setLeftDriveExpo (vex::directionType::fwd, Controller1.Axis3.value());
    setRightDriveExpo (vex::directionType::fwd, Controller1.Axis2.value());

    // catapult code //
    /* if (Controller1.ButtonL2.pressing()) {
      Motor5.setVelocity(100, percent);
      Motor6.setVelocity(25, percent);
      Motor5.spin(forward);
      Motor6.spin(forward);
    } else {
      Motor5.stop();
      Motor6.stop();
    }
    */

    // intake code //
    if(switchOn == true){
      Intake.set(true);
    }

    if(switchOff == true){
      Intake.set(false);
    }

    // catapult code //
    if(cataOn == true) {
      Motor5.setVelocity(40, percent);
      Motor5.spin(forward);
      Motor6.setVelocity(40, percent);
      Motor6.spin(forward);
    }
    if (cataOff == true) {
    }

    // double acting pistons //
    if(pistOn == true) {
      PistonLeft.set(true);
      PistonRight.set(true);
            Motor5.setVelocity(40, percent);
      Motor5.spin(forward);
      Motor6.setVelocity(40, percent);
      Motor6.spin(forward);
    }
    if (pistOff == true) {
      PistonLeft.set(false);
      PistonRight.set(false);
      Motor5.stop();
      Motor6.stop();
    }

    // calling intake function // 
    Controller1.ButtonR2.pressed(intakeon);
    Controller1.ButtonR1.pressed(intakeoff);

    // calling catapult function //
    Controller1.ButtonY.pressed(pulton);
    Controller1.ButtonA.pressed(pultoff);

    // calling piston function //
    Controller1.ButtonLeft.pressed(onon);
    Controller1.ButtonRight.pressed(onoff);
 
    wait(20, msec); 
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
