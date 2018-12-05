#ifndef NOTICE_H
#define NOTICE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>
#include <QVector>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

class Mainwindow;

class Notice : public QWidget
{
    Q_OBJECT
public:
    explicit Notice(Mainwindow *parent = nullptr);

    QWidget *noticeFrame = new QWidget;
    QGridLayout *layout = new QGridLayout;
    QLabel *text = new QLabel();
    QLabel *noticeContent = new QLabel();

signals:

public slots:
    int addText(QString);
    void showText(QString);
    void clear(int);
    void clearAll();
    void show();
    void hide();

private:
    QString m_content = "BOOT COMPLETE!";
    QVector<int> noticeId;
    Mainwindow *m_parent;
    QPixmap *bgImg = new QPixmap(":/entry.png");
    QTimer *hideTimer = new QTimer;
    QTimer *releaseTimer = new QTimer;
    QFont *noticeFont = new QFont;
    void initFont();
    QGraphicsOpacityEffect *opacity = new QGraphicsOpacityEffect(this->noticeFrame);
    QPropertyAnimation *opacityAnim = new QPropertyAnimation(opacity, "opacity");

    bool keepHidden = false;
};

#endif // NOTICE_H
