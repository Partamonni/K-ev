#include "digitalclock.h"
#include <QDebug>

DigitalClock::DigitalClock()
{
    QFont font("Digital-7 Mono", 40, Qt::white);

    time = time.currentTime();
    display->setText(time.toString("hh:mm"));
    display->setFont(font);
    display->setStyleSheet("QLabel {color: white;}");
    display->setMargin(10);

    updateInterval->setSingleShot(false);
    updateInterval->setInterval(2000);
    updateInterval->start();


    connect(updateInterval, SIGNAL(timeout()),
            this, SLOT(changeTime()));
}

void DigitalClock::changeTime()
{
    time = time.currentTime();
    display->setText(time.toString("hh:mm"));
}
