#include "TimeTable.h"

TimeTable::TimeTable() {}

TimeTable::TimeTable(const QString& subject, const QString& teacher, const QString& room,
                     const QString& timeFrom, const QString& timeTo,
                     const QString& dayOfWeek)
    : m_subject(subject), m_teacher(teacher), m_room(room),
      m_timeFrom(timeFrom), m_timeTo(timeTo), m_dayOfWeek(dayOfWeek) {}

QString TimeTable::subject() const { return m_subject; }
QString TimeTable::teacher() const { return m_teacher; }
QString TimeTable::room() const { return m_room; }
QString TimeTable::timeFrom() const { return m_timeFrom; }
QString TimeTable::timeTo() const { return m_timeTo; }
QString TimeTable::dayOfWeek() const { return m_dayOfWeek; }

void TimeTable::setSubject(const QString& subject) { m_subject = subject; }
void TimeTable::setTeacher(const QString& teacher) { m_teacher = teacher; }
void TimeTable::setRoom(const QString& room) { m_room = room; }
void TimeTable::setTimeFrom(const QString& timeFrom) { m_timeFrom = timeFrom; }
void TimeTable::setTimeTo(const QString& timeTo) { m_timeTo = timeTo; }
void TimeTable::setDayOfWeek(const QString& dayOfWeek) { m_dayOfWeek = dayOfWeek; }

QString TimeTable::toString() const {
    return QString("%1 | %2 | %3 | %4-%5 | %6")
        .arg(m_subject, m_teacher, m_room, m_timeFrom, m_timeTo, m_dayOfWeek);
}
