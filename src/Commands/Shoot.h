#ifndef Shoot_H
#define Shoot_H

#include "../CommandBase.h"

class Shoot : public CommandBase {
public:
	Shoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	void ShootTShirt();
};

#endif  // Shoot_H
