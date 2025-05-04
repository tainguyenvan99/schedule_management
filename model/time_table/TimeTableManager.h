// TimeTableManager.h
#ifndef TIMETABLEMANAGER_H
#define TIMETABLEMANAGER_H

#include <QList>
#include "TimeTable.h"
#include "JsonUtils.h"

class TimeTableManager : public JsonUtils<TimeTable> {
public:
    TimeTableManager() = default;
    ~TimeTableManager() = default;
public:
    QList<TimeTable> filterByDayOfWeek(const QString& dayOfWeek) const;
};

#endif // TIMETABLEMANAGER_H
