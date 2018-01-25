#ifndef RAY_HPP
#define RAY_HPP

#include "../glm/vec3.hpp"
#include "Plane.hpp"

struct Ray {
    glm::vec3 q;              // origin position
    glm::vec3 w;              // direction vector
    float t (Plane p)         // distance to a point along the line
        { return glm::dot(p.n, (p.o - q)) / glm::dot(p.n, w); }
    glm::vec3 intersect (Plane p) // point of intersection with a given plane
        { return q + (w * t(p)); }

    /** Construct a ray with the given origin and direction */
    Ray (glm::vec3 from, glm::vec3 to):
        q (from), w (glm::normalize(to - from)) {}
};


#endif /* Ray_h */
