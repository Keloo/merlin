#pragma once

#include "glm/vec3.hpp"

namespace Component { namespace Camera {
    class Camera {
        public:
            Camera();
            ~Camera();
            glm::vec3 getPosition();
            void setPosition(glm::vec3);

            glm::vec3 getFocalPoint();
            void setFocalPoint(glm::vec3);
        protected:
            glm::vec3 position;
            glm::vec3 focalPoint;
    };
}}