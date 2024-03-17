#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left1 = motor(PORT10, ratio6_1, false);
motor Left2 = motor(PORT9, ratio18_1, false);
motor Right1 = motor(PORT20, ratio6_1, true);
motor Right2 = motor(PORT19, ratio18_1, true);
motor Intake = motor(PORT16, ratio6_1, false);
digital_out Sol1 = digital_out(Brain.ThreeWirePort.A);
digital_out Sol2 = digital_out(Brain.ThreeWirePort.B);
digital_out Sol3 = digital_out(Brain.ThreeWirePort.C);
digital_out Sol4 = digital_out(Brain.ThreeWirePort.D);
digital_out Sol5 = digital_out(Brain.ThreeWirePort.E);
digital_out Sol6 = digital_out(Brain.ThreeWirePort.F);
controller Controller1 = controller(primary);
motor Left3 = motor(PORT8, ratio6_1, false);
motor Left4 = motor(PORT7, ratio6_1, true);
motor Right3 = motor(PORT18, ratio6_1, true);
motor Right4 = motor(PORT17, ratio6_1, false);

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