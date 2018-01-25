#ifndef PHYSICSENGINE_HPP
#define PHYSICSENGINE_HPP

#include "PhysicsObject.hpp"
#include "Collisions.hpp"
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PhysicsEngine
 *
 *  Holds a physics scene and handles updating the entities, as well
 *  as testing them for collisions and applying resolutions for said
 *  collisions.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct PhysicsEngine {
    std::vector<PhysicsObject*> scene;
    std::vector<glm::vec3> forces;
    float t = 0; // time

    /**
     *  reset
     *
     *  clears the scene and active forces data structures
     *  and resets the tick to 0;
     */
    void reset () {
        forces.clear();
        scene.clear();
        t = 0;
    }

    /**
     *  reset
     *
     *  clears the scene and active forces data structures
     *  and resets the tick to 0;
     */
    void simulate () {
        t += 0.0001;
        testCollisions();
        resolveCollisions();
        applyForces();
    }

    /**
     *  testCollisions
     *
     *  resets all colliders before testing them all against eachother
     */
    void testCollisions () {
        for (int i = 0; i < scene.size(); ++i) {
            scene[i]->collider->norm = glm::vec3(1.0, 1.0, 1.0);
            scene[i]->collider->contacted = 0;
        }

        // not optimal, could be improved as some tests are repeated
        for (int i = 0; i < scene.size(); ++i)
            for (int j = 0; j < scene.size(); ++j)
                if (i != j) Collisions::test(scene[i]->collider, scene[j]->collider);
    }

    /**
     *  resolveCollisions
     *
     *  applies collision resolution to contacting colliders
     */
    void resolveCollisions () {
        for (int i = 0; i < scene.size(); ++i)
            if (scene[i]->collider->contacted) {
                scene[i]->p.y += scene[i]->collider->displacement;
                scene[i]->v *= scene[i]->collider->norm;
            }
    }

    /**
     *  applyForces
     *
     *  resets all colliders before testing them all against eachother
     */
    void applyForces () {
        for (PhysicsObject* object : scene) {
            for (glm::vec3& f : forces) object->fs.push_back(f);
            object->update(t);
        }
    }
};

#endif
