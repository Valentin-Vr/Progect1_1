#ifndef STRUCTWORDS_H
#define STRUCTWORDS_H

#include <QObject>
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <iostream>
#include <vector>

struct StructWords
{
    StructWords();
    void writeToFile(QString engWord, QString rusWord);
    QString readFile(int nextWord);

private:

    QVector<QStringList> dictionary;
};

#endif // STRUCTWORDS_H
