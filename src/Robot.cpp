// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<VisionTracking> Robot::visionTracking;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<CompressorSubsystem> Robot::compressor;
//std::shared_ptr<Compressor> Robot::otherCompressor;
void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drivetrain.reset(new Drivetrain());
    shooter.reset(new Shooter());
    intake.reset(new Intake());
    climber.reset(new Climber());
    visionTracking.reset(new VisionTracking());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    compressor.reset(new CompressorSubsystem());
    //otherCompressor.reset(new Compressor());
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	chooser.reset(new SendableChooser());
	chooser->AddDefault("Auto Do Nothing", new _CMG_AutonomousDoNothing());
	chooser->AddObject("Auto Drive into Courtyard", new _CMG_AutonomousDriveForward());
	chooser->AddObject("Auto Low Bar No Shooting", new _CMG_AutonomousWithShooting(false));
	chooser->AddObject("Auto Low Bar with Shooting", new _CMG_AutonomousWithShooting(true));
	SmartDashboard::PutData("Autonomous Modes", chooser.get());
	// instantiate the command used for the autonomous period
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	//change camera settings to dark for autonomous vision tracking
	Robot::visionTracking->cameraAuton();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutBoolean("Ball in", RobotMap::shooterPhotoeye->Get());
	if(Robot::oi->GetThrottle() > 0.0) {
		useChooser = true;
	}else{
		useChooser = false;
	}
	SmartDashboard::PutBoolean("Using Chooser", useChooser);
}

void Robot::AutonomousInit() {	//start autonomous
	if(useChooser) {
		autonomousCommand.reset((Command *) chooser->GetSelected());
	}else{
		autonomousCommand.reset(new _CMG_AutonomousWithShooting(true));
	}
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();	//change camera settings to dark for autonomous vision tracking
	Robot::visionTracking->cameraAuton();
	//resets drivetrain encoders
	Robot::drivetrain->ResetEncoders();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	//set camera settings to regular for teleop
	Robot::visionTracking->cameraTeleop();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//print encoders and photoeye to smartdashboard
	SmartDashboard::PutNumber("climber encoder", RobotMap::climberHookEncoder->GetRaw());
	SmartDashboard::PutNumber("left encoder", RobotMap::drivetrainLeftEncoder->GetDistance());
	SmartDashboard::PutNumber("right encoder", RobotMap::drivetrainRightEncoder->GetDistance());
	SmartDashboard::PutBoolean("Ball in", RobotMap::shooterPhotoeye->Get());
	SmartDashboard::PutNumber("Joystick POV", Robot::oi->GetJoystickPOV());
	SmartDashboard::PutBoolean("POV forward", Robot::oi->POVForward());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

