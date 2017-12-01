#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>

class Serial : QObject
{
    Q_OBJECT

public:
    Serial();
    QSerialPort *port = new QSerialPort;

public slots:
    void readData();

private:
    QString data;
    bool connectionEstablished = false;
};

#endif // SERIAL_H
