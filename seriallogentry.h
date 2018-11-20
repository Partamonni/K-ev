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

public slots:
    void addLine(QString);

private:
    QLabel *serialLog = new QLabel;
    QVector<QString> data;
    QString *temp = new QString;

};

#endif // SERIALLOGENTRY_H
