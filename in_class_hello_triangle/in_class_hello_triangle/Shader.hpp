#ifndef SHADER_H_
#define SHADER_H_

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//Class is similar to the one defined on www.learnopengl.com.  Primary
// differences include: 1) separate header and source files; 2) use of the
// GLM library to easily set vectors of size 4 (1-3 could be added separately).
class Shader {
public:
    //The ID of the resulting shader program
    unsigned int ID;

    //Constructor for the shader program (takes the path to the
    //vertex and fragment shader GLSL files).
    Shader(const char* vertexPath, const char* fragmentPath);

    //Use the shader program
    void use();

    //Utility functions used to set uniform "boolean", integer, float,
    // and vector values.  Add more as needed.
    void setBool(const std::string &name, bool value) const;
    void setInt (const std::string &name, int value) const;
    void setFloat (const std::string &name, float value) const;
    void setVec4 (const std::string &name, glm::vec4 v) const;

private:
    //Internal function used to check for errors during shader compilation.
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif // SHADER_H_
