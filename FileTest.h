#pragma once
#include <FileUtility.h>
#include <QMap>
#include <QVector>

class FileTest
{
public:
    FileTest(const QString &path);

    /**
     * @brief addFileInGroup
     */
    void addFileInGroup();

    /**
     * @brief compareFiles
     */
    void compareFiles();

    /**
     * @brief listOk
     * @return
     */
    bool writeData(const QString &dataPath);

private:
    QString _path;
    QStringList _listOk;
    QStringList _listNok;
    QStringList _filePaths;
    QMap<QString,QStringList> _fileGroups;
};
