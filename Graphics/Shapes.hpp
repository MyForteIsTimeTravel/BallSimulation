#ifndef SHAPES_HPP
#define SHAPES_HPP

struct Shapes {
    /** Triangle */
    static const GLfloat  Triangle[];
    static const unsigned TriangleN;

    /** Box */
    static const GLfloat  Box[];
    static const unsigned BoxN;
};

/**
 * Triangle
 */
const unsigned Shapes::TriangleN  = 3;
const GLfloat  Shapes::Triangle[] =
    {
    0.0f,  0.5f, 0.0,
   -0.5f, -0.5f, 0.0,
    0.5f, -0.5f, 0.0
    };

/**
 * Box
 */
const unsigned Shapes::BoxN  = 6;
const GLfloat  Shapes::Box[] =
    {
   -0.5f,  0.5f, 0.0,
   -0.5f, -0.5f, 0.0,
    0.5f, -0.5f, 0.0

   -0.5f,  0.5f, 0.0,
    0.5f,  0.5f, 0.0,
    0.5f, -0.5f, 0.0
    };

#endif // SHAPES_HPP
