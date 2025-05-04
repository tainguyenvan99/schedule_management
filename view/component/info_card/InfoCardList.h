#ifndef INFOCARDLIST_H
#define INFOCARDLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "InfoCard.h"

class InfoCardList : public QWidget
{
    Q_OBJECT

public:
    explicit InfoCardList(QWidget *parent = nullptr);

    InfoCard *addCard(const QString &headerText, const QString &bgColor);

    void clearCards();

private:
    QVBoxLayout *mainLayout;
    QWidget *containerWidget;
    QVBoxLayout *cardsLayout;
};

#endif // INFOCARDLIST_H
 