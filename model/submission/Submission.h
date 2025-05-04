#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <QString>
#include <QJsonObject>

class Submission {
public:
    Submission();
    Submission(const QString& subject, const QString& desc, const QString& deadline);

    QString subject() const;
    QString desc() const;
    QString deadline() const;

    void setSubject(const QString& subject);
    void setDesc(const QString& desc);
    void setDeadline(const QString& deadline);

    QJsonObject toJson() const;
    void fromJson(const QJsonObject &obj);

private:
    QString m_subject;
    QString m_desc;
    QString m_deadline;
};

#endif // SUBMISSION_H
