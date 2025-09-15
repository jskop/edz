#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("E-dziennik działa");
    mainWindow.resize(800, 600);
    mainWindow.show();
    return app.exec();
}