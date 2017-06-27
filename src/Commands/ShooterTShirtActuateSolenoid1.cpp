#include "ShooterTShirtActuateSolenoid1.h"

ShooterTShirtActuateSolenoid1::ShooterTShirtActuateSolenoid1(bool direction) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shootertshirt.get());

	m_direction = direction;
}

// Called just before this Command runs the first time
void ShooterTShirtActuateSolenoid1::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterTShirtActuateSolenoid1::Execute() {
	if (m_direction) {
		Robot::shootertshirt->ActuateSolenoidOne(frc::DoubleSolenoid::kReverse);
	}else{
		Robot::shootertshirt->ActuateSolenoidOne(frc::DoubleSolenoid::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterTShirtActuateSolenoid1::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterTShirtActuateSolenoid1::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterTShirtActuateSolenoid1::Interrupted() {

}
