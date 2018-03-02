#pragma once
#include <vector>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//gonna use this as a container
class Map {
public:

	static GLuint *map_shader;
	static glm::mat4 *model_matrix;
	static void set_shader(GLuint &shader);
	static void set_model(glm::mat4 &mm);

	static void draw();
};


class Coordinates {
public:
	static std::vector<glm::vec3> coord_vertices;
	static void set();
	static void draw();
};

class Grid {
public:
	static std::vector<glm::vec3> grid_vertices;
	static void set();
	static void draw();
};

class Floor {

public:
	static GLuint *floor_shader;
	static bool tex_toggle;

	static float floor_vertices[];
	static void set(GLuint &shader);
	static void draw();

	static GLuint texture;
	static GLuint  floorVBO, floorVAO;
};