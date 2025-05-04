#ifndef EXAMMANAGER_H
#define EXAMMANAGER_H

#include <QList>
#include "Exam.h"

class ExamManager {
public:
    void addExam(const Exam& e);
    QList<Exam> getExams() const;
    bool loadFromJson(const QString& filePath);

private:
    QList<Exam> m_exams;
};

#endif // EXAMMANAGER_H
