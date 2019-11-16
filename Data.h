#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDate>
#include <QDebug>

struct Data
{
    Data(QString currentEngWord, QString currentRusWords, QDate realDate, int valueForRepetition);
    QString engWord;
    QString rusWords;
    QDate date;
    int repetitionValue;

private:


};

#endif
