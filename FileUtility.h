#pragma once
#include <QString>
#include <QStringList>

enum E_typelist
{
    ABSOLUTPATH,
    FILENAME,
    BASENAME,
    EXTENSION
};

class FileUtility
{
public:

    /**
     * @brief readFile
     * @param filePath
     * @return
     */
    static QStringList readFile(const QString &filePath);

    /**
     * @brief writeFile
     * @param filePath
     * @param content
     * @return
     */
    static bool writeFile(const QString& filePath, const QString &content);

    /**
     * @brief ListFile
     * @param folderPath
     * @return
     */
    static QStringList ListFile(const QString &dirPath, E_typelist typeList);

};
