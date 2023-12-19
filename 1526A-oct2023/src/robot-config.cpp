#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightMotorMotorA = motor(PORT1, ratio18_1, false);
motor RightMotorMotorB = motor(PORT2, ratio18_1, true);
motor_group RightMotor = motor_group(RightMotorMotorA, RightMotorMotorB);
motor LeftMotorMotorA = motor(PORT3, ratio18_1, false);
motor LeftMotorMotorB = motor(PORT4, ratio18_1, true);
motor_group LeftMotor = motor_group(LeftMotorMotorA, LeftMotorMotorB);
motor Motor5 = motor(PORT5, ratio36_1, true);
motor Motor6 = motor(PORT6, ratio18_1, false);
motor Right2 = motor(PORT8, ratio6_1, true);
motor Left2 = motor(PORT7, ratio6_1, false);
digital_out Sol1 = digital_out(Brain.ThreeWirePort.A);
digital_out Sol2 = digital_out(Brain.ThreeWirePort.B);
digital_out PistonRight = digital_out(Brain.ThreeWirePort.C);
rotation Rotati = rotation(PORT9, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}