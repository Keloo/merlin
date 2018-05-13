#include "Component/Camera/Camera.hpp"

namespace Component { namespace Camera {
    Camera::Camera(){};
    Camera::~Camera(){};

    glm::vec3 Camera::getPosition() { return position; }
    void Camera::setPosition(glm::vec3 p) { position = p; }

    glm::vec3 Camera::getFocalPoint() { return focalPoint; }
    void Camera::setFocalPoint(glm::vec3 f) { focalPoint = f; }
}}