#include "entry.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;

Entry::Entry(Mainwindow *parent)
{
    short int entWidth = SCR_WIDTH*3/4;
    QFont font("Digital-7 Mono", 28, Qt::white);

    motEffEntry->setEasingCurve(QEasingCurve::InSine);
    motEffEntry->setDuration(800);

    entryFrame->setFont(font);
    entryFrame->setStyleSheet("QLabel {color: white;}");
    entryFrame->setFixedSize(entWidth, SCR_HEIGHT);
    entryFrame->setLayout(entryLayout);

    canvas->setFixedSize(entWidth, SCR_HEIGHT);
    canvas->setPixmap(entryBg->scaled(entryFrame->size(),Qt::IgnoreAspectRatio));

//    connect(this->motEffEntry, SIGNAL(finished()), parent, SLOT(entryIsShutFunc()));
}
