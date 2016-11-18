#include "OI.h"
#include "Commands/_CMG_IntakeBall.h"
#include "Commands/IntakeActuate.h"
#include "Commands/IntakeSpeed.h"
#include "Commands/_CMG_ShootBall.h"
#include "Commands/_CMG_ShooterCharge.h"
#include "Commands/ClimbWinchSpeed.h"
#include "Commands/ShooterActuate.h"
#include "Commands/ShooterSpeed.h"
#include "Commands/ClimbHookSpeed.h"
#include "Commands/ShooterManualSpeed.h"
#include "Commands/IntakeManualSpeed.h"
#include "Commands/DrivetrainTenPercent.h"
OI::OI()
{
	// activates commands based on controller inputs
	DRC_rightTrigger.WhenPressed(new _CMG_IntakeBall()); //intake ball
	DRC_rightBumper.WhenPressed(new IntakeActuate(true)); //intake up
	DRC_leftBumper.WhenPressed(new IntakeActuate(false)); //intake down
	DRC_a_Button.WhenPressed(new IntakeSpeed(0.0)); //stop intake
	DRC_b_Button.WhileHeld(new DrivetrainTenPercent());

	CDR_trigger.WhenPressed(new _CMG_ShootBall());//fire ball
	CDR_sideJoystickButton.WhenPressed(new _CMG_ShooterCharge());//start revving up shooter
	CDR_bottomLeftJoystick.WhileHeld(new ShooterSpeed(0.0, false));//stop shooter wheels
	CDR_topLeftJoystick.WhileHeld(new ShooterManualSpeed());//set shooter speed with throttle
	CDR_bottomRightJoystick.WhenPressed(new ShooterActuate(false));
	CDR_topRightJoystick.WhenPressed(new ShooterActuate(true));
	CDR_bottomLeftBase.WhileHeld(new ClimbWinchSpeed(-1.0)); // rope in/robot up
	CDR_bottomLeftBase.WhenReleased(new ClimbWinchSpeed(0.0));
	CDR_topLeftBase.WhileHeld(new ClimbWinchSpeed(1.0)); // rope out/robot down
	CDR_topLeftBase.WhenReleased(new ClimbWinchSpeed(0.0));
	CDR_bottomMiddleBase.WhileHeld(new ClimbHookSpeed(-0.9)); //hook down
	CDR_topMiddleBase.WhileHeld(new ClimbHookSpeed(0.7)); //hook up
	CDR_bottomRightBase.WhenPressed(new IntakeActuate(false));
	CDR_topRightBase.WhenPressed(new IntakeActuate(true));
	CDR_joystickPOV.WhenPressed(new IntakeManualSpeed());
	CDR_joystickPOV.WhenReleased(new IntakeSpeed(0.0));
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
	if(DRC_leftTrigger.Get()) {
		driverController.SetRumble(Joystick::kRightRumble, 1.0);
		return true;
	}else{
		driverController.SetRumble(Joystick::kRightRumble, 0.0);
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
