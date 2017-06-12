#ifndef ROIWIZARD_H
#define ROIWIZARD_H

#include <QCheckBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QWizard>

#include <iostream>
#include <string>

class ROIWizard : public QWizard {
  Q_OBJECT

public:
  explicit ROIWizard(std::vector<std::pair<std::string, std::string>> *classes,
                     QString *imagesPath, bool *resize, int *col, int *row,
                     QWidget *parent = 0);
  void accept() override;

private:
  bool *resize;
  int *col, *row;
  QString *imagesPath;
  std::vector<std::pair<std::string, std::string>> *classes;
};

#endif // ROIWIZARD_H
