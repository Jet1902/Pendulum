#ifndef CPENDULUM_H
#define CPENDULUM_H

#include <QtGlobal>
#include <QPointF>
#include <QColor>
#include <QVector>
#include <QtMath>

class CPendulum
{
public:
    explicit CPendulum();

    QPointF lockPos() const
        { return m_lockPos; }
    void setLockPos(const QPointF &lockPos)
        { m_lockPos = lockPos; }

    QPointF tipPos() const
        { return m_tipPos; }
    void setTipPos(const QPointF &tipPos)
        { m_tipPos = tipPos; }

    CPendulum *nextPendulum() const
        { return m_nextPendulum; }
    void setNextPendulum(CPendulum *nextPendulum)
        { m_nextPendulum = nextPendulum; }

    void setSpeed(const qreal &speed)
        { m_speed = speed; }

    void setLength(const qreal &length)
        { m_length = length; }

    QColor color() const;

    void setColor(const QColor &color)
        { m_color = color; }

protected:
    friend class QWorld;
    void move(int dT);

private:
    qreal m_length = 300;
    QPointF m_lockPos;          // = 0
    QPointF m_tipPos;           // = 0
    qreal m_speed = M_PI_4;
    qreal m_angle = 0;
    QColor m_color = Qt::white;

    CPendulum* m_nextPendulum = nullptr;

    void moveNextPendulum(int dT);
};

typedef QVector<CPendulum> vPendulums;

#endif // CPENDULUM_H
