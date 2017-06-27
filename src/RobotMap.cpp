#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

//access pointer objects declared in RobotMap.h file
std::shared_ptr<CANTalon> RobotMap::drivetrainFrontLeftMotor;
std::shared_ptr<CANTalon> RobotMap::drivetrainRearLeftMotor;
std::shared_ptr<CANTalon> RobotMap::drivetrainFrontRightMotor;
std::shared_ptr<CANTalon> RobotMap::drivetrainRearRightMotor;
std::shared_ptr<frc::RobotDrive> RobotMap::drivetrainchassis;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::drivetrainShift;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::shooterSolenoidOne;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::shooterSolenoidTwo;
std::shared_ptr<frc::Relay> RobotMap::shooterSpike;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::shooterFrisbeeSolenoid;
std::shared_ptr<CANTalon> RobotMap::shooterFrisbeeMotor;
std::shared_ptr<frc::DigitalInput> RobotMap::shooterFrisbeePhotoeye;

//runs on startup of the robot
void RobotMap::init() {
	//assign ports and settings to pointer objects declared in RobotMap.h
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    drivetrainFrontLeftMotor.reset(new CANTalon(0));
    lw->AddActuator("Drivetrain", "FrontLeftMotor", drivetrainFrontLeftMotor);
    
    drivetrainRearLeftMotor.reset(new CANTalon(0));
    lw->AddActuator("Drivetrain", "RearLeftMotor", drivetrainRearLeftMotor);
    
    drivetrainFrontRightMotor.reset(new CANTalon(0));
    lw->AddActuator("Drivetrain", "FrontRightMotor", drivetrainFrontRightMotor);
    
    drivetrainRearRightMotor.reset(new CANTalon(0));
    lw->AddActuator("Drivetrain", "RearRightMotor", drivetrainRearRightMotor);
    
    drivetrainchassis.reset(new frc::RobotDrive(drivetrainFrontLeftMotor, drivetrainRearLeftMotor,
              drivetrainFrontRightMotor, drivetrainRearRightMotor));
    
    drivetrainchassis->SetSafetyEnabled(true);
        drivetrainchassis->SetExpiration(0.5);
        drivetrainchassis->SetSensitivity(0.5);
        drivetrainchassis->SetMaxOutput(1.0);

    drivetrainShift.reset(new frc::DoubleSolenoid(0, 0, 1));

    shooterSolenoidOne.reset(new frc::DoubleSolenoid(0, 0, 1)); //solenoid that pulls bolt back
    shooterSolenoidTwo.reset(new frc::DoubleSolenoid(0, 0, 1)); //solenoid that rotates chamber
    shooterSpike.reset(new frc::Relay(0));

    shooterFrisbeeSolenoid.reset(new frc::DoubleSolenoid(0, 0, 1));
    shooterFrisbeeMotor.reset(new CANTalon(0));
    shooterFrisbeePhotoeye.reset (new frc::DigitalInput(0));
}
