#include "intropage.h"
#include "ui_intropage.h"

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent), ui(new Ui::IntroPage) {
  ui->setupUi(this);

  setTitle(tr("Introduction"));
}

IntroPage::~IntroPage() { delete ui; }
