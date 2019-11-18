#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDir>
#include "data.h"
#include <QByteArray>
#include <QTextStream>
#include <QStandardPaths>

class Dictionary : public QObject
{

    Q_OBJECT

    QList<Data> dictionary;

    int m_lineCount;

public:

    Dictionary(QObject *parent = nullptr);

    Q_INVOKABLE QString openFile();
    Q_INVOKABLE void writeToFile(QString engWord, QString rusWord);
    Q_INVOKABLE QString engWord(int nextWord);
    Q_INVOKABLE QString rusWord(int nextWord);

    Q_PROPERTY(int lineCount READ lineCount WRITE setLineCount NOTIFY lineCountChanged)
    int lineCount() const;

private:
    void randomShuffle();
    void wordCheck(QString engWord, QString rusWord);

public slots:
    void setLineCount(int lineCount);
signals:
    void lineCountChanged(int lineCount);
};

#endif
