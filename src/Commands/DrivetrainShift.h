#ifndef DrivetrainShift_H
#define DrivetrainShift_H

#include "../CommandBase.h"

class DrivetrainShift : public CommandBase {
private:
	bool direction;
public:
	DrivetrainShift(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivetrainShift_H
