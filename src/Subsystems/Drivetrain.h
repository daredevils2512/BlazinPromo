#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Drivetrain: public Subsystem {
private:
	std::shared_ptr<CANTalon> frontLeftMotor;
	std::shared_ptr<CANTalon> rearLeftMotor;
	std::shared_ptr<CANTalon> frontRightMotor;
	std::shared_ptr<CANTalon> rearRightMotor;
	std::shared_ptr<RobotDrive> chassis;
	std::shared_ptr<DoubleSolenoid> shift;

	bool blockJoysticks;
public:
	Drivetrain();
	void InitDefaultCommand();
	void DriveRobot(double move, double turn);
	void AutonTankDrive(double left, double right);
	void SetAutonomous(bool isAutonomous);
	bool GetAutonomous();
	void Shift(frc::DoubleSolenoid::Value direction);

};

#endif
