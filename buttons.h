#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QTime>
#include <QTimer>

#define RPI 0

class Mainwindow;

class Buttons : public QObject
{
#if RPI

    Q_OBJECT
public:
    explicit Buttons(Mainwindow *parent = 0);

    Mainwindow *m_parent;

    bool lActive = false;
    bool lLock = false;
    bool lDown = false;
    bool rActive = false;

    static void isrCatchR();
    static void isrCatchL();

    void delay(int millisecondsToWait);

    QTimer *timerL = new QTimer(this);
    QTimer *timerR = new QTimer(this);

signals:
    void buttonPressedL();
    void buttonPressedR();

private:
    bool longPressL = false;


public slots:
    void buttonInterruptL();
    void buttonInterruptR();
    void shutMenuFunc();

#endif
};

#endif // BUTTONS_H
