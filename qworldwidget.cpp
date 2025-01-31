#include "qworldwidget.h"

#include <QPainter>
#include <QResizeEvent>
#include <QRandomGenerator>
#include <QDebug>

QWorldWidget::QWorldWidget(QWidget *parent) : QWidget(parent)
{
    connect(&world(), SIGNAL(needUpdate()), this, SLOT(onWorldNeedUpdate()));
}

void QWorldWidget::paintPendulums(QPainter &painter, qreal opacity)
{
//    painter.setBrush(Qt::white);
//    painter.setPen(Qt::white);

    QRectF rcLock(0, 0, 10, 10);
    QRectF rcTip(0, 0, 10, 10);

    foreach(const CPendulum& pendulum, world().pendulums())
    {
        QColor color = pendulum.color();
        color.setAlphaF(opacity);
        painter.setBrush(color);
        painter.setPen(color);

//        rcLock.moveCenter(pendulum.lockPos());
//        painter.drawEllipse(rcLock);

        rcTip.moveCenter(pendulum.tipPos());
//        painter.drawEllipse(rcTip);

        painter.drawLine(pendulum.lockPos(), pendulum.tipPos());
    }
}

void QWorldWidget::drawTrail()
{
    QPainter painter(&m_trailImage);
    painter.setRenderHint(QPainter::Antialiasing);
//    painter.fillRect(rect(), QColor(0, 0, 0, 3));
    painter.translate(rect().center());
    paintPendulums(painter, 0.01);

//    m_trailImage.fill(QColor(0, 0, 0, 1));
}

void QWorldWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    qDebug() << painter.device()->colorCount();
//    qDebug() << painter.device()->depth();
    painter.setRenderHint(QPainter::Antialiasing);
//    painter.fillRect(rect(), Qt::black);
    painter.drawImage(QPoint(), m_trailImage);
//    painter.fillRect(rect(), QColor(0, 0, 0, 200));
    painter.translate(rect().center());

    drawTrail();
//    paintPendulums(painter, 1);
}


void QWorldWidget::resizeEvent(QResizeEvent *event)
{
    m_trailImage = QImage(event->size(), QImage::Format_RGBA8888);
    m_trailImage.fill(Qt::black);
}
