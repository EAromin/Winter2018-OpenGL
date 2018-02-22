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
	if (parent != nullptr)
	{
		model_matrix = parent->model_matrix;
	}

	model_matrix *= rotation_matrix;
	model_matrix *= translation_matrix;


	glUniformMatrix4fv(glGetUniformLocation(*shader, "model"), 1, GL_FALSE, glm::value_ptr(model_matrix));
	glUniform4f(glGetUniformLocation(*shader, "col"), color.r, color.g, color.b,color.a);
	glUniformMatrix4fv(glGetUniformLocation(*shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale_matrix));

	Cube::draw();

	for (Part* y : children) {
		y->draw();
	}
}
