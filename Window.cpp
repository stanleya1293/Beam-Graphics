#include "Window.h"

Window::Window(const std::string& title, int width, int height) :
	m_windowPtr(nullptr),
	m_width(width),
	m_height(height)
{
	glfwInit();
	m_windowPtr = glfwCreateWindow(m_width, m_height, title.c_str(), NULL, NULL);
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

int Window::width() const {
	return m_width;
}

int Window::height() const {
	return m_height;
}

void Window::setPointer(void* object) const {
	glfwSetWindowUserPointer(m_windowPtr, object);
}

void Window::setKeyCallback(GLFWkeyfun function) const {
	glfwSetKeyCallback(m_windowPtr, function);
}
