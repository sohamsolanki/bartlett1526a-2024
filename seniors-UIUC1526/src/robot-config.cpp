#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left1 = motor(PORT1, ratio6_1, false);
motor Left2 = motor(PORT2, ratio18_1, true);
motor Left3MotorA = motor(PORT3, ratio6_1, false);
motor Left3MotorB = motor(PORT4, ratio6_1, true);
motor_group Left3 = motor_group(Left3MotorA, Left3MotorB);
motor Right1 = motor(PORT5, ratio6_1, true);
motor Right2 = motor(PORT6, ratio18_1, false);
motor Right3MotorA = motor(PORT7, ratio6_1, true);
motor Right3MotorB = motor(PORT8, ratio6_1, false);
motor_group Right3 = motor_group(Right3MotorA, Right3MotorB);
motor Intake = motor(PORT9, ratio6_1, false);
digital_out Sol1 = digital_out(Brain.ThreeWirePort.A);
digital_out Sol2 = digital_out(Brain.ThreeWirePort.B);
digital_out Sol3 = digital_out(Brain.ThreeWirePort.C);
digital_out Sol4 = digital_out(Brain.ThreeWirePort.D);
digital_out Sol5 = digital_out(Brain.ThreeWirePort.E);
digital_out Sol6 = digital_out(Brain.ThreeWirePort.F);
controller Controller1 = controller(primary);

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