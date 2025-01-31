#ifndef QWORLDWIDGET_H
#define QWORLDWIDGET_H

#include <QWidget>
#include "qworld.h"

class QWorldWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QWorldWidget(QWidget *parent = nullptr);

signals:

public slots:
    void onWorldNeedUpdate()
        { update(); }

protected:
    void paintPendulums(QPainter &painter, qreal opacity);
    void paintHistory(QPainter& painter);

    void drawTrail();

private:
    QImage m_trailImage;

protected:
    virtual void paintEvent(QPaintEvent *event) Q_DECL_FINAL;
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_FINAL;
};

#endif // QWORLDWIDGET_H
