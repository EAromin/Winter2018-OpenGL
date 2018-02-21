#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Cube.h"

// For hierarchical modeling
class Part {
private:
protected:
	//One-to-many Parent-to-child relationship
	Part* parent;
	std::vector<Part*> children;

public:

	//for the transformations
	glm::mat4 model_matrix;
	glm::mat4 scale;
	glm::mat4 rotation_matrix;
	glm::mat4 translation_matrix;

	//joint's position relative to the current part
	glm::vec3 joint_loc;

	GLuint *shader;


	Part() {}; //default
	Part(GLuint &shdr);//will be used for parent to set shader
	Part(GLuint &shdr, Part &prnt);//for child

	virtual void draw() {}; //draw it and make it call the children recursively
	void addChild( Part *child);
};

class CubicPart : virtual public Part {
public:
	//constructos
	CubicPart() :Part() {};
	CubicPart(GLuint &shdr, Part &prnt) :Part(shdr, prnt) {};
	CubicPart(GLuint &shdr) :Part(shdr) {};

	//draw
	void draw();
};