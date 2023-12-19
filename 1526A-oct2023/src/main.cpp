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
// Sol1                 digital_out   A               
// Sol2                 digital_out   B               
// PistonRight          digital_out   C               
// Rotati               rotation      9               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Soham Solanki and Raiyan Hasan                            */
/*    Created:      October 15, 2023                                          */
/*    Description:  1526A - December Code                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Rotati.setPosition(0.0, degrees);
  // All activities that occur before the competition starts goes here
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  LeftMotor.setVelocity(250, rpm);
  RightMotor.setVelocity(250, rpm);
  Left2.setVelocity(250, rpm);
  Right2.setVelocity(250, rpm);
  
  LeftMotor.spin(reverse);
  RightMotor.spin(reverse);
  Left2.spin(reverse);
  Right2.spin(reverse);
  wait(1.8, sec);

  LeftMotor.spin(forward);
  RightMotor.spin(forward);
  Left2.spin(forward);
  Right2.spin(forward);
  wait(0.5, sec);

  LeftMotor.setVelocity(270, rpm);
  RightMotor.setVelocity(270, rpm);
  Left2.setVelocity(270, rpm);
  Right2.setVelocity(270, rpm);
  
  LeftMotor.spin(reverse);
  RightMotor.spin(reverse);
  Left2.spin(reverse);
  Right2.spin(reverse);
  wait(0.8, sec);

  LeftMotor.spin(forward);
  RightMotor.spin(forward);
  Left2.spin(forward);
  Right2.spin(forward);
  wait(1.2, sec);
  
  LeftMotor.stop();
  RightMotor.stop();
  Left2.stop();
  Right2.stop();

  /* LeftMotor.spin(forward);
  Left2.spin(reverse);
  RightMotor.spin(reverse);
  Right2.spin(forward);
  wait(0.5, sec);
  LeftMotor.spin(reverse);
  RightMotor.spin(reverse);
  Left2.spin(reverse);
  Right2.spin(reverse);
  wait(0.5, sec);
  LeftMotor.stop();
  RightMotor.stop();
  Left2.stop();
  Right2.stop(); */
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
bool intakeForward = false;
bool intakeReverse = true;
bool intakeOff = true;

void intakeforward(void) {
  intakeForward = true;
  intakeReverse = false;
  intakeOff = false;
}

void intakereverse(void) {
  intakeForward = false;
  intakeReverse = true;
  intakeOff = false;
}

void intakeoff(void) {
  intakeForward = false;
  intakeReverse = false;
  intakeOff = true;
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

// FUNCTIONS FOR SOLENOIDS //
bool solOn = false;
bool solOff = true;

void onon(void) {
  solOn = true;
  solOff = false;
}

void onoff(void) {
  solOn = false;
  solOff = true;
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
    /* if(intakeForward == true){
      Motor6.setVelocity(100, percent);
      Motor6.spin(forward);
    } else if (intakeForward == false) {
      Motor6.spin(reverse);
    } else {
      Motor6.stop();
    }

    if(intakeReverse == true){
      Motor6.setVelocity(100, percent);
      Motor6.spin(reverse);
    } else if (intakeReverse == false) {
      Motor6.spin(forward);
    } else {
      Motor6.stop();
    }

     
    if(intakeOff == true){
      Motor6.setVelocity(0, percent);
      Motor6.stop();
    }

    */

    if(Controller1.ButtonR2.pressing()) {
      Motor6.setVelocity(100, percent);
      Motor6.spin(forward);
    } else if (Controller1.ButtonR1.pressing()) {
      Motor6.setVelocity(100, percent);
      Motor6.spin(reverse);
    } else {
      Motor6.stop();
    }

    
    // catapult code //
    if(cataOn == true) {
      Motor5.setVelocity(100, percent);
      Motor5.spin(forward);
    }
    
    if (cataOff == true) {
      Motor5.setVelocity(100, percent);
      Motor5.spin(forward);
      if(Rotati.position(degrees) >= 12.9) {
        Motor5.setVelocity(0, percent);
        Motor5.stop();
        }
      }
    }

    // double acting pistons //
    if(solOn == true) {
      Sol1.set(true);
      Sol2.set(true);
    }
    if (solOff == true) {
      Sol1.set(false);
      Sol2.set(false);
    }
    
    /*
    // calling intake function// 
    Controller1.ButtonR2.pressed(intakeforward);
    Controller1.ButtonR1.pressed(intakereverse);
    Controller1.ButtonL1.pressed(intakeoff); 
    */

    // calling catapult function //
    Controller1.ButtonLeft.pressed(pulton);
    Controller1.ButtonRight.pressed(pultoff);

    // calling solenoid function //
    Controller1.ButtonL1.pressed(onon);
    Controller1.ButtonL2.pressed(onoff);
    
 
    wait(20, msec); 
  }

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
