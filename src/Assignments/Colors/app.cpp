//
// Created by pbialas on 25.09.2020.
//

#include "app.h"

#include <iostream>
#include <vector>
#include <tuple>

#include "Application/utils.h"

#include "glm/gtc/constants.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "spdlog/spdlog.h"
#include "XeEngine/ColorMaterial.h"

#define STB_IMAGE_IMPLEMENTATION 1

#include "3rdParty/stb/stb_image.h"

void SimpleShapeApplication::init() {
	// A utility function that reads the shader sources, compiles them and creates the program object
	// As everything in OpenGL we reference program by an integer "handle".
	auto program = xe::utils::create_program(
		{ {GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
		 {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"} });

	if (!program) {
		std::cerr << "Invalid program" << std::endl;
		exit(-1);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	std::vector<GLushort> indices = {
		0, 1, 2,  // first base triangle
		0, 2, 3,
		0, 5, 1,  // first wall triangle
		0, 5, 4,
		1, 6, 2,  // second wall triangle
		1, 6, 5,
		2, 13, 3,  // third wall triangle, double vertices for consitent color
		2, 13, 12,
		0, 7, 3,  // fourth wall triangle
		0, 7, 4,
		5, 4, 8,  // first (front) side triangle
		4, 7, 9,
		7, 6, 10,
		6, 5, 11,
	};

	// A vector containing the x,y,z vertex coordinates + texture coords
	std::vector<GLfloat> vertices = {
		0.5f, -1.0f, 0.5f,
		0.f, 0.f, 0.f,

		-0.5f, -1.0f, 0.5f,
		0.f, 0.f, 0.f,

		-0.5f, -1.0f, -0.5f,
		0.f, 1.f, 0.f,

		0.5f, -1.0f, -0.5f,
		0.f, 1.f, 0.f,

		0.5f, -0.5f, 0.5f,
		0.f, 0.f, 0.f,

		-0.5f, -0.5f, 0.5f,
		0.f, 0.f, 0.f,

		-0.5f, -0.5f, -0.5f,
		1.f, 0.f, 0.f,

		0.5f, -0.5f, -0.5f,
		1.f, 0.f, 0.f,

		0.0f, 0.5f, 0.0f,
		0.f, 0.f, 0.f,

		0.0f, 0.5f, 0.0f,
		0.f, 0.f, 0.f,

		0.0f, 0.5f, 0.0f,
		1.f, 0.f, 0.f,

		0.0f, 0.5f, 0.0f,
		0.f, 0.f, 0.f,

		-0.5f, -0.5f, -0.5f,
		0.f, 1.f, 0.f,

		0.5f, -0.5f, -0.5f,
		0.f, 1.f, 0.f,
	};

	// PVM uniform

#if __APPLE__
	auto u_modifiers_index = glGetUniformBlockIndex(program, "Modifiers");
	if (u_modifiers_index == -1) {
		std::cerr << "Cannot find Modifiers uniform block in program" << std::endl;
	}
	else {
		glUniformBlockBinding(program, u_modifiers_index, 0);
	}
#endif

	glGenBuffers(1, &u_pvm_buffer_);
	OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_));
	glBufferData(GL_UNIFORM_BUFFER, 16 * sizeof(float), 0, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, 1, u_pvm_buffer_);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	set_camera(new Camera);

	camera()->look_at(
		glm::vec3(0, 1, 1),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	int w, h;
	std::tie(w, h) = frame_buffer_size();
	camera()->perspective(glm::pi<float>() / 2.0, (float)w / h, 0.1f, 100.f);

	set_controler(new CameraControler(camera()));

	// loading texture
	stbi_set_flip_vertically_on_load(true);
	GLint width, height, channels;
	auto texture_file = std::string(ROOT_DIR) + "/Models/multicolor.png";
	auto img = stbi_load(texture_file.c_str(), &width, &height, &channels, 0);
	if (!img) {
		spdlog::warn("Could not read image from file `{}'", texture_file);
	}

	GLuint texture_handle;
	glGenTextures(1, &texture_handle);
	glBindTexture(GL_TEXTURE_2D, texture_handle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(img);

	// applying colours/texture
	xe::ColorMaterial::set_shader(program);
	xe::ColorMaterial::init();

	auto pyramid = new xe::Mesh;

	size_t indices_sizeof = sizeof(indices[0]) * indices.size();
	pyramid->allocate_index_buffer(indices_sizeof, GL_STATIC_DRAW);
	pyramid->load_indices(0, indices_sizeof, indices.data());

	size_t vertices_sizeof = sizeof(vertices[0]) * vertices.size();
	pyramid->allocate_vertex_buffer(vertices_sizeof, GL_STATIC_DRAW);
	pyramid->load_vertices(0, vertices_sizeof, vertices.data());

	pyramid->vertex_attrib_pointer(0, 3, GL_FLOAT, 6 * sizeof(vertices[0]), 0);
	pyramid->vertex_attrib_pointer(1, 3, GL_FLOAT, 6 * sizeof(vertices[0]), 3 * sizeof(GLfloat));

	// Colours based on pyramid from CameraMovement assignment, not Textures (pink > grey)
	pyramid->add_submesh(0, 6);  // base == 2 triangles == 6 vertices
	pyramid->add_submesh(6, 12);  // wall == 2 triangles == 6 vertices
	pyramid->add_submesh(12, 18);
	pyramid->add_submesh(18, 24);
	pyramid->add_submesh(24, 30);
	pyramid->add_submesh(30, 33);  // side == 1 triangle == 3 vertices
	pyramid->add_submesh(33, 36);
	pyramid->add_submesh(36, 39);
	pyramid->add_submesh(39, 42);

	// Using texture
	// for (int i = 0; i < indices.size(); i += 3)
	// {
	//     pyramid->add_submesh(i, i+3, new xe::ColorMaterial(glm::vec4(1.f), texture_handle));
	// }

	add_submesh(pyramid);

	// Setting the background color of the rendering window,
	// I suggest not to use white or black for better debuging.
	glClearColor(0.81f, 0.81f, 0.8f, 1.0f);

	// This setups an OpenGL vieport of the size of the whole rendering window.
	glViewport(0, 0, w, h);

	glUseProgram(program);
}

//This functions is called every frame and does the actual rendering.
void SimpleShapeApplication::frame() {
	auto PVM = camera()->projection() * camera()->view();
	glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
