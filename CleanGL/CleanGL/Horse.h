#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include "Bounding_Sphere.h"
#include "Part.h"
#include "Cube.h"
class Bounding_Sphere;

class Horse {
private:
	void debug_anim();
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
    const glm::vec3 LEG_JOINT = glm::vec3(0.0f, -.25f, 0.0f);

	glm::vec3 head_to_neck = glm::vec3(0.0f, -.25f, 0.0f);
	glm::vec3 neck_to_torso = glm::vec3(.0f, -0.325f, 0.0f);
	//from torso
	glm::vec3 torso_to_front_upper_right = LEG_JOINT;
	glm::vec3 torso_to_hind_upper_right = LEG_JOINT;
	glm::vec3 torso_to_front_upper_left = LEG_JOINT;
	glm::vec3 torso_to_hind_upper_left = LEG_JOINT;
	
	glm::vec3 front_right_knee = LEG_JOINT;
	glm::vec3 hind_right_knee = LEG_JOINT;
	glm::vec3 front_left_knee = LEG_JOINT;
	glm::vec3 hind_left_knee = LEG_JOINT;
	//we use this for single press flags
	bool w_press = false;
	bool s_press = false;
	bool a_press = false;
	bool d_press = false;
	bool space_press = false;
	bool upright = false;
	bool run_toggle = false;
public:
	bool is_god = false;
	bool stopped = false;
	int frame;
	void gallop();
	void stop_gallop();
	Bounding_Sphere* touchy_ball;
	glm::mat4 core_model; //anchor

	//parts. vec3 after each one is their respective logs for rotations
	Part* torso ;

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
	glm::vec3 ulhl = glm::vec3(0.0f, 0.0f, 0.0f);

	Part* upper_right_hind_leg;
	glm::vec3 urhl = glm::vec3(0.0f, 0.0f, 0.0f);

	//lower parts
	Part* lower_left_front_leg;
	glm::vec3 llfl = glm::vec3(0.0f, 0.0f, 0.0f);

	Part* lower_right_front_leg;
	glm::vec3 lrfl = glm::vec3(0.0f, 0.0f, 0.0f);
	
	Part* lower_left_hind_leg;
	glm::vec3 llhl = glm::vec3(0.0f, 0.0f, 0.0f);

	Part* lower_right_hind_leg;
	glm::vec3 lrhl = glm::vec3(0.0f, 0.0f, 0.0f);


	glm::vec3 movement_log = glm::vec3(0.0f,0.0f,0.0f);
	glm::mat4 rotation = glm::mat4(1.0f);
	glm::mat4 scale;
	 bool joints[11];
	float horse_size = 1.0f;
	static	GLuint *horse_shader;
	Horse();
	Horse(float x, float y, float z);
	static void set_shader(GLuint &shader);
	void set_model(glm::mat4 &model);
	void draw();
	void ready();
	void horse_controller(GLFWwindow* window);
	void joint_controller(GLFWwindow* window);

	glm::vec3 get_absolute_position();
};