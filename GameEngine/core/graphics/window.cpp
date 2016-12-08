#include "window.h"

Window::Window(int width, int height, const char * title)
{
    m_Width = width;
    m_Height = height;
    m_Title = title;
    if (!init()) glfwTerminate();
}

Window::~Window()
{
    glfwTerminate();
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(m_Window);
}

bool Window::init()
{
    if (!glfwInit()) return false;
    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

    if (!m_Window) return false;
    if (!glewInit()) return false;

    glfwMakeContextCurrent(m_Window);
}
