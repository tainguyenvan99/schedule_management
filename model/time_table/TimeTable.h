#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QString>

class TimeTable {
public:
    TimeTable();
    TimeTable(const QString& subject, const QString& teacher, const QString& room,
              const QString& timeFrom, const QString& timeTo,
              const QString& dayOfWeek);

    QString subject() const;
    QString teacher() const;
    QString room() const;
    QString timeFrom() const;
    QString timeTo() const;
    QString dayOfWeek() const;

    void setSubject(const QString& subject);
    void setTeacher(const QString& teacher);
    void setRoom(const QString& room);
    void setTimeFrom(const QString& timeFrom);
    void setTimeTo(const QString& timeTo);
    void setDayOfWeek(const QString& dayOfWeek);

    QString toString() const;

private:
    QString m_subject;
    QString m_teacher;
    QString m_room;
    QString m_timeFrom;
    QString m_timeTo;
    QString m_dayOfWeek;
};

#endif // TIMETABLE_H
