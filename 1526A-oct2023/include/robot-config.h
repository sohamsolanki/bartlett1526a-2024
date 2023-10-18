using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group RightMotor;
extern motor_group LeftMotor;
extern motor Motor5;
extern motor Motor6;
extern motor Motor8;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );