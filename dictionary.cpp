#include "dictionary.h"

static QString PATH = "C:/Users/User/Documents/Project1_1/dictionary.txt";

Dictionary::Dictionary(QObject *parent) : QObject(parent)
{
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
        QStringList valueString = line.split('/');
        QDate date = QDate::fromString(valueString[0], "ddMMyyyy");
        int dayDifference = date.daysTo(currentDate);
        int repetitionValue = valueString[1].toInt();
        if (repetitionValue == 1 ||
                dayDifference == 0 ||
                dayDifference == 1 ||
                dayDifference == 3 ||
                dayDifference == 7 ||
                dayDifference == 14 ||
                dayDifference == 30) {
            Data addToDictionary(valueString[2], valueString[3], QDate::fromString(valueString[0], "ddMMyyyy"), valueString[1].toInt());
            dictionary.push_back(addToDictionary);
        }
        //                Data addToDictionary(valueString[2], valueString[3], QDate::fromString(valueString[0], "ddMMyyyy"), valueString[1].toInt());
        //                dictionary.push_back(addToDictionary);
    }
    qDebug() << "Количество слов =" << dictionary.size();
    //    for (int i = 0; i < dictionary.size(); i++) {
    //        qDebug() << dictionary[i].engWord <<  dictionary[i].rusWords << dictionary[i].date << dictionary[i].repetitionValue;
    //    }

    mFile.close();
}

void Dictionary::writeToFile(QString engWord, QString rusWord)
{
    QDate currentDate(QDate::currentDate());
    int repetitionValue = 0;
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::Append | QIODevice::Text);
        qDebug() << "Файл открыт";
        QTextStream writeStream(&mFile);
        writeStream << currentDate.toString("ddMMyyyy") << "/" << repetitionValue << "/" << engWord << "/" << rusWord << "/" << "\n";
        mFile.close();
    }
    Data newData(engWord, rusWord, currentDate, repetitionValue);
    dictionary.push_back(newData);
//    qDebug() << "Количество слов =" << dictionary.size();
}

QString Dictionary::openFile()
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

QString Dictionary::engWord(int nextWord)
{
//    qDebug() << "size =" << dictionary.size() << "nextWord =" << nextWord;
    if (nextWord > dictionary.size() - 1) {
        nextWord = 0;
        randomShuffle();
    }
    setLineCount(nextWord);
    return dictionary[nextWord].engWord;
}

QString Dictionary::rusWord(int nextWord)
{
    return dictionary[nextWord].rusWords;
}


int Dictionary::lineCount() const
{
    return m_lineCount;
}

void Dictionary::randomShuffle()
{
    if (dictionary.size() > 3) {
        QList<Data> temporaryList;
        int i = 0;
        while(i * 2 < dictionary.size()) {
            Data temporary(dictionary[i * 2].engWord,
                    dictionary[i * 2].rusWords,
                    dictionary[i * 2].date,
                    dictionary[i * 2].repetitionValue);
            temporaryList.push_back(temporary);
//            qDebug() << "Размер временного листа" << temporaryList.size();
//            qDebug() << "Слово dictionary" << i * 2 << dictionary[i * 2].engWord;
//            qDebug() << "Слово temporary" << i << temporaryList[i].engWord;
            i++;
        }
        i = 0;
        while(i * 2 + 1 < dictionary.size()) {
            Data temporary(dictionary[i * 2 + 1].engWord,
                    dictionary[i * 2 + 1].rusWords,
                    dictionary[i * 2 + 1].date,
                    dictionary[i * 2 + 1].repetitionValue);
            temporaryList.push_back(temporary);
//            qDebug() << "Размер временного листа" << temporaryList.size();
//            qDebug() << "Слово dictionary" << i * 2 + 1 << dictionary[i * 2 + 1].engWord;
//            qDebug() << "Слово temporary" << temporaryList.size() - 1 << temporaryList[temporaryList.size() - 1].engWord;
            i++;
        }
//        qDebug() << "Размер временного листа" << temporaryList.size();
        for (int i = 0; i < temporaryList.size(); i++) {
            dictionary[i] = temporaryList[i];
        }
    }
}

void Dictionary::wordCheck(QString engWord, QString rusWord)
{
    if (engWord == "" || rusWord == "") {

    }
}

void Dictionary::setLineCount(int lineCount)
{
    if (m_lineCount == lineCount)
        return;

    m_lineCount = lineCount;
    emit lineCountChanged(m_lineCount);
}

