#pragma once

#include "Input.h"



struct Editor : virtual public Input {
	void input() override;
};