#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pendulumsSpin_valueChanged(int arg1);
    void setPendulumsCount(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
