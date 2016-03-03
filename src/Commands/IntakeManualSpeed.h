#ifndef IntakeManualSpeed_H
#define IntakeManualSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

#include "../Robot.h"

class IntakeManualSpeed: public CommandBase
{
public:
	IntakeManualSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
