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

QString ReadFile::readWords(int nextWord)
{
    StructWords entry;
    entry.readFile(nextWord);
}

void ReadFile::setreadfile(QString readfile)
{
    if (m_readfile == readfile)
        return;

    m_readfile = readfile;
    emit readfileChanged(m_readfile);
}
