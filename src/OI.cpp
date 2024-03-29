#include "OI.h"
#include "RobotMap.h"
#include "Commands/_CMG_ShootTShirt.h"
#include "Commands/_CMG_ShootFrisbee.h"
#include "Commands/ShooterFrisbeeActuate.h"
#include "Commands/ShooterFrisbeeRunMotor.h"
#include "Commands/ShooterTShirtActuateSolenoid1.h"
#include "Commands/ShooterTShirtActuateSolenoid2.h"
#include "Commands/ShooterTShirtFireValve.h"
OI::OI()
{
	// activates commands based on controller inputs
	DRC_rightTrigger.WhenPressed(new _CMG_ShootTShirt());
	DRC_leftTrigger.WhenPressed(new ShooterFrisbeeActuate(true));
	DRC_a_Button.WhenPressed(new ShooterTShirtActuateSolenoid1(true));
	DRC_b_Button.WhenPressed(new ShooterTShirtActuateSolenoid1(false));
	DRC_x_Button.WhenPressed(new ShooterTShirtActuateSolenoid2(true));
	DRC_y_Button.WhenPressed(new ShooterTShirtActuateSolenoid2(false));
	DRC_start_Button.WhileHeld(new ShooterFrisbeeRunMotor(1.0));
	DRC_start_Button.WhenReleased(new ShooterFrisbeeRunMotor(0.0));

}


double OI::GetDriveMove() {
	//get forward/backwards values, invert if inverting driving
	if(InvertDriving()) {
		return Desensitize(driverController.GetRawAxis(1));
	}else{
		return Desensitize(-driverController.GetRawAxis(1));
	}
}

double OI::GetDriveTurn() {
	//get turning values
	return Desensitize(-driverController.GetRawAxis(4));
}

double OI::Desensitize(double value) {
	//set threshold so tiny values on the joystick don't register,
	//sometimes resting value of joystick is not 0
	if (fabs(value) < 0.2) value = 0;
	return value;
}

double OI::GetThrottle() {
	//get value of throttle axis
	return coDriverController.GetRawAxis(3);
}

bool OI::InvertDriving() {
	//for traversing defenses easier, invert forward/backward direction if
	//driver left trigger is held
	//also set controller to rumble, to inform driver controls are now inverted
	if(DRC_leftBumper.Get()) {
		driverController.SetRumble(frc::Joystick::kRightRumble, 1.0);
		return true;
	}else{
		driverController.SetRumble(frc::Joystick::kRightRumble, 0.0);
		return false;
	}
}
bool OI::POVForward() {
	//detects if the POV hat is pushed forward or not
	if((coDriverController.GetPOV() >= 270) || (coDriverController.GetPOV() <= 90)) {
		return true;
	}else{
		return false;
	}
}

int OI::GetJoystickPOV() {
	//accesses the POV hat value
	return coDriverController.GetPOV();
}

bool OI::DriveNosKick() {
	if(DRC_rightBumper.Get()) {
		RobotMap::drivetrainchassis->SetMaxOutput(1.5);
		return true;
	}else{
		RobotMap::drivetrainchassis->SetMaxOutput(1.0);
		return false;
	}
}
