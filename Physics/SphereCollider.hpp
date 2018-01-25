#ifndef SPHERECOLLIDER_HPP
#define SPHERECOLLIDER_HPP

#include "../glm/vec3.hpp"
#include "Collider.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SphereCollider
 *
 *  represents a spherical collision mesh
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct SphereCollider : public Collider {
    SphereCollider (float _r):
        Collider (Type::SPHERE),
        r (_r) {}
    float r; // radius
};

#endif // SPHERECOLLIDER_HPP
