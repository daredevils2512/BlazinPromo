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

OI::OI()
{
	// Process operator interface input here.
	DRC_rightTrigger.WhenPressed(new _CMG_IntakeBall());
	DRC_rightBumper.WhenPressed(new IntakeActuate(true));
	DRC_leftBumper.WhenPressed(new IntakeActuate(false));
	DRC_a_Button.WhenPressed(new IntakeSpeed(0.0));

	CDR_trigger.WhenPressed(new _CMG_ShootBall());
	CDR_sideJoystickButton.WhenPressed(new _CMG_ShooterCharge());
	CDR_bottomLeftJoystick.WhileHeld(new ShooterSpeed(0.0, false));
	CDR_topLeftJoystick.WhileHeld(new ShooterSpeed(GetThrottle(), false));
	CDR_bottomRightJoystick.WhenPressed(new ShooterActuate(false));
	CDR_topRightJoystick.WhenPressed(new ShooterActuate(true));
	CDR_bottomLeftBase.WhileHeld(new ClimbWinchSpeed(-1.0));
	CDR_bottomLeftBase.WhenReleased(new ClimbWinchSpeed(0.0));
	CDR_topLeftBase.WhileHeld(new ClimbWinchSpeed(1.0));
	CDR_topLeftBase.WhenReleased(new ClimbWinchSpeed(0.0));
	CDR_bottomMiddleBase.WhileHeld(new ClimbHookSpeed(-0.5));
	CDR_topMiddleBase.WhileHeld(new ClimbHookSpeed(0.5));
	CDR_bottomRightBase.WhenPressed(new IntakeActuate(false));
	CDR_topRightBase.WhenPressed(new IntakeActuate(true));
}

double OI::GetDriveMove() {
	if(InvertDriving()) {
		return Desensitize(driverController.GetRawAxis(1));
	}else{
		return Desensitize(-driverController.GetRawAxis(1));
	}
}

double OI::GetDriveTurn() {
	return Desensitize(-driverController.GetRawAxis(4));
}

double OI::Desensitize(double value) {
	if (fabs(value) < 0.2) value = 0;
	return value;
}

double OI::GetThrottle() {
	return coDriverController.GetRawAxis(3);
}

bool OI::InvertDriving() {
	if(DRC_leftTrigger.Get()) {
		driverController.SetRumble(Joystick::kRightRumble, 1.0);
		return true;
	}else{
		driverController.SetRumble(Joystick::kRightRumble, 0.0);
		return false;
	}
}
