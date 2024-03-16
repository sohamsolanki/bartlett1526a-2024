using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Left1;
extern motor Left2;
extern motor_group Left3;
extern motor Right1;
extern motor Right2;
extern motor_group Right3;
extern motor Intake;
extern digital_out Sol1;
extern digital_out Sol2;
extern digital_out Sol3;
extern digital_out Sol4;
extern digital_out Sol5;
extern digital_out Sol6;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );