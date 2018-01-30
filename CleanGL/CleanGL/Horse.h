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

	bool w_press = false;
	bool s_press = false;
	bool a_press = false;
	bool d_press = false;

	glm::vec3 movement_log = glm::vec3(0.0f,0.0f,0.0f);
	glm::mat4 rotation = glm::mat4(1.0f);
	float horse_size = 1.0f;
	glm::mat4 *horse_model;
	GLuint *horse_shader;
	void set_shader(GLuint &shader);
	void set_model(glm::mat4 &model);
	void draw();
	void horse_controller(GLFWwindow* window);
};