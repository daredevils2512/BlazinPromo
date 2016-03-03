/*
 * POVButton.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: troym
 */
#include "POVButton.h"


bool POVButton::Get() {
	if(stick->GetPOV(axis) == -1) {
		return false;
	}else{
		return true;
	}
}
