#include "stdafx.h"
#include "Map.h"
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include <iostream>

//https://github.com/nothings/stb/blob/master/stb_image.h
glm::mat4 *Map::model_matrix = nullptr;
GLuint *Map::map_shader = nullptr;
void Map::set_shader(GLuint &shader)
{
	Map::map_shader = &shader;
}

void Map::set_model(glm::mat4 &mm)
{
	Map::model_matrix = &mm;
}

void Map::draw()
{
	glUseProgram(*map_shader);

	Grid::set();
	Grid::draw();
	Coordinates::set();
	Coordinates::draw();
	
}


std::vector<glm::vec3> Coordinates::coord_vertices{
	glm::vec3(0.0f,0.0f,0.0f),glm::vec3(5.0f,0.0f,0.0f), //X

	glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,5.0f,0.0f), //Y

	glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,0.0f,5.0f) //Z

};

std::vector<glm::vec3> Grid::grid_vertices{

	glm::vec3(-50.0f,0.0f,0.0f),
	glm::vec3(50.0f,0.0f,0.0f),
	glm::vec3(0.0f,0.0f,-50.0f),
	glm::vec3(0.0f,0.0f,50.0f),
};

void Coordinates::set()
{
	GLuint axisVAO;
	glGenVertexArrays(1, &axisVAO);
	glBindVertexArray(axisVAO);

	GLuint axisVBO;
	glGenBuffers(1, &axisVBO);
	glBindBuffer(GL_ARRAY_BUFFER, axisVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*Coordinates::coord_vertices.size(), &Coordinates::coord_vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(axisVAO);
}

void Coordinates::draw()
{
	glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_LINES, 0, 2);

	glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 0.0f, 1.0f, 0.0f, 1.0f);
	glDrawArrays(GL_LINES, 2, 2);

	glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 0.0f, 0.0f, 1.0f, 1.0f);
	glDrawArrays(GL_LINES, 4, 2);
	
}

void Grid::set()
{
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*Grid::grid_vertices.size(), &Grid::grid_vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(VAO);

}

void Grid::draw()
{
	*Map::model_matrix = glm::translate(*Map::model_matrix, glm::vec3(0, 0, -51.0f)); //so grid is centered
	glUniformMatrix4fv(glGetUniformLocation(*Map::map_shader, "model"), 1, GL_FALSE, glm::value_ptr(*Map::model_matrix));
	for (int z = 0; z <= 100; z++) {
		*Map::model_matrix = glm::translate(*Map::model_matrix, glm::vec3(0.0f, 0.0f, 1 + 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(*Map::map_shader, "model"), 1, GL_FALSE,glm::value_ptr(*Map::model_matrix));
		glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 1.0f, 1.0f, 1.0f, 1.0f);
		glDrawArrays(GL_LINES, 0, 2);


	}
	//reposition
	*Map::model_matrix = glm::translate(*Map::model_matrix, glm::vec3(-51.0f, 0, -50.0f)); //prep for next lines
	glUniformMatrix4fv(glGetUniformLocation(*Map::map_shader, "model"), 1, GL_FALSE, glm::value_ptr(*Map::model_matrix));


	for (int x = 0; x <= 100; x++) {
		*Map::model_matrix = glm::translate(*Map::model_matrix, glm::vec3(1 + 0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(*Map::map_shader, "model"), 1, GL_FALSE, glm::value_ptr(*Map::model_matrix));
		glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 1.0f, 1.0f, 1.0f, 1.0f);
		glDrawArrays(GL_LINES, 2, 2);


	}
	//recentre
	*Map::model_matrix = glm::translate(*Map::model_matrix, glm::vec3(-50.0f, 0, 0)); //we head back to centre
	glUniformMatrix4fv(glGetUniformLocation(*Map::map_shader, "model"), 1, GL_FALSE, glm::value_ptr(*Map::model_matrix));
}

float Floor::floor_vertices[] = {

	50.0f, 0.0f, 50.0f,		50.0f, 0.0f,	//bottom right
	-50.0f, 0.0f, -50.0f,	0.0f, 50.0f,	//upper left
	-50.0f, 0.0f, 50.0f,	0.0f, 0.0f,	//bottom left

	50.0f, 0.0f, 50.0f,		50.0f, 0.0f,	//bottom right
	50.0f, 0.0f, -50.0f,	50.0f, 50.0f,	//upper right
	-50.0f, 0.0f, -50.0f,	0.0f, 50.0f	//upper left


};
GLuint *Floor::floor_shader = nullptr;
GLuint Floor::texture = 0;
GLuint Floor::floorVBO = 0;
GLuint Floor::floorVAO = 0;

void Floor::set(GLuint &shader) {
	floor_shader = &shader;

	glGenVertexArrays(1, &floorVAO);
	glGenBuffers(1, &floorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, floorVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(floor_vertices), floor_vertices, GL_STATIC_DRAW);
	
	glBindVertexArray(floorVAO);

	//coordinates
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	//glEnableVertexAttribArray(1);

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
	unsigned char *data = stbi_load("grass.png", &width, &height, &nrChannels, 0);
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

	glUseProgram(*floor_shader);
	glUniform1i(glGetUniformLocation(*floor_shader, "theTexture"), 0);

};

void Floor::draw() {

	glUseProgram(*floor_shader);
	glUniformMatrix4fv(glGetUniformLocation(*floor_shader, "model"), 1, GL_FALSE, glm::value_ptr(*Map::model_matrix));
	glUniform4f(glGetUniformLocation(*Map::map_shader, "col"), 1.0f, 1.0f, 1.0f, 1.0f);

	glBindVertexArray(floorVAO);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);


	glDrawArrays(GL_TRIANGLES, 0, sizeof(floor_vertices));
}