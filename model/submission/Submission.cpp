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


