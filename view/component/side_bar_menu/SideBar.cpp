#include "SideBar.h"
#include <QHash>
#include <QString>
#include <QDir>

Sidebar::Sidebar(QWidget *parent)
    : QWidget(parent)
{
    sidebar = new QWidget(this);
    sidebar->setFixedWidth(313);
    sidebar->setFixedHeight(800);
    sidebar->setStyleSheet("background-color;#F88103;");

    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setSpacing(10);
    sidebarLayout->setContentsMargins(0, 0, 0, 0);
    QWidget *headerWidget = new QWidget(sidebar);
    headerWidget->setStyleSheet(R"(
        background: #FE9900;
    )");
    QVBoxLayout *headerLayout = new QVBoxLayout(headerWidget);

    QLabel *labelImage = new QLabel(this);
    QPixmap pixmap("../../assets/logo.png");

    labelImage->setMaximumSize(171, 171);
    pixmap = pixmap.scaled(labelImage->maximumSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    labelImage->setPixmap(pixmap);
    labelImage->setScaledContents(true);
    labelImage->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(labelImage);

    titleHeaderSidebar = new QLabel(this);
    headerLayout->addWidget(titleHeaderSidebar);
    headerLayout->setAlignment(Qt::AlignCenter);

    sidebarLayout->addWidget(headerWidget);

    // data
    QList<QPair<QString, QString>> infoList;
    infoList.append(qMakePair(QString("Time Table"), QString("../../assets/calendar.png")));
    infoList.append(qMakePair(QString("Exam"), QString("../../assets/graduate.png")));
    infoList.append(qMakePair(QString("Teachers"), QString("../../assets/people.png")));
    infoList.append(qMakePair(QString("Submissions"), QString("../../assets/agenda.png")));

    for (const auto &pair : infoList)
    {
        iconLabel = new IconLabel();
        iconLabel->setIconPath(pair.second, 24);
        iconLabel->setText(pair.first, 20);
        iconLabel->setContentsMargins(10, 0, 0, 0);
        sidebarLayout->addWidget(iconLabel);
        connect(iconLabel, &IconLabel::clicked, this, &Sidebar::onIconLabelClicked);
    }
    sidebarLayout->addStretch();
    sidebarAnimation = new QPropertyAnimation(this, "pos", this);
    sidebarAnimation->setDuration(300);

    setStyleSheet(R"(
        background: #FFFFFF;
    )");
}

void Sidebar::onBtnHeaderClick()
{
    if (this->x() < 0)
    {
        sidebarAnimation->setStartValue(QPoint(-313, 0));
        sidebarAnimation->setEndValue(QPoint(0, 0));
    }
    else
    {
        sidebarAnimation->setStartValue(QPoint(0, 0));
        sidebarAnimation->setEndValue(QPoint(-313, 0));
    }
    sidebarAnimation->start();
}

void Sidebar::hideSideBar()
{
    if (this->x() >= 0)
    {
        sidebarAnimation->setStartValue(QPoint(0, 0));
        sidebarAnimation->setEndValue(QPoint(-313, 0));
        sidebarAnimation->start();
    }
}

void Sidebar::onIconLabelClicked(const QString &labelName)
{
    hideSideBar();
    titleHeaderSidebar->setText(labelName);
    emit pageSelected(labelName);
}
 