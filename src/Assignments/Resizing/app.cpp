//
// Created by pbialas on 25.09.2020.
//


#include "app.h"
#include <vector>
#include "spdlog/spdlog.h"
#include "glad/gl.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Application/utils.h"

void SimpleShapeApplication::init() {
    auto program = xe::utils::create_program(
        {
                {GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
                {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"}
        });


    if (!program) {
        SPDLOG_CRITICAL("Invalid program");
        exit(-1);
    }

    std::vector<GLshort> indices = {
        0, 1, 2,
        1, 3, 2,
        4, 6, 5,
        7, 9, 8,
        10, 11, 12,
        13, 14, 15
    };
    std::vector<GLfloat> vertices = {
         1,  1,  0,     0.5, 0.5, 0.5,
         1, -1,  0,     0.5, 0.5, 0.5,
        -1,  1,  0,     0.5, 0.5, 0.5,
        -1, -1,  0,     0.5, 0.5, 0.5,
         1, -1,  0,     1, 0, 0,
        -1, -1,  0,     1, 0, 0,
         0,  0,  1,     1, 0, 0,
         1,  1,  0,     0, 1, 0,
         1, -1,  0,     0, 1, 0,
         0,  0,  1,     0, 1, 0,
         1,  1,  0,     0, 0, 1,
        -1,  1,  0,     0, 0, 1,
         0,  0,  1,     0, 0, 1,
        -1,  1,  0,     1, 1, 0,
        -1, -1,  0,     1, 1, 0,
         0,  0,  1,     1, 1, 0,
    };

    glm::mat4 PVM(1.0f);
    glm::mat4 M(1.0);
    glm::vec3 camera_position = { 0,0,3 };
    glm::vec3 zero = { 0,0,0 };
    glm::vec3 up_vector = { 0,1,0 };
    glm::mat4 V;
    glm::mat4 P;
    int w, h;
    std::tie(w, h) = frame_buffer_size();
    aspect_ = (float)w/h;
    fov_ = glm::pi<float>()/4.0;
    near_ = 0.1f;
    far_ = 100.0f;
    P_ = glm::perspective(fov_, aspect_, near_, far_); 
    V_ = glm::lookAt(camera_position, zero, up_vector);

    PVM = P_ * V_ * M;

    glm::mat4 T = glm::translate(PVM, glm::vec3(0, 0, 0));

    PVM = T;
    GLuint pvm_buffer_handle;
    OGL_CALL(glGenBuffers(1, &pvm_buffer_handle));
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, pvm_buffer_handle));
    OGL_CALL(glBufferData(GL_UNIFORM_BUFFER, 16 * sizeof(GLfloat), 0, GL_STATIC_DRAW));
    OGL_CALL(glBindBufferBase(GL_UNIFORM_BUFFER, 1, pvm_buffer_handle));
    OGL_CALL(glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(PVM), &PVM));
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, 0));

    GLuint m_buffer_handle;
    float strength = 0.5f;
    float color[3] = { 1,0,0 };
    OGL_CALL(glGenBuffers(1, &m_buffer_handle));
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_handle));
    OGL_CALL(glBufferData(GL_UNIFORM_BUFFER, 8 * sizeof(GLfloat), 0, GL_STATIC_DRAW));
    OGL_CALL(glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_buffer_handle));
    OGL_CALL(glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(strength), &strength));
    OGL_CALL(glBufferSubData(GL_UNIFORM_BUFFER, 4 * sizeof(float), sizeof(color), color));
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, 0));

    GLuint v_buffer_handle;
    OGL_CALL(glGenBuffers(1, &v_buffer_handle));
    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle));
    OGL_CALL(glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW));
    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));

    GLuint i_buffer_handle;
    OGL_CALL(glGenBuffers(1, &i_buffer_handle));
    OGL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle));
    OGL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLshort), indices.data(), GL_STATIC_DRAW));
    OGL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

    OGL_CALL(glGenVertexArrays(1, &vao_));
    OGL_CALL(glBindVertexArray(vao_));
    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle));
    OGL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle));

    OGL_CALL(glEnableVertexAttribArray(0));
    OGL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
        reinterpret_cast<GLvoid*>(0)));

    // <FOR COLOR> <NOT NEEDED NOW>
    OGL_CALL(glEnableVertexAttribArray(1));
    OGL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
        reinterpret_cast<GLvoid*>(3 * sizeof(GLfloat))));

    OGL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
    OGL_CALL(glBindVertexArray(0));

    OGL_CALL(glClearColor(0.81f, 0.81f, 0.8f, 1.0f));

    OGL_CALL(glViewport(0, 0, w, h));

    OGL_CALL(glUseProgram(program));
    GLuint modIndex = glGetUniformBlockIndex(program, "Modifier");
glUniformBlockBinding(program, modIndex, 0);

GLuint transIndex = glGetUniformBlockIndex(program, "Transformations");
glUniformBlockBinding(program, transIndex, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    
}

void SimpleShapeApplication::frame() {
    auto PVM = P_ * V_;
    glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    OGL_CALL(glBindVertexArray(vao_));
    OGL_CALL(glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0));
    OGL_CALL(glBindVertexArray(0)); 
}

void SimpleShapeApplication::framebuffer_resize_callback(int w, int h) {
    Application::framebuffer_resize_callback(w, h);
    glViewport(0,0,w,h); 
    aspect_ = (float) w / h;
    P_ = glm::perspective(fov_, aspect_, near_, far_);
}
