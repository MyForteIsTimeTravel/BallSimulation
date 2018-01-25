#ifndef BALL_HPP
#define BALL_HPP

#include "Graphics/SphereGeometry.hpp"
#include "Physics/SphereCollider.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Ball
 *
 *  representation of a ball in the graphics & physics engine
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Ball : public Object {
    Ball (float radius) {
        graphics = new GraphicsObject(SphereGeometry(radius));
        physics = new PhysicsObject(new SphereCollider(radius));
        physics->m = radius;
    }

    ~Ball () {
        delete graphics;
        delete physics;
    }
};

#endif
