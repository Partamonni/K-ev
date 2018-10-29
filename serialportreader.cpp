#include "serialportreader.h"
#include "mainwindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"

#define RPI 0


//QT_USE_NAMESPACE
extern short int CELL_COUNT;

SerialPortReader::SerialPortReader(Mainwindow *parent) :
        m_serial(new QSerialPort(this))
{
    m_parent = parent;
    inData->reserve(100);

    connect(m_serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error), this, &SerialPortReader::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &SerialPortReader::readData);
    connect(this, SIGNAL(motorIsShut(bool)), parent, SLOT(toggleMotorEntry(bool)));
}

SerialPortReader::~SerialPortReader()
{}

bool SerialPortReader::openSerialPort()
{
#if RPI
    m_serial->setPortName("ttyAMA0");
#else
    m_serial->setPortName("COM3");
#endif

    m_serial->setBaudRate(QSerialPort::Baud57600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite))
    {
        displayMessage("Connected");
        return true;
    }
    else
    {
        QMessageBox::critical(this, "Error", m_serial->errorString());

        displayMessage("Open error");
        return false;
    }
}

void SerialPortReader::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    displayMessage("Disconnected");
}

void SerialPortReader::writeData(const QByteArray &outData)
{
    m_serial->write(outData);
}

void SerialPortReader::readData()
{
    const QByteArray data = m_serial->readAll();

    inData->append(QString::fromUtf8(data));

    while(inData->contains('\n') || inData->contains('\r'))
    {
        int i;
        if(inData->contains('\n'))
        {
            inData->remove('\r');
            i = inData->indexOf('\n');
        }
        else
            i = inData->indexOf('\r');

        if(inData->at(0) == 'e' || inData->at(0) == '~')
            m_serial->write("ok\n");
        else if(inData->at(0) == '?' && inData->at(1) == 'h')
        {
            m_serial->write("ok\n");
        }
        else if(inData->at(0) == '!')
        {
            if(inData->at(1) == 'C')
            {
                m_parent->splash->showText("Overcurrent detected!");
            }
            else if(inData->at(1) == 'V')
            {
                m_parent->splash->showText("Overvoltage detected!");
            }
            else if(inData->at(1) == 'T')
            {
                m_parent->splash->showText("Overtemperature detected!");
            }
            else if(inData->at(1) == 'v')
            {
                m_parent->splash->showText("Low voltage detected!");
            }
        }
        else if(inData->at(0) == 'u' && inData->at(1) == 'p')
        {
            emit motorIsShut(false);
        }
        else if(inData->at(0) == 's' && inData->at(1) == 'h')
        {
            emit motorIsShut(true);
        }
        else if(inData->at(0) == ':')
        {
            if(inData->at(1) == 'c')
            {
                entry = 1;
                displayMessage(inData->mid(2,i-2));
            }
            else if(inData->at(1) == 'v')
            {
                entry = 2;
                displayMessage(inData->mid(2,i-2));
            }
            else
            {
                QString entryNum = inData->mid(1,inData->indexOf('-')-1);
                entry = entryNum.toInt()+3;
                if(inData->mid(inData->indexOf('-')+1,i-inData->indexOf('-')-1) != "257.0")
                    displayMessage(inData->mid(inData->indexOf('-')+1,i-inData->indexOf('-')-1));
                else
                    displayMessage("CRC");
            }
        }
        else
        {
            // Unknown data
        }

        *inData = inData->remove(0,i+1);

    }
}

void SerialPortReader::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, "Critical Error", m_serial->errorString());
        closeSerialPort();
    }
}

void SerialPortReader::displayMessage(const QString &message)
{
    static QString f_message;
    f_message = message;
    if(entry == 1)
        m_parent->ampMeter->amps->setText(message);
    else if(entry == 2)
        m_parent->ampMeter->volts->setText(message);
    else if(entry >= 3 && entry <= CELL_COUNT+3)
    {
        f_message.append("'C");
        m_parent->tempEntry->packTemp[entry-3]->setText(f_message);
    }
    else
    {}// Do something?

}
