#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QFileInfo>

class FileSystem
{
public:
    FileSystem();
    ~FileSystem();

    QList<QString> getFileList(const QString &path);
    QString getFilePath();
    bool openFile(const QString &path);
    int Write(const QString &data);
    void Read(QString &buf,int len);
    void ReadAll(QString &buf);
    bool IsOpen();
    void Close();

private:
    QString m_path;
    QList<QString> m_list;
    QFile m_file;
};

#endif // FILESYSTEM_H
