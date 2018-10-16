#include "notice.h"


Notice::Notice(Mainwindow *parent) : QWidget()
{
    m_parent = parent;
    initFont();

    noticeFrame->setFixedSize(400,180);
    noticeFrame->setGraphicsEffect(opacity);
    layout->setContentsMargins(0,0,0,0);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setRowStretch(1,1);
    noticeFrame->setLayout(layout);

    opacity->setOpacity(1);
    opacityAnim->setStartValue(1);
    opacityAnim->setEndValue(0);
    opacityAnim->setDuration(500);

    text->setText(m_content);
    text->setFont(*noticeFont);
    text->setStyleSheet("*{color: white;}");

    layout->addWidget(noticeContent,0,0,3,1);
    layout->addWidget(text,1,0,1,1,Qt::AlignCenter);

    noticeContent->setPixmap(bgImg->scaled(noticeFrame->size()));

    hideTimer->setSingleShot(true);
    connect(hideTimer, SIGNAL(timeout()), opacityAnim, SLOT(start()));
    connect(opacityAnim, SIGNAL(finished()), this, SLOT(hide()));

    show();
}

void Notice::initFont()
{
    noticeFont->setFamily("Square Sans Serif 7");
    noticeFont->setPixelSize(20);
    noticeFont->setCapitalization(QFont::AllUppercase);
    noticeFont->setLetterSpacing(QFont::PercentageSpacing, 110);
    noticeFont->setStretch(75);
}

int Notice::addText(QString addText)
{
    int i = -1;
    int freeId = -1; // -1 == non-free id

    while(freeId < 0)
    {
        ++i;
        freeId = i; // Put id up for test
        for(int j = 0; j >= noticeId.size();)
        {
            if(i == noticeId.at(j)) // If id exists, mark it non-free
            {
                freeId = -1;
                break; // Don't continue unnecessarily
            }
        }
    }

    noticeId.push_front(freeId);
    m_content.prepend("\n");
    m_content.prepend(addText);
    text->setText(m_content);
    noticeFrame->show();
    return freeId;
}

void Notice::showText(QString setText)
{
    text->setText(setText);
    show();
}

void Notice::clear(int deleteId)
{
    bool clear = false;

    int line = -1;
    for(int i = 0; i < noticeId.size(); ++i)
    {
        if(noticeId.at(i) == deleteId)
        { // Go through id:s and return order index of one when match found
            line = i;
            break; // Don't go over unnecessary indexes
        }
    }

    if(line > -1)
    {
        int i = 0;
        int begin = 0;
        int end = 0;
        while(!clear)
        {
            begin = end+1; // Move previous index to be starting index
            end = m_content.indexOf("\n", begin);
            if(i == line)
            {
                m_content.remove(begin, (end - begin)+1);
                noticeId.remove(line);
                clear = true;
            }
            else
                ++i;
        }
    }
    else{}
        //error
}

void Notice::clearAll()
{
    m_content.clear();
    noticeId.clear();
}

void Notice::show()
{
    opacity->setOpacity(1);
    noticeFrame->show();
    hideTimer->start(2000);
}

void Notice::hide()
{
    if(noticeId.isEmpty())
    {
        m_content.clear();
    }
    noticeFrame->hide();
}
