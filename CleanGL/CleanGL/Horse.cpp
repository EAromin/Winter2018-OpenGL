#include "stdafx.h"
#include "Horse.h"
#include "Bounding_Sphere.h"
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <iostream>
#include <string>
#define HORSE_ROTATION_LEVEL  5.0f
GLuint *Horse::horse_shader = nullptr;
Horse::Horse() {
	joints[11] = { false };
	touchy_ball = nullptr;
	stopped = false;
	speed = rand() % 10 +1;
}
Horse::Horse(float x, float y, float z) {
	joints[11] = { false };
	movement_log = glm::vec3(x, y, z);
	touchy_ball = nullptr;
	stopped = false;
	speed = rand() % 10 +1;
}

void Horse::set_shader(GLuint & shader)
{
	horse_shader = &shader;
}

void Horse::set_model(glm::mat4 &model)
{
	core_model = model;

}
void Horse::ready() {

}
void Horse::draw()
{
	//glUseProgram(*horse_shader);

	Cube::set(); //unit to draw


	ready();
	torso = &CubicPart::CubicPart(*horse_shader);
	set_core();

	neck = &CubicPart::CubicPart(*horse_shader, *torso);
	set_neck();

	head = &CubicPart::CubicPart(*horse_shader, *neck);
	set_head();

	//uppers
	upper_right_front_leg = &CubicPart::CubicPart(*horse_shader, *torso);
	set_upper_right_front_leg();
	upper_right_hind_leg = &CubicPart::CubicPart(*horse_shader, *torso);
	set_upper_right_hind_leg();

	upper_left_front_leg = &CubicPart::CubicPart(*horse_shader, *torso);
	set_upper_left_front_leg();
	upper_left_hind_leg = &CubicPart::CubicPart(*horse_shader, *torso);
	set_upper_left_hind_leg();
	//lowers
	lower_left_front_leg = &CubicPart::CubicPart(*horse_shader, *upper_left_front_leg);
	set_lower_left_front_leg();
	lower_right_hind_leg = &CubicPart::CubicPart(*horse_shader, *upper_right_hind_leg);
	set_lower_right_hind_leg();
	lower_right_front_leg = &CubicPart::CubicPart(*horse_shader, *upper_right_front_leg);
	set_lower_right_front_leg();
	lower_left_hind_leg = &CubicPart::CubicPart(*horse_shader, *upper_left_hind_leg);
	set_lower_left_hind_leg();
	if (Cube::tex_toggle) {
		torso->color = glm::vec4(1.0f);
		upper_left_hind_leg->color = glm::vec4(1.0f);
		upper_right_hind_leg->color = glm::vec4(1.0f);
		upper_left_front_leg->color = glm::vec4(1.0f);
		upper_right_front_leg->color = glm::vec4(1.0f);
		lower_left_hind_leg->color = glm::vec4(1.0f);
		lower_right_hind_leg->color = glm::vec4(1.0f);
		lower_left_front_leg->color = glm::vec4(1.0f);
		lower_right_front_leg->color = glm::vec4(1.0f);
		neck->color = glm::vec4(1.0f);
		head->color = glm::vec4(1.0f);

	}


	torso->draw();
	if (run_toggle)
		gallop();
	else
		stop_gallop();

	if (touchy_ball != nullptr)
		touchy_ball->location = get_absolute_position();
}
void Horse::stop_gallop() {
	if (upright)
	{
		rotation = glm::translate(rotation, movement_log + glm::vec3(0.f, 1.3f, 0));
		rotation *= glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.f, 1.3f, 0)));

		neckrot.y = 0;
		headrot.y = 0;
		ulfl.y = 0;
		urfl.y = 0;
		ulhl.y = 0;
		urhl.y = 0;
		llfl.y = 0;
		lrfl.y = 0;
		llhl.y = 0;
		lrhl.y = 0;
		upright = false;
	}
}

void Horse::gallop() {
	if (!upright) {
		rotation = glm::translate(rotation, movement_log + glm::vec3(0.f, 1.3f, 0));
		rotation *= glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.f, 1.3f, 0)));

		upright = true;

	}
	frame = ((int)(glfwGetTime() * 15)) % 10;
	switch (frame) {

	case 1: {

		neckrot.y = 45;
		headrot.y = 0;
		ulfl.y = 65;
		urfl.y = 100;
		ulhl.y = 95;
		urhl.y = 70;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 15;
		lrhl.y = 5;


	}
			break;
	case 2: {

		neckrot.y = 45;
		headrot.y = 0;
		ulfl.y = 60;
		urfl.y = 105;
		ulhl.y = 100;
		urhl.y = 65;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 15;
		lrhl.y = 5;
	}			break;

	case 3: {

		neckrot.y = 45;
		headrot.y = -15;
		ulfl.y = 55;
		urfl.y = 110;
		ulhl.y = 105;
		urhl.y = 60;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 15;
		lrhl.y = 5;
	}			break;

	case 4: {

		neckrot.y = 55;
		headrot.y = 0;
		ulfl.y = 60;
		urfl.y = 105;
		ulhl.y = 100;
		urhl.y = 65;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 20;
		lrhl.y = 5;
	}			break;

	case 5: {

		neckrot.y = 65;
		headrot.y = 5;
		ulfl.y = 70;
		urfl.y = 95;
		ulhl.y = 90;
		urhl.y = 75;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 20;
		lrhl.y = 5;
	}			break;

	case 6: {

		neckrot.y = 60;
		headrot.y = -10;
		ulfl.y = 80;
		urfl.y = 85;
		ulhl.y = 80;
		urhl.y = 85;
		llfl.y = -15;
		lrfl.y = -25;
		llhl.y = 25;
		lrhl.y = 5;
	}			break;

	case 7: {

		neckrot.y = 50;
		headrot.y = -35;
		ulfl.y = 90;
		urfl.y = 75;
		ulhl.y = 70;
		urhl.y = 95;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 5;
		lrhl.y = 5;
	}			break;

	case 8: {

		neckrot.y = 55;
		headrot.y = -15;
		ulfl.y = 80;
		urfl.y = 85;
		ulhl.y = 80;
		urhl.y = 85;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 5;
		lrhl.y = 5;
	}			break;

	case 9: {

		neckrot.y = 70;
		headrot.y = 0;
		ulfl.y = 75;
		urfl.y = 105;
		ulhl.y = 95;
		urhl.y = 80;
		llfl.y = -15;
		lrfl.y = -20;
		llhl.y = 10;
		lrhl.y = 5;
	}			break;

		std::cout << frame << std::endl;
	}
}
void Horse::horse_controller(GLFWwindow* window)
{
	//move forward
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS))
	{
		w_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE))
	{
		if (w_press) {
			movement_log.x--;

			std::cout << "(" << std::to_string(get_absolute_position().x) << ", " << std::to_string(get_absolute_position().y) << ", " << std::to_string(get_absolute_position().z) << ")" << std::endl;

		}
		w_press = false;
	}
	//move backward
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS))
	{
		s_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE))
	{
		if (s_press) {
			movement_log.x++;
		}
		s_press = false;
	}
	//move left
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
	{
		a_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE))
	{
		if (a_press) {
			movement_log.z++;
		}
		a_press = false;
	}
	//move right
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
	{
		d_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE))
	{
		if (d_press) {
			movement_log.z--;
		}
		d_press = false;
	}

	//rotate left

	if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
	{
		a_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE))
	{
		if (a_press) {
			rotation = glm::translate(rotation, movement_log);
			rotation = glm::rotate(rotation, glm::radians(HORSE_ROTATION_LEVEL), glm::vec3(0.0f, 1.0f, 0.0f));
			rotation = glm::translate(rotation, -movement_log);

		}
		a_press = false;
	}

	//rotate right
	if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
	{
		d_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE))
	{
		if (d_press) {
			rotation = glm::translate(rotation, movement_log);
			rotation = glm::rotate(rotation, glm::radians(-HORSE_ROTATION_LEVEL), glm::vec3(0.0f, 1.0f, 0.0f));
			rotation = glm::translate(rotation, -movement_log);
		}
		d_press = false;
	}

	//tilt up
	if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS))
	{
		w_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE))
	{
		if (w_press) {
			rotation = glm::translate(rotation, (movement_log + glm::vec3(0.0f, 1.1f, 0.0f)));
			rotation = glm::rotate(rotation, glm::radians(-HORSE_ROTATION_LEVEL), glm::vec3(0.0f, 0.0f, 1.0f));
			rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.0f, 1.1f, 0.0f)));
		}
		w_press = false;
	}
	//tilt down

	if ((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS))
	{
		s_press = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE))
	{
		if (s_press) {
			rotation = glm::translate(rotation, (movement_log + glm::vec3(0.0f, 1.1f, 0.0f)));
			rotation = glm::rotate(rotation, glm::radians(HORSE_ROTATION_LEVEL), glm::vec3(0.0f, 0.0f, 1.0f));
			rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.0f, 1.1f, 0.0f)));
		}
		s_press = false;
	}
	//teleport

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		space_press = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
	{
		if (space_press) {
			//teleport
			//reset rot
			int randx = rand() % 99 - 49;
			int randz = rand() % 99 - 49;
			rotation = glm::mat4(1.0f);
			movement_log = glm::vec3(randx + 0.0f, 0.0f, randz + 0.0f);
		}
		space_press = false;
	}
	//scale up
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
		horse_size += 0.01f;
	}
	//scale down
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
		horse_size -= 0.01f;

	}
	//FOR DA JOINTS
	joint_controller(window);

}

void Horse::joint_controller(GLFWwindow * window)
{
	if ((glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS))
	{
		debug_anim();
	}
	if ((glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS))
	{
		joints[10] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE))
	{
		if (joints[10]) {
			if (run_toggle)
				run_toggle = false;
			else
				run_toggle = true;
		}
		joints[10] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS))
	{
		std::cout << "(" << movement_log.x << ", " << movement_log.z << ")" << std::endl;
	}

	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS))
	{
		joints[0] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_0) == GLFW_RELEASE))
	{
		if (joints[0]) {
			headrot.y -= HORSE_ROTATION_LEVEL;
		}
		joints[0] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS))
	{
		joints[0] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_0) == GLFW_RELEASE))
	{
		if (joints[0]) {
			headrot.y += HORSE_ROTATION_LEVEL;
		}
		joints[0] = false;
	}

	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS))
	{
		joints[1] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE))
	{
		if (joints[1]) {
			neckrot.y -= HORSE_ROTATION_LEVEL;
		}
		joints[1] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS))
	{
		joints[1] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE))
	{
		if (joints[1]) {
			neckrot.y += HORSE_ROTATION_LEVEL;
		}
		joints[1] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS))
	{
		joints[2] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE))
	{
		if (joints[2]) {
			urfl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[2] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS))
	{
		joints[2] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE))
	{
		if (joints[2]) {
			urfl.y += HORSE_ROTATION_LEVEL;
		}
		joints[2] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS))
	{
		joints[3] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE))
	{
		if (joints[3]) {
			lrfl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[3] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS))
	{
		joints[3] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE))
	{
		if (joints[3]) {
			lrfl.y += HORSE_ROTATION_LEVEL;
		}
		joints[3] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS))
	{
		joints[4] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_4) == GLFW_RELEASE))
	{
		if (joints[4]) {
			urhl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[4] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS))
	{
		joints[4] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_4) == GLFW_RELEASE))
	{
		if (joints[4]) {
			urhl.y += HORSE_ROTATION_LEVEL;
		}
		joints[4] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS))
	{
		joints[5] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_5) == GLFW_RELEASE))
	{
		if (joints[5]) {
			lrhl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[5] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS))
	{
		joints[5] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_5) == GLFW_RELEASE))
	{
		if (joints[5]) {
			lrhl.y += HORSE_ROTATION_LEVEL;
		}
		joints[5] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS))
	{
		joints[6] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_6) == GLFW_RELEASE))
	{
		if (joints[6]) {
			ulfl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[6] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS))
	{
		joints[6] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_6) == GLFW_RELEASE))
	{
		if (joints[6]) {
			ulfl.y += HORSE_ROTATION_LEVEL;
		}
		joints[6] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS))
	{
		joints[7] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_7) == GLFW_RELEASE))
	{
		if (joints[7]) {
			llfl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[7] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS))
	{
		joints[7] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_7) == GLFW_RELEASE))
	{
		if (joints[7]) {
			llfl.y += HORSE_ROTATION_LEVEL;
		}
		joints[7] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS))
	{
		joints[8] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_8) == GLFW_RELEASE))
	{
		if (joints[8]) {
			ulhl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[8] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS))
	{
		joints[8] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_8) == GLFW_RELEASE))
	{
		if (joints[8]) {
			ulhl.y += HORSE_ROTATION_LEVEL;
		}
		joints[8] = false;
	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS))
	{
		joints[9] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_9) == GLFW_RELEASE))
	{
		if (joints[9]) {
			llhl.y -= HORSE_ROTATION_LEVEL;
		}
		joints[9] = false;
	}


	if ((glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS))
	{
		joints[9] = true;
	}
	else if ((glfwGetKey(window, GLFW_KEY_9) == GLFW_RELEASE))
	{
		if (joints[9]) {
			llhl.y += HORSE_ROTATION_LEVEL;
		}
		joints[9] = false;
	}
}

glm::vec3 Horse::get_absolute_position()
{

	return glm::vec3(core_model[3][0], core_model[3][1], core_model[3][2]);
}

void Horse::debug_anim()
{
	std::cout << " =====================================" << std::endl;
	std::cout << "neckrot.y=" << neckrot.y << ";" << std::endl;
	std::cout << "headrot.y=" << headrot.y << ";" << std::endl;
	std::cout << "ulfl.y=" << ulfl.y << ";" << std::endl;
	std::cout << "urfl.y=" << urfl.y << ";" << std::endl;
	std::cout << "ulhl.y=" << ulhl.y << ";" << std::endl;
	std::cout << "urhl.y=" << urhl.y << ";" << std::endl;
	std::cout << "llfl.y=" << llfl.y << ";" << std::endl;
	std::cout << "lrfl.y=" << lrfl.y << ";" << std::endl;
	std::cout << "llhl.y=" << llhl.y << ";" << std::endl;
	std::cout << "lrhl.y=" << lrhl.y << ";" << std::endl;
	std::cout << " =====================================" << std::endl;


}

void Horse::set_core()
{
	core_model *= rotation;

	core_model = glm::translate(core_model, movement_log + (horse_size* glm::vec3(0.0f, 1.2f, 0.0f)));


	torso->model_matrix = core_model;
	torso->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(1.0f, 0.60f, 0.40f));
	torso->color = glm::vec4(1.0f, 0.5411764705882353f, 0.4f, 1.0f);

	//END OF BODYSTUFF
}

//TIME FOR SOME THICC THIGHS
void Horse::set_upper_left_hind_leg()
{
	upper_left_hind_leg->joint_loc = -horse_size*torso_to_hind_upper_left;
	upper_left_hind_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	upper_left_hind_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.4f, -0.15f, 0.175f)); // move it according to world xyz, base position of it. 
	upper_left_hind_leg->rotation_matrix = glm::rotate(upper_left_hind_leg->rotation_matrix, glm::radians(180 + ulhl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	upper_left_hind_leg->color = glm::vec4(1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
}

void Horse::set_upper_right_hind_leg()
{
	upper_right_hind_leg->joint_loc = -horse_size*torso_to_hind_upper_right;
	upper_right_hind_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	upper_right_hind_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.4f, -0.15f, -0.175f)); // move it according to world xyz, base position of it. 
	upper_right_hind_leg->rotation_matrix = glm::rotate(upper_right_hind_leg->rotation_matrix, glm::radians(180 + urhl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	upper_right_hind_leg->color = glm::vec4(1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
}


void Horse::set_upper_left_front_leg()
{

	upper_left_front_leg->joint_loc = -horse_size*torso_to_front_upper_left;
	upper_left_front_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	upper_left_front_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(-0.4f, -0.15f, 0.175f)); // move it according to world xyz, base position of it. 
	upper_left_front_leg->rotation_matrix = glm::rotate(upper_left_front_leg->rotation_matrix, glm::radians(180 + ulfl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	upper_left_front_leg->color = glm::vec4(1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
}

void Horse::set_upper_right_front_leg()
{

	//upper_right_front_leg
	upper_right_front_leg->joint_loc = -horse_size*torso_to_front_upper_right;
	upper_right_front_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	upper_right_front_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(-0.4f, -0.15f, -0.175f)); // move it according to world xyz, base position of it. 
	upper_right_front_leg->rotation_matrix = glm::rotate(upper_right_front_leg->rotation_matrix, glm::radians(180 + urfl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	upper_right_front_leg->color = glm::vec4(1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
}

//OH YES hind_legS
void Horse::set_lower_left_hind_leg()
{
	lower_left_hind_leg->joint_loc = -horse_size*hind_left_knee;
	lower_left_hind_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	lower_left_hind_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.f, 0.5f, -0.f)); // move it according to world xyz, base position of it. 
	lower_left_hind_leg->rotation_matrix = glm::rotate(lower_left_hind_leg->rotation_matrix, glm::radians(llhl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	lower_left_hind_leg->color = glm::vec4(0.6f, 0.1411764705882353f, 0.0f, 1.0f);
}


void Horse::set_lower_right_hind_leg()
{

	lower_right_hind_leg->joint_loc = -horse_size*hind_right_knee;
	lower_right_hind_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	lower_right_hind_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.f, 0.5f, -0.f)); // move it according to world xyz, base position of it. 
	lower_right_hind_leg->rotation_matrix = glm::rotate(lower_right_hind_leg->rotation_matrix, glm::radians(lrhl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	lower_right_hind_leg->color = glm::vec4(0.6f, 0.1411764705882353f, 0.0f, 1.0f);
}



void Horse::set_lower_left_front_leg()
{

	lower_left_front_leg->joint_loc = -horse_size*front_left_knee;
	lower_left_front_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	lower_left_front_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.f, 0.5f, -0.f)); // move it according to world xyz, base position of it. 
	lower_left_front_leg->rotation_matrix = glm::rotate(lower_left_front_leg->rotation_matrix, glm::radians(llfl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	lower_left_front_leg->color = glm::vec4(0.6f, 0.1411764705882353f, 0.0f, 1.0f);
}


void Horse::set_lower_right_front_leg()
{
	lower_right_front_leg->joint_loc = -horse_size*front_right_knee;
	lower_right_front_leg->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	lower_right_front_leg->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(0.f, 0.5f, -0.f)); // move it according to world xyz, base position of it. 
	lower_right_front_leg->rotation_matrix = glm::rotate(lower_right_front_leg->rotation_matrix, glm::radians(lrfl.y), glm::vec3(0.0f, 0.0f, 1.0f));
	lower_right_front_leg->color = glm::vec4(0.6f, 0.1411764705882353f, 0.0f, 1.0f);
}

//DRAW NEK
void Horse::set_neck() {


	neck->joint_loc = -horse_size*neck_to_torso; //neck_to_torso
	neck->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(0.30f, 0.65f, 0.30f));
	neck->model_matrix *= glm::translate(glm::mat4(1.0f), horse_size*glm::vec3(-0.3f, 0.0f, 0.0f)); // move it according to world xyz, base position of it. 
	neck->rotation_matrix = glm::rotate(neck->rotation_matrix, glm::radians(40.0f + neckrot.y), glm::vec3(0.0f, 0.0f, 1.0f));
	neck->rotation_matrix = glm::rotate(neck->rotation_matrix, glm::radians(neckrot.x), glm::vec3(0.0f, 1.0f, 0.0f));
	neck->color = glm::vec4(0.7019607843137255f, 0.1647058823529412f, 0.0f, 1.0f);

}

//DRAW HEAD
void Horse::set_head() {

	head->joint_loc = -horse_size*head_to_neck;//head_to_neck
	head->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(0.20f, 0.50f, 0.35f));
	head->model_matrix *= glm::translate(glm::mat4(1.0f), (horse_size*glm::vec3(-0.00f, 0.6f, 0.0f))); // move it according to world xyz, base position of it. 
	head->rotation_matrix = glm::rotate(head->rotation_matrix, glm::radians(110.0f + headrot.y), glm::vec3(0.0f, 0.0f, 1.0f));
	head->color = glm::vec4(0.4f, 0.0941176470588235f, 0.0f, 1.0f);

}
