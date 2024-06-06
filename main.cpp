#include "minesweeper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Minesweeper minesweeper;
    minesweeper.show();

    return a.exec();
}
