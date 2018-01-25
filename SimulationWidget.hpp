#ifndef SIMULATIONWIDGET_HPP
#define SIMULATIONWIDGET_HPP

#include "Graphics/GraphicsEngine.hpp"
#include "Graphics/ScreenGeometry.hpp"
#include "Physics/PhysicsEngine.hpp"
#include "Objects/Object.hpp"
#include "Objects/Ground.hpp"
#include "Objects/Ball.hpp"
#include "Scenes/Scene.hpp"
#include <QGLShaderProgram>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include <bitset>

namespace Ui { class SimulationWidget; }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SimulationWidget
 *
 *  A QT / OpenGL widget on which to render the simulation and
 *  control update calls. Post processing plumbing is present but
 *  QT didn't seem to play very nicely with this, presumably because
 *  it uses framebuffers and renderbuffers liberally behind the
 *  scenes already
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class SimulationWidget : public QOpenGLWidget {
    Q_OBJECT
    public:
        SimulationWidget (QWidget* parent = 0) :
            QOpenGLWidget (parent),
            graphics  (parent->width(), parent->height()),
            physics   (),
            frameCamera(parent->width(), parent->height()),
            screen    (ScreenGeometry())
        {}
       ~SimulationWidget () {
            delete scene;
        }

        bool paused = false;
        Ball* ball;

        void multiReset();
        void reset (glm::vec3 p, glm::vec3 v, glm::vec3 a);
        void reset ();

    protected:
        virtual void initializeGL();
        virtual void resizeGL (int w, int h);
        virtual void paintGL ();

        virtual void mouseMoveEvent    (QMouseEvent* e);
        virtual void mousePressEvent   (QMouseEvent* e);
        virtual void mouseReleaseEvent (QMouseEvent* e);
        virtual void keyPressEvent     (QKeyEvent*   e);
        virtual void keyReleaseEvent   (QKeyEvent*   e);

    private:
        GraphicsObject screen;       // the geometry to render the scene onto
        Camera    frameCamera;       // a static camera for the screen rendering
        QGLShaderProgram blurShader; // blur the scene when paused
        QGLShaderProgram postShader; // unblur the scene when running
        QGLShaderProgram shader;     // for objects in the scene
        GLuint renderbufferID;       // on-screen buffer for depth
        GLuint framebufferID;        // off-screen buffer for colour
        GLuint textureID;            // texture to pass to GPU

        GraphicsEngine graphics;     // renderer
        PhysicsEngine physics;       // simulation
        Scene* scene;

        std::bitset<7> kCommands;    // holds the status of keys we're interested in
        std::bitset<2> mCommands;    // holds the status of the two mouse buttons
        int lastx = 0;               // x position of the mouse in the previous update
        int lasty = 0;               // y position of the mouse in the previous update
};

#endif // SimulationWidget_HPP
