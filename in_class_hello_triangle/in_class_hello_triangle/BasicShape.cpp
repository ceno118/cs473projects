#include "BasicShape.hpp"

BasicShape::BasicShape(){

}

void BasicShape::Initialize(VAOStruct vao, float *vertex_data, int data_byte_size, int number_vertices, int prim){
    this -> vao = vao;

    //create the buffer
    glGenBuffers(1, &(this->vbo));

    //bind and populate the buffer
    glBindBuffer(GL_ARRAY_BUFFER, this -> vbo);
    glBufferData(GL_ARRAY_BUFFER, data_byte_size, vertex_data, GL_STATIC_DRAW);

    this -> vao_init = true;
    this -> vao_delete = true;
    this -> vbo_init = true;
    this -> vbo_delete = true;
    this -> number_of_vertices = number_vertices;
    this -> primitive = prim;
}

void BasicShape::Draw(unsigned int shader_program){
    glUseProgram(shader_program);
    BindVAO(this -> vao, this -> vbo);
    glDrawArrays(this -> primitive, 0, this -> number_of_vertices);
}

BasicShape::~BasicShape(){
    if (this -> vao_delete){
        glDeleteVertexArrays(1, &(this -> vao.id));
    }
    if (this -> vbo_delete){
        glDeleteBuffers(1, &(this -> vbo));
    }
}