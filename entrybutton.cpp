#include "entrybutton.h"
#include "dropdown.h"

#include <QPushButton>
#include "dropdown.h"

extern short int SCR_WIDTH;
extern short int SCR_HEIGHT;

EntryButton::EntryButton(Dropdown *parent, QString text) : QWidget(parent)
{
    QFont font;
    font.setFamily("Square Sans Serif 7");
    font.setPixelSize(20);
    font.setCapitalization(QFont::AllUppercase);
    font.setLetterSpacing(QFont::PercentageSpacing, 110);
    font.setStretch(75);

    entry->setText(text);
    entry->setFixedSize(SCR_WIDTH/4,SCR_HEIGHT/parent->entries);
    parent->layout->addWidget(entry,parent->entriesInserted,0);
    entry->setFont(font);
    entry->setStyleSheet("QPushButton {border-image: url(:/button.png); color: white;}");

    parent->entriesInserted++;
}
