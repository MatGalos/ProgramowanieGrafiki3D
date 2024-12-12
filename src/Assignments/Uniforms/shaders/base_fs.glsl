#version 420

layout(location=0) out vec4 vFragColor;
layout(location=1) in vec4 vertex_color;

layout(std140) uniform Modifier {
 float strength;
 vec3  color; 
};

void main() {
    vFragColor = vertex_color;
    vFragColor.rgb = mix(vertex_color.rgb, color, strength);
}
