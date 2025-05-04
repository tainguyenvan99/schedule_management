// TimeTableManager.cpp
#include "TimeTableManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

void TimeTableManager::addTimeTable(const TimeTable& t) {
    m_timeTables.append(t);
}

QList<TimeTable> TimeTableManager::getTimeTables() const {
    return m_timeTables;
}

bool TimeTableManager::loadFromJson(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file:" << filePath;
        return false;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning() << "Invalid JSON format";
        return false;
    }

    QJsonArray array = doc.array();
    m_timeTables.clear();

    for (const QJsonValue& val : array) {
        if (!val.isObject()) continue;
        QJsonObject obj = val.toObject();

        TimeTable t;
        t.setSubject(obj["subject"].toString());
        t.setTeacher(obj["teacher"].toString());
        t.setRoom(obj["room"].toString());
        t.setTimeFrom(obj["timeFrom"].toString());
        t.setTimeTo(obj["timeTo"].toString());
        t.setDayOfWeek(obj["dayOfWeek"].toString());

        m_timeTables.append(t);
    }

    return true;
}

QList<TimeTable> TimeTableManager::filterByDayOfWeek(const QString& dayOfWeek) const {
    QList<TimeTable> filtered;
    for (const TimeTable& t : m_timeTables) {
        if (t.dayOfWeek().compare(dayOfWeek, Qt::CaseInsensitive) == 0) {
            filtered.append(t);
        }
    }
    return filtered;
}

bool TimeTableManager::saveToJson(const QString& filePath, const TimeTable& timeTable) const {
    QJsonArray array;

    QFile file(filePath);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isArray())
            array = doc.array();
        file.close();
    }

    QJsonObject obj;
    obj["subject"] = timeTable.subject();
    obj["teacher"] = timeTable.teacher();
    obj["room"] = timeTable.room();
    obj["timeFrom"] = timeTable.timeFrom();
    obj["timeTo"] = timeTable.timeTo();
    obj["dayOfWeek"] = timeTable.dayOfWeek();
    array.append(obj);

    QJsonDocument newDoc(array);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Cannot open file for writing:" << filePath;
        return false;
    }

    file.write(newDoc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

