#ifndef ShooterTShirtActuateSolenoid1_H
#define ShooterTShirtActuateSolenoid1_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterTShirt.h"
#include "Robot.h"

class ShooterTShirtActuateSolenoid1 : public CommandBase {
public:
	ShooterTShirtActuateSolenoid1(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_direction;
};

#endif  // ShooterTShirtActuateSolenoid1_H
