#include "roiwizard.h"
#include "conclusionpage.h"
#include "intropage.h"
#include "parameterpage.h"

#include <iostream>

ROIWizard::ROIWizard(std::vector<std::pair<std::string, std::string>> *classes,
                     QString *imagesPath, bool *resize, int *col, int *row,
                     QWidget *parent)
    : QWizard(parent), resize(resize), col(col), row(row),
      imagesPath(imagesPath) {

  this->classes = classes;
  addPage(new IntroPage);
  addPage(new ParameterPage(classes));
  addPage(new ConclusionPage);

  setWindowTitle(tr("ROI Extraction Wizard"));
}

void ROIWizard::accept() {
  *resize = field("resize").toBool();
  *col = field("col").toInt();
  *row = field("row").toInt();
  *imagesPath = field("imagePath").toString();
  QDialog::accept();
}
