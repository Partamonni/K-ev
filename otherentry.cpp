#include "otherentry.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <QTextEdit>
#include <QPropertyAnimation>

#include "mainwindow.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;
extern short int CELL_COUNT;


OtherEntry::OtherEntry(Mainwindow *parent) : QWidget(parent)
{
    short int ENT_WIDTH = SCR_WIDTH*3/4;

    QFont font("Arial", 10, Qt::white);

    motEffEntry->setEasingCurve(QEasingCurve::InSine);

    entryFrame->setFixedSize(ENT_WIDTH,SCR_HEIGHT);
    entryFrame->setContentsMargins(20,0,20,0);
    entryFrame->setStyleSheet("*{background-color: black; color: white;}");

    entryFrame->setLayout(entryLayout);

    entryLayout->setContentsMargins(0,0,0,0);
    entryLayout->setSpacing(0);

    std::ifstream txtFile;
    txtFile.open("C:/Users/Sieni/Documents/lgpl.txt");
    QString text;
    std::string line;

    while(std::getline(txtFile, line))
    {
        text.append(QString::fromStdString(line));
        text.append("\n");
    }

    textField->setText(text);

    entryLayout->addWidget(textField,0,0,Qt::AlignHCenter);

    motEffOth->setDirection(QAbstractAnimation::Forward); // set direction to open
    motEffOth->setDuration(60000);
    motEffOth->setStartValue(textField->pos());
    motEffOth->setEndValue(QPoint(textField->x(),textField->y() - textField->height()));
}
