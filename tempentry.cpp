#include "tempentry.h"
#include <math.h>

#include "mainwindow.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;


TempEntry::TempEntry(Mainwindow *parent) : QWidget(parent)
{
    short int entWidth = SCR_WIDTH*3/4;
    int columns = 4;

    QFont font("Digital-7 Mono", 28, Qt::white);

    motEffEntry->setEasingCurve(QEasingCurve::InSine);
    motEffEntry->setDuration(800);

    for (int i=0; i<cells; ++i)
    {
        packTemp[i] = new QLabel(this);
        packTemp[i]->setFont(font);
        packTemp[i]->setStyleSheet("QLabel {background-color: rgba(0,0,0,80); color: white;}");
    }

    entryFrame->setFixedSize(entWidth, SCR_HEIGHT);
    entryFrame->setContentsMargins(0,20,0,20);

    entryLayout->setVerticalSpacing(8);

    *entryBg = entryBg->scaled(entryFrame->size(),Qt::IgnoreAspectRatio);
    canvas->setPixmap(*entryBg);
    canvas->setFixedSize(entryFrame->size());
    entryFrame->setLayout(entryLayout);

    int rows;
    do
    {
        double a = cells;
        double b = columns;
        double rowsTmp = a/b;
        rows = ceil(rowsTmp);
    }
    while(false);

    for(int i=0; i<cells; ++i)
    {
        static int col=0;

        if (i%rows==0 && i!=0)
            ++col;

        entryLayout->addWidget(packTemp[i],i-(col*rows),col,Qt::AlignCenter);
        packTemp[i]->setText((QString("N/A'C")));
        packTemp[i]->setFixedWidth(600/columns-10);
        packTemp[i]->setAlignment(Qt::AlignCenter);
    }

    for(int i=0; i<columns; ++i)
    {
        entryLayout->setColumnMinimumWidth(i, SCR_WIDTH/4 / columns);
    }

    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
