#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:
	//4 speed controllers for the drivetrain
	static std::shared_ptr<CANTalon> drivetrainFrontLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainRearLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainFrontRightMotor;
	static std::shared_ptr<CANTalon> drivetrainRearRightMotor;
	//robot drivetrain
	static std::shared_ptr<RobotDrive> drivetrainchassis;
	//encoder inputs on drivetrain to track distance
	static std::shared_ptr<Encoder> drivetrainLeftEncoder;
	static std::shared_ptr<Encoder> drivetrainRightEncoder;
	//pneumatic actuator to raise and lower shooter
	static std::shared_ptr<DoubleSolenoid> shooterSolenoid;
	//speed controller to run shooter wheels
	static std::shared_ptr<CANTalon> shooterMotor;
	//boolean sensor input that detects if the ball is in the shooter or not
	static std::shared_ptr<DigitalInput> shooterPhotoeye;
	//pneumatic actuator to raise and lower the intake
	static std::shared_ptr<DoubleSolenoid> intakeSolenoid;
	//speed controler to run intake roller
	static std::shared_ptr<CANTalon> intakeMotor;
	//speed controller to run scissor lift for climbing hook
	static std::shared_ptr<CANTalon> climberHookMotor;
	//speed controllers to run winches that raise the robot
	static std::shared_ptr<CANTalon> climberLeftWinchMotor;
	static std::shared_ptr<CANTalon> climberRightWinchMotor;
	//encoder input that measures distance the winch runs
	static std::shared_ptr<Encoder> climberHookEncoder;
	//compressor switch and sensor to regulate compressor when it is connected
	static std::shared_ptr<Relay> compressorSpike;
	static std::shared_ptr<DigitalInput> compressorPressureSwitch;

	static void init();
};

#endif
