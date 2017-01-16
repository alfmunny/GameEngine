#include <iostream>
#include "core/graphics/window.h"
#include "core/graphics/shader.h"

int main() {

    Window window(800, 600, "Game Engine");
    static const GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        0.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.1f,
    };

    GLuint VBO[2];
    glGenBuffers(2, VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    Shader shader("shaders/shader.vert", "shaders/shader.frag");
    shader.enable();

    while (!window.isClosed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        window.update();
    }


    return 0;
}