#include "ShooterFrisbee.h"
#include "../RobotMap.h"

ShooterFrisbee::ShooterFrisbee() : Subsystem("ShooterFrisbee") {
	Motor = RobotMap::shooterFrisbeeMotor;
	Solenoid = RobotMap::shooterFrisbeeSolenoid;
	Photoeye = RobotMap::shooterFrisbeePhotoeye;

	ShooterRPM = 2000;
}

void ShooterFrisbee::InitDefaultCommand() {

}

void ShooterFrisbee::SetFlywheelSpeed(double speed) {
	Motor->Set(speed);
}

void ShooterFrisbee::ActuateShooterSolenoid(frc::DoubleSolenoid::Value dir) {
	Solenoid->Set(dir);
}

void ShooterFrisbee::GetPhotoeye() {
	Photoeye->Get();
}
