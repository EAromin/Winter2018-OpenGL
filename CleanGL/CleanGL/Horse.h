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
	void draw_core();

	void draw_neck();
	void draw_head();

	void draw_upper_left_front_leg();
	void draw_upper_right_front_leg();

	void draw_upper_left_hind_leg();
	void draw_upper_right_hind_leg();

	void draw_lower_left_front_leg();
	void draw_lower_right_front_leg();

	void draw_lower_left_hind_leg();
	void draw_lower_right_hind_leg();

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

	Part* neck = &CubicPart::CubicPart();
	Part* head = &CubicPart::CubicPart();

	//upper parts
	Part* upper_left_front_leg= &CubicPart::CubicPart();
	Part* upper_right_front_leg= &CubicPart::CubicPart();
	Part* upper_left_hind_leg= &CubicPart::CubicPart();
	Part* upper_right_hind_leg= &CubicPart::CubicPart();

	//lower parts
	Part* lower_left_front_leg= &CubicPart::CubicPart();
	Part* lower_right_front_leg= &CubicPart::CubicPart();
	Part* lower_left_hind_leg= &CubicPart::CubicPart();
	Part* lower_right_hind_leg= &CubicPart::CubicPart();
	

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