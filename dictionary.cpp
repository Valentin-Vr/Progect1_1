#include "Dictionary.h"

static QString PATH = ":/dictionary.txt";

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
        if (repetitionValue == 1 || dayDifference == 0 || dayDifference == 1 || dayDifference == 3 || dayDifference == 7 || dayDifference == 14 || dayDifference == 30) {
            Data addToDictionary(valueString[2], valueString[3], QDate::fromString(valueString[0], "ddMMyyyy"), valueString[1].toInt());
            dictionary.push_back(addToDictionary);
        }
        //        Data addToDictionary(valueString[2], valueString[3], QDate::fromString(valueString[0], "ddMMyyyy"), valueString[1].toInt());
        //        dictionary.push_back(addToDictionary);
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
        writeStream << currentDate.toString("ddMMyyyy") << "/" << repetitionValue << "/" << engWord << "/" << rusWord << "\n";
        mFile.close();
    }

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
//    if (nextWord >= dictionary.size()) {
//        nextWord = 0;
//        setlineCount(nextWord);

//    }
    return dictionary[nextWord].engWord;
}

QString Dictionary::rusWord(int nextWord)
{
    return dictionary[nextWord].rusWords;
}

//int Dictionary::lineNumber() const
//{
//    return m_lineNumber;
//}

