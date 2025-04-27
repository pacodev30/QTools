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
     * @brief result
     * @return
     */
    QString result() const;

    /**
     * @brief toPrint
     * @return
     */
    void resultToPrint();

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
    QLabel *_resultLabel = nullptr;
    QString _path;
    QString _result;
    QString _ext1, _ext2, _ext3;
    QStringList _listOk;
    QStringList _listNok;
    QStringList _filePaths;
    QMap<QString,QStringList> _fileGroups;
};
