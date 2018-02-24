#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Part.h"
#include "Cube.h"

class Horse {
private:
	void set_core();

	void set_neck();
	void set_head();

	void set_upper_left_front_leg();
	void set_upper_right_front_leg();

	void set_upper_left_hind_leg();
	void set_upper_right_hind_leg();

	void set_lower_left_front_leg();
	void set_lower_right_front_leg();

	void set_lower_left_hind_leg();
	void set_lower_right_hind_leg();
	//joints
	glm::vec3 head_to_neck = glm::vec3(0.0f, -.25f, 0.0f);
	glm::vec3 neck_to_torso = glm::vec3(.0f, -0.325f, 0.0f);
	glm::vec3 torso_to_front_upper_right = glm::vec3(0.0f, -.25f, 0.0f);
	glm::vec3 front_right_knee = glm::vec3(0.0f, -.25f, 0.0f);
	//glm::vec3 torso_to_hind_upper_right = glm::vec3(0.0f, -.25f, 0.0f);
	//glm::vec3 hind_right_knee = glm::vec3(0.0f, -.25f, 0.0f);
	glm::vec3 torso_to_front_upper_left = glm::vec3(0.0f, -.25f, 0.0f);
	glm::vec3 front_left_knee = glm::vec3(0.0f, -.25f, 0.0f);
	//we use this for single press flags
	bool w_press = false;
	bool s_press = false;
	bool a_press = false;
	bool d_press = false;
	bool space_press = false;
public:


	//horse part models
	glm::mat4 core_model; //anchor

	glm::mat4 neck_model;
	glm::mat4 head_model;

	//upper parts
	glm::mat4 upper_left_front_leg_model;
	glm::mat4 upper_right_front_leg_model;

	glm::mat4 upper_left_hind_leg_model;
	glm::mat4 upper_right_hind_leg_model;

	//lower parts
	glm::mat4 lower_left_front_leg_model;
	glm::mat4 lower_right_front_leg_model;

	glm::mat4 lower_left_hind_leg_model;
	glm::mat4 lower_right_hind_leg_model;

	//remove upper part once done with making parts
	Part* torso;

	Part* neck;
	glm::vec3 neckrot = glm::vec3(0.0f,0.0f, 0.0f);
	Part* head;
	glm::vec3 headrot = glm::vec3(0.0f, 0.0f, 0.0f);
	//upper parts
	Part* upper_left_front_leg;
	glm::vec3 ulfl = glm::vec3(0.0f, 0.0f, 0.0f);
	Part* upper_right_front_leg;
	glm::vec3 urfl = glm::vec3(0.0f, 0.0f, 0.0f);
	Part* upper_left_hind_leg;
	Part* upper_right_hind_leg;

	//lower parts
	Part* lower_left_front_leg;
	glm::vec3 llfl = glm::vec3(0.0f, 0.0f, 0.0f);
	Part* lower_right_front_leg;
	glm::vec3 lrfl = glm::vec3(0.0f, 0.0f, 0.0f);
	Part* lower_left_hind_leg;
	Part* lower_right_hind_leg;
	

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