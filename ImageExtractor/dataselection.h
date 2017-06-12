#ifndef DATASELECTION_H
#define DATASELECTION_H

#include <QFrame>

namespace Ui {
class DataSelection;
}

class DataSelection : public QFrame
{
    Q_OBJECT

public:
    explicit DataSelection(QWidget *parent = 0);
    ~DataSelection();

private:
    Ui::DataSelection *ui;
};

#endif // DATASELECTION_H
