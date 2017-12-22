#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsOpacityEffect>
#include "dropdown.h"
#include "tempentry.h"
#include "otherentry.h"
#include "ampmeter.h"
#include "serialportreader.h"

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();

    int releaseTime = 600;
    bool mouseReleased = false;
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
    SerialPortReader *serial = new SerialPortReader;
    void delay(int);

signals:
    void menuPressed();
    void selectDown();
    void keyPressed();

public slots:
    void toggleMenu();
    void toggleEntry();

protected:
    void mouseReleaseEvent(QMouseEvent *mouseEvent1);
    void mousePressEvent(QMouseEvent *mouseEvent2);
    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // MAINWINDOW_H
