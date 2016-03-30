#pragma once
#include "Object.h"



enum class direction {
	none,
	right,
	up,
	left,
};





struct Player : virtual public Object {



	// VARIABLES
	Transform trans_update; // trans change per second

	double      speed    = 5.;
	direction   move_dir = direction::none;
	double     gravity   = 9.81;





	// FUNCTIONS
	Player();
	virtual ~Player() {}

	void    input() override;
	void    update() override;
	void    render(Transform offset) const override;
};