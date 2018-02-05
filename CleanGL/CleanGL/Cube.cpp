#include "stdafx.h"
#include "Cube.h"
#include <vector>


std::vector<glm::vec3> Cube::vertices = {
	//front face
	glm::vec3(-0.5f,-0.5f,0.5f),glm::vec3(0.5f,-0.5f,0.5f),
	glm::vec3(0.5f,0.5f,0.5f),glm::vec3(-0.5f,-0.5f,0.5f),
	glm::vec3(-0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),

	//top
	glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.5f,0.5f,-0.5f),
	glm::vec3(-0.5f,0.5f,-0.5f),glm::vec3(0.5f,0.5f,0.5f),
	glm::vec3(-0.5f,0.5f,0.5f),glm::vec3(-0.5f,0.5f,-0.5f),
	//left
	glm::vec3(-0.5f,0.5f,-0.5f),glm::vec3(-0.5f,0.5f,0.5f),
	glm::vec3(-0.5f,-0.5f,0.5f),glm::vec3(-0.5f,0.5f,-0.5f),
	glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec3(-0.5f,-0.5f,0.5f),

	//bottom
	glm::vec3(-0.5f,-0.5f,0.5f),glm::vec3(0.5f,-0.5f,0.5f),
	glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(-0.5f,-0.5f,0.5f),
	glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec3(0.5f,-0.5f,-0.5f),

	//right
	glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(0.5f,0.5f,-0.5f),
	glm::vec3(0.5f,0.5f,0.5f),glm::vec3(0.5f,-0.5f,-0.5f),
	glm::vec3(0.5f,-0.5f,0.5f),glm::vec3(0.5f,0.5f,0.5f),
	//back face
	glm::vec3(-0.5f,0.5f,-0.5f),glm::vec3(-0.5f,-0.5f,-0.5f),
	glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(-0.5f,0.5f,-0.5f),
	glm::vec3(0.5f,0.5f,-0.5f),glm::vec3(0.5f,-0.5f,-0.5f),

};

Cube::Cube()
{
	

}

//sets vao vbo
void Cube::set()
{
	GLuint VAO;
	GLuint VBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*Cube::vertices.size(), &Cube::vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(VAO);
}

void Cube::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, Cube::vertices.size());
}
