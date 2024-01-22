#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
digital_out LeftDou = digital_out(Brain.ThreeWirePort.A);
digital_out RightDou = digital_out(Brain.ThreeWirePort.B);
controller Controller1 = controller(primary);
digital_out LeftWing = digital_out(Brain.ThreeWirePort.H);
digital_out RightWing = digital_out(Brain.ThreeWirePort.G);
motor RightMotorMotorA = motor(PORT1, ratio18_1, false);
motor RightMotorMotorB = motor(PORT2, ratio18_1, true);
motor_group RightMotor = motor_group(RightMotorMotorA, RightMotorMotorB);
motor LeftMotorMotorA = motor(PORT3, ratio18_1, false);
motor LeftMotorMotorB = motor(PORT4, ratio18_1, true);
motor_group LeftMotor = motor_group(LeftMotorMotorA, LeftMotorMotorB);
motor CataP = motor(PORT5, ratio36_1, true);
motor Intake = motor(PORT6, ratio18_1, true);
motor Right2 = motor(PORT7, ratio6_1, false);
motor Left2 = motor(PORT8, ratio6_1, true);
rotation Roti = rotation(PORT11, false);

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