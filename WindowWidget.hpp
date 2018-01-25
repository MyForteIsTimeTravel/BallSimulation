#ifndef WINDOWWIDGET_HPP
#define WINDOWWIDGET_HPP

#include "ui_WindowWidget.h"

#include "SimulationWidget.hpp"
#include "glm/vec3.hpp"
#include <QWidget>

namespace Ui { class WindowWidget; }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  WindowWidget
 *
 *  A QT widget holding all the control GUI elements and the
 *  simulation GL widget
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct WindowWidget : public QWidget {
    Q_OBJECT
    public:
        WindowWidget (QWidget* parent = 0) :
            QWidget (parent),
            ui      (new Ui::WindowWidget) {
            ui->setupUi(this);
            // hide pause data
            unpause();
            ui->pos_x->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->pos_y->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->pos_z->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->acc_x->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->acc_y->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->acc_z->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->vel_x->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->vel_y->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->vel_z->setValidator (new QDoubleValidator(-100, 100, 2, this));
            ui->pos_x->setText      (QString::number(0.0f));
            ui->pos_y->setText      (QString::number(5.0f));
            ui->pos_z->setText      (QString::number(0.0f));
            ui->acc_x->setText      (QString::number(0.0f));
            ui->acc_y->setText      (QString::number(0.0f));
            ui->acc_z->setText      (QString::number(0.0f));
            ui->vel_x->setText      (QString::number(0.0f));
            ui->vel_y->setText      (QString::number(0.0f));
            ui->vel_z->setText      (QString::number(0.0f));
            sim    = (ui->simulationWidget);
            single = ui->reset_single;
            multi  = ui->reset_double;
            connect (single, SIGNAL (released()), this, SLOT (singleReset()));
            connect (multi, SIGNAL (released()), this, SLOT (doubleReset()));

            setWindowTitle("Physics Simulation");
        }

       ~WindowWidget () {
            delete ui;
        }

        void pause () {
            ui->acceleration->setVisible (true);
            ui->acc_x->setVisible        (true);
            ui->acc_y->setVisible        (true);
            ui->acc_z->setVisible        (true);
            ui->position->setVisible     (true);
            ui->pos_x->setVisible        (true);
            ui->pos_y->setVisible        (true);
            ui->pos_z->setVisible        (true);
            ui->velocity->setVisible     (true);
            ui->vel_x->setVisible        (true);
            ui->vel_y->setVisible        (true);
            ui->vel_z->setVisible        (true);
            ui->paused->setVisible       (true);
            ui->reset_single->setVisible (true);
            ui->reset_double->setVisible (true);
            ui->state->setVisible        (true);
            ui->disclaimer->setVisible   (true);
        }

        void unpause () {
            ui->acceleration->setVisible (false);
            ui->acc_x->setVisible        (false);
            ui->acc_y->setVisible        (false);
            ui->acc_z->setVisible        (false);
            ui->position->setVisible     (false);
            ui->pos_x->setVisible        (false);
            ui->pos_y->setVisible        (false);
            ui->pos_z->setVisible        (false);
            ui->velocity->setVisible     (false);
            ui->vel_x->setVisible        (false);
            ui->vel_y->setVisible        (false);
            ui->vel_z->setVisible        (false);
            ui->paused->setVisible       (false);
            ui->reset_single->setVisible (false);
            ui->reset_double->setVisible (false);
            ui->state->setVisible        (false);
            ui->disclaimer->setVisible   (false);
        }

        virtual void update () {
            if (!sim->paused) {
                ui->pos_x->setText(QString::number(sim->ball->graphics->position.x));
                ui->pos_y->setText(QString::number(sim->ball->graphics->position.y));
                ui->pos_z->setText(QString::number(sim->ball->graphics->position.z));
                ui->acc_x->setText(QString::number(sim->ball->physics->a.x));
                ui->acc_y->setText(QString::number(sim->ball->physics->a.y));
                ui->acc_z->setText(QString::number(sim->ball->physics->a.z));
                ui->vel_x->setText(QString::number(sim->ball->physics->v.x));
                ui->vel_y->setText(QString::number(sim->ball->physics->v.y));
                ui->vel_z->setText(QString::number(sim->ball->physics->v.z));
            }
        }

    private slots:
        void singleReset () {
            pos.x = ui->pos_x->text().toFloat();
            pos.y = ui->pos_y->text().toFloat();
            pos.z = ui->pos_z->text().toFloat();
            acc.x = ui->acc_x->text().toFloat();
            acc.y = ui->acc_y->text().toFloat();
            acc.z = ui->acc_z->text().toFloat();
            vel.x = ui->vel_x->text().toFloat();
            vel.y = ui->vel_y->text().toFloat();
            vel.z = ui->vel_z->text().toFloat();
            sim->reset(pos, vel, acc);
            sim->paused = false;
            unpause();
        }

        void doubleReset () {
            sim->multiReset();
            sim->paused = false;
            unpause();
        }

    private:
        Ui::WindowWidget*  ui; // GUI Overlay
        SimulationWidget* sim; // simulation GL
        QPushButton*  single;  // button to start a single ball simulation
        QPushButton*  multi;   // button to start a multi ball simulation
        glm::vec3 pos;         // holds the user-given ball position
        glm::vec3 vel;         // holds the user-given ball velocity
        glm::vec3 acc;         // holds the user-given ball acceleration
};

#endif // WindowWidget_HPP
