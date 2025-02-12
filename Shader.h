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
	Shader(const std::string &vertexPath, const std::string &fragmentPath);
	~Shader();
	void use() const;
	void setMat4(const std::string &name, const glm::mat4 &data) const;
	void setVec3(const std::string &name, const glm::vec3 &data) const;
	void setFloat(const std::string& name, float value) const;
	void setInt(const std::string& name, int value) const;
private:
	unsigned int m_program;
};

#endif