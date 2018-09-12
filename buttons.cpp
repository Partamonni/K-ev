
#define RPI 1

#if RPI

#include "buttons.h"
#include "mainwindow.h"
#include <wiringPi.h>

#include <QTime>
#include <QTimer>
#include <QCoreApplication>

#define output33 1
#define inputL 26
#define inputR 27

extern Buttons *isrClass;

Buttons::Buttons(Mainwindow *parent)
{
    isrClass = this;
    wiringPiSetup();
    m_parent = parent;
    pinMode(output33, OUTPUT);
    digitalWrite(output33, 1);

    pinMode(inputL, INPUT);
    pinMode(inputR, INPUT);
    pullUpDnControl(inputL, PUD_UP);
    pullUpDnControl(inputR, PUD_UP);

    wiringPiISR(inputL, INT_EDGE_BOTH, isrCatchL);
    wiringPiISR(inputR, INT_EDGE_BOTH, isrCatchR);

    connect(this, SIGNAL(buttonPressedL()), this, SLOT(buttonInterruptL()));
    connect(this, SIGNAL(buttonPressedR()), this, SLOT(buttonInterruptR()));
    connect(timerL, SIGNAL(timeout()), this, SLOT(shutMenuFunc()));
}

void Buttons::buttonInterruptL()
{
    if(!lLock)
    {
        lLock = true;
        delay(50);
        if(!lDown && !digitalRead(inputL))
        {
            lDown = true;
            timerL->start(m_parent->releaseTime);
        }
        else
            lLock = false;

        lActive = false;
    }
    else
    {
        delay(50);
        if(digitalRead(inputL))
        {
            timerL->stop();
            lLock = false;
            lDown = false;
            lActive = false;
            m_parent->toggleMenu();
        }
        else
            lActive = false;
    }
}

void Buttons::buttonInterruptR()
{
    delay(200);
    if(digitalRead(inputL))
    {
        m_parent->toggleEntry();
    }

    rActive = false;
}

void Buttons::isrCatchL()
{
    if(!isrClass->lActive)
    {
        emit isrClass->buttonPressedL();
        isrClass->lActive = true;
    }
    return;
}

void Buttons::isrCatchR()
{
    if(!isrClass->rActive)
    {
        emit isrClass->buttonPressedR();
        isrClass->rActive = true;
    }
    return;
}

void Buttons::delay(int millisecondsToWait)
{ // allows establishing within-code timers which won't hang up the program (gold nugget!)
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Buttons::shutMenuFunc()
{
    m_parent->justClosedFlag = true;
    m_parent->shutMenu();
    lLock = false;
    lDown = false;
    lActive = false;
}
#endif
