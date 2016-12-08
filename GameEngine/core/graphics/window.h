#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
    GLFWwindow *m_Window;
    const char *m_Title;
    int m_Width, m_Height;

public:
    Window(int width, int height, const char *title);
    ~Window();
    void update();
    bool isClosed() const;

    inline int getWidth() { return m_Width; };
    inline int getHeight() { return m_Height; };

private:
    bool init();
};