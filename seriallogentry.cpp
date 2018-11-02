#include "seriallogentry.h"

#include "mainwindow.h"

SerialLogEntry::SerialLogEntry(Mainwindow *parent) : Entry(parent)
{
   connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
