#ifndef SCENE_HPP
#define SCENE_HPP

#include "../Objects/Object.hpp"
#include "../glm/vec3.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Scene
 *
 *  Abstract representation of a scene with a collection of forces
 *  and objects upon which these forces will act.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Scene {
    std::vector<glm::vec3> forces;
    std::vector<Object*> objects;
};

#endif
