#include "IconLabel.h"
#include <QPixmap>
#include <QMouseEvent>

IconLabel::IconLabel(QWidget *parent)
    : QWidget(parent)
{
    iconLabel = new QLabel(this);
    textLabel = new QLabel(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(iconLabel);
    layout->addWidget(textLabel);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(16);
    setLayout(layout);
}

QString IconLabel::getText()
{
    return textLabel->text();
}

void IconLabel::setText(QString text, int size)
{
    textLabel->setText(text);
    textLabel->setStyleSheet(QString(R"(
        font-family: Inria Serif;
        font-weight: 400;
        font-size: %1px;
    )")
                                 .arg(size));
}

QString IconLabel::getIconPath()
{
    return iconLabel->text();
}

void IconLabel::setIconPath(QString iconPath, int size)
{
    QPixmap icon(iconPath);
    iconLabel->setPixmap(icon);
    iconLabel->setFixedSize(size, size);
    iconLabel->setScaledContents(true);
}

void IconLabel::setAsButton(bool isButton)
{
    isButtonMode = isButton;
}

void IconLabel::mousePressEvent(QMouseEvent *event)
{
    if (isButtonMode)
    {
        emit clicked(getText());
        QWidget::mousePressEvent(event);
    }
}
 