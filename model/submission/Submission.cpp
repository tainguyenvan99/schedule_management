#include "Submission.h"

Submission::Submission() {}

Submission::Submission(const QString& subject, const QString& desc, const QString& deadline)
    : m_subject(subject), m_desc(desc), m_deadline(deadline) {}

QString Submission::subject() const { return m_subject; }
QString Submission::desc() const { return m_desc; }
QString Submission::deadline() const { return m_deadline; }

void Submission::setSubject(const QString& subject) { m_subject = subject; }
void Submission::setDesc(const QString& desc) { m_desc = desc; }
void Submission::setDeadline(const QString& deadline) { m_deadline = deadline; }

QJsonObject Submission::toJson() const
{
    QJsonObject obj;
    obj["subject"] = m_subject;
    obj["desc"] = m_desc;
    obj["deadline"] = m_deadline;
    return obj;
}

void Submission::fromJson(const QJsonObject &obj)
{
    m_subject = obj["subject"].toString();
    m_desc = obj["desc"].toString();
    m_deadline = obj["deadline"].toString();
}
