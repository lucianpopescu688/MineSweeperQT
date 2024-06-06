#ifndef MINESWEEPERCELL_H
#define MINESWEEPERCELL_H

#include <QWidget>
#include <QPushButton>

class MinesweeperCell: public QPushButton
{
private:
    bool isMine;
public:
    MinesweeperCell(bool _isMine);
    bool getIsMine() const
    {
        return isMine;
    }
};

#endif // MINESWEEPERCELL_H
