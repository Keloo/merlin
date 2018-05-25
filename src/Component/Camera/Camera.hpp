#pragma once

#include "Event/EventListener.hpp"

#include "glm/vec3.hpp"

namespace Component { namespace Camera {
    class Camera: public Event::EventListener {
        public:
            Camera();
            ~Camera() override ;
            glm::vec3 getPosition();
            void setPosition(glm::vec3);

            glm::vec3 getFocalPoint();
            void setFocalPoint(glm::vec3);
        protected:
            glm::vec3 position;
            glm::vec3 focalPoint;
    };
}}