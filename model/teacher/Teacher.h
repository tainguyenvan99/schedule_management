#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QJsonObject>


class Teacher {
public:
    Teacher();
    Teacher(const QString& name, const QString& post,
            const QString& phone, const QString& email);

    QString name() const;
    QString post() const;
    QString phone() const;
    QString email() const;

    void setName(const QString& name);
    void setPost(const QString& post);
    void setPhone(const QString& phone);
    void setEmail(const QString& email);

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& obj);

private:
    QString m_name;
    QString m_post;
    QString m_phone;
    QString m_email;
};

#endif // TEACHER_H
