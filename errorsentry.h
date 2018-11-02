#ifndef ERRORSENTRY_H
#define ERRORSENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include "entry.h"

class Mainwindow;

class ErrorsEntry : public Entry
{
    Q_OBJECT
public:
    ErrorsEntry(Mainwindow *parent = nullptr);
};

#endif // ERRORSENTRY_H
