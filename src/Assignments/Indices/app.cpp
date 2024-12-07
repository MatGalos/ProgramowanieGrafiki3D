//
// Created by pbialas on 25.09.2020.
//


#include "app.h"

#include <vector>

#include "spdlog/spdlog.h"

#include "glad/gl.h"

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

    // A vector containing the x,y,z vertex coordinates for the triangle.
    std::vector<GLfloat> vertices = {
            // roof
            0.0f, 0.5f, 0.0f,   
            1.0f,0.0f,0.f,

            -0.5f, 0.0f, 0.0f,  
            1.0f,0.0f,0.f,

            0.5f, 0.0f, 0.0f,   
            1.0f,0.0f,0.f,

            // bottom side of the base
            0.5f, 0.0f, 0.0f,   
            0.0f,1.0f,0.0f,

            -0.5f, -0.5f, 0.0f, 
            0.0f,1.0f,0.0f,

            0.5f, -0.5f, 0.0f,  
            0.0f,1.0f,0.0f,

            // Top right side of the home base
            0.5f, 0.0f, 0.0f,   
            0.0f,1.0f,0.0f,

            -0.5f, -0.5f, 0.0f, 
            0.0f,1.0f,0.0f,
            
            -0.5f, 0.0f, 0.0f,  
            0.0f,1.0f,0.0f};

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
    glBindVertexArray(0);

    // Setting the background color of the rendering window,
    // I suggest not using white or black for better debugging.
    glClearColor(1.f, 1.f, 0.8f, 1.0f);

    // This set up an OpenGL viewport of the size of the whole rendering window.
    auto [w, h] = frame_buffer_size();
    glViewport(0, 0, w, h);

    glUseProgram(program);
}

//This functions is called every frame and does the actual rendering.
void SimpleShapeApplication::frame() {
    // Binding the VAO will set up all the required vertex attribute arrays.
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, 9);
    glBindVertexArray(0);
}
