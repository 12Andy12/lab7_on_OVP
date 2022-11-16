#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QRectF>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

public slots:
    void slotGameTimer();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    qreal angle;
    QPointF m_posBeforeCollision;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BALL_H
