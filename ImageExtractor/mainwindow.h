#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <string>

#include "roiselection.h"
#include "roiselectioncutdown.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_actionROI_Extraction_triggered();

  void on_actionCut_Down_With_Classes_triggered();

  private:

  Ui::MainWindow* ui;

  ROISelection *rs;
  ROISelectionCutDown *rsc;

  std::vector<std::pair<std::string, std::string>> *classes;
};

#endif  // MAINWINDOW_H
