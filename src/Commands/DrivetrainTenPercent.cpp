#include "DrivetrainTenPercent.h"

DrivetrainTenPercent::DrivetrainTenPercent()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DrivetrainTenPercent::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DrivetrainTenPercent::Execute()
{
	Robot::drivetrain->DriveRobot(0.1, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DrivetrainTenPercent::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DrivetrainTenPercent::End()
{
	Robot::drivetrain->DriveRobot(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivetrainTenPercent::Interrupted()
{
	End();
}
