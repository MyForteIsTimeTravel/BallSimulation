#ifndef GRAPHICSENGINE_HPP
#define GRAPHICSENGINE_HPP

#include "TriangleGeometry.hpp"
#include "SphereGeometry.hpp"
#include "GraphicsObject.hpp"
#include "PlaneGeometry.hpp"
#include "CubeGeometry.hpp"
#include "Camera.hpp"

#include <QGLShaderProgram>
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GraphicsEngine
 *
 *  Holds a collection of graphics objects representing a scene, in
 *  addition to a camera from which to render such a scene.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct GraphicsEngine {
    std::vector<GraphicsObject*> scene;
    Camera camera;
    int frame = 0;

    GraphicsEngine (int width, int height): camera (width, height) {}

    /**
     *  reset
     *
     *  clears the scene and resets the frame count to 0
     */
    void reset () {
        scene.clear();
        frame = 0;
    }

    /**
     *  render
     *
     *  renders the scene using the given shader
     *  for every object
     */
    void render (QGLShaderProgram *shader) {
        camera.update();
        shader->bind();
        for (GraphicsObject* object : scene)
            object->draw(shader->programId(), &camera);
        shader->release();
        frame++;
    }
};

#endif
