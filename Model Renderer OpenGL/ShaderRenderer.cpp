#include "mpch.h"
#include "ShaderRenderer.h"
#include "Buffer.h"

GLuint ShaderRenderer::vertexShader;
GLuint ShaderRenderer::fragmentShader;
GLuint ShaderRenderer::shaderProgram;



void ShaderRenderer::CreateVertexShader()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string shader_source = readFromFile("Shaders/Vertex.glsl");
	const char* shader_source_ptr = shader_source.c_str();
	glShaderSource(vertexShader, 1, &shader_source_ptr, NULL);
	glCompileShader(vertexShader);

	GLint  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "Created vertex shader" << std::endl;
	}

}

void ShaderRenderer::CreateFragmentShader()
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string shader_source = readFromFile("Shaders/Fragment.glsl");
	const char* shader_source_ptr = shader_source.c_str();
	glShaderSource(fragmentShader, 1, &shader_source_ptr, NULL);
	glCompileShader(fragmentShader);

	GLint  success;
	char infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "Created fragment shader" << std::endl;
	}
}

void ShaderRenderer::CreateProgram()
{
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLint  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else {
		std::cout << "Created program" << std::endl;
	}
}

void ShaderRenderer::Bind()
{
	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void ShaderRenderer::UnBind()
{
	glUseProgram(0);
}

std::string ShaderRenderer::readFromFile(const GLchar* path)
{
	std::ifstream file(path);
	if (!file) 
		return std::string();

	file.ignore(std::numeric_limits<std::streamsize>::max());
	auto size = file.gcount();

	if (size > 0x10000) 
		return std::string();

	file.clear();
	file.seekg(0, std::ios_base::beg);

	std::stringstream sstr;
	sstr << file.rdbuf();
	file.close();

	return sstr.str();
}
