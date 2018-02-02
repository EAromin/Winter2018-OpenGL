#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Cube.h"

class Horse {
private:
	void draw_torso();

	void draw_neck();
	void draw_head();

	void draw_upper_left_arm();
	void draw_upper_right_arm();

	void draw_upper_left_leg();
	void draw_upper_right_leg();

	void draw_lower_left_arm();
	void draw_lower_right_arm();

	void draw_lower_left_leg();
	void draw_lower_right_leg();
public:
	//we use this for single press flags
	bool w_press = false;
	bool s_press = false;
	bool a_press = false;
	bool d_press = false;
	bool space_press = false;

	//horse part models
	glm::mat4 torso_model; //anchor

	glm::mat4 neck_model;
	glm::mat4 head_model;

	//upper parts
	glm::mat4 upper_left_arm_model;
	glm::mat4 upper_right_arm_model;

	glm::mat4 upper_left_leg_model;
	glm::mat4 upper_right_leg_model;

	//lower parts
	glm::mat4 lower_left_arm_model;
	glm::mat4 lower_right_arm_model;

	glm::mat4 lower_left_leg_model;
	glm::mat4 lower_right_leg_model;


	glm::vec3 movement_log = glm::vec3(0.0f,0.0f,0.0f);
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 scale;

	float horse_size = 1.0f;
	GLuint *horse_shader;
	void set_shader(GLuint &shader);
	void set_model(glm::mat4 &model);
	void draw();
	void horse_controller(GLFWwindow* window);
};