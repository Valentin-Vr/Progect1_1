#include "structwords.h"
#include <vector>

static QString PATH = QDir::homePath() + "/Example/eng.txt";

StructWords::StructWords()
{
    QString engWord;
    QString rusWords;
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
        QStringList list1 = line.split('/');
        QDate date = QDate::fromString(list1[0], "ddMMyyyy");
        int dayDifference = date.daysTo(currentDate);
        engWord = list1[1];
        rusWords = list1[2];
        if (dayDifference == 1 || dayDifference == 3 || dayDifference == 7 || dayDifference == 14 || dayDifference == 30) {
            dictionary.push_back(list1);
        }
    }
    mFile.close();
}



void StructWords::writeToFile(QString engWord, QString rusWord)
{
    QDate currentDate(QDate::currentDate());
    QString currentDateStr = currentDate.toString("ddMMyyyy");
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::Append | QIODevice::Text);
    }
    QTextStream writeStream(&mFile);
    writeStream << currentDateStr << "/" << engWord << "/" << rusWord << "\n";
    mFile.close();
}

QString StructWords::readFile(int nextWord)
{
        qDebug() << dictionary[nextWord];
        QString eng;
        eng = dictionary[0].at(0);
        qDebug() << eng;
        return eng;
}
