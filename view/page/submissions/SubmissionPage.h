#ifndef SUBMISSIONPAGE_H
#define SUBMISSIONPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "ButtonAction.h"
#include "InfoCardList.h"
#include "FormDialog.h"
#include "SubmissionManager.h"

class SubmissionPage : public QWidget
{
    Q_OBJECT
public:
    explicit SubmissionPage(QWidget *parent = nullptr);
    ~SubmissionPage();

private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *bottomLayout;
    ButtonAction *btnFooter;
    FormDialog *formDialog;
    InfoCardList *infoCardList;
    InfoCard *infoCard;
    SubmissionManager *submissionManager;

    void initializeDialog();
    void initializeItem();
    void openFormDialog();
};

#endif // SUBMISSIONPAGE_H
