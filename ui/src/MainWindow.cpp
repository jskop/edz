#include "MainWindow.h"
#include "logic.hpp"
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qtextedit.h>

MainWindow::MainWindow()
    : initDbButton(new QPushButton("Initialize DB", this)),
      newStudentButton(new QPushButton("New student", this)) {

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  QHBoxLayout *buttonsLayout = new QHBoxLayout(this);
  mainLayout->addLayout(buttonsLayout);
  buttonsLayout->addWidget(initDbButton);
  buttonsLayout->addWidget(newStudentButton);
  studentsList = new QListWidget(this);
  mainLayout->addWidget(studentsList);
  newStudentButton->setDisabled(true);
  connect(initDbButton, &QPushButton::clicked, this, &MainWindow::initDb);
  connect(newStudentButton, &QPushButton::clicked, this,
          &MainWindow::newStudent);
}

void MainWindow::initDb() {
  if (logic::ensure_db_initialized("edz.db")) {
    initDbButton->setDisabled(true);
    connected = true;
    this->newStudentButton->setDisabled(false);
    this->refreshList();
  } else {
    QMessageBox::critical(this, "Błąd", "Nie można połączyć się z bazą");
  }
}

void MainWindow::refreshList() {
  if (!this->connected) {
    return;
  }
  this->studentsList->clear();
  auto students = logic::list_students();
  for (const auto [id, name, surname] : students) {
    auto label = std::format("{0}: {1} {2}", id, surname, name);
    this->studentsList->addItem(QString(label.c_str()));
  }
}

void MainWindow::newStudent() {
  auto inputDialog = new QDialog(this);
  inputDialog->setModal(true);
  auto mainLayout = new QVBoxLayout(inputDialog);
  auto buttons = new QHBoxLayout(inputDialog);
  auto inputGrid = new QGridLayout(inputDialog);
  mainLayout->addLayout(inputGrid);
  mainLayout->addLayout(buttons);
  auto cancelButton = new QPushButton(tr("&Cancel"), inputDialog);
  auto okButton = new QPushButton(tr("&Ok"), inputDialog);
  buttons->addWidget(okButton);
  buttons->addWidget(cancelButton);
  auto nameLabel = new QLabel(tr("Name"));
  auto surnameLabel = new QLabel(tr("Surname"));
  inputGrid->addWidget(nameLabel, 0, 0);
  inputGrid->addWidget(surnameLabel, 1, 0);
  auto nameInput = new QLineEdit(inputDialog);
  auto surnameInput = new QLineEdit(inputDialog);
  inputGrid->addWidget(nameInput, 0, 1);
  inputGrid->addWidget(surnameInput, 1, 1);
  connect(cancelButton, &QPushButton::clicked, inputDialog, &QDialog::reject);
  connect(okButton, &QPushButton::clicked, inputDialog, &QDialog::accept);
  if (inputDialog->exec() == QDialog::Accepted) {
    if (logic::add_student(nameInput->text().toStdString(),
                           surnameInput->text().toStdString())) {
      refreshList();
    } else {
      QMessageBox::critical(this, "Błąd", "Nie udało się dodać ucznia do bazy");
    }
  }
}

MainWindow::~MainWindow() { logic::ensure_db_closed(); }