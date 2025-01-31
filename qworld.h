#ifndef QWORLD_H
#define QWORLD_H

#include <QObject>
#include "cpendulum.h"

class QWorld : public QObject
{

    Q_OBJECT
public:
    explicit QWorld(QObject *parent = nullptr);

    vPendulums& pendulums()
        { return m_vPendulums; }

    void addPendulum();
    void removePendulum();

signals:
    void needUpdate();

public slots:
    void calc(int dT);

private:
    vPendulums m_vPendulums;

    bool m_bPlay = true;
    int m_iPrevTick = -1;

protected:
    virtual void timerEvent(QTimerEvent *event) Q_DECL_FINAL;

};

QWorld& world();

#endif // QWORLD_H
