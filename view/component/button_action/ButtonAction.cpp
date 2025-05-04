#include "ButtonAction.h"

ButtonAction::ButtonAction(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    btn = new QPushButton(this);
    btn->setCursor(Qt::PointingHandCursor);
    connect(btn, &QPushButton::clicked, this, &ButtonAction::onBtnClicked);
    layout->addWidget(btn);
}
void ButtonAction::setBtnName(QString btnName)
{
    btn->setText(btnName);
}
void ButtonAction::setIcon(QString icon, int size)
{
    btn->setIcon(QIcon(icon));
    btn->setIconSize(QSize(size, size));
    btn->setStyleSheet("background: transparent;border: none;");
}
QPushButton *ButtonAction::getBtn()
{
    return btn;
}
void ButtonAction::onPageChange(const QString &pageName)
{
    qDebug() << pageName;
}
void ButtonAction::onBtnClicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if (btn)
    {
        emit btnClicked(btn->text());
    }
}