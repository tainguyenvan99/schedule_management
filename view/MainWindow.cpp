#include "MainWindow.h"
#include <QScrollArea>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(390, 800);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    header = new HeaderBar(390, 60);
    header->setHeaderTitle("Time Table");
    mainLayout->addWidget(header);

    // content
    stackedWidget = new QStackedWidget;
    timeTablePage = new TimeTablePage();
    examPage = new ExamPage();
    teacherPage = new TeacherPage();
    submissionPage = new SubmissionPage();

    stackedWidget->addWidget(timeTablePage);
    stackedWidget->addWidget(examPage);
    stackedWidget->addWidget(teacherPage);
    stackedWidget->addWidget(submissionPage);
    stackedWidget->setCurrentIndex(0);
    mainLayout->addWidget(stackedWidget);

    pageIndexMap["Time Table"] = 0;
    pageIndexMap["Exam"] = 1;
    pageIndexMap["Teachers"] = 2;
    pageIndexMap["Submissions"] = 3;

    // QScrollArea *scrollArea = new QScrollArea(this);
    // scrollArea->setWidgetResizable(true);
    // scrollArea->setWidget(this);
    // sidebar
    sidebar = new Sidebar(centralWidget);
    sidebar->setGeometry(-313, 0, 313, 800);
    sidebar->raise();

    connect(header->button(), &QPushButton::clicked, sidebar, &Sidebar::onBtnHeaderClick);
    connect(sidebar, &Sidebar::pageSelected, this, &MainWindow::handlePageSelected);
    connect(sidebar, &Sidebar::pageSelected, header, &HeaderBar::setHeaderTitle);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handlePageSelected(const QString &pageName)
{
    if (pageIndexMap.contains(pageName))
    {
        stackedWidget->setCurrentIndex(pageIndexMap.value(pageName));
    }
}
 