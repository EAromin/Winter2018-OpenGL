#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Horse.h"


#include <math.h>
class Horse;
class Bounding_Sphere {
private:
	float radius;
	static float compute_distance(const Bounding_Sphere &a, const Bounding_Sphere &b);

public:
	Horse* touchy_horse;
	static void update_collision();
	static std::vector<Bounding_Sphere*> bs;
	glm::vec3 location;
	Bounding_Sphere();
	Bounding_Sphere(Horse &horsie);
};