// TimeTableManager.cpp
#include "TimeTableManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

QList<TimeTable> TimeTableManager::filterByDayOfWeek(const QString& dayOfWeek) const {
    QList<TimeTable> filtered;
    for (const TimeTable& t : getAll()) {
        if (t.dayOfWeek() == dayOfWeek) {
            filtered.append(t);
        }
    }
    return filtered;
}
