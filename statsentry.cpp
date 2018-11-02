#include "statsentry.h"

#include "mainwindow.h"

StatsEntry::StatsEntry(Mainwindow *parent) : Entry(parent)
{
    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
