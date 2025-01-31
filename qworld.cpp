#include "qworld.h"

#include <QTime>
#include <QTimer>
#include <QDebug>


QWorld* g_pWorld = nullptr;

QWorld& world()
{
    if(!g_pWorld)
        g_pWorld = new QWorld;
    return *g_pWorld;
}

QWorld::QWorld(QObject *parent) : QObject(parent)
{
    startTimer(0);

    m_vPendulums.reserve(10);

//    addPendulum();
//    addPendulum();
}

void QWorld::addPendulum()
{
    CPendulum newPendulum;
    if (!m_vPendulums.empty())
    {
        CPendulum& prevLast = m_vPendulums.last();
        m_vPendulums << newPendulum;
        prevLast.setNextPendulum(&m_vPendulums.last());
    }
    else
        m_vPendulums << newPendulum;
}

void QWorld::removePendulum()
{
    if (!m_vPendulums.empty())
        m_vPendulums.pop_back();

    if (!m_vPendulums.empty())
        m_vPendulums.last().setNextPendulum(nullptr);
}

void QWorld::calc(int dT)
{
    m_vPendulums[0].move(dT);

    emit needUpdate();
}

void QWorld::timerEvent(QTimerEvent *event)
{
    int curTick = QTime::currentTime().msecsSinceStartOfDay();
    if(m_iPrevTick != -1 && m_bPlay)
    {
        int dT = (curTick - m_iPrevTick);
        if(dT < 2)
            return;
        calc(dT);
    }
    m_iPrevTick = curTick;
}


