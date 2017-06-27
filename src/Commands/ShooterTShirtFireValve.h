#ifndef ShooterTShirtFireValve_H
#define ShooterTShirtFireValve_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterTShirt.h"
#include "Robot.h"

class ShooterTShirtFireValve : public CommandBase {
public:
	ShooterTShirtFireValve(bool active);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_active;
};

#endif  // ShooterTShirtFireValve_H
