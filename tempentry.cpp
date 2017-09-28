#include "tempentry.h"
#include <math.h>

#include "mainwindow.h"

extern short int SCR_WIDTH;

extern short int SCR_HEIGHT;
extern short int CELL_COUNT;

TempEntry::TempEntry(Mainwindow *parent) : QWidget(parent)
{
    short int ENT_WIDTH = SCR_WIDTH*3/4;
    int COLUMNS = 4;

    QFont font("Digital-7 Mono", 28, Qt::white);

    motEffEntry->setEasingCurve(QEasingCurve::InSine);

    QLabel *packTemp[CELL_COUNT];
    for (int i=0; i<CELL_COUNT; ++i)
    {
        packTemp[i] = new QLabel(this);
        packTemp[i]->setFont(font);
        packTemp[i]->setStyleSheet("QLabel {background-color: rgba(0,0,0,80); color: white;}");
    }

    entryFrame->setFixedSize(ENT_WIDTH,SCR_HEIGHT);
    entryFrame->setContentsMargins(0,20,0,20);

    entryLayout->setVerticalSpacing(8);

    *entryBg = entryBg->scaled(entryFrame->size(),Qt::IgnoreAspectRatio);
    canvas->setPixmap(*entryBg);
    canvas->setFixedSize(entryFrame->size());
    entryFrame->setLayout(entryLayout);

    int rows;
    do
    {
        double a = CELL_COUNT;
        double b = COLUMNS;
        double rowsTmp = a/b;
        rows = ceil(rowsTmp);
    }
    while(false);

    for(int i=0; i<CELL_COUNT; ++i)
    {
        static int col=0;

        if (i%rows==0 && i!=0)
            ++col;

        entryLayout->addWidget(packTemp[i],i-(col*rows),col,Qt::AlignCenter);
        packTemp[i]->setText((QString("34,%1'C").arg(i%10)));
        packTemp[i]->setFixedWidth(600/COLUMNS-10);
        packTemp[i]->setAlignment(Qt::AlignCenter);
    }

    for(int i=0; i<COLUMNS; ++i)
    {
        entryLayout->setColumnMinimumWidth(i, entryFrame->width() / COLUMNS);
    }
}
