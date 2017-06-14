#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:
	//4 speed controllers for the drivetrain
	static std::shared_ptr<CANTalon> drivetrainFrontLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainRearLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainFrontRightMotor;
	static std::shared_ptr<CANTalon> drivetrainRearRightMotor;
	//robot drivetrain
	static std::shared_ptr<frc::RobotDrive> drivetrainchassis;
	//encoder inputs on drivetrain to track distance
	static std::shared_ptr<frc::Encoder> drivetrainLeftEncoder;
	static std::shared_ptr<frc::Encoder> drivetrainRightEncoder;

	static std::shared_ptr<frc::DoubleSolenoid> drivetrainShift;

	static std::shared_ptr<frc::DoubleSolenoid> shooterSolenoidOne;
	static std::shared_ptr<frc::DoubleSolenoid> shooterSolenoidTwo;
	static std::shared_ptr<frc::Relay> shooterSpike;

	static std::shared_ptr<frc::DoubleSolenoid> shooterFrisbeeSolenoid;
	static std::shared_ptr<CANTalon> shooterFrisbeeMotor;
	static std::shared_ptr<frc::DigitalInput> shooterFrisbeePhotoeye;

	static void init();
};

#endif
