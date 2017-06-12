#ifndef PARAMETERPAGE_H
#define PARAMETERPAGE_H

#include <QWizardPage>

namespace Ui {
class ParameterPage;
}

class ParameterPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ParameterPage(QWidget *parent = 0);
    ~ParameterPage();

private:
    Ui::ParameterPage *ui;
};

#endif // PARAMETERPAGE_H
