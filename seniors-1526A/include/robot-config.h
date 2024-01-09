using namespace vex;

extern brain Brain;

// VEXcode devices
extern digital_out LeftDou;
extern digital_out RightDou;
extern controller Controller1;
extern digital_out LeftWing;
extern digital_out RightWing;
extern motor_group RightMotor;
extern motor_group LeftMotor;
extern motor CataP;
extern motor Intake;
extern motor Right2;
extern motor Left2;
extern rotation Roti;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );