#ifndef TEACHERPAGE_H
#define TEACHERPAGE_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>

#include "InfoCardList.h"
#include "InfoCard.h"
#include "ButtonAction.h"
#include "FormDialog.h"
#include "Teacher.h"
#include "TeacherManager.h"

class TeacherPage : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherPage(QWidget *parent = nullptr);
    ~TeacherPage();

    void initializeDialog();

private slots:
    void initializeItem();
    void openFormDialog();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *bottomLayout;

    InfoCardList *infoCardList;
    InfoCard *infoCard;
    ButtonAction *btnFooter;
    FormDialog *formDialog;

    TeacherManager *teacherManager; // Assuming you have a TeacherManager class to manage teacher data
};

#endif
 