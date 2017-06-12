#include "roiselection.h"
#include "ui_roiselection.h"

#include <QDir>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <utility>

ROISelection::ROISelection(
    std::vector<std::pair<std::string, std::string>> *classes,
    QString imagesPath, bool resize, int col, int row, QWidget *parent)
    :ROISelectionInterface(parent), resize(resize), col(col), row(row),
      imagesPath(imagesPath), classes(classes), ui(new Ui::ROISelection) {

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

ROISelection::~ROISelection() {
  delete ds;
  delete qli;
  delete ui;
}

void ROISelection::loadNextImage() {

  if (posCurrentImage == (imagesName.size() - 1)) {
    ds->disable();
  } else {
    qli->setNewImage(imagesPath + "/" + imagesName.at(++posCurrentImage));
  }
}

void ROISelection::processCurrentImage() {

  // Load the image with opencv
  cv::Mat imageCV = cv::imread(imagesPath.toStdString() + "/" +
                             imagesName.at(posCurrentImage).toStdString());

  std::string roiName, classPath, currentClass;
  double x1, y1, width, height;
  unsigned int checkPos;

  int colImage, rowImage;

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

  // Extracting and saving all the ROI selected
  for (unsigned int rectNum = 0; rectNum < positions.size(); rectNum++) {

    // Getting the current ROI to handle
    std::pair<std::string, cv::Rect> currentROI = positions.at(rectNum);
    checkPos = 0;

    // Can be improved
    // Checking the class associated with the roi to know where to save the
    // image
    do {
      if (std::get<0>(classes->at(checkPos)).compare(std::get<0>(currentROI)) ==
          0) {
        classPath = std::get<1>(classes->at(checkPos));
        currentClass = std::get<0>(classes->at(checkPos));
      }
      checkPos++;
    } while (std::get<0>(classes->at(checkPos - 1))
                     .compare(std::get<0>(currentROI)) != 0 &&
             checkPos < classes->size());

    // Setting the output name for the extracted image
    roiName = classPath + "/" + baseName.toStdString() +
              currentClass + std::to_string(rectNum) + ".png";

    // Getting the ROI coordinate
    x1 = std::get<1>(currentROI).x * colImage / displayCol;
    y1 = std::get<1>(currentROI).y * rowImage / displayRow;
    width = std::get<1>(currentROI).width * colImage / displayCol;
    height = std::get<1>(currentROI).height * rowImage / displayRow;

    // checking if the rectangle are bigger than the image
    if (x1 < 0){
      width += x1;
      x1 =0;
    }
    if (y1 < 0){
      height += y1;
      y1 = 0;
    }

    if (x1 + width > colImage)
      width = colImage - x1;

    if (y1 + height > rowImage)
      height = rowImage - y1;

    // Saving the image
    imwrite(roiName, imageCV(cv::Rect(x1, y1, width, height)));
  }
}

void ROISelection::resetImage() { qli->reset(); }

void ROISelection::resetLastActionImage() { qli->goBack(); }

void ROISelection::setClass(QString name) {
  qli->setCurrentClass(name);
}
