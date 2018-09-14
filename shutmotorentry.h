#ifndef SHUTMOTORENTRY_H
#define SHUTMOTORENTRY_H
#include <QObject>

class Mainwindow;

class ShutMotorEntry : public QObject
{
    Q_OBJECT

public:
    explicit ShutMotorEntry(Mainwindow *parent);

    void cutPower(Mainwindow *parent);
    void setState(bool newState){m_onState = newState;}
    bool getState(){return m_onState;}

private:
    bool m_onState = false;
};

#endif // SHUTMOTORENTRY_H
