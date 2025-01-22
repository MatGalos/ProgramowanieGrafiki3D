//
// Created by pbialas on 25.09.2020.
//

#include "app.h"
#include <vector>
#include "spdlog/spdlog.h"
#include "glad/gl.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Application/utils.h"
#include "Engine/Mesh.h"
#include "Engine/Material.h"

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

    xe::ColorMaterial::init();

    set_camera(new Camera);
    set_controler(new CameraControler(camera()));

    auto pyramid = new xe::Mesh;

    std::vector<GLshort> indices = {
        0, 1, 2,
        1, 3, 2,
        4, 6, 5,
        7, 9, 8,
        10, 11, 12,
        13, 14, 15
    };
    std::vector<GLfloat> vertices = {
         1,  1,  0,
         1, -1,  0,
        -1,  1,  0,
        -1, -1,  0,
         1, -1,  0,
        -1, -1,  0,
         0,  0,  1,
         1,  1,  0,
         1, -1,  0,
         0,  0,  1,
         1,  1,  0,
        -1,  1,  0,
         0,  0,  1,
        -1,  1,  0,
        -1, -1,  0,
         0,  0,  1,
    };

    glm::vec3 camera_position = { 0,0,3 };
    glm::vec3 zero = { 0,0,0 };
    glm::vec3 up_vector = { 0,1,0 };
    int w, h;
    std::tie(w, h) = frame_buffer_size();
    float aspect = (float)w / h;
    float fov = 1.0 * glm::radians(90.0f);
    float near = 0.1f;
    float far = 100.0f;
    std::tie(w, h) = frame_buffer_size();
    camera()->look_at(camera_position, zero, up_vector);
    camera()->perspective(fov, aspect, near, far);

    glGenBuffers(1, &u_pvm_buffer_);
    glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
    glBufferData(GL_UNIFORM_BUFFER, 16 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, u_pvm_buffer_);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    auto vertices_size = sizeof(vertices[0]) * vertices.size();
    pyramid->allocate_vertex_buffer(vertices_size, GL_STATIC_DRAW);
    pyramid->load_vertices(0, vertices_size, vertices.data());

    auto indices_size = sizeof(indices[0]) * indices.size();
    pyramid->allocate_index_buffer(indices_size, GL_STATIC_DRAW);
    pyramid->load_indices(0, indices_size, indices.data());

    pyramid->vertex_attrib_pointer(0, 3, GL_FLOAT, 3 * sizeof(GLfloat), 0);

    pyramid->add_submesh(0, 6, new xe::ColorMaterial(glm::vec4(glm::vec3(0.5, 0.5, 0.5), 1)));
    pyramid->add_submesh(6, 9, new xe::ColorMaterial(glm::vec4(glm::vec3(1, 0, 0), 1)));
    pyramid->add_submesh(9, 12, new xe::ColorMaterial(glm::vec4(glm::vec3(0, 1, 0), 1)));
    pyramid->add_submesh(12, 15, new xe::ColorMaterial(glm::vec4(glm::vec3(0, 0, 1), 1)));
    pyramid->add_submesh(15, 18, new xe::ColorMaterial(glm::vec4(glm::vec3(1, 1, 0), 1)));
    add_submesh(pyramid);
    glClearColor(0.81f, 0.81f, 0.8f, 1.0f);
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
    auto PVM = camera()->projection() * camera()->view();
    glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    for (auto m : meshes_)
        m->draw();
}

void SimpleShapeApplication::framebuffer_resize_callback(int w, int h) {
    Application::framebuffer_resize_callback(w, h);
    glViewport(0, 0, w, h);
    camera()->set_aspect((float)w / h);
}

void SimpleShapeApplication::mouse_button_callback(int button, int action, int mods) {
    Application::mouse_button_callback(button, action, mods);
    if (controler_) {
        double x, y;
        glfwGetCursorPos(window_, &x, &y);
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
            controler_->LMB_pressed(x, y);
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
            controler_->LMB_released(x, y);
    }
}

void SimpleShapeApplication::cursor_position_callback(double x, double y) {
    Application::cursor_position_callback(x, y);
    if (controler_) {
        controler_->mouse_moved(x, y);
    }
}