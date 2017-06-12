#include "dataselection.h"
#include "ui_dataselection.h"

DataSelection::DataSelection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DataSelection)
{
    ui->setupUi(this);
}

DataSelection::~DataSelection()
{
    delete ui;
}
