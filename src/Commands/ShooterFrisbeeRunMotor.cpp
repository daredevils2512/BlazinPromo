#include "ShooterFrisbeeRunMotor.h"

ShooterFrisbeeRunMotor::ShooterFrisbeeRunMotor(double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shooterfrisbee.get());
	m_speed = speed;
}

// Called just before this Command runs the first time
void ShooterFrisbeeRunMotor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterFrisbeeRunMotor::Execute() {
	Robot::shooterfrisbee->SetFlywheelSpeed(m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterFrisbeeRunMotor::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterFrisbeeRunMotor::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterFrisbeeRunMotor::Interrupted() {

}
