
#ifndef _ROBOT_H
#define _ROBOT_H

#include "Commands/_CMG_AutonomousWithShooting.h"
#include "Commands/_CMG_AutonomousDriveForward.h"
#include "Commands/_CMG_AutonomousDoNothing.h"
#include "Commands/_CMG_AutonomousWithVision.h"
#include "Subsystems/CompressorSubsystem.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/VisionTracking.h"
#include "OI.h"

//class declaration of the robot
class Robot : public IterativeRobot {
public:
	//pointer object declaration for subsystems, autonomous and chooser, oi, and live window
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	std::shared_ptr<SendableChooser> chooser;
    static std::shared_ptr<Drivetrain> drivetrain;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Intake> intake;
    static std::shared_ptr<Climber> climber;
    static std::shared_ptr<VisionTracking> visionTracking;
    static std::shared_ptr<CompressorSubsystem> compressor;

    //declaration of robot class functions
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	//true if using the autonomous chooser
	bool useChooser;
};
#endif
