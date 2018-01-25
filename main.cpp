#include <QApplication>
#include <QGLFormat>

#include "WindowWidget.hpp"

int main(int argc, char* argv[]) {
    QApplication app (argc, argv);
    QSurfaceFormat glFormat;
    glFormat.setVersion(3, 3);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(glFormat);
    WindowWidget widget;
    widget.show();
    return app.exec();
}
