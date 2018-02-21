#include "stdafx.h"
#include "Map.h"

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
