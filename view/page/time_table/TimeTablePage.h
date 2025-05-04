#ifndef TIMETABLEPAGE_H
#define TIMETABLEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "../../component/info_card/InfoCardList.h"
#include "../../component/info_card/InfoCard.h"
#include "../../component/button_action/ButtonAction.h"
#include "../../component/form_dialog/FormDialog.h"
#include "../../../model/time_table/TimeTableManager.h"


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
 