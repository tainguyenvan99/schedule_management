#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const QString& name, const QString& post,
                 const QString& phone, const QString& email)
    : m_name(name), m_post(post), m_phone(phone), m_email(email) {}

QString Teacher::name() const { return m_name; }
QString Teacher::post() const { return m_post; }
QString Teacher::phone() const { return m_phone; }
QString Teacher::email() const { return m_email; }

void Teacher::setName(const QString& name) { m_name = name; }
void Teacher::setPost(const QString& post) { m_post = post; }
void Teacher::setPhone(const QString& phone) { m_phone = phone; }
void Teacher::setEmail(const QString& email) { m_email = email; }

QJsonObject Teacher::toJson() const
{
    QJsonObject obj;
    obj["name"] = m_name;
    obj["post"] = m_post;
    obj["phone"] = m_phone;
    obj["email"] = m_email;
    return obj;
}

void Teacher::fromJson(const QJsonObject &obj)
{
    m_name = obj["name"].toString();
    m_post = obj["post"].toString();
    m_phone = obj["phone"].toString();  
    m_email = obj["email"].toString();
}
