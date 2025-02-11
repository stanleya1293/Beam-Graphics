#include "Window.h"

Window::Window(const std::string &title, int width, int height) : m_windowPtr(nullptr) {
	glfwInit();
	m_windowPtr = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_windowPtr);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, width, height);
}

Window::~Window() {
	glfwDestroyWindow(m_windowPtr);
	glfwTerminate();
}

bool Window::isOpen() const {
	if (glfwWindowShouldClose(m_windowPtr)){
		return false;
	}
	return true;
}

void Window::update() const {
	glfwSwapBuffers(m_windowPtr);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}