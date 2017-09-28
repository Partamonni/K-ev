#include "dropdown.h"
#include "mainwindow.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;

Dropdown::Dropdown(Mainwindow *parent)
{
    menu->setLayout(layout);
    menu->setFixedSize(SCR_WIDTH/4,SCR_HEIGHT);

    *selectorImg = selectorImg->scaled(SCR_WIDTH/4,SCR_HEIGHT/entries, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    selector->setPixmap(*selectorImg);
    selector->setFixedSize(SCR_WIDTH/4,SCR_HEIGHT/entries);

    layout->addWidget(selector,selPos,0);
    layout->setContentsMargins(0,0,0,0);
    layout->setMargin(0);
    layout->setSpacing(0);

    motEffMen->setStartValue(menu->pos());
    motEffMen->setEndValue(QPoint(menu->x(), menu->y() - menu->height()));
    motEffMen->setEasingCurve(QEasingCurve::InOutQuad);
    motEffMen->setDuration(700);

    motEffSel = new QPropertyAnimation(selector, "pos");
    motEffSel->setEasingCurve(QEasingCurve::OutQuint);
    motEffSel->setDuration(300);

}
