#include "roiselectioncutdown.h"
#include "ui_roiselectioncutdown.h"

#include <QDir>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <utility>

ROISelectionCutDown::ROISelectionCutDown(
    std::vector<std::pair<std::string, std::string>> *classes,
    QString imagesPath, QString basePath, bool resize, int col, int row,
    int moduleCol, int moduleRow, QWidget *parent)
    : ROISelectionInterface(parent), resize(resize), col(col), row(row),
      moduleCol(moduleCol), moduleRow(moduleRow), imagesPath(imagesPath),
      basePath(basePath), classes(classes), ui(new Ui::ROISelectionCutDown) {

  // Setting up the ui.
  ui->setupUi(this);

  // Display size (could be improved to fit the window or to implement zoom
  displayCol = 512;
  displayRow = 512;

  // Setting the iterator for the images
  this->posCurrentImage = 0;

  // Loading all the file names
  QDir dir(imagesPath);
  imagesName = dir.entryList(QDir::Files);

  // Creating the left side of the selection tool
  ds = new DataSelection();

  // Adding each class to the left pane
  for (unsigned int i = 0; i < classes->size(); i++) {
    ds->addItem(QString::fromStdString(std::get<0>(classes->at(i))));
  }

  // Creating the right pane with the image
  qli = new QLabelImage(imagesPath + "/" + imagesName.at(posCurrentImage));

  // Handling the display splitter
  splitter.addWidget(ds);
  splitter.addWidget(qli);
  ui->horizontalLayout->addWidget(&splitter);
}

ROISelectionCutDown::~ROISelectionCutDown() {
  delete ds;
  delete qli;
  delete ui;
}

void ROISelectionCutDown::loadNextImage() {

  if (posCurrentImage == (imagesName.size() - 1)) {
    ds->disable();
  } else {
    qli->setNewImage(imagesPath + "/" + imagesName.at(++posCurrentImage));
  }
}

void ROISelectionCutDown::processCurrentImage() {

  // Load the image with opencv
  cv::Mat imageCV = cv::imread(imagesPath.toStdString() + "/" +
                               imagesName.at(posCurrentImage).toStdString());

  bool noClass = true;
  std::string roiName, classPath, currentClass;
  unsigned int checkPos = 0;

  int colImage, rowImage, rowCutNumber, colCutNumber, rowPos, colPos;

  // resizing the image if required
  if (resize) {
    cv::resize(imageCV, imageCV, cv::Size(col, row));
  }

  colImage = imageCV.cols;
  rowImage = imageCV.rows;

  // Getting file info to create the name of the ROI file once extracted
  QFileInfo fi(imagesName.at(posCurrentImage));
  QString baseName = fi.baseName();

  // Getting all the rectangles drawn and the class name associated
  std::vector<std::pair<std::string, cv::Rect>> positions =
      qli->getRectangles();

  rowCutNumber = rowImage / moduleRow;
  colCutNumber = colImage / moduleCol;
  // Extracting all the module from the image and saving them in the right
  // directory
  for (int row = 0; row < rowCutNumber; row++) {
    for (int col = 0; col < colCutNumber; col++) {

      rowPos = row * moduleRow;
      colPos = col * moduleCol;

      cv::Rect input(colPos, rowPos, moduleCol, moduleRow);

      noClass = true;
      for (unsigned int classNum = 0; classNum < positions.size(); classNum++) {
        cv::Rect target = std::get<1>(positions.at(classNum));

        target.x = (int)(target.x * colImage / displayCol);
        target.y = (int)(target.y * rowImage / displayRow);
        target.width = (int)(target.width * colImage / displayCol);
        target.height = (int)(target.height * rowImage / displayRow);

        if (isInsideRectTarget(input, target)) {
          noClass = false;
          checkPos = 0;
          do {
            if (std::get<0>(classes->at(checkPos))
                    .compare(std::get<0>(positions.at(classNum))) == 0) {
              classPath = std::get<1>(classes->at(checkPos));
              currentClass = std::get<0>(classes->at(checkPos));
            }
            checkPos++;
          } while (std::get<0>(classes->at(checkPos - 1))
                           .compare(std::get<0>(positions.at(classNum))) != 0 &&
                   checkPos < classes->size());
          roiName = classPath + "/" + baseName.toStdString() + currentClass +
                    std::to_string(row) + "0123546" + std::to_string(col) +
                    ".png";
          imwrite(roiName,
                  imageCV(cv::Rect(colPos, rowPos, moduleCol, moduleRow)));
        }
      }
      if (noClass) {
        roiName = basePath.toStdString() + "/" + baseName.toStdString() +
                  std::to_string(row) + "0123546" + std::to_string(col) +
                  ".png";
        imwrite(roiName,
                imageCV(cv::Rect(colPos, rowPos, moduleCol, moduleRow)));
      }

    }
  }
}

void ROISelectionCutDown::resetImage() { qli->reset(); }

void ROISelectionCutDown::resetLastActionImage() { qli->goBack(); }

void ROISelectionCutDown::setClass(QString name) { qli->setCurrentClass(name); }

bool ROISelectionCutDown::isInsideRectTarget(cv::Rect input, cv::Rect target) {

  if (((input.x > target.x && input.x < target.x + target.width) ||
       (input.x + input.width > target.x &&
        input.x + input.width < target.x + target.width) ||
       (input.x < target.x &&
        input.x + input.width > target.x + target.width)) &&
      ((input.y > target.y && input.y < target.y + target.height) ||
       (input.y + input.height > target.y &&
        input.y + input.height < target.y + target.height) ||
       (input.y < target.y &&
        input.y + input.height > target.y + target.height))) {
    return true;
  } else {
    return false;
  }
}
