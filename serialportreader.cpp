#include "serialportreader.h"
#include "mainwindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"


//QT_USE_NAMESPACE


SerialPortReader::SerialPortReader(Mainwindow *parent) :
        //QMainWindow(parent),
        status(new QLabel),
        m_serial(new QSerialPort(this))
{
    m_parent = parent;

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
        showStatusMessage(tr("Connected"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}

void SerialPortReader::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    showStatusMessage(tr("Disconnected"));
}

void SerialPortReader::writeData(const QByteArray &outData)
{
    m_serial->write(outData);
}

void SerialPortReader::readData()
{
    const QByteArray data = m_serial->readAll();

    if(!readyToRec)
    {
        if(inData->length() <= 2)
            inData->append(QString::fromUtf8(data));

        if(inData->at(0) == '?')
        {
            if(inData->at(1) == h)
            {
                m_serial->writeData("ok\n",3);
                readyToRec = true;
            }
            else
            {
                //error?
            }
        }
        else if(inData->at(0) == '!')
        {
            // Control board errors
        }
        else
            inData->clear();
    }

    showStatusMessage(*inData);
}

void SerialPortReader::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void SerialPortReader::showStatusMessage(const QString &message)
{
    status->setText(message);
    m_parent->ampMeter->amps->setText(message);
}
