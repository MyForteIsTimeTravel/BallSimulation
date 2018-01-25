#ifndef DOUBLEBALL_HPP
#define DOUBLEBALL_HPP

#include "../Objects/Object.hpp"
#include "../Objects/Ground.hpp"
#include "../Objects/Ball.hpp"
#include "../glm/vec3.hpp"
#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  DoubleBall
 *
 *  represents a scene with many balls and a ground plane, with only
 *  gravity acting on the scene.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct DoubleBall : public Scene {
    Ground* ground;
    Ball* ball1;
    Ball* ball2;
    Ball* ball3;
    Ball* ball4;
    Ball* ball5;

    DoubleBall () {
        forces.push_back(glm::vec3(0,  -1, 0)); // gravity
        //forces.push_back(glm::vec3(0.1, 0, 0)); // wind

        ground = new Ground();
        ball1  = new Ball (0.25);
        ball2  = new Ball (0.50);
        ball3  = new Ball (0.75);
        ball4  = new Ball (1.00);
        ball5  = new Ball (1.25);

        ball1->graphics->position = glm::vec3(-4, 5, 0.0);
        ball2->graphics->position = glm::vec3(-3, 5, 0.0);
        ball3->graphics->position = glm::vec3(-1.5, 5, 0.0);
        ball4->graphics->position = glm::vec3( 0.5, 5, 0.0);
        ball5->graphics->position = glm::vec3( 3.25, 5, 0.0);

        objects.push_back(ground);
        objects.push_back(ball1);
        objects.push_back(ball2);
        objects.push_back(ball3);
        objects.push_back(ball4);
        objects.push_back(ball5);
    }

   ~DoubleBall () {
        delete ground;
        delete ball1;
        delete ball2;
        delete ball3;
        delete ball4;
        delete ball5;
    }
};

#endif
