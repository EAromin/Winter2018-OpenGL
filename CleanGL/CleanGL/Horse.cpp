#include "stdafx.h"
#include "Horse.h"
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <iostream>
void Horse::set_shader(GLuint & shader)
{
	horse_shader = &shader;
}

void Horse::set_model(glm::mat4 &model)
{
	core_model = model;
}

void Horse::draw()
{
	glUseProgram(*horse_shader);

	Cube::set(); //unit to draw
	torso = &CubicPart::CubicPart(*horse_shader);
	set_core();

	neck = &CubicPart::CubicPart(*horse_shader, *torso);
	set_neck();

	head = &CubicPart::CubicPart(*horse_shader,*neck);
	set_head();

	//uppers
	upper_right_front_leg= &CubicPart::CubicPart(*horse_shader,*torso);
	set_upper_right_front_leg();
	upper_right_hind_leg = &CubicPart::CubicPart(*horse_shader,*torso);
	set_upper_right_hind_leg();

	upper_left_front_leg= &CubicPart::CubicPart(*horse_shader,*torso);
	set_upper_left_front_leg();
	upper_left_hind_leg= &CubicPart::CubicPart(*horse_shader,*torso);
	set_upper_left_hind_leg();
	//lowers
	lower_left_front_leg= &CubicPart::CubicPart(*horse_shader,*upper_left_front_leg);
	set_lower_left_front_leg();
	lower_right_hind_leg = &CubicPart::CubicPart(*horse_shader,*upper_right_hind_leg);
	set_lower_right_hind_leg();
	lower_right_front_leg= &CubicPart::CubicPart(*horse_shader, *upper_right_front_leg);
	set_lower_right_front_leg();
	lower_left_hind_leg= &CubicPart::CubicPart(*horse_shader,*upper_left_hind_leg);
	set_lower_left_hind_leg();


	torso->draw();


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
			rotation = glm::rotate(rotation, glm::radians(5.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
			rotation = glm::translate(rotation,movement_log);
			rotation = glm::rotate(rotation, glm::radians(-5.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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
			rotation = glm::translate(rotation, (movement_log + glm::vec3(0.0f,1.1f,0.0f)));
			rotation = glm::rotate(rotation, glm::radians(-5.0f), glm::vec3(0.0f, 0.0f,1.0f));
			rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.0f,1.1f,0.0f)));
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
			rotation = glm::translate(rotation, (movement_log + glm::vec3(0.0f,1.1f,0.0f)));
			rotation = glm::rotate(rotation, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			rotation = glm::translate(rotation, -(movement_log + glm::vec3(0.0f,1.1f,0.0f)));
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
			movement_log = glm::vec3(randx + 0.0f, 0.0f,randz + 0.0f);
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


	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS))
	{
		neckrot.y -= 5.0f;
	}else	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		neckrot.y += 5.0f;

	}
	if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS))
	{
		headrot.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) {
		headrot.y += 5.0f;


	}if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS))
	{
		urfl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		urfl.y += 5.0f;


	}if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS))
	{
		lrfl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		lrfl.y += 5.0f;


	}
		if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS))
	{
		urhl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		urhl.y += 5.0f;


	}if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS))
	{
		lrhl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
		lrhl.y += 5.0f;


	}




		if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS))
	{
		ulfl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
		ulfl.y += 5.0f;


	}if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS))
	{
		llfl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {
		llfl.y += 5.0f;


	}
		if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS))
	{
		ulhl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) {
		ulhl.y += 5.0f;


	}if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) && (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS))
	{
		llhl.y -= 5.0f;
	}
	else
	if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) {
		llhl.y += 5.0f;


	}
}

void Horse::set_core()
{
	core_model *= rotation;
	core_model = glm::translate(core_model, movement_log + (horse_size* glm::vec3(0.0f, 1.1f, 0.0f)));

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
	//neck->translation_matrix = glm::translate(neck->translation_matrix, horse_size*glm::vec3(-0.6f, 0.125f, 0.0f));
	neck->rotation_matrix = glm::rotate(neck->rotation_matrix, glm::radians(40.0f + neckrot.y), glm::vec3(0.0f, 0.0f, 1.0f));
	neck->rotation_matrix = glm::rotate(neck->rotation_matrix, glm::radians(neckrot.x), glm::vec3(0.0f, 1.0f, 0.0f));
	neck->color = glm::vec4(0.7019607843137255f, 0.1647058823529412f, 0.0f, 1.0f);

}

//DRAW HEAD
void Horse::set_head() {

	head->joint_loc = -horse_size*head_to_neck;//head_to_neck
	//head->joint_loc = head->parent->joint_loc;
	head->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(0.20f, 0.50f, 0.35f));
	head->model_matrix *= glm::translate(glm::mat4(1.0f), (horse_size*glm::vec3(-0.00f,0.6f, 0.0f))); // move it according to world xyz, base position of it. 
   // head->translation_matrix *= glm::translate(head->translation_matrix, horse_size*glm::vec3(0.00f, .250f, 0.0f));
	head->rotation_matrix = glm::rotate(head->rotation_matrix, glm::radians( 110.0f +headrot.y), glm::vec3(0.0f, 0.0f, 1.0f));
	head->color = glm::vec4(0.4f, 0.0941176470588235f, 0.0f, 1.0f);
	
}
