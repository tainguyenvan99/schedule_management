#include "TeacherPage.h"

TeacherPage::TeacherPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("This is teacher page", this));
}
 