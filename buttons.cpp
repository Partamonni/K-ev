
#define RPI 0

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
    if(!lDown) // If no pressed down state is present, step into
    {
        lDown = true; // Make code wait for release
        delay(50); // Debounce time
        if(!digitalRead(inputL)) // Check if button really is pressed
        {
            timerL->start(m_parent->releaseTime); // Start counting if button is held down long enough
        }
        else
            lDown = false; // False signal, don't notice it
    }
    else // If button was pressed last time
    {
        delay(50); // Debounce
        if(digitalRead(inputL)) // If it's now released
        {
            timerL->stop(); // Stop timer that counts menu shutdown
            lDown = false; // Set state to be up
            m_parent->toggleMenu(); // Toggle menu instead of closing
        }
    }

    lActive = false; // Let new button interrupts be noticed again
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
        return;
    }
}

void Buttons::isrCatchR()
{
    if(!isrClass->rActive)
    {
        emit isrClass->buttonPressedR();
        isrClass->rActive = true;   
        return;
    }
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
