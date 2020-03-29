#include "imusicplayer.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMusicPlayer w;
    //w.setStyleSheet("background-color:gray");
    w.show();

    return a.exec();
}
