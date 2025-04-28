#include <FileTest.h>
#include <FileUtility.h>
#include <QDebug>
#include <QFileInfo>

FileTest::FileTest(const QString &path, QWidget *parent)
    : QWidget(parent), _path(path)
{
    setWindowTitle(tr("File test"));
    _ext = {"sldprt", "slddrw", "pdf"};
    _missingList.clear();

    _filePaths = FileUtility::ListFile(path, E_typelist::ABSOLUTPATH);
    if(addFileInGroup())
    {
        compareFiles();
        resultToPrint();
    }
}

QString FileTest::resultToPrint() const
{
    QString result = "-- VERIFICATION DU REPERTOIRE : " + _path + " --\n";

    result += "Liste des extensions testées : \n";
    for(const QString &i : std::as_const(_ext))
    {
        result += "." + i + "\n";
    }

    if(_missingList.isEmpty())
        result += "\n✅ Pas de fichiers manquants";
    else
    {
        result += "\n❌ Fichiers manquants :\n";
        for(const QString &nOK : std::as_const(_missingList))
        {
            result += nOK + "\n";
        }
    }
    return result;
}

bool FileTest::addFileInGroup()
{
    for(QString &fullPath : _filePaths)
    {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.completeBaseName();
        QString baseName = fileName.section("_", 0, 0);
        QString ext = fileInfo.suffix().toLower();

        if(ext == _ext.at(0) || ext == _ext.at(1) || ext == _ext.at(2))
        {
            _fileGroups[baseName].append(ext);
        }
    }
    if(_fileGroups.isEmpty())
        return false;
    else
        return true;
}

void FileTest::compareFiles()
{
    for(auto it = _fileGroups.begin(); it != _fileGroups.end(); it++)
    {
        const QString base = it.key();
        const QStringList &extensions = it.value();


        QStringList missingExtensions;

        for(const QString &e : std::as_const(_ext))
        {
            if(!extensions.contains(e))
                missingExtensions.append(e);
        }

        if (!missingExtensions.isEmpty())
        {
            for(const QString &ext : std::as_const(missingExtensions))
            {
                _missingList.append(base + "." + ext);
            }
        }
    }
}



