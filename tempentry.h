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

    QLabel *packTemp[41];

signals:

public slots:

private:
    const int cells = CELL_COUNT;
};

#endif // TEMPENTRY_H
