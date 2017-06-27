#include "Drive.h"

Drive::Drive(): Command() {
	Requires(Robot::drivetrain.get());
}

void Drive::Initialize() {

}

void Drive::Execute() {
	if(!Robot::drivetrain->GetAutonomous()) {
		Robot::drivetrain->DriveRobot(Robot::oi->GetDriveMove(), Robot::oi->GetDriveTurn());
	}
}

bool Drive::IsFinished() {
    return false;
}

void Drive::End() {

}

void Drive::Interrupted() {

}
