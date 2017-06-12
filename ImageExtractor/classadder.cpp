#include "classadder.h"
#include "ui_classadder.h"

#include <QFileDialog>

#include <iostream>

ClassAdder::ClassAdder(QString *className, QString *path, QWidget *parent)
    : QDialog(parent), ui(new Ui::ClassAdder) {
  ui->setupUi(this);
  this->path = path;
  this->className = className;
}

ClassAdder::~ClassAdder() { delete ui; }

void ClassAdder::on_pushButton_clicked() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  ui->lineEdit_2->setText(dir);
}

void ClassAdder::on_buttonBox_accepted() {
  *path = ui->lineEdit_2->text();
  *className = ui->lineEdit->text();
}
