#include "filesystem.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>

FileSystem::FileSystem()
{
    m_path = "";
}

FileSystem::~FileSystem()
{
    Close();
}

QString FileSystem::getFilePath()
{
    return m_path;
}

int FileSystem::Write(const QString &data)
{
    int wret=-1;
    if(IsOpen())
        wret=m_file.write(data.toStdString().c_str());

    return wret;
}

void FileSystem::Read(QString &buf,int len)
{
    if(buf==NULL)
        return;
    if(IsOpen())
        buf=m_file.read(len);
}

void FileSystem::ReadAll(QString &buf)
{
    buf=QString(m_file.readAll());
}

bool FileSystem::IsOpen()
{
    return m_file.isOpen();
}

void FileSystem::Close()
{
    if(m_file.isOpen())
        m_file.close();
}

QList<QString> FileSystem::getFileList(const QString &path)
{
    m_path = path;
    QDir dir(path);
    QStringList filter;
    QList<QFileInfo> fileInfo(QList<QFileInfo>(dir.entryInfoList(filter)));

    qDebug()<<fileInfo.count();
    for(int i=0;i<fileInfo.count();i++)
    {
        if(fileInfo.at(i).fileName()=="."||
                fileInfo.at(i).fileName()=="..")
        {
            continue;
        }
        qDebug()<<fileInfo.at(i).fileName();
        m_list.push_back(fileInfo.at(i).fileName());
    }

    return m_list;
}

bool FileSystem::openFile(const QString &path)
{
    m_file.setFileName(path);
    if(!m_file.open(QIODevice::ReadWrite)){
        return false;
    }
    return true;
}


