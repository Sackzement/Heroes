#pragma once

#include "Scene.h"
#include "TextureInfo.h"




struct TextureOptions : virtual public Object
{
	TextureOptions();
	~TextureOptions() {}

	bool load()  override;
	void input() override;
	void render(Transform offset) const override;


	vector<TextureInfo> texinfos;
};




struct LevelEditor : virtual public Scene
{ 
	TextureOptions texops;


	LevelEditor();
	virtual ~LevelEditor() {}






	bool load() override;
	void unload() override;

	void input() override;
	void update() override;
	void render(Transform offset) const override;



	// selection
	vector<Transform*> selection;
};

