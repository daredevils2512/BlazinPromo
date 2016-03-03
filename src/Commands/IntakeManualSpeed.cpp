#include "IntakeManualSpeed.h"

IntakeManualSpeed::IntakeManualSpeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeManualSpeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeManualSpeed::Execute()
{
	if(Robot::oi->POVForward()) {
		Robot::intake->SetIntakeSpeed(1.0);
	}else{
		Robot::intake->SetIntakeSpeed(-1.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeManualSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeManualSpeed::End()
{
	Robot::intake->SetIntakeSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeManualSpeed::Interrupted()
{
	End();
}
