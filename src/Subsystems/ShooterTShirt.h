#ifndef ShooterTShirt_H
#define ShooterTShirt_H

#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "../RobotMap.h"

class ShooterTShirt : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<frc::DoubleSolenoid> shooterSolenoidOne;
	std::shared_ptr<frc::DoubleSolenoid> shooterSolenoidTwo;
	std::shared_ptr<frc::Relay> shooterSpike;



public:
	ShooterTShirt();
	void InitDefaultCommand();
	void ActuateSolenoidOne(frc::DoubleSolenoid::Value dir);
	void ActuateSolenoidTwo(frc::DoubleSolenoid::Value dir);
	void RelayInfo();


};

#endif  // ShooterTShirt_H
