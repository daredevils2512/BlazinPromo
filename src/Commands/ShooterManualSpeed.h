#ifndef ShooterManualSpeed_H
#define ShooterManualSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

#include "../Robot.h"

class ShooterManualSpeed: public CommandBase
{
public:
	ShooterManualSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
