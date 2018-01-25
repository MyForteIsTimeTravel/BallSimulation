#ifndef GROUND_HPP
#define GROUND_HPP

#include "Graphics/PlaneGeometry.hpp"
#include "Physics/PlaneCollider.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Ground
 *
 *  representation of a ground plane in the graphics & physics engine
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Ground : public Object {
    Ground () {
        float scale = 10;

        graphics = new GraphicsObject(PlaneGeometry());
        graphics->scale = glm::vec3(scale, 1, scale);

        float xmin = graphics->geometry.vertices.front().position.x;
        float xmax = graphics->geometry.vertices.front().position.x;
        float zmin = graphics->geometry.vertices.front().position.z;
        float zmax = graphics->geometry.vertices.front().position.z;
        for (Vertex& v : graphics->geometry.vertices)
            {
            float x = v.position.x * scale;
            float z = v.position.z * scale;

            if (x > xmax) xmax = x;
            if (x < xmin) xmin = x;
            if (z > zmax) zmax = z;
            if (z < zmin) zmin = z;
            }

        physics = new PhysicsObject(new PlaneCollider(
            graphics->geometry.vertices[0].position,
            graphics->geometry.vertices[1].position,
            graphics->geometry.vertices[2].position,
            xmin, xmax, zmin, zmax
        ));

        physics->m = 0;
    }

   ~Ground () {
        delete graphics;
        delete physics;
    }
};

#endif // OBJECT_HPP
