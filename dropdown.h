#ifndef DROPDOWN_H
#define DROPDOWN_H

#include <QWidget>

#include <QLabel>
#include <QGridLayout>
#include <QFont>
#include <QPropertyAnimation>
#include "entrybutton.h"
#include "tempentry.h"

class Mainwindow;

class Dropdown : public QWidget
{
    Q_OBJECT
public:
    explicit Dropdown(Mainwindow *parent);

    short int selPos = 0;
    const short int entries = 6;
    short int entriesInserted = 0;

    QWidget *menu = new QWidget;
    QLabel *selector = new QLabel();
    QPixmap *selectorImg = new QPixmap("C:/Users/Sieni/Pictures/buttonselect.png");
    QGridLayout *layout = new QGridLayout();

    EntryButton *e1 = new EntryButton(this, QString("Cell Voltages"));
    EntryButton *e2 = new EntryButton(this, QString("Temperatures"));
    EntryButton *e3 = new EntryButton(this, QString("Something"));
    EntryButton *e4 = new EntryButton(this, QString("More Something"));
    EntryButton *e5 = new EntryButton(this, QString("About"));
    EntryButton *e6 = new EntryButton(this, QString("Error Messages"));

    QPropertyAnimation *motEffMen = new QPropertyAnimation(menu, "pos"); // motion effect for menu
    QPropertyAnimation *motEffSel = new QPropertyAnimation(selector, "pos"); // motion effect for selector

signals:

public slots:
};

#endif // DROPDOWN_H
