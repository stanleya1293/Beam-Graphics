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
    void rotate(float xOffset, float yOffset);
    glm::mat4 view() const;
    glm::mat4 projection() const;
    glm::vec3 position() const;
private:
    glm::mat4 m_projection;
    glm::mat4 m_view;
    glm::vec3 m_position;
    glm::vec3 m_front;
    float m_yaw;
    float m_pitch;
};


#endif