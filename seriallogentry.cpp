#include "seriallogentry.h"

#include "mainwindow.h"

SerialLogEntry::SerialLogEntry(Mainwindow *parent) : Entry(parent)
{
    entryLayout->addWidget(serialLog, 0, 0, (Qt::AlignTop | Qt::AlignLeft));
    entryLayout->setMargin(30);

    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}

void SerialLogEntry::addLine(QString line)
{
    data.prepend(line);
    if(data.size() > 20)
        data.removeLast();
    temp->clear();
    for(QString line : data)
    {
        temp->append("\n");
        temp->append(line);
    }
    serialLog->setText(*temp);
}
