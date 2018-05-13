#include "Component/Camera/FPSCamera.hpp"

#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include <math.h>

namespace Component { namespace Camera {
    FPSCamera::FPSCamera(
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), 
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
        float _yaw = FPSCamera::DEFAULT_YAW,
        float _pitch = FPSCamera::DEFUALT_PITCH
    ) {
        position = pos;
        upVector = up;
        yaw = _yaw;
        pitch = _pitch;
        updateCameraVectors();
    };

    FPSCamera::~FPSCamera(){};

    glm::mat4 FPSCamera::getViewMatrix() {
        return glm::lookAt(position, position + frontVector, upVector);
    }

    void FPSCamera::updateCameraVectors() {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        frontVector = glm::normalize(front);
        rightVector = glm::normalize(glm::cross(frontVector, worldUpVector));
        upVector    = glm::normalize(glm::cross(rightVector, frontVector));
    }
}}