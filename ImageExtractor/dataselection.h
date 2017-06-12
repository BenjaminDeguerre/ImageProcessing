#ifndef DATASELECTION_H
#define DATASELECTION_H

#include <QFrame>
#include <QString>
#include <QListWidgetItem>
#include <QVector>

namespace Ui {
class DataSelection;
}

class DataSelection : public QFrame {
  Q_OBJECT

public:
  explicit DataSelection(QWidget *parent = 0);
  void addItem(QString text);
  void disable();
  ~DataSelection();

  private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_listWidget_itemClicked(QListWidgetItem *item);

  private:
  Ui::DataSelection *ui;

  QVector<QListWidgetItem*> items;
};

#endif // DATASELECTION_H
