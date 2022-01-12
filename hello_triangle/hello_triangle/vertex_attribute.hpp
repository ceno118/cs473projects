#ifndef VERTEX_ATTRIBUTE_HPP
#define VERTEX_ATTRIBUTE_HPP
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>

#include <iostream>
#include <vector>
#include <glad/glad.h>

#endif //ENVIRONMENT_SETUP_HPP

struct AttributePointer{
    int vals;
    int type;
    bool norm;
    int bytes;
    int offset;
};

struct VAO{
    unsigned int id;
    std::vector<AttributePointer> attributes;
};

AttributePointer BuildAttribute(int vals, int type, bool norm, int bytes, int offset);
void BindVAO(VAO vao, unsigned int id, int buffer_type);
