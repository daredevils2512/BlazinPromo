#ifndef ShooterFrisbee_H
#define ShooterFrisbee_H

#include <Commands/Subsystem.h>

class ShooterFrisbee : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	ShooterFrisbee();
	void InitDefaultCommand();
};

#endif  // ShooterFrisbee_H
