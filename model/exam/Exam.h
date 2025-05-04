#ifndef EXAM_H
#define EXAM_H

#include <QString>
#include <QString>

class Exam {
public:
    Exam();
    Exam(const QString& subject, const QString& room, const QString& date,
         const QString& timeFrom, const QString& timeTo);

    QString subject() const;
    QString room() const;
    QString date() const;
    QString timeFrom() const;
    QString timeTo() const;

    void setSubject(const QString& subject);
    void setRoom(const QString& room);
    void setDate(const QString& date);
    void setTimeFrom(const QString& timeFrom);
    void setTimeTo(const QString& timeTo);


private:
    QString m_subject;
    QString m_room;
    QString m_date;
    QString m_timeFrom;
    QString m_timeTo;
};

#endif // EXAM_H
