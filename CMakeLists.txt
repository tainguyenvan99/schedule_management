cmake_minimum_required(VERSION 3.16)

project(schedule_management VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        ./view/MainWindow.cpp
        ./view/MainWindow.h
        # component view
        ./view/component/header_bar/HeaderBar.h
        ./view/component/header_bar/HeaderBar.cpp
        ./view/component/side_bar_menu/SideBar.h
        ./view/component/side_bar_menu/SideBar.cpp
        ./view/component/icon_label/IconLabel.h
        ./view/component/icon_label/IconLabel.cpp
        ./view/component/info_card/InfoCard.h
        ./view/component/info_card/InfoCard.cpp
        ./view/component/info_card/InfoCardList.h
        ./view/component/info_card/InfoCardList.cpp
        ./view/component/button_action/ButtonAction.h
        ./view/component/button_action/ButtonAction.cpp
        ./view/component/form_dialog/FormDialog.h
        ./view/component/form_dialog/FormDialog.cpp


        # page view
        ./view/page/time_table/TimeTablePage.h
        ./view/page/time_table/TimeTablePage.cpp
        ./view/page/exams/ExamPage.h
        ./view/page/exams/ExamPage.cpp
        ./view/page/submissions/SubmissionPage.h
        ./view/page/submissions/SubmissionPage.cpp
        ./view/page/teachers/TeacherPage.h
        ./view/page/teachers/TeacherPage.cpp

        # model
        ./model/exam/Exam.h
        ./model/exam/Exam.cpp
        ./model/exam/ExamManager.h
        ./model/exam/ExamManager.cpp
        ./model/time_table/TimeTable.h
        ./model/time_table/TimeTable.cpp
        ./model/time_table/TimeTableManager.h
        ./model/time_table/TimeTableManager.cpp
        ./model/submission/Submission.h
        ./model/submission/Submission.cpp
        ./model/submission/SubmissionManager.h
        ./model/submission/SubmissionManager.cpp
        ./model/teacher/Teacher.h
        ./model/teacher/Teacher.cpp
        ./model/teacher/TeacherManager.h
        ./model/teacher/TeacherManager.cpp

        # image
        ./assets/agenda.png
        ./assets/calendar.png
        ./assets/graduate.png
        ./assets/people.png
        ./assets/add.png

        # data
        ./data/exams.json
        ./data/submissions.json
        ./data/teachers.json
        ./data/time_table.json

        # common
        ./common/JsonUtils.h
        ./common/RandomColor.h
        ./common/RandomColor.cpp
)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}/model/exam
    ${CMAKE_CURRENT_SOURCE_DIR}/model/submission
    ${CMAKE_CURRENT_SOURCE_DIR}/model/teacher
    ${CMAKE_CURRENT_SOURCE_DIR}/model/time_table
    ${CMAKE_CURRENT_SOURCE_DIR}/view
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/header_bar
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/side_bar_menu
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/icon_label
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/info_card
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/button_action
    ${CMAKE_CURRENT_SOURCE_DIR}/view/component/form_dialog
    ${CMAKE_CURRENT_SOURCE_DIR}/view/page
    ${CMAKE_CURRENT_SOURCE_DIR}/view/page/time_table
    ${CMAKE_CURRENT_SOURCE_DIR}/view/page/exams
    ${CMAKE_CURRENT_SOURCE_DIR}/view/page/submissions
    ${CMAKE_CURRENT_SOURCE_DIR}/view/page/teachers
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    )


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(schedule_management
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET schedule_management APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(schedule_management SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(schedule_management
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(schedule_management PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.schedule_management)
endif()
set_target_properties(schedule_management PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS schedule_management
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(schedule_management)
endif()
