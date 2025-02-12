#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera.h"

class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();
	bool isOpen() const;
	void update() const;
	int width() const;
	int height() const;
	void setPointer(void* object) const;
private:
	void processKeyInputs() const;
private:
	GLFWwindow* m_windowPtr;
	int m_width;
	int m_height;
};

void mouseCallback(GLFWwindow* window, double xPos, double yPos);

#endif
