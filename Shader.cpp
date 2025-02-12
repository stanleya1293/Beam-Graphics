#include "Shader.h"

#include <iostream>

enum ShaderType { //work on this another time
	Vertex,
	Fragment
};

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) :
	m_program(NULL)
{
	std::ifstream vertexFile(vertexPath);
	std::ifstream fragmentFile(fragmentPath);

	if (!vertexFile)
	{
		std::cout << "Invalid vertex file path" << std::endl;
	}
	if (!fragmentFile)
	{
		std::cout << "Invalid fragment file path" << std::endl;
	}

	std::stringstream vertexStream;
	std::stringstream fragmentStream;
	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();
	
	std::string vertexSrcCode = vertexStream.str();
	std::string fragmentSrcCode = fragmentStream.str();

	const char* vertexSrc = vertexSrcCode.c_str();
	const char* fragmentSrc = fragmentSrcCode.c_str();

	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vertexSrc, NULL);
	glShaderSource(fShader, 1, &fragmentSrc, NULL);
	
	int vSuccess;
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vSuccess);
	if (!vSuccess)
	{
		std::cout << "Vertex shader error compilation" << std::endl;
	}

	int fSuccess;
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fSuccess);
	if (!fSuccess)
	{
		std::cout << "Fragment shader error compilation" << std::endl;
	}

	m_program = glCreateProgram();
	glAttachShader(m_program, vShader);
	glAttachShader(m_program, fShader);
	glLinkProgram(m_program);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

void Shader::use() const {
	glUseProgram(m_program);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &data) const {
	glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, glm::value_ptr(data));
}

void Shader::setVec3(const std::string& name, const glm::vec3& data) const {
	glUniform3fv(glGetUniformLocation(m_program, name.c_str()), 1, glm::value_ptr(data));
}