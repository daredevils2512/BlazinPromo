#include "ShooterTShirtFireValve.h"

ShooterTShirtFireValve::ShooterTShirtFireValve(bool active) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires (Robot::shootertshirt.get());
	m_active = active;
}

// Called just before this Command runs the first time
void ShooterTShirtFireValve::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ShooterTShirtFireValve::Execute() {
	if (m_active) {
		Robot::shootertshirt->ValveOpen();
	}else{
		Robot::shootertshirt->ValveClose();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterTShirtFireValve::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterTShirtFireValve::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterTShirtFireValve::Interrupted() {

}
