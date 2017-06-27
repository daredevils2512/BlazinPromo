#ifndef ShooterTShirt_H
#define ShooterTShirt_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../RobotMap.h"

class ShooterTShirt : public Subsystem {
private:
	std::shared_ptr<frc::DoubleSolenoid> SolenoidOne;
	std::shared_ptr<frc::DoubleSolenoid> SolenoidTwo;
	std::shared_ptr<frc::Relay> Spike;

public:
	ShooterTShirt();
	void InitDefaultCommand();
	void ActuateSolenoidOne(frc::DoubleSolenoid::Value dir);
	void ActuateSolenoidTwo(frc::DoubleSolenoid::Value dir);
	void RelayInfo();
	void ValveOpen();
	void ValveClose();
	frc::DoubleSolenoid::Value GetSolenoidOneDirection();
	frc::DoubleSolenoid::Value GetSolenoidTwoDirection();

};

#endif  // ShooterTShirt_H
