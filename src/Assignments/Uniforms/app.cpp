//
// Created by pbialas on 25.09.2020.
//


#include "app.h"

#include <vector>

#include "spdlog/spdlog.h"

#include "glad/gl.h"

#include "glm/glm.hpp"

#include "glm/gtc/constants.hpp"

#include "Application/utils.h"

void SimpleShapeApplication::init() {
    /*
     * A utility function that reads the shaders' source files, compiles them and creates the program object,
     * as everything in OpenGL we reference the program by an integer "handle".
     * The input to this function is a map that associates a shader type (GL_VERTEX_SHADER and GL_FRAGMENT_SHADER) with
     * its source file. The source files are located in the PROJECT_DIR/shaders directory, where  PROJECT_DIR is the
     * current assignment directory (e.g., src/Assignments/Triangle).
     */
    auto program = xe::utils::create_program(
            {
                    {GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
                    {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"}
            });


    if (!program) {
        SPDLOG_CRITICAL("Invalid program");
        exit(-1);
    }

    GLuint uniform_buffer_handle;
    glGenBuffers(1, &uniform_buffer_handle);
    glBindBuffer(GL_UNIFORM_BUFFER, uniform_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, 8*sizeof(float), NULL, GL_STATIC_DRAW);

    float strength = 0.75;
    float mix_color[3] = {1.0, 2.0, 2.0};

    glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniform_buffer_handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, 4*sizeof(float), &strength);
    glBufferSubData(GL_UNIFORM_BUFFER, 4*sizeof(float), 4*sizeof(float), mix_color);

    GLuint uniform_buffer_handle2;
    glGenBuffers(1, &uniform_buffer_handle2);
    glBindBuffer(GL_UNIFORM_BUFFER, uniform_buffer_handle2);
    glBufferData(GL_UNIFORM_BUFFER, 16*sizeof(float), NULL, GL_STATIC_DRAW);

    float theta = 1.0*glm::pi<float>()/1.0f;//30 degrees
    auto cs = std::cos(theta);
    auto ss = std::sin(theta);  
    glm::mat2 rot{cs,ss,-ss,cs};
    glm::vec2 trans{1.0, 1.0};
    glm::vec2 scale{1.0, 1.0};

    glBindBufferBase(GL_UNIFORM_BUFFER, 1, uniform_buffer_handle2);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, 2*sizeof(float), &scale);
    glBufferSubData(GL_UNIFORM_BUFFER, 2*sizeof(float), 2*sizeof(float), &trans);
    glBufferSubData(GL_UNIFORM_BUFFER, 4*sizeof(float), 4*sizeof(float), &rot[0]);
    glBufferSubData(GL_UNIFORM_BUFFER, 8*sizeof(float), 4*sizeof(float), &rot[1]);

    // A vector containing the x,y,z vertex coordinates for the triangle.
    std::vector<GLfloat> vertices = {
            // roof
            0.0f, 0.5f, 0.0f,   
            1,0,0,

            -0.5f, 0.0f, 0.0f,  
            1,0,0,

            0.5f, 0.0f, 0.0f,
            1,0,0,

            // bottom side of the base
            0.5f, -0.5f, 0.0f,
            0,1,0,

            // Top right side of the home base
            -0.5f, -0.5f, 0.0f,
            0,1,0
        };

    std::vector<GLubyte> index_buffer;
    for(int i = 0; i<vertices.size()/6; i++)index_buffer.push_back(i);

    // A vector containing the indicies for the house
    //std::vector<GLubyte> indices = {0,1,2,3,4,5,6,7,8};
    std::vector<GLubyte> indices = {
        0,1,2,
        1,2,3,
        1,3,4
    };

    GLuint index_buffer_handle;
    glGenBuffers(1, &index_buffer_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLushort), indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 

    // Generating the buffer and loading the vertex data into it.
    GLuint v_buffer_handle;
    glGenBuffers(1, &v_buffer_handle);
    glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // This sets up a Vertex Array Object (VAO) for encapsulation
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle);

    // This specifies that the data for attribute 0 should be read from a vertex buffer
    glEnableVertexAttribArray(0);
    // and this specifies the data layout in the buffer.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                                   reinterpret_cast<GLvoid *>(0));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                                   reinterpret_cast<GLvoid *>(3 * sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_handle);
    glBindVertexArray(0);

    // Setting the background color of the rendering window,
    // I suggest not using white or black for better debugging.
    glClearColor(1.f, 1.f, 0.0f, 1.0f);

    // This set up an OpenGL viewport of the size of the whole rendering window.
    auto [w, h] = frame_buffer_size();
    glViewport(0, 0, w, h);

    glUseProgram(program);
}

//This functions is called every frame and does the actual rendering.
void SimpleShapeApplication::frame() {
    // Binding the VAO will set up all the required vertex attribute arrays.
    glBindVertexArray(vao_);
    glDrawElements(GL_TRIANGLES, 9,  GL_UNSIGNED_BYTE, 0);
    glBindVertexArray(0);
}
