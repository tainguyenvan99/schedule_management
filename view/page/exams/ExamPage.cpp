#include "ExamPage.h"

ExamPage::ExamPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("This is exam page", this));
}
 