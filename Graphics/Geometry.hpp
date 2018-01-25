#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "../glm/vec3.hpp"
#include "Vertex.hpp"

#include <QtGui/qopengl.h>
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Geometry
 *
 *  Parent class contatining the boilerplate for passing an indexed
 *  mesh to the GPU and calling OpenGL's render function for the
 *  given mesh. Inheriting classes should fill their vertex and index
 *  arrays in their constructor before calling init to set the mesh
 *  up on the graphics card
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Geometry {
    Geometry () {}
   ~Geometry () {}

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    /**
     *  init
     *
     *  sets up the mesh on the GPU, should only be called
     *  after the vertex and index arrays have been populated
     *  with the desired geometry
     */
    virtual void init () {
        glGenVertexArrays (1, &this->VAO);
        glGenBuffers      (1, &this->VBO);
        glGenBuffers      (1, &this->EBO);

        glBindVertexArray(this->VAO);
            // Send VBO to GPU
            glBindBuffer (GL_ARRAY_BUFFER, this->VBO);
            glBufferData (GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);
            // send EBO to GPU
            glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData (GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
            // Vertex Position
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
            glEnableVertexAttribArray(0);
            // Vertex Colour
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));
            glEnableVertexAttribArray(1);
            // Vertex Normal
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
            glEnableVertexAttribArray(2);
            // Vertex uvs
            glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv));
            glEnableVertexAttribArray(3);
        glBindVertexArray(0);
    }

    /**
     *  draw
     *
     *  calls OpenGL to render the mesh
     */
    void draw () {
        glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
};

#endif
