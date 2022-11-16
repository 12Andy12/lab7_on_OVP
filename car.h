#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QRectF>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Car : public QObject, public QGraphicsItem
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

#endif // CAR_H
