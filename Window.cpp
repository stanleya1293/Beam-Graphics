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
	glfwSetInputMode(m_windowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_windowPtr, mouseCallback);
	glEnable(GL_DEPTH_TEST);
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
	processKeyInputs();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void Window::processKeyInputs() const {
	Camera* camera = reinterpret_cast<Camera*>(glfwGetWindowUserPointer(m_windowPtr));
		if (glfwGetKey(m_windowPtr, GLFW_KEY_W) == GLFW_PRESS)
			camera->move(Forward, 0.05);
		if (glfwGetKey(m_windowPtr, GLFW_KEY_S) == GLFW_PRESS)
			camera->move(Backward, 0.05);
		if (glfwGetKey(m_windowPtr, GLFW_KEY_A) == GLFW_PRESS)
			camera->move(Left, 0.05);
		if (glfwGetKey(m_windowPtr, GLFW_KEY_D) == GLFW_PRESS)
			camera->move(Right, 0.05);
}

void mouseCallback(GLFWwindow* window, double xPos, double yPos) {

	static bool firstMouse = true;
	static float lastx, lasty;
	Camera* camera = reinterpret_cast<Camera*>(glfwGetWindowUserPointer(window));
	if (firstMouse) {
		lastx = xPos;
		lasty = yPos;
		firstMouse = false;
	}

	camera->rotate((xPos - lastx), (lasty - yPos));
	
	lastx = xPos;
	lasty = yPos;
}