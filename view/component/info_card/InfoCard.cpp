#include "InfoCard.h"
#include <QListWidgetItem>
#include <QPushButton>
#include <QScrollArea>

InfoCard::InfoCard(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    containerWidget = new QWidget(this);
    containerWidget->setObjectName("main");

    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);

    headerLabel = new QLabel(containerWidget);
    headerLabel->setAlignment(Qt::AlignCenter);
    headerLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
    headerLabel->setFixedHeight(30);

    QFrame *line = new QFrame(containerWidget);
    line->setFrameShape(QFrame::HLine);
    line->setLineWidth(3);
    line->setStyleSheet("QFrame { border: 3px solid black; }");

    // Layout nội dung
    QWidget *contentWidget = new QWidget(containerWidget);
    contentLayout = new QVBoxLayout(contentWidget);
    containerLayout->addWidget(headerLabel);
    containerLayout->addWidget(line);
    containerLayout->addWidget(contentWidget);
    mainLayout->addWidget(containerWidget);
    // setLayout(layout);
}
void InfoCard::setHeaderText(const QString &text)
{
    headerLabel->setText(text);
}

void InfoCard::addContentLine(const QList<QPair<QString, QString>> &labels)
{
    QHBoxLayout *lineLayout = new QHBoxLayout();

    if (labels.size() == 1)
    {
        IconLabel *iconLabel = new IconLabel();
        iconLabel->setIconPath(labels[0].first, 14);
        iconLabel->setText(labels[0].second, 14);

        lineLayout->addStretch();
        lineLayout->addWidget(iconLabel);
        lineLayout->addStretch();

        QWidget *wrapper = new QWidget(this);
        wrapper->setLayout(lineLayout);

        contentLayout->addWidget(wrapper);
    }
    else
    {
        for (const auto &pair : labels)
        {
            IconLabel *iconLabel = new IconLabel();
            iconLabel->setIconPath(pair.first, 14);
            iconLabel->setText(pair.second, 14);
            lineLayout->addWidget(iconLabel, 1);
        }

        QWidget *wrapper = new QWidget(this);
        wrapper->setLayout(lineLayout);
        contentLayout->addWidget(wrapper);
    }

}

void InfoCard::setBGColor(QString color)
{
    containerWidget->setStyleSheet(QString("#main { background-color: %1;  border-radius: 10px;}")
                                       .arg(color));
}
 