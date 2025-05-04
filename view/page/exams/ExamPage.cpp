#include "ExamPage.h"
#include <QLabel>
#include <QPushButton>
#include "RandomColor.h"

ExamPage::ExamPage(QWidget *parent) : QWidget(parent)
{
    resize(390, 800);
    mainLayout = new QVBoxLayout(this);
    QWidget *topPart = new QWidget(this);
    QHBoxLayout *topLayout = new QHBoxLayout(topPart);
    QLabel *titleLabel = new QLabel("Examination Schedule", this);
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
    examManager = new ExamManager();
    examManager->loadFromJson("../../data/exams.json");

    initializeDialog();
    initializeItem();
    
    connect(btnFooter->getBtn(), &QPushButton::clicked, this, &ExamPage::openFormDialog);
}

ExamPage::~ExamPage()
{
    delete formDialog;
    delete examManager;
}

void ExamPage::initializeItem()
{
    infoCardList->clearCards();   
    QList<Exam> list = examManager->getAll();
    for (const Exam& e : list) {
        infoCard = infoCardList->addCard(e.subject(), getRandomColorString());
        infoCard->addContentLine({{"../../assets/calendar.png", "Room: " + e.room()}});
        infoCard->addContentLine({{"../../assets/calendar.png", "Date: " + e.date()}});
        infoCard->addContentLine({{"../../assets/calendar.png", e.timeFrom() + " - " + e.timeTo()}});
    }
    bottomLayout->addWidget(infoCardList);
}

void ExamPage::initializeDialog()
{
    formDialog->setHeaderTitle("Add Exam: ");
    formDialog->addContentLine("Subject: ");
    formDialog->addContentLine("Room: ");
    formDialog->addContentLine("Date: ");
    formDialog->addContentLine("From Time: ");
    formDialog->addContentLine("To Time: ");
}

void ExamPage::openFormDialog()
{
    Exam newExam;
    if (formDialog->exec() == QDialog::Accepted)
    {
        QVector<QPair<QString, QString>> entries = formDialog->getLabelInputPairs();
        for (const auto &entry : entries)
        {
            if (entry.first == "Subject: ")
                newExam.setSubject(entry.second);
            else if (entry.first == "Room: ")
                newExam.setRoom(entry.second);
            else if (entry.first == "Date: ")
                newExam.setDate(entry.second);
            else if (entry.first == "From Time: ")
                newExam.setTimeFrom(entry.second);
            else if (entry.first == "To Time: ")
                newExam.setTimeTo(entry.second);
        }
        examManager->saveToJson("../../data/exams.json", newExam);
        examManager->loadFromJson("../../data/exams.json");
        initializeItem();
    }
}
