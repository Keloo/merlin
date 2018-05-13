#pragma once

#include "Event/Event.hpp"

#include "Component/Camera/Camera.hpp"

#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Component { namespace Camera {
    class FPSCamera: public Camera {
        public:
            constexpr static float DEFAULT_YAW         = -90.0f;
            constexpr static float DEFUALT_PITCH       = 0.0f;
            constexpr static float DEFUALT_SPEED       = 2.5f;
            constexpr static float DEFUALT_SENSITIVITY = 0.1f;
            constexpr static float DEFUALT_ZOOM        = 45.0f;

            FPSCamera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
            ~FPSCamera();

            glm::mat4 getViewMatrix();

            virtual void onEvent(Event::Event*) = 0;
        private:
            float yaw;
            float pitch;
            float movementSpeed;
            float mouseSensitivity;
            float zoom;

            glm::vec3 frontVector;
            glm::vec3 upVector;
            glm::vec3 rightVector;
            glm::vec3 worldUpVector;

            void updateCameraVectors();
    };
}}