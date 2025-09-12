#include "MainWindow.h"

MainWindow::MainWindow()
    : initDbButton(new QPushButton("Initialize DB", this)) {
  initDbButton->move(100, 100);
  connect(initDbButton, &QPushButton::clicked, this, &MainWindow::initDb);
}
void MainWindow::initDb()
{
    
}