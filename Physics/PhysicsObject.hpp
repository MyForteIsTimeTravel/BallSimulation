/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsObject.hpp
 *  PhysicsEngine
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PHYSICSOBJECT_HPP
#define PHYSICSOBJECT_HPP

#include "../glm/vec3.hpp"
#include "Collider.hpp"
#include <algorithm>
#include <queue>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  State
 *
 *  Holds a snapshot of the entities state
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct State {
    State (glm::vec3 _p, glm::vec3 _v, glm::vec3 _a):
        p (_p),
        v (_v),
        a (_a) {}
    glm::vec3 p;
    glm::vec3 v;
    glm::vec3 a;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsObject
 *
 *  represents an entity in the simulation and provides methods for
 *  updating said entity
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct PhysicsObject {
    PhysicsObject (Collider* _collider): collider (_collider) {}
   ~PhysicsObject () { delete collider; }

    glm::vec3 p; // positionition
    glm::vec3 v; // velocity
    glm::vec3 a; // acceleration
    float   dmp; // dampening
    float     m; // newtonian mass

    std::vector<glm::vec3> fs; // forces
    std::vector<glm::vec3> is; // impulses
    std::vector<State>   past; // history of states
    int n = 10;                // number of states to store

    Collider* collider;

    /**
     *  update
     *
     *  t - time to step by
     *
     *  updates the entity by the given timestep
     */
    void update (const float t) {
        if (!(m <= 0.0))  {
            glm::vec3 f = std::accumulate(fs.begin(), fs.end(), glm::vec3(0, 0, 0));
            glm::vec3 i = std::accumulate(is.begin(), is.end(), glm::vec3(1, 1, 1));
            a  = f / m;
            v += a * t;
            v *= i;
            p += v * t;
        }

        collider->p = p;
        fs.clear();
        is.clear();
    }
};

#endif
