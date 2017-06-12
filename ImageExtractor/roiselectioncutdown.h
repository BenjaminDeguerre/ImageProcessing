#ifndef ROISELECTIONCUTDOWN_H
#define ROISELECTIONCUTDOWN_H

#include <QWidget>

namespace Ui {
  class ROISelectionCutDown;
}

class ROISelectionCutDown : public QWidget
{
    Q_OBJECT

  public:
    explicit ROISelectionCutDown(QWidget *parent = 0);
    ~ROISelectionCutDown();

  private:
    Ui::ROISelectionCutDown *ui;
};

#endif // ROISELECTIONCUTDOWN_H
