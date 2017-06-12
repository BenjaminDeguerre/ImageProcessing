#include "mainwindow.h"
#include "roiwizard.h"
#include "roiwizardcutdown.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  classes = new std::vector<std::pair<std::string, std::string>>();
  rs = NULL;
  rsc = NULL;
}

MainWindow::~MainWindow() {
  if (rs) {
    delete rs;
  }
  if (rsc) {
    delete rsc;
  }
  delete ui;
  delete classes;
}

void MainWindow::on_actionROI_Extraction_triggered() {

  int col, row;
  bool resize;
  QString imagesPath;

  classes->clear();

  if (rs) {
    ui->horizontalLayout->removeWidget(rs);
    delete rs;
  }

  if (rsc) {
    ui->horizontalLayout->removeWidget(rsc);
    delete rsc;
    rsc = NULL;
  }

  ROIWizard rw(classes, &imagesPath, &resize, &col, &row);

  if (rw.exec()) {
    rs = new ROISelection(classes, imagesPath, resize, col, row);
    ui->horizontalLayout->addWidget(rs);
  }
}

void MainWindow::on_actionCut_Down_With_Classes_triggered() {

  int col, row, moduleCol, moduleRow;
  bool resize;
  QString imagesPath, basePath;

  classes->clear();

  if (rs) {
    ui->horizontalLayout->removeWidget(rs);
    delete rs;
    rs = NULL;
  }

  if (rsc) {
    ui->horizontalLayout->removeWidget(rsc);
    delete rsc;
  }

  ROIWizardCutDown rw(classes, &imagesPath, &basePath, &resize, &col, &row, &moduleCol, &moduleRow);

  if (rw.exec()) {
    rsc = new ROISelectionCutDown(classes, imagesPath, basePath, resize, col, row, moduleCol, moduleRow);
    ui->horizontalLayout->addWidget(rsc);
  }
}
