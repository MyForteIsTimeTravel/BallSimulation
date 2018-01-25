#include "GLSLShaders/Shaders.hpp"
#include "Scenes/DoubleBall.hpp"
#include "Scenes/SingleBall.hpp"
#include "SimulationWidget.hpp"
#include "WindowWidget.hpp"

/**
 *  initialiseGL
 *
 *  sets up QT & OpenGL plumbing before creating the scene
 */
void SimulationWidget::initializeGL() {
    // setup QT plumbing
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    // Setup OpenGL rendering properties & post-processing plumbing
    glEnable(GL_DEPTH_TEST);
/*
    glGenTextures         (1, &textureID);
    glBindTexture         (GL_TEXTURE_2D, textureID);
    glGenFramebuffers     (1, &framebufferID);
    glBindFramebuffer     (GL_FRAMEBUFFER, framebufferID);
    glGenRenderbuffers    (1, &renderbufferID);
    glBindRenderbuffer    (GL_RENDERBUFFER, renderbufferID);
    glRenderbufferStorage (GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width(), height());
    glBindRenderbuffer    (GL_RENDERBUFFER, 0);
*/
    // set up shader programs
    shader.addShaderFromSourceCode(QGLShader::Vertex,   Shaders::PhongVertex);
    shader.addShaderFromSourceCode(QGLShader::Fragment, Shaders::PhongFragment);
    shader.link();
    postShader.addShaderFromSourceCode(QGLShader::Vertex,   Shaders::PostVertex);
    postShader.addShaderFromSourceCode(QGLShader::Fragment, Shaders::PostFragment);
    postShader.link();
    blurShader.addShaderFromSourceCode(QGLShader::Vertex,   Shaders::BlurVertex);
    blurShader.addShaderFromSourceCode(QGLShader::Fragment, Shaders::BlurFragment);
    blurShader.link();

    // set up scene
    graphics.camera.position = glm::vec3(0, 4, 16);
    multiReset();
}

/**
 *  resizeGL
 *
 *  w   - new width
 *  h   - new height
 *
 *  resizes the gl viewport
 */
void SimulationWidget::resizeGL (int w, int h) {
    glViewport(0, 0, w, qMax(h, 1));
}

/**
 *  paintGL
 *
 *  handles input, updates the simulation and renders the scene
 */
void SimulationWidget::paintGL () {
    if (!paused) {
        if (kCommands[0]) graphics.camera.position += graphics.camera.relativeForward * -0.1f;
        if (kCommands[1]) graphics.camera.position += graphics.camera.relativeRight * -0.1f;
        if (kCommands[2]) graphics.camera.position += graphics.camera.relativeForward * 0.1f;
        if (kCommands[3]) graphics.camera.position += graphics.camera.relativeRight * 0.1f;
        if (kCommands[4]) graphics.camera.position.y += 0.1;
        if (kCommands[5]) graphics.camera.position.y -= 0.1;
        graphics.camera.update();
        physics.simulate();
    }

    for (Object* o : scene->objects) o->update();
    const qreal scale = devicePixelRatio();
    glViewport(0, 0, width() * scale, height() * scale);
    glClearColor(0.82, 0.82, 0.82, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    graphics.render(&shader);
    update();
}


/**
 *  reset
 *
 *  p   - initial ball position
 *  v   - initial ball velocity
 *  a   - initial ball acceleration
 *
 *  resets the scene with the given ball state
 */
void SimulationWidget::reset (glm::vec3 p, glm::vec3 v, glm::vec3 a) {
    graphics.reset();
    physics.reset();

    scene = new SingleBall();

    scene->objects.at(1)->graphics->position = p;
    scene->objects.at(1)->physics->v = v;
    scene->objects.at(1)->physics->a = a;

    for (glm::vec3& f : scene->forces) physics.forces.push_back(f);
    for (Object* o : scene->objects) o->init(&graphics, &physics);

    ball = static_cast<Ball*>(scene->objects.at(1));
}


/**
 *  reset
 *
 *  resets the scene with a single ball
 */
void SimulationWidget::reset () {
    graphics.reset();
    physics.reset();

    scene = new SingleBall();
    for (glm::vec3& f : scene->forces) physics.forces.push_back(f);
    for (Object* o : scene->objects) o->init(&graphics, &physics);
    ball = static_cast<Ball*>(scene->objects.at(1));
}

/**
 *  multiReset
 *
 *  resets the scene with many balls
 */
void SimulationWidget::multiReset () {
    graphics.reset();
    physics.reset();

    scene = new DoubleBall();
    for (glm::vec3& f : scene->forces) physics.forces.push_back(f);
    for (Object* o : scene->objects) o->init(&graphics, &physics);
    ball = static_cast<Ball*>(scene->objects.at(1));
}

/**
 *  mouseMoveEvent
 *
 *  e   - pointer to the event to handle
 */
void SimulationWidget::mouseMoveEvent (QMouseEvent *e) {
    if (mCommands[1]) {
        graphics.camera.rotation.y += (e->y() - lasty) * -0.1f;
        graphics.camera.rotation.x += (e->x() - lastx) * 0.1f;
        graphics.camera.update();
    }

    lastx = e->x();
    lasty = e->y();
}

/**
 *  mousePressEvent
 *
 *  e   - pointer to the event to handle
 */
void SimulationWidget::mousePressEvent (QMouseEvent *e) {
    switch (e->button()) {
        case Qt::LeftButton: mCommands [0] = true; break;
        case Qt::RightButton: mCommands [1] = true; break;
        default: break;
    }
}

/**
 *  mouseReleaseEvent
 *
 *  e   - pointer to the event to handle
 */
void SimulationWidget::mouseReleaseEvent (QMouseEvent *e) {
    switch (e->button()) {
        case Qt::LeftButton: mCommands [0] = false; break;
        case Qt::RightButton: mCommands [1] = false; break;
        default: break;
    }
}

/**
 *  keyPressEvent
 *
 *  e   - pointer to the event to handle
 */
void SimulationWidget::keyPressEvent(QKeyEvent* e) {
    switch (e->key()) {
        case Qt::Key_W: kCommands[0] = true; break;
        case Qt::Key_A: kCommands[1] = true; break;
        case Qt::Key_S: kCommands[2] = true; break;
        case Qt::Key_D: kCommands[3] = true; break;
        case Qt::Key_E: kCommands[4] = true; break;
        case Qt::Key_Q: kCommands[5] = true; break;
        case Qt::Key_Space: reset(); break;
        case Qt::Key_Escape:
            if (!paused) (dynamic_cast<WindowWidget*>(parent()))->pause();
            if (paused) (dynamic_cast<WindowWidget*>(parent()))->unpause();
            paused = !paused;
            break;
        default: QOpenGLWidget::keyPressEvent( e );
    }
}

/**
 *  keyReleaseEvent
 *
 *  e   - pointer to the event to handle
 */
void SimulationWidget::keyReleaseEvent(QKeyEvent* e) {
    switch (e->key()) {
        case Qt::Key_Escape: break;
        case Qt::Key_W: kCommands[0] = false; break;
        case Qt::Key_A: kCommands[1] = false; break;
        case Qt::Key_S: kCommands[2] = false; break;
        case Qt::Key_D: kCommands[3] = false; break;
        case Qt::Key_E: kCommands[4] = false; break;
        case Qt::Key_Q: kCommands[5] = false; break;
        default: QOpenGLWidget::keyPressEvent( e );
    }
}
