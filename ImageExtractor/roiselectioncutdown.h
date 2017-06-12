#ifndef ROISELECTIONCUTDOWN_H
#define ROISELECTIONCUTDOWN_H

#include <QSplitter>
#include <QWidget>

#include "dataselection.h"
#include "roiselectioninterface.h"
#include "qlabelimage.h"

#include <opencv2/core/core.hpp>

namespace Ui {
class ROISelectionCutDown;
}

class ROISelectionCutDown : public ROISelectionInterface {
  Q_OBJECT

public:
  explicit ROISelectionCutDown(
      std::vector<std::pair<std::string, std::string>> *classes,
      QString imagesPath, QString basePath, bool resize, int col, int row,
      int moduleCol, int moduleRow, QWidget *parent = 0);
  ~ROISelectionCutDown();
  void processCurrentImage();
  void resetImage();
  void resetLastActionImage();
  void setCurrentClass(QString className);
  void loadNextImage();
  void setClass(QString name);

protected:
private:
  bool isInsideRectTarget(cv::Rect input, cv::Rect target);
  bool resize;
  int col, row, posCurrentImage, moduleCol, moduleRow;
  double displayRow, displayCol;
  QString imagesPath, basePath;
  std::vector<std::pair<std::string, std::string>> *classes;

  Ui::ROISelectionCutDown *ui;

  QSplitter splitter;
  QStringList imagesName;

  QImage image;

  DataSelection *ds;
  QLabelImage *qli;
};

#endif // ROISELECTIONCUTDOWN_H
