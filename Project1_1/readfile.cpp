#include "readfile.h"
#include <QByteArray>
#include <QTextStream>

static QString PATH = QDir::homePath() + "/Example/eng.txt";

ReadFile::ReadFile(QObject *parent) : QObject(parent)
{
    //    qDebug() << PATH;
    //    QFile mFile(PATH);
    //    if(!mFile.exists()) {
    //        mFile.open(QIODevice::WriteOnly);
    //        qDebug() << "Файл создан";
    //    } else {
    //        qDebug() << "Файл существует";
    //    }
}

QString ReadFile::readfile() const
{
    return m_readfile;
}

QString ReadFile::openFile()
{
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::ReadOnly);
    }
    QByteArray data;
    data = mFile.readAll();
    //    qDebug() << QString(data);
    mFile.close();
    return QString(data);
}

void ReadFile::writeFile(QString engWord, QString rusWords)
{
    StructWords entry;
    entry.writeToFile(engWord, rusWords);
}

QStringList ReadFile::engWord(int nextWord)
{
    StructWords entry;
    return entry.engWord(nextWord);
}

QString ReadFile::rusWord(int nextWord)
{
    StructWords entry;
    return entry.rusWord(nextWord);
}

void ReadFile::setreadfile(QString readfile)
{
    if (m_readfile == readfile)
        return;

    m_readfile = readfile;
    emit readfileChanged(m_readfile);
}
