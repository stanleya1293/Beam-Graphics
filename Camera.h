#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum Movement {
    Left,
    Right, 
    Forward,
    Backward
};

class Camera {
public:
	Camera(const glm::vec3 &position, int screenWidth, int screenHeight);
    void move(Movement direction, float speed);
    glm::mat4 view() const;
    glm::mat4 projection() const;
private:
    glm::mat4 m_projection;
    glm::mat4 m_view;
    glm::vec3 m_position;
    glm::vec3 m_front;
};


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif