#include "dataselection.h"
#include "ui_dataselection.h"

#include "roiselectioninterface.h"

#include <iostream>

DataSelection::DataSelection(QWidget *parent)
    : QFrame(parent), ui(new Ui::DataSelection) {
  ui->setupUi(this);
  connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem *)), SLOT(on_listWidget_itemClicked(QListWidgetItem *)));
}

DataSelection::~DataSelection() {
  delete ui;
  for (QVector<QListWidgetItem*>::iterator it = items.begin(); it != items.end(); ++it) {
    delete (*it);
  }
  items.clear();
}

void DataSelection::addItem(QString text) {
  items.push_back(new QListWidgetItem(text));
  ui->listWidget->addItem(items.last());
}

void DataSelection::disable() {
  ui->pushButton->setEnabled(false);
  ui->pushButton_2->setEnabled(false);
  ui->pushButton_3->setEnabled(false);
}

void DataSelection::on_pushButton_clicked() {
  qobject_cast<ROISelectionInterface *>(this->parent()->parent())->processCurrentImage();
  qobject_cast<ROISelectionInterface *>(this->parent()->parent())->loadNextImage();
}

void DataSelection::on_pushButton_2_clicked() {
  qobject_cast<ROISelectionInterface *>(this->parent()->parent())->resetImage();
}

void DataSelection::on_pushButton_3_clicked() {
  qobject_cast<ROISelectionInterface *>(this->parent()->parent())
      ->resetLastActionImage();
}

void DataSelection::on_listWidget_itemClicked(QListWidgetItem *item) {
  ui->pushButton->setEnabled(true);
  ui->pushButton_2->setEnabled(true);
  ui->pushButton_3->setEnabled(true);
  qobject_cast<ROISelectionInterface*>(this->parent()->parent())
      ->setClass(item->text());
}
