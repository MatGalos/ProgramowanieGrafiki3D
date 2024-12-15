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

#include "glm/vec2.hpp"
#include "glm/fwd.hpp"
#include "glm/detail/type_mat2x2.hpp"
#include "glm/ext/scalar_constants.hpp"
#include "glm/trigonometric.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

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
    float mix_color[3] = {1.0, 1.0, 1.0};

    glBindBufferBase(GL_UNIFORM_BUFFER, 0, uniform_buffer_handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, 4*sizeof(float), &strength);
    glBufferSubData(GL_UNIFORM_BUFFER, 4*sizeof(float), 4*sizeof(float), mix_color);

    GLuint transformation;
    glGenBuffers(1, &transformation);
    glBindBuffer(GL_UNIFORM_BUFFER, transformation);
    glBufferData(GL_UNIFORM_BUFFER, 64, nullptr, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, transformation);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::lookAt(
            glm::vec3(0.0f, 0.0f, 1.0f),             
            glm::vec3(0.0f, 0.0f, 0.0f),           
            glm::vec3(0.0f, 0.0f, 0.0f));            

    glm::mat4 projection = glm::perspective(
            glm::radians(90.0f),                    
            0.2f,                                          
            0.1f,                                          
            100.0f);                                         

    glm::mat4 PVM = projection * view * model;

    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(PVM));

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
