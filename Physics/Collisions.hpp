/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Colisions.hpp
 *  PhysicsEngine
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "SphereCollider.hpp"
#include "PlaneCollider.hpp"
#include "../Math/Plane.hpp"
#include "../Math/Ray.hpp"
#include "../glm/vec3.hpp"
#include <iostream>
#include <cmath>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Collisions
 *
 *  namespace holding static methods for testing various colliders
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Collisions {

    /**
     *  test
     *
     *  a   - pointer to the first body in the collision
     *  b   - pointer to the second body in the collision
     *
     *  delegates the the appropriate test based on the type of the
     *  two bodies.
     */
    static void test (Collider* a, Collider* b) {
        if (a->type == Type::SPHERE) {
            if (b->type == Type::SPHERE) test (static_cast<SphereCollider*>(a), static_cast<SphereCollider*>(b));
            if (b->type ==  Type::PLANE) test (static_cast<SphereCollider*>(a), static_cast<PlaneCollider*>(b));
        }

        if (a->type == Type::PLANE) {
            if (b->type == Type::SPHERE) test (static_cast<SphereCollider*>(b), static_cast<PlaneCollider*>(a));
            if (b->type ==  Type::PLANE) test (static_cast<PlaneCollider*>(a), static_cast<PlaneCollider*>(b));
        }
    }

private:

    /**
     *  test
     *
     *  a   - pointer to the first body in the collision
     *  b   - pointer to the second body in the collision
     *
     *  tests two sphere colliders against eachother for collisions,
     *  setting the colliders state based on the outcome
     */
    static void test (SphereCollider* a, SphereCollider* b) {
        glm::vec3 center1 = a->p;
        float radius1 = a->r;

        glm::vec3 center2 = b->p;
        float radius2 = b->r;

        float minDist = radius1 + radius2;
        float dist = glm::length(a->p - b->p);

        if (dist < minDist) {
            a->norm = b->p - a->p;
            b->norm = a->p - b->p;

            a->contacted = 1;
            b->contacted = 1;
        }
    }

    /**
     *  test
     *
     *  a   - pointer to the first body in the collision
     *  b   - pointer to the second body in the collision
     *
     *  tests a sphere and a plane against eachother for collisions,
     *  setting the colliders state based on the outcome
     */
    static void test (SphereCollider* a, PlaneCollider* b) {
        float distY = fabs(a->p.y - b->p.y);
        float rad = a->r;

        if (a->p.x-a->r > b->xMin && a->p.x+a->r < b->xMax)
            if (a->p.z-a->r > b->zMin && a->p.z+a->r < b->zMax)
                if (distY < rad) {
                    a->norm = glm::vec3(1.0, -0.9, 1.0);
                    a->displacement = rad - distY;
                    a->contacted = 1;
                }
    }
};

#endif
