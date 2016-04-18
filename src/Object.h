#pragma once

#include "Transform.h"
#include "Load.h"
#include "Input.h"
#include "Update.h"
#include "Render.h"

#include <vector>
using std::vector;



namespace obj_type {

	static Uint8 const 
		none = 0,
		transform = 1,
		load = 2,
		input = 4,
		update = 8,
		render = 16;
}








struct Object : 
	virtual public Transform, 
	virtual public Load, 
	virtual public Input, 
	virtual public Update, 
	virtual public Render  {






	Object();
	virtual ~Object() {}

protected:
	Uint8 m_type;
	vector<Load*>  loads;
	vector<Input*>  inputs;
	vector<Update*> updates;
	vector<Transform*> renders;





	// functions
public:
	Uint8 type() const;
	void addType(Uint8 new_type);

	bool load() override;
	void unload() override;

	void input() override;
	void update() override;
    void render(Transform offset) const override;

	bool addObject(Object * obj);

	void addLoad  (Load   * lo);
	void addInput (Input  * in);
	void addUpdate(Update * up);
	void addRender(Transform * re);


protected:

	bool loadChildren(); 
	void unloadChildren();
	void inputChildren();
	void updateChildren();
	void renderChildren(Transform offset) const;
};



