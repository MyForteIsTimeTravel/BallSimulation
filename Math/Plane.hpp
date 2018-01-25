#ifndef PLANE_HPP
#define PLANE_HPP

#include "../glm/vec3.hpp"

struct Plane {
    glm::vec3 o; // origin in world space
    glm::vec3 u; // forward
    glm::vec3 v; // left
    glm::vec3 n; // up / surface normal

    /** construct a plane given a triangle's vertices */
    Plane (glm::vec3 a, glm::vec3 b, glm::vec3 c):
        o (a), u (b - a), v (c - a), n (glm::cross(u, v)) {}
    /** construct a plane given a plane collider's values */
    Plane (glm::vec3 _o, glm::vec3 _u, glm::vec3 _v, glm::vec3 _n):
        o (_o), u (_u), v (_v), n (_n) {}
};

#endif /* Plane_h */
