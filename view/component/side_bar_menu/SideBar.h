#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include "../icon_label/IconLabel.h"
#include "../header_bar/HeaderBar.h"

class Sidebar : public QWidget
{
    Q_OBJECT

public:
    explicit Sidebar(QWidget *parent = nullptr);

signals:
    void pageSelected(const QString &pageTitle);

public slots:
    void onIconLabelClicked(const QString &labelName);
    void onBtnHeaderClick();
    void hideSideBar();

private:
    IconLabel *iconLabel;
    QWidget *sidebar;
    QPropertyAnimation *sidebarAnimation;
    HeaderBar *headerBar;
    QLabel *titleHeaderSidebar;
    QString sidebarHeaderTitle = "Time Table";
};
#endif
 