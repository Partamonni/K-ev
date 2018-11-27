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

    void addLine(QString);

private:
    QLabel *serialLog = new QLabel;
    QVector<QString> data;
    QLabel *serialLog2 = new QLabel;
    QVector<QString> data2;
    QString *temp = new QString;

};

#endif // SERIALLOGENTRY_H
