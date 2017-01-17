#include <iostream>
#include "core/graphics/window.h"
#include "core/graphics/shader.h"

int main() {

    Window window(800, 600, "Game Engine");
    static const GLfloat vertices[] = {
        0.0f, 0.4f, 0.0f,
        -0.4f, 0.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
    };

    GLuint VAO;
    GLuint VBO[2];

    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    Shader shader("shaders/shader.vert", "shaders/shader.frag");
    shader.enable();

    while (!window.isClosed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.update();
    }

    return 0;
}