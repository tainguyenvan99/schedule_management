#ifndef TEACHERMANAGER_H
#define TEACHERMANAGER_H

#include <QList>
#include "Teacher.h"
#include "JsonUtils.h"


class TeacherManager : public JsonUtils<Teacher> {
public:
    TeacherManager() = default;
    ~TeacherManager() = default;
};

#endif // TEACHERMANAGER_H
