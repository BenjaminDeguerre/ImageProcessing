#include "roiwizardcutdown.h"
#include "conclusionpage.h"
#include "intropage.h"
#include "parameterpagecutdown.h"

#include <iostream>

ROIWizardCutDown::ROIWizardCutDown(
    std::vector<std::pair<std::string, std::string>> *classes,
    QString *imagesPath, QString *basePath, bool *resize, int *col, int *row, int *moduleCol,
    int *moduleRow, QWidget *parent)
    : QWizard(parent), resize(resize), col(col), row(row), moduleCol(moduleCol), moduleRow(moduleRow),
      imagesPath(imagesPath), basePath(basePath) {

  this->classes = classes;
  addPage(new IntroPage);
  addPage(new ParameterPageCutDown(classes));
  addPage(new ConclusionPage);

  setWindowTitle(tr("ROI Extraction Wizard"));
}

void ROIWizardCutDown::accept() {
  *resize = field("resize").toBool();
  *col = field("col").toInt();
  *row = field("row").toInt();
  *moduleCol = field("moduleCol").toInt();
  *moduleRow = field("moduleRow").toInt();
  *imagesPath = field("imagePath").toString();
  *basePath = field("basePath").toString();
  QDialog::accept();
}
