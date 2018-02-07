#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QString>

//#include "mainwindow.h"


class QLabel;
class Mainwindow;

class SerialPortReader : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortReader(Mainwindow *parent = 0);
    ~SerialPortReader();

    //QLabel *status = nullptr;
    QString *inData = new QString;

public slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &outData);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void displayMessage(const QString &message);

    QSerialPort *m_serial = nullptr;
    Mainwindow *m_parent;
    bool readyToRec = false;
};

#endif
