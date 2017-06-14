#include "ShooterTShirt.h"
#include "../RobotMap.h"

ShooterTShirt::ShooterTShirt() : Subsystem("ShooterTShirt") {
	shooterSolenoidOne = RobotMap::shooterSolenoidOne;
	shooterSolenoidTwo = RobotMap::shooterSolenoidTwo;
	shooterSpike = RobotMap::shooterSpike;


}

void ShooterTShirt::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShooterTShirt::ActuateSolenoidOne(frc::DoubleSolenoid::Value dir) {
	shooterSolenoidOne->Set(dir);
}

void ShooterTShirt::ActuateSolenoidTwo(frc::DoubleSolenoid::Value dir) {
	shooterSolenoidTwo->Set(dir);
}
void RelayInfo() {
	RobotMap::shooterSpike->Get();
}
