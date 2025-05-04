#ifndef BUTTONACTION_H
#define BUTTONACTION_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

class ButtonAction : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonAction(QWidget *parent = nullptr);
    void setBtnName(QString btnName);
    void setIcon(QString icon, int size);
    QPushButton *getBtn();
signals:
    void btnClicked(const QString &btnName);
private slots:
    void onBtnClicked();
public slots:
    void onPageChange(const QString &pageName);

private:
    QPushButton *btn;
};

#endif