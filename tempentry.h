#ifndef TEMPENTRY_H
#define TEMPENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include "entry.h"

class Mainwindow;

extern short int CELL_COUNT;

class TempEntry : public Entry
{
    Q_OBJECT
public:
    explicit TempEntry(Mainwindow *parent = nullptr);

//    QWidget *entryFrame = new QWidget();
//    QGridLayout *entryLayout = new QGridLayout;
//    QPixmap *entryBg = new QPixmap(":/entry.png");
//    QLabel *canvas = new QLabel(entryFrame);
//    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
    QLabel *packTemp[41];

signals:

public slots:

private:
    const int cells = CELL_COUNT;
};

#endif // TEMPENTRY_H
