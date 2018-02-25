#include "ampmeter.h"
#include <QTime>
#include <QPixmap>

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;

AmpMeter::AmpMeter(QWidget *parent)
{
    QFont font;
    //font.setStretch(50);
    font.setLetterSpacing(QFont::PercentageSpacing, 90);
    font.setFamily("Digital-7 Mono");
    font.setPixelSize(90);
    font.setCapitalization(QFont::AllUppercase);
    font.setWeight(QFont::Bold);

    amps->setFont(font);
    amps->setText("0");
    amps->setStyleSheet("color: white;");

    ampsUnit->setFont(font);
    ampsUnit->setText("A");
    ampsUnit->setStyleSheet("color: white;");

    volts->setFont(font);
    volts->setText("0");
    volts->setStyleSheet("color: white;");

    voltsUnit->setFont(font);
    voltsUnit->setText("V");
    voltsUnit->setStyleSheet("color: white;");

    ampFrame->setFixedSize(SCR_WIDTH,SCR_HEIGHT);
    ampFrame->setLayout(ampLay);

    QPixmap *fill = new QPixmap(SCR_WIDTH,font.pixelSize());
    QLabel *fillFrame = new QLabel;
    fill->fill(QColor(0,0,0,230));
    fillFrame->setPixmap(*fill);
    fillFrame->setFixedSize(SCR_WIDTH,SCR_HEIGHT);


    ampLay->addWidget(fillFrame,1,1,1,3);
    ampLay->addWidget(volts,1,1,Qt::AlignRight);
    ampLay->addWidget(voltsUnit,1,2,Qt::AlignLeft);
    ampLay->addWidget(amps,1,3,Qt::AlignRight);
    ampLay->addWidget(ampsUnit,1,4,Qt::AlignLeft);
    ampLay->setSpacing(0);
    ampLay->setContentsMargins(0,0,0,0);
    ampLay->setMargin(0);

    fillFrame->show();
    amps->show();
    ampsUnit->show();


/*  connect(timer,SIGNAL(timeout()),this,SLOT(changeAmp()));
    timer->start(500); */
}
/* For testing
void AmpMeter::changeAmp()
{
    int var = qrand();
    var = 50 + var % 3;
    QString text = QStringLiteral("%1").arg(var);
    //amps->setText(text);
}
*/
