#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>
#include <fstream>

class Shader
{
public:
	Shader(std::string vertexPath, std::string fragmentPath);
	~Shader();
	void use();
	void setMat4(std::string name, glm::mat4 data);
private:
	unsigned int m_program;
};

#endif