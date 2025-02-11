#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum Movement {
    Left,
    Right, 
    Down,
    Up
};

class Camera {
public:
	Camera(const glm::vec3 &position);
    void move(Movement direction, float speed);
private:
    glm::mat4 m_view;
    glm::vec3 m_position;
};

#endif