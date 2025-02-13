
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.h"
#include "Window.h"
#include "Camera.h"
#include "Model.h"


int main() {
    
    Window window("Title", 1000, 800);

    Camera camera({ 0.0f, 0.0f, 3.0f }, window.width(), window.height());

    window.setPointer(&camera);

    Shader shader("../../../shaders/shader.vertex", "../../../shaders/shader.fragment");
    
    Model ourModel("../../../assets/backpack.obj");

	while (window.isOpen()) {
        shader.use();
        shader.setMat4("view", camera.view());
        shader.setMat4("projection", camera.projection());
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4("model", model);

        ourModel.draw(shader);
        window.update();
	}
	return 0;
}

