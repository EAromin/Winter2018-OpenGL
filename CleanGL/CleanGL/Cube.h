#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "stb_image.h"
class Cube {
private:
	 
public: 
	static bool tex_toggle;
	static GLuint VAO;
	static GLuint VBO;
	static GLuint texture;
	static GLuint *shader;
	static float verticess[];
	static std::vector<glm::vec3> vertices;
	Cube();
	static void set();
	static void draw();
	static void set_shader(GLuint &shdr);
};