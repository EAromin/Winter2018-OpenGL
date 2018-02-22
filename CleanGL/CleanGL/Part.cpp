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
	if (parent != nullptr)
	{
		model_matrix = parent->model_matrix;
		scale_matrix = parent->scale_matrix;
		rotation_matrix = parent->rotation_matrix;
		translation_matrix = parent->translation_matrix;
	}	
}


void Part::addChild(Part * child)
{
	children.push_back(child);
}

void CubicPart::draw()
{
	Cube::set();


	model_matrix *= rotation_matrix;
	model_matrix *= translation_matrix; //this translation is rotated. If you want to give it absolute pos, translate relative to model
	// do an external model_matrix *= glm::translate(glm::mat4(1.0f),(glm::vec3(x,y,z)));

	glUniformMatrix4fv(glGetUniformLocation(*shader, "model"), 1, GL_FALSE, glm::value_ptr(model_matrix));
	glUniform4f(glGetUniformLocation(*shader, "col"), color.r, color.g, color.b,color.a);
	glUniformMatrix4fv(glGetUniformLocation(*shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale_matrix));

	Cube::draw();

	//for (Part* y : children) {
		//y->draw();
	//}
	//std::vector<Part*>::iterator y;
	//for ( y = children.begin(); y != children.end(); ++y) {
	//	(*y)->draw();
//	}
	for (int i = 0; i < children.size(); i++) {
		children[i]->draw();
	}

}
