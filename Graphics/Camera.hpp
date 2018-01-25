#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/quaternion.hpp"
#include "../glm/gtc/functions.hpp"
#include "../glm/glm.hpp"
#include "Math.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Camera
 *
 *  very basic camera class with position and orientation control
 *  (ideally should use quaternions, but euler angles were quick
 *  to set up and rendering is not the aim of this assessment)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Camera {

    /**
     *  Camera
     *
     *  width   - horizontal size of the GL context
     *  height  - vertical size of the GL context
     */
    Camera (int width, int height) {
        position = glm::vec3 (0.0f, 0.0f, 3.0f);
        rotation = glm::vec3 (-90.0f, 0.0f, 0.0f);

        relativeForward = glm::normalize(glm::vec3(position - glm::vec3(0, 0, 0)));
        worldUp         = glm::vec3(0.0f, 1.0f, 0.0f);
        relativeRight   = glm::normalize(glm::cross(relativeForward, worldUp));
        relativeUp      = glm::normalize(glm::cross(relativeRight, relativeForward));

        aspect   = width / height;
        near     = 0.01f;
        far      = 100.0f;

        proj = glm::perspective(45.0f, aspect, near, far);
        view = glm::lookAt(position, position + relativeForward, relativeUp);
    }

   ~Camera () {

    }

    glm::vec3 position;
    glm::vec3 rotation; // replace with Quat
    glm::vec3 relativeForward;
    glm::vec3 relativeUp;
    glm::vec3 relativeRight;
    glm::vec3 worldUp;
    GLfloat aspect;
    GLfloat near;
    GLfloat far;

    glm::mat4 proj;
    glm::mat4 view;

    /**
     *  methods to return view and projection matrices
     *  for passing to shaders
     */
    glm::mat4 getProjection () { return proj; }
    glm::mat4 getView () { return view; }

    /**
     *  update
     *
     *  update the relative vectors and the view matrix based on the
     *  current position and orientation
     */
    void update () {
        /*
        relativeForward = glm::normalize(glm::vec3(
              cos (glm::radians(rotation.x) * cos (glm::radians(rotation.y))), // x
              sin (glm::radians(rotation.y)),                                  // y
              sin (glm::radians(rotation.x) * cos (glm::radians(rotation.y)))  // z
        ));
        */

        relativeRight = glm::normalize(glm::cross(relativeForward, worldUp));
        relativeUp    = glm::normalize(glm::cross(relativeRight, relativeForward));
        view          = glm::lookAt(position, glm::vec3(0, 0, 0) - position, relativeUp);
    }
};

#endif
