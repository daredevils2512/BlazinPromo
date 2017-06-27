#include "ShooterTShirt.h"
#include "../RobotMap.h"

ShooterTShirt::ShooterTShirt() : Subsystem("ShooterTShirt") {
	SolenoidOne = RobotMap::shooterSolenoidOne;
	SolenoidTwo = RobotMap::shooterSolenoidTwo;
	Spike = RobotMap::shooterSpike;

}

void ShooterTShirt::InitDefaultCommand() {

}

void ShooterTShirt::ActuateSolenoidOne(frc::DoubleSolenoid::Value dir) {
	//solenoid that pulls bolt back, first part of process
	SolenoidOne->Set(dir);
}

void ShooterTShirt::ActuateSolenoidTwo(frc::DoubleSolenoid::Value dir) {
	//solenoid that rotates chamber, second part of process
	SolenoidTwo->Set(dir);
}

void ShooterTShirt::RelayInfo() {
	Spike->Get();
}

void ShooterTShirt::ValveOpen() {
	Spike->Set(frc::Relay::kForward);
}

void ShooterTShirt::ValveClose() {
	Spike->Set(frc::Relay::kReverse);
}

frc::DoubleSolenoid::Value ShooterTShirt::GetSolenoidOneDirection() {
	return SolenoidOne->Get();
}

frc::DoubleSolenoid::Value ShooterTShirt::GetSolenoidTwoDirection() {
	return SolenoidTwo->Get();
}
