#ifndef AutonVisionTurning_H
#define AutonVisionTurning_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Nullable.h"
#include "../Robot.h"

class AutonVisionTurning: public CommandBase
{
public:
	AutonVisionTurning(bool first);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Nullable<double> target;
	int UPPER_LIMIT;
	int LOWER_LIMIT;
	int direction = 0;
};

#endif
