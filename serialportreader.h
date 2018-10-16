#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QString>

class QLabel;
class Mainwindow;

class SerialPortReader : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortReader(Mainwindow *parent = 0);
    ~SerialPortReader();

    QString *inData = new QString;

signals:
    void motorIsShut(bool);

public slots:
    bool openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &outData);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void displayMessage(const QString &message);

    QSerialPort *m_serial = nullptr;
    Mainwindow *m_parent;
    int entry = 1;
};

#endif
