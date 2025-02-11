#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();
	bool isOpen() const;
	void update() const;
private:
	GLFWwindow* m_windowPtr;
};

#endif
