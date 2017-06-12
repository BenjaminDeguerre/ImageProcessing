#ifndef ROISELECTIONINTERFACE_H
#define ROISELECTIONINTERFACE_H

#include <QString>
#include <QWidget>

class ROISelectionInterface : public QWidget {
    Q_OBJECT
public:
  explicit ROISelectionInterface(QWidget *parent = 0);
  ~ROISelectionInterface();
  virtual void setClass(QString name) = 0;
  virtual void resetImage() = 0;
  virtual void resetLastActionImage() = 0;
  virtual void processCurrentImage() = 0;
  virtual void loadNextImage() = 0;
};

#endif // ROISELELCTIONINTERFACE_H
