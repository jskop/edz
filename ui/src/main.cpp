#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("E-dziennik działa");
    mainWindow.resize(800, 600);
    mainWindow.show();
    QPushButton *button = new QPushButton(
        QApplication::translate("childwidget", "Initialize DB"), &mainWindow
    );
    button->move(100, 100);
    button->show();
    return app.exec();
}