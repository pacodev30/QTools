#include <FileTest.h>
#include <FileUtility.h>
#include <QDebug>
#include <QFileInfo>

FileTest::FileTest(const QString &path, QWidget *parent)
    : QWidget(parent), _path(path)
{
    setWindowTitle(tr("File test"));
    _ext1 = "sldprt";
    _ext2 = "slddrw";
    _ext3 = "pdf";

    _filePaths = FileUtility::ListFile(path, E_typelist::ABSOLUTPATH);
    if(addFileInGroup())
    {
        compareFiles();
        resultToPrint();
    }
}

QString FileTest::result() const
{
    return _result;
}

void FileTest::resultToPrint()
{
    _result = "-- VERIFICATION DU REPERTOIRE : " + _path + " --\n";
    if(!_listOk.isEmpty())
    {
        _result += "\n- Fichiers ok :\n";

        for(const QString &ok : std::as_const(_listOk))
        {
            _result += ok + "\n";
        }
    }

    if(!_listNok.isEmpty())
    {
        _result += "\n- Fichiers Nok :\n";
        for(const QString &nOK : std::as_const(_listNok))
        {
            _result += nOK + "\n";
        }
    }
}

bool FileTest::addFileInGroup()
{
    for(QString &fullPath : _filePaths)
    {
        QFileInfo fileInfo(fullPath);
        QString fileName = fileInfo.completeBaseName();
        QString baseName = fileName.section("_", 0, 0);
        QString ext = fileInfo.suffix().toLower();

        if(ext == _ext1 || ext == _ext2 || ext == _ext3)
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

        if(extensions.contains(_ext1) && extensions.contains(_ext2) && extensions.contains(_ext3))
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



