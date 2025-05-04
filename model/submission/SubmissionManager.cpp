#include "SubmissionManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

void SubmissionManager::addSubmission(const Submission& s) {
    m_submissions.append(s);
}

QList<Submission> SubmissionManager::getSubmissions() const {
    return m_submissions;
}

bool SubmissionManager::loadFromJson(const QString& filePath) {
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
    m_submissions.clear();

    for (const QJsonValue& val : array) {
        QJsonObject obj = val.toObject();
        Submission s;
        s.setSubject(obj["subject"].toString());
        s.setDesc(obj["desc"].toString());
        s.setDeadline(obj["deadline"].toString());
        m_submissions.append(s);
    }

    return true;
}
