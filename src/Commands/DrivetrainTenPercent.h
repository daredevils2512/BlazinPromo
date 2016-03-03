#ifndef DrivetrainTenPercent_H
#define DrivetrainTenPercent_H

#include "../CommandBase.h"
#include "WPILib.h"

#include "../Robot.h"

class DrivetrainTenPercent: public CommandBase
{
public:
	DrivetrainTenPercent();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
