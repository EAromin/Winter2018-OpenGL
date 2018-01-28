#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Cube {
private:
	 
public: 
	static std::vector<glm::vec3> vertices;
	Cube();
	static void set();
	static void draw();
};