#include "Event/Keyboard/PressEvent.hpp"

#include "Component/Camera/FPSCamera.hpp"

#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include <cmath>
#include <iostream>

namespace Component { namespace Camera {
    FPSCamera::FPSCamera(glm::vec3 _position, glm::vec3 _upVector, double _yaw, double _pitch) {
        position = _position;
        worldUpVector = _upVector;
        frontVector = glm::vec3(0.0f, 0.0f, -1.0f);
        yaw = _yaw;
        pitch = _pitch;
        movementSpeed = DEFAULT_SPEED;
        mouseSensitivity = DEFAULT_SENSITIVITY;
        zoom = DEFAULT_ZOOM;
        updateCameraVectors();
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

    glm::vec3 FPSCamera::getFrontVector() {
        return frontVector;
    }

    glm::vec3 FPSCamera::getRightVector() {
        return rightVector;
    }
    void FPSCamera::setRightVector(const glm::vec3 & rightVector) {
        FPSCamera::rightVector = rightVector;
    }


    void FPSCamera::setFrontVector(const glm::vec3 &frontVector) {
        FPSCamera::frontVector = frontVector;
    }
}}