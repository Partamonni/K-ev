#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>

class Mainwindow;

class Serial : QObject
{
    Q_OBJECT

public:
    Serial(Mainwindow *parent = 0);
    QSerialPort *port = new QSerialPort;

public slots:
    void readData();

signals:
    void readyRead();

private:
    QByteArray *data = new QByteArray;
    bool connectionEstablished = false;
};

#endif // SERIAL_H
