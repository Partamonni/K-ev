#include "mainwindow.h"
#include "dropdown.h"
#include "tempentry.h"
#include "otherentry.h"
#include "serialportreader.h"
#include "buttons.h"
#include "shutmotorentry.h"

#include <QTime>
#include <QCoreApplication>

#define RPI 0

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;
extern short int CELL_COUNT;

Mainwindow::Mainwindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(SCR_WIDTH,SCR_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
#if RPI == 0
    this->grabMouse();
    this->grabKeyboard();
#endif
    if(mySerial->openSerialPort())
        mySerial->writeData("!S");

    bgLabel->setFixedSize(SCR_WIDTH,SCR_HEIGHT);

    bgImg->load(":/K-EV_rev4.png");
    *bgImg = bgImg->scaled(SCR_WIDTH, SCR_HEIGHT,
                           Qt::KeepAspectRatioByExpanding,
                           Qt::SmoothTransformation);

    this->setLayout(bgLayout);
    bgLabel->setPixmap(*bgImg);
    bgLayout->addWidget(bgLabel,0,0,1,3);
    bgLayout->addWidget(ampMeter->ampFrame,0,0,Qt::AlignVCenter);
    bgLayout->addWidget(splash->noticeFrame,0,0,1,4,Qt::AlignCenter);
    bgLayout->setContentsMargins(0,0,0,0);

    for(int i = 0; i < 4; ++i)
    {
        bgLayout->setColumnMinimumWidth(i,SCR_WIDTH/4);
    }

    fgLayout->addWidget(dropdown->menu,0,0,Qt::AlignLeft);
    fgLayout->addWidget(tempEntry->entryFrame,0,1);
    fgLayout->addWidget(otherEntry->entryFrame,0,1);
    fgLayout->setContentsMargins(0,0,0,0);
    fgLayout->setColumnMinimumWidth(0,SCR_WIDTH/4);
    fgLayout->setSpacing(0);
    fgLayer->setLayout(fgLayout);
    bgLayout->addWidget(fgLayer,0,0,0,4);

    opaEff->setOpacity(0.98);
    fgLayer->setGraphicsEffect(opaEff);
    fgLayer->raise();

    this->show();
    dropdown->menu->hide();
    tempEntry->entryFrame->hide();
    otherEntry->entryFrame->hide();
    splash->noticeFrame->show();

#if RPI == 0
    connect(this, SIGNAL(menuPressed()), this, SLOT(toggleMenu()) );
    connect(this, SIGNAL(keyPressed()), this, SLOT(toggleEntry()) );
#endif

}

Mainwindow::~Mainwindow(){}

#if RPI == 0
void Mainwindow::mouseReleaseEvent(QMouseEvent *mouseEvent1)
{
    this->lReleaseEvent();
}

void Mainwindow::mousePressEvent(QMouseEvent *mouseEvent2)
{
    this->lPressEvent();
}

void Mainwindow::keyPressEvent(QKeyEvent *keyEvent)
{
    this->rPressEvent();
}


void Mainwindow::lReleaseEvent()
{
    emit this->menuPressed();
    released = true;
}

void Mainwindow::lPressEvent()
{
    released = false; // make sure previous toggles doesn't affect evaluation.
    delay(releaseTime); // don't hang the program while waiting
    if(!released && !dropdown->menu->isHidden())
    {   // if pressed long enough, and menu is visible
        // and not moving, set menu to slide out.
        if(dropdown->motEffMen->state() == QAbstractAnimation::Stopped)
        {
            dropdown->motEffMen->setDirection(QAbstractAnimation::Forward);
            dropdown->motEffMen->start();
            if(tempEntry->entryFrame->isVisible() ||
                    otherEntry->entryFrame->isVisible())
                toggleEntry();
            delay(dropdown->motEffMen->duration());
            dropdown->menu->hide();
            if(!released)
                justClosedFlag = true;
            // Flag to inform that menu has closed if button hasn't
            // been released. If not implemented, menu would open
            // again if button was still held when menu had closed.
        }
    }
}

void Mainwindow::rPressEvent()
{
    if(tempEntry->motEffEntry->state() == QAbstractAnimation::Stopped ||
            tempEntry->motEffEntry->state() ==
            (QAbstractAnimation::Forward | QAbstractAnimation::Running))
    {
        emit keyPressed();
    }
}
#endif

void Mainwindow::toggleMenu()
{
#if RPI
    if(dropdown->menu->isHidden())
#else
    if(justClosedFlag) // capture false start
        justClosedFlag = false;
    else if(dropdown->menu->isHidden())
#endif
    {
        // set direction to open
        dropdown->motEffMen->
                setDirection(QAbstractAnimation::Backward);
        dropdown->selPos = 1; // move selection to top
        dropdown->motEffSel->setStartValue(dropdown->selector->pos());
        dropdown->motEffSel->setEndValue(
                    QPoint(dropdown->selector->x(),
                           dropdown->selector->height()*(dropdown->selPos-1))
                    );
        dropdown->motEffSel->start();
        dropdown->menu->show(); // show menu outside of shown area
        dropdown->motEffMen->start(); // start animation that slides the menu visible
    }
    else // if menu is visible, change entry
    {
        if(dropdown->selPos < dropdown->entries)
            ++dropdown->selPos;
        else
            dropdown->selPos = 1;
        if(dropdown->motEffSel->state() == dropdown->motEffSel->Running)
            dropdown->motEffSel->stop();
        // If menu selector is advanced while animation is still running,
        // cancel animation to start new one from the old destination.
        // (Prevents glitching and looks sharper.)

        dropdown->motEffSel->setStartValue(dropdown->selector->pos());
        dropdown->motEffSel->setEndValue(
                    QPoint(dropdown->selector->x(),
                           dropdown->selector->height()*(dropdown->selPos-1))
                    );
        dropdown->motEffSel->start();
    }
}

void Mainwindow::shutMenu()
{
    if(!dropdown->menu->isHidden())
    {   // if pressed long enough, and menu is visible
        // and not moving, set menu to slide out.
        if(dropdown->motEffMen->state() == QAbstractAnimation::Stopped)
        {
            dropdown->motEffMen->setDirection(QAbstractAnimation::Forward);
            dropdown->motEffMen->start();
            if(dropdown->entryOpen)
                toggleEntry();

            // Flag to inform that menu has closed if button hasn't
            // been released. If not implemented, menu would open
            // again if button was still held when menu had closed.
        }
    }
}

void Mainwindow::toggleEntry()
{
    if(dropdown->menu->isVisible())
    {

        if(dropdown->entryOpen && lastEntryFunc != NULL)
            (this->*lastEntryFunc)();

        switch(dropdown->selPos)
        {
        case 1:
            toggleTempEntry();
            lastEntryFunc = &Mainwindow::toggleTempEntry;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            toggleMotorEntry();
            lastEntryFunc = &Mainwindow::toggleTempEntry;
            break;
        }
    }
}

void Mainwindow::toggleTempEntry()
{
    if(tempEntry->entryFrame->isHidden() && !dropdown->entryOpen)
    {
        tempEntry->motEffEntry->setDirection(QAbstractAnimation::Forward);
        // set direction to open
        tempEntry->motEffEntry->setStartValue(QPoint(QPoint(-SCR_WIDTH*3/4, 0)));
        tempEntry->motEffEntry->setEndValue(QPoint(SCR_WIDTH/4,0));

        dropdown->menu->raise();
        tempEntry->entryFrame->show();
        tempEntry->motEffEntry->start();
        dropdown->entryOpen = true;
    }
    else if(tempEntry->entryFrame->isVisible())
    {
        tempEntry->motEffEntry->setDirection(QAbstractAnimation::Backward);
        tempEntry->motEffEntry->setStartValue(QPoint(-SCR_WIDTH*3/4, 0));
        tempEntry->motEffEntry->setEndValue(QPoint(SCR_WIDTH/4,0));

        dropdown->menu->raise();
        tempEntry->motEffEntry->start();
    }
    dropdown->menu->setFocus();
}

void Mainwindow::toggleMotorEntry()
{
#if RPI
    if(!shutMotor->getState())
    {
        mySerial->writeData("!S");
        motorShutTimer->singleShot(100, this, SLOT(toggleMotorEntry(false)));
    }
#else
    toggleMotorEntry(shutMotor->getState());
#endif
}

void Mainwindow::toggleMotorEntry(bool success)
{
    if(success)
    {
        motorShutTimer->stop();
        dropdown->e6->entry->setText("Motor Power\nOn");
        splash->showText("Traction is now off");
        shutMotor->setState(false);
    }
    else
    {
        dropdown->e6->entry->setText("Motor Power\nOff");
        splash->showText("Traction is now on");
        shutMotor->setState(true);
    }

}

void Mainwindow::delay(int millisecondsToWait)
{ // allows establishing within-code timers which won't hang up the program (gold nugget!)
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Mainwindow::menuIsShutFunc()
{
    if(dropdown->motEffMen->direction() == QAbstractAnimation::Forward)
        dropdown->menu->hide();
    justClosedFlag = false;
}

void Mainwindow::entryIsShutFunc()
{
    if(tempEntry->motEffEntry->direction() == QAbstractAnimation::Backward)
    {
        tempEntry->entryFrame->hide();
        dropdown->entryOpen = false;
    }
}
