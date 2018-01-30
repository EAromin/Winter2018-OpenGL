#include "stdafx.h"
#include "Horse.h"
#include <vector>
#include <stdlib.h>    
#include <time.h> 

void Horse::set_shader(GLuint & shader)
{
	horse_shader = &shader;
}

void Horse::set_model(glm::mat4 &model)
{
	horse_model = &model;
}

void Horse::draw()
{


	glm::mat4 scale;
	glm::mat4 temp_horse; //makes it so you dont tamper with world model
	temp_horse = *horse_model;
	temp_horse *= rotation;
	temp_horse = glm::translate(temp_horse, movement_log + (horse_size* glm::vec3(0.0f, 1.1f, 0.0f)));



	Cube::set();


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	//BODY STUFF
	scale = glm::scale(glm::mat4(1.0f), horse_size*glm::vec3(1.0f, 0.60f, 0.40f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.5411764705882353f, 0.4f, 1.0f);
	Cube::draw();
	//END OF BODYSTUFF

	//THICC THIGHS
	//size
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.15f, 0.5f, 0.15f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	//position
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, -0.35f, 0.0f)); //make it go down
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.40f, 0.0f, 0.0f)); //move back

																					  //left hind 
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, 0.0f, 0.175f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	Cube::draw();

	//right hind
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, 0.0f, -0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();

	//go front
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(-0.80f, 0.0f, 0.0f));

	//right front
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();

	//left front
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, 0.0f, 0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();

	//LEG DAYS BOIS
	//LOWER
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));
	//left front
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();

	//right front
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, 0.0f, -0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();


	//go back
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.80f, 0.0f, 0.0f));

	//left back
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();

	//right back
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(0.0f, 0.0f, 0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	Cube::draw();



	//TIME FOR NEK
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(-01.0f, 1.1f, -0.175f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.30f, 0.65f, 0.30f));
	temp_horse = glm::rotate(temp_horse, glm::radians(40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.7019607843137255f, 0.1647058823529412f, 0.0f, 1.0f);
	Cube::draw();

	//TIME FOR HEAD
	temp_horse = glm::translate(temp_horse, horse_size*glm::vec3(-0.30f, 0.2f, 0.0f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.20f, 0.50f, 0.35f));
	temp_horse = glm::rotate(temp_horse, glm::radians(110.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.4f, 0.0941176470588235f, 0.0f, 1.0f);
	Cube::draw();


	temp_horse = glm::rotate(temp_horse, glm::radians(-150.0f), glm::vec3(0.0f, 0.0f, 1.0f));


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(temp_horse));

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
			rotation = glm::translate(rotation, movement_log);
			rotation = glm::rotate(rotation, glm::radians(-5.0f), glm::vec3(0.0f, 0.0f,1.0f));
			rotation = glm::translate(rotation, -movement_log);
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
			rotation = glm::translate(rotation, movement_log);
			rotation = glm::rotate(rotation, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			rotation = glm::translate(rotation, -movement_log);
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
