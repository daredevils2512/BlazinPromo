/*
 * POVButton.h
 *
 *  Created on: Feb 23, 2016
 *      Author: troym
 */

#ifndef SRC_POVBUTTON_H_
#define SRC_POVBUTTON_H_

#pragma once
#include <Buttons\Button.h>
#include <Joystick.h>

class POVButton : public Button
{
private:
	Joystick* stick;
	int axis;

public:
	POVButton(Joystick *joystick, int rawAxis) :
		stick(joystick), axis(rawAxis) {}
	bool Get();
};


#endif /* SRC_POVBUTTON_H_ */
