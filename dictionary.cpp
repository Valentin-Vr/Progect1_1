#include "dictionary.h"

static QString PATH = "C:/Users/User/Documents/Project1_1/dictionary.txt";

Dictionary::Dictionary(QObject *parent) : QObject(parent)
{
    //Считывание данных из файла
    QDate currentDate(QDate::currentDate());
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    QTextStream file(&mFile);
    while (!file.atEnd()) {
        QString line = file.readLine();
        QStringList valueString = line.split('*');
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
    }
    qDebug() << "Количество слов =" << dictionary.size();
    mFile.close();
}

void Dictionary::writeToFile(QString engWord, QString rusWord)
{
    //Запись в файл нового слова
    if (wordCheck(engWord, rusWord) == true) {
        QDate currentDate(QDate::currentDate());
        int repetitionValue = 0;
        QFile mFile(PATH);
        if(!mFile.exists()) {
            qDebug() << "Файл не существует";
        } else {
            mFile.open(QIODevice::Append | QIODevice::Text);
            QTextStream writeStream(&mFile);
            writeStream << currentDate.toString("ddMMyyyy") << "*" << repetitionValue << "*" << engWord << "*" << rusWord << "*" << "\n";
            mFile.close();
        }
        Data newData(engWord, rusWord, currentDate, repetitionValue);
        dictionary.push_back(newData);
    }
    qDebug() << "Количество слов =" << dictionary.size();
}

QString Dictionary::openFile()
{
    //Открытие блокнота
        QProcess process;
        process.start("notepad C:/Users/User/Documents/Project1_1/dictionary.txt");
        process.waitForFinished();
    //Открытие файла
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::ReadOnly);
    }
    QByteArray data;
    data = mFile.readAll();
    mFile.close();
    return QString(data);
}

QString Dictionary::engWord(int nextWord)
{
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

int Dictionary::numberOfLines()
{
    int numberOfLines = 0;
    QFile mFile(PATH);
    if(!mFile.exists()) {
        qDebug() << "Файл не существует";
    } else {
        mFile.open(QIODevice::Append | QIODevice::Text);
        QTextStream file(&mFile);
        while (!file.atEnd()) {
            numberOfLines++;
        }
        mFile.close();
    }
    qDebug() << "numberOfLines" << numberOfLines;
    return numberOfLines;
}


int Dictionary::lineCount() const
{
    return m_lineCount;
}

void Dictionary::randomShuffle()
{
    //Пересортировка слов в словаре после первого и последующих кругов повторения
    if (dictionary.size() > 3) {
        QList<Data> temporaryList;
        int i = 0;
        while(i * 2 < dictionary.size()) {
            Data temporary(dictionary[i * 2].engWord,
                    dictionary[i * 2].rusWords,
                    dictionary[i * 2].date,
                    dictionary[i * 2].repetitionValue);
            temporaryList.push_back(temporary);
            i++;
        }
        i = 0;
        while(i * 2 + 1 < dictionary.size()) {
            Data temporary(dictionary[i * 2 + 1].engWord,
                    dictionary[i * 2 + 1].rusWords,
                    dictionary[i * 2 + 1].date,
                    dictionary[i * 2 + 1].repetitionValue);
            temporaryList.push_back(temporary);
            i++;
        }
        for (int i = 0; i < temporaryList.size(); i++) {
            dictionary[i] = temporaryList[i];
        }
    }
}

bool Dictionary::wordCheck(QString engWord, QString rusWord)
{
    //Проверка нового слова на необходимость добавления в словарь
    if ((engWord.size() > 1 && rusWord.size() > 1) || (engWord.size() == 1 && engWord[0] == QChar('i'))) {
        //Проверка на наличие символа "*" в engWord
        for (int i = 0; i < engWord.size(); i++) {
            if (engWord[i] == QChar('*')) {
                return false;
            }
        }
        //Проверка на наличие символа "*" в rusWord
        for (int i = 0; i < rusWord.size(); i++) {
            if (rusWord[i] == QChar('*')) {
                return false;
            }
        }
        //Проверка на наличие engWord в словаре
        QFile mFile(PATH);
        if(!mFile.exists()) {
            qDebug() << "Файл не существует";
        } else {
            mFile.open(QIODevice::ReadOnly | QIODevice::Text);
        }
        QTextStream file(&mFile);
        while (!file.atEnd()) {
            QString line = file.readLine();
            QStringList valueString = line.split('*');
            if (engWord == valueString[2]) {
                mFile.close();
                return false;
            }
        }
        mFile.close();
        return true;
    }
    return false;
}

void Dictionary::setLineCount(int lineCount)
{
    if (m_lineCount == lineCount)
        return;

    m_lineCount = lineCount;
    emit lineCountChanged(m_lineCount);
}

