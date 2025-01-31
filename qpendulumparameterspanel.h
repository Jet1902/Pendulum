#ifndef QPENDULUMPARAMETERSPANEL_H
#define QPENDULUMPARAMETERSPANEL_H

#include <QWidget>
#include "qcolorpicker.h"
#include "qworld.h"

namespace Ui {
class QPendulumParametersPanel;
}

class QPendulumParametersPanel : public QWidget
{
    Q_OBJECT

public:
    explicit QPendulumParametersPanel(QWidget *parent = nullptr);
    ~QPendulumParametersPanel();

    int idx() const
        { return m_idx; }
    void setIdx(int idx)
        { m_idx = idx; }

public slots:
    void setLength(int value);
    void setSpeed(int value);
    void setColor(QColor color);

private:
    int m_idx = -1;

    Ui::QPendulumParametersPanel *ui;
};

#endif // QPENDULUMPARAMETERSPANEL_H
