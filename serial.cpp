#include "serial.h"
#include "mainwindow.h"
#include <QtSerialPort/QSerialPort>


extern int BAUD;
extern short int CELL_COUNT;

Serial::Serial(Mainwindow *parent)
{
    port->setPortName("/dev/ttyAMA0");
    if (!port->open(QIODevice::ReadWrite))
    {
        // Serial port couldn't open
    }
    port->setBaudRate(BAUD);

    connect(port, &Serial::readyRead, readData());
}

void Serial::readData()
{
    if(!connectionEstablished && port->readLine(,6))
    {
        // Reading error
    }
    else if(data->at(0) == '!')
    {
        if(data->at(1) == 'C')
        {
            // Bad current
        }
        else if(data->at(1) == 'V')
        {
            // High Voltage
        }
        else if(data->at(1) == 'T')
        {
            // High temp
        }
        else if(data->at(1) == 'v')
        {
            // Low voltage
        }
        else if(data->at(1) == 'h')
        {
            // RasPi didn't respond in time
            port->write("ok\n");
            connectionEstablished = false;
        }
        else
        {
            emit port->errorOccurred(QSerialPort::UnknownError);
        }
    }
    else if(data->at(0) == 'u' && data->at(1) == 'p')
    {
        // PCU opened the MOSFET switch
    }
    else if(data->at(0) == '?' && data->at(1) == 'h')
        port->write("ok\n");
    else if(data->at(0) == 's' && data->at(1) == 'h')
    {
        // Gates were shut but RasPi didn't handle it
    }
    else if(!connectionEstablished)
    {
        // Do something with current, value is already read to data
        port->readLine(data,3); // Do something with voltage

        port->clear(QSerialPort::Input);
        // Ignore all other input this time
        connectionEstablished = true;
    }
    else if(connectionEstablished)
    {
        port->readLine(data,6);
        // Do something with current
        port->readLine(data,6);
        // Do something with voltage
        for(int i = 0; i < CELL_COUNT; ++i)
        {
            port->readLine(data,6);

            // Do something for temperature of cell i
        }
        port->readLine(data,2);
        if(!(data->at(0) == 'e'))
        {
            // Data ending not received
            emit port->errorOccurred(QSerialPort::ReadError);
        }
    }
}
