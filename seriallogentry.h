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
    SerialLogEntry(Mainwindow *parent = 0);
/*
    QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QPixmap *entryBg = new QPixmap(":/entry.png");
    QLabel *canvas = new QLabel(entryFrame);
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
*/};

#endif // SERIALLOGENTRY_H
