#pragma once

#include <glm/vec3.hpp>
#include "Object.hpp"

namespace Component {
    class Cube {
    public:
        Cube(Object*);
        ~Cube();

        Object *getObject() const;

        void setObject(Object *object);

        const glm::vec3 &getPosition() const;

        void setPosition(const glm::vec3 &position);

        const glm::vec3 &getVelocity() const;

        void setVelocity(const glm::vec3 &velocity);

        float getMass() const;

        void setMass(float mass);

        double distanceTo(glm::vec3);

    private:
        Object *object;
        glm::vec3 position;
        glm::vec3 velocity;
        float mass;
    };
}