#ifndef ShooterFrisbeeActuate_H
#define ShooterFrisbeeActuate_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterFrisbee.h"
#include "Robot.h"

class ShooterFrisbeeActuate : public CommandBase {
public:
	ShooterFrisbeeActuate(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_direction;
};

#endif  // ShooterFrisbeeActuate_H
