#pragma once
#include "Object.h"





struct Player : virtual public Object {
	double speed = 5.;
	virtual ~Player() {}
	void update() override;
};