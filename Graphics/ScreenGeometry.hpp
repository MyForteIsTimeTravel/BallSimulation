#ifndef SCREENGEOMETRY_HPP
#define SCREENGEOMETRY_HPP

#include "Geometry.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ScreenGeometry
 *
 *  indexed quad mesh to render the scene to in post-processing
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct ScreenGeometry : public Geometry {
    ScreenGeometry() {
        vertices =
            {
            Vertex(Position (-0.5f,  -0.5f, 0.0f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (0.0f, 0.0f)),
            Vertex(Position (-0.5f,   0.5f, 0.0f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (0.0f, 1.0f)),
            Vertex(Position ( 0.5f,  -0.5f, 0.0f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (1.0f, 0.0f)),
            Vertex(Position ( 0.5f,   0.5f, 0.0f), Colour (0.64f, 0.64f, 0.64f), Normal (0.0f, 1.0f, 0.0f), UV (1.0f, 1.0f)),
            };

        indices =
            {
            0, 1, 2,
            2, 1, 3
            };

        init();
    }
};

#endif // ScreenGEOMETRY_HPP
