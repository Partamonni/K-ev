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
    bool entryOpen = false;

    QWidget *menu = new QWidget();
    QLabel *selector = new QLabel();
    QPixmap *selectorImg = new QPixmap(":/buttonselect.png");
    QGridLayout *layout = new QGridLayout();

    EntryButton *e1 = new EntryButton(this, QString("Temperatures"));
    EntryButton *e2 = new EntryButton(this, QString("Status"));
    EntryButton *e3 = new EntryButton(this, QString("Stats"));
    EntryButton *e4 = new EntryButton(this, QString("Error Messages"));
    EntryButton *e5 = new EntryButton(this, QString("Serial Log"));
    EntryButton *e6 = new EntryButton(this, QString("Motor Power\nOn"));

    QPropertyAnimation *motEffMen = new QPropertyAnimation(menu, "pos"); // motion effect for menu
    QPropertyAnimation *motEffSel = new QPropertyAnimation(selector, "pos"); // motion effect for selector

signals:

public slots:
};

#endif // DROPDOWN_H
