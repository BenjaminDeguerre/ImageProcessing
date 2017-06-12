#ifndef ROIWIZARDCUTDOWN_H
#define ROIWIZARDCUTDOWN_H


#include <QLineEdit>
#include <QString>
#include <QWizard>

#include <iostream>
#include <string>

class ROIWizardCutDown : public QWizard {
  Q_OBJECT

public:
  explicit ROIWizardCutDown(
      std::vector<std::pair<std::string, std::string>> *classes,
      QString *imagesPath, QString *basePath, bool *resize, int *col, int *row, int *moduleCol,
      int *moduleRow, QWidget *parent = 0);
  void accept() override;

private:
  bool *resize;
  int *col, *row, *moduleCol, *moduleRow;
  QString *imagesPath, *basePath;
  std::vector<std::pair<std::string, std::string>> *classes;
};

#endif // ROIWIZARD_H
