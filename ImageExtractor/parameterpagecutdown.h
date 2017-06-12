#ifndef PARAMETERPAGECUTDOWN_H
#define PARAMETERPAGECUTDOWN_H

#include <QWizardPage>

namespace Ui {
  class ParameterPageCutDown;
}

class ParameterPageCutDown : public QWizardPage
{
    Q_OBJECT

  public:
    explicit ParameterPageCutDown(QWidget *parent = 0);
    ~ParameterPageCutDown();

  private:
    Ui::ParameterPageCutDown *ui;
};

#endif // PARAMETERPAGECUTDOWN_H
