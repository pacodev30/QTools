#pragma once
#include <QWidget>
#include <FileUtility.h>
#include <QMap>
#include <QVector>
#include <QVBoxLayout>
#include <QLabel>

class FileTest : public QWidget
{
public:
    FileTest(const QString &path, QWidget *parent);

    /**
     * @brief toPrint
     * @return
     */
    QString resultToPrint() const;

private:
    /**
     * @brief addFileInGroup
     */
    bool addFileInGroup();

    /**
     * @brief compareFiles
     */
    void compareFiles();

    QVBoxLayout *_vBox = nullptr;
    QLabel      *_resultLabel = nullptr;
    QStringList _filePaths;
    QStringList _ext;
    QStringList _missingList;
    QString     _path;
    QString     _result;
    QMap<QString,QStringList> _fileGroups;
};
