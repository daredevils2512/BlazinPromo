#ifndef SRC_TRIGGERBUTTON_H_
#define SRC_TRIGGERBUTTON_H_

#pragma once
#include <Buttons\Button.h>
#include <Joystick.h>

//class declaration for converting analog trigger (0.0-1.0 or -1.0-0.0) to boolean input
class TriggerButton : public Button
{
private:
	Joystick* stick; // controller
	int axis; // axis number of trigger
	float threshold; // float value between true and false
public:
	TriggerButton(Joystick *joystick, int rawAxis, float pressThreshold):
		stick(joystick), axis(rawAxis), threshold(pressThreshold){}
	bool Get();
};

#endif
