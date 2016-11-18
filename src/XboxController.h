/*
 * XboxController.h
 *
 *  Created on: Feb 23, 2016
 *      Author: Daredevils
 */

#ifndef SRC_XBOXCONTROLLER_H_
#define SRC_XBOXCONTROLLER_H_

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include "TriggerButton.h"

//class declaration for xbox controller joystick
class XboxController : public Joystick  {
private:
	//declaration of buttons and triggers on the xbox controller
	JoystickButton aButton{this, 1};
	JoystickButton bbButton{this, 2};
	JoystickButton xButton{this, 3};
	JoystickButton yButton{this, 4};
	JoystickButton leftBumper{this, 5};
	JoystickButton rightBumper{this, 6};
	JoystickButton backButton{this, 7};
	JoystickButton startButton{this, 8};
	JoystickButton leftStickButton{this, 9};
	JoystickButton rightStickButton{this, 10};
	TriggerButton  leftTriggerButton{this, 3, 0.8};
	TriggerButton  rightTriggerButton{this, 3, -0.8};


public:
	//constructor that takes usb port input
	XboxController(uint32_t port);
	virtual ~XboxController();
	//functions that get values of buttons and triggers on the xbox controller
	float GetRightStickX() const;
	float GetRightStickY() const;
	JoystickButton GetAButton();


};

#endif
