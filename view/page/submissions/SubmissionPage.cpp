#include "SubmissionPage.h"

SubmissionPage::SubmissionPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("This is submission page", this));
}
 