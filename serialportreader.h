#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QString>
#include <QTimer>

class QLabel;
class Mainwindow;

class SerialPortReader : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortReader(Mainwindow *parent = nullptr);
    ~SerialPortReader();

signals:
    void motorIsShut(bool);

public slots:
    bool openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &outData);
    void readData();

private slots:
    void stopBreak();
    void handleError(QSerialPort::SerialPortError error);

private:
    void displayMessage(const QString &message);

    QString *inData = new QString;
    QSerialPort *m_serial = nullptr;
    Mainwindow *m_parent;
    int entry = 1;
    QTimer *breakTimer = new QTimer;
};

#endif
