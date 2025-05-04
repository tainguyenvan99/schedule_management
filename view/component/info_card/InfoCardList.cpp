#include "InfoCardList.h"

InfoCardList::InfoCardList(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    containerWidget = new QWidget(this);
    cardsLayout = new QVBoxLayout(containerWidget);
    containerWidget->setLayout(cardsLayout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    mainLayout->addWidget(scrollArea); 
    setLayout(mainLayout);
}

InfoCard *InfoCardList::addCard(const QString &headerText, const QString &bgColor)
{
    InfoCard *card = new InfoCard(containerWidget);
    card->setHeaderText(headerText);
    card->setBGColor(bgColor);
    cardsLayout->addWidget(card);
    card->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    cardsLayout->setAlignment(Qt::AlignTop);
    return card;
}

void InfoCardList::clearCards()
{
    QLayoutItem *item;
    while ((item = cardsLayout->takeAt(0)) != nullptr)
    {
        QWidget *widget = item->widget();
        if (widget)
        {
            widget->deleteLater();
        }
        delete item;
    }
}
 