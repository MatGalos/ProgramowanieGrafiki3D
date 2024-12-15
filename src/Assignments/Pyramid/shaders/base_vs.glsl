#version 420

layout(location=0) in  vec4 a_vertex_position;
layout(location=1) in  vec4 a_vertex_color;

layout(location=1) out vec4 vertex_color;

layout(std140) uniform Transformations {
    mat4 PVM;
    };

void main() {
    gl_Position =  PVM * a_vertex_position;
    gl_Position.zw = a_vertex_position.zw;
    vertex_color = a_vertex_color;
}
