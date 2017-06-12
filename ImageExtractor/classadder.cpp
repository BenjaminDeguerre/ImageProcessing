#include "classadder.h"
#include "ui_classadder.h"

ClassAdder::ClassAdder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassAdder)
{
    ui->setupUi(this);
}

ClassAdder::~ClassAdder()
{
    delete ui;
}
