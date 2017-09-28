#ifndef TEMPENTRY_H
#define TEMPENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>

class Mainwindow;

class TempEntry : public QWidget
{
    Q_OBJECT
public:
    explicit TempEntry(Mainwindow *parent = 0);

    QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QPixmap *entryBg = new QPixmap("C:/Users/Sieni/Pictures/entry.png");
    QLabel *canvas = new QLabel(entryFrame);
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");

signals:

public slots:
};

#endif // TEMPENTRY_H
