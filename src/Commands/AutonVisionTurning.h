#ifndef AutonVisionTurning_H
#define AutonVisionTurning_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Nullable.h"
#include "../Robot.h"

class AutonVisionTurning: public CommandBase
{
public:
	AutonVisionTurning();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Nullable<double> target;
	static const int UPPER_LIMIT = 136;
	static const int LOWER_LIMIT = 130;
	bool onTarget = false;
};

#endif
