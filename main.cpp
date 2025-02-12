#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Window.h"
#include "Camera.h"

int main() {
	

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
    };

    Window window("Title", 1000, 800);

    Camera camera({ 0.0f, 0.0f, 0.0f }, window.width(), window.height());

    window.setPointer(&camera);

    Shader lightShader("../../../shaders/shader.vertex", "../../../shaders/shader.fragment");
    Shader cubeShader("../../../shaders/lightShader.vertex", "../../../shaders/lightShader.fragment");

    unsigned int cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glm::mat4 cube = glm::mat4(1.0f);
    cube = glm::translate(cube, glm::vec3(0.0f, 0.0f, -3.0f));
    cube = glm::scale(cube, glm::vec3(1.0f));
    
    glm::mat4 lightCube = glm::mat4(1.0f);
    lightCube = glm::translate(lightCube, glm::vec3(1.2f, 1.0f, 2.0f));
    lightCube = glm::scale(lightCube, glm::vec3(0.2f));

	while (window.isOpen()) {
        glBindVertexArray(cubeVAO);
        cubeShader.use();
        cubeShader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
        cubeShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
        cubeShader.setMat4("view", camera.view());
        cubeShader.setMat4("projection", camera.projection());
        cubeShader.setMat4("model", cube);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        
        glBindVertexArray(lightCubeVAO);
        lightShader.use();
        lightShader.setMat4("view", camera.view());
        lightShader.setMat4("projection", camera.projection());
        lightShader.setMat4("model", lightCube);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        window.update();
	}

	return 0;
}
