#ifndef OTHERENTRY_H
#define OTHERENTRY_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>

class Mainwindow;

class OtherEntry : public QWidget
{
    Q_OBJECT
public:
    explicit OtherEntry(Mainwindow *parent = 0);

    QWidget *entryFrame = new QWidget();
    QGridLayout *entryLayout = new QGridLayout;
    QLabel *textField = new QLabel;
    QPropertyAnimation *motEffEntry = new QPropertyAnimation(entryFrame, "pos");
    QPropertyAnimation *motEffOth = new QPropertyAnimation(textField, "pos");

signals:

public slots:
};

#endif // OtherEntry_H
