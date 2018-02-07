#include "mainwindow.h"
#include "dropdown.h"
#include "tempentry.h"
#include "otherentry.h"
#include "serialportreader.h"

#include <QTime>
#include <QCoreApplication>

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;
extern short int CELL_COUNT;

Mainwindow::Mainwindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(SCR_WIDTH,SCR_HEIGHT);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->grabMouse();
    this->grabKeyboard();

    mySerial->openSerialPort();

    bgLabel->setFixedSize(this->width(),this->height());

    bgImg->load("C:/Users/Sieni/Pictures/K-EV_rev4.png");
    *bgImg = bgImg->scaled(this->width(),this->height(),
                           Qt::KeepAspectRatioByExpanding,
                           Qt::SmoothTransformation);

    this->setLayout(bgLayout);
    bgLabel->setPixmap(*bgImg);
    bgLayout->addWidget(bgLabel,0,0,1,3);
    bgLayout->addWidget(ampMeter->ampFrame,0,0,Qt::AlignVCenter);
    bgLayout->setContentsMargins(0,0,0,0);

    for(int i = 0; i < 4; ++i)
    {
        bgLayout->setColumnMinimumWidth(i,this->width()/4);
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

    connect(this, SIGNAL(menuPressed()), this, SLOT(toggleMenu()) );
    connect(this, SIGNAL(keyPressed()), this, SLOT(toggleEntry()) );
}

Mainwindow::~Mainwindow(){}

void Mainwindow::mouseReleaseEvent(QMouseEvent *mouseEvent1)
{
    emit menuPressed();
    mouseReleased = true;
}

void Mainwindow::mousePressEvent(QMouseEvent *mouseEvent2)
{
    mouseReleased = false; // make sure previous toggles doesn't affect evaluation.
    delay(releaseTime); // don't hang the program while waiting
    if(!mouseReleased && !dropdown->menu->isHidden())
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
            if(!mouseReleased)
                justClosedFlag = true;
            // Flag to inform that menu has closed if button hasn't
            // been released. If not implemented, menu would open
            // again if button was still held when menu had closed.
        }
    }
}

void Mainwindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if(tempEntry->motEffEntry->state() == QAbstractAnimation::Stopped ||
            tempEntry->motEffEntry->state() ==
            QAbstractAnimation::Forward | QAbstractAnimation::Running
            )
        emit keyPressed();
}

void Mainwindow::toggleMenu()
{
    if(justClosedFlag) // capture false start
        justClosedFlag = false;
    else if(dropdown->menu->isHidden())
    {
        dropdown->motEffMen->setDirection(
                    QAbstractAnimation::Backward); // set direction to open
        dropdown->selPos = 1; // move selection to top
        dropdown->motEffSel->setStartValue(dropdown->selector->pos());
        dropdown->motEffSel->setEndValue(
                    QPoint(dropdown->selector->x(),
                           dropdown->selector->height()*(dropdown->selPos-1)));
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

void Mainwindow::toggleEntry()
{
    if(tempEntry->entryFrame->isHidden() && dropdown->selPos == 2
        && dropdown->menu->isVisible() && !dropdown->entryOpen)
    {
        tempEntry->motEffEntry->setDirection(QAbstractAnimation::Forward);
        // set direction to open
        tempEntry->motEffEntry->setStartValue(
                    QPoint(SCR_WIDTH/4 - tempEntry->entryFrame->width(),
                           tempEntry->entryFrame->y())
                    );
        tempEntry->motEffEntry->setEndValue(
                    QPoint(SCR_WIDTH/4,tempEntry->entryFrame->y())
                    );
        dropdown->menu->raise();
        tempEntry->entryFrame->show();
        tempEntry->motEffEntry->start();
        dropdown->entryOpen = true;
    }
    else if(tempEntry->entryFrame->isVisible())
    {
        tempEntry->motEffEntry->setDirection(QAbstractAnimation::Backward);
        tempEntry->motEffEntry->setEndValue(QPoint(tempEntry->entryFrame->pos()));
        tempEntry->motEffEntry->setStartValue(
                    QPoint(SCR_WIDTH/4 - SCR_WIDTH, tempEntry->entryFrame->y())
                    );
        dropdown->menu->raise();
        tempEntry->motEffEntry->start();
        delay(tempEntry->motEffEntry->duration());
        tempEntry->entryFrame->hide();
        dropdown->entryOpen = false;
    }

    if(otherEntry->entryFrame->isHidden() && dropdown->selPos == 6
            && dropdown->menu->isVisible() && !dropdown->entryOpen)
    {
        otherEntry->motEffEntry->setDirection(
                    QAbstractAnimation::Forward); // set direction to open
        otherEntry->motEffEntry->setStartValue(
                    QPoint(SCR_WIDTH/4 - otherEntry->entryFrame->width(),
                           otherEntry->entryFrame->y())
                    );
        otherEntry->motEffEntry->setEndValue(
                    QPoint(SCR_WIDTH/4,otherEntry->entryFrame->y()));
        dropdown->menu->raise();
        otherEntry->entryFrame->show();
        delay(2000);
        otherEntry->motEffEntry->start();
        otherEntry->motEffOth->start();
        dropdown->entryOpen = true;
    }
    else if (otherEntry->entryFrame->isVisible())
    {
        otherEntry->motEffEntry->setDirection(
                    QAbstractAnimation::Backward);
        otherEntry->motEffEntry->setEndValue(
                    QPoint(otherEntry->entryFrame->pos()));
        otherEntry->motEffEntry->setStartValue(
                    QPoint(SCR_WIDTH/4 - SCR_WIDTH, otherEntry->entryFrame->y()));
        dropdown->menu->raise();
        dropdown->entryOpen = false;
        otherEntry->motEffEntry->start();
        delay(tempEntry->motEffEntry->duration());
        otherEntry->entryFrame->hide();
        otherEntry->motEffOth->stop();
    }
}

void Mainwindow::delay( int millisecondsToWait )
{ // allows establishing within-code timers which won't hang up the program (gold nugget!)
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
