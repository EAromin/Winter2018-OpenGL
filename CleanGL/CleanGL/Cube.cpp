#include "stdafx.h"
#include "Cube.h"
#include <vector>
#include <iostream>



float Cube::verticess[] = {
	//front face		
	-0.5f,-0.5f,0.5f,	1.0f, 0.0f,
	0.5f,-0.5f,0.5f,	0.0f, 1.0f,
	0.5f,0.5f,0.5f,		0.0f, 0.0f,
	-0.5f,-0.5f,0.5f,	1.0f, 0.0f,
	-0.5f,0.5f,0.5f,	1.0f, 1.0f,
	0.5f,0.5f,0.5f,		0.0f, 1.0f,

	//top face
	0.5f,0.5f,0.5f,		1.0f, 0.0f,
	0.5f,0.5f,-0.5f,	0.0f, 1.0f,
	-0.5f,0.5f,-0.5f,	0.0f, 0.0f,
	0.5f,0.5f,0.5f,		1.0f, 0.0f,
	-0.5f,0.5f,0.5f,	1.0f, 1.0f,
	-0.5f,0.5f,-0.5f,	0.0f, 1.0f,

	//left
	-0.5f,0.5f,-0.5f,	1.0f, 0.0f,
	-0.5f,0.5f,0.5f,	0.0f, 1.0f,
	-0.5f,-0.5f,0.5f,	0.0f, 0.0f,
	-0.5f,0.5f,-0.5f,	1.0f, 0.0f,
	-0.5f,-0.5f,-0.5f,	1.0f, 1.0f,
	-0.5f,-0.5f,0.5f,	0.0f, 1.0f,

	//bottom
	-0.5f,-0.5f,0.5f,	1.0f, 0.0f,
	0.5f,-0.5f,0.5f,	0.0f, 1.0f,
	0.5f,-0.5f,-0.5f,	0.0f, 0.0f,
	-0.5f,-0.5f,0.5f,	1.0f, 0.0f,
	-0.5f,-0.5f,-0.5f,	1.0f, 1.0f,
	0.5f,-0.5f,-0.5f,	0.0f, 1.0f,

	//right
	0.5f,-0.5f,-0.5f,	1.0f, 0.0f,
	0.5f,0.5f,-0.5f,	0.0f, 1.0f,
	0.5f,0.5f,0.5f,		0.0f, 0.0f,
	0.5f,-0.5f,-0.5f,	1.0f, 0.0f,
	0.5f,-0.5f,0.5f,	1.0f, 1.0f,
	0.5f,0.5f,0.5f,		0.0f, 1.0f,

	//back
	-0.5f,0.5f,-0.5f,	1.0f, 0.0f,
	-0.5f,-0.5f,-0.5f,	0.0f, 1.0f,
	0.5f,-0.5f,-0.5f,	0.0f, 0.0f,
	-0.5f,0.5f,-0.5f,	1.0f, 0.0f,
	0.5f,0.5f,-0.5f,	1.0f, 1.0f,
	0.5f,-0.5f,-0.5f,	0.0f, 1.0f,

};
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
 bool Cube::tex_toggle = false;
 GLuint Cube::texture= 0;
 GLuint* Cube::shader = nullptr;
 GLuint Cube::VAO = 0;
 GLuint Cube::VBO = 0;
//sets vao vbo
void Cube::set()
{


}

void Cube::draw()
{
	
	if (tex_toggle)
		glEnableVertexAttribArray(1);
	else
		glDisableVertexAttribArray(1);

	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(Cube::verticess));

	glDisableVertexAttribArray(1);

}

void Cube::set_shader(GLuint &shdr)
{
	shader = &shdr;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*Cube::vertices.size(), &Cube::vertices[0], GL_STATIC_DRAW);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Cube::verticess), &Cube::verticess[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//text
	//texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// ---------
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load("smonk.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture 1" << std::endl;
	}

	stbi_image_free(data);

	glUseProgram(*shader);
	glUniform1i(glGetUniformLocation(*shader, "theTexture"), 0);
}
