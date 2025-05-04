#include "Exam.h"

Exam::Exam() {}

Exam::Exam(const QString& subject, const QString& room, const QString& date,
           const QString& timeFrom, const QString& timeTo)
    : m_subject(subject), m_room(room), m_date(date),
      m_timeFrom(timeFrom), m_timeTo(timeTo) {}

QString Exam::subject() const { return m_subject; }
QString Exam::room() const { return m_room; }
QString Exam::date() const { return m_date; }
QString Exam::timeFrom() const { return m_timeFrom; }
QString Exam::timeTo() const { return m_timeTo; }

void Exam::setSubject(const QString& subject) { m_subject = subject; }
void Exam::setRoom(const QString& room) { m_room = room; }
void Exam::setDate(const QString& date) { m_date = date; }
void Exam::setTimeFrom(const QString& timeFrom) { m_timeFrom = timeFrom; }
void Exam::setTimeTo(const QString& timeTo) { m_timeTo = timeTo; }

QJsonObject Exam::toJson() const
{
    QJsonObject obj;
    obj["subject"] = m_subject;
    obj["room"] = m_room;
    obj["date"] = m_date;
    obj["timeFrom"] = m_timeFrom;
    obj["timeTo"] = m_timeTo;
    return obj;
}

void Exam::fromJson(const QJsonObject &obj)
{
    m_subject = obj["subject"].toString();
    m_room = obj["room"].toString();
    m_date = obj["date"].toString();
    m_timeFrom = obj["timeFrom"].toString();
    m_timeTo = obj["timeTo"].toString();
}