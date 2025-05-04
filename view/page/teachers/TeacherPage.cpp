#include "TeacherPage.h"
#include "RandomColor.h"


TeacherPage::TeacherPage(QWidget *parent) : QWidget(parent)
{
    resize(390, 800);
    mainLayout = new QVBoxLayout(this);
    QWidget *topPart = new QWidget(this);
    topLayout = new QHBoxLayout(topPart);
    QLabel *titleLabel = new QLabel("Teacher's Details", this);
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
    teacherManager = new TeacherManager();
    teacherManager->loadFromJson("../../data/teachers.json");

    initializeDialog();
    initializeItem();
    
    connect(btnFooter->getBtn(), &QPushButton::clicked, this, &TeacherPage::openFormDialog);
}
TeacherPage::~TeacherPage()
{
    delete formDialog;
    delete teacherManager;
}
void TeacherPage::initializeItem()
{
    infoCardList->clearCards();   
    QList<Teacher> list = teacherManager->getAll();
    for (const Teacher& t : list) {
        infoCard = infoCardList->addCard(t.name(), getRandomColorString());
        infoCard->addContentLine({{"../../assets/calendar.png", t.post()}});
        infoCard->addContentLine({{"../../assets/calendar.png", t.phone()}});
        infoCard->addContentLine({{"../../assets/calendar.png", t.email()}});
    }
    bottomLayout->addWidget(infoCardList);
}

void TeacherPage::initializeDialog()
{
    formDialog->setHeaderTitle("Add Teacher: ");
    formDialog->addContentLine("Name: ");
    formDialog->addContentLine("Post: ");
    formDialog->addContentLine("Phone: ");
    formDialog->addContentLine("Email: ");
}

void TeacherPage::openFormDialog()
{
    Teacher newTimeTable;
    if (formDialog->exec() == QDialog::Accepted)
    {
        QVector<QPair<QString, QString>> entries = formDialog->getLabelInputPairs();
        for (const auto &entry : entries)
        {
            if (entry.first == "Name: ")
            {
                newTimeTable.setName(entry.second);
            }
            else if (entry.first == "Post: ")
            {
                newTimeTable.setPost(entry.second);
            }
            else if (entry.first == "Phone: ")
            {
                newTimeTable.setPhone(entry.second);
            }
            else if (entry.first == "Email: ")
            {
                newTimeTable.setEmail(entry.second);
            }
        }
        teacherManager->saveToJson("../../data/teachers.json", newTimeTable);
        teacherManager->loadFromJson("../../data/teachers.json");
        initializeItem();
    }
}
