#ifndef ShooterFrisbeeRunMotor_H
#define ShooterFrisbeeRunMotor_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterFrisbee.h"
#include "CANTalon.h"
#include "Robot.h"

class ShooterFrisbeeRunMotor : public CommandBase {
public:
	ShooterFrisbeeRunMotor(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_speed;
};

#endif  // ShooterFrisbeeRunMotor_H
