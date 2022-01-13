#ifndef BASICSHAPE_HPP
#define BASICSHAPE_HPP
#include "vertex_attribute.hpp"


class BasicShape{
    protected:
        VAOStruct vao;
        unsigned int vbo = 0;
        int number_of_vertices = 2;
        bool vao_init = false;
        bool vbo_init = false;
        bool vao_delete = false;
        bool vbo_delete = false;
        GLuint primitive = GL_TRIANGLES;
    
    public:
        BasicShape();
        void Initialize(VAOStruct vao, float *vertex_data, int data_byte_size, int number_vertices, int prim = GL_TRIANGLES);
        void Draw(unsigned int shader_program);
        ~BasicShape();
};

#endif //BASICSHAPE_HPP