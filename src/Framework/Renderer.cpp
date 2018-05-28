#include "Component/Exception.hpp"

#include "Framework/Renderer.hpp"
#include "Framework/GLDebug.hpp"
#include "Framework/Shader.hpp"
#include "Framework/VertexArray.hpp"
#include "Framework/IndexBuffer.hpp"

#include <iostream>
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Component/Camera/FPSCamera.hpp>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.hpp"

namespace Framework {
    Renderer::Renderer(): drawMode(Renderer::DrawMode::Triangle) {
        init();
        glProgramId = glCreateProgram();
    };

    Renderer::~Renderer(){};

    void Renderer::init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            throw new Component::Exception("Failed to initialize GLAD");
        }
    }

    unsigned int Renderer::getGlProgramId() {
        return glProgramId;
    }

    void Renderer::attachShader(Shader* shader) const {
        GLCall(glAttachShader(glProgramId, (*shader).getId()));
    }

    void Renderer::link() const {
        GLCall(glLinkProgram(glProgramId));
    }

    void Renderer::clear() const {
        GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    }

    Renderer::DrawMode Renderer::getDrawMode() {
        return drawMode;
    }

    void Renderer::setDrawMode(DrawMode d) {
        drawMode = d;
    }

    unsigned int Renderer::getGlDrawMode() {
        switch (drawMode) {
            case Renderer::DrawMode::Triangle:  return GL_TRIANGLES;
            case Renderer::DrawMode::Line:      return GL_LINES;
        }
    }

    //@todo remove camera from here
    void Renderer::draw(Framework::Window *window, Component::Camera::FPSCamera* camera, VertexArray *vertexArray, IndexBuffer *indexBuffer) {
        GLCall(glUseProgram(glProgramId));

        (*vertexArray).bind();
        (*indexBuffer).bind();

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.1f, 100.0f);

        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));

        glm::mat4 view = (*camera).getViewMatrix();

        GLCall(glUniformMatrix4fv(
                glGetUniformLocation(getGlProgramId(), "projection"),
                1,
                GL_FALSE,
                &projection[0][0]
        ));

        GLCall(glUniformMatrix4fv(
                glGetUniformLocation(glProgramId, "model"),
                1,
                GL_FALSE,
                &model[0][0]
        ));

        GLCall(glUniformMatrix4fv(
                glGetUniformLocation(glProgramId, "view"),
                1,
                GL_FALSE,
                &view[0][0]
        ))

        GLCall(glDrawElements(getGlDrawMode(), (*indexBuffer).getCount(), GL_UNSIGNED_INT, nullptr));
    }
}