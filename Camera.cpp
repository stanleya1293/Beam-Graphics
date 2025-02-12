#include "Camera.h"

Camera::Camera(const glm::vec3& position, int screenWidth, int screenHeight) :
	m_projection(glm::mat4(1.0f)),
	m_view(glm::mat4(1.0f)),
	m_position(position),
	m_front(0.0f),
	m_yaw(-90.0f),
	m_pitch(0.0f)
{
	m_front = glm::normalize(
		glm::vec3(
			cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch)),
			sin(glm::radians(m_pitch)),
			sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch))
		)
	);
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
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::rotate(float xOffset, float yOffset) {
	m_yaw += (xOffset * 0.1);
	m_pitch += (yOffset * 0.1);

	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	if (m_pitch < -89.0f)
		m_pitch = -89.0f;

	m_front = glm::normalize(
		glm::vec3(
			cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch)),
			sin(glm::radians(m_pitch)),
			sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch))
		)
	);
	m_view = glm::lookAt(m_position, m_position + m_front, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::view() const {
	return m_view;
}

glm::mat4 Camera::projection() const {
	return m_projection;
}

glm::vec3 Camera::position() const {
	return m_position;
}
