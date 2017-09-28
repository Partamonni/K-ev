#ifndef AMPMETER_H
#define AMPMETER_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QGridLayout>

class AmpMeter : public QLabel
{
    Q_OBJECT

public:
    AmpMeter(QWidget *parent = 0);
    QWidget *ampFrame = new QWidget;
    QGridLayout *ampLay = new QGridLayout;
    QLabel *amps = new QLabel;
    QLabel *ampsUnit = new QLabel;
    QLabel *back = new QLabel;
    QTime *time = new QTime;
    QTimer *timer = new QTimer;
    QFont *font = new QFont;

public slots:
    void changeAmp();

};

#endif // AMPMETER_H
