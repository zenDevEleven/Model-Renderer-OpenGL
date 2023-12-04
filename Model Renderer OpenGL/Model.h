#pragma once
#include "mpch.h"
#include "Mesh.h"

class Model
{
public:
	Model(std::string const& path, bool needsFlip);
	void AddTexture(const char* texturePath);
	void Draw();
	void Translate(glm::vec3 newPos);
	void AddToPosition(glm::vec3 vectorToAdd);
	void SetScale(glm::vec3 newScale);
	void SetRotation(glm::vec3 RotateAxis, float rotationValue);

private:
	std::vector<Mesh> meshes;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
		std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);

	void ResetMatrix() { modelMatrix = glm::mat4(1.0f); }


	std::vector<Texture> textures_loaded;

	std::string modelName;

	GLint positionAttribute;
	GLint textureCoordAttribute;
	GLint colorAttribute;

	std::vector<GLuint> texture;
	std::vector <GLuint> textureLocation;

	glm::vec3 Position;
	glm::vec3 Scale;
	glm::vec3 RotationAxis;
	float RotationValue;

	GLuint modelAttribute;
	glm::mat4 modelMatrix = glm::mat4(1.0f);

};