#include "ShooterManualSpeed.h"

ShooterManualSpeed::ShooterManualSpeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterManualSpeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterManualSpeed::Execute()
{
	Robot::shooter->SetShooterSpeed(Robot::oi->GetThrottle());
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterManualSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterManualSpeed::End()
{
	Robot::shooter->SetShooterSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterManualSpeed::Interrupted()
{
	End();
}
