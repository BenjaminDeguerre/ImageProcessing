#ifndef PARAMETERPAGE_H
#define PARAMETERPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QVector>

#include <iostream>
#include <string>

namespace Ui {
class ParameterPage;
}

class ParameterPage : public QWizardPage {
  Q_OBJECT

public:
  explicit ParameterPage(std::vector<std::pair<std::string, std::string>> *classes, QWidget *parent = 0);
  ~ParameterPage();

private slots:
  void on_pushButton_clicked();

  void on_checkBox_stateChanged();

  void on_pushButton_2_clicked();

private:
  Ui::ParameterPage *ui;
  QString className;
  QString path;
  std::vector<std::pair<std::string, std::string>> *classes;

  QVector<QLabel*> labels;
  int row = 0;
};

#endif // PARAMETERPAGE_H
