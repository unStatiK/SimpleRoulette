#ifndef ROULETTESOURCESTORAGE_H
#include "randomadapter.h"
#include <QSet>
#include <QPair>
#define ROULETTESOURCESTORAGE_H

#include <QObject>

class RouletteSourceStorage : public QObject
{
    Q_OBJECT
public:
    explicit RouletteSourceStorage(QObject *parent = 0);
    void fillTextSourcesFromConfig(const QString filename);    
    QPair<int, QString> getRolledValue();

private:
    RandomAdapter ra;
    QSet<QString> TEXT_SOURCES;
    QPair<int, QString> ROLL_PAIR;
    static const QString TEXT_LIST_CONFIG_KEY;

    QPair<int, QString> getNextRandomValue();

signals:
    void rolled();

public slots:
    void roll();
};

#endif // ROULETTESOURCESTORAGE_H
