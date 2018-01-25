#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Graphics/GraphicsEngine.hpp"
#include "Graphics/GraphicsObject.hpp"
#include "Physics/PhysicsEngine.hpp"
#include "Physics/PhysicsObject.hpp"
#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Object
 *
 *  abstract representation of an object with a graphics and physics
 *  component
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Object {
    void init (GraphicsEngine* g, PhysicsEngine* p) {
        g->scene.push_back(graphics);
        p->scene.push_back(physics);
        physics->p = graphics->position;
    }

    void update () {
        graphics->position = physics->p;
        graphics->colliding = physics->collider->contacted;
    }

    GraphicsObject* graphics;
    PhysicsObject* physics;
};

#endif // OBJECT_HPP
