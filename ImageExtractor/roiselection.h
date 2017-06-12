#ifndef ROISELECTION_H
#define ROISELECTION_H

#include <QWidget>

namespace Ui {
  class ROISelection;
}

class ROISelection : public QWidget
{
    Q_OBJECT

  public:
    explicit ROISelection(QWidget *parent = 0);
    ~ROISelection();

  private:
    Ui::ROISelection *ui;
};

#endif // ROISELECTION_H
