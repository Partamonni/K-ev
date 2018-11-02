#ifndef STATSENTRY_H
#define STATSENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include "entry.h"

class Mainwindow;

class StatsEntry : public Entry
{
    Q_OBJECT
public:
    StatsEntry(Mainwindow *parent = 0);
/*
    QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QPixmap *entryBg = new QPixmap(":/entry.png");
    QLabel *canvas = new QLabel(entryFrame);
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
*/};


#endif // STATSENTRY_H
