#include "cpendulum.h"
#include <QDebug>
#include <QRandomGenerator>

CPendulum::CPendulum()
{
//    m_color = Qt::GlobalColor(Qt::red + QRandomGenerator::global()->bounded(11));
    m_color = QColor::fromHsl(QRandomGenerator::global()->bounded(360), 255, 125);
    m_length = QRandomGenerator::global()->bounded(500) - 250;
    m_speed = qDegreesToRadians(double(QRandomGenerator::global()->bounded(90) - 45));
}

void CPendulum::move(int dT)
{
    m_angle += m_speed * dT / 1000;
    qreal tipX = m_lockPos.x() + m_length * qCos(m_angle);
    qreal tipY = m_lockPos.y() + m_length * qSin(m_angle);
    m_tipPos = QPointF(tipX, tipY);
    if(m_nextPendulum)
        moveNextPendulum(dT);
}



QColor CPendulum::color() const
{
    return m_color;
}

void CPendulum::moveNextPendulum(int dT)
{
    m_nextPendulum->setLockPos(m_tipPos);
    m_nextPendulum->move(dT);
}
