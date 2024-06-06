#include "minesweepercell.h"

MinesweeperCell::MinesweeperCell(bool _isMine):
    isMine{_isMine}
{
    this->setStyleSheet("QPushButton { background-color: #5A5A5A; }");
};
