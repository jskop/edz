// Main window class
#pragma once
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

};