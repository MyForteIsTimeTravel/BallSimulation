#ifndef CUBEGEOMETRY_HPP
#define CUBEGEOMETRY_HPP

#include "Geometry.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  CubeGeometry
 *
 *  indexed cube mesh
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct CubeGeometry : public Geometry {
    CubeGeometry() {
        vertices =
            {
            Vertex(Position (-0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f, -1.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f, -1.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f, -1.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f, -1.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f,  1.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f,  1.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f,  1.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  0.0f,  1.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal (-1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal (-1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal (-1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal (-1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 1.0f,  0.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f, -1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f, -1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f, -1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f, -0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f, -1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f, -0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position ( 0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  1.0f,  0.0f), UV(0.0, 0.0)),
            Vertex(Position (-0.5f,  0.5f,  0.5f), Colour (0.12f, 0.12f, 0.12f), Normal ( 0.0f,  1.0f,  0.0f), UV(0.0, 0.0))
            };

        indices =
            {
            0,   1,  2,  2,  3,  0,
            4,   5,  6,  6,  7,  4,
            8,   9, 10, 10, 11,  8,
            12, 13, 14, 14, 15, 12,
            16, 17, 18, 18, 19, 16,
            20, 12, 22, 22, 23, 20
            };

        init();
    }
};

#endif
