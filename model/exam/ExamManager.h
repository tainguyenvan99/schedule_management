#ifndef EXAMMANAGER_H
#define EXAMMANAGER_H

#include <QList>
#include "Exam.h"
#include "JsonUtils.h"

class ExamManager : public JsonUtils<Exam>
{
public:
    ExamManager() = default;
    ~ExamManager() = default;
};

#endif // EXAMMANAGER_H
