#include "AutonVisionTurning.h"

AutonVisionTurning::AutonVisionTurning()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain.get());
	SetTimeout(0.2);
}

// Called just before this Command runs the first time
void AutonVisionTurning::Initialize()
{
	target = Robot::visionTracking->GetTargetX();
	if(target.HasValue()) {
		if(target.GetValue() > UPPER_LIMIT) {
			direction = 1;
		}else if(target.GetValue() < LOWER_LIMIT) {
			direction = 2;
		}
	}

}

// Called repeatedly when this Command is scheduled to run
void AutonVisionTurning::Execute()
{
	if(direction == 1) {
		Robot::drivetrain->AutonTankDrive(0.5, -0.5);
	}else if(direction == 2) {
		Robot::drivetrain->AutonTankDrive(-0.5, 0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonVisionTurning::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonVisionTurning::End()
{
	Robot::drivetrain->DriveRobot(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonVisionTurning::Interrupted()
{

}
