#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include "qpendulumparameterspanel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setPendulumsCount(ui->pendulumsSpin->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pendulumsSpin_valueChanged(int arg1)
{
    setPendulumsCount(arg1);
}

void MainWindow::setPendulumsCount(int value)
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->parametersGroup->layout());
    if(!layout)
        return;
    while(layout->count() != value)
    {
        if(layout->count() < value)
        {
            int panelNumber = layout->count();

            QPendulumParametersPanel* newPanel = new QPendulumParametersPanel();
            newPanel->setIdx(panelNumber);
            newPanel->setObjectName(QString("panel_%1").arg(panelNumber));

            layout->addWidget(newPanel);
            world().addPendulum();
        }
        else
        {
            layout->removeItem(layout->itemAt(value));
            world().removePendulum();
        }
    }
}
