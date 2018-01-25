#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../glm/glm.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Light
 *
 *  a simple light represented by its position in world space and
 *  its intensity.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Light {
    glm::vec3 position;
    float intensity;
};

#endif
