#include "structwords.h"
#include <vector>

static QString PATH = ":/dictionary.txt";

StructWords::StructWords()
{
    QString engWord;
    QString rusWords;
    int repetitionValue;
    QDate currentDate(QDate::currentDate());
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    QTextStream in(&mFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        for (int i = 0; i < line.length();i++) {
        }
        QStringList valueString = line.split('/');
        QDate date = QDate::fromString(valueString[0], "ddMMyyyy");
        int dayDifference = date.daysTo(currentDate);
        repetitionValue = valueString[1].toInt();
        engWord = valueString[2];
        rusWords = valueString[3];
        if (repetitionValue == 1 || dayDifference == 1 || dayDifference == 3 || dayDifference == 7 || dayDifference == 14 || dayDifference == 30) {
            dictionary.push_back(valueString);
        }
    }
    mFile.close();
}



void StructWords::writeToFile(QString engWord, QString rusWord)
{
    QDate currentDate(QDate::currentDate());
    QString currentDateStr = currentDate.toString("ddMMyyyy");
    int repetitionValue = 0;
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::Append | QIODevice::Text);
    }
    QTextStream writeStream(&mFile);
    writeStream << currentDateStr << "/" << repetitionValue << "/" << engWord << "/" << rusWord << "\n";
    mFile.close();
}

QString StructWords::engWord(int nextWord)
{
    qDebug() << "length =" << dictionary.length();
    qDebug() << "nextWord =" << nextWord;
    if(nextWord >= dictionary.length()) {
        nextWord = 0;
        qDebug() << "nextWordNew =" << nextWord;
    }
    return dictionary[nextWord].at(2);
}

QString StructWords::rusWord(int nextWord)
{
    if(nextWord >= dictionary.length()) {
        nextWord = 0;
        qDebug() << "nextWordNew =" << nextWord;
    }
    return dictionary[nextWord].at(3);
}
