#pragma once

#include "Event/EventListener.hpp"

#include "glm/vec3.hpp"

// @todo make it abstract
namespace Component { namespace Camera {
    enum Direction {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    constexpr static double DEFAULT_YAW         = -90.0f;
    constexpr static double DEFAULT_PITCH       = 0.0f;
    constexpr static double DEFAULT_SPEED       = 2.5f;
    constexpr static double DEFAULT_SENSITIVITY = 0.01f;
    constexpr static double DEFAULT_ZOOM        = 45.0f;

    class Camera {
    public:
        Camera();
        virtual ~Camera();
        glm::vec3 getPosition();
        void setPosition(glm::vec3);

        glm::vec3 getFocalPoint();
        void setFocalPoint(glm::vec3);

        void setMovementSpeed(double speed);
        double getMovementSpeed();
    protected:
        glm::vec3 position;
        glm::vec3 focalPoint;
        double movementSpeed;
    };
}}