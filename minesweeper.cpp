#include "minesweeper.h"

Minesweeper::Minesweeper(QWidget* parent) {
    this->back = new QGridLayout;

    this->background = new QWidget;
    this->backgroundColor = new QPalette;
    this->backgroundColor->setColor(QPalette::Window, "#8C92AC");
    this->background->setAutoFillBackground(true);
    this->background->setPalette(*backgroundColor);
    this->back->addWidget(background);

    this->mainLayout = new QVBoxLayout;
    this->background->setLayout(mainLayout);

    init();

    connectStuff();

    this->setLayout(back);
}

void Minesweeper::init()
{
    initSettings();
}

void Minesweeper::connectStuff()
{
    QWidget::connect(heightSlider, &QSlider::valueChanged, this, [&](){
        QString aux = "Height: ";
        aux += QString::number(heightSlider->value());

        this->heightLabel->setText(aux);
        this->height = heightSlider->value();
    });

    QWidget::connect(widthSlider, &QSlider::valueChanged, this, [&](){
        QString aux = "Width: ";
        aux += QString::number(widthSlider->value());

        this->widthLabel->setText(aux);
        this->width = widthSlider->value();
    });

    QWidget::connect(okButton, &QPushButton::released, this, [&](){
        initGrid();
    });
}

void Minesweeper::initSettings()
{
    this->settingsAux = new QWidget;
    this->settings = new QGridLayout;

    this->heightLabel = new QLabel("Height: ");
    this->widthLabel = new QLabel("Width: ");
    this->heightSlider = new QSlider(Qt::Horizontal);
    this->widthSlider = new QSlider(Qt::Horizontal);

    this->heightSlider->setMinimum(1);
    this->heightSlider->setMaximum(10);
    this->heightSlider->setTickInterval(1);
    this->widthSlider->setMinimum(1);
    this->widthSlider->setMaximum(10);
    this->widthSlider->setTickInterval(1);

    this->settings->addWidget(heightLabel, 0, 0);
    this->settings->addWidget(heightSlider, 0, 1);
    this->settings->addWidget(widthLabel, 1, 0);
    this->settings->addWidget(widthSlider, 1, 1);

    this->okButton = new QPushButton("OK");
    this->settings->addWidget(okButton, 2, 0);

    this->settingsAux->setLayout(settings);
    this->mainLayout->addWidget(settingsAux);
}

void Minesweeper::initGrid()
{
    this->gridAux = new QWidget;
    this->grid = new QGridLayout;

    for (int i=0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            srand(time(0));
            bool isMine = (rand() % 7 == 0);
            auto cell = new MinesweeperCell(isMine);

            this->grid->addWidget(cell, i, j);
        }
    }

    this->gridAux->setLayout(grid);
    this->mainLayout->addWidget(gridAux);
}
