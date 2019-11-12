#ifndef READFILE_H
#define READFILE_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDir>
#include "structwords.h"

class ReadFile : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QString readfile READ readfile WRITE setreadfile NOTIFY readfileChanged)
    QString m_readfile;

public:

    ReadFile(QObject *parent = nullptr);
    QString readfile() const;
    Q_INVOKABLE QString openFile();
    Q_INVOKABLE void writeFile(QString engWord, QString rusWords);
    Q_INVOKABLE QStringList engWord(int nextWord);
    Q_INVOKABLE QString rusWord(int nextWord);

public slots:
    void setreadfile(QString readfile);
signals:
    void readfileChanged(QString readfile);
};

#endif // READFILE_H
