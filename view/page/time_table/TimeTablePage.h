#ifndef TIMETABLEPAGE_H
#define TIMETABLEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "InfoCardList.h"
#include "InfoCard.h"
#include "ButtonAction.h"
#include "FormDialog.h"
#include "TimeTableManager.h"


class TimeTablePage : public QWidget
{
    Q_OBJECT

public:
    explicit TimeTablePage(QWidget *parent = nullptr);
    ~TimeTablePage();
    void initializeDialog();

private slots:
    void initializeItem(const QString &dayOfWeek);
    void openFormDialog();
    // void loadDataWhenFormAccepted(const QVector<QPair<QString, QString>> &entries);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *bottomLayout;


    ButtonAction *btnDay;
    InfoCardList *infoCardList;
    InfoCard *infoCard;
    ButtonAction *btnFooter;
    FormDialog *formDialog;

    TimeTableManager *timeTableManager; 
};

#endif // TIMETABLE_H
 