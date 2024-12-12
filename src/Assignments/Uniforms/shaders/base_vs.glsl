#version 420

layout(location=0) in  vec4 a_vertex_position;
layout(location=1) in  vec4 a_vertex_color;

layout(location=1) out vec4 vertex_color;

layout(std140) uniform Transformations {
    vec2 scale;
    vec2 translation;
    mat2 rotation;
    };

void main() {
    gl_Position = a_vertex_position;
    vertex_color = a_vertex_color;
    gl_Position.xy = rotation*(scale*a_vertex_position.xy) + translation;
    gl_Position.zw = a_vertex_position.zw;
}
