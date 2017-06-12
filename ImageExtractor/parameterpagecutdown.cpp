#include "parameterpagecutdown.h"
#include "ui_parameterpagecutdown.h"

ParameterPageCutDown::ParameterPageCutDown(QWidget *parent) :
  QWizardPage(parent),
  ui(new Ui::ParameterPageCutDown)
{
  ui->setupUi(this);
}

ParameterPageCutDown::~ParameterPageCutDown()
{
  delete ui;
}
