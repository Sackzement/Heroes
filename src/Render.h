#pragma once
struct Transform;

struct Render {
	virtual ~Render() {}
	virtual void render(Transform offset) const = 0;
};
