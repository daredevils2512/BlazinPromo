#ifndef ShooterTShirtActuateSolenoid2_H
#define ShooterTShirtActuateSolenoid2_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterTShirt.h"
#include "Robot.h"

class ShooterTShirtActuateSolenoid2 : public CommandBase {
public:
	ShooterTShirtActuateSolenoid2(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_direction;
};

#endif  // ShooterTShirtActuateSolenoid2_H
