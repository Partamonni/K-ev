#include "statusentry.h"

#include "mainwindow.h"


StatusEntry::StatusEntry(Mainwindow *parent) : Entry(parent)
{
    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
