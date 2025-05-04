// TimeTableManager.h
#ifndef TIMETABLEMANAGER_H
#define TIMETABLEMANAGER_H

#include <QList>
#include "TimeTable.h"

class TimeTableManager {
public:
    void addTimeTable(const TimeTable& t);
    QList<TimeTable> getTimeTables() const;
    bool loadFromJson(const QString& filePath);
    QList<TimeTable> filterByDayOfWeek(const QString& dayOfWeek) const;
    bool saveToJson(const QString& filePath,  const TimeTable& timeTable) const;

private:
    QList<TimeTable> m_timeTables;
};

#endif // TIMETABLEMANAGER_H
