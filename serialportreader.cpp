#include "serialportreader.h"
#include "mainwindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"


//QT_USE_NAMESPACE


SerialPortReader::SerialPortReader(Mainwindow *parent) :
        m_serial(new QSerialPort(this))
{
    m_parent = parent;
    inData->reserve(100);

    connect(m_serial, &QSerialPort::errorOccurred, this, &SerialPortReader::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &SerialPortReader::readData);
}

SerialPortReader::~SerialPortReader()
{}

void SerialPortReader::openSerialPort()
{
    m_serial->setPortName("COM7");
    m_serial->setBaudRate(QSerialPort::Baud57600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite))
    {
        displayMessage(tr("Connected"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        displayMessage(tr("Open error"));
    }
}

void SerialPortReader::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    displayMessage(tr("Disconnected"));
}

void SerialPortReader::writeData(const QByteArray &outData)
{
    m_serial->write(outData);
}

void SerialPortReader::readData()
{
    const QByteArray data = m_serial->readAll();

    inData->append(QString::fromUtf8(data));

    m_serial->write("ok\n");

    if(inData->length() >= 4 && (inData->contains('\n') || inData->contains('\r')))
    {
        int i = inData->indexOf('\n');
        if(i < 0)
            i = inData->indexOf('\r');
        displayMessage(inData->left(i));
        *inData = inData->remove(0,i+1);
    }
}

void SerialPortReader::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void SerialPortReader::displayMessage(const QString &message)
{
    m_parent->ampMeter->amps->setText(message);
}
