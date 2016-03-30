#pragma once


struct Size2i{

	int w, h;

	Size2i();
	Size2i(int w, int h);

	void set(int w, int h);
	void nullify();

};