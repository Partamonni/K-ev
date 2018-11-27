#include "seriallogentry.h"

#include "mainwindow.h"

SerialLogEntry::SerialLogEntry(Mainwindow *parent) : Entry(parent)
{
    serialLog->setFont(QFont("Source Code Variable"));
    serialLog2->setFont(QFont("Source Code Variable"));

    entryLayout->addWidget(serialLog, 0, 0, (Qt::AlignTop | Qt::AlignLeft));
    entryLayout->addWidget(serialLog2, 0, 1, (Qt::AlignTop | Qt::AlignLeft));
    entryLayout->setMargin(30);

    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}

void SerialLogEntry::addLine(QString line)
{
    data.prepend(line);
    if(data.size() > 20)
    {
        data2.prepend(data.last());
        data.removeLast();

        if(data2.size() > 20)
        {
            data2.removeLast();
        }
    }
    temp->clear();
    for(QString line : data)
    {
        temp->append("\n");
        temp->append(line);
    }
    serialLog->setText(*temp);
    temp->clear();
    for(QString line : data2)
    {
        temp->append("\n");
        temp->append(line);
    }
    serialLog2->setText(*temp);
}
