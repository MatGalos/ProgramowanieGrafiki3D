#version 420

in vec3 vertexColor;

layout(location=0) out vec4 vFragColor;

//uniform Color {
//    vec4 Kd;
//    bool use_map_Kd;
//};
//
//uniform sampler2D map_Kd;

void main() {
    //if (use_map_Kd)
        vFragColor = vec4(vertexColor, 1.0);
        //vFragColor = Kd*texture(map_Kd, vertex_texcoords);
    //else
        //vFragColor = Kd;
}
