#include "ShooterTShirtActuateSolenoid2.h"

ShooterTShirtActuateSolenoid2::ShooterTShirtActuateSolenoid2(bool direction) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shootertshirt.get());

	m_direction = direction;
}

// Called just before this Command runs the first time
void ShooterTShirtActuateSolenoid2::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterTShirtActuateSolenoid2::Execute() {
	if (m_direction) {
		Robot::shootertshirt->ActuateSolenoidTwo(frc::DoubleSolenoid::kForward);
	}else{
		Robot::shootertshirt->ActuateSolenoidTwo(frc::DoubleSolenoid::kReverse);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterTShirtActuateSolenoid2::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterTShirtActuateSolenoid2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterTShirtActuateSolenoid2::Interrupted() {

}
