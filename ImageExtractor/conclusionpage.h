#ifndef CONCLUSIONPAGE_H
#define CONCLUSIONPAGE_H

#include <QWizardPage>

namespace Ui {
class ConclusionPage;
}

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ConclusionPage(QWidget *parent = 0);
    ~ConclusionPage();

private:
    Ui::ConclusionPage *ui;
};

#endif // CONCLUSIONPAGE_H
