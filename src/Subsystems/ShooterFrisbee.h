#ifndef ShooterFrisbee_H
#define ShooterFrisbee_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"

class ShooterFrisbee : public Subsystem {
private:
	std::shared_ptr<CANTalon> Motor;
	std::shared_ptr<frc::DoubleSolenoid> Solenoid;
	std::shared_ptr<frc::DigitalInput> Photoeye;

	double ShooterRPM;

public:
	ShooterFrisbee();
	void InitDefaultCommand();
	void SetFlywheelSpeed(double speed);
	void ActuateShooterSolenoid(frc::DoubleSolenoid::Value dir);
	void GetPhotoeye();
};

#endif  // ShooterFrisbee_H
