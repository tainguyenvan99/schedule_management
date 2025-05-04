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

QJsonObject TimeTable::toJson() const
{
  QJsonObject obj;
  obj["subject"] = m_subject;
  obj["teacher"] = m_teacher;
  obj["room"] = m_room;
  obj["dayOfWeek"] = m_dayOfWeek;
  obj["timeFrom"] = m_timeFrom;
  obj["timeTo"] = m_timeTo;
  return obj;
}

void TimeTable::fromJson(const QJsonObject &obj)
{
  m_subject = obj["subject"].toString();
  m_teacher = obj["teacher"].toString();
  m_room = obj["room"].toString();
  m_dayOfWeek = obj["dayOfWeek"].toString();
  m_timeFrom = obj["timeFrom"].toString();
  m_timeTo = obj["timeTo"].toString();
}
