#ifndef HEADERBAR_H
#define HEADERBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class HeaderBar : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderBar(int headerWidth, int headerHeight, QWidget *parent = nullptr);

    Q_PROPERTY(QString headerTitle READ getHeaderTitle WRITE setHeaderTitle NOTIFY headerTitleChanged)

    QPushButton *button();
signals:
    void headerTitleChanged();

public slots:
    void setHeaderTitle(QString title);
    QString getHeaderTitle();

private:
    QString m_headerText;
    QLabel *headerLabel;
    QPushButton *leftButton;
};

#endif