#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedWidget>
#include "../view/component/header_bar/HeaderBar.h"
#include "../view/component/button_action/ButtonAction.h"
#include "../view/component/side_bar_menu/SideBar.h"

#include "./page/exams/ExamPage.h"
#include "./page/submissions/SubmissionPage.h"
#include "./page/teachers/TeacherPage.h"
#include "./page/time_table/TimeTablePage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handlePageSelected(const QString &pageName);

private:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QVBoxLayout *mainLayout;
    HeaderBar *header;
    Sidebar *sidebar;
    TimeTablePage *timeTablePage;
    ExamPage *examPage;
    SubmissionPage *submissionPage;
    TeacherPage *teacherPage;
    QMap<QString, int> pageIndexMap;
};

#endif // MAINWINDOW_H
 