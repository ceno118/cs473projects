#include "vertex_attribute.hpp"

AttributePointer BuildAttribute(int vals, int type, bool norm, int bytes, int offset){
    AttributePointer pointer;
    pointer.vals = vals;
    pointer.type = type;
    pointer.norm = norm;
    pointer.bytes = bytes;
    pointer.offset = offset;
    return pointer;
};

void BindVAO(VAO vao, unsigned int id, int buffer_type){
    glBindVertexArray(id);
    glBindBuffer(buffer_type, id);

    for (int i = 0; i < vao.attributes.size(); i++){
        AttributePointer attr = vao.attributes[i];
        glVertexAttribPointer(i, attr.vals, attr.type, attr.norm, attr.bytes, (void*)(intptr_t)attr.offset);
        glEnableVertexAttribArray(i);
    }

};