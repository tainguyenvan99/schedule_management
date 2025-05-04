#include "HeaderBar.h"

HeaderBar::HeaderBar(int headerWidth, int headerHeight, QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    setFixedSize(headerWidth, headerHeight);

    leftButton = new QPushButton("☰", this);
    leftButton->setFixedSize(36, 36);

    headerLabel = new QLabel(m_headerText, this);
    headerLabel->setStyleSheet("font-size: 36px; font-weight: 600;");
    headerLabel->setContentsMargins(-36, 0, 0, 0);
    headerLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(leftButton);
    layout->addWidget(headerLabel);

    setLayout(layout);
    setStyleSheet(R"(
            font-family: Irish Grover;
            font-weight: 200;
            font-size: 24px;
        )");
}

QPushButton *HeaderBar::button()
{
    return leftButton;
}

QString HeaderBar::getHeaderTitle()
{
    return m_headerText;
}

void HeaderBar::setHeaderTitle(QString title)
{
    m_headerText = title;
    headerLabel->setText(title);
    emit headerTitleChanged();
}
 