#include "ShooterFrisbeeActuate.h"

ShooterFrisbeeActuate::ShooterFrisbeeActuate(bool direction) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shooterfrisbee.get());

	m_direction = direction;
}

// Called just before this Command runs the first time
void ShooterFrisbeeActuate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterFrisbeeActuate::Execute() {
	if (m_direction) {
		Robot::shooterfrisbee->ActuateShooterSolenoid(frc::DoubleSolenoid::kReverse);
	}else{
		Robot::shooterfrisbee->ActuateShooterSolenoid(frc::DoubleSolenoid::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterFrisbeeActuate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterFrisbeeActuate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterFrisbeeActuate::Interrupted() {

}
