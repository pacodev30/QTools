#pragma once
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>

class JsonManager
{
public:
    /**
     * @brief readJson
     * @param filepath
     * @return
     */
    static QJsonObject readJson(const QString &filepath);

    /**
     * @brief writeJson
     * @param filePath
     * @param jsonObject
     * @return
     */
    static bool writeJson(const QString &filePath, const QJsonObject &jsonObject);

    /**
     * @brief addEntry
     * @param filePath
     * @param key
     * @param value
     * @return
     */
    static bool addEntry(const QString &filePath, const QString &key, const QJsonValue &value);
};
