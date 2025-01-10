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
    V = glm::lookAt(camera_position, zero, up_vector);
    P = glm::perspective(1.0 * glm::radians(90.0f), 1.0 * frame_buffer_size().first / frame_buffer_size().second, 0.1, 20.0);

    PVM = P * V * M;

    glm::mat4 T = glm::translate(PVM, glm::vec3(0, 0, 0));

    PVM = T;
    GLuint pvm_buffer_handle;
    glGenBuffers(1, &pvm_buffer_handle);
    glBindBuffer(GL_UNIFORM_BUFFER, pvm_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, 16 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, pvm_buffer_handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(PVM), &PVM);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    GLuint m_buffer_handle;
    float strength = 0.5f;
    float color[3] = { 1,0,0 };
    glGenBuffers(1, &m_buffer_handle);
    glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_handle);
    glBufferData(GL_UNIFORM_BUFFER, 8 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, m_buffer_handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(strength), &strength);
    glBufferSubData(GL_UNIFORM_BUFFER, 4 * sizeof(float), sizeof(color), color);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    GLuint v_buffer_handle;
    glGenBuffers(1, &v_buffer_handle);
    glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint i_buffer_handle;
    glGenBuffers(1, &i_buffer_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLshort), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, v_buffer_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buffer_handle);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
        reinterpret_cast<GLvoid*>(0));

    // <FOR COLOR> <NOT NEEDED NOW>
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
        reinterpret_cast<GLvoid*>(3 * sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glClearColor(0.81f, 0.81f, 0.8f, 1.0f);

    auto [w, h] = frame_buffer_size();
    glViewport(0, 0, w, h);

    glUseProgram(program);
    GLuint modIndex = glGetUniformBlockIndex(program, "Modifier");
        glUniformBlockBinding(program, modIndex, 0);

    GLuint transIndex = glGetUniformBlockIndex(program, "Transformations");
        glUniformBlockBinding(program, transIndex, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void SimpleShapeApplication::frame() {
    glBindVertexArray(vao_);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}