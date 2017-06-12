#ifndef PARAMETERPAGECUTDOWN_H
#define PARAMETERPAGECUTDOWN_H

#include <QWizardPage>
#include <QLabel>
#include <QVector>

#include <iostream>
#include <string>


namespace Ui {
class ParameterPageCutDown;
}

class ParameterPageCutDown : public QWizardPage {
  Q_OBJECT

public:
  explicit ParameterPageCutDown(std::vector<std::pair<std::string, std::string>> *classes, QWidget *parent = 0);
  ~ParameterPageCutDown();

private slots:
  void on_pushButton_clicked();

  void on_checkBox_stateChanged();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  private:
  Ui::ParameterPageCutDown *ui;
  QString className;
  QString path;
  std::vector<std::pair<std::string, std::string>> *classes;

  QVector<QLabel*> labels;
  int row = 0;
};

#endif // PARAMETERPAGE_H

