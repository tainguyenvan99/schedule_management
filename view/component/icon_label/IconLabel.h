#ifndef ICONLABLE_H
#define ICONLABLE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>

class IconLabel : public QWidget
{
    Q_OBJECT

public:
    explicit IconLabel(QWidget *parent = nullptr);

    QString getText();
    void setText(QString text, int size);
    QString getIconPath();
    void setIconPath(QString iconPath, int size);
    void setAsButton(bool isButton);
signals:
    void clicked(QString text);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QLabel *iconLabel;
    QLabel *textLabel;
    bool isButtonMode = true;
};

#endif