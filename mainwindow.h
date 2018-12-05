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
#include "otherentry.h"
#include "ampmeter.h"
#include "serialportreader.h"
#include "buttons.h"
#include "notice.h"
#include "digitalclock.h"
#include "entry.h"
#include "tempentry.h"
#include "errorsentry.h"
#include "seriallogentry.h"
#include "statsentry.h"
#include "statusentry.h"
#include "shutmotorentry.h"

#define RPI 0

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = nullptr);
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
    ErrorsEntry *errorsEntry = new ErrorsEntry(this);
    StatsEntry *statsEntry = new StatsEntry(this);
    StatusEntry *statusEntry = new StatusEntry(this);
    SerialLogEntry *serialLogEntry = new SerialLogEntry(this);
    OtherEntry *otherEntry = new OtherEntry(this);
    ShutMotorEntry *shutMotor = new ShutMotorEntry(this);
    AmpMeter *ampMeter = new AmpMeter;
    QGraphicsOpacityEffect *opaEff = new QGraphicsOpacityEffect;
    SerialPortReader *mySerial = new SerialPortReader(this);
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

private slots:
    void motorShutFailed();

#if RPI == 0
protected:
    void mouseReleaseEvent(QMouseEvent *mouseEvent1);
    void mousePressEvent(QMouseEvent *mouseEvent2);
    void keyPressEvent(QKeyEvent *keyEvent);
#endif
private:
    void toggleTempEntry();
    void toggleStatusEntry();
    void toggleStatsEntry();
    void toggleErrorsEntry();
    void toggleSerialLogEntry();
    void toggleMotorEntry();
    void doSliding(Entry*);
    void (Mainwindow::*lastEntryFunc)() = nullptr;
    Entry *closingEntry = nullptr;
    Entry *entries[6];

    QTimer *motorShutTimer = new QTimer;


};

#endif // MAINWINDOW_H
