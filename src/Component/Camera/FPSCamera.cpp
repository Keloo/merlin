#include "Event/Keyboard/PressEvent.hpp"

#include "Component/Camera/FPSCamera.hpp"

#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include <cmath>
#include <iostream>

namespace Component { namespace Camera {
    FPSCamera::FPSCamera(
        glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 _upVector = glm::vec3(0.0f, 1.0f, 0.0f),
        double _yaw = FPSCamera::DEFAULT_YAW,
        double _pitch = FPSCamera::DEFUALT_PITCH
    ) {
        position = _position;
        upVector = _upVector;
        yaw = _yaw;
        pitch = _pitch;
        updateCameraVectors();

        addListenEvent(Event::Keyboard::PressEvent::NAME);
    };

    FPSCamera::~FPSCamera() = default;

    glm::mat4 FPSCamera::getViewMatrix() {
        return glm::lookAt(position, position + frontVector, upVector);
    }

    void FPSCamera::updateCameraVectors() {
        glm::vec3 front;
        front.x = (float)cos(glm::radians(yaw)) * (float)cos(glm::radians(pitch));
        front.y = (float)sin(glm::radians(pitch));
        front.z = (float)sin(glm::radians(yaw)) * (float)cos(glm::radians(pitch));
        frontVector = glm::normalize(front);
        rightVector = glm::normalize(glm::cross(frontVector, worldUpVector));
        upVector    = glm::normalize(glm::cross(rightVector, frontVector));
    }

    void FPSCamera::onEvent(Event::Event *event) {
        std::cout << "in event fps camera";
    }
}}