#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "../glm/vec3.hpp"
#include "../glm/vec2.hpp"

typedef glm::vec3 Position;
typedef glm::vec3 Colour;
typedef glm::vec3 Normal;
typedef glm::vec2 UV;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Vertex
 *
 *  Reperesents a single vertex for passing to the graphics card. A
 *  vertex consists of a position, colour, normal and uv (texture
 *  coordinate)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Vertex {
    glm::vec3 position;
    glm::vec3 colour;
    glm::vec3 normal;
    glm::vec2 uv;

    Vertex (glm::vec3 _position,
            glm::vec3 _colour,
            glm::vec3 _normal,
            glm::vec2 _uv):
        position (_position),
        colour   (_colour),
        normal   (_normal),
        uv       (_uv) {}
    Vertex (glm::vec3 _position,
            glm::vec3 _colour):
        position (_position),
        colour   (_colour),
        normal   (glm::vec3(0.0, 0.0, 0.0)),
        uv       (glm::vec2(0.0, 0.0)) {}
};

#endif // VERTEX_HPP
