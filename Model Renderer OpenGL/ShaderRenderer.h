#pragma once



class ShaderRenderer
{
public:
	static void CreateVertexShader();
	static void CreateFragmentShader();
	static void CreateProgram();

	static void Bind();
	static void UnBind();

	static inline GLuint GetShaderProgram() { return shaderProgram; }


private:
	static std::string readFromFile(const GLchar* path);
	static GLuint vertexShader;
	static GLuint fragmentShader;
	static GLuint shaderProgram;


};

