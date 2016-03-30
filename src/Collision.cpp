#include "Collision.h"

void Collision::nullify()
{
	Transform::nullify();
	type = coll_type::none;
}
