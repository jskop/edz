#include "MainWindow.h"
#include "logic.hpp"

MainWindow::MainWindow()
    : initDbButton(new QPushButton("Initialize DB", this)),
      initDbLabel(new QLabel("")) {

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(initDbButton);
  mainLayout->addWidget(initDbLabel);
  connect(initDbButton, &QPushButton::clicked, this, &MainWindow::initDb);
}

void MainWindow::initDb() {
  if(ensure_db_initialized("edz.db")) {
    this->initDbLabel->setText("Connected");
  } else {
    this->initDbLabel->setText("Error");
  }
}