#pragma once

#include "Event/Event.hpp"

#include "Component/Camera/Camera.hpp"

#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Component { namespace Camera {
    class FPSCamera: public Camera {
    public:
        explicit FPSCamera(
            glm::vec3 _position = glm::vec3(0.0f, 0.0f, 10.0f),
            glm::vec3 _upVector = glm::vec3(0.0f, 1.0f, 0.0f),
            double _yaw = DEFAULT_YAW,
            double _pitch = DEFAULT_PITCH
        );

        ~FPSCamera() override;

        glm::vec3 getFrontVector();
        void setFrontVector(const glm::vec3 &frontVector);

        glm::vec3 getRightVector();
        void setRightVector(const glm::vec3 &rightVector);

        glm::mat4 getViewMatrix();

        double getMouseSensitivity() const;
        void setMouseSensitivity(double mouseSensitivity);

        double getYaw() const;

        void setYaw(double yaw);

        double getPitch() const;

        void setPitch(double pitch);

        void updateCameraVectors();
    private:
        double yaw;
        double pitch;
        double mouseSensitivity;
        double zoom;

        glm::vec3 frontVector;
        glm::vec3 upVector;
        glm::vec3 rightVector;
        glm::vec3 worldUpVector;
    };
}}