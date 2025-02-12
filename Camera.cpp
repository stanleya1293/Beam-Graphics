#include "Camera.h"

Camera::Camera(const glm::vec3& position, int screenWidth, int screenHeight) :
	m_projection(glm::mat4(1.0f)),
	m_view(glm::mat4(1.0f)),
	m_position(position),
	m_front(glm::vec3(0, 0, -1))
{
	m_projection = glm::perspective(glm::radians(45.0f), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::move(Movement direction, float speed) {
	switch (direction) {
	case Left:
		m_position -= glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f))) * speed;
		break;
	case Right:
		m_position += glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f))) * speed;
		break;
	case Forward:
		m_position += speed * m_front;
		break;
	case Backward:
		m_position -= speed * m_front;
		break;
	}
}

glm::mat4 Camera::view() const {
	return m_view;
}

glm::mat4 Camera::projection() const {
	return m_projection;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Camera* camera = reinterpret_cast<Camera*>(glfwGetWindowUserPointer(window));
	switch (key) {
	case GLFW_KEY_W:
		camera->move(Forward, 0.05f);
		break;
	case GLFW_KEY_S:
		camera->move(Backward, 0.05f);
		break;
	case GLFW_KEY_A:
		camera->move(Left, 0.05f);
		break;
	case GLFW_KEY_D:
		camera->move(Right, 0.05f);
		break;
	}
}


