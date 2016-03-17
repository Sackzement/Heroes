#pragma once

#include "Transform.h"
#include "Load.h"
#include "Input.h"
#include "Update.h"
#include "Render.h"
#include <vector>
using std::vector;




struct Object : virtual public Transform, virtual public Load, virtual public Input, virtual public Update, virtual public Render  {

	Object();

	vector<Load*>  loads;
	vector<Input*>  inputs;
	vector<Update*> updates;
	vector<Render*> renders;



	bool load() override;
	void unload() override;

	void input() override;
	void update() override;
    void render(Transform offset) const override;

	void addChild(Object * ch);
	void addChild(Load   * lo);
	void addChild(Input  * in);
	void addChild(Update * up);
	void addChild(Render * re);

	void addLoad  (Load   * lo);
	void addInput (Input  * in);
	void addUpdate(Update * up);
	void addRender(Render * re);

protected:
	bool loadChildren(); 
	void unloadChildren();
	void inputChildren();
	void updateChildren();
	void renderChildren(Transform offset) const;
};