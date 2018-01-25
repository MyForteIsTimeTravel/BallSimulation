/********************************************************************************
** Form generated from reading UI file 'WindowWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWWIDGET_H
#define UI_WINDOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "simulationwidget.hpp"

QT_BEGIN_NAMESPACE

class Ui_WindowWidget
{
public:
    SimulationWidget *simulationWidget;
    QLabel *paused;
    QLabel *state;
    QPushButton *reset_single;
    QLabel *position;
    QLabel *velocity;
    QLabel *acceleration;
    QLineEdit *acc_x;
    QLineEdit *acc_y;
    QLineEdit *acc_z;
    QLineEdit *vel_y;
    QLineEdit *vel_z;
    QLineEdit *vel_x;
    QLineEdit *pos_y;
    QLineEdit *pos_z;
    QLineEdit *pos_x;
    QLabel *paused_2;
    QLabel *paused_3;
    QLabel *paused_4;
    QLabel *disclaimer;
    QLabel *paused_6;
    QPushButton *reset_double;
    QLabel *paused_7;

    void setupUi(QWidget *WindowWidget)
    {
        if (WindowWidget->objectName().isEmpty())
            WindowWidget->setObjectName(QStringLiteral("WindowWidget"));
        WindowWidget->resize(800, 467);
        simulationWidget = new SimulationWidget(WindowWidget);
        simulationWidget->setObjectName(QStringLiteral("simulationWidget"));
        simulationWidget->setGeometry(QRect(0, -10, 800, 480));
        paused = new QLabel(WindowWidget);
        paused->setObjectName(QStringLiteral("paused"));
        paused->setGeometry(QRect(350, 210, 100, 20));
        paused->setAlignment(Qt::AlignCenter);
        state = new QLabel(WindowWidget);
        state->setObjectName(QStringLiteral("state"));
        state->setGeometry(QRect(10, 10, 101, 16));
        reset_single = new QPushButton(WindowWidget);
        reset_single->setObjectName(QStringLiteral("reset_single"));
        reset_single->setGeometry(QRect(30, 130, 131, 24));
        position = new QLabel(WindowWidget);
        position->setObjectName(QStringLiteral("position"));
        position->setGeometry(QRect(20, 30, 60, 16));
        velocity = new QLabel(WindowWidget);
        velocity->setObjectName(QStringLiteral("velocity"));
        velocity->setGeometry(QRect(20, 50, 60, 16));
        acceleration = new QLabel(WindowWidget);
        acceleration->setObjectName(QStringLiteral("acceleration"));
        acceleration->setGeometry(QRect(20, 70, 81, 16));
        acc_x = new QLineEdit(WindowWidget);
        acc_x->setObjectName(QStringLiteral("acc_x"));
        acc_x->setGeometry(QRect(100, 70, 21, 16));
        acc_y = new QLineEdit(WindowWidget);
        acc_y->setObjectName(QStringLiteral("acc_y"));
        acc_y->setGeometry(QRect(130, 70, 21, 16));
        acc_z = new QLineEdit(WindowWidget);
        acc_z->setObjectName(QStringLiteral("acc_z"));
        acc_z->setGeometry(QRect(160, 70, 21, 16));
        vel_y = new QLineEdit(WindowWidget);
        vel_y->setObjectName(QStringLiteral("vel_y"));
        vel_y->setGeometry(QRect(130, 50, 21, 16));
        vel_z = new QLineEdit(WindowWidget);
        vel_z->setObjectName(QStringLiteral("vel_z"));
        vel_z->setGeometry(QRect(160, 50, 21, 16));
        vel_x = new QLineEdit(WindowWidget);
        vel_x->setObjectName(QStringLiteral("vel_x"));
        vel_x->setGeometry(QRect(100, 50, 21, 16));
        pos_y = new QLineEdit(WindowWidget);
        pos_y->setObjectName(QStringLiteral("pos_y"));
        pos_y->setGeometry(QRect(130, 30, 21, 16));
        pos_z = new QLineEdit(WindowWidget);
        pos_z->setObjectName(QStringLiteral("pos_z"));
        pos_z->setGeometry(QRect(160, 30, 21, 16));
        pos_x = new QLineEdit(WindowWidget);
        pos_x->setObjectName(QStringLiteral("pos_x"));
        pos_x->setGeometry(QRect(100, 30, 21, 16));
        paused_2 = new QLabel(WindowWidget);
        paused_2->setObjectName(QStringLiteral("paused_2"));
        paused_2->setGeometry(QRect(0, 440, 201, 16));
        paused_2->setAlignment(Qt::AlignCenter);
        paused_3 = new QLabel(WindowWidget);
        paused_3->setObjectName(QStringLiteral("paused_3"));
        paused_3->setGeometry(QRect(220, 440, 181, 16));
        paused_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        paused_4 = new QLabel(WindowWidget);
        paused_4->setObjectName(QStringLiteral("paused_4"));
        paused_4->setGeometry(QRect(390, 440, 161, 16));
        paused_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        disclaimer = new QLabel(WindowWidget);
        disclaimer->setObjectName(QStringLiteral("disclaimer"));
        disclaimer->setGeometry(QRect(10, 100, 181, 16));
        disclaimer->setAlignment(Qt::AlignCenter);
        paused_6 = new QLabel(WindowWidget);
        paused_6->setObjectName(QStringLiteral("paused_6"));
        paused_6->setGeometry(QRect(540, 440, 81, 16));
        paused_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        reset_double = new QPushButton(WindowWidget);
        reset_double->setObjectName(QStringLiteral("reset_double"));
        reset_double->setGeometry(QRect(30, 170, 131, 24));
        paused_7 = new QLabel(WindowWidget);
        paused_7->setObjectName(QStringLiteral("paused_7"));
        paused_7->setGeometry(QRect(630, 440, 181, 16));
        paused_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(WindowWidget);

        QMetaObject::connectSlotsByName(WindowWidget);
    } // setupUi

    void retranslateUi(QWidget *WindowWidget)
    {
        WindowWidget->setWindowTitle(QApplication::translate("WindowWidget", "SimulationWidget", Q_NULLPTR));
        paused->setText(QApplication::translate("WindowWidget", "PAUSED", Q_NULLPTR));
        state->setText(QApplication::translate("WindowWidget", "Initial Ball State:", Q_NULLPTR));
        reset_single->setText(QApplication::translate("WindowWidget", "single ball", Q_NULLPTR));
        position->setText(QApplication::translate("WindowWidget", "position:", Q_NULLPTR));
        velocity->setText(QApplication::translate("WindowWidget", "velocity:", Q_NULLPTR));
        acceleration->setText(QApplication::translate("WindowWidget", "acceleration:", Q_NULLPTR));
        paused_2->setText(QApplication::translate("WindowWidget", "W A S D - horizontal movement", Q_NULLPTR));
        paused_3->setText(QApplication::translate("WindowWidget", "E Q - vertical movement", Q_NULLPTR));
        paused_4->setText(QApplication::translate("WindowWidget", "SPACE - default reset", Q_NULLPTR));
        disclaimer->setText(QApplication::translate("WindowWidget", "(only in single ball scene)", Q_NULLPTR));
        paused_6->setText(QApplication::translate("WindowWidget", "ESC - pause", Q_NULLPTR));
        reset_double->setText(QApplication::translate("WindowWidget", "multi ball", Q_NULLPTR));
        paused_7->setText(QApplication::translate("WindowWidget", "Right Mouse - orientation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WindowWidget: public Ui_WindowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWWIDGET_H
