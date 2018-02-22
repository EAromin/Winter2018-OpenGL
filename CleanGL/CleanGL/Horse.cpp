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
	Cube::set(); //unit to draw
	torso = &CubicPart::CubicPart(*horse_shader);


	

	//hieirarchial model
	draw_core();
	
	//draw_upper_left_hind_leg();
	//draw_upper_right_hind_leg();
	//draw_upper_left_front_leg();
	//draw_upper_right_front_leg();

	//draw_lower_left_hind_leg();
	//draw_lower_right_hind_leg(); 
	//draw_lower_left_front_leg();
	//draw_lower_right_front_leg();

	//draw_neck();
	//draw_head();

	torso->draw();
	double dArray[16] = {0.0};

const float *pSource = (const float*)glm::value_ptr(torso->model_matrix);
	for (int i = 0; i < 16; i+=4)
   { dArray[i] = pSource[i];
   	std::cout << dArray[i] << "\t" <<dArray[i+1] << "\t" <<dArray[i+2] << "\t" <<dArray[i+3] << std::endl;
   	}

//	core_model = glm::rotate(core_model, glm::radians(-150.0f), glm::vec3(0.0f, 0.0f, 1.0f));
//	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(core_model));

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


}

void Horse::draw_core()
{
	core_model *= rotation;
	core_model = glm::translate(core_model, movement_log + (horse_size* glm::vec3(0.0f, 1.1f, 0.0f)));

/*
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(core_model));
	//BODY STUFF
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.5411764705882353f, 0.4f, 1.0f);
	Cube::draw();
*/

	torso->model_matrix = core_model;
	torso->scale_matrix = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(1.0f, 0.60f, 0.40f));
	torso->color = glm::vec4(1.0f, 0.5411764705882353f, 0.4f, 1.0f);

	//END OF BODYSTUFF
}

//TIME FOR SOME THICC THIGHS
void Horse::draw_upper_left_hind_leg()
{
	//set
	upper_left_hind_leg_model = core_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	upper_left_hind_leg_model = glm::translate(upper_left_hind_leg_model, horse_size*glm::vec3(0.0f, -0.35f, 0.0f));//down
	upper_left_hind_leg_model = glm::translate(upper_left_hind_leg_model, horse_size*glm::vec3(0.40f, 0.0f, 0.0f));//back
	upper_left_hind_leg_model = glm::translate(upper_left_hind_leg_model, horse_size*glm::vec3(0.0f, 0.0f, 0.175f));//left
	
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(upper_left_hind_leg_model));
	glm::vec4 couleur = glm::vec4(1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), couleur.r, couleur.g, couleur.b,couleur.a);
	Cube::draw();
}

void Horse::draw_upper_right_hind_leg()
{
	//set
	upper_right_hind_leg_model = core_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	
	//pos
	upper_right_hind_leg_model = glm::translate(upper_right_hind_leg_model, horse_size*glm::vec3(0.0f, -0.35f, 0.0f));//down
	upper_right_hind_leg_model = glm::translate(upper_right_hind_leg_model, horse_size*glm::vec3(0.40f, 0.0f, 0.0f));//back 																										
	upper_right_hind_leg_model = glm::translate(upper_right_hind_leg_model, horse_size*glm::vec3(0.0f, 0.0f, -0.175f));//right
	
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(upper_right_hind_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	Cube::draw();
}


void Horse::draw_upper_left_front_leg()
{
	//set
	upper_left_front_leg_model = core_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	upper_left_front_leg_model = glm::translate(upper_left_front_leg_model, horse_size*glm::vec3(0.0f, -0.35f, 0.0f));//down
	upper_left_front_leg_model = glm::translate(upper_left_front_leg_model, horse_size*glm::vec3(-0.40f, 0.0f, 0.0f));//front
	upper_left_front_leg_model = glm::translate(upper_left_front_leg_model, horse_size*glm::vec3(0.0f, 0.0f, 0.175f));//left

	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(upper_left_front_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	Cube::draw();
}

void Horse::draw_upper_right_front_leg()
{
	//set
	upper_right_front_leg_model = core_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	upper_right_front_leg_model = glm::translate(upper_right_front_leg_model, horse_size*glm::vec3(0.0f, -0.35f, 0.0f));//down
	upper_right_front_leg_model = glm::translate(upper_right_front_leg_model, horse_size*glm::vec3(-0.40f, 0.0f, 0.0f));//front 																										
	upper_right_front_leg_model = glm::translate(upper_right_front_leg_model, horse_size*glm::vec3(0.0f, 0.0f, -0.175f));//right

	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(upper_right_front_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	Cube::draw();
}

//OH YES hind_legS
void Horse::draw_lower_left_hind_leg()
{
	//set
	lower_left_hind_leg_model = upper_left_hind_leg_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	lower_left_hind_leg_model = glm::translate(lower_left_hind_leg_model, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));//down


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(lower_left_hind_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();
}


void Horse::draw_lower_right_hind_leg()
{
	//set
	lower_right_hind_leg_model = upper_right_hind_leg_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	lower_right_hind_leg_model = glm::translate(lower_right_hind_leg_model, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));//down


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(lower_right_hind_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();
}



void Horse::draw_lower_left_front_leg()
{
	//set
	lower_left_front_leg_model = upper_left_front_leg_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	lower_left_front_leg_model = glm::translate(lower_left_front_leg_model, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));//down


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(lower_left_front_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();
}


void Horse::draw_lower_right_front_leg()
{
	//set
	lower_right_front_leg_model = upper_right_front_leg_model;
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));

	//pos
	lower_right_front_leg_model = glm::translate(lower_right_front_leg_model, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));//down


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(lower_right_front_leg_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();
}

//DRAW NEK
void Horse::draw_neck() {
	neck_model = core_model;
	neck_model = glm::translate(neck_model, horse_size*glm::vec3(-0.6f, 0.125f, 0.0f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.30f, 0.65f, 0.30f));
	neck_model = glm::rotate(neck_model, glm::radians(40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(neck_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.7019607843137255f, 0.1647058823529412f, 0.0f, 1.0f);
	Cube::draw();
}

//DRAW HEAD
void Horse::draw_head() {
	head_model = neck_model;
	head_model = glm::translate(head_model, horse_size*glm::vec3(-0.30f, 0.2f, 0.0f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.20f, 0.50f, 0.35f));
	head_model = glm::rotate(head_model, glm::radians(110.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(head_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.4f, 0.0941176470588235f, 0.0f, 1.0f);
	Cube::draw();

	
}
