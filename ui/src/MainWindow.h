// Main window class
#ifndef  MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QtWidgets>

class MainWindow : public QWidget {
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();
private slots:
  void initDb();
  void newStudent();

private:
  QPushButton *initDbButton;
  QPushButton *newStudentButton;
  QListWidget *studentsList;
  bool connected;
  void refreshList();
};
#endif