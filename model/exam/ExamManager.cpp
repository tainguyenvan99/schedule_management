#include "ExamManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

void ExamManager::addExam(const Exam& e) {
    m_exams.append(e);
}

QList<Exam> ExamManager::getExams() const {
    return m_exams;
}

bool ExamManager::loadFromJson(const QString& filePath) {
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
    m_exams.clear();

    for (const QJsonValue& val : array) {
        QJsonObject obj = val.toObject();
        Exam e;
        e.setSubject(obj["subject"].toString());
        e.setRoom(obj["room"].toString());
        e.setDate(obj["date"].toString());
        e.setTimeFrom(obj["timeFrom"].toString());
        e.setTimeTo(obj["timeTo"].toString());
        m_exams.append(e);
    }

    return true;
}
