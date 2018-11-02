#ifndef STATUSENTRY_H
#define STATUSENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include "entry.h"

class Mainwindow;

class StatusEntry : public Entry
{
    Q_OBJECT
public:
    StatusEntry(Mainwindow *parent = nullptr);

    /*QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QPixmap *entryBg = new QPixmap(":/entry.png");
    QLabel *canvas = new QLabel(entryFrame);
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
*/};


#endif // STATUSENTRY_H
