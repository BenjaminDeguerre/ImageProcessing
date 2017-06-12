#ifndef CLASSADDER_H
#define CLASSADDER_H

#include <QDialog>
#include <QString>


namespace Ui {
class ClassAdder;
}

class ClassAdder : public QDialog {
  Q_OBJECT

public:
  ClassAdder(QString *className, QString *path, QWidget *parent = 0);
  ~ClassAdder();

private slots:
  void on_pushButton_clicked();

  void on_buttonBox_accepted();

private:
  Ui::ClassAdder *ui;
  QString *className;
  QString *path;

};

#endif // CLASSADDER_H
