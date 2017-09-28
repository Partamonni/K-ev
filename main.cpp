#include "mainwindow.h"
#include <QApplication>

short int SCR_WIDTH = 800;
short int SCR_HEIGHT = 480;
short int CELL_COUNT = 38;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainwindow w;

    return a.exec();
}
