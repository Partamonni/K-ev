#include "errorsentry.h"

#include "mainwindow.h"

ErrorsEntry::ErrorsEntry(Mainwindow *parent) : Entry(parent)
{
    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
