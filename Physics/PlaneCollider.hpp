#ifndef PLANECOLLIDER_HPP
#define PLANECOLLIDER_HPP

#include "../glm/vec3.hpp"
#include "Collider.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlaneCollider
 *
 *  represents a plane collision mesh
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct PlaneCollider : public Collider {
    PlaneCollider (glm::vec3 a, glm::vec3 b, glm::vec3 c, float _xMin, float _xMax, float _zMin, float _zMax):
        Collider (Type::PLANE),
        o (a),
        u (b - a),
        v (c - a),
        n (glm::cross(u, v)),
        xMin (_xMin),
        xMax (_xMax),
        zMin (_zMin),
        zMax (_zMax) {
    }

    glm::vec3 o; // origin
    glm::vec3 u; // forward
    glm::vec3 v; // left
    glm::vec3 n; // up / normal

    float xMin; // minimum extents on the X axis
    float xMax; // maximum extents on the X axis
    float zMin; // minimum extents on the Z axis
    float zMax; // maximum extents on the Z axis
};

#endif
