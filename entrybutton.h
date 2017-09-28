#ifndef ENTRYBUTTON_H
#define ENTRYBUTTON_H

#include <QWidget>
#include <QPushButton>

class Dropdown;

class EntryButton : public QWidget
{
    Q_OBJECT
public:
    explicit EntryButton(Dropdown *parent = 0, QString text = 0);

    QPushButton *entry = new QPushButton();

signals:

public slots:
};

#endif // ENTRYBUTTON_H
