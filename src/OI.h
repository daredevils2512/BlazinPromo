#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "TriggerButton.h"
#include "POVButton.h"

//creates all of the inputs on the controllers
class OI
{
private:
	//declare controllers
	Joystick driverController{0};
	Joystick coDriverController{1};

	//driver controls
	TriggerButton DRC_rightTrigger{&driverController, 3, 0.8};
	TriggerButton DRC_leftTrigger{&driverController, 2, 0.8};
	JoystickButton DRC_rightBumper{&driverController, 6};
	JoystickButton DRC_leftBumper{&driverController, 5};
	JoystickButton DRC_a_Button{&driverController, 1};
	JoystickButton DRC_b_Button{&driverController, 2};
	JoystickButton DRC_x_Button{&driverController, 3};
	JoystickButton DRC_y_Button{&driverController, 4};
	JoystickButton DRC_start_Button{&driverController, 8};

	//codriver controls
	JoystickButton CDR_trigger{&coDriverController, 1};
	JoystickButton CDR_sideJoystickButton{&coDriverController, 2};
	JoystickButton CDR_bottomLeftJoystick{&coDriverController, 3};
	JoystickButton CDR_topLeftJoystick{&coDriverController, 5};
	JoystickButton CDR_bottomRightJoystick{&coDriverController, 4};
	JoystickButton CDR_topRightJoystick{&coDriverController, 6};
	JoystickButton CDR_bottomLeftBase{&coDriverController, 7};
	JoystickButton CDR_topLeftBase{&coDriverController, 8};
	JoystickButton CDR_bottomMiddleBase{&coDriverController, 9};
	JoystickButton CDR_topMiddleBase{&coDriverController, 10};
	JoystickButton CDR_bottomRightBase{&coDriverController, 11};
	JoystickButton CDR_topRightBase{&coDriverController, 12};
	POVButton CDR_joystickPOV{&coDriverController, 0};

public:
	OI();
	//control related functions
	double GetDriveMove();
	double GetDriveTurn();
	double Desensitize(double value);
	double GetThrottle();
	bool InvertDriving();
	bool POVForward();
	int GetJoystickPOV();
	bool DriveNosKick();
};

#endif
