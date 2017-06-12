#include "parameterpage.h"
#include "classadder.h"
#include "ui_parameterpage.h"

#include <QFileDialog>

#include <iostream>

ParameterPage::ParameterPage(
    std::vector<std::pair<std::string, std::string>> *classes, QWidget *parent)
    : QWizardPage(parent), ui(new Ui::ParameterPage) {
  ui->setupUi(this);
  setTitle(tr("Parameter selection"));
  setSubTitle(tr("Specify basic information about the extraction"));

  this->classes = classes;
  registerField("imagePath*", ui->lineEdit);
  registerField("resize", ui->checkBox);
  registerField("col", ui->spinBox);
  registerField("row", ui->spinBox_2);
}

ParameterPage::~ParameterPage() {
  for (QVector<QLabel*>::iterator it = labels.begin(); it != labels.end(); ++it) {
    delete (*it);
  }
  labels.clear();
  delete ui;
}

void ParameterPage::on_pushButton_clicked() {
  ClassAdder ca(&className, &path);
  ca.exec();
  classes->push_back(
      std::make_pair(className.toStdString(), path.toStdString()));
  labels.push_back(new QLabel(className));
  labels.push_back(new QLabel(path));

  ui->gridLayout_4->addWidget(labels.at(labels.size() - 2), row, 0);
  ui->gridLayout_4->addWidget(labels.at(labels.size() - 1), row, 1);
  row++;
}

void ParameterPage::on_checkBox_stateChanged() {
  ui->spinBox->setEnabled(!ui->spinBox->isEnabled());
  ui->spinBox_2->setEnabled(!ui->spinBox_2->isEnabled());
}

void ParameterPage::on_pushButton_2_clicked() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  ui->lineEdit->setText(dir);
}
