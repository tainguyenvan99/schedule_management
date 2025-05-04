#pragma once
#include <QString>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <functional>

template <typename T>
class JsonUtils {
protected:
    QList<T> dataList;

public:
    QList<T> getAll() const {
        return dataList;
    }

    void loadFromJson(const QString& filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QByteArray jsonData = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        file.close();

        dataList.clear();
        QJsonArray array = doc.array();
        for (const QJsonValue &val : array) {
            T obj;
            obj.fromJson(val.toObject());
            dataList.append(obj);
        }
    }

    void saveToJson(const QString& filePath, const T& newItem) {
        dataList.append(newItem);
        QJsonArray array;
        for (const T &item : dataList) {
            array.append(item.toJson());
        }

        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QJsonDocument doc(array);
        file.write(doc.toJson());
        file.close();
    }

    void remove(const T& item) {
        dataList.removeAll(item);
    }

    void clear() {
        dataList.clear();
    }
};
