#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "minesweepercell.h"

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QPalette>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QString>

#include <cstdlib>
#include <time.h>

class Minesweeper: public QWidget
{
private:
    QGridLayout* back;
    QWidget* background;
    QPalette* backgroundColor;
    QVBoxLayout* mainLayout;

    QWidget* settingsAux;
    QGridLayout* settings;
    QLabel* heightLabel;
    QLabel* widthLabel;
    QSlider* heightSlider;
    QSlider* widthSlider;
    QPushButton* okButton;

    QGridLayout* grid;
    QWidget* gridAux;

    void init();

    void initSettings();
    void initGrid();

    void connectStuff();

    int height = 1;
    int width = 1;
public:
    Minesweeper(QWidget* parent = nullptr);
};

#endif // MINESWEEPER_H
