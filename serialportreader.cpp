#include "serialportreader.h"
#include "mainwindow.h"

#include <QCoreApplication>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"


//QT_USE_NAMESPACE
extern short int CELL_COUNT;

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
        QMessageBox::critical(this, "Error", m_serial->errorString());

        displayMessage("Open error");
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

        if(inData->at(0) == "e")
            m_serial->write("ok\n");
        else if(inData->at(0) == '?' && inData->at(1) == 'h')
        {
            m_serial->write("ok\n");
        }
        else if(inData->at(0) == "!" || inData->at(0) == "!")
        {
            if(inData->at(1) == 'C')
            {}//Do something
            else if(inData->at(1) == 'V')
            {}//Do something
            else if(inData->at(1) == 'T')
            {}//Do something
            else if(inData->at(1) == 'v')
            {}//Do something
        }
        else if(inData->at(0) == 'u')
        {}
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
