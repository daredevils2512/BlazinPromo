/* TriggerButton.h
 *
 *  Created on: Feb 11, 2016
 *      Author: troym
 */

#ifndef SRC_TRIGGERBUTTON_H_
#define SRC_TRIGGERBUTTON_H_

#pragma once
#include <Buttons\Button.h>
#include <Joystick.h>

class TriggerButton : public Button
{
private:
	Joystick* stick;
	int axis;
	float threshold;
public:
	TriggerButton(Joystick *joystick, int rawAxis, float pressThreshold):
		stick(joystick), axis(rawAxis), threshold(pressThreshold){}
	bool Get();
};

#endif
