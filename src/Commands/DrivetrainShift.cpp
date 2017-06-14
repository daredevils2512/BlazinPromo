#include "DrivetrainShift.h"
#include "Robot.h"

DrivetrainShift::DrivetrainShift(bool direction) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
	this->direction = direction;
}

// Called just before this Command runs the first time
void DrivetrainShift::Initialize() {
	this->SetInterruptible(false);
	this->SetTimeout(0.02);
	Robot::drivetrain->DriveRobot(0,0);
}

// Called repeatedly when this Command is scheduled to run
void DrivetrainShift::Execute() {
	if(direction){
		Wait(0.01);
		Robot::drivetrain->Shift(frc::DoubleSolenoid::kForward);
	}else{
		Wait(0.01);
		Robot::drivetrain->Shift(frc::DoubleSolenoid::kReverse);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DrivetrainShift::IsFinished() {
	return this->IsTimedOut();
}

// Called once after isFinished returns true
void DrivetrainShift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivetrainShift::Interrupted() {

}
