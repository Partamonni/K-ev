#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>

class DigitalClock : public QWidget
{
    Q_OBJECT
public:
    DigitalClock();

    QLabel *display = new QLabel;

private slots:
    void changeTime();

private:
    QTime time;
    QTimer *updateInterval = new QTimer;
};

#endif // DIGITALCLOCK_H
