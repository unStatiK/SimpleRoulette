#include "roulettesourcestorage.h"
#include <QSettings>

RouletteSourceStorage::RouletteSourceStorage(QObject *parent) : QObject(parent)
{   
}

void RouletteSourceStorage::fillTextSourcesFromConfig(const QString filename)
{
    QSettings settings(filename, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    if(settings.contains(this->TEXT_LIST_CONFIG_KEY)) {
        QVariant textListParameterValue = settings.value(this->TEXT_LIST_CONFIG_KEY);
        QSet<QString> sourceTextValues = textListParameterValue.toString().split(",").toSet();

        foreach (const QString &value, sourceTextValues) {
            this->TEXT_SOURCES.insert(value.trimmed());
        }
    }
}

void RouletteSourceStorage::roll()
{    
    this->ROLL_PAIR = getNextRandomValue();
    rolling();
}

QPair<int, QString> RouletteSourceStorage::getNextRandomValue()
{
    QPair<int, QString> rollPair;
    int position = this->ra.getRandomPosition(this->TEXT_SOURCES.size());
    QString value = this->TEXT_SOURCES.values().at(position);
    rollPair.first = position;
    rollPair.second = value;
    return rollPair;
}
