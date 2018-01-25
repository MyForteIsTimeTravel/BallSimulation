#ifndef SINGLEBALL_HPP
#define SINGLEBALL_HPP

#include "../Objects/Object.hpp"
#include "../Objects/Ground.hpp"
#include "../Objects/Ball.hpp"
#include "../glm/vec3.hpp"
#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SingleBall
 *
 *  represents a scene with a single ball and multiple forces,
 *  namely wind and gravity
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct SingleBall : public Scene {
    Ground* ground;
    Ball* ball;

    SingleBall () {
        forces.push_back(glm::vec3(0,  -1, 0)); // gravity
       // forces.push_back(glm::vec3(0.032, 0, 0)); // wind
        ground = new Ground();
        ball = new Ball (0.5f);
        ball->graphics->position = glm::vec3(0.0, 5, 0.0);
        objects.push_back(ground);
        objects.push_back(ball);
    }

    /**
     *  create the scene with a given initial ball state
     *
     *  p   - the starting position of the ball
     *  v   - the starting velocity of the ball
     *  a   - the starting acceleration of the ball
     */
    SingleBall (glm::vec3 p, glm::vec3 v, glm::vec3 a) {
        forces.push_back(glm::vec3(0,  -1, 0)); // gravity
        forces.push_back(glm::vec3(0.1, 0, 0)); // wind
        ground = new Ground();
        ball = new Ball (0.5);
        ball->graphics->position = p;
        ball->physics->v = v;
        ball->physics->a = a;
        objects.push_back(ground);
        objects.push_back(ball);
    }


   ~SingleBall () {
        delete ground;
        delete ball;
    }
};

#endif
