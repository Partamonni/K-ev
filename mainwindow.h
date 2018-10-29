#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsOpacityEffect>
#include <QTime>
#include <QTimer>
#include "dropdown.h"
#include "tempentry.h"
#include "otherentry.h"
#include "ampmeter.h"
#include "serialportreader.h"
#include "buttons.h"
#include "shutmotorentry.h"
#include "notice.h"
#include "digitalclock.h"

#define RPI 0

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();

    int releaseTime = 600;
    bool released = false;
    bool justClosedFlag = false;

    QLabel *bgLabel = new QLabel;
    QPixmap *bgImg = new QPixmap;
    QGridLayout *bgLayout = new QGridLayout;
    QWidget *fgLayer = new QWidget;
    QGridLayout *fgLayout = new QGridLayout;
    Dropdown *dropdown = new Dropdown(this);
    TempEntry *tempEntry = new TempEntry(this);
    OtherEntry *otherEntry = new OtherEntry(this);
    AmpMeter *ampMeter = new AmpMeter;
    QGraphicsOpacityEffect *opaEff = new QGraphicsOpacityEffect;
    SerialPortReader *mySerial = new SerialPortReader(this);
    ShutMotorEntry *shutMotor = new ShutMotorEntry(this);
    Notice *splash = new Notice(this);
    DigitalClock *clock = new DigitalClock;
#if RPI
    Buttons *buttons = new Buttons(this);
#endif
    QTimer *menuTimer = new QTimer(this);
    QTimer *entryTimer = new QTimer(this);

    void delay(int);
#if RPI == 0
    void lReleaseEvent();
    void lPressEvent();
    void rPressEvent();
#endif

signals:
    void menuPressed();
    void keyPressed();

public slots:
    void toggleMenu();
    void shutMenu();
    void toggleEntry();
    void toggleMotorEntry(bool success);

    void menuIsShutFunc();
    void entryIsShutFunc();

#if RPI == 0
protected:
    void mouseReleaseEvent(QMouseEvent *mouseEvent1);
    void mousePressEvent(QMouseEvent *mouseEvent2);
    void keyPressEvent(QKeyEvent *keyEvent);
#endif
private:
    void toggleTempEntry();
    void toggleMotorEntry();
    void (Mainwindow::*lastEntryFunc)() = NULL;

    QTimer *motorShutTimer = new QTimer;

};

#endif // MAINWINDOW_H
