#pragma once

#include <glm/vec3.hpp>
#include <vector>

namespace Component {
    class Object {
    public:
        Object();
        ~Object();

        const std::vector<float> &getGlVertex() const;
        void setGlVertex(const std::vector<float> &glVertex);

        const std::vector<unsigned int> &getGlIndices() const;
        void setGlIndices(const std::vector<unsigned int> &glIndices);

    private:
        std::vector<float> glVertex;
        std::vector<unsigned int> glIndices;
    };
}