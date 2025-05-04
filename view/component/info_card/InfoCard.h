#ifndef INFOCARD_H
#define INFOCARD_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include "../icon_label/IconLabel.h"

class InfoCard : public QWidget
{
    Q_OBJECT

public:
    explicit InfoCard(QWidget *parent = nullptr);
    void setHeaderText(const QString &text);
    void addContentLine(const QList<QPair<QString, QString>> &labels);
    void setBGColor(QString color);

private:
    QLabel *headerLabel;
    QVBoxLayout *mainLayout;
    QVBoxLayout *contentLayout;
    QWidget *containerWidget;
    QString bGColor;
};

#endif
 