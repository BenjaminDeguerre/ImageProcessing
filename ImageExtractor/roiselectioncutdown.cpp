#include "roiselectioncutdown.h"
#include "ui_roiselectioncutdown.h"

ROISelectionCutDown::ROISelectionCutDown(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ROISelectionCutDown)
{
  ui->setupUi(this);
}

ROISelectionCutDown::~ROISelectionCutDown()
{
  delete ui;
}
