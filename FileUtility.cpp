#include "FileUtility.h"
#include <QDir>
#include <QTextStream>

QStringList FileUtility::readFile(const QString &filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Can't open file : " << filePath;
        return {};
    }

    QTextStream in(&file);
    QStringList list;
    while(!in.atEnd())
    {
        list.append(in.readLine());
    }
    return list;
}

bool FileUtility::writeFile(const QString &filePath, const QString &content)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << "Can't open file : " << filePath;
        return false;
    }
    QTextStream out(&file);
    out << content;
    return true;
}

QStringList FileUtility::ListFile(const QString &dirPath, E_typelist typeList)
{
    QDir dir(dirPath);
    QStringList files;
    if(dir.exists())
    {
        QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

        for(const QFileInfo& infoList : std::as_const(fileList))
        {
            switch (typeList)
            {
            case E_typelist::ABSOLUTPATH :
                files.append(infoList.absoluteFilePath());
                break;
            case E_typelist::FILENAME :
                files.append(infoList.fileName());
                break;
            case E_typelist::BASENAME :
                files.append(infoList.completeBaseName());
                break;
            case E_typelist::EXTENSION :
                files.append(infoList.suffix().toLower());
                break;
            }
        }
    }
    return files;
}

