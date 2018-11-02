#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>

class Mainwindow;

class Entry : public QWidget
{
    Q_OBJECT
public:
    Entry(Mainwindow *parent = nullptr);

    QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QPixmap *entryBg = new QPixmap(":/entry.png");
    QLabel *canvas = new QLabel(entryFrame);
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
};

#endif // ENTRY_H
