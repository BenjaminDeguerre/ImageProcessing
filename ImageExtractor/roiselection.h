#ifndef ROISELECTION_H
#define ROISELECTION_H

#include "dataselection.h"
#include "roiselectioninterface.h"
#include "qlabelimage.h"

#include <QImage>
#include <QSplitter>
#include <QString>
#include <QWidget>

#include <utility>

namespace Ui {
class ROISelection;
}

class ROISelection : public ROISelectionInterface {
  Q_OBJECT

public:
  explicit ROISelection(
      std::vector<std::pair<std::string, std::string>> *classes,
      QString imagesPath, bool resize, int col, int row, QWidget *parent = 0);
  ~ROISelection();
   void processCurrentImage();
   void resetImage();
   void resetLastActionImage();
   void setCurrentClass(QString className);
   void loadNextImage();
   void setClass(QString name);

protected:

private:
  bool resize;
  int col, row, posCurrentImage;
  double displayRow, displayCol;
  QString imagesPath;
  std::vector<std::pair<std::string, std::string>> *classes;

  Ui::ROISelection *ui;

  QSplitter splitter;
  QStringList imagesName;

  QImage image;

  DataSelection *ds;
  QLabelImage *qli;
};

#endif // ROISELECTION_H
