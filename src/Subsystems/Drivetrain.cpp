#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
    frontLeftMotor = RobotMap::drivetrainFrontLeftMotor;
    rearLeftMotor = RobotMap::drivetrainRearLeftMotor;
    frontRightMotor = RobotMap::drivetrainFrontRightMotor;
    rearRightMotor = RobotMap::drivetrainRearRightMotor;
    chassis = RobotMap::drivetrainchassis;
    shift = RobotMap::drivetrainShift;

    blockJoysticks = false;
}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

void Drivetrain::DriveRobot(double move, double turn) {
	//drives robot in arcade mode using specified values
	chassis->ArcadeDrive(move, turn, false);
}

void Drivetrain::AutonTankDrive(double left, double right) {
	//drives robot in tank mode using specified values
	chassis->TankDrive(left, right);
}

void Drivetrain::SetAutonomous(bool isAutonomous) {
	blockJoysticks = isAutonomous;
}

bool Drivetrain::GetAutonomous() {
	return blockJoysticks;
}

void Drivetrain::Shift(frc::DoubleSolenoid::Value direction){
	shift->Set(direction);
}

