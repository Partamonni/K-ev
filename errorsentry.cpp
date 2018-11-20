#include "errorsentry.h"

#include "mainwindow.h"

ErrorsEntry::ErrorsEntry(Mainwindow *parent) : Entry(parent)
{
    entryLayout->addWidget(errorLog, 0, 0, (Qt::AlignTop | Qt::AlignLeft));
    entryLayout->setMargin(30);

    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}

void ErrorsEntry::addLine(QString line)
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
    errorLog->setText(*temp);
}
