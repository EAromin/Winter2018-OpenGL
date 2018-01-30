#include "stdafx.h"
#include "Horse.h"
#include <vector>

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
	*horse_model *= rotation;
	*horse_model = glm::translate(*horse_model, movement_log + glm::vec3(0.0f, 1.1f, 0.0f));


	
	Cube::set();


	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
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
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, -0.35f, 0.0f)); //make it go down
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.40f, 0.0f, 0.0f)); //move back

																						  //left hind 
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, 0.0f, 0.175f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 1.0f, 0.4627450980392157f, 0.3019607843137255f, 1.0f);
	Cube::draw();

	//right hind
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, 0.0f, -0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();

	//go front
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(-0.80f, 0.0f, 0.0f));

	//right front
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();

	//left front
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, 0.0f, 0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();

	//LEG DAYS BOIS
	//LOWER
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, -0.5f, 0.0f));
	//left front
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.6f, 0.1411764705882353f, 0.0f, 1.0f);
	Cube::draw();

	//right front
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, 0.0f, -0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();


	//go back
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.80f, 0.0f, 0.0f));

	//left back
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();

	//right back
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(0.0f, 0.0f, 0.35f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	Cube::draw();



	//TIME FOR NEK
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(-01.0f, 1.1f, -0.175f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.30f, 0.65f, 0.30f));
	*horse_model = glm::rotate(*horse_model, glm::radians(40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.7019607843137255f, 0.1647058823529412f, 0.0f, 1.0f);
	Cube::draw();

	//TIME FOR HEAD
	*horse_model = glm::translate(*horse_model, horse_size*glm::vec3(-0.30f, 0.2f, 0.0f));
	scale = glm::scale(glm::mat4(1.0f), horse_size* glm::vec3(0.20f, 0.50f, 0.35f));
	*horse_model = glm::rotate(*horse_model, glm::radians(110.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "scale"), 1, GL_FALSE, glm::value_ptr(scale));
	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));
	glUniform4f(glGetUniformLocation(*horse_shader, "col"), 0.4f, 0.0941176470588235f, 0.0f, 1.0f);
	Cube::draw();


	*horse_model = glm::rotate(*horse_model, glm::radians(-150.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	

	glUniformMatrix4fv(glGetUniformLocation(*horse_shader, "model"), 1, GL_FALSE, glm::value_ptr(*horse_model));

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
}
