#ifndef PLANEGEOMETRY_HPP
#define PLANEGEOMETRY_HPP

#include "Geometry.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlaneGeometry
 *
 *  indexed plane mesh with a back and sides to look like a
 *  stand/podium
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct PlaneGeometry : public Geometry {
    PlaneGeometry() {
        vertices =
            {
            Vertex(Position (-0.5f, 0, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (0.0f, 0.0f)),
            Vertex(Position ( 0.5f, 0,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (0.5f, 1.0f)),
            Vertex(Position ( 0.5f, 0, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (1.0f, 0.0f)),
            Vertex(Position (-0.5f, 0,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (1.0f, 0.0f)),

            Vertex(Position (-0.5f, -1000.f, 0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, -1.0f), UV (0.0f, 0.0f)),
            Vertex(Position ( 0.5f,  0.0f, 0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, -1.0f), UV (0.5f, 1.0f)),
            Vertex(Position ( 0.5f, -1000.f, 0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, -1.0f), UV (1.0f, 0.0f)),
            Vertex(Position (-0.5f,  0.0f, 0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, -1.0f), UV (1.0f, 0.0f)),

            Vertex(Position (-0.5f, -1000.f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, 1.0f), UV (0.0f, 0.0f)),
            Vertex(Position ( 0.5f,  0.0f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, 1.0f), UV (0.5f, 1.0f)),
            Vertex(Position ( 0.5f, -1000.f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, 1.0f), UV (1.0f, 0.0f)),
            Vertex(Position (-0.5f,  0.0f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 0.0f, 1.0f), UV (1.0f, 0.0f)),

            Vertex(Position (-0.5f, -10, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, -1.0f, 0.0f), UV (0.0f, 0.0f)),
            Vertex(Position ( 0.5f, -10,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, -1.0f, 0.0f), UV (0.5f, 1.0f)),
            Vertex(Position ( 0.5f, -10, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, -1.0f, 0.0f), UV (1.0f, 0.0f)),
            Vertex(Position (-0.5f, -10,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, -1.0f, 0.0f), UV (1.0f, 0.0f)),

            // normals reversed on purpose
            Vertex(Position (0.5f, -1000.f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (-1.0f, 0.0f, 0.0f), UV (0.0f, 0.0f)),
            Vertex(Position (0.5f,  0.0f,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (-1.0f, 0.0f, 0.0f), UV (0.5f, 1.0f)),
            Vertex(Position (0.5f, -1000.f,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (-1.0f, 0.0f, 0.0f), UV (1.0f, 0.0f)),
            Vertex(Position (0.5f,  0.0f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (-1.0f, 0.0f, 0.0f), UV (1.0f, 0.0f)),

            // normals reversed on purpose
            Vertex(Position (-0.5f, -1000.f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (1.0f, 0.0f, 0.0f), UV (0.0f, 0.0f)),
            Vertex(Position (-0.5f,  0.0f,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (1.0f, 0.0f, 0.0f), UV (0.5f, 1.0f)),
            Vertex(Position (-0.5f, -1000.f,  0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (1.0f, 0.0f, 0.0f), UV (1.0f, 0.0f)),
            Vertex(Position (-0.5f,  0.0f, -0.5f), Colour (0.64f, 0.64f, 0.64f), Normal (1.0f, 0.0f, 0.0f), UV (1.0f, 0.0f))
            };

        indices =
            {
            0, 1, 2, 1, 0, 3,
            4, 5, 6, 5, 4, 7,
            8, 9, 10, 9, 8, 11,
            12, 13, 14, 13, 12, 15,
            16, 17, 18, 17, 16, 19,
            20, 21, 22, 21, 20, 23
            };

        init();
    }
};

#endif
