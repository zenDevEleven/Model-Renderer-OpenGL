#pragma once

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string path;
	std::string type;
};

class Mesh
{
	public:
		// mesh data
		std::vector<Vertex>       vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture>      textures;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		void Draw();
	private:
		//  render data
		unsigned int VAO, VBO, EBO;

		void setupMesh();
	};

