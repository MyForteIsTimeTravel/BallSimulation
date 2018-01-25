#ifndef GRAPHICSOBJECT_HPP
#define GRAPHICSOBJECT_HPP

#include "../glm/gtc/type_ptr.hpp"
#include "Geometry.hpp"
#include "Camera.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GraphicsObject
 *
 *  holds a geometry and model space transforms for an object in
 *  a graphics scene, in addition to an int representing if the
 *  object is colliding with anything. Ideally this would be a bool
 *  but there is no uniform bool type for GLSL, therefore we'll have
 *  to waste the memory and use a full 32.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct GraphicsObject {
    GraphicsObject (Geometry _geometry):
        position (glm::vec3(0.0, 0.0, 0.0)),
        rotation (glm::vec3(0.0, 0.0, 0.0)), // replace with quat
        scale    (glm::vec3(1.0, 1.0, 1.0)),
        geometry (_geometry) {}
   ~GraphicsObject () { }

    glm::vec3 position;
    glm::vec3 rotation; // replace with quat
    glm::vec3 scale;

    int colliding = 0;

    Geometry geometry;

    /**
     *  draw
     *
     *  programID - the id of the shader program in use
     *  Camera    - a pointer to the camera/eye of the scene
     *
     *  passes relevant matrix data to the GLSL shader before calling
     *  the geometry's draw method to render the object
     */
    void draw (GLuint programID, Camera* camera) {
        // Transforms to GPU
        glm::mat4 proj = camera->getProjection();
        glm::mat4 view = camera->getView();
        glm::mat4 model = glm::mat4();
        model = glm::translate (model, position);
        model = glm::rotate    (model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
        model = glm::rotate    (model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
        model = glm::rotate    (model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
        model = glm::scale     (model, scale);
        glUniformMatrix4fv(glGetUniformLocation(programID,  "proj"), 1, GL_FALSE, glm::value_ptr(proj));
        glUniformMatrix4fv(glGetUniformLocation(programID,  "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(programID, "model"), 1, GL_FALSE, glm::value_ptr(model));

        // Light Data to GPU
        glm::vec3 viewPosition  = camera->position;
        glm::vec3 lightPosition = glm::vec3(0.0, 3, 3);
        glUniform3fv(glGetUniformLocation(programID, "viewPosition"), 1, glm::value_ptr(viewPosition));
        glUniform3fv(glGetUniformLocation(programID, "lightPosition"), 1, glm::value_ptr(lightPosition));

        // collision data to GPU
        glUniform1i(glGetUniformLocation(programID, "colliding"), colliding);

        // render
        geometry.draw();
    }
};

#endif
