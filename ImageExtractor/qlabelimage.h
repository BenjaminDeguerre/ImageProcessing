#ifndef QLABELIMAGE_H
#define QLABELIMAGE_H

#include <QImage>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

#include <utility>

#include <opencv2/core/core.hpp>

class QLabelImage : public QLabel {
public:
  QLabelImage(QString imagePath, int displayCol = 512, int displayRow = 512,
              QWidget *parent = 0);
  void addQImage(QImage *image);
  void setNewImage(QString path);
  std::vector<std::pair<std::string, cv::Rect>> getRectangles();
  void setCurrentClass(std::string className);
  void setCurrentClass(QString className);
  void goBack();
  void reset();

protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

private:

  void paintImage();

  std::vector<std::pair<std::string, cv::Rect>> rectangles;
  int x1, x2, y1, y2, displayCol, displayRow;
  int height, width;
  QImage *image;
  QPixmap pm;
  QPainter painter;

  std::string currentClass;
  cv::Rect currentRectangle;
};

#endif // QLABELIMAGE_H
