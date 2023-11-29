#pragma once


class Buffer
{
public:
	Buffer();
	~Buffer();

	void Init();
	void UpdateBufferData();
	void BindVertexArray();
	void CreateAttributePointers();

	inline GLuint GetVAO() { return vao; }
	inline GLuint GetVBO() { return vbo; }
private:
	GLuint vao;
	GLuint vbo;

};