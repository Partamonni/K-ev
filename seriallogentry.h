#ifndef SERIALLOGENTRY_H
#define SERIALLOGENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include "entry.h"

class Mainwindow;

class SerialLogEntry : public Entry
{
    Q_OBJECT
public:
    SerialLogEntry(Mainwindow *parent = nullptr);

};

#endif // SERIALLOGENTRY_H
