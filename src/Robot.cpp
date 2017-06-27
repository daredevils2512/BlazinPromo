#include "Robot.h"

//access pointer objects delcared in Robot.h
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterTShirt> Robot::shootertshirt;
std::shared_ptr<ShooterFrisbee> Robot::shooterfrisbee;
std::shared_ptr<frc::Compressor> Robot::compressor;
std::unique_ptr<OI> Robot::oi;


void Robot::RobotInit() {
	RobotMap::init();
	//start subsystems
    drivetrain.reset(new Drivetrain());
    shootertshirt.reset(new ShooterTShirt());
    shooterfrisbee.reset(new ShooterFrisbee());
    compressor.reset(new frc::Compressor());
    //starts operator interface
	oi.reset(new OI());

  }

void Robot::DisabledInit(){
	compressor->SetClosedLoopControl(false);
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	//the joystick throttle

	//puts if we are using the chooser or not on the smartdashboard
	frc::SmartDashboard::PutBoolean("Using Chooser", useChooser);
}

void Robot::AutonomousInit() {	//start autonomous
	Robot::drivetrain->SetAutonomous(true);

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//stops autonomous command
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	Robot::drivetrain->SetAutonomous(false);
	compressor->SetClosedLoopControl(true);
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	//print information to smartdashboard
	frc::SmartDashboard::PutBoolean("nos status" , Robot::oi->DriveNosKick());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

