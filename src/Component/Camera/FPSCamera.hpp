#pragma once

#include "Event/Event.hpp"

#include "Component/Camera/Camera.hpp"

#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Component { namespace Camera {
    class FPSCamera: public Camera {
        public:
            constexpr static double DEFAULT_YAW         = -90.0f;
            constexpr static double DEFUALT_PITCH       = 0.0f;
            constexpr static double DEFUALT_SPEED       = 2.5f;
            constexpr static double DEFUALT_SENSITIVITY = 0.1f;
            constexpr static double DEFUALT_ZOOM        = 45.0f;

            FPSCamera(glm::vec3, glm::vec3, double yaw, double pitch);
            ~FPSCamera() override ;

            glm::mat4 getViewMatrix();

            void onEvent(Event::Event*) override;
        private:
            double yaw;
            double pitch;
            double movementSpeed;
            double mouseSensitivity;
            double zoom;

            glm::vec3 frontVector;
            glm::vec3 upVector;
            glm::vec3 rightVector;
            glm::vec3 worldUpVector;

            void updateCameraVectors();
    };
}}