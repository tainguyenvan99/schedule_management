#ifndef EXAMPAGE_H
#define EXAMPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "ButtonAction.h"
#include "InfoCardList.h"
#include "FormDialog.h"
#include "ExamManager.h"

class ExamPage : public QWidget
{
    Q_OBJECT
public:
    explicit ExamPage(QWidget *parent = nullptr);
    ~ExamPage();

private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *bottomLayout;
    ButtonAction *btnFooter;
    FormDialog *formDialog;
    InfoCardList *infoCardList;
    InfoCard *infoCard;
    ExamManager *examManager;

    void initializeDialog();
    void initializeItem();
    void openFormDialog();
};

#endif // EXAMPAGE_H
