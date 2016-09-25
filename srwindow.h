#ifndef SRWINDOW_H
#define SRWINDOW_H

#include <QMainWindow>

namespace Ui {
class SRWindow;
}

class SRWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SRWindow(QWidget *parent = 0);
    ~SRWindow();

signals:
    void getRandomValue();

public slots:
    void fetchRolledValue();

private slots:
    void on_rollButton_clicked();

private:
    Ui::SRWindow *ui;

    void localization();
    void showRolledValue(const int position, const QString value);
};

#endif // SRWINDOW_H
