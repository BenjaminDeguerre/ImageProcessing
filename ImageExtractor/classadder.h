#ifndef CLASSADDER_H
#define CLASSADDER_H

#include <QDialog>

namespace Ui {
class ClassAdder;
}

class ClassAdder : public QDialog
{
    Q_OBJECT

public:
    explicit ClassAdder(QWidget *parent = 0);
    ~ClassAdder();

private:
    Ui::ClassAdder *ui;
};

#endif // CLASSADDER_H
