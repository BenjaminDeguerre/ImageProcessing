#include "qlabelimage.h"

#include <QWidget>

#include <iostream>

QLabelImage::QLabelImage(QString imagePath, int displayCol, int displayRow,
                         QWidget *parent)
    : QLabel(parent), displayCol(displayCol), displayRow(displayRow) {
  this->image = new QImage(imagePath);

  pm = QPixmap::fromImage(*image);
  pm = pm.scaled(displayCol, displayRow);
  setPixmap(pm);
}

void QLabelImage::mousePressEvent(QMouseEvent *event) {
  if (currentRectangle.width > 0) {
    currentRectangle.x = 0;
    currentRectangle.y = 0;
    currentRectangle.width = 0;
    currentRectangle.height = 0;
  }

  x1 = event->x();
  y1 = event->y();
}

void QLabelImage::mouseReleaseEvent(QMouseEvent *event) {

  (void)event;

  rectangles.push_back(
      std::pair<std::string, cv::Rect>(currentClass, currentRectangle));
  paintImage();
}

void QLabelImage::mouseMoveEvent(QMouseEvent *event) {

  x2 = event->x();
  y2 = event->y();

  currentRectangle.x = 0;
  currentRectangle.y = 0;
  currentRectangle.width = 0;
  currentRectangle.height = 0;

  if (x1 < x2) {
    currentRectangle.x = x1;
    width = x2 - x1;
    if (y1 < y2) {
      height = y2 - y1;
      currentRectangle.y = y1;
      currentRectangle.width = width;
      currentRectangle.height = height;

    } else {
      height = y1 - y2;
      currentRectangle.y = y2;
      currentRectangle.width = width;
      currentRectangle.height = height;
    }
  } else {
    currentRectangle.x = x2;
    width = x1 - x2;
    if (y1 < y2) {
      height = y2 - y1;
      currentRectangle.y = y1;
      currentRectangle.width = width;
      currentRectangle.height = height;
    } else {
      height = y1 - y2;
      currentRectangle.y = y2;
      currentRectangle.width = width;
      currentRectangle.height = height;
    }
  }

  paintImage();
}

void QLabelImage::addQImage(QImage *image) { this->image = image; }

void QLabelImage::setNewImage(QString path) {
  image->load(path);
  pm = QPixmap::fromImage(*image);
  pm = pm.scaled(displayCol, displayRow);
  setPixmap(pm);
  rectangles.clear();
  currentRectangle.x = 0;
  currentRectangle.y = 0;
  currentRectangle.width = 0;
  currentRectangle.height = 0;
  paintImage();
}

std::vector<std::pair<std::string, cv::Rect>>
QLabelImage::getRectangles() {
  return rectangles;
}

void QLabelImage::setCurrentClass(std::string className) {
  this->currentClass = className;
}

void QLabelImage::setCurrentClass(QString className) {
  this->currentClass = className.toStdString();
}

void QLabelImage::paintImage() {
  int x1, y1, height, width;
  pm = QPixmap::fromImage(*image);
  pm = pm.scaled(displayCol, displayRow);
  painter.begin(&(this->pm));
  painter.setPen(Qt::red);
  for (unsigned int pos = 0; pos < rectangles.size(); ++pos) {
    x1 = std::get<1>(rectangles.at(pos)).x;
    y1 = std::get<1>(rectangles.at(pos)).y;
    width = std::get<1>(rectangles.at(pos)).width;
    height = std::get<1>(rectangles.at(pos)).height;
    painter.drawRect(x1, y1, width, height);
  }

  if (currentRectangle.width > 0) {
    painter.drawRect(currentRectangle.x, currentRectangle.y,
                     currentRectangle.width, currentRectangle.height);
  }
  painter.end();
  setPixmap(pm);
}

void QLabelImage::goBack() {
  if (rectangles.size() > 0)
    rectangles.pop_back();
  currentRectangle.x = 0;
  currentRectangle.y = 0;
  currentRectangle.width = 0;
  currentRectangle.height = 0;
  paintImage();
}

void QLabelImage::reset() {
  rectangles.clear();
  currentRectangle.x = 0;
  currentRectangle.y = 0;
  currentRectangle.width = 0;
  currentRectangle.height = 0;
  paintImage();
}
