#ifndef TEACHERMANAGER_H
#define TEACHERMANAGER_H

#include <QList>
#include "Teacher.h"

class TeacherManager {
public:
    void addTeacher(const Teacher& t);
    QList<Teacher> getTeachers() const;
    bool loadFromJson(const QString& filePath);

private:
    QList<Teacher> m_teachers;
};

#endif // TEACHERMANAGER_H
