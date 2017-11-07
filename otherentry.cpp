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
    entryFrame->setStyleSheet("*{background-color: black; color: white;}");

    entryFrame->setLayout(entryLayout);


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
    textField->setFixedHeight(10000);
    textField->setFixedWidth(ENT_WIDTH);
    textField->setContentsMargins(50,0,0,0);

    entryLayout->addWidget(textField,0,0,(Qt::AlignTop | Qt::AlignLeft));

    motEffOth->setDirection(QAbstractAnimation::Forward); // set direction to open
    motEffOth->setDuration(60000);
    motEffOth->setStartValue(QPoint(1/4*SCR_WIDTH,0));
    motEffOth->setEndValue(QPoint(1/4*SCR_WIDTH,-(textField->height())));
}
