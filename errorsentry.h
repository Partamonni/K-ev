#ifndef ERRORSENTRY_H
#define ERRORSENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QString>
#include "entry.h"

class Mainwindow;

class ErrorsEntry : public Entry
{
    Q_OBJECT
public:
    ErrorsEntry(Mainwindow *parent = nullptr);

    void addLine(QString);

private:
    QLabel *errorLog = new QLabel;
    QVector<QString> data;
    QString *temp = new QString;
};

#endif // ERRORSENTRY_H
