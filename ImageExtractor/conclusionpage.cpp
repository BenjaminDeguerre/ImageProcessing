#include "conclusionpage.h"
#include "ui_conclusionpage.h"

ConclusionPage::ConclusionPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ConclusionPage)
{
    ui->setupUi(this);
}

ConclusionPage::~ConclusionPage()
{
    delete ui;
}
