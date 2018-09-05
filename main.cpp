#include "mainwindow.h"
#include "buttons.h"
#include <QApplication>

short int SCR_WIDTH = 800;
short int SCR_HEIGHT = 480;
short int CELL_COUNT = 41;
int BAUD = 9600;

Buttons *isrClass = 0; // Needed for interrupts

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainwindow w;

    return a.exec();
}
