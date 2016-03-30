#pragma once

#include "Transform.h"




enum class coll_type {
	none,
	touch,
	intersect,
};



struct Collision : virtual public Transform {

	coll_type type = coll_type::none;

	void nullify() override;
};