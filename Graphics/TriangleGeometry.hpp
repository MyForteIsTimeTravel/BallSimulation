#ifndef TRIANGLEGEOMETRY_HPP
#define TRIANGLEGEOMETRY_HPP

#include "Geometry.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TriangleGeometry
 *
 *  generates an indexed triangle mesh
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct TriangleGeometry : public Geometry {
    TriangleGeometry() {
        vertices =
            {
            Vertex(Position (-0.5f, -0.5f, 0.0f), Colour (0.64f, 0.00f, 0.00f), Normal (0.0f, 0.0f, 1.0f), UV (0.0f, 0.0f)),
            Vertex(Position ( 0.0f,  0.5f, 0.0f), Colour (0.64f, 0.64f, 0.00f), Normal (0.0f, 0.0f, 1.0f), UV (0.5f, 1.0f)),
            Vertex(Position ( 0.5f, -0.5f, 0.0f), Colour (0.64f, 0.00f, 0.64f), Normal (0.0f, 0.0f, 1.0f), UV (1.0f, 0.0f))
            };

        indices =
            {
            0, 1, 2
            };

        init();
    }
};

#endif // TRIANGLEGEOMETRY_HPP
