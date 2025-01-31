#include "qpendulumparameterspanel.h"
#include "ui_qpendulumparameterspanel.h"

QPendulumParametersPanel::QPendulumParametersPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPendulumParametersPanel)
{
    ui->setupUi(this);

    connect(ui->speedSpin, SIGNAL(valueChanged(int)), this, SLOT(setSpeed(int)));
    connect(ui->lengthSpin, SIGNAL(valueChanged(int)), this, SLOT(setLength(int)));
    connect(ui->widget, SIGNAL(colorChanged(QColor)), this, SLOT(setColor(QColor)));

//    setLength(ui->lengthSpin->value());
//    setSpeed(ui->speedSpin->value());

}

QPendulumParametersPanel::~QPendulumParametersPanel()
{
    delete ui;
}

void QPendulumParametersPanel::setLength(int value)
{
    world().pendulums()[m_idx].setLength(value);
}

void QPendulumParametersPanel::setSpeed(int value)
{
    world().pendulums()[m_idx].setSpeed(qDegreesToRadians(float(value)));
}

void QPendulumParametersPanel::setColor(QColor color)
{
    world().pendulums()[m_idx].setColor(color);
}




