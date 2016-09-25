#include "srwindow.h"
#include "ui_srwindow.h"
#include "roulettesourcestorage.h"
#include <QSettings>

SRWindow::SRWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SRWindow)
{    
    ui->setupUi(this);    
    ui->rollValue->setAlignment(Qt::AlignCenter);
    localization();
}

SRWindow::~SRWindow()
{
    delete ui;
}

void SRWindow::localization()
{
    this->setWindowTitle(QObject::tr("SRWindowTitle"));
    this->ui->rollButton->setText(QObject::tr("SRRollButtonTitle"));
}

void SRWindow::on_rollButton_clicked()
{
    getRandomValue();   
}

void SRWindow::fetchRolledValue()
{
    QObject* sender = const_cast<QObject*>(QObject::sender());
    RouletteSourceStorage* rss = static_cast<RouletteSourceStorage*>(sender);
    QPair<int, QString> rollPair = rss->ROLL_PAIR;
    showRolledValue(rollPair.first, rollPair.second);
}

void SRWindow::showRolledValue(const int position, const QString value)
{
    this->ui->rollValue->setText(value);
    this->ui->statusBar->showMessage("rolled " + QVariant(position).toString() + " !");
}
