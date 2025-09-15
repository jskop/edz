// Main window class
#ifndef  MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QtWidgets>

class MainWindow : public QWidget {
  Q_OBJECT

public:
  MainWindow();
private slots:
  void initDb();

private:
  QPushButton *initDbButton;
  QLabel *initDbLabel;
};
#endif