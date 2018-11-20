#include "tempentry.h"
#include <math.h>

#include "mainwindow.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;


TempEntry::TempEntry(Mainwindow *parent) : Entry(parent)
{
    int columns = 4;

    for (int i=0; i<cells; ++i)
    {
        packTemp[i] = new QLabel(this);
        packTemp[i]->setFont(entryFrame->font());
        packTemp[i]->setStyleSheet("QLabel {background-color: rgba(0,0,0,80); color: white;}");
    }

    entryFrame->setContentsMargins(0,20,0,20);

    entryLayout->setVerticalSpacing(8);

    int rows;
    do
    {
        double a = cells;
        double b = columns;
        double rowsTmp = a/b;
        rows = static_cast<int>(ceil(rowsTmp));
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
