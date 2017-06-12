#include "parameterpagecutdown.h"
#include "classadder.h"
#include "ui_parameterpagecutdown.h"

#include <QFileDialog>

ParameterPageCutDown::ParameterPageCutDown(
    std::vector<std::pair<std::string, std::string>> *classes, QWidget *parent)
    : QWizardPage(parent), ui(new Ui::ParameterPageCutDown) {
  ui->setupUi(this);
  setTitle(tr("Parameter selection"));
  setSubTitle(tr("Specify basic information about the extraction"));

  this->classes = classes;
  registerField("imagePath*", ui->lineEdit);
  registerField("basePath*", ui->lineEdit_2);
  registerField("resize", ui->checkBox);
  registerField("col", ui->spinBox);
  registerField("row", ui->spinBox_2);
  registerField("moduleCol", ui->spinBox_3);
  registerField("moduleRow", ui->spinBox_4);
}

ParameterPageCutDown::~ParameterPageCutDown() {
  for (QVector<QLabel *>::iterator it = labels.begin(); it != labels.end();
       ++it) {
    delete (*it);
  }
  labels.clear();
  ;
  delete ui;
}

void ParameterPageCutDown::on_pushButton_2_clicked() {
  ClassAdder ca(&className, &path);
  ca.exec();
  classes->push_back(
      std::make_pair(className.toStdString(), path.toStdString()));
  labels.push_back(new QLabel(className));
  labels.push_back(new QLabel(path));

  ui->gridLayout_7->addWidget(labels.at(labels.size() - 2), row, 0);
  ui->gridLayout_7->addWidget(labels.at(labels.size() - 1), row, 1);
  row++;
}

void ParameterPageCutDown::on_checkBox_stateChanged() {
  ui->spinBox->setEnabled(!ui->spinBox->isEnabled());
  ui->spinBox_2->setEnabled(!ui->spinBox_2->isEnabled());
}

void ParameterPageCutDown::on_pushButton_clicked() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  ui->lineEdit->setText(dir);
}

void ParameterPageCutDown::on_pushButton_3_clicked() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  ui->lineEdit_2->setText(dir);
}
