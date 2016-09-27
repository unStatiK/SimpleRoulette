#include "srwindow.h"
#include "roulettesourcestorage.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include <QTranslator>
#include <QFile>
#include <QTextStream>

const QString RouletteSourceStorage::TEXT_LIST_CONFIG_KEY = "text-list";
const QString appStyleFile = "style/general.css";

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

QString failBackStyle()
{
    return " "
           "QWidget#mainWindow  {"
                                 "background-color: #000000;"
                                "}"
           "QLabel#rollValue  {"
                                 "color: #ffffff;"
                              "}"

           "QPushButton#rollButton {"
                                    "border: 1px solid #ef9327;"
                                    "border-radius: 6px;"
                                    "background-color: #116a06;"
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #e5f2f7, stop: 1 #bbe4ef);"
                                    "}"
           "QPushButton#rollButton:pressed {"
                                    "border: 1px solid #989898;"
                                    "background-color: #222222;"
                                    "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0  #787878, stop: 1 #989898);"
                                   "}";
}

void loadStyle(QApplication *srApp)
{
    QString style = srApp->styleSheet();
    QString appCss = "";

    QFile file(appStyleFile);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        appCss = failBackStyle();
    } else {
        QTextStream in(&file);
        appCss = in.readAll();
        file.close();
    }

    srApp->setStyleSheet(appCss);
}

int main(int argc, char *argv[])
{
    QApplication srApp(argc, argv);
    QTranslator srTranslator;
    srTranslator.load("sr_ru_RU");

    //if need english translation
    //srTranslator.load("sr_ru_EN");

    srApp.installTranslator(&srTranslator);
    loadStyle(&srApp);

    RouletteSourceStorage rss;
    rss.fillTextSourcesFromConfig("sources.ini");

    SRWindow srWindow;    
    configureSRWindow(&srWindow);

    QObject::connect(&srWindow, SIGNAL(getRandomValue()), &rss, SLOT(roll()));
    QObject::connect(&rss, SIGNAL(rolled()), &srWindow, SLOT(fetchRolledValue()));

    showWindowAtCenter(&srWindow);
    return srApp.exec();
}
