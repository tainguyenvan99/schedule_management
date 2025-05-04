#include "TimeTablePage.h"
#include <QListWidgetItem>
#include <QPushButton>
#include <QScrollArea>

TimeTablePage::TimeTablePage(QWidget *parent)
    : QWidget(parent)
{
    resize(390, 800);
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    QWidget *topPart = new QWidget();
    topLayout = new QHBoxLayout(topPart);

    QWidget *bottomPart = new QWidget();
    bottomLayout = new QVBoxLayout(bottomPart);

    // day of week buttons
    QStringList days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (const QString &day : days)
    {
        btnDay = new ButtonAction();
        btnDay->setStyleSheet(R"(
                background-color: #FE9900;
                padding: 10px;
                border-radius: 5px;
                font-weight: bold;
        )");
        btnDay->setBtnName(day);
        connect(btnDay, &ButtonAction::btnClicked, this, &TimeTablePage::initializeItem);
        topLayout->addWidget(btnDay);
    }
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(topPart);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedHeight(85);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setFrameShape(QFrame::NoFrame);
    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(bottomPart);

    infoCardList = new InfoCardList(this);
    btnFooter = new ButtonAction(this);
    btnFooter->setIcon("../../assets/add.png", 65);
    btnFooter->setFixedSize(65, 65);
    btnFooter->move(this->width() - btnFooter->width() - 20, this->height() - btnFooter->height() - 110);

    // Initialize the time table manager and load data from JSON
    timeTableManager = new TimeTableManager();
    timeTableManager->loadFromJson("../../data/time_table.json");
    initializeItem("Monday");

    // Initialize the form dialog
    formDialog = new FormDialog();
    initializeDialog();
    connect(btnFooter->getBtn(), &QPushButton::clicked, this, &TimeTablePage::openFormDialog);
    // connect(formDialog, &FormDialog::formSubmitted, this, &TimeTablePage::loadDataWhenFormAccepted);
}
TimeTablePage::~TimeTablePage()
{
    delete formDialog;
    delete timeTableManager;
}
void TimeTablePage::initializeItem(const QString &dayOfWeek)
{
    infoCardList->clearCards();   
    QList<TimeTable> list = timeTableManager->filterByDayOfWeek(dayOfWeek);
    for (const TimeTable& t : list) {
        infoCard = infoCardList->addCard(t.subject(), "#3E61DE7D");
        infoCard->addContentLine({{"../../assets/calendar.png", t.teacher()}});
        infoCard->addContentLine({{"../../assets/calendar.png", t.room()}, {"../../assets/calendar.png", t.timeFrom() + " - " + t.timeTo()}});
    }
    bottomLayout->addWidget(infoCardList);
}
void TimeTablePage::initializeDialog()
{
    formDialog->setHeaderTitle("Add Subject: ");
    formDialog->addContentLine("Subject: ");
    formDialog->addContentLine("Teacher: ");
    formDialog->addContentLine("Room: ");
    formDialog->addContentLine("From Time: ");
    formDialog->addContentLine("To Time: ");
    formDialog->addContentLine("Day of Week: ");
}
void TimeTablePage::openFormDialog()
{
    TimeTable newTimeTable;
    if (formDialog->exec() == QDialog::Accepted)
    {
        QVector<QPair<QString, QString>> entries = formDialog->getLabelInputPairs();
        for (const auto &entry : entries)
        {
            if (entry.first == "Subject: ")
            {
                newTimeTable.setSubject(entry.second);
            }
            else if (entry.first == "Teacher: ")
            {
                newTimeTable.setTeacher(entry.second);
            }
            else if (entry.first == "Room: ")
            {
                newTimeTable.setRoom(entry.second);
            }
            else if (entry.first == "From Time: ")
            {
                newTimeTable.setTimeFrom(entry.second);
            }
            else if (entry.first == "To Time: ")
            {
                newTimeTable.setTimeTo(entry.second);
            }
            else if (entry.first == "Day of Week: ")
            {
                newTimeTable.setDayOfWeek(entry.second);
            }
        }
        timeTableManager->saveToJson("../../data/time_table.json", newTimeTable);
        timeTableManager->loadFromJson("../../data/time_table.json");
        initializeItem(newTimeTable.dayOfWeek());
    }
}

// void TimeTablePage::loadDataWhenFormAccepted(const QVector<QPair<QString, QString>> &entries)
// {
    // TimeTable newTimeTable;
    // if (formDialog->exec() == QDialog::Accepted)
    // {
    //     QVector<QPair<QString, QString>> entries = formDialog->getLabelInputPairs();
    //     for (const auto &entry : entries)
    //     {
    //         if (entry.first == "Subject: ")
    //         {
    //             newTimeTable.setSubject(entry.second);
    //         }
    //         else if (entry.first == "Teacher: ")
    //         {
    //             newTimeTable.setTeacher(entry.second);
    //         }
    //         else if (entry.first == "Room: ")
    //         {
    //             newTimeTable.setRoom(entry.second);
    //         }
    //         else if (entry.first == "From Time: ")
    //         {
    //             newTimeTable.setTimeFrom(entry.second);
    //         }
    //         else if (entry.first == "To Time: ")
    //         {
    //             newTimeTable.setTimeTo(entry.second);
    //         }
    //         else if (entry.first == "Day of Week: ")
    //         {
    //             newTimeTable.setDayOfWeek(entry.second);
    //         }
    //     }
    //     timeTableManager->saveToJson("../../data/time_table.json", newTimeTable);
    //     timeTableManager->loadFromJson("../../data/time_table.json");
    //     initializeItem(newTimeTable.dayOfWeek());
// }
