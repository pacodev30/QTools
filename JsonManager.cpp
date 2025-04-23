#include "JsonManager.h"


QJsonObject JsonManager::readJson(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Can't open the path : " << filePath;
        return {};
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    return doc.object();
}

bool JsonManager::writeJson(const QString &filePath, const QJsonObject &jsonObject)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << "Can't open the path : " << filePath;
        return false;
    }

    QJsonDocument jsonDoc(jsonObject);
    file.write(jsonDoc.toJson());
    file.close();
    return true;
}

bool JsonManager::addEntry(const QString &filePath, const QString &key, const QJsonValue &value)
{
    QJsonObject jsonObject = readJson(filePath);
    jsonObject.insert(key, value);
    return writeJson(filePath, jsonObject);
}
