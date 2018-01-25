#ifndef MATH_HPP
#define MATH_HPP

#include "../glm/gtc/quaternion.hpp"
#include "../glm/gtx/quaternion.hpp"
#include "../glm/glm.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Math
 *
 *  convenient functions for quaternion rotations
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Math {

    /**
     *  rotateBetween
     *
     *  v1  - the starting vector of the desired rotation
     *  v2  - the finishing vector of the desired rotation
     */
    static glm::quat rotateBetween (glm::vec3 v1, glm::vec3 v2) {
        v1 = glm::normalize(v1);
        v2 = glm::normalize(v2);
        float th = glm::dot(v1, v2);
        if (th < -1 + 0.001f) return glm::quat();
        glm::vec3 axis = glm::cross(v1, v2);
        float s = sqrt((1 + th) * 2);
        float i = 1 / s;
        return glm::quat(s * 0.5f, axis * i);
    }
};

#endif
