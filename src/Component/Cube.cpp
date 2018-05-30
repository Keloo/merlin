#include "Cube.hpp"

#include "math.h"

namespace Component {
    Cube::Cube(Object *object): object(object) {}

    Object *Cube::getObject() const {
        return object;
    }

    void Cube::setObject(Object *object) {
        Cube::object = object;
    }

    const glm::vec3 &Cube::getPosition() const {
        return position;
    }

    void Cube::setPosition(const glm::vec3 &position) {
        Cube::position = position;
    }

    const glm::vec3 &Cube::getVelocity() const {
        return velocity;
    }

    void Cube::setVelocity(const glm::vec3 &velocity) {
        Cube::velocity = velocity;
    }

    float Cube::getMass() const {
        return mass;
    }

    void Cube::setMass(float mass) {
        Cube::mass = mass;
    }

    double Cube::distanceTo(glm::vec3 destination) {
        double rs =
                pow(position.x-destination.x,2) +
                pow(position.y-destination.y,2) +
                pow(position.z-destination.z,2);
        return pow(rs, 0.5f);
    }

    Cube::~Cube() = default;
}