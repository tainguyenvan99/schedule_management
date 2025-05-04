#include "TeacherManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

void TeacherManager::addTeacher(const Teacher& t) {
    m_teachers.append(t);
}

QList<Teacher> TeacherManager::getTeachers() const {
    return m_teachers;
}

bool TeacherManager::loadFromJson(const QString& filePath) {
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
    m_teachers.clear();

    for (const QJsonValue& val : array) {
        QJsonObject obj = val.toObject();
        Teacher t;
        t.setName(obj["name"].toString());
        t.setPost(obj["post"].toString());
        t.setPhone(obj["phone"].toString());
        t.setEmail(obj["email"].toString());
        m_teachers.append(t);
    }

    return true;
}
