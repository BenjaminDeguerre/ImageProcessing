#include "parameterpage.h"
#include "ui_parameterpage.h"

ParameterPage::ParameterPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ParameterPage)
{
    ui->setupUi(this);
}

ParameterPage::~ParameterPage()
{
    delete ui;
}
