#include "SubmissionPage.h"
#include <QLabel>
#include <QPushButton>
#include "RandomColor.h"


SubmissionPage::SubmissionPage(QWidget *parent) : QWidget(parent)
{
    resize(390, 800);
    mainLayout = new QVBoxLayout(this);
    QWidget *topPart = new QWidget(this);
    QHBoxLayout *topLayout = new QHBoxLayout(topPart);
    QLabel *titleLabel = new QLabel("Pending Submissions", this);
    QFont font = titleLabel->font();
    font.setPointSize(24);
    font.setBold(true); 
    titleLabel->setFont(font);
    topLayout->addWidget(titleLabel);

    QWidget *bottomPart = new QWidget(this);
    bottomLayout = new QVBoxLayout(bottomPart);

    mainLayout->addWidget(topPart);
    mainLayout->addWidget(bottomPart);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    btnFooter = new ButtonAction(this);
    btnFooter->setIcon("../../assets/add.png", 65);
    btnFooter->setFixedSize(65, 65);
    btnFooter->move(this->width() - btnFooter->width() - 20, this->height() - btnFooter->height() - 110);

    formDialog = new FormDialog();
    infoCardList = new InfoCardList(this);
    submissionManager = new SubmissionManager();
    submissionManager->loadFromJson("../../data/submissions.json");

    initializeDialog();
    initializeItem();
    
    connect(btnFooter->getBtn(), &QPushButton::clicked, this, &SubmissionPage::openFormDialog);
}

SubmissionPage::~SubmissionPage()
{
    delete formDialog;
    delete submissionManager;
}

void SubmissionPage::initializeItem()
{
    infoCardList->clearCards();   
    QList<Submission> list = submissionManager->getAll();
    for (const Submission& s : list) {
        infoCard = infoCardList->addCard(s.subject(), getRandomColorString());
        infoCard->addContentLine({{"../../assets/calendar.png", s.desc()}});
        infoCard->addContentLine({{"../../assets/calendar.png", "Deadline: " + s.deadline()}});
    }
    bottomLayout->addWidget(infoCardList);
}

void SubmissionPage::initializeDialog()
{
    formDialog->setHeaderTitle("Add Submission: ");
    formDialog->addContentLine("Subject: ");
    formDialog->addContentLine("Description: ");
    formDialog->addContentLine("Deadline: ");
}

void SubmissionPage::openFormDialog()
{
    Submission newSubmission;
    if (formDialog->exec() == QDialog::Accepted)
    {
        QVector<QPair<QString, QString>> entries = formDialog->getLabelInputPairs();
        for (const auto &entry : entries)
        {
            if (entry.first == "Subject: ")
                newSubmission.setSubject(entry.second);
            else if (entry.first == "Description: ")
                newSubmission.setDesc(entry.second);
            else if (entry.first == "Deadline: ")
                newSubmission.setDeadline(entry.second);
        }
        submissionManager->saveToJson("../../data/submissions.json", newSubmission);
        submissionManager->loadFromJson("../../data/submissions.json");
        initializeItem();
    }
}
