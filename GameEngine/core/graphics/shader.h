#pragma once
#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>
using std::string;

class Shader
{
private:
    GLuint m_ShaderID;
    const string m_VertexShader;
    const string m_FragmentShader;

public:
    Shader(const string vetexShader, const string fragmentShader);
    ~Shader();
    GLuint LoadShader();
    void enable() const;
};
