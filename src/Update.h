#pragma once

struct Update {
	virtual ~Update() {}
	virtual void update () =0;
};
