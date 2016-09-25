#include "srwindow.h"
#include "roulettesourcestorage.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include <QTranslator>

const QString RouletteSourceStorage::TEXT_LIST_CONFIG_KEY = "text-list";

void showWindowAtCenter(SRWindow *window)
{
    window->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            window->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    window->show();
}

void configureSRWindow(SRWindow *srWindow)
{
    srWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
}

int main(int argc, char *argv[])
{
    QApplication srApp(argc, argv);
    QTranslator srTranslator;
    srTranslator.load("sr_ru_RU");

    //if need english translation
    //srTranslator.load("sr_ru_EN");

    srApp.installTranslator(&srTranslator);

    RouletteSourceStorage rss;
    rss.fillTextSourcesFromConfig("sources.ini");

    SRWindow srWindow;    
    configureSRWindow(&srWindow);

    QObject::connect(&srWindow, SIGNAL(getRandomValue()), &rss, SLOT(roll()));
    QObject::connect(&rss, SIGNAL(rolling()), &srWindow, SLOT(fetchRolledValue()));

    showWindowAtCenter(&srWindow);
    return srApp.exec();
}
