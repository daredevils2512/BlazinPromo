#include "XboxController.h"

XboxController::XboxController(uint32_t port) : Joystick(port) {


}

XboxController::~XboxController() {

}

float XboxController::GetRightStickX() const {
	return GetRawAxis(4);
}

float XboxController::GetRightStickY() const {
	return GetRawAxis(5);
}
JoystickButton XboxController::GetAButton() {
	return aButton;
}



