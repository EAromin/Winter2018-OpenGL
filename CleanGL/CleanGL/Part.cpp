#include "stdafx.h"
#include "Part.h"

Part::Part(GLuint & shdr)
{
	shader = &shdr;
}

Part::Part(GLuint & shdr, Part & prnt) //ref to a parent
{
	shader = &shdr;
	parent = &prnt; //point to address of reference
	parent->addChild(this);
}


void Part::addChild(Part * child)
{
	children.push_back(child);
}

void CubicPart::draw()
{
	Cube::set();
	Cube::draw();

	for (Part* y : children) {
		y->draw();
	}
}
