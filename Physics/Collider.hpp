/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Colisions.hpp
 *  PhysicsEngine
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "../glm/vec3.hpp"

enum Type { SPHERE, PLANE };

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Collider
 *
 *  abstract representation of a collider with two possible
 *  implementations, sphere and plane
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Collider {
    Collider (Type t): type (t) {}
    glm::vec3 norm; // collision normal
    float displacement;
    int contacted = 0;
    glm::vec3 p;
    Type type;
};

#endif
