#include <FileTest.h>
#include <FileUtility.h>
#include <QDebug>
#include <QFileInfo>

FileTest::FileTest(const QString &path)
    :_path(path)
{
    _filePaths = FileUtility::ListFile(path, E_typelist::ABSOLUTPATH);
    addFileInGroup();
    compareFiles();
}

void FileTest::addFileInGroup()
{
    for(QString &fullPath : _filePaths)
    {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.completeBaseName();
        QString baseName = fileName.section("_", 0, 0);
        QString ext = fileInfo.suffix().toLower();

        if(ext == "txt" || ext == "xls" || ext == "pdf")
        {
            _fileGroups[baseName].append(ext);
        }
    }
}

void FileTest::compareFiles()
{
    for(auto it = _fileGroups.begin(); it != _fileGroups.end(); it++)
    {
        const QString base = it.key();
        const QStringList &extensions = it.value();

        if(extensions.contains("txt") && extensions.contains("xls") && extensions.contains("pdf"))
        {
            _listOk.append(base);
        } else
        {
            for(const QString &item : extensions)
            {
                _listNok.append(base + "." + item);
            }
            _listNok.append("---");
        }
    }
}

bool FileTest::writeData(const QString &dataPath)
{
    QString data;
    data += "Fichiers ok :\n";

    for(const QString &ok : std::as_const(_listOk))
    {
        data += ok + "\n";
    }

    data += "\nFichiers Nok :\n";
    for(const QString &nOK : std::as_const(_listNok))
    {
        data += nOK + "\n";
    }

    return FileUtility::writeFile(dataPath, data);
}

