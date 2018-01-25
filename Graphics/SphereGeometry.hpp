#ifndef SPHEREGEOMETRY_HPP
#define SPHEREGEOMETRY_HPP

#include "../glm/glm.hpp"
#include "Geometry.hpp"
#include <cmath>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SphereGeometry
 *
 *  generates an indexed sphere mesh with the given radius
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct SphereGeometry : public Geometry {
    glm::vec3 colour = glm::vec3(1, 1, 1);

    const float X = 0.525731112119133606;
    const float Z = 0.850650808352039932;

    SphereGeometry(float radius) {
        float vert[12][3] = {
            {-X,  0.0,  Z}, { X,  0.0,  Z}, {-X,  0.0, -Z}, { X,  0.0, -Z},
            { 0.0,  Z,  X}, { 0.0,  Z, -X}, { 0.0, -Z,  X}, { 0.0, -Z, -X},
            { Z,   X, 0.0}, {-Z,   X, 0.0}, { Z,  -X, 0.0}, {-Z,  -X, 0.0}};

        uint ind[20][3] = {
            { 0,  4,   1 }, { 0,  9,   4 }, { 9,  5,   4 }, { 4,  5,   8 },
            { 4,  8,   1 }, { 8,  10,  1 }, { 8,  3,  10 }, { 5,  3,   8 },
            { 5,  2,   3 }, { 2,  7,   3 }, { 7,  10,  3 }, { 7,  6,  10 },
            { 7,  11,  6 }, { 11, 0,   6 }, { 0,  1,   6 }, { 6,  1,  10 },
            { 9,  0,  11 }, { 9, 11,   2 }, { 9,  2,   5 }, { 7,  2,  11 }};

        int ndiv = 3;
        for (int i = 0; i < 20; ++i) divide (vert[ind[i][0]], vert[ind[i][1]], vert[ind[i][2]], ndiv, radius);
        for (int i = 0; i < vertices.size(); ++i) indices.push_back(i);
        init();
    }

    /**
     *  normalize
     *
     *  a   - pointer to a 3 float vector
     *
     *  normalizes the vector represented by an array of floats
     */
    void normalize (float *a) {
        float d = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
        a[0] /= d; a[1] /= d; a[2] /= d;
    }

    /**
     *  divide
     *
     *  a   - vertex one
     *  b   - vertex two
     *  c   - vertex three
     *  div - number of divisions / recursion depth & control
     *  r   - radius of the desired sphere
     *
     *  recursively divides a triangle
     */
    void divide (float *a, float *b, float *c, int div, float r) {
        if (div <= 0) {
            Position _a = glm::vec3(a[0]*r, a[1]*r, a[2]*r);
            Position _b = glm::vec3(b[0]*r, b[1]*r, b[2]*r);
            Position _c = glm::vec3(c[0]*r, c[1]*r, c[2]*r);
            glm::vec3 _ba = _b - _a;
            glm::vec3 _ca = _c - _a;
            Normal n = glm::cross(_ca, _ba);
            vertices.push_back(Vertex( _a, colour, n, UV ()));
            vertices.push_back(Vertex( _b, colour, n, UV ()));
            vertices.push_back(Vertex( _c, colour, n, UV ()));
        } else {
            float ab[3];
            float ac[3];
            float bc[3];
            for (int i = 0; i < 3; ++i) {
                ab[i] = (a[i] + b[i]) / 2;
                ac[i] = (a[i] + c[i]) / 2;
                bc[i] = (b[i] + c[i]) / 2;
            }
            normalize(ab);
            normalize(ac);
            normalize(bc);
            divide (a,  ab, ac, div - 1, r);
            divide (b,  bc, ab, div - 1, r);
            divide (c,  ac, bc, div - 1, r);
            divide (ab, bc, ac, div - 1, r);
        }
    }
};

#endif
