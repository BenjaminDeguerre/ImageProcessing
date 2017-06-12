#include "roiselection.h"
#include "ui_roiselection.h"

ROISelection::ROISelection(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ROISelection)
{
  ui->setupUi(this);
}

ROISelection::~ROISelection()
{
  delete ui;
}
