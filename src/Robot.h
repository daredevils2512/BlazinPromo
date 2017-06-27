#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/ShooterTShirt.h"
#include"Subsystems/ShooterFrisbee.h"
#include "OI.h"


//class declaration of the robot
class Robot : public IterativeRobot {
public:
	//pointer object declaration for subsystems, autonomous and chooser, oi, and live window
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
    static std::shared_ptr<Drivetrain> drivetrain;
    static std::shared_ptr<ShooterTShirt> shootertshirt;
    static std::shared_ptr<ShooterFrisbee> shooterfrisbee;
    static std::shared_ptr<frc::Compressor> compressor;

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
