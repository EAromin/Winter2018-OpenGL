#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Cube.h"

class Horse {
public:
	float horse_size = 1.0f;
	glm::mat4 horse_model;
	GLuint *horse_shader;
	void set_shader(GLuint &shader);
	void set_model(glm::mat4 model);
	void draw();
};